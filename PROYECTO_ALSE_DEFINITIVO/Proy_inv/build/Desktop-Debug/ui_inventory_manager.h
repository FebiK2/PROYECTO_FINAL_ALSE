/********************************************************************************
** Form generated from reading UI file 'inventory_manager.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORY_MANAGER_H
#define UI_INVENTORY_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inventory_manager
{
public:
    QTableView *tableView;
    QPushButton *btn_agregar;
    QLineEdit *lineEdit_tipo;
    QLineEdit *lineEdit_localizacion;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *lineEdit_buscar;
    QLabel *label_5;
    QLineEdit *lineEdit_cantidad;
    QLabel *statusLabel;
    QComboBox *comboBox;
    QLabel *label_3;
    QLineEdit *lineEdit_nombre;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_crearCSV;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_9;
    QPushButton *btn_agregar_2;
    QLineEdit *lineEdit_cantidad_2;
    QLineEdit *lineEdit_nombre_2;
    QLabel *label_10;
    QLineEdit *lineEdit_tipo_2;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QTableView *tableView_2;
    QLabel *statusLabel_2;
    QComboBox *comboBox_2;
    QLabel *label_14;
    QLineEdit *lineEdit_buscar_2;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;

    void setupUi(QWidget *inventory_manager)
    {
        if (inventory_manager->objectName().isEmpty())
            inventory_manager->setObjectName(QString::fromUtf8("inventory_manager"));
        inventory_manager->resize(1292, 689);
        tableView = new QTableView(inventory_manager);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 320, 611, 331));
        btn_agregar = new QPushButton(inventory_manager);
        btn_agregar->setObjectName(QString::fromUtf8("btn_agregar"));
        btn_agregar->setGeometry(QRect(790, 190, 121, 23));
        lineEdit_tipo = new QLineEdit(inventory_manager);
        lineEdit_tipo->setObjectName(QString::fromUtf8("lineEdit_tipo"));
        lineEdit_tipo->setGeometry(QRect(100, 170, 113, 23));
        lineEdit_localizacion = new QLineEdit(inventory_manager);
        lineEdit_localizacion->setObjectName(QString::fromUtf8("lineEdit_localizacion"));
        lineEdit_localizacion->setGeometry(QRect(330, 170, 113, 23));
        label = new QLabel(inventory_manager);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 170, 57, 15));
        label_2 = new QLabel(inventory_manager);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 170, 101, 16));
        label_4 = new QLabel(inventory_manager);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(460, 190, 111, 16));
        label_6 = new QLabel(inventory_manager);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 250, 71, 16));
        lineEdit_buscar = new QLineEdit(inventory_manager);
        lineEdit_buscar->setObjectName(QString::fromUtf8("lineEdit_buscar"));
        lineEdit_buscar->setGeometry(QRect(70, 250, 151, 23));
        label_5 = new QLabel(inventory_manager);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(250, 200, 57, 15));
        lineEdit_cantidad = new QLineEdit(inventory_manager);
        lineEdit_cantidad->setObjectName(QString::fromUtf8("lineEdit_cantidad"));
        lineEdit_cantidad->setGeometry(QRect(330, 200, 113, 23));
        statusLabel = new QLabel(inventory_manager);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(360, 250, 291, 20));
        statusLabel->setLayoutDirection(Qt::LeftToRight);
        statusLabel->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(inventory_manager);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(260, 250, 79, 23));
        label_3 = new QLabel(inventory_manager);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 200, 101, 16));
        lineEdit_nombre = new QLineEdit(inventory_manager);
        lineEdit_nombre->setObjectName(QString::fromUtf8("lineEdit_nombre"));
        lineEdit_nombre->setGeometry(QRect(100, 200, 113, 23));
        label_7 = new QLabel(inventory_manager);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(230, 250, 31, 16));
        label_8 = new QLabel(inventory_manager);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(450, 10, 401, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Serif"));
        font.setPointSize(14);
        font.setBold(true);
        label_8->setFont(font);
        pushButton_crearCSV = new QPushButton(inventory_manager);
        pushButton_crearCSV->setObjectName(QString::fromUtf8("pushButton_crearCSV"));
        pushButton_crearCSV->setGeometry(QRect(20, 660, 281, 23));
        dateTimeEdit = new QDateTimeEdit(inventory_manager);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(580, 190, 194, 23));
        label_9 = new QLabel(inventory_manager);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(410, 100, 57, 15));
        btn_agregar_2 = new QPushButton(inventory_manager);
        btn_agregar_2->setObjectName(QString::fromUtf8("btn_agregar_2"));
        btn_agregar_2->setGeometry(QRect(600, 100, 121, 23));
        lineEdit_cantidad_2 = new QLineEdit(inventory_manager);
        lineEdit_cantidad_2->setObjectName(QString::fromUtf8("lineEdit_cantidad_2"));
        lineEdit_cantidad_2->setGeometry(QRect(470, 100, 113, 23));
        lineEdit_nombre_2 = new QLineEdit(inventory_manager);
        lineEdit_nombre_2->setObjectName(QString::fromUtf8("lineEdit_nombre_2"));
        lineEdit_nombre_2->setGeometry(QRect(270, 100, 113, 23));
        label_10 = new QLabel(inventory_manager);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(190, 100, 101, 16));
        lineEdit_tipo_2 = new QLineEdit(inventory_manager);
        lineEdit_tipo_2->setObjectName(QString::fromUtf8("lineEdit_tipo_2"));
        lineEdit_tipo_2->setGeometry(QRect(50, 100, 113, 23));
        label_11 = new QLabel(inventory_manager);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 100, 57, 15));
        label_12 = new QLabel(inventory_manager);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 140, 281, 21));
        label_12->setFont(font);
        label_13 = new QLabel(inventory_manager);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 60, 351, 21));
        label_13->setFont(font);
        tableView_2 = new QTableView(inventory_manager);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(640, 320, 641, 331));
        statusLabel_2 = new QLabel(inventory_manager);
        statusLabel_2->setObjectName(QString::fromUtf8("statusLabel_2"));
        statusLabel_2->setGeometry(QRect(990, 250, 291, 20));
        statusLabel_2->setLayoutDirection(Qt::LeftToRight);
        statusLabel_2->setAlignment(Qt::AlignCenter);
        comboBox_2 = new QComboBox(inventory_manager);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(900, 250, 79, 23));
        label_14 = new QLabel(inventory_manager);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(870, 250, 31, 16));
        lineEdit_buscar_2 = new QLineEdit(inventory_manager);
        lineEdit_buscar_2->setObjectName(QString::fromUtf8("lineEdit_buscar_2"));
        lineEdit_buscar_2->setGeometry(QRect(710, 250, 151, 23));
        label_15 = new QLabel(inventory_manager);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(660, 250, 71, 16));
        label_16 = new QLabel(inventory_manager);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 290, 351, 21));
        label_16->setFont(font);
        label_17 = new QLabel(inventory_manager);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(640, 290, 351, 21));
        label_17->setFont(font);

        retranslateUi(inventory_manager);

        QMetaObject::connectSlotsByName(inventory_manager);
    } // setupUi

    void retranslateUi(QWidget *inventory_manager)
    {
        inventory_manager->setWindowTitle(QCoreApplication::translate("inventory_manager", "Form", nullptr));
        btn_agregar->setText(QCoreApplication::translate("inventory_manager", "Nueva Compra", nullptr));
        label->setText(QCoreApplication::translate("inventory_manager", "Tipo:", nullptr));
        label_2->setText(QCoreApplication::translate("inventory_manager", "Localizaci\303\263n:", nullptr));
        label_4->setText(QCoreApplication::translate("inventory_manager", "Fecha de compra:", nullptr));
        label_6->setText(QCoreApplication::translate("inventory_manager", "Buscar:", nullptr));
        label_5->setText(QCoreApplication::translate("inventory_manager", "Cantidad:", nullptr));
        statusLabel->setText(QString());
        label_3->setText(QCoreApplication::translate("inventory_manager", "Nombre:", nullptr));
        label_7->setText(QCoreApplication::translate("inventory_manager", "Por:", nullptr));
        label_8->setText(QCoreApplication::translate("inventory_manager", "ADMINISTRACI\303\223N DE INVENTARIO", nullptr));
        pushButton_crearCSV->setText(QCoreApplication::translate("inventory_manager", "Crear archivo CSV Para Compras", nullptr));
        label_9->setText(QCoreApplication::translate("inventory_manager", "Cantidad:", nullptr));
        btn_agregar_2->setText(QCoreApplication::translate("inventory_manager", "Aumentar Stock", nullptr));
        label_10->setText(QCoreApplication::translate("inventory_manager", "Nombre:", nullptr));
        label_11->setText(QCoreApplication::translate("inventory_manager", "Tipo:", nullptr));
        label_12->setText(QCoreApplication::translate("inventory_manager", "Registrar Una Compra", nullptr));
        label_13->setText(QCoreApplication::translate("inventory_manager", "Registrar Un Aumento de Stock", nullptr));
        statusLabel_2->setText(QString());
        label_14->setText(QCoreApplication::translate("inventory_manager", "Por:", nullptr));
        label_15->setText(QCoreApplication::translate("inventory_manager", "Buscar:", nullptr));
        label_16->setText(QCoreApplication::translate("inventory_manager", "Registro de Compras", nullptr));
        label_17->setText(QCoreApplication::translate("inventory_manager", "Registro de Stock", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inventory_manager: public Ui_inventory_manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORY_MANAGER_H
