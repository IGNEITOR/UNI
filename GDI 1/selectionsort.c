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



void selectionsort_time(int *p_numbers,int start, int size){
    clock_t t = clock();
    selectionsort(p_numbers,size);
    t = clock()-t;
    printf("%9d : %6.3f sec \n",size,((float)t)/CLOCKS_PER_SEC);
}

void test_selectionsort(int size){
    
    int *p_numbers = NULL;
    p_numbers = (int *) malloc(size * sizeof(int));
    
    for(int i =0; i <= size-1;i++){
        p_numbers[i]=(((rand()&0x7FFF)<<15)+(rand()&0x7FFF));
    }

    //FeldAusgeben(p_numbers,10);
    selectionsort_time(p_numbers,0,size);
    //FeldAusgeben(p_numbers,10);
    free(p_numbers);

}

void testmultiple_selectionsort(){
    int wert = 5000;
    for(int x = 0; x < 10; x++){
        printf("Feldgröße: %d\n",wert);
        test_selectionsort(wert);
        wert = wert +5000;
       
    }
}



int main(void){
    srand(time(NULL));
   testmultiple_selectionsort();

    return 0;
}