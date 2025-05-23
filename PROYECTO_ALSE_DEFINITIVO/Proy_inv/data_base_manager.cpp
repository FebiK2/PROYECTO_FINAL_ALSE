#include "data_base_manager.h"
#include <QDebug>

// Constructor de la clase data_base_manager
data_base_manager::data_base_manager(QObject *parent) : QObject(parent)
{

    // Se crea el modelo relacional modInventario para manipular la tabla "compras"
    // usando la conexión proporcionada por crea_base_datos
    modInventario = new QSqlRelationalTableModel(this, crea_base_datos::db());
    modInventario->setTable("compras"); // Asocia el modelo con la tabla "compras"
    modInventario->select(); // Carga los datos desde la base de datos

    // Se crea el modelo de filtrado proxyUser, que usará modInventario como fuente de datos
    proxyUser = new QSortFilterProxyModel(this);
    proxyUser->setSourceModel(modInventario); // Conecta el modelo base al modelo de filtro
    proxyUser->setFilterCaseSensitivity(Qt::CaseInsensitive); // Ignora mayúsculas y minúsculas al filtrar
}



// Getter que devuelve un puntero al modelo base (sin filtros)
QSqlRelationalTableModel* data_base_manager::getInventarioModel()
{
    return modInventario;
}

// Getter que devuelve un puntero al modelo filtrado (proxy)
QSortFilterProxyModel* data_base_manager::getFilteredModel() {
    return proxyUser;
}



// Método que inserta un nuevo registro en la tabla "compras"
bool data_base_manager::addRecord(const QString& name, const QString& type, int quantity, const QString& location, const QString& purchase_date) {

    // Se prepara una consulta SQL con la conexión actual
    QSqlQuery query(crea_base_datos::db());
    query.prepare("INSERT INTO compras (name, type, quantity, location, purchase_date)"
                  "VALUES (?, ?, ?, ?, ?)"); // Se utilizan '?’ para facilitar el enlace con las columnas de las tablas

    // Se enlazan los valores a los ‘?’
    query.addBindValue(name);
    query.addBindValue(type);
    query.addBindValue(quantity);
    query.addBindValue(location);
    query.addBindValue(purchase_date);

    // Se ejecuta la consulta
    if (query.exec()) {
        modInventario->select(); // Refresca el modelo para que refleje los cambios en la vista
        return true;
    }
    else {
        // En caso de error, se imprime el mensaje en la terminal
        qDebug() << "Error al insertar registro:";
        return false;
    }
}
