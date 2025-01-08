#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <stdexcept> 
#include <ostream>   
#include "List.h"
#include <vector>

using namespace std;

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;          
    int max;         
    int n;                  // Número de elementos
    static const int MINSIZE = 2; 

    // Redimensiona el array al tamaño especifico (new_size)
    void resize(int new_size) {
        if (new_size < MINSIZE) {
            new_size = MINSIZE;
        }
        T* new_arr = new T[new_size];
        for (int i = 0; i < n; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }
    //PAra la clase Drawing
    vector<T> data;
public:
    // Constructor
    ListArray(){
    	this->arr = new T[this->MINSIZE];
    	this->max = this->MINSIZE;
    	this->n = 0;
    }
    // Destructor
    ~ListArray() {
        delete[] arr;
    }

    // Sobrecarga del operador [](Devuelve elemento situado en posicion pos)
    T operator[](int pos) const {
        if (pos < 0 || pos >= n) {
            throw out_of_range("Posición Inválida");
        }
        return arr[pos];
    }

    // Sobrecarga del operador <<(Imprime instancia de ListArray<T>)
    friend ostream& operator<<(ostream& out, const ListArray<T>& list) {
        out << "[";
        for (int i = 0; i < list.n; ++i) {
            out << list.arr[i];
            if (i < list.n - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }

    // Implementación de los métodos heredados de List<T>

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw out_of_range("Posición Inválida");
        }
        if (n == max) {
            resize(max * 2);
        }
        for (int i = n; i > pos; --i) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        ++n;
    }
    //Agrega un elemento al final del array
    void append(T e) override {
        insert(n, e);
    }
    //Agrega elemento al principio del array
    void prepend(T e) override {
        insert(0, e);
    }
    //Elimina un elemento de la posicion pos
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw out_of_range("Posición Inválida");
        }
        T removed = arr[pos];
        for (int i = pos; i < n - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --n;
        if (n < max / 4) {
            resize(max / 2);
        }
        return removed;
    }
    //Obtiene elemento de la posicion pos
    T get(int pos) override {
        return (*this)[pos];
    }
    //Busca elemento y retorna su posicion
    int search(T e) override {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1; 
    }
    //Comprueba si la lista esta vacía
    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

};

#endif

