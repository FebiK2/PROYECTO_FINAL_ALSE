#include "component.h"
#include <QDebug>

Component::Component(QObject *parent) : QObject(parent)
{
    modStock = new QSqlRelationalTableModel(this, crea_base_datos::db()); // Crea el modelo relacional modStock
    modStock ->setTable("stock"); // Se le asigna la tabla stock de la base de datos, porque a este modelo le va a corresponder trabajar con dicha tabla
    modStock ->select();

    // Filtrado
    proxySeller = new QSortFilterProxyModel(this); //  Crea el proxy model para el filtro de stock
    proxySeller->setSourceModel(modStock); // Establece modStock como modelo fuente, porque proxuSeller es el modelo para la tabla ya filtrada
    proxySeller->setFilterCaseSensitivity(Qt::CaseInsensitive); // Para que no sea sensible a mayúsculas o minúsculas
}
QSqlRelationalTableModel* Component::getStockModel() // Método que solo retorna el modelo modStock para la tabla "stock" normal sin alterar
{
    return modStock;
}

QSortFilterProxyModel* Component::getFilteredStockModel() // Método que solo retorna el modelo modStock para la tabla "stock" alterada y filtrada
{
    return proxySeller;
}

bool Component::addStock(const QString& name, const QString& type, int quantity) // Es la función que permite añadir artículos al stock
{
    QSqlQuery query(crea_base_datos::db()); // Se establece conexión con la base de datos, se crea un objeto QSqlQuery vinculado a la base de datos,
    //QSqlQuery ejecuta comandos en SQL en la base de datos.
    query.prepare("INSERT INTO stock(name, type, quantity) "
                  "VALUES (?, ?, ?)"); // Se prepara el comando de insercción del artículo requerido al stock
    // Estas lineas sirven para meter las variables de los campos de texto del formulario al comando en el prepare(), en el apartado de VALUES
    query.addBindValue(name);
    query.addBindValue(type);
    query.addBindValue(quantity);

    // Para ejecutar la consulta en el objeto query, se utiliza exec() que retorna true si la ejecución fue exitosa y false si no
    if (query.exec()) {
        modStock->select(); // Refresca la vista
        proxySeller->invalidate(); // Refresca el proxy para que actualice los datos visibles
        return true; // True porque la transacción o proceso fue exitoso
    } else { // De lo contrario, se retorna false para avisar que no fue posible añadir el artículo
        qDebug() << "Error al insertar Stock:";
        return false;
    }
}

void Component::filtrarLowStock(int threshold) // Es el método encargado de que en la tabla se filtren y se muestren los artículos con bajo stock
{
    // Se crea una expresión regular (un intervalo) que coincida solo con números de un dígito entre 0 y el umbral (threshold),
    // por ejemplo, si threshold = 3, regex = "^([0-3])$"
    // Esto se usa para filtrar registros cuya cantidad sea menor o igual al umbral (en nuestro caso será 3 para un stock bajo
    QString intervalo_stock_bajo = QString("^([0-%1])$").arg(threshold);
    proxySeller->setFilterKeyColumn(3); // Índice para filtrar en la columna quantity
    proxySeller->setFilterRegExp(QRegExp(intervalo_stock_bajo)); // Indíce para definir el rango de bajo stock (Es decir la variable intervalo_stock_bajo
}

bool Component::procesarCompra(const QString& NombreComponente, int CantidadComprada) //  Es el método que permite restar las cantidades en la tabla stock cuando un vendedor realiza una compra y se registra en la tabla compras
{
    QSqlDatabase db = crea_base_datos::db(); // Inicialmente se realiza la conexión con la base de datos

    //bloque try-catch, que es una estructura que permite encerrar una estructura de código que al conectarse con una base de datos puede fallar,
    // llevando a errores de funcionamiento del programa.

    try {
        // Se verifica cual es el stock existente en la tabla stock
        QSqlQuery verificarStock(db); // Se crea un objeto de la clase QSqlQuery llamado verificarStock, al cual se le ingresa como atributo la base de datos db
        verificarStock.prepare("SELECT quantity FROM stock WHERE name = ?"); // Se prepara un comando en SQLite que permite mostrar la columna de cantidad de un componente con un nombre específico
        verificarStock.addBindValue(NombreComponente); // Nombre específico de componente o artículo

        if(!verificarStock.exec() || !verificarStock.next()) { // Luego se ejecuta y se valida la consulta con la condición !verificarStock.exec() || !verificarStock.next() que en caso de que en la iteración a la tabla stock no se encuentre el componente,
            //se muestra un mensaje de error.
            qDebug() <<"Componente no encontrado en stock";
            return false; // False porque no se encuentra el componente en la tabla "stock"
        }

        int actualStock = verificarStock.value(0).toInt(); // Con un condicional se verifica si el componente deseado tiene suficiente stock en la tabla stock, en caso de que no, procesarCompra retorna false.
        if(actualStock < CantidadComprada) {
            qDebug() << "Stock insuficiente";
            return false;
        }

        //
        QSqlQuery actualizarStock(db); // Se crea un objeto de la clase QSqlQuery llamado actualizarStock, al cual se le ingresa como atributo la base de datos db
        actualizarStock.prepare("UPDATE stock SET quantity = quantity - ? WHERE name = ?"); // Se prepara comando para actualizar la tabla
        actualizarStock.addBindValue(CantidadComprada);
        actualizarStock.addBindValue(NombreComponente);

        if(!actualizarStock.exec()) { // Para que los cambios se vean en la interfaz, si no se puede hay mensaje de error en la terminal y se retorna false
            qDebug() << "Error al actualizar Stock";
            return false;
        }

        // Si no hubo ningún problema, se retorna true y el proceso fué un éxito
        return true;

    }
    // se cierra con un catch y usando un std::exception& e se evita que el programa haga crash, o en caso de que haya habido un error en la estructura dentro del try
    catch (const std::exception& e) {
        qDebug() << "Error en procesarCompra";
        return false;
    }
}

bool Component::existeBajoStock(int threshold) const{ // Sirve para comprobar si hay al menos un componente con bajo stock
    QSqlQuery query(crea_base_datos::db()); // Conexión a la base de datos
    query.prepare("SELECT 1 FROM stock WHERE quantity <= ? LIMIT 1"); // El comando para buscar si hay al menos un componente que tenga tres o menos en cantidad
    query.addBindValue(threshold);

    if(query.exec() && query.next()) { // se ejecuta el comando SQL anterior con exec() en el condicional. Si se ejecuta y se encuentra un elemento con bajo stock, la función retorna true
        return true;  // Existe al menos un componente con stock bajo
    }
    // se ejecuta el comando SQL anterior con exec() en el condicional. Si se ejecuta y se encuentra un elemento con bajo stock, la función retorna true
    return false;
}


