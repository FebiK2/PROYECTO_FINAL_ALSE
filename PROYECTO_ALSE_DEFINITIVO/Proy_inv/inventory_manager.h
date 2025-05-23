#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include <QWidget>
#include "data_base_manager.h"
#include "component.h"
#include "report_generator.h"

namespace Ui {
class inventory_manager;
}

class inventory_manager : public QWidget
{
    Q_OBJECT
private:
    Ui::inventory_manager *ui;
    data_base_manager *dbManager;
    QAbstractItemModel *lastModel = nullptr;
    Component *Cpnt = nullptr;

public:
    explicit inventory_manager(QWidget *parent = nullptr);
    ~inventory_manager();

private slots:
    void on_lineEdit_buscar_textChanged(const QString &arg1);
    void on_btn_agregar_clicked();    
    void on_comboBox_currentIndexChanged(int index);
    void on_pushButton_crearCSV_clicked();
    void on_comboBox_2_currentIndexChanged(int index);
    void on_btn_agregar_2_clicked();
    void on_lineEdit_buscar_2_textChanged(const QString &arg1);
    void on_borrar_articulo_clicked();
    void on_borrar_compra_clicked();

    void on_verificarBajoStock_clicked();
};
#endif // INVENTORY_MANAGER_H3
