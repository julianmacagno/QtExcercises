#ifndef OGL_H
#define OGL_H

#include <QGLWidget>
#include <QWidget>
#include <math.h>
#include <QVector>
#include <QMessageBox>
#include <QMouseEvent>

class QTimer;

class Ogl : public QGLWidget  {
    Q_OBJECT

public:
    explicit Ogl(QWidget *parent = 0);
    void setTimer(int timerIntervalo);
    void mouseMove(int x, int y);
    void setposXY(float x, float y,float rot);
protected:
    void initializeGL();
    void resizeGL(int ancho, int alto);
    void paintGL();
    void timeout();

private:

    unsigned char *textura[8];
    GLuint idTexturas[8];
    float rotX, rotY,mouseX,mouseY,x,y,rot;

    void configurarTextura(int id, QString dir, unsigned char* text);
    void cargarTexturas();
    void dibujarHorizontal(float x, float y, float z, float ancho, float profundidad, GLuint idTextura,
                           int repeticionX = 1, int repeticionY = 1);
    void dibujarVertical(float x, float y, float z, float ancho, float alto, GLuint idTextura,
                         int repeticionX = 1, int repeticionY = 1);

protected slots:
    virtual void slot_timeout();

private:
    QTimer *timer;

};



#endif // OGL_H
