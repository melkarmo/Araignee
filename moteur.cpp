#include "moteur.h"

// pour la description de la fonction de chaque méthode, voir moteur.h

Moteur::Moteur(QObject *parent) : QObject(parent)
{
    // les cases sont créées à la construction
    for(int i = 0; i < 9; i++)
        cases[i] = new Case(i);

    initialisation(); // mise à zéro des paramètres de jeu

    // on signale les changements à l'IG
    changeInfos();
    changeBords();
    changeCouleurs();
    changeEtatCases();
}


void Moteur::initialisation(){
    compteur = 0; // mise à zéro du compteur
    selected = false; // rien n'est encore sélectionné
    caseSelected = -1; // -1 par défaut car aucune case n'est encore sélectionnée
    infos = "Joueur 1, à vous de jouer!"; // message d'informations de début de jeu
    etatCases = true; // les cases sont cliquables

    // on initialise les listes :
    for(int i = 0; i < 9; i++){
        tapisVide[i] = true; // toutes les cases sont vides
        joueur1[i] = false; // aucun marqueur n'a été posé
        joueur2[i] = false; // aucun marqueur n'a été posé
        bords[i] = "#000000"; // les bords sont remis en couleur noire
        couleurs[i] = "#ffffff"; // les cases sont remises en couleur blanche
    }
}


void Moteur::nouvellePartie(){

    initialisation();

    // on signale les changements à l'IG
    changeInfos();
    changeBords();
    changeCouleurs();
    changeEtatCases();
}


void Moteur::clique(int i){

    int joueur = compteur % 2 + 1; // on identifie le joueur à l'aide du compteur

    if (compteur <= 5) {
        // tant que chaque joueur n'a pas placé 3 marqueurs dans la toile (moins de 6 coups), on procède au placement
        place(i);
    } else {
        // la phase de placement étant finie, on procède au déplacement
        if (!selected) {
            // s'il n'y a pas de sélection auparavant, un appui sur une case entraine forcément une sélection
            selectionne(i);
        } else if (selected && caseSelected == i) {
            // s'il y a sélection auparavant, et qu'on appuie sur la case sélectionnée, on le désélectionne
            deselectionne();
        } else {
            // enfin s'il y a sélection auparavant, et qu'on appuie sur une case non sélectionnée, ça correspond à un déplacement
            deplace(i);
        }
    }

    // on vérifie si l'un des joueurs gagne
    if (gagne(joueur)){
        if (joueur == 1){
            infos = "Bravo Joueur 1 ! Vous avez gagné !"; // on indique dans la zone d'information que le joueur 1 gagne
            // on "colorie" pour améliorer le visuel
            for(int j = 0; j<9; j++){
                if(joueur1[j]) {
                    bords[j] = "#00ff00"; // on colorie en vert les bords des cases gagnantes
                } else if (joueur2[j]){
                    // la couleur de cases du joueur adverse restent inchangées
                } else {
                    couleurs[j] = "#ebebeb"; // on colorie en gris des cases vides
                }
            }
        } else {
            infos = "Bravo Joueur 2 ! Vous avez gagné !";
            for(int j = 0; j<9; j++){
                if(joueur2[j]){
                    bords[j] = "#00ff00";
                } else if (joueur1[j]){
                } else {
                    couleurs[j] = "#ebebeb";
                }
            }
        }
        etatCases = false; // on désactive le cases
        changeEtatCases(); // on le signale
    }

    // on signale les changements
    changeInfos();
    changeBords();
    changeCouleurs();

}


void Moteur::place(int i){
    // on vérifie d'abord que la case correspondante est vide
    if (tapisVide[i]) {
        // selon le joueur, on met à jour sa liste, ainsi que le bouton et la zone d'information
        if (compteur % 2 == 0) {
            joueur1[i] = true; // indique que le joueur a un marqueur dans la case i
            couleurs[i] = "#ffff09"; // on colorie la case à la couleur du joueur
            infos = "Joueur 2, à vous de jouer!"; // annonce que c'est au tour du joueur suivant
        } else {
            joueur2[i] = true;
            couleurs[i] = "#04f2ff";
            infos = "Joueur 1, à vous de jouer!";
        }
        tapisVide[i] = false; // on met à jour la liste tapisVide
        compteur++; // on incrémente le compteur
    }
}


