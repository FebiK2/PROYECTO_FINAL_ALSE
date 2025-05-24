#include "crea_base_datos.h"
#include "QDir"
#include <QDebug>


// Inicializa el miembro estático _db con una conexión SQLite
QSqlDatabase crea_base_datos::_db = QSqlDatabase::addDatabase("QSQLITE");

// Inicializa la instancia única de la clase
crea_base_datos *crea_base_datos::_obj = new crea_base_datos;


// Constructor de la clase crea_base_datos
crea_base_datos::crea_base_datos(QObject *parent)

    : QObject{parent} // Inicializa el objeto base QObject con el padre (si lo hay)

{
    // Establece el nombre del archivo de la base de datos en el directorio actual (usando QDir::currentPath()
    _db.setDatabaseName(QDir::currentPath() + "/datos_inventario.sqlite");

    // Se intenta abrir la base de datos
    if(_db.open()){
        qDebug() << "Conexión a la base de datos exitosa =>" + _db.databaseName() + "<=";
    }

    else{ // Si no se puede abrir la base de datos, se muestra un mensaje de error en la terminal
        qDebug() << "Problemas para conectar a la base de datos" + _db.databaseName();
    }
}


// Devuelve la instancia única de la clase
crea_base_datos *crea_base_datos::obj()

{
    // Si no existe una instancia aún, se crea
    if(!_obj){
        _obj = new crea_base_datos();
    }
    return _obj;
}

// Devuelve la conexión a la base de datos
QSqlDatabase crea_base_datos::db()

{
    return _db;
}
