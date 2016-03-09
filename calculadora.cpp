#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include "calculadora.hpp"
#include "enteros.hpp"
#include "racionales.hpp"
#include "complejos.hpp"
#include <cstdlib>
#include <sstream>
#include <vector>
using namespace std;

calculadora::calculadora()
{}

calculadora::~calculadora()
{}

void calculadora::parse(void)
{
    string archivo ;
    cout << "Introduzca el nombre del archivo" << endl;
    cin >> archivo;
    ifstream ficheroEntrada(archivo.c_str());
    string i;
    if ( ! ficheroEntrada)
        cout << "No se ha podido abrir el fichero"<<endl;
    else
    {
        while (! ficheroEntrada.eof() )
        {
            ficheroEntrada >> i;
            if(i[0]=='+')
            {
                calcular(i[0]);   
            }
            else
            {
                if(i[0]=='+')
                {
                   calcular(i[0]); 
                }
                else
                {
                    if(i[0]=='-')
                    {
                        calcular(i[0]);   
                    }
                    else
                    {
                        if(i[0]=='*') 
                        {
                            calcular(i[0]);     
                        }
                        else
                        {
                            if(i[0]=='/')
                            {
                                calcular(i[0]);      
                            }
                            if((i[0]=='0')||(i[0]=='1')||(i[0]=='2')||(i[0]=='3')||(i[0]=='4')||(i[0]=='5')||(i[0]=='6')||(i[0]=='7')||(i[0]=='8')||(i[0]=='9'))
                            {
                                pila.push(i); 
                            }
                        }
                    }
                }
            }
        }
    }
}

void calculadora::calcular(char op)
{
    enteros A;
    enteros B;
    racionales D;
    racionales E;
    complejos G;
    complejos H;
    string valoruno;
    string valordos;
    string valorentrante;
    int aux1;
    int aux2;
    int converorent;
    double conversordou;
    int dummy = 1;
    double re;
    double im;
    vector<string> complex;
    while ( dummy == 1) 
    {
        vector<string> complex;
        valoruno = pila.pop();
        if(valoruno.find('i')!=string::npos)
        {
            int found = valoruno.find("+");
            if(found!=-1)
            {
                complex.push_back(valoruno.substr(0,found));
                complex.push_back(valoruno.substr(found+1,valoruno.size()));
                complex[1] = complex[1].substr(0,complex[1].size()-1);
                re = atof(complex[0].c_str());
                im = atof(complex[1].c_str());
                G.pasar(re, im);
                aux1 = 3;
            }
            else
            {
                int found = valoruno.find("-"); 
                complex.push_back(valoruno.substr(0,found));
                complex.push_back(valoruno.substr(found+1,valoruno.size()));
                complex[1] = complex[1].substr(0,complex[1].size()-1);
                re = atof(complex[0].c_str());
                im = atof(complex[1].c_str());
                G.pasar(re, im);
                aux1 = 3;
            }
        }
        else
        {
            if(valoruno.find('.')!=string::npos)
            {
                conversordou = atof(valoruno.c_str());
                D.pasar(conversordou);  
                aux1 = 2;    
            }
            else
            {
                if(valoruno.find('e')!=string::npos)
                {
                    cout << " e " << endl;   
                }
                else
                {
                    converorent = atoi(valoruno.c_str());
                    A.pasar(converorent);  
                    aux1 = 1;
                }
            }
        }
        if(!pila.empty()) {
            valordos = pila.pop();
            vector<string> complex;
        if(valordos.find('i')!=string::npos)
        {
            int found = valordos.find("+");
            if(found!=-1)
            {
                complex.push_back(valordos.substr(0,found));
                complex.push_back(valordos.substr(found+1,(valordos.size())));
                complex[1] = complex[1].substr(0,complex[1].size()-1);
                re = atof(complex[0].c_str());
                im = atof(complex[1].c_str());
                H.pasar(re, im);
                aux2 = 3;
            }
            else
            {
                int found = valordos.find("-"); 
                complex.push_back(valordos.substr(0,found));
                complex.push_back(valordos.substr(found+1,valordos.size()));
                complex[1] = complex[1].substr(0,complex[1].size()-1);
                re = atof(complex[0].c_str());
                im = atof(complex[1].c_str());
                H.pasar(re, im);
                aux2 = 3;
            }
        }
        else
        {
            if(valordos.find('.')!=string::npos)
            {
                conversordou = atof(valordos.c_str());
                E.pasar(conversordou);  
                aux2 = 2;      
            }
            else
            {
                if(valordos.find('e')!=string::npos)
                {
                    
                }
                else
                {
                    converorent = atoi(valordos.c_str());
                    B.pasar(converorent);  
                    aux2 = 1;     
                }
            }
        }
        }
        
        
    if((aux1==1)&&(aux2==1)&&(op=='+'))
    {
        enteros C;
        C.suma(A,B);
        int guardar = C.getDato();
        std::stringstream flujo;
        flujo << guardar;
        valorentrante = flujo.str();
        cout << endl;
        cout << " Valor nuevo de pila " << valorentrante << endl;
        pila.push(valorentrante);
    }
    if((aux1==1)&&(aux2==1)&&(op=='-'))
    {
        enteros C;
        C.resta(B,A);
        int guardar = C.getDato();
        std::stringstream flujo;
        flujo << guardar;
        valorentrante = flujo.str();
        cout << endl;
        cout << " Valor nuevo de pila " << valorentrante << endl;
        pila.push(valorentrante);
    }
    if((aux1==1)&&(aux2==1)&&(op=='*'))
    {
        enteros C;
        C.producto(B,A);
        int guardar = C.getDato();
        std::stringstream flujo;
        flujo << guardar;
        valorentrante = flujo.str();
        cout << endl;
        cout << " Valor nuevo de pila " << valorentrante << endl;
        pila.push(valorentrante);
    }
    if((aux1==1)&&(aux2==1)&&(op=='/'))
    {
        enteros C;
        C.division(B,A);
        int guardar = C.getDato();
        std::stringstream flujo;
        flujo << guardar;
        valorentrante = flujo.str();
        cout << endl;
        cout << " Valor nuevo de pila " << valorentrante << endl;
        pila.push(valorentrante);
    }
    if((aux1==2)&&(aux2==2))
    {
        racionales F;
        F.operarrac(D,E,op);
        double guardar = F.getDato();
        std::stringstream flujo;
        flujo << guardar;
        valorentrante = flujo.str();
        cout << endl;
        cout << " Valor nuevo de pila " << valorentrante << endl;
        pila.push(valorentrante);
    }
    if((aux1==1)&&(aux2==2))
    {
        racionales F;
        F.operarent(A,E,op);
        double guardar = F.getDato();
        std::stringstream flujo;
        flujo << guardar;
        valorentrante = flujo.str();
        cout << endl;
        cout << " Valor nuevo de pila " << valorentrante << endl;
        pila.push(valorentrante);
    }
    if((aux1==2)&&(aux2==1))
    {
        racionales F;
        F.operarent(B,D,op);
        double guardar = F.getDato();
        std::stringstream flujo;
        flujo << guardar;
        valorentrante = flujo.str();
        cout << endl;
        cout << " Valor nuevo de pila " << valorentrante << endl;
        pila.push(valorentrante);
    }
    if((aux1==3)&&(aux2==3))
    {
        complejos I;
        I.operarcom(G,H,op);
        double guardar = I.getReal();
        std::stringstream flujo;
        flujo << guardar;
        valorentrante = flujo.str();
        double guardardos = I.getImag();
        std::stringstream flujodos;
        flujodos << guardardos;
        string concatenar = flujodos.str();
        if(I.getImag()>=0)
        {
            valorentrante = valorentrante + "+" + concatenar + "i";
        }
        else
        {
            valorentrante = valorentrante + concatenar + "i";
        }
        cout << endl;
        cout << " Valor nuevo de pila " << valorentrante << endl;
        pila.push(valorentrante);
    }
    if((aux1==3)&&(aux2==2))
    {
        complejos I;
        I.operarrac(E,G,op);
        double guardar = I.getReal();
        std::stringstream flujo;
        flujo << guardar;
        valorentrante = flujo.str();
        double guardardos = I.getImag();
        std::stringstream flujodos;
        flujodos << guardardos;
        string concatenar = flujodos.str();
        if(I.getImag()>=0)
        {
            valorentrante = valorentrante + "+" + concatenar + "i";
        }
        else
        {
            valorentrante = valorentrante + concatenar + "i";
        }
        cout << endl;
        cout << " Valor nuevo de pila " << valorentrante << endl;
        pila.push(valorentrante);
    }
    if((aux1==2)&&(aux2==3))
    {
        complejos I;
        I.operarrac(D,H,op);
        double guardar = I.getReal();
        std::stringstream flujo;
        flujo << guardar;
        valorentrante = flujo.str();
        double guardardos = I.getImag();
        std::stringstream flujodos;
        flujodos << guardardos;
        string concatenar = flujodos.str();
        if(I.getImag()>=0)
        {
            valorentrante = valorentrante + "+" + concatenar + "i";
        }
        else
        {
            valorentrante = valorentrante + "-" + concatenar + "i";
        }
        cout << endl;
        cout << " Valor nuevo de pila " << valorentrante << endl;
        pila.push(valorentrante);
    }
    if((aux1==1)&&(aux2==3))
    {
        complejos I;
        I.operarent(A,H,op);
        double guardar = I.getReal();
        std::stringstream flujo;
        flujo << guardar;
        valorentrante = flujo.str();
        double guardardos = I.getImag();
        std::stringstream flujodos;
        flujodos << guardardos;
        string concatenar = flujodos.str();
        if(I.getImag()>=0)
        {
            valorentrante = valorentrante + "+" + concatenar + "i";
        }
        else
        {
            valorentrante = valorentrante + "-" + concatenar + "i";
        }
        cout << endl;
        cout << " Valor nuevo de pila " << valorentrante << endl;
        pila.push(valorentrante);
    }
    if((aux1==3)&&(aux2==1))
    {
        complejos I;
        I.operarent(B,G,op);
        double guardar = I.getReal();
        std::stringstream flujo;
        flujo << guardar;
        valorentrante = flujo.str();
        double guardardos = I.getImag();
        std::stringstream flujodos;
        flujodos << guardardos;
        string concatenar = flujodos.str();
        if(I.getImag()>=0)
        {
            valorentrante = valorentrante + "+" + concatenar + "i";
        }
        else
        {
            valorentrante = valorentrante + "-" + concatenar + "i";
        }
        cout << endl;
        cout << " Valor nuevo de pila " << valorentrante << endl;
        pila.push(valorentrante);
    }
    aux1 = 0 ;
    aux2 = 0;
    dummy = 0;
    }
}

