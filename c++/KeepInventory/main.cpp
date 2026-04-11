//El programa le permitira al usuario ingresar sus ventas, 
//calcular el profit y mostrarle su balance actual.

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

ofstream salesFile("sales.txt", ios::app);

string sale;
int profit, investment = 0;
int salesAmount;


void AppStart();
int SelectOption();
int AddSales();
int LoadLastID();
void WantToContinue();



int main() {
    salesAmount = LoadLastID(); 
    AppStart();
    return 0;
}

void AppStart()
{
    cout << "Bienvenido a la aplicacion de ventas!" << endl;
    cout << "Que deseas ver?" << endl;
    cout << "1. Ingresar ventas" << endl;
    cout << "2. Ver datos" << endl;
    cout << "3. Ver logs" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: " << endl;
    SelectOption();
}

int SelectOption()
{
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
        AddSales();
        break;
    case 2:
        cout << "Ver datos" << endl;
        break;
    case 3:
        cout << "Ver logs" << endl;
        break;
    case 4:
        cout << "Salir" << endl;
        break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }
    return 0;
}

int AddSales()
{

    cout << "Ingrese cuanto dinero gano y cuanto gasto: " << endl;
    cin >> profit >> investment;
    salesAmount++;

    salesFile << salesAmount << ". " << "Profit: " << profit << " Investment: " << investment << endl;
    sale = to_string(salesAmount) + ". Profit: " + to_string(profit) + " Investment: " + to_string(investment);
    cout << sale << endl;

    if (salesFile.is_open()) 
    {
        salesFile.close();
    } 
    else 
    {
        cout << "No se pudo abrir el archivo para escribir." << endl;
    }
    WantToContinue();
    return 0;

}

void WantToContinue()
{
    char option;
    cout << "Desea continuar? (Y/N): " << endl;
    cin >> option;

    if (option == 'Y' || option == 'y') {
        system("cls");
        AppStart();
    }
     else if (option == 'N' || option == 'n') {
        cout << "Gracias por usar la aplicacion!" << endl;
        Sleep(2000);
    } 
    else {
        cout << "Opcion no valida, regresando al menu principal." << endl;
        Sleep(2000);
        system("cls");
        AppStart();
    }
}

int LoadLastID() {
    ifstream fileRead("sales.txt");
    string line;
    int count = 0;
    
    if (fileRead.is_open()) {
        while (getline(fileRead, line)) {
            if (!line.empty()) count++; // Cuenta cada línea no vacía como una venta
        }
        fileRead.close();
    }
    return count;
}
