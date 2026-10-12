#include <QCoreApplication>
#include <QObject>
#include "comunicacion.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject *person = new QObject;
    Comunicacion *pepe = new Comunicacion(person);
    Comunicacion *jose = new Comunicacion(person);

    // Asignamos nombres
    pepe->setNombre("Pepe");
    jose->setNombre("Jose");

    // Conectamos las señales y slots cruzados para que ambos se escuchen
    QObject::connect(pepe, SIGNAL(enviarmensaje(QString)), jose, SLOT(escuchar(QString)));
    QObject::connect(jose, SIGNAL(enviarmensaje(QString)), pepe, SLOT(escuchar(QString)));

    // Probamos la comunicación
    pepe->conversar("buenos dias");
    jose->conversar("como vas?");

    delete person;

    return 0;
}