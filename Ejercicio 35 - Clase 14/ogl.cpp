#include "ogl.h"

#include <QTimer>
#include <QKeyEvent>
#include <GL/glu.h>
#include <QDebug>

Ogl::Ogl(QWidget *parent):QGLWidget(parent),rotX(0),rotY(0),mouseX(0),mouseY(0),x(-5),y(-5),rot(0)
{
    setMouseTracking(true);
    this->setTimer(10);
}

void Ogl::mouseMove(int x, int y)
{
    if((x-mouseX)<0)--rotX;
    if((x-mouseX)>0)++rotX;
    if((y-mouseY)>0)++rotY;
    if((y-mouseY)<0)--rotY;

    if(rotX==360)rotX=0;
    if(rotY>40)rotY=40;
    if(rotY<-40)rotY=-40;

    mouseX=x;
    mouseY=y;
}
void Ogl::initializeGL()  {
    this->cargarTexturas();
    glClearColor(1, 1, 1, 1);
    glEnable(GL_DEPTH_TEST);
}

void Ogl::resizeGL(int ancho, int alto)  {
    glViewport( 0, 0, ancho, alto );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)ancho/(GLfloat)alto, 1, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
}
void Ogl::setposXY(float x, float y, float rot)
{
    this->x=x;
    this->y=y;
    this->rot=rot;
}
void Ogl::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glRotatef(rotY, 1, 0, 0);
    glRotatef(rotX, 0, 1, 0);
    glRotatef(rot,0,1,0);
    glTranslatef(x, y, 5);

    this->dibujarHorizontal(-50, 0, 50, 100,200, idTexturas[0], 5,20);
    this->dibujarHorizontal(-50,20, 50, 100,200, idTexturas[2], 5,20);

    this->dibujarVertical  (-50, 0,-50, 100, 20, idTexturas[1], 5, 1);
    this->dibujarVertical  (-50, 0, 50, 100, 20, idTexturas[1], 5, 1);


    this->dibujarVertical  (  0, 2, 48, 30, 15, idTexturas[3], 1, 1);//cuadros
    this->dibujarVertical  (-10, 2,-48, 30, 15, idTexturas[7], 1, 1);//cuadros
    this->dibujarVertical  (-20, 2, 48, 10, 15, idTexturas[4], 1, 1);//cuadros

    glRotatef(90, 0,1,0);

    this->dibujarVertical  (-50, 0,-50, 100, 20, idTexturas[1], 5, 1);
    this->dibujarVertical  (-50, 0, 50, 100, 20, idTexturas[1], 5, 1);

    this->dibujarVertical  (-10, 2, 48, 30, 15,  idTexturas[5], 1, 1);//cuadros
    this->dibujarVertical  (-10, 2,-48, 30, 15,  idTexturas[6], 1, 1);//cuadros

    glFlush();
}

void Ogl::cargarTexturas()   {
    glGenTextures(8, idTexturas);

    configurarTextura(idTexturas[0],":/Imagen/Techo", textura[0]);
    configurarTextura(idTexturas[1], ":/Imagen/Pared", textura[1]);
    configurarTextura(idTexturas[2], ":/Imagen/Piso", textura[2]);
    configurarTextura(idTexturas[3], ":/Imagen/1", textura[3]);
    configurarTextura(idTexturas[4], ":/Imagen/2", textura[4]);
    configurarTextura(idTexturas[5], ":/Imagen/3", textura[5]);
    configurarTextura(idTexturas[6], ":/Imagen/4", textura[6]);
    configurarTextura(idTexturas[7], ":/Imagen/5", textura[7]);
}

void Ogl::configurarTextura(int id, QString dir, unsigned char *text)
{
    glEnable(GL_TEXTURE_2D);	// Activamos la texturizacion

    QImage im;
    if (!im.load(dir))  {
        QMessageBox::critical(this, "Recurso no disponible", "La imagen no pudo ser cargada.");
        return;
    }

    im = QGLWidget::convertToGLFormat( im );
    text = im.bits();

    glBindTexture(GL_TEXTURE_2D, id);  // Activamos idTextura.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // GL_LINEAR - Interpolacion
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // GL_NEAREST - Sin

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);  // GL_CLAMP -
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);  // GL_REPEAT - Permite repetir

    glTexImage2D(GL_TEXTURE_2D, 0, 3, im.width(), im.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, text);

    glDisable(GL_TEXTURE_2D);	// Desactivamos la texturizacion
}

void Ogl::dibujarHorizontal(float x, float y, float z, float ancho, float profundidad, GLuint idTextura, int repeticionX, int repeticionY)
{
    glEnable(GL_TEXTURE_2D);	// Activamos la texturizacion
    glBindTexture(GL_TEXTURE_2D, idTextura);	// Activamos la textura con idTextura

    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);                         glVertex3f(x, y, z);
        glTexCoord2f(repeticionX, 0);               glVertex3f(x+ancho, y, z);
        glTexCoord2f(repeticionX, repeticionY);     glVertex3f(x+ancho, y, z-profundidad);
        glTexCoord2f(0, repeticionY);               glVertex3f(x, y, z-profundidad);
    glEnd();

    glDisable(GL_TEXTURE_2D);	// Activamos la texturizacion
}

void Ogl::dibujarVertical(float x, float y, float z, float ancho, float alto, GLuint idTextura, int repeticionX, int repeticionY)
{
    glEnable(GL_TEXTURE_2D);	// Activamos la texturizacion
    glBindTexture(GL_TEXTURE_2D, idTextura);	// Activamos la textura con idTextura

    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);                      glVertex3f(x, y, z);
        glTexCoord2f(repeticionX, 0);            glVertex3f(x+ancho, y, z);
        glTexCoord2f(repeticionX, repeticionY);  glVertex3f(x+ancho, y+alto, z);
        glTexCoord2f(0, repeticionY);            glVertex3f(x, y+alto, z);
    glEnd();

    glDisable(GL_TEXTURE_2D);	// Activamos la texturizacion
}
void Ogl::setTimer(int timerIntervalo)  {
    if(timerIntervalo > 0)  {
        timerIntervalo = qMin(15, timerIntervalo);
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(slot_timeout()));
        timer->start(timerIntervalo);
    }
}

void Ogl::slot_timeout()  {
    this->timeout();
}

void Ogl::timeout()  {
    this->updateGL();
}


