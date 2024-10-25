#include <iostream>
using namespace std;

/*
Etape 1 calculatrice simple
// Penser à la sortie dans le menu de départ
// Penser aux exceptions dans les divisions (ex: 1/0)
// Bonus : Clear la console à chaque opération effectuée

Etape 2 utiliser autant de nombre que l'on veut dans les fonctions (exemple 1 + 2 + 3)
// Vecteurs ??

Etape 3 Créer un historique des calculs
*/

void showMenu();
double addition(double a, double b);
double soustraction(double a, double b);
double multiplication(double a, double b);
double division(double a, double b);
double puissance(double nombre, int exposant);

int main() {
    int choice, exposant;
    double a, b;

    while (true)
    {
        showMenu();
        cin >> choice;
        
        if (choice >= 1 && choice <= 6)
        {
            if (choice == 6) {
                system("cls");
                cout << "Au revoir !" << endl;
                break;
            }

            cout << "Entrer le premier nombre : ";
            cin >> a;

            if (choice != 5) {
                cout << "Entrez le second nombre : ";
                cin >> b;
            }
        }

        switch (choice)
        {
        case 1:
            cout << a << " + " << b << " = " << addition(a, b) << endl;
            break;

        case 2:
            cout << a << " - " << b << " = " << soustraction(a, b) << endl;
            break;

        case 3:
            cout << a << " * " << b << " = " << multiplication(a, b) << endl;
            break;

        case 4:
            if (b == 0) {
                cout << "Division par 0 impossible" << endl;
                break;
            }
            cout << a << " / " << b << " = " << division(a, b) << endl;
            break;

        case 5:
            cout << "Entrez l'exposant : ";
            cin >> exposant;
            cout << a << " ^ " << exposant << " = " << puissance(a, exposant) << endl;
            break;

        default :
            cout << "Option non valide" << endl;
            break;
        }

        system("pause");
        system("cls");
    }
    return 0;
}

void showMenu()
{
    cout << "[1] Addition" << endl;
    cout << "[2] Soustraction" << endl;
    cout << "[3] Multiplication" << endl;
    cout << "[4] Division" << endl;
    cout << "[5] Puissance" << endl;
    cout << "[6] Quitter" << endl;
}

double addition(double a, double b)
{
    return a + b;
}

double soustraction(double a, double b)
{
    return a - b;
}

double multiplication(double a, double b)
{
    return a * b;
}

double division(double a, double b)
{
    return a / b;
}

double puissance(double nombre, int exposant)
{
    double result = nombre;
    for (int i = 1; i < exposant; i++) {
        result = result * nombre;
        // result = multiplication(result, nombre);
    }
    return result;
}