#ifndef VORGABE_H
#define VORGABE_H

const int N_MAX_STACK = 1000; // maximale Stapelgröße
class Stack {
    public:
        Stack(); // Konstruktor
        ~Stack();
        void push(int datum); // Element hinzufügen
        int pop(); // Element entfernen
        int peek(); // Wert des obersten Elementes
        int size(); // Anzahl der Elemente
        int get_capacity(); // Stapelgröße
        bool is_empty(); // Stapel leer
        bool is_not_empty(); // Stapel nicht leer
    private:
        void init(); // Initialisierung
        int *value[N_MAX_STACK]; // Feld zur Aufnahme der Datenelemente
        int next; // Stapelzeiger
        int capacity; // maximale Elementzahl
 };

#endif