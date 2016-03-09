#pragma once
#include <cstdio>
#include <string>
#include "enteros.hpp"


class racionales
{
    private:
    
        double dato;
        
    public:
        racionales();
        void pasar(double numero);
        ~racionales();
        void operarrac(racionales A, racionales B, char op);
        void operarent(enteros A, racionales B, char op);
        double getDato();
};