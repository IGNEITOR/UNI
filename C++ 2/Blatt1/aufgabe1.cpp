#include "vorgabe.hpp"
#include <iostream>

using namespace std;


void test_stack() {

    // Test 1: Push einer negativen Zahl
    Stack s1;
    s1.push(-5);
    cout << "Test 1 (Push negativ): " << (s1.size() == -1 ? "Bestanden" : "Fehlgeschlagen") << endl;

    // Test 2: Stack voll
    Stack s2;
    //  N_MAX_STACK ist 1000
    for (int i = 0; i < 1000; ++i) {
        s2.push(i + 1);
    }
    s2.push(11); // Sollte Fehler ausgeben
    cout << "Test 2 (Stack voll): " << (s2.size() == 1000 ? "Bestanden" : "Fehlgeschlagen") << endl;

    // Test 3: Pop von leerem Stack
    Stack s3;
    int popResult = s3.pop();
    cout << "Test 3 (Pop leer): " << (popResult == -1 ? "Bestanden" : "Fehlgeschlagen") << endl;

    // Test 4: Peek von leerem Stack
    Stack s4;
    int peekResult = s4.peek();
    cout << "Test 4 (Peek leer): " << (peekResult == -1 ? "Bestanden" : "Fehlgeschlagen") << endl;

    // Test 5: size() auf leerem Stack
    Stack s5;
    cout << "Test 5 (size leer): " << (s5.size() == -1 ? "Bestanden" : "Fehlgeschlagen") << endl;

    // Test 6: get_capacity() auf leerem Stack (Fehler in der Implementierung)
    Stack s6;
    cout << "Test 6 (get_capacity leer): " << (s6.get_capacity() == -1 ? "Bestanden (Fehler vorhanden)" : "Fehlgeschlagen") << endl;

    // Test 7: is_empty() auf leerem Stack
    Stack s7;
    cout << "Test 7 (is_empty leer): " << (s7.is_empty() ? "Bestanden" : "Fehlgeschlagen") << endl;

    // Test 8: is_not_empty() auf nicht leerem Stack
    Stack s8;
    s8.push(1);
    cout << "Test 8 (is_not_empty nicht leer): " << (s8.is_not_empty() ? "Bestanden" : "Fehlgeschlagen") << endl;

    // Test 9: is_not_empty() auf leerem Stack
    Stack s9;
    cout << "Test 9 (is_not_empty leer): " << (!s9.is_not_empty() ? "Bestanden" : "Fehlgeschlagen") << endl;

    // Test 10: Korrektes Push und Pop
    Stack s10;
    s10.push(5);
    s10.push(10);
    int p1 = s10.pop();
    int p2 = s10.pop();
    int p3 = s10.pop();
    cout << "Test 10 (Push/Pop): " << ((p1 == 10 && p2 == 5 && p3 == -1) ? "Bestanden" : "Fehlgeschlagen") << endl;

    // Test 11: Peek ohne Entfernen
    Stack s11;
    s11.push(42);
    int pk = s11.peek();
    cout << "Test 11 (Peek): " << (pk == 42 && s11.size() == 1 ? "Bestanden" : "Fehlgeschlagen") << endl;

    // Test 12: Kapazitätsprüfung nach Push 
    Stack s12;
    s12.push(1);
    cout << "Test 12 (Kapazität): " << (s12.get_capacity() == 1000 ? "Bestanden" : "Fehlgeschlagen") << endl;

    cout << "Stack-Tests abgeschlossen." << endl;
}

int main() {
    test_stack();
    return 0;
}