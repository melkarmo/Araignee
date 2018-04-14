#ifndef CASE_H
#define CASE_H

// Classe d'une case de jeu (voir moteur.h au préalable pour plus de clarté)
class Case
{
public:

    // une Case correspond à l'une des 9 cases de la "toile" du jeu de l'araignée

    Case(int i); // constructeur

    int* getDeplacements(); // getter de "deplacements" (voir plus bas)
    int getTailleDepl(); // getter de "tailleDepl" (voir plus bas)
    bool deplPossible(int j); // renvoie true si la case j est accessible depuis cette case, et false sinon

private: // --- Attributs ---

    int numero; // numéro de la case suivant la numérotation choisie pour la toile (voir moteur.h)
    int* deplacements; // liste des indices des cases accessibles depuis cette case
    int tailleDepl; // taille de la liste précédente
};

#endif // CASE_H
