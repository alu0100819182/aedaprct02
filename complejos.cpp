#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
#include "complejos.hpp"

complejos::complejos(void)
{}

complejos::~complejos()
{}

void complejos::pasar(double r, double i)
{
    real = r;
    imag = i;
}

void complejos::operarcom(complejos A, complejos B, char op)
{
    if(op=='+')
    {
        real = A.real + B.real;
        imag = A.imag + B.imag;
    }
    if(op=='-')
    {
        real = B.real - A.real;
        imag = B.imag - A.imag;
    }
    if(op=='*')
    {
        real = A.real * B.real - A.imag * B.imag;
        imag = A.real * B.imag + A.imag * B.real;
    }
    if(op=='/')
    {
        real = A.real - B.real;
        imag = A.imag - B.imag;
    }
}

void complejos::operarrac(racionales A, complejos B, char op)
{
    if(op=='+')
    {
        real = A.getDato() + B.real;
        imag = B.getImag();
    }
    if(op=='-')
    {
        real = A.getDato() - B.real;
        imag = B.getImag();
    }
    if(op=='*')
    {
        real = A.getDato() * B.real;
        imag = A.getDato() * B.imag;
    }
    if(op=='/')
    {
        real = A.getDato() / B.real;
        imag = A.getDato() / B.imag;
    }
}

void complejos::operarent(enteros A, complejos B, char op)
{
    double aux = A.getDato() * 1.0;
     if(op=='+')
     {
        real = aux + B.real;
        imag = B.getImag();
     }
    if(op=='-')
    {
        real = aux - B.real;
        imag = B.getImag();
    }
    if(op=='*')
    {
        real = aux * B.real;
        imag = aux * B.imag;
    }
    if(op=='/')
    {
        real = aux / B.real;
        imag = aux / B.getImag();
    }
}

double complejos::getReal()
{
    return real;
}

double complejos::getImag()
{
    return imag;
}

void complejos::copiar(double img)
{
    imag = img;
}