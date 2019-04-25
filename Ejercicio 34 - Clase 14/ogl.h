#ifndef OGL_H
#define OGL_H

#include <QGLWidget>

class QTimer;

class Ogl : public QGLWidget  {
    Q_OBJECT

public:
    Ogl();
    void setTimer(int timerIntervalo);

protected:
    virtual void initializeGL() = 0;
    virtual void resizeGL(int width, int height) = 0;
    virtual void paintGL() = 0;

    virtual void keyPressEvent(QKeyEvent *e);

    virtual void timeout();

protected slots:
    virtual void slot_timeout();

private:
    QTimer *timer;

};

#endif // OGL_H
