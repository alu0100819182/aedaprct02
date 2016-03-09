#include <cstdio>
#include <string>
#include "enteros.hpp"

enteros::enteros(void)
{}

enteros::~enteros()
{}

void enteros::pasar(int numero)
{
    dato = numero;
}

void enteros::suma(enteros A, enteros B)
{
    dato = A.dato + B.dato;
}

void enteros::resta(enteros A, enteros B)
{
    dato = A.dato - B.dato;
}

void enteros::producto(enteros A, enteros B)
{
    dato = A.dato * B.dato;
}

void enteros::division(enteros A, enteros B)
{
    dato = A.dato / B.dato;
}

int enteros::getDato()
{
    return dato;
}