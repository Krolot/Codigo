#include <iostream>
using namespace std;

class TPlayer {
public:
    // Constructor
    TPlayer(string IName, string IModel, int IHealth, int ISpeed, int IStamina, int IAim, int IStrenght, int IOther) {
        name = IName;
        model = IModel;
        hp = IHealth;
        speed = ISpeed;
        stamina = IStamina;
        aim = IAim;
        strenght = IStrenght;
        other = IOther;
    };

    //getters de todo

    string getName()
    {
        return name;
    }

    string getModel()
    {
        return model;
    }

    int getHealth()
    {
        return hp;
    }

    int getSpeed()
    {
        return speed;
    }

    int getStamina()
    {
        return stamina;
    }

    int getAim()
    {
        return aim;
    }

    int getHitStrenght()
    {
        return strenght;
    }
    /*
    Stats base
    void ShowStats() {
        cout << "=== Estadisticas de " << Default.getName() << " ===" << endl;
        cout << "Modelo: " << Default.getModel() << endl;
        cout << "Vida: " << Default.getHealth() << endl;
        cout << "Velocidad: " << Default.getSpeed() << " unidades/segundo" << endl;
        cout << "Stamina: " << Default.getStamina() << endl;
        cout << "Nivel de apuntado: " << Default.getAim() << endl;
        cout << "Fuerza de golpe: " << Default.getHitStrenght() << endl;
        cout << "Extra: NULL" << endl;
        cout << "============================" << endl;
    }
    */

    //la parte privada
private:
    string name, model;
    int hp, strenght, speed, stamina, aim, other;
};

    //el codigo principal
int main() {

    /*
    La logica general de Surv1
    Proposito: Hacer que el Surv1 tenga las caracteristicas unicas necesrias
    */

    TPlayer Surv1("Survivor_1", "models/players/surv1.mdl", 125, 275, 50, 1, 15, 0);

    /*
    La logica general de Surv2
    Proposito: Hacer que el Surv2 tenga las caracteristicas unicas necesrias
    */
    
    TPlayer Surv2("Survivor_2", "models/players/surv2.mdl", 75, 400, 75, 1, 5, 0);

    /*
    La logica general de Surv3
    Proposito: Hacer que el Surv3 tenga las caracteristicas unicas necesrias
    */

    TPlayer Surv3("Survivor_3", "models/players/surv3.mdl", 100, 300, 100, 10, 10, 0);

    /*
    Default, si no funcionan los demas, o si se utiliza el personaje en multijugador
    Proposito: Evitar errores si no se inicializa el resto
    */

    TPlayer Default("Default", "models/players/player.mdl", 100, 300, 10, 1, 7, 0);

    //Menu

    //opciones para el switch
    int option;

    //escape
    int escape;

    //Menu principal
    cout << "===== Estadisticas de los Personajes =====" << endl;
    cout << "1. Ver las estadisticas de " << Surv1.getName() << endl;
    cout << "2. Ver las estadisticas de " << Surv2.getName() << endl;
    cout << "3. Ver las estadisticas de " << Surv3.getName() << endl;
    cout << "0. Salir" << endl;
    cout << "Elige una opcion: ";

    //Obtiene el numero, del 0 al 3
    cin >> option;

    switch (option)
    {
        //Si es 0, skipea y termina el programa
    case 0:
        break;
    case 1:
    //Muestra estadisticas del surv, y asi con los otros 2
        cout << "=== Estadisticas de " << Surv1.getName() << " ===" << endl;
        cout << "Modelo: " << Surv1.getModel() << endl;
        cout << "Vida: " << Surv1.getHealth() << endl;
        cout << "Velocidad: " << Surv1.getSpeed() << " unidades/segundo" << endl;
        cout << "Stamina: " << Surv1.getStamina() << endl;
        cout << "Nivel de apuntado: " << Surv1.getAim() << endl;
        cout << "Fuerza de golpe: " << Surv1.getHitStrenght() << endl;
        cout << "Extra: NULL" << endl;
        cout << "============================" << endl;
        break;
    case 2:
        cout << "=== Estadisticas de " << Surv2.getName() << " ===" << endl;
        cout << "Modelo: " << Surv2.getModel() << endl;
        cout << "Vida: " << Surv2.getHealth() << endl;
        cout << "Velocidad: " << Surv2.getSpeed() << " unidades/segundo" << endl;
        cout << "Stamina: " << Surv2.getStamina() << endl;
        cout << "Nivel de apuntado: " << Surv2.getAim() << endl;
        cout << "Fuerza de golpe: " << Surv2.getHitStrenght() << endl;
        cout << "Extra: NULL" << endl;
        cout << "============================" << endl;
        break;
    case 3:
        cout << "=== Estadisticas de " << Surv3.getName() << " ===" << endl;
        cout << "Modelo: " << Surv3.getModel() << endl;
        cout << "Vida: " << Surv3.getHealth() << endl;
        cout << "Velocidad: " << Surv3.getSpeed() << " unidades/segundo" << endl;
        cout << "Stamina: " << Surv3.getStamina() << endl;
        cout << "Nivel de apuntado: " << Surv3.getAim() << endl;
        cout << "Fuerza de golpe: " << Surv3.getHitStrenght() << endl;
        cout << "Extra: NULL" << endl;
        cout << "============================" << endl;
        break;
        //en caso de poner letras o un numero invalido
    default:
        cout << "=== Estadisticas de " << Default.getName() << " ===" << endl;
        cout << "Modelo: " << Default.getModel() << endl;
        cout << "Vida: " << Default.getHealth() << endl;
        cout << "Velocidad: " << Default.getSpeed() << " unidades/segundo" << endl;
        cout << "Stamina: " << Default.getStamina() << endl;
        cout << "Nivel de apuntado: " << Default.getAim() << endl;
        cout << "Fuerza de golpe: " << Default.getHitStrenght() << endl;
        cout << "Extra: NULL" << endl;
        cout << "============================" << endl;
        break;
    }
    //finalmente la salida del programa
    cout << "Escribe lo que quieras para terminar el programa" << endl;

    //intente conseguir una solucion para que el cmd no se cerrara inmediatamente a la hora de terminar pero no encontre nada en internet, asi que hice que el usuario pusiera texto antes de que se termine.
    cin >> escape;
    return 0;
}
