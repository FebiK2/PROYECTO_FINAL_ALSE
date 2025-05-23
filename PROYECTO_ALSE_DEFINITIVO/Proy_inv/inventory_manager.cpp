#include "inventory_manager.h"
#include "ui_inventory_manager.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>

inventory_manager::inventory_manager(QWidget *parent) :
    QWidget(parent), // Constructor de la Clase QWidget para los elementos gráficos de la UI
    ui(new Ui::inventory_manager), // con está línea se crea la UI en sí, la muestra
    dbManager(new data_base_manager(this)), // Inicializa o crea el modelo dbManager que gestiona la tabla "compras"
    Cpnt(new Component(this)) // Inicializa el modelo Cpnt que gestiona la tabla "stock"

    {
    ui->setupUi(this); // Carga en la interfaz todos los elementos gráficos como los botones, etiquetas, cuadros de texto, etc...

    // Se asignan lo modelos creados a las tablas de la base de datos en SQL
    ui->tableView->setModel(dbManager->getFilteredModel()); // Se asigna a “compras” (en la UI se verá a la izquierda), y se asigna la versión filtrada para que se observen los filtros al aplicarlos
    ui->tableView_2->setModel(Cpnt->getFilteredStockModel()); // Se asigna a “stock” (en la UI se verá a la derecha), y se asigna la versión filtrada para que se observen los filtros al aplicarlos


    // Para ver cuál fila se selecciona de la tabla de registros de compra con el cursor
    // (nos sirve para seleccionar e implementar una función para eliminar registros)
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    //Para ver cuál fila se selecciona de la tabla de artículos en stock con el cursor
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);



    // Datos que queremos que aparezcan en las opciones de filtrado, para esto se utiliza la estructura
    // ui->comboBox->addItem("Nombre_atributo"); para cada atributo

    // Para el comboBox de la tabla "compras"
    ui->comboBox->addItem("Id");
    ui->comboBox->addItem("Nombre");
    ui->comboBox->addItem("Tipo");
    ui->comboBox->addItem("Cantidad");
    ui->comboBox->addItem("Localización");
    ui->comboBox->addItem("Fecha de compra");

    // Para el comboBox de la tabla "stock"
    ui->comboBox_2->addItem("Id");
    ui->comboBox_2->addItem("Nombre");
    ui->comboBox_2->addItem("Tipo");
    ui->comboBox_2->addItem("Cantidad");
    ui->comboBox_2->addItem("Bajo Stock");

}


inventory_manager::~inventory_manager()
{
    delete ui;
    delete dbManager;
    delete Cpnt;
}


