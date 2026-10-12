#include <QCoreApplication>
#include <QDebug>
#include <QObject>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 1. Declaración de variables primitivas
    int x = 47;
    double y = 3.2478;
    char t = 'k';

    // 2. Formateo de cadena usando QString y .arg()
    QString qtcadena = QString("%1 %2 %3").arg(t).arg(y).arg(x);

    // 3. Convertir dato primitivo string a QString (o viceversa)
    string cadena = qtcadena.toStdString();

    // 4. Convertir para mostrar en el debug
    qDebug() << cadena.c_str();
    qDebug() << qtcadena;

    // 5. Uso de métodos contains() e indexOf()
    qtcadena = "arequipa ciudad blanca 2021";
    qDebug() << qtcadena.contains("ciudad"); // devuelve bool (true/false)
    qDebug() << qtcadena.indexOf("2021");    // devuelve la posición numérica
    fflush(stdout);
    return 0;
}