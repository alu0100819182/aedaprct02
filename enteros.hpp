#pragma once
#include <cstdio>
#include <string>

class enteros
{
    private:
    
        int dato;
        
    public:
        enteros();
        void pasar(int numero);
        ~enteros();
        void suma(enteros A, enteros B);
        void resta(enteros A, enteros B);
        void producto(enteros A, enteros B);
        void division(enteros A, enteros B);
        int getDato();
};