// MÉTODOS PARA LOS BOTONES
void inventory_manager::on_btn_agregar_clicked()
{
    // Obtener valores de la UI en los campos de texto
    QString name = ui->lineEdit_nombre->text(); // Se define una variable de tipo QString que obtiene lo que se ingrese en lineEdit_nombre y recolecta el nombre del artículo
    QString type = ui->lineEdit_tipo->text(); // Se define una variable de tipo QString que obtiene lo que se ingrese en lineEdit_tipo y recolecta el tipo de artículo
    int quantity = ui->lineEdit_cantidad->text().toInt(); // Se define una variable de tipo entero que obtiene lo que se ingrese en lineEdit_cantidad y recolecta la cantidad que el cliente solicitó del artículo
    QString location = ui->lineEdit_localizacion->text();// Se define una variable de tipo QString que obtiene lo que se ingrese en lineEdit_localización y recolecta el lugar de donde se compró
    QString purchase_date = ui->dateTimeEdit->dateTime().toString(Qt::ISODate); // Se define una variable de tipo QString que obtiene el tiempo exacto que el vendedor registre en dateTimeEdit, que es un campo para digitar fecha y hora. Estos datos se almacenan en purchase_date

    // Iniciar transacción con SQLite:
    QSqlDatabase db = crea_base_datos::db(); // Se define una variable local db que copia la referencia de la conexión ya existente a la base de datos.
    db.transaction(); // Comienza la transacción en la conexión compartida

    try {
        // procesar en "stock"
        if(!Cpnt->procesarCompra(name, quantity)) { // Si no se puede ejecutar procesarCompra, esta retorna false y manda un mensaje de error
            ui->statusLabel->setText("Error en transacción, Stock insuficiente");
            qDebug() << "Error en transacción";
        }
        // Si se logró verificar el stock se evalua si se puede o no añadir un registro
        else if(!dbManager->addRecord(name, type, quantity, location, purchase_date)) { // Si ocurre también un error a la hora de registrar una compra, addRecord retorna false y se arroja un mensaje de error
            ui->statusLabel->setText("Compra registrada y stock actualizado");
            qDebug() << "Error al añadir registro de compra"; // Si no se logra añadir un registro en la tabla de “compras” se envía un mensaje de error en la terminal
        }
        else { // Si se logró verificar el stock y añadir el registro, se muestra en pantalla que la compra fue registrad
            ui->statusLabel->setText("Compra registrada y stock actualizado");
        }

        // Al lograr hacer los registros, se envía un mensaje al textLabel de la izquierda arriba de la tabla de “compras” (llamado statusLabel)

        // Actualizar vistas en las tablas
        dbManager->getInventarioModel()->select();
        Cpnt->getStockModel()->select();

    } catch (const std::exception& e) {
        db.rollback();
        ui->statusLabel->setText("Error en transacción");
        qDebug() << "Error en transacción";
    }

    // Limpiar mensaje después de 3 segundos (Usando la librería QTime para fijar el tiempo de duración), si no se realiza este proceso el mensaje queda en pantalla por siempre, y para esto se requiere la siguiente línea de código para cada etiqueta
    QTimer::singleShot(3000, [this](){ui->statusLabel->clear();ui->statusLabel->setStyleSheet("");});
    // Se repite para la otra etiqueta
    QTimer::singleShot(3000, [this](){ui->statusLabel_2->clear();ui->statusLabel_2->setStyleSheet("");});
}

void inventory_manager::on_btn_agregar_2_clicked() // El botón 2 agrega artículos a la tabla “stock”
{
    int quantity = ui->lineEdit_cantidad_2->text().toInt(); // Se crea una variable quantity de tipo entero que se obtiene desde “lineEdit_cantidad_2” que obtiene la cantidad de artículo en la compra

    QString type = ui->lineEdit_tipo_2->text(); // Se crea una variable quantity de tipo QString que se obtiene desde “lineEdit_tipo_2” que obtiene el tipo de artículo en la compra

    QString name = ui->lineEdit_nombre_2->text(); // Se crea una variable name de tipo QString que se obtiene desde “lineEdit_tipo_2” que obtiene el tipo de artículo en la compra

    if (Cpnt->addStock(name, type, quantity)) { // Verificamos si se logra añadir el artículo
        ui->statusLabel_2->setText("Nuevo Stock añadido con éxito"); // Si se logra añadir el artículo, se envía un mensaje de éxito en el textLabel arriba de la tabla “stock” (llamado statusLabel_2)
    } else {
        ui->statusLabel_2->setText("Error al añadir Nuevo Stock");  // Si no se logra añadir el artículo, se envía un mensaje de error en el textLabel arriba de la tabla “stock” (llamado statusLabel_2)

    }

    // Limpiar mensaje después de 3 segundos
    QTimer::singleShot(3000, [this](){ui->statusLabel->clear();ui->statusLabel->setStyleSheet("");});
    // Se repite para la otra etiqueta
    QTimer::singleShot(3000, [this](){ui->statusLabel_2->clear();ui->statusLabel_2->setStyleSheet("");});

}

