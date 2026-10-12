#include "Task.h"
#include "ui_Task.h"
#include <QLineEdit>

Task::Task(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    // Cuando el Line Edit cambie, Task emitirá la señal "textoActualizado"
    connect(ui->Mitext, &QLineEdit::textChanged, this, &Task::textoActualizado);
    connect(ui->checkBox, &QCheckBox::toggled, ui->Mitext, &QLineEdit::setEnabled);
}

Task::~Task()
{
    delete ui;
}
