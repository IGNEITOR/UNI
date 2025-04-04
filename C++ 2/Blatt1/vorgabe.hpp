/*
Author: Lennart Janson
Aufabe: Blatt1 Stack implementieren
Sprache: c++
*/
#ifndef VORGABE_HPP
#define VORGABE_HPP

const int N_MAX_STACK = 1000; 
class Stack {
    public:
        Stack(); // Konstruktor
        ~Stack();// Dekonstruktor
        int push(int datum); // Element hinzufügen
        int pop(); // Element entfernen
        int peek(); // Wert des obersten Elementes
        int size(); // Anzahl der Elemente
        int get_capacity(); // Stapelgröße
        bool is_empty(); // Stapel leer
        bool is_not_empty(); // Stapel nicht leer
    private:
        void init(); // Initialisierung
        int *value; // Feld zur Aufnahme der Datenelemente
        int next; // Stapelzeiger
        int capacity; // maximale Elementzahl
};

#endif