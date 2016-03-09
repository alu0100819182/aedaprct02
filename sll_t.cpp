#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "sll_t.hpp"

using namespace std;

sll_t::sll_t(void) :
    inicio_(NULL),
    fin_(NULL),
    size_(0) {
    }

    sll_t::~sll_t(void) {

        clear();
    }

    sll_t::sll_t(const sll_t& lista) :
    inicio_(NULL),
    fin_(NULL),
    size_(0) {
    }

    void sll_t::clear(void) {

        sll_item_t* aux = NULL;

        while (inicio_ != NULL) {
            aux = inicio_;
            inicio_ = inicio_->next_;
            delete aux;
            aux = NULL;
        }
        size_ = 0;
        inicio_ = NULL;
        fin_ = NULL;
    }


    void sll_t::clean(void) {

        sll_item_t* aux = NULL;

        while (inicio_ != NULL) {
			
            aux = inicio_;
            inicio_ = inicio_->next_;
			
			if (aux){
				aux->clean();
				delete aux;				
			}
        }

        size_ = 0;
        inicio_ = NULL;
        fin_ = NULL;
    }


    void sll_t::push_back(sll_item_t* nodo) {

        assert(nodo != NULL);

        if (!inicio_) {
            inicio_ = nodo;
            fin_ = inicio_;
        } else {
            fin_->next_ = nodo;
            nodo->prev_ = fin_;
            fin_ = nodo;
        }

        size_++;
    }

    bool sll_t::empty(void) {
        return (inicio_ == NULL);
    }

    sll_item_t* sll_t::pop_front(void) {

        assert(inicio_ != NULL);

        sll_item_t* aux = inicio_;

        inicio_ = inicio_->next_;

        if (inicio_)
            inicio_->prev_ = NULL;
        else
            fin_ = NULL;

        size_--;

        return aux;
    }

    sll_item_t* sll_t::pop_back(void) {

        assert(fin_ != NULL);

        sll_item_t* aux = fin_;

        fin_ = fin_->prev_;

        if (fin_)
            fin_->next_ = NULL;
        else
            inicio_ = NULL;

        size_--;

        return aux;
    }

    void sll_t::write(std::ostream& os) {
		
        sll_item_t* aux = inicio_;

        while (aux != NULL) {
            aux->write(os);
            aux = aux->next_;
        }
    }

    void sll_t::remove(sll_item_t* nodo) {
			
        assert(nodo != NULL);

        if (nodo->prev_ != NULL)
            nodo->prev_->next_ = nodo->next_;
        else
            inicio_ = nodo->next_;

        if (nodo->next_ != NULL)
            nodo->next_->prev_ = nodo->prev_;
        else
            fin_ = nodo->prev_;

        size_--;

    }

    int sll_t::size(void) {
        return size_;
    }
