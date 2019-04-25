#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this->webView = new QWebEngineView(NULL);
    this->webView->setUrl(QUrl("http://google.com"));

    connect(ui->actionAbrir, SIGNAL(triggered(bool)), this, SLOT(slot_open()));
    connect(ui->actionGuardar, SIGNAL(triggered(bool)), this, SLOT(slot_save()));
    connect(ui->actionNew, SIGNAL(triggered(bool)), this, SLOT(slot_new()));
    connect(ui->actionCerrar, SIGNAL(triggered(bool)), this, SLOT(slot_close()));
    connect(ui->actionBrowser, SIGNAL(triggered(bool)), this, SLOT(slot_toggleBrowser()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::slot_open() {
    this->fName = QFileDialog::getOpenFileName(this, "Abrir Archivo", "Cualquier Archivo (*.txt)");
    this->file = new QFile(this->fName);
    this->file->open(QIODevice::Text | QIODevice::ReadWrite);

    QTextStream pipe(this->file);
    this->contents = QString(pipe.readAll());

    this->ui->textEdit->setText(this->contents);
}


void MainWindow::slot_save() {
    this->contents = this->ui->textEdit->toPlainText();

    if(this->fName.isEmpty()) {
        this->fName = QFileDialog::getSaveFileName(this, "Nuevo Archivo", "file.txt");
        this->file = new QFile(this->fName);
        this->file->open(QIODevice::Text | QIODevice::ReadWrite);
    }

    file->resize(0);
    QTextStream pipe(this->file);
    pipe << this->contents;
}

void MainWindow::slot_new() {
    this->fName = QFileDialog::getSaveFileName(this, "Nuevo Archivo", "file.txt");
    this->file = new QFile(this->fName);
    this->file->open(QIODevice::Text | QIODevice::ReadWrite);
    this->contents = "";
    this->ui->textEdit->setText(this->contents);
}

void MainWindow::slot_close() {
    this->close();
}

void MainWindow::slot_toggleBrowser() {
    this->setCentralWidget(this->webView);
}
