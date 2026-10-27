// Q1: Reponse : Le programme affiche 20.
// Q2:Passage par valeur : une copie de la variable est transmise a la fonction. Les modifications ne changent pas la variable originale.  
//  Passage par reference : la fonction travaille directement sur la variable originale. Les modifications sont conservees apres l'appel.
// Q3:
#include <iostream>
using namespace std;

void modifier(int &a, int &b) {
    a += 5;
    b += 10;
}

int main() {
    int x = 10, y = 20;

    modifier(x, y);

    cout << y << endl;

    return 0;
}
// Q4: L'operateur &, place dans la declaration d'un parametre, indique que ce parametre est une reference a  la variable originale. Il permet de modifier directement cette variable sans creer une copie.
