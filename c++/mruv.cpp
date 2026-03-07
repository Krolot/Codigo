#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;

float DistanciaFinal(float xo, float vo, float t, float a)
{
    return xo + vo * t + a * powf(t, 2) / 2;
}

float Tiempo(float vo, float vf, float a)
{
    return (vf - vo) / a;
}

float VelocidadFinal(float vo, float a, float t)
{
    return vo + a * t;
}

float VelocidadInicial(float vf, float a, float t)
{
    return vf - a * t;
}

float Aceleracion(float vo, float vf, float t)
{
    return (vf - vo) / t;
}

int main()
{
    cout << DistanciaFinal(0, 0, 10, 2) << endl;
    cout << Tiempo(0, 20, 2) << endl;
    cout << VelocidadFinal(0, 2, 10) << endl;
    cout << VelocidadInicial(20, 2, 10) << endl;
    cout << Aceleracion(0, 20, 10) << endl;
    return 0;
}
