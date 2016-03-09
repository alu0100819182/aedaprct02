#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "sll_item_t.hpp"

using namespace std;  
   
    sll_item_t::sll_item_t() :
	next_(NULL),
    prev_(NULL)
	{
    }

    sll_item_t::sll_item_t(sll_item_t* prev, sll_item_t* next) :
    next_(next),
    prev_(prev) {
    }

    sll_item_t::~sll_item_t(void) {
        prev_ = NULL;
        next_ = NULL;
    }