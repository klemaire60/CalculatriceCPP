#include <iostream>
#include <sstream>
#include <iomanip>
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
// Utilisation de Vecteurs
*/

void showMenu();
static void showHistory(vector<string>& history);
double addition(vector<double>& numbers);
double soustraction(vector<double>& numbers);
double multiplication(vector<double>& numbers);
double division(double a, double b);
double puissance(double nombre, int exposant);
// Fonction remplaçante de to_string pour gérer les décimales
string formatResult(double result);

int main() {
    int choice, exposant;
    double number;
    vector<string> history;

    while (true)
    {
        vector<double> numbers;
        string result;
        showMenu();
        cin >> choice;
        
        if (choice >= 1 && choice <= 7)
        {
            if (choice == 7) {
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
                result += formatResult(numbers[i]) + " + ";
            }
            result += formatResult(numbers[numbers.size() - 1]) + " = " + formatResult(addition(numbers));
            system("cls");
            cout << result << endl;
            history.push_back(result);
            break;

        case 2:
            for (int i = 0; i < numbers.size() - 1; i++)
            {
                result += formatResult(numbers[i]) + " - ";
            }
            result += formatResult(numbers[numbers.size() - 1]) + " = " + formatResult(soustraction(numbers));
            system("cls");
            cout << result << endl;
            history.push_back(result);
            break;

        case 3:
            for (int i = 0; i < numbers.size() - 1; i++)
            {
                result += formatResult(numbers[i]) + " * ";
            }
            result += formatResult(numbers[numbers.size() - 1]) + " = " + formatResult(multiplication(numbers));
            system("cls");
            cout << result << endl;
            history.push_back(result);
            break;

        case 4:
            if (numbers[1] == 0) {
                cout << "Division par 0 impossible" << endl;
                break;
            }
            system("cls");
            cout << numbers[0] << " / " << numbers[1] << " = " << division(numbers[0], numbers[1]) << endl;
            history.push_back(formatResult(numbers[0]) + " / " + formatResult(numbers[0]) + " = " + formatResult(division(numbers[0], numbers[1])));
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
            system("cls");
            cout << number << " ^ " << exposant << " = " << puissance(number, exposant) << endl;
            history.push_back(formatResult(number) + " ^ " + formatResult(exposant) + " = " + formatResult(puissance(number, exposant)));
            break;

        case 6:
            showHistory(history);
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
    cout << "[6] Voir l'historique des calculs" << endl;
    cout << "[7] Quitter" << endl;
}

static void showHistory(vector<string>& history)
{
    system("cls");
    if (history.size() == 0)
    {
        cout << "Aucun calcul fait pour le moment" << endl << endl << endl;
        return;
    }
    for (string calcul : history)
    {
        cout << calcul << endl;
    }
    cout << endl << endl;
}

double addition(vector<double>& numbers)
{
    double result = 0;
    for (double n : numbers) 
    {
        result += n;
    }
    return result;
}

double soustraction(vector<double>& numbers)
{
    double result = numbers[0];
    for (int i = 1; i < numbers.size(); i++) 
    {
        result -= numbers[i];
    }
    return result;
}

double multiplication(vector<double>& numbers)
{
    double result = 1;
    for (double n : numbers)
    {
        result *= n;
    }
    return result;
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
    }
    return result;
}

string formatResult(double result) {
    ostringstream oss;
    if (result == static_cast<int>(result)) {
        // Pas de décimales si c'est un entier
        oss << static_cast<int>(result);
    }
    else {
        // Affiche avec 2 décimales si nécessaire
        oss << fixed << setprecision(2) << result;
    }
    return oss.str();
}