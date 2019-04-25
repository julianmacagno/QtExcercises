#ifndef VISUAL_H
#define VISUAL_H

#include <QWidget>
#include <ogl.h>
#include <math.h>
#include <QVector>
#include <QKeyEvent>
#include <QMessageBox>

class Visual: public Ogl
{
    Q_OBJECT
public:
    Visual();

protected:
    void initializeGL();
    void resizeGL(int ancho, int alto);
    void paintGL();

    void keyPressEvent(QKeyEvent *e);

private:

    unsigned char *textura[4];
    GLuint idTexturas[4];
    float x, y, z;

    void configurarTextura(int id, QString dir, unsigned char* text);
    void cargarTexturas();
    void dibujarHorizontal(float x, float y, float z, float ancho, float profundidad, GLuint idTextura,
                           int repeticionX = 1, int repeticionY = 1);
    void dibujarVertical(float x, float y, float z, float ancho, float alto, GLuint idTextura,
                         int repeticionX = 1, int repeticionY = 1);
};

#endif // VISUAL_H