// Botón para borrar artículos en la tabla “stock”
void inventory_manager::on_borrar_articulo_clicked() // Se ejecuta la función al presionar el botón “borrar_articulo”
{
    // Obtener la fila seleccionada en la tabla “stock” (tableView_2)
    QModelIndex selectedIndex = ui->tableView_2->currentIndex();

    if (!selectedIndex.isValid()) { // Si no se selecciona una fila válida, se envía un mensaje de error en una ventana emergente
        QMessageBox::warning(this, "Advertencia", "Selecciona un artículo para borrar.");
        return;
    }

    // Convertir el índice seleccionado desde el proxy al modelo base (modStock)
    int rowInSource = Cpnt->getFilteredStockModel()->mapToSource(selectedIndex).row();

    // Eliminar fila seleccionada del modelo
    if (Cpnt->getStockModel()->removeRow(rowInSource)) {
        Cpnt->getStockModel()->submitAll();      // Aplicar cambios a la base de datos
        Cpnt->getStockModel()->select();         // Refrescar
        Cpnt->getFilteredStockModel()->invalidate(); // Refrescar proxy
        ui->statusLabel_2->setText("Artículo eliminado correctamente");
    } else {
        QMessageBox::critical(this, "Error", "No se pudo eliminar el artículo.");
    }

    // Limpiar mensaje después de 3 segundos
    QTimer::singleShot(3000, [this](){ui->statusLabel->clear();ui->statusLabel->setStyleSheet("");});
    QTimer::singleShot(3000, [this](){ui->statusLabel_2->clear();ui->statusLabel_2->setStyleSheet("");});

}


// Botón para borrar registros de compras
void inventory_manager::on_borrar_compra_clicked() // Se ejecuta la función al presionar el botón “borrar_compra”

{
    // Obtener la fila seleccionada en la tabla “compras” (tableView)
    QModelIndex selectedIndex = ui->tableView->currentIndex();

    if (!selectedIndex.isValid()) { // Si no se selecciona una fila válida, se envía un mensaje de error en una ventana emergente
        QMessageBox::warning(this, "Advertencia", "Selecciona un registro para borrar.");
        return;
    }

    // Convertir el índice seleccionado desde el proxy al modelo base (modInventario)
    int rowInSource = dbManager->getFilteredModel()->mapToSource(selectedIndex).row();

    // Eliminar fila del modelo
    if (dbManager->getInventarioModel()->removeRow(rowInSource)) {
        dbManager->getInventarioModel()->submitAll();      // Aplicar cambios a la base de datos
        dbManager->getInventarioModel()->select();         // Refrescar
        dbManager->getFilteredModel()->invalidate(); // Refrescar proxy
        ui->statusLabel->setText("Registro eliminado correctamente");
    } else {
        QMessageBox::critical(this, "Error", "No se pudo eliminar el registro.");
    }

    // Limpiar mensaje después de 3 segundos
    QTimer::singleShot(3000, [this](){ui->statusLabel->clear();ui->statusLabel->setStyleSheet("");});
    // Se repite para la otra etiqueta
    QTimer::singleShot(3000, [this](){ui->statusLabel_2->clear();ui->statusLabel_2->setStyleSheet("");});

}

// La siguiente función es la de un botón que permite saber si hay al menos un componente con bajo Stock. En caso de que haya un componente con menos de 3 en cantidad, se lanza un mensaje de alerta con una etiqueta avisando que hay falta de Stock.
void inventory_manager::on_verificarBajoStock_clicked()
{
    if(Cpnt->existeBajoStock()) { // Se evalúa si hay objetos con bajo stock recurriendo a la función existeBajoStock() de la clase Component. Si se encuentra un artículo con bajo stock, se retorna True y se lanza la advertencia.

        ui->labelAlertaStock->setText("Hay componentes con stock bajo"); // Advertencia

        // Se muestra por 3 segundos el mensaje
        QTimer::singleShot(3000, [this](){ui->labelAlertaStock->clear();ui->labelAlertaStock->setStyleSheet("");});
    }
    else { // Si no se encuentran componentes con bajo stock entonces avisa que no hay componentes con bajo stock
        ui->labelAlertaStock->setText("No hay componentes con stock bajo");
        // Se muestra por 3 segundos el mensaje
        QTimer::singleShot(3000, [this](){ui->labelAlertaStock->clear();ui->labelAlertaStock->setStyleSheet("");});
    }
}


