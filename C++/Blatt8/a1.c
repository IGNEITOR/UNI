#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Höchster wert der Exestieren kann
#define MAX_NUMBER 100 


//Array wird mit random nummer befüllt
void init_numbers(int *p_numbers, int range){
    for(int x = 0; x<range; x++){
        p_numbers[x] = (rand()%MAX_NUMBER)+1;
    }
    return;
}

//sortier Algorythmus
int selectionsort(int *p_numbers, int range){

    int position = 0;
    int buffer = 0;
     
    for(int x = 0 ; x < range; x++){

        int min = MAX_NUMBER;
        //sucht minumum im vom noch unsorierten bereich bis zum ende
        for(int y = x ; y < range; y++){

            if(min>p_numbers[y]){
                min = p_numbers[y];
                position = y;
            }
        }

        //speichert den wert des erste nicht sortierten array slots damit er nicht verloren geht
        buffer = p_numbers[x];
        //schreibt das minium an die erste stelle des unsortieren bereiches
        p_numbers[x]= min;
        //schreibt die zahl die in dem ersten unsortierent array slot war in den array slot wo die kleinste zahl her ist
        p_numbers[position]=buffer;
        
    }
    return 0;
}


void print_numbers(int *p_numbers, int range, int rows) {
    //berechnet wieviele zeilen erstellt werden müssen
    int columns = range / rows;
    if(range%rows!=0) columns++; // added eine reihe falls bei der zeilen berechnung eine zeile wegfallen würde
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            int pos = (r + c * rows);
            if(pos>=range)printf(" ");
            else printf("Stelle[ %3d ]:%3d\t",(pos)+1, p_numbers[pos]);
        }
        printf("\n");
    }
    return;
}



int main(void){
    srand(time(NULL));
    int range = 20;
    int rows = 4;
    //int numbers[range];

    int *p_numbers = NULL;
    //p_numbers = numbers;

    p_numbers = (int *) malloc(range * sizeof(int));
    //prüft ob der speicher verfügbar ist
    if(p_numbers==NULL){
        printf("error while allocating memory\n");
        return -1;
    }

    init_numbers(p_numbers, range);
    print_numbers(p_numbers,range, rows);
    selectionsort(p_numbers,range);
    print_numbers(p_numbers,range, rows);
    
    //gibt den speicher wieder frei
    free(p_numbers);

    return 0;
}