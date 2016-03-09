#pragma once
#include <cstdio>
#include <string>
#include "enteros.hpp"
#include "racionales.hpp"


class complejos
{
    private:
    
        double real;
        double imag;
        
    public:
        complejos();
        void pasar(double r, double i);
        ~complejos();
        void operarcom(complejos A, complejos B, char op);
        void operarrac(racionales A, complejos B, char op);
        void operarent(enteros A, complejos B, char op);
        double getReal();
        double getImag();
        void copiar(double img);
};