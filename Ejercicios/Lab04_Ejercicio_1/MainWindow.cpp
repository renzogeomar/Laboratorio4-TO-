#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->listWidget, &QListWidget::currentTextChanged, this, &MainWindow::cambiarColorLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cambiarColorLabel(const QString &colorTexto) {
    // Primero, actualizamos el texto del Label como lo hacíamos antes
    ui->labelColor->setText(colorTexto);

    // Evaluamos qué color seleccionó el usuario para cambiar el fondo
    if (colorTexto == "Rojo") {
        ui->labelColor->setStyleSheet("background-color: red; color: white; font-weight: bold;");
    } else if (colorTexto == "Azul") {
        ui->labelColor->setStyleSheet("background-color: blue; color: white; font-weight: bold;");
    } else if (colorTexto == "Verde") {
        ui->labelColor->setStyleSheet("background-color: green; color: white; font-weight: bold;");
    } else if (colorTexto == "Amarillo") {
        ui->labelColor->setStyleSheet("background-color: yellow; color: black; font-weight: bold;");
    } else {
        // Color por defecto si se agrega algo más a la lista
        ui->labelColor->setStyleSheet("background-color: transparent; color: black;");
    }
}