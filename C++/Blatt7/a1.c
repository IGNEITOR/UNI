#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// erstellt random nummern von 0 bis 10 und schreibt sie in das array
float init_numbers(int groesse, float *pnumbers){
    srand(time(NULL));
    if(groesse <1){
        printf("Fehler Array ist zu Klein\n");
        return -1;
    }
    for(int i=0; i<groesse;i++){
        pnumbers[i]= ((rand() / (float)RAND_MAX)*10)+20;
        printf("Array slot %d = %f  ",i, pnumbers[i]);
        if (i%2!=0)printf("\n");
        
    }
  
    return 0;
}

// Sucht den kleinsten Wert des Arrays 
float minimum(int groesse, float *pnumbers){
    if(groesse <1){
        printf("Fehler Array ist zu Klein\n");
        return -1;
    }
    float min =pnumbers[0];
    for(int i = 0; i<groesse;i++){
        if(pnumbers[i]<min) min = pnumbers[i];
    }
    return min;
}

// Sucht den größten Wert des Arrays 
float maximum(int groesse, float *pnumbers){
    if(groesse <1){
        printf("Fehler Array ist zu Klein\n");
        return -1;
    }
    float max =pnumbers[0];
    for(int i = 0; i<groesse;i++){
        if(pnumbers[i]>max) max = pnumbers[i];
    }
    return max;
}

// Berechnet den mittelwert des Arrays 
float mittelwert(int groesse,float *pnumbers){
    
    if(groesse <1){
        printf("Fehler Array ist zu Klein\n");
        return -1;
    }
    float value =0.0;
    for(int i = 0; i<groesse;i++){
        value = value + pnumbers[i];
    }
    value = value / groesse;
    return value;
}


// Berechnet die mittlere absolute abweichung des Arrays 
float abweichung(int groesse,float mittelwertErg, float *pnumbers){
    if(groesse <1){
        printf("Fehler Array ist zu Klein\n");
        return -1;
    }

    float value =0.0;
    float value2 =0.0;
    for(int i = 0; i<groesse;i++){
        value2 = pnumbers[i] - mittelwertErg;
        if (value2 <0) value2 = value2 *(-1);
        value = value + value2;
    }
    value = value * (1.0/groesse);
    return value;
}


int main(void) {
    //legt die anzahl der zahlen fest
    int groesse = 10;
    float numbers[groesse];

    // erstellt pointer
    float *pnumbers = NULL;
    pnumbers = numbers;


    init_numbers(groesse, pnumbers);
    printf("\n");
    char* format = "%-10s:%10.3f\n";
    printf(format, "Minimum",minimum(groesse, pnumbers));
    printf(format, "Maximum",maximum(groesse, pnumbers));
    float mittelwertErg = mittelwert(groesse, pnumbers);
    printf(format, "Mittelwert",mittelwertErg);
    printf(format, "Abweichung",abweichung(groesse, mittelwertErg,  pnumbers));
    
}