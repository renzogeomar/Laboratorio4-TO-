#include <QCoreApplication>
#include <QDebug>
#include <QObject>

// Creación de la clase adulto que hereda de QObject
class adulto : public QObject {
private:
    QString nombre;

public:
    // Constructor: asigna el objeto padre (base)
    adulto(QObject *base = nullptr) : QObject(base) {}

    void setNombre(const QString &nomb) {
        nombre = nomb;
    }

    QString getNombre() const {
        return nombre;
    }

    // Destructor: se ejecuta cuando el objeto es eliminado
    ~adulto() {
        qDebug() << "..objeto destruido...";
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Instanciación del padre
    adulto *papa = new adulto;

    // Instanciación de los hijos, pasándole 'papa' como objeto base
    adulto *hijo1 = new adulto(papa);
    adulto *hijo2 = new adulto(papa);

    hijo1->setNombre("manuel");
    hijo2->setNombre("Jose");

    // Al eliminar al padre, Qt destruye automáticamente a todos sus hijos
    delete papa;

    return 0;
}