#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
#include "racionales.hpp"

racionales::racionales(void)
{}

racionales::~racionales()
{}

void racionales::pasar(double numero)
{
    dato = numero;
}

void racionales::operarrac(racionales A, racionales B, char op)
{
    if(op=='+')
        dato = A.dato + B.dato;
    if(op=='-')
        dato = B.dato - A.dato;
    if(op=='*')
        dato = A.dato * B.dato;
    if(op=='/')
        dato = B.dato / A.dato;
}

void racionales::operarent(enteros A, racionales B, char op)
{
    double aux = A.getDato() * 1.0;
    if(op=='+')
        dato = aux + B.dato;
    if(op=='-')
        dato = B.dato - aux;
    if(op=='*')
        dato = aux * B.dato;
    if(op=='/')
        dato = aux / B.dato;
}

double racionales::getDato()
{
    return dato;
}