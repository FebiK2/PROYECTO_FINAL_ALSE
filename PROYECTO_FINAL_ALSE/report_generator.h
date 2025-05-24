#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H

// Inclusión de clases necesarias de Qt
#include <QObject>                // Clase base para objetos que usan señales y slots
#include <QAbstractItemModel>    // Modelo abstracto de datos, permite manejar datos tabulares como en QTableView
#include <QString>               // Clase para manejar cadenas de texto

// Definición de la clase report_generator, que hereda de QObject para poder usar señales y slots
class report_generator : public QObject
{
    Q_OBJECT // Macro necesaria para habilitar señales y slots en la clase

public:
    // Constructor explícito que permite definir un objeto padre (por defecto es nullptr)
    explicit report_generator(QObject *parent = nullptr);

    // Método público que exporta un modelo de datos (de una tabla en este caso) a un archivo CSV
    // Recibe un puntero al modelo de datos y la ruta del archivo como parámetros
    bool exportToCSV(const QAbstractItemModel *model, const QString &filePath);
};

#endif // REPORT_GENERATOR_H
