#include "moteur.h"

Moteur::Moteur(QObject *parent) : QObject(parent)
{
    for(int i = 0; i < 9; i++)
        cases[i] = new Case(i);
    initialisation();

    changeInfos();
    changeBords();
    changeCouleurs();
    changeEtatCases();
}


void Moteur::initialisation(){
    compteur = 0;
    selected = false;
    caseSelected = -1;
    infos = "Joueur 1, à vous de jouer!";
    etatCases = true;
    for(int i = 0; i < 9; i++){
        tapisVide[i] = true;
        joueur1[i] = false;
        joueur2[i] = false;
        bords[i] = "#000000";
        couleurs[i] = "#ffffff";
    }
}


void Moteur::nouvellePartie(){
    initialisation();
    changeInfos();
    changeBords();
    changeCouleurs();
    changeEtatCases();
}


void Moteur::clique(int i){

    int joueur = compteur % 2 + 1;

    if (compteur <= 5) {
        place(i);
    } else {
        if (!selected) {
            selectionne(i);
        } else if (selected && caseSelected == i) {
            deselectionne();
        } else {
            deplace(i);
        }
    }

    if (gagne(joueur)){
        if (joueur == 1){
            infos = "Bravo Joueur 1 ! Vous avez gagné !";
            for(int j = 0; j<9; j++){
                if(joueur1[j]) {
                    bords[j] = "#00ff00";
                } else if (joueur2[j]){
                } else {
                    couleurs[j] = "#ebebeb";
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
        etatCases = false;
        changeEtatCases();
    }

    changeInfos();
    changeBords();
    changeCouleurs();

}


void Moteur::place(int i){
    if (tapisVide[i]) {
        if (compteur % 2 == 0) {
            joueur1[i] = true;
            couleurs[i] = "#ffff09";
            infos = "Joueur 2, à vous de jouer!";
        } else {
            joueur2[i] = true;
            couleurs[i] = "#04f2ff";
            infos = "Joueur 1, à vous de jouer!";
        }
        tapisVide[i] = false;
        compteur++;
    }
}


bool Moteur::gagne(int joueur){
    bool res = false;
    int i = 0;
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
    if ((tapisVide[i]) && (cases[caseSelected]->deplPossible(i))) {
        if (compteur % 2 == 0){
            joueur1[i] = true;
            joueur1[caseSelected] = false;
            couleurs[i] = "#ffff09";
            infos = "Joueur 2, à vous de jouer!";
        } else {
            joueur2[i] = true;
            joueur2[caseSelected] = false;
            couleurs[i] = "#04f2ff";
            infos = "Joueur 1, à vous de jouer!";
        }
        couleurs[caseSelected] = "#ffffff";
        tapisVide[i] = false;
        tapisVide[caseSelected] = true;
        deselectionne();
        compteur++;
    }
}

void Moteur::selectionne(int i){
    if ( ((compteur % 2 == 0) && (joueur1[i])) || ((compteur % 2 == 1) && (joueur2[i])) ){
        selected = true;
        caseSelected = i;
        bords[caseSelected] = "#fe0000";

        for (int j = 0; j < cases[i]->getTailleDepl(); j++){
            if(tapisVide[cases[i]->getDeplacements()[j]])
                couleurs[cases[i]->getDeplacements()[j]] = "#F6CECE";
        }
    }
}


void Moteur::deselectionne(){
    selected = false;
    bords[caseSelected] = "#000000";

    for (int j = 0; j < 9; j++){
        if(tapisVide[j])
            couleurs[j] = "#ffffff";
    }
}


QString Moteur::readInfos(){
    return QString::fromStdString(infos);
}


QList<QString> Moteur::readBords(){
    QList<QString> res;
    for(int i = 0 ; i < 9 ; i++)
        res.append(QString::fromStdString(bords[i]));
    return res;
}


QList<QString> Moteur::readCouleurs(){
    QList<QString> res;
    for(int i = 0 ; i < 9 ; i++)
        res.append(QString::fromStdString(couleurs[i]));
    return res;
}


bool Moteur::readEtatCases(){
    return etatCases;
}
