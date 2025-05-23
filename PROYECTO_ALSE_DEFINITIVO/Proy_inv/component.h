#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject> // Clase para objetos Qt, permite usar señales y slots.
#include <QSqlRelationalTableModel> // Es el modelo para bases de datos relacionales
#include <QSqlQuery> // Para ejecutar consultas SQL directas
#include <QSortFilterProxyModel> // Es el modelo para ordenar y filtrar datos.
#include <crea_base_datos.h> // Se incluye porque es la clase que conecta el programa con la base de datos

class Component: public QObject
{
    Q_OBJECT // Q_OBJECT permite que Component herede de la clase QObject, que permite que funcionen correctamente las conecciones con los slots o elementos de la UI

public:
    // Se define el constructor de la clase
    explicit Component(QObject *parent = nullptr); // Se declara el constructor de la clase
    bool addStock(const QString& name, const QString& type, int quantity); // Se declara el método que permitirá añadir artículos a la tabla de stock (inventario)
    void filtrarLowStock(int threshold = 3); // Este método sirve para poder filtrar e identificar y filtrar los articulos que tienen bajo stock (Se definió que si no supera los
    // tres elementos, el artículo se considerará con bajo stock)
    bool procesarCompra(const QString& NombreComponente, int CantidadComprada); // Este método permite reducir las cantidades cuando en la UI se registra la compra de un usuario
    bool existeBajoStock(int threshold = 3) const; // Este método permite saber si al menos un solo artículo tienen bajo stock (tres elementos o menos) y se conecta con la alerta de bajo stock en la UI


    // Se requieren dos métodos que van a permitir obtener la tabla stock de la base de datos para que la clase Component pueda trabajarla y filtrarla
    QSqlRelationalTableModel* getStockModel(); // Esté método devuelve un puntero al modelo QSqlRelationalTableModel que de por sí representa la tabla "stock" en la base de datos (Osea modStock)
    QSortFilterProxyModel* getFilteredStockModel(); // Devuelve un puntero al modelo SortFilterProxyModel que permite filtrar y ordenar los datos de "stock" sin modificar su contenido, solo se cambia su vizualización (Osea el modelo proxySeller)

private:
    // Se definen los dos modelos que van a retornar lo métodos getStockModel() y etFilteredStockModel()
    QSqlRelationalTableModel *modStock; // Es un modelo de tipo QSqlRelationalTableModel que permite trabajar con la tabla "stock"
    QSortFilterProxyModel *proxySeller; // Este modelo permite manejar el filtro de la tabla (Es decir que también permite que comboBox_2 filtre correctamente)
};

#endif // COMPONENT_H
