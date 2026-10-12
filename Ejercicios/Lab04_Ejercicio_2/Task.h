#ifndef TASK_H
#define TASK_H
#include <QLineEdit>

#include <QWidget>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

    signals:
        void textoActualizado(QString texto);

public:
    explicit Task(QWidget *parent = nullptr);
    ~Task();

private:
    Ui::Task *ui;
};

#endif // TASK_H
