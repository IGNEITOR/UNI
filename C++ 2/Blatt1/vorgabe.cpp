#include "vorgabe.hpp"
#include <iostream>

using namespace std;

Stack::Stack() {
    capacity = N_MAX_STACK;
    value = nullptr;
    init();
}

Stack::~Stack() {
    delete[] value;
}

void Stack::init() { // INITIALISIERUNG
    next = 0; // Index zurücksetzen
    if (value == nullptr) {
        value = new int[capacity]; // Speicher anfordern
    }
}

void Stack::push(int datum) {
    if (datum < 0) {
        cout << "Fehler: negative Zahlen koennen nicht gespeichert werden!" << endl;
    } else if (next >= capacity) {
        cout << "Fehler: Stack ist voll!" << endl;
    } else {
        value[next] = datum; // Wert speichern
        next++; // Index erhöhen
    }
}

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
    if (next <= 0) {
        cout << "Fehler: Stack ist leer!" << endl;
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
    if (next < 0) {
        cout << "Fehler: Stack ist leer!" << endl;
        return -1;
    } else if (next == 0) {
        return true;
    } else return false;
}

bool Stack::is_not_empty() {
    if (next < 0) {
        cout << "Fehler: Stack ist leer!" << endl;
        return -1;
    } else if (next > 0) {
        return true;
    } else return false;
}