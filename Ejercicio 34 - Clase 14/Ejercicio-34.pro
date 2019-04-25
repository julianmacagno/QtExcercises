#-------------------------------------------------
#
# Project created by QtCreator 2017-10-31T16:27:50
#
#-------------------------------------------------
QT +=core gui widgets opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ejercicio-34
TEMPLATE = app

unix:LIBS += -lGLU  # Esta es la libreria libGLU.so

win32:LIBS += -lopengl32
win32:LIBS += -lglu32


SOURCES += main.cpp\
    ogl.cpp \
    visual.cpp

HEADERS  += \
    ogl.h \
    visual.h

FORMS    +=

RESOURCES += \
    imagenes.qrc
