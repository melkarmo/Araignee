#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "moteur.h"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    Moteur unMoteur;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("vueObjetMoteur", &unMoteur);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();

}
