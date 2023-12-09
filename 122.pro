TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    basicas.cpp \
    estructuras.cpp

include(deployment.pri)
qtcAddDeployment()

