
#include <iostream>
#include <string>
using namespace std;

class Compte {
private:
    int identifiant;
    string nomProprietaire;
    double solde;

public:
    
    Compte(int id, string nom, double montant) {
        identifiant = id;
        nomProprietaire = nom;
        solde = montant;
    }

   
    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
        }
    }

    
    void retirer(double montant) {
        if (montant > 0 && montant <= solde) {
            solde -= montant;
        }
    }

    
    void afficher() {
        cout << "Identifiant : " << identifiant << endl;
        cout << "Proprietaire : " << nomProprietaire << endl;
        cout << "Solde : " << solde << endl;
    }
};

int main() {
    Compte c1(1, "Sara", 1000);
    Compte c2(2, "Ali", 500);

    c1.deposer(200);
    c2.retirer(100);

    cout << "--- Compte 1 ---" << endl;
    c1.afficher();

    cout << "--- Compte 2 ---" << endl;
    c2.afficher();

    return 0;
}
