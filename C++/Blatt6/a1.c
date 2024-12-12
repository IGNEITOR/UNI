#include <stdio.h>

//string umdrehen
void reverse_str(char puffer[] , int laenge){
    char reverse_puffer[laenge];
    //reverse_puffer erhält an seiner "letzten" stelle den Buchstaben der im string an erster stelle steht
    for(int i=0; i<laenge; i++){
        reverse_puffer[laenge-i-1]=puffer[i];  
    }
    //Ausgabe vom Reverse string
    printf("Ausgabe: %s\n", reverse_puffer);
}

//berechnet die länge des strings indem geschaut wird wann im string null steht
int my_strlen(char puffer[]){
    int i =0;
    while(1){
        if(puffer[i]!=0) i++;
        else return i;
    }
}


int main(void) {
// Zeichenkette mit maximale 199 Zeichen
    char puffer[200];
    while (1) {
        printf("Geben Sie eine Zeichenkette ein:\n" );

        int anz = scanf("%[^\n]", puffer);

        getchar ( ) ; // Konsumiere '\n'

        if (anz!=1 ) {
            printf("Ende\n");
            break ;
        }

        int laenge = my_strlen(puffer);
        printf("Eingabe: %s\n", puffer);
        reverse_str (puffer, laenge);
        printf("Ausgabe: %s\n", puffer);
    }

    return 0;
}
