#pragma once
#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "sll_item_t.hpp"

using namespace std;


class sll_t 
{
    private:
    
        sll_item_t* inicio_;
        sll_item_t* fin_;
        int size_;

    public:
    
        sll_t(void);
        sll_t(const sll_t& lista);
        virtual ~sll_t(void); // Elimina la lista pero no la información

        void push_back(sll_item_t*);
        sll_item_t* pop_front(void);
        sll_item_t* pop_back(void);

        bool empty(void);

        void remove(sll_item_t*);

        void clear(void); // Borra el sólo el nodo y no borra el dato
        void clean(void); // Borra el nodo y el dato
      
        int size(void);

        void write(std::ostream& os);

    };