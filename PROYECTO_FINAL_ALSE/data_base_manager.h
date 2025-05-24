#ifndef DATA_BASE_MANAGER_H
#define DATA_BASE_MANAGER_H

// Inclusión de las librerías necesarias
#include <QObject>                       // Clase base de Qt para todos los objetos que usan señales y slots
#include <QSqlRelationalTableModel>     // Modelo que permite manejar tablas con relaciones entre columnas
#include <QSqlQuery>                    // Permite ejecutar consultas SQL directamente
#include <QSortFilterProxyModel>        // Modelo que permite filtrar y ordenar datos de otro modelo
#include <crea_base_datos.h>            // Clase encargada de gestionar la conexión con la base de datos

// Definición de la clase data_base_manager que hereda de QObject
class data_base_manager : public QObject
{
    Q_OBJECT  // Macro necesaria para permitir señales y slots en la clase

public:
    // Constructor explícito que permite asignar un objeto padre (útil para jerarquía de objetos en Qt)
    explicit data_base_manager(QObject *parent = nullptr);

    // Método para acceder al modelo que representa la tabla "compras" original sin filtros en la base de datos
    QSqlRelationalTableModel* getInventarioModel();

    // Método para acceder a un modelo filtrado del modelo original
    QSortFilterProxyModel* getFilteredModel();

    // Método para añadir un nuevo registro a la tabla "compras"
    // Recibe como parámetros los datos que componen un registro de una compra
    bool addRecord(const QString& name, const QString& type, int quantity, const QString& location, const QString& purchase_date);

private:
    QSqlRelationalTableModel *modInventario;  // Modelo que representa la tabla completa de compras
    QSortFilterProxyModel *proxyUser;         // Modelo que permite aplicar filtros al modelo original
};

#endif // DATA_BASE_MANAGER_H

