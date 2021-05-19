#ifndef BRIQUES_H
#define BRIQUES_H

#include <vector>
#include <iostream>
using namespace std;

class Briques
{
public:
    int x,y;
    int r;
    int c=5; //collone
    int w=90; // largeur
    int h=10; // hauteur
    int p=20; // padding
    int ox=40; // offsetX
    int oy=40; // offsetY
    bool status; // brique casée ou pas
    vector<Briques> b_array; // vecteur de la class Briques
public:
    Briques();
    ~Briques() {};
    void setBriques();
    void display();
};


#endif
