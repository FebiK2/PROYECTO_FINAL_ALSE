#include "report_generator.h"
#include <QFile>                      // Clase para manejar archivos
#include <QTextStream>               // Clase para escribir texto en un archivo


report_generator::report_generator(QObject *parent) : QObject(parent) {}

// Método que exporta el contenido de un modelo (QAbstractItemModel) a un archivo CSV

bool report_generator::exportToCSV(const QAbstractItemModel *model, const QString &filePath)
{

    QFile file(filePath); // Crea un objeto QFile con la ruta especificada
    // Intenta abrir el archivo en modo escritura de texto
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false; // Si falla al abrir, devuelve false

    }
    QTextStream out(&file); // Objeto para escribir texto en el archivo

    // --- Escribir los encabezados de las columnas ---
    QStringList headers; // Lista para guardar los encabezados

    // Recorre las columnas y obtiene los encabezados horizontales
    for (int col = 0; col < model->columnCount(); ++col) {
        headers << model->headerData(col, Qt::Horizontal).toString();
    }

    // Escribe los encabezados separados por comas, seguidos de un salto de línea
    out << headers.join(", ") << "\n";

    // Escribir el contenido de las filas
    for (int row = 0; row < model->rowCount(); ++row) { // Itera por cada fila de la tabla
        QStringList rowContent; // Lista para almacenar el contenido de la fila actual
        for (int col = 0; col < model->columnCount(); ++col) {
            // Obtiene el dato de cada celda y lo convierte en QString
            rowContent << model->data(model->index(row, col)).toString();
        }
        // Escribe la fila como una línea CSV (valores separados por comas)
        out << rowContent.join(", ") << "\n";
    }

    file.close(); // Cierra el archivo

    return true; // Retorna true si todo el proceso se realizó correctamente

}
