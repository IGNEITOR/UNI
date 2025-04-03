
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#define unendlich INT_MAX

// Ausgabe des Arrays für Debugging
void FeldAusgeben(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("[%02d]:%6d\t", i, A[i]);
        if (i % 5 == 4) printf("\n");
    }
    printf("\n");
}

// Merge-Funktion
void merge(int *p_numbers, int pe, int qu, int er) {
    int n1 = qu - pe + 1;
    int n2 = er - qu;

    int *L = (int *) malloc((n1 + 1) * sizeof(int));
    int *R = (int *) malloc((n2 + 1) * sizeof(int));

    if (L == NULL || R == NULL) {
        fprintf(stderr, "Fehler: Speicher konnte nicht reserviert werden.\n");
        exit(EXIT_FAILURE);
    }

    // Linkes und rechtes Teilarray füllen
    for (int i = 0; i < n1; i++) {
        L[i] = p_numbers[pe + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = p_numbers[qu + 1 + j];
    }

    L[n1] = unendlich;  // Sentinels
    R[n2] = unendlich;

    int i = 0, j = 0;
    for (int k = pe; k <= er; k++) {
        if (L[i] <= R[j]) {
            p_numbers[k] = L[i];
            i++;
        } else {
            p_numbers[k] = R[j];
            j++;
        }
    }

    free(L);
    free(R);
}

// Merge-Sort Funktion (rekursiv)
void merge_sort(int *p_numbers, int pe, int er) {
    if (pe < er) {
        int qu = (pe + er) / 2;
        merge_sort(p_numbers, pe, qu);
        merge_sort(p_numbers, qu + 1, er);
        merge(p_numbers, pe, qu, er);
    }
}

// Zeitmessung für Merge-Sort
void Mergesort_time(int *p_numbers, int size) {
    clock_t t = clock();
    merge_sort(p_numbers, 0, size - 1);
    t = clock() - t;
    printf("Feldgröße %9d: Zeit = %6.3f Sekunden\n", size, ((float)t) / CLOCKS_PER_SEC);
}

// Test für ein einzelnes Merge-Sort
void TestMerge_sort(int size) {
    int *p_numbers = (int *) malloc(size * sizeof(int));
    if (p_numbers == NULL) {
        fprintf(stderr, "Fehler: Speicher konnte nicht reserviert werden.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        
        p_numbers[i]=(((rand()&0x7FFF)<<15)+(rand()&0x7FFF));
    }

    
    Mergesort_time(p_numbers, size);

    free(p_numbers);
}

// Mehrere Tests mit unterschiedlichen Array-Größen
void Testmultiple_mergesort(int feldgroesse, int wiederholungen) {
    int inc = feldgroesse/10;
    for (int x = 0; x < wiederholungen; x++) {
        TestMerge_sort(feldgroesse);
        feldgroesse = feldgroesse + inc ;
    }
}

int main(void) {
    srand((unsigned int)time(NULL));  

    Testmultiple_mergesort(5000000,10);
    return 0;
}
