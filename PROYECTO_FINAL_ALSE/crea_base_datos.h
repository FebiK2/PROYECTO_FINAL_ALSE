#ifndef CREA_BASE_DATOS_H
#define CREA_BASE_DATOS_H

// Inclusión de las bibliotecas necesarias
#include <QObject>         // Clase base de Qt para permitir el uso de señales y slots
#include <QSqlDatabase>    // Clase para manejar conexiones a bases de datos

// Clase que administra una única instancia de la conexión a la base de datos
class crea_base_datos : public QObject
{
    Q_OBJECT  // Macro de Qt necesaria para habilitar el sistema de señales y slots

public:
    // Constructor explícito que permite establecer un objeto padre (puede ser nullptr si no se necesita)
    explicit crea_base_datos(QObject *parent = nullptr);

    // Método estático que devuelve la conexión activa a la base de datos
    static QSqlDatabase db();

    // Método estático que devuelve un puntero a la instancia única de la clase
    static crea_base_datos *obj();

    // Atributos estáticos (compartidos entre todas las instancias de la clase)
    static crea_base_datos *_obj;  // Puntero a la única instancia de la clase
    static QSqlDatabase _db;       // Objeto que representa la conexión a la base de datos
};

#endif // CREA_BASE_DATOS_H
