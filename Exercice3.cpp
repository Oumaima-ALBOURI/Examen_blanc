#include <iostream>
#include <string>
#include <vector>

using namespace std;

// --- 1 & 2. Définition de la classe mère Vehicule ---
class Vehicule {
protected: // Attributs protégés (accessibles par les classes dérivées)
    string immatriculation;
    string marque;
    double vitesseMax; // nombre réel

public:
    // 2. Constructeur paramétré
    Vehicule(string imm, string mq, double vMax) 
        : immatriculation(imm), marque(mq), vitesseMax(vMax) {}

    // Méthode virtuelle (permet le polymorphisme)
    virtual void afficherDetails() const {
        cout << "Immatriculation : " << immatriculation 
             << " | Marque : " << marque 
             << " | Vitesse Max : " << vitesseMax << " km/h";
    }

    // Bonne pratique : Destructeur virtuel
    virtual ~Vehicule() {}
};

// --- 3 & 4. Définition de la classe dérivée Voiture ---
class Voiture : public Vehicule {
private:
    int nombrePortes;
    string typeCarburant;

public:
    // 3. Constructeur de la classe dérivée
    Voiture(string imm, string mq, double vMax, int portes, string carburant)
        : Vehicule(imm, mq, vMax), nombrePortes(portes), typeCarburant(carburant) {}

    // 4. Redéfinition de la méthode virtuelle
    void afficherDetails() const override { // 'override' est optionnel mais sécurise le code
        cout << "[Voiture] ";
        Vehicule::afficherDetails(); // Appel de la méthode de la classe mère
        cout << " | Portes : " << nombrePortes 
             << " | Carburant : " << typeCarburant << endl;
    }
};

// --- 3 & 4. Definition de la classe derivee Camion ---
class Camion : public Vehicule {
private:
    double capaciteCharge;
    int nombreEssieux;

public:
    // 3. Constructeur de la classe derivee
    Camion(string imm, string mq, double vMax, double capacite, int essieux)
        : Vehicule(imm, mq, vMax), capaciteCharge(capacite), nombreEssieux(essieux) {}

    // 4. Redefinition de la methode virtuelle
    void afficherDetails() const override {
        cout << "[Camion]  ";
        Vehicule::afficherDetails(); 
        cout << " | Charge : " << capaciteCharge << " t" 
             << " | Essieux : " << nombreEssieux << endl;
    }
};

// --- 5. Fonction main ---
int main() {
    // 5. Creation d'un tableau de pointeurs de type Vehicule
    // (Utilisation de std::vector pour une meilleure gestion, ou tableau classique Vehicule* tab[2])
    Vehicule* flotte[2];

    // Ajout d'une voiture et d'un camion
    flotte[0] = new Voiture("AB-123-CD", "Peugeot", 180.0, 5, "Essence");
    flotte[1] = new Camion("XY-987-ZW", "Volvo", 110.5, 18.5, 4);

    cout << "--- Affichage des details de la flotte (Polymorphisme) ---" << endl;
    
    // Parcours du tableau et affichage
    for (int i = 0; i < 2; ++i) {
        // Grace au mot-cle 'virtual' dans la classe mere, 
        // c'est la bonne methode (Voiture ou Camion) qui sera appelee ici.
        flotte[i]->afficherDetails(); 
    }

    // Liberation de la memoire allouee dynamiquement
    delete flotte[0];
    delete flotte[1];

    return 0;
}