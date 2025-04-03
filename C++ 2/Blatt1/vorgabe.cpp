#include "vorgabe.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;

Stack :: Stack(){
    capacity = N_MAX_STACK;
    init();
}

Stack::~Stack(){
    delete[] value;
}

void Stack :: init () { // INITIALISIERUNG
 int next = 0; // Index zurücksetzen
 if (value == nullptr)
 *value = new int[capacity]; // Speicher anfordern
 }