void inventory_manager::on_pushButton_crearCSV_clicked() // Al presionar el botón “pushButton_crearCSV” se ejecuta la función para crear el archivo formato CSV
{

    // Se crea una instancia del objeto que genera el reporte
    // Este objeto contiene la lógica para exportar datos en formato CSV
    report_generator generator;

    // Se abre un cuadro de diálogo para que el usuario elija dónde guardar el archivo CSV
    // QFileDialog::getSaveFileName devuelve un string con la ruta completa del archivo que se desea guardar

    QString filePath = QFileDialog::getSaveFileName(
        this, // “this” indica que el cuadro de diálogo pertenece a esta ventana
        "Guardar reporte CSV", // Título del cuadro de diálogo
        "", // Ruta por defecto (Si se deja vacía, se elige la carpeta actual).
        "Archivos CSV (*.csv)"); // Filtro para que solo se vean o guarden archivos con extensión .csv

    if (!filePath.isEmpty()) { // Si el usuario no canceló y se seleccionó una ruta válida para guardar el archivo:
        // Se llama a la función exportToCSV, pasándole el modelo de datos actual de la tabla y la ruta del archivo.
        // Esta función intentará guardar el contenido del QTableView como un archivo CSV.

        if (generator.exportToCSV(ui->tableView->model(), filePath)) {
            // Si la exportación fue exitosa, se muestra un mensaje en una ventana emergente
            QMessageBox::information(this, "Éxito", "Reporte generado con éxito");
        } else {
            // Si la exportación no funcionó, se muestra un mensaje de error
            QMessageBox::warning(this, "Error", "No se pudo generar el reporte");
        }
    }

}

// MÉTODOS DE LAS COMBOBOX
void inventory_manager::on_comboBox_currentIndexChanged(int index) // Esta función se ejecuta cada vez que se selecciona una nueva opción del comboBox de la tabla de registros de compras
{

    // Se llama al método getFilteredModel() del objeto dbManager, el cual devuelve un puntero al QSortFilterProxyModel (“proxyUser`”), que está enlazado al modelo de la base de datos (modInventario) a través de setSourceModel en data_base_manager

    dbManager->getFilteredModel()->setFilterKeyColumn(index);

    // El index es la columna a filtrar (el orden de las opciones del comboBox coincide con las columnas de la tabla, entonces, la opción “0”, corresponde a la primera columna y así sucesivamente)
}


// comboBox_2 Es la comboBox de la tabla “compras” que permite filtrar por categoría o atributo del artículo
void inventory_manager::on_comboBox_2_currentIndexChanged(int index)
{
    ui->tableView_2->setModel(Cpnt->getFilteredStockModel()); // Se recurre al método getFilteredStockModel(), se obtiene proxySeller que se utiliza para filtrar stock
    QString filter = ui->comboBox_2->itemText(index); // Se crea una variable de tipo QString para saber a que opción o atributo de filtrado

    if (filter == "Bajo Stock") {
        Cpnt->filtrarLowStock(); // Aplicar filtro por cantidad <= 3
    } else {
        Cpnt->getFilteredStockModel()->setFilterKeyColumn(index);
        // Reaplica el filtro actual (si hay texto en la barra de búsqueda)
        QString currentText = ui->lineEdit_buscar_2->text();
        Cpnt->getFilteredStockModel()->setFilterRegExp(QRegExp(currentText, Qt::CaseInsensitive));
    }
}

// Métodos para las líneas de texto
void inventory_manager::on_lineEdit_buscar_textChanged(const QString &arg1)
{
    dbManager->getFilteredModel()->setFilterFixedString(arg1); // Permite leer lo que se escribió en lineEdit_buscar para ingresarlo a la función setFilterFixedString(arg1), la cual sirve como intermediario para filtrar entre Qt y SQLite
}

void inventory_manager::on_lineEdit_buscar_2_textChanged(const QString &arg1)
{
    Cpnt->getFilteredStockModel()->setFilterFixedString(arg1); // Permite leer lo que se escribió en lineEdit_buscar_2 para ingresarlo a la función setFilterFixedString(arg1)
}


