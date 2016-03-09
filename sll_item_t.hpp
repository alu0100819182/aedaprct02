#pragma once
#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
  
class sll_item_t 
{
    public:
        
        sll_item_t* next_;
        sll_item_t* prev_;

    public:
        sll_item_t();
        sll_item_t(sll_item_t* prev, sll_item_t* next);
        virtual ~sll_item_t(void);
        virtual void write(std::ostream& os) {};
        virtual sll_item_t* copy(void) {return NULL;}
        virtual void clean(void) {}
};