bool Moteur::gagne(int joueur){
    bool res = false;
    int i = 0;
    // on vérifie si les cases marquées par le joueur correspondent à l'une des configurations gagnantes dans listeGagnante
    // et ce à l'aide d'une boucle parcourant la listeGagnante
    if (joueur == 1){
        while (!res && i < 8) {
            res = (joueur1[listeGagnante[i][0]]) && (joueur1[listeGagnante[i][1]]) && (joueur1[listeGagnante[i][2]]);
            i++;
        }
    } else {
        while (!res && i < 8) {
            res = (joueur2[listeGagnante[i][0]]) && (joueur2[listeGagnante[i][1]]) && (joueur2[listeGagnante[i][2]]);
            i++;
        }
    }
    return res;
}


void Moteur::deplace(int i){
    // on vérifie d'abord que la case d'arrivée est libre, et que celle-ci appartient aux cases accessibles depuis la case sélectionnée
    if ((tapisVide[i]) && (cases[caseSelected]->deplPossible(i))) {
        if (compteur % 2 == 0){ // si c'est le joueur 1 qui joue
            // on met à jour la liste joueur
            joueur1[i] = true;
            joueur1[caseSelected] = false;
            // on met à jour l'IG
            couleurs[i] = "#ffff09";
            infos = "Joueur 2, à vous de jouer!";
        } else { // si c'est le joueur 2 qui joue
            joueur2[i] = true;
            joueur2[caseSelected] = false;
            couleurs[i] = "#04f2ff";
            infos = "Joueur 1, à vous de jouer!";
        }
        couleurs[caseSelected] = "#ffffff"; // on décolorie la case auparavant sélectionnée
        // on met à jour le tapis de jeu
        tapisVide[i] = false;
        tapisVide[caseSelected] = true;
        deselectionne(); // on déselectionne la case auparavant sélectionnée (voir plus bas)
        compteur++; // on incrémente le compteur
    }
}

void Moteur::selectionne(int i){
    // on vérifie que le joueur en question a bien un marqueur dans cette case
    if ( ((compteur % 2 == 0) && (joueur1[i])) || ((compteur % 2 == 1) && (joueur2[i])) ){
        selected = true; // le joueur a bien sélectionné une case
        caseSelected = i; // la case sélectionné est la i-ème case
        bords[caseSelected] = "#fe0000"; // on colorie en rouge les bords de la i-ème case pour montrer la sélection

        // on colorie en couleur claire (ici rose) les cases atteignables, et non déjà occupées, depuis la case sélectionnée
        for (int j = 0; j < cases[i]->getTailleDepl(); j++){
            if(tapisVide[cases[i]->getDeplacements()[j]])
                couleurs[cases[i]->getDeplacements()[j]] = "#F6CECE";
        }
    }
}


void Moteur::deselectionne(){
    selected = false; // on annule la sélection
    bords[caseSelected] = "#000000"; // on colorie par défaut (en noir) les bords de la case auparavant sélectionnée

    // on colorie par défaut (en blanc) les cases correspondant aux cases possibles coloriées lors de la sélection
    for (int j = 0; j < 9; j++){
        if(tapisVide[j])
            couleurs[j] = "#ffffff";
    }
}


// --- Fonctions de lecture des élements pour la mise à jour de l'IG ---

QString Moteur::readInfos(){
    return QString::fromStdString(infos);
} // renvoie le message d'information sous forme de QString, exploitable dans le qml


QList<QString> Moteur::readBords(){
    QList<QString> res;
    for(int i = 0 ; i < 9 ; i++)
        res.append(QString::fromStdString(bords[i]));
    return res;
} // renvoie la liste de la couleur des bords sous forme d'une liste de QString, exploitable dans le qml


QList<QString> Moteur::readCouleurs(){
    QList<QString> res;
    for(int i = 0 ; i < 9 ; i++)
        res.append(QString::fromStdString(couleurs[i]));
    return res;
} // renvoie la liste de la couleur des cases sous forme d'une liste de QString, exploitable dans le qml


bool Moteur::readEtatCases(){
    return etatCases;
} // renvoie le booléen de l'état des cases
