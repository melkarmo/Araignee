#ifndef MOTEUR_H
#define MOTEUR_H

#include "case.h"
#include <QObject>
#include <string>
using namespace std;

// Classe du moteur de jeu
class Moteur : public QObject
{
    Q_OBJECT
public:
    explicit Moteur(QObject *parent = 0); // constructeur

    // ---- Intéractions avec l'IG (Interface Graphique) ----

    Q_INVOKABLE void clique(int i); // fonction appelée lors du clique sur la i-ème case
    Q_INVOKABLE void nouvellePartie(); // fonction appelée lors du clique sur la zone "Nouvelle Partie"

    // Notification des changements dans les élèments de l'IG
    Q_PROPERTY(QString infosQML READ readInfos NOTIFY changeInfos);
    Q_PROPERTY(QList<QString> bordsQML READ readBords NOTIFY changeBords);
    Q_PROPERTY(QList<QString> couleursQML READ readCouleurs NOTIFY changeCouleurs);
    Q_PROPERTY(bool etatCasesQML READ readEtatCases NOTIFY changeEtatCases);

    // Fonctions de lecture des élements pour la mise à jour de l'IG (voir attributs plus bas) :
    QString readInfos();
    QList<QString> readBords();
    QList<QString> readCouleurs();
    bool readEtatCases();

    // ---- Fonctions "motrices" du jeu ----

    void initialisation(); // permet d'initialiser (ou remettre à zéro) les paramètres du jeu pour une nouvelle partie
    void place(int i); // s'occupe du placement du marqueur dans la i-ème case
    bool gagne(int joueur); // renvoie true si le joueur donné en entrée (1 ou 2) gagne, false sinon
    void deplace(int i); // s'occupe du déplacement d'un marqueur de la case sélectionnée vers la case d'indice i donné en entrée
    void selectionne(int i); // s'occupe de la sélection de la i-ème case avant un déplacement
    void deselectionne(); // s'occupe de la déselection de la case auparavant sélectionnée

signals:

    // Signaux de changement des élements pour la mise à jour de l'IG (voir attributs plus bas) :
    void changeInfos();
    void changeBords();
    void changeCouleurs();
    void changeEtatCases();

public slots:

private: // ---- Attributs ----

    // Les différentes cases du jeu sont numérotées de 0 à 8, ce qui permet de facilement y avoir accès et de bien se repérer
    // Schéma simplifié de la numérotation des 9 cases de la toile :
    // 0 . 1 . 2
    // 3 . 4 . 5
    // 6 . 7 . 8

    bool tapisVide [9]; // tapisVide[i] vaut true si la case i est vide, false sinon (tapis fait référence au tapis de jeu)

    // joueur[i] vaut true si le joueur a marqué la case i
    bool joueur1 [9];
    bool joueur2 [9];

    // listeGagnante contient les différents alignements de victoire
    int listeGagnante [8] [3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {6, 4, 2}, {0, 4, 8}};

    // cases contient les différentes cases de jeu (voir case.h)
    Case* cases [9];

    bool selected; // vaut true si une case est sélectionnée pour être déplacée
    int caseSelected; // correspond à l'indice de la case sélectionnée

    int compteur; // compteur de tours de jeu, un tour correspondant à un mouvement de placement ou de déplacement par l'un des joueurs

    // élements pour la mise à jour de l'IG :
    string infos; // contient le message d'informations
    string bords[9]; // bords[i] correspond à la couleur (en code html) du bord de la i-ème case
    string couleurs[9]; // // couleurs[i] correspond à la couleur (en code html) du fond de la i-ème case
    bool etatCases; // vaut true si les cases sont cliquables, et false sinon (fin de jeu)

};

#endif // MOTEUR_H
