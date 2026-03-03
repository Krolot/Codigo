#include <iostream>
#include <Windows.h>

using namespace std;

int PowerOf(int base, int exponent) {
    int resultado = 1;
    
    if (exponent == 0) {
        return 1;
    }
    
    for (int i = 0; i < exponent; i++) {
        resultado *= base;
    }
    
    return resultado;
}

int main() {

    cout << "2^6 = " << PowerOf(2, 6) << endl;
    cout << "3^4 = " << PowerOf(3, 4) << endl;
    cout << "5^0 = " << PowerOf(5, 0) << endl;

    Sleep(10000);
    return 0;
}
