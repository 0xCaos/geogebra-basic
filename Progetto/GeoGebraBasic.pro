QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QMAKE_CXXFLAGS += -Wall

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Circonferenza.cpp \
    Controller.cpp \
    Creator.cpp \
    Curva.cpp \
    Disegnabile.cpp \
    Ellisse.cpp \
    Figura.cpp \
    Interfaccia.cpp \
    Linea.cpp \
    Model.cpp \
    PianoCartesiano.cpp \
    Poligono.cpp \
    Punto.cpp \
    Regolare.cpp \
    Retta.cpp \
    Segmento.cpp \
    Workspace.cpp \
    main.cpp

HEADERS += \
    Circonferenza.h \
    Controller.h \
    Creator.h \
    Curva.h \
    DeepPtr.h \
    Disegnabile.h \
    Ellisse.h \
    Figura.h \
    Interfaccia.h \
    Linea.h \
    Model.h \
    PianoCartesiano.h \
    Poligono.h \
    Punto.h \
    Regolare.h \
    Retta.h \
    Segmento.h \
    Vettore.h \
    Workspace.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
