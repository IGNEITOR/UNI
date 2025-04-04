/*
Author: Lennart Janson
Aufabe: Blatt1 Stack implementieren
Sprache: c++
*/

#include "vorgabe.hpp"
#include <iostream>

using namespace std;

//Konstruktor
Stack::Stack() {
    capacity = N_MAX_STACK;
    value = nullptr;
    init();
}
// Dekonstruktor
Stack::~Stack() {
    delete[] value;
}


void Stack::init() { // INITIALISIERUNG
    next = 0; // Index zurücksetzen
    if (value == nullptr) {
        value = new int[capacity]; // Speicher anfordern
    }
}

// Legt wert >0 auf den stack
int Stack::push(int datum) {
    if (datum < 0) {
        cout << "Fehler: negative Zahlen koennen nicht gespeichert werden!" << endl;
        return -1;
    } else if (next >= capacity) {
        cout << "Fehler: Stack ist voll!" << endl;
        return -1;
    } else {
        value[next] = datum; // Wert speichern
        next++; // Index erhöhen
        return 0;
    }
}

// Nimmt den obersten wert vom Stack
int Stack::pop() {
    if (next <= 0) {
        cout << "Fehler: Stack ist leer!" << endl;
        return -1; // Fehlerwert zurückgeben
    } else {
        next--; // Index verringern
        return value[next]; // Wert zurückgeben
    }
}

int Stack::peek() {
    if (next <= 0) {
        cout << "Fehler: Stack ist leer!" << endl;
        return -1; 
    } else {
        return value[next-1];
    }
}

int Stack::size() {
    if (next < 0) {
        cout << "Fehler: Stack ist Negativ!" << endl;
        return -1;  
    } else {
        return next;
    }
}

int Stack::get_capacity() {
    if (next <= 0) {
        cout << "Fehler: Stack ist leer!" << endl;
        return -1;
    } else {
        return capacity;
    }
}

bool Stack::is_empty() {
    return (next == 0);
}

bool Stack::is_not_empty() {
    return (next > 0);
}