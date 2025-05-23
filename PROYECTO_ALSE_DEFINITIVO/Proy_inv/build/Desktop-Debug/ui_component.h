/********************************************************************************
** Form generated from reading UI file 'component.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPONENT_H
#define UI_COMPONENT_H

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

class Ui_Component
{
public:
    QComboBox *comboBox;
    QLabel *label_8;
    QLabel *statusLabel;
    QLabel *label_3;
    QLineEdit *lineEdit_tipo;
    QLineEdit *lineEdit_cantidad;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_4;
    QDateTimeEdit *dateTimeEdit;
    QLineEdit *lineEdit_buscar;
    QLabel *label_6;
    QTableView *tableView;
    QPushButton *btn_agregar;
    QLineEdit *lineEdit_nombre;
    QLabel *label_5;
    QPushButton *pushButton_crearCSV;

    void setupUi(QWidget *Component)
    {
        if (Component->objectName().isEmpty())
            Component->setObjectName(QString::fromUtf8("Component"));
        Component->resize(842, 398);
        comboBox = new QComboBox(Component);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(560, 330, 79, 23));
        label_8 = new QLabel(Component);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(270, 10, 331, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Serif"));
        font.setPointSize(14);
        font.setBold(true);
        label_8->setFont(font);
        statusLabel = new QLabel(Component);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(220, 310, 381, 20));
        statusLabel->setLayoutDirection(Qt::LeftToRight);
        statusLabel->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Component);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(290, 50, 101, 16));
        lineEdit_tipo = new QLineEdit(Component);
        lineEdit_tipo->setObjectName(QString::fromUtf8("lineEdit_tipo"));
        lineEdit_tipo->setGeometry(QRect(150, 50, 113, 23));
        lineEdit_cantidad = new QLineEdit(Component);
        lineEdit_cantidad->setObjectName(QString::fromUtf8("lineEdit_cantidad"));
        lineEdit_cantidad->setGeometry(QRect(570, 50, 113, 23));
        label_7 = new QLabel(Component);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(530, 330, 31, 16));
        label = new QLabel(Component);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 50, 57, 15));
        label_4 = new QLabel(Component);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 320, 111, 16));
        dateTimeEdit = new QDateTimeEdit(Component);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(70, 340, 194, 23));
        lineEdit_buscar = new QLineEdit(Component);
        lineEdit_buscar->setObjectName(QString::fromUtf8("lineEdit_buscar"));
        lineEdit_buscar->setGeometry(QRect(370, 330, 151, 23));
        label_6 = new QLabel(Component);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(320, 330, 71, 16));
        tableView = new QTableView(Component);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(50, 110, 731, 192));
        btn_agregar = new QPushButton(Component);
        btn_agregar->setObjectName(QString::fromUtf8("btn_agregar"));
        btn_agregar->setGeometry(QRect(700, 50, 121, 23));
        lineEdit_nombre = new QLineEdit(Component);
        lineEdit_nombre->setObjectName(QString::fromUtf8("lineEdit_nombre"));
        lineEdit_nombre->setGeometry(QRect(370, 50, 113, 23));
        label_5 = new QLabel(Component);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(510, 50, 57, 15));
        pushButton_crearCSV = new QPushButton(Component);
        pushButton_crearCSV->setObjectName(QString::fromUtf8("pushButton_crearCSV"));
        pushButton_crearCSV->setGeometry(QRect(680, 330, 121, 23));

        retranslateUi(Component);

        QMetaObject::connectSlotsByName(Component);
    } // setupUi

    void retranslateUi(QWidget *Component)
    {
        Component->setWindowTitle(QCoreApplication::translate("Component", "Form", nullptr));
        label_8->setText(QCoreApplication::translate("Component", " Administraci\303\263n de Inventario", nullptr));
        statusLabel->setText(QString());
        label_3->setText(QCoreApplication::translate("Component", "Nombre:", nullptr));
        label_7->setText(QCoreApplication::translate("Component", "Por:", nullptr));
        label->setText(QCoreApplication::translate("Component", "Tipo:", nullptr));
        label_4->setText(QCoreApplication::translate("Component", "Fecha de Aumento:", nullptr));
        label_6->setText(QCoreApplication::translate("Component", "Buscar:", nullptr));
        btn_agregar->setText(QCoreApplication::translate("Component", "Aumentar Stock", nullptr));
        label_5->setText(QCoreApplication::translate("Component", "Cantidad:", nullptr));
        pushButton_crearCSV->setText(QCoreApplication::translate("Component", "Crear archivo CSV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Component: public Ui_Component {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPONENT_H
