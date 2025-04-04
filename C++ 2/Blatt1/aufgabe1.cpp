/*
Author: Lennart Janson
Aufabe: Blatt1 Stack implementieren
Sprache: c++
*/

#include "vorgabe.hpp"
#include <iostream>

using namespace std;

void test_stack() {
  

    // Testfall 1: Negativen Wert pushen
    Stack test1;
    test1.push(-10);
    if(test1.size() != 0) {
        cout << "FEHLER in Testfall 1" << endl;
    } else {
        cout << "Testfall 1 erfolgreich" << endl;
    }

    // Testfall 2: Stack-Overflow testen
    Stack test2;
    for(int i = 0; i < 1000; i++) {
        test2.push(i);
    }
    
    
    if(test2.push(4) == -1) {
        cout << "FEHLER in Testfall 2" << endl;
    } else {
        cout << "Testfall 2 erfolgreich" << endl;
    }

    // Testfall 3: Pop von leerem Stack
    Stack test3;
    int ergebnis = test3.pop();
    if(ergebnis != -1) {
        cout << "FEHLER in Testfall 3" << endl;
    } else {
        cout << "Testfall 3 erfolgreich" << endl;
    }

    // Testfall 4: Peek auf leerem Stack
    Stack test4;
    if(test4.peek() != -1) {
        cout << "FEHLER in Testfall 4" << endl;
    } else {
        cout << "Testfall 4 erfolgreich" << endl;
    }

    // Testfall 5: Größenabfrage leerer Stack
    Stack test5;
    if(test5.size() != 0) {
        cout << "FEHLER in Testfall 5" << endl;
    } else {
        cout << "Testfall 5 erfolgreich" << endl;
    }

    // Testfall 6: Kapazitätsabfrage ???
    Stack test6;
    test6.push(1);
    if(test6.get_capacity() != 1000) {
        cout << "FEHLER in Testfall 6" << endl;
    } else {
        cout << "Testfall 6 erfolgreich" << endl;
    }

    // Testfall 7: isEmpty-Funktionalität
    Stack test7;
    if(!test7.is_empty()) {
        cout << "FEHLER in Testfall 7" << endl;
    } else {
        cout << "Testfall 7 erfolgreich" << endl;
    }

    // Testfall 8: is_not_empty-Funktionalität
    Stack test8;
    test8.push(42);
    if(!test8.is_not_empty()) {
        cout << "FEHLER in Testfall 8" << endl;
    } else {
        cout << "Testfall 8 erfolgreich" << endl;
    }

    // Testfall 9: Push/Pop Sequenz
    Stack test9;
    test9.push(10);
    test9.push(20);
    if(test9.pop() != 20 || test9.pop() != 10 || test9.pop() != -1) {
        cout << "FEHLER in Testfall 9" << endl;
    } else {
        cout << "Testfall 9 erfolgreich" << endl;
    }

    // Testfall 10: Peek 
    Stack test10;
    test10.push(99);
    int peekWert = test10.peek();
    if(peekWert != 99 || test10.size() != 1) {
        cout << "FEHLER in Testfall 10" << endl;
    } else {
        cout << "Testfall 10 erfolgreich" << endl;
    }

}

int main() {
    test_stack();
    return 0;
}