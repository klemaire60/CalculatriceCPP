#include <iostream>
#include <vector>

using namespace std;

/*
Etape 1 calculatrice simple
// Penser à la sortie dans le menu de départ
// Penser aux exceptions dans les divisions (ex: 1/0)
// Bonus : Clear la console à chaque opération effectuée

Etape 2 utiliser autant de nombre que l'on veut dans les fonctions (exemple 1 + 2 + 3)
// Utilisation de Vecteurs 

Etape 3 Créer un historique des calculs
*/

void showMenu();
double addition(vector<double>& numbers);
double soustraction(double a, double b);
double multiplication(double a, double b);
double division(double a, double b);
double puissance(double nombre, int exposant);

int main() {
    int choice, exposant;
    double number;

    while (true)
    {
        vector<double> numbers;
        showMenu();
        cin >> choice;
        
        if (choice >= 1 && choice <= 6)
        {
            if (choice == 6) {
                system("cls");
                cout << "Au revoir !" << endl;
                break;
            }

            if (choice <= 4)
            {
                int i = 0;
                while (true) {
                    if (i == 0)
                    {
                        cout << "Entrez le " << i + 1  << "er nombre ou \"fin\" pour obtenir le resultat : ";
                    }
                    else
                    {
                        cout << "Entrez le " << i +1 << "eme nombre ou \"fin\" pour obtenir le resultat : ";
                    }

                    if (cin >> number) 
                    {
                        numbers.push_back(number);

                        if (choice == 4 && i == 1) break;
                    }
                    else
                    {
                        // Vérifier si la saisie est "fin"
                        string input;
                        cin.clear();
                        cin >> input;
                        if (input == "fin")
                        {
                            if (i >= 2) {
                                break;
                            }
                            cout << "Il faut au minimum 2 nombres" << endl;
                            continue;
                        }
                        else
                        {
                            cout << "Entrez un nombre valide ou \"fin\" pour obtenir le resultat" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
                        }
                    }
                    i++;
                }
            }
        }

        switch (choice)
        {
        case 1:
            for (int i = 0; i < numbers.size() - 1; i++)
            {
                cout << numbers[i] << " + ";
            }
            cout << numbers[numbers.size() - 1] << " = " << addition(numbers) << endl;
            break;

        case 2:
            //cout << a << " - " << b << " = " << soustraction(a, b) << endl;
            break;

        case 3:
            //cout << a << " * " << b << " = " << multiplication(a, b) << endl;
            break;

        case 4:
            if (numbers[1] == 0) {
                cout << "Division par 0 impossible" << endl;
                break;
            }
            cout << numbers[0] << " / " << numbers[1] << " = " << division(numbers[0], numbers[1]) << endl;
            break;

        case 5:
            while (true) {
                cout << "Entrez le nombre : ";
                cin >> number;
                cout << "Entrez l'exposant : ";
                cin >> exposant;
            
                // Vérification de l'entrée utilisateur
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrez un nombre valide !" << endl;
                }
                else
                {
                    break;
                }
            }
            cout << number << " ^ " << exposant << " = " << puissance(number, exposant) << endl;
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

double addition(vector<double>& numbers)
{
    double somme = 0;
    for (double n : numbers) {
        somme += n;
    }
    return somme;
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