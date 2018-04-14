#ifndef MOTEUR_H
#define MOTEUR_H

#include "case.h"
#include <QObject>
#include <string>
using namespace std;

class Moteur : public QObject
{
    Q_OBJECT
public:
    explicit Moteur(QObject *parent = 0);

    Q_INVOKABLE void clique(int i);
    Q_INVOKABLE void nouvellePartie();

    Q_PROPERTY(QString infosQML READ readInfos NOTIFY changeInfos);
    Q_PROPERTY(QList<QString> bordsQML READ readBords NOTIFY changeBords);
    Q_PROPERTY(QList<QString> couleursQML READ readCouleurs NOTIFY changeCouleurs);
    Q_PROPERTY(bool etatCasesQML READ readEtatCases NOTIFY changeEtatCases);

    QString readInfos();
    QList<QString> readBords();
    QList<QString> readCouleurs();
    bool readEtatCases();

    void initialisation();
    void place(int i);
    bool gagne(int joueur);
    void deplace(int i);
    void selectionne(int i);
    void deselectionne();

signals:
    void changeInfos();
    void changeBords();
    void changeCouleurs();
    void changeEtatCases();

public slots:

private:
    bool tapisVide [9];
    bool joueur1 [9];
    bool joueur2 [9];
    int listeGagnante [8] [3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {6, 4, 2}, {0, 4, 8}};
    Case* cases [9];
    bool selected;
    int caseSelected;
    int compteur;
    string infos;
    string bords[9];
    string couleurs[9];
    bool etatCases;
};

#endif // MOTEUR_H
