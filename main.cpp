#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "moteur.h"

// Méthode principale :
int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    Moteur unMoteur; // création d'une instance Moteur

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("vueObjetMoteur", &unMoteur);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec(); // lancement du jeu

}
