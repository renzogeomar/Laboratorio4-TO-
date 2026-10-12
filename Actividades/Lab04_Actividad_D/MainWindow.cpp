#include "MainWindow.h"
#include "./ui_MainWindow.h"
//#include <QDebug>
#include <iostream>

// Este es el CONSTRUCTOR (se ejecuta al abrir la ventana)
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Aquí debe ir la conexión, justo después de configurar la interfaz
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

// Este es el DESTRUCTOR (se ejecuta al cerrar la ventana)
MainWindow::~MainWindow()
{
    delete ui; // Solo esto debe quedar aquí
}

// Este es tu SLOT personalizado
void MainWindow::addTask() {
    //qWarning() << "Slot corresponde al clic en el boton ...";
    std::cout << "Slot corresponde al clic en el boton ..." << std::endl;
}