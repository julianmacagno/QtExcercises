#include "visual.h"
#include <GL/glu.h>

Visual::Visual()
{
    this->setTimer(10);
}
void Visual::cargarTexturas()   {
    glGenTextures(4, idTexturas);

    configurarTextura(idTexturas[0],":/Imagen/Techo", textura[0]);
    configurarTextura(idTexturas[1], ":/Imagen/Pared", textura[1]);
    configurarTextura(idTexturas[2], ":/Imagen/Piso", textura[2]);
}

void Visual::configurarTextura(int id, QString dir, unsigned char *text)
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

void Visual::initializeGL()  {
    this->cargarTexturas();
    glClearColor(1, 1, 1, 1);
    glEnable(GL_DEPTH_TEST);
}

void Visual::resizeGL(int ancho, int alto)  {
    glViewport( 0, 0, ancho, alto );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)ancho/(GLfloat)alto, 1, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
}
void Visual::keyPressEvent(QKeyEvent *e)  {
    switch (e->key()) {
        case Qt::Key_Escape:
            close();
            break;
        case Qt::Key_W:
            if(z<=98)z++;
            break;
        case Qt::Key_S:
            if(z>=-100)z--;
            break;
        default:;
    }
}
void Visual::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(0, 1, 0, 0);
    glRotatef(0, 0, 1, 0);
    glTranslatef(-5, -5, z);

    this->dibujarHorizontal(-500,0,100, 1000,200, idTexturas[0], 50,20);
    this->dibujarHorizontal(-500,20,100, 1000,200, idTexturas[2], 50,20);
    this->dibujarVertical(-500,0,-100, 1000,20, idTexturas[1], 50,1);

    glFlush();
}
void Visual::dibujarHorizontal(float x, float y, float z, float ancho, float profundidad, GLuint idTextura, int repeticionX, int repeticionY)
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

void Visual::dibujarVertical(float x, float y, float z, float ancho, float alto, GLuint idTextura, int repeticionX, int repeticionY)
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

