#include "MainWindow.h"
#include "ui_MainWindow.h" // A veces quitar el "./" del inicio ayuda a evitar errores en Linux
#include "Task.h" // Vital para que reconozca a tu segunda ventana

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1. Instanciamos la ventana secundaria
    Task *miTarea = new Task();

    // 2. La mostramos en pantalla
    miTarea->show();

    // 3. Conectamos la señal de Task con el slot de MainWindow
    connect(miTarea, &Task::textoActualizado, this, &MainWindow::procesarTexto);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Aquí programamos qué hace el slot que declaramos en el .h
void MainWindow::procesarTexto(QString texto) {
    ui->statusLabel->setText("Status: " + texto);
}