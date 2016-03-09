#include <iostream>
#include <cstdio>
#include <string>
#include "stack_template_t.hpp"
using namespace std;

class calculadora
{
    private:
    
        stack_template_t<string> pila;
    
    public:
        
        calculadora(void);
        ~calculadora(void);
        void parse(void);
        void calcular(char op);
};