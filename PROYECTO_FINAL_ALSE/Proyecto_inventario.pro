QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    component.cpp \
    crea_base_datos.cpp \
    data_base_manager.cpp \
    inventory_manager.cpp \
    main.cpp \
    report_generator.cpp

HEADERS += \
    component.h \
    crea_base_datos.h \
    data_base_manager.h \
    inventory_manager.h \
    report_generator.h

FORMS += \
    inventory_manager.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
