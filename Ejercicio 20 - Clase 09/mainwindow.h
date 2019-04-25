#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QWebEngineView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

    QFile *file;
    QString fName, contents;
    QWebEngineView *webView;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void slot_open();
    void slot_save();
    void slot_new();
    void slot_close();
    void slot_toggleBrowser();
};

#endif // MAINWINDOW_H
