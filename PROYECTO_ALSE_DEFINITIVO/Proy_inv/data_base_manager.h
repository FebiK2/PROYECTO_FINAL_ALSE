#ifndef DATA_BASE_MANAGER_H
#define DATA_BASE_MANAGER_H

#include <QObject>
#include <QSqlRelationalTableModel>
#include <QSqlQuery>
#include <QSortFilterProxyModel>
#include <crea_base_datos.h>

class data_base_manager : public QObject
{
    Q_OBJECT

public:
    explicit data_base_manager(QObject *parent = nullptr);
    QSqlRelationalTableModel* getInventarioModel();
    QSortFilterProxyModel* getFilteredModel();

    bool addRecord(const QString& name, const QString& type, int quantity, const QString& location, const QString& purchase_date);

private:
    QSqlRelationalTableModel *modInventario;
    QSortFilterProxyModel *proxyUser;

};

#endif // DATA_BASE_MANAGER_H
