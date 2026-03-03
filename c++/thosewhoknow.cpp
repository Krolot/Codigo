// Este codigo ha sido generado por el modulo psexport 20230904-w32 de PSeInt.
// Es posible que el codigo generado no sea completamente correcto. Si encuentra
// errores por favor reportelos en el foro (http://pseint.sourceforge.net).

#include<iostream>
#include<ctime>
using namespace std;

// No hay en el C++ estandar una funcion equivalente a "esperar", pero puede programarse una similar
void esperar(double t);

// Para leer variables de texto se utiliza el operador << del objeto cin, que
// lee solo una palabra. Para leer una linea completa (es decir, incluyendo los
// espacios en blanco) se debe utilzar getline (ej, reemplazar cin>>x por
// getline(cin,x)), pero obliga a agregar un cin.ignore() si antes del getline
// se leyó otra variable con >>.

int main() {
	string muerte;
	string nombre;
	float opciones;
	float skip;
	muerte = "Te moriste Chamo";
	// Intro
	cout << "Bievenido al Simulador Hiper-Realista de Relaciones Sociales con Algoritmos hechos en 5 MINUTOS. Por favor inserta el disco (Presiona enter)" << endl;
	cin.get(); // a diferencia del pseudocódigo, espera un Enter, no cualquier tecla
	esperar(1*1000);
	cout << "Por favor, pon tu nombre" << endl;
	cin >> nombre;
	cout << "Bienvenido " << nombre << endl;
	esperar(1*1000);
	cout << "Entrando al Juego" << endl;
	esperar(1*1000);
	// Escena 1
	cout << "Quieres Saltar directamente a las opciones o ver la cinematica incial (no recomendado para los que juegan por primera vez)" << endl;
	esperar(1*1000);
	cout << "Escribe 1 para aceptar o 0 para denegar" << endl;
	esperar(1*1000);
	cin >> skip;
	if (skip==0) {
		cout << "Vas caminando por el pasillo cuando te encuentras con Yonkleiberson Lopez, el se detiene y de dice un monton de cosas gays, pero tu no eres gay. Bueno quizas lo eres pero en este caso no" << endl;
		esperar(5*1000);
		cout << "EPA " << nombre << " ,como ta, te preguntaba si queria ve mi toyota skrintitailain que me compre, me costo 50 bolos" << endl;
		esperar(3*1000);
		cout << "Y tambien pa ve si querias invertir en criptomonedas y ir pa los motopiruetas" << endl;
		esperar(3*1000);
		cout << "Que haces:" << endl;
		esperar(2*1000);
		skip = 1;
	}
	if (skip==1) {
		cout << "1. Decir Amablemente que no" << endl;
		cout << "2. Decir que SI, aunque no seas gay" << endl;
		cout << "3. Lanzarte por la ventana (no hay ventana, estas en la calle huevoncio)" << endl;
		cout << "4. Nada" << endl;
		esperar(3*1000);
		cin >> opciones;
		if (opciones==1) {
			cout << "De pronto, Yonkleiberson Lopez saca su Bichereta, o asi es como le llama a una Pistola 9mm y te dispara en la jeta." << endl;
			esperar(2*1000);
			cout << muerte << endl;
		}
		if (opciones==2) {
			cout << "Yonkleiberson y tu van a hacer esa monda y de la nada la toyota skrintitailain te pasa por encima junto a los 50 motopiruetas" << endl;
			esperar(2*1000);
			cout << muerte << endl;
		}
		if (opciones==3) {
			cout << "Si habia ventana, solo que era pa dentro de una casa, entonces los que vivian ahi te dispararon" << endl;
			esperar(2*1000);
			cout << muerte << endl;
		}
		if (opciones==4) {
			cout << "Te mantienes inmovil sin hacer nada" << endl;
			esperar(2*1000);
			cout << muerte << endl;
		}
		// Good Ending
		if (opciones==5) {
			cout << "Sobreviviste, Pensaste fuera de la caja" << endl;
			esperar(2*1000);
			cout << "Yonkleiberson Lopez te dice: " << nombre << " chamito, tu develdad ere un genio. Sigue asi chamito" << endl;
			esperar(3*1000);
			cout << "Entonces asi termina tu travesia en esta bella historia" << endl;
		}
		// La cagaste Chamo
		if (opciones>=6) {
			cout << "matate, es el jodido numero 5 que debias usar" << endl;
			esperar(2*1000);
			cout << muerte << endl;
		}
	}
	// Fin
	esperar(1*1000);
	cout << "Fin" << endl;
	esperar(1*1000);
	return 0;
}


void esperar(double t) {
	clock_t t0 = clock();
	double e = 0;
	do {
		e = 1000*double(clock()-t0)/CLOCKS_PER_SEC;
	} while (e<t);
}

