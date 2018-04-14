#include "case.h"

// pour la description de la fonction de chaque méthode, voir case.h

Case::Case(int i)
{
    numero = i; // numéro de la case

    // on crée la liste déplacements selon le numéro de la case
    switch(i)
    {
    case 0:{
        tailleDepl = 3; // taille de la liste
        // création et définition de la liste
        deplacements = new int[3];
        deplacements[0] = 1;
        deplacements[1] = 3;
        deplacements[2] = 4;
        break;
    } // idem pour les autres cas
    case 1:{
        tailleDepl = 3;
        deplacements = new int[3];
        deplacements[0] = 0;
        deplacements[1] = 2;
        deplacements[2] = 4;
        break;
    }
    case 2:{
        tailleDepl = 3;
        deplacements = new int[3];
        deplacements[0] = 1;
        deplacements[1] = 4;
        deplacements[2] = 5;
        break;
    }
    case 3:{
        tailleDepl = 3;
        deplacements = new int[3];
        deplacements[0] = 0;
        deplacements[1] = 4;
        deplacements[2] = 6;
        break;
    }
    case 4:{
        tailleDepl = 8;
        deplacements = new int[8];
        deplacements[0] = 0;
        deplacements[1] = 1;
        deplacements[2] = 2;
        deplacements[3] = 3;
        deplacements[4] = 5;
        deplacements[5] = 6;
        deplacements[6] = 7;
        deplacements[7] = 8;
        break;
    }
    case 5:{
        tailleDepl = 3;
        deplacements = new int[3];
        deplacements[0] = 2;
        deplacements[1] = 4;
        deplacements[2] = 8;
        break;
    }
    case 6:{
        tailleDepl = 3;
        deplacements = new int[3];
        deplacements[0] = 3;
        deplacements[1] = 4;
        deplacements[2] = 7;
        break;
    }
    case 7:{
        tailleDepl = 3;
        deplacements = new int[3];
        deplacements[0] = 4;
        deplacements[1] = 6;
        deplacements[2] = 8;
        break;
    }
    case 8:{
        tailleDepl = 3;
        deplacements = new int[3];
        deplacements[0] = 4;
        deplacements[1] = 5;
        deplacements[2] = 7;
        break;
    }
    }

}


int* Case::getDeplacements(){
    return deplacements;
}

int Case::getTailleDepl(){
    return tailleDepl;
}

bool Case::deplPossible(int j){
    bool res = false;
    // test d'appartenance
    for (int h = 0; h<tailleDepl; h++){
        if (deplacements[h] == j)
                res = true;
    }
    return res;
}
