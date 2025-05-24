#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include <QWidget>
#include "data_base_manager.h" // Se incluye para que maneje la tabla "compras"
#include "component.h" // Se incluye para que maneje la tabla "stock"
#include "report_generator.h" // Se incluye para generar archivos CSV

namespace Ui {
class inventory_manager;
}

// Clase principal del gestor de inventario, que hereda de QWidget para poder integrarse en la interfaz gráfica de Qt
class inventory_manager : public QWidget
{
    Q_OBJECT // Macro de Qt necesaria para habilitar señales y slots en esta clase

private:
    // Puntero a la interfaz gráfica generada por Qt Designer (archivo .ui)
    Ui::inventory_manager *ui;

    // Puntero al manejador de base de datos, encargado de la lógica de la tabla "compras"
    data_base_manager *dbManager;

    // Modelo genérico utilizado para mostrar datos en vistas
    QAbstractItemModel *lastModel = nullptr;

    // Puntero a la clase Component, que maneja la lógica relacionada con el "stock"
    Component *Cpnt = nullptr;

public:
    // Constructor explícito que permite inicializar la clase con un padre opcional (por defecto es nullptr)
    explicit inventory_manager(QWidget *parent = nullptr);

    // Destructor para liberar los recursos asociados con esta clase
    ~inventory_manager();

private slots:
    // Elementos interactivos de la interfaz
    void on_lineEdit_buscar_textChanged(const QString &arg1); // Barra de búsqueda de tabla "compras"
    void on_btn_agregar_clicked(); // Botón para añadir registro de compra en tabla "compras"
    void on_comboBox_currentIndexChanged(int index); // comboBox para filtrado de tabla "compras"
    void on_pushButton_crearCSV_clicked(); // Botón para crear archivo CSV
    void on_comboBox_2_currentIndexChanged(int index); // comboBox para filtrado de tabla "stock"
    void on_btn_agregar_2_clicked(); // Botón para añadir artículo en tabla "stock"
    void on_lineEdit_buscar_2_textChanged(const QString &arg1); // Barra de búsqueda de tabla "stock"
    void on_borrar_articulo_clicked(); // Botón para borrar artículo de tabla "stock"
    void on_borrar_compra_clicked(); // Botón para borrar registro de tabla "compras"
    void on_verificarBajoStock_clicked(); // Botón para mostrar alerta de bajo Stock de tabla "stock"
};
#endif // INVENTORY_MANAGER_H3
