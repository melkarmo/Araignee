#ifndef CASE_H
#define CASE_H

class Case
{
public:
    Case(int i);

    int getNumero();
    int* getDeplacements();
    int getTailleDepl();
    bool deplPossible(int i);

private:
    int numero;
    int* deplacements;
    int tailleDepl;
};

#endif // CASE_H
