/*
Projekt: Blatt 9 Aufgabe 1
Autor:   Lennart Janson
Datum:   07.12.2024
*/

#include <stdio.h>
#include <stdlib.h>
//groesse des strings
#define SIZE_OF_ARRAY 200


//Erstellet einen compremmierten string "HALLLO" -> "HAL3O" braucht als parameter einen string pointer
int compression(char *p_str) {
    char temp_string[SIZE_OF_ARRAY] = {0};
    int size = 0;
    //zählt wie lang der string ist
    while (p_str[size] != 0) size++;
    if(size == 0) {
        printf("Fehler String ist zu klein");
        return -1;
    }
     
    //counter zählt wie oft ein buchstabe doppelt vorkommt
    int counter = 1;
    int second_index = 0;

    //schleife geht den gesammten string durch
    for (int first_index = 0; first_index < size; first_index++) {
        //while schleife zählt wie oft etwas doppelt vorkommt
        while (p_str[first_index] == p_str[first_index + 1] && p_str[first_index + 1] != 0) {
            counter++;
            first_index++;
        }
        /*schreib jeweils den ausgewählten Buchstaben aus dem string in einen temporären
        und schreibt gegebenen falls die counter Nummer dahinter*/
        if (second_index == 0 || (temp_string[second_index-1] != p_str[first_index])) {
            temp_string[second_index++] = p_str[first_index];
            if (counter > 1) {
                //(char)counter % 10 +'0' wandelt counter in einen string um
                if (counter > 9) {
                    // Zehnerstelle
                    temp_string[second_index++] = (char)(counter / 10 + '0'); 
                }
                // Einerstelle
                temp_string[second_index++] = (char)(counter % 10 + '0'); 
                counter = 1;
            }
        }
    }

    //überschreibt unseren eingabe string mit dem temporären string
    int translate_index = 0;
    while (temp_string[translate_index] != '\0') {
        p_str[translate_index] = temp_string[translate_index];
        translate_index++;
    }
    p_str[translate_index] = '\0';

    return 0;
}

int main() {
    char str[SIZE_OF_ARRAY];
    char *p_str = str;

    printf("Gib eine Zeichenkette ein:\n");
    scanf("%[^\n]", str);
    compression(p_str);
    printf("%s\n", p_str);

    return 0;
}
