#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#define unendlich INT_MAX;


void FeldAusgeben(int A[],int n){
    for(int i =0;i <n;i++){
        printf("[%02d]:%4d\t",i,A[i]);
        if(i%5==4) printf("\n");
    }
    printf("\n");
}

void merge(int *p_numbers, int pe, int qu, int er){
    
    int n1 = qu-pe +1;
    int n2 = er-qu;
    
    int *L = NULL;
    int *R = NULL;
    L = (int *) malloc((n1+2) * sizeof(int));
    R = (int *) malloc((n2+2) * sizeof(int));

    for (int i=1;i<=n1;i++){
        L[i]=p_numbers[pe+i-1];
    }

    for (int j = 1; j<=n2;j++){
        R[j]=p_numbers[qu+j];
    }

    L[n1+1] = unendlich;
    R[n2+1] = unendlich;

    int i=1;
    int j=1;

    for(int k = pe; k<=er;k++){
        if(L[i]<=R[j]){
            p_numbers[k]=L[i];
            i=i+1;
        }
        else{
            p_numbers[k]=R[j];
            j=j+1;
        }
    }
    free(L);
    free(R);
}

void merge_sort(int *p_numbers, int pe, int er){
    if(pe<er){
        int qu = (pe+er)/2;
        merge_sort(p_numbers,pe,qu);
        merge_sort(p_numbers,qu+1,er);
        merge(p_numbers,pe,qu,er);
    }
}

void Mergesort_time(int *p_numbers,int start, int size){
    clock_t t = clock();
    merge_sort(p_numbers,start,size);
    t = clock()-t;
    printf("%9d : %6.3f sec \n",size,((float)t)/CLOCKS_PER_SEC);
}

void TestMerge_sort(int size){
    
    int *p_numbers = NULL;
    p_numbers = (int *) malloc(size * sizeof(int));
    
    for(int i =0; i <= size-1;i++){
        p_numbers[i]=(((rand()&0x7FFF)<<15)+(rand()&0x7FFF));
    }

    //FeldAusgeben(p_numbers,10);
    Mergesort_time(p_numbers,0,size);
    //FeldAusgeben(p_numbers,10);
    free(p_numbers);

}

void Testmultiple_mergesort(){
    int wert = 5000;
    for(int x = 0; x < 10; x++){
        printf("Feldgröße: %d\n",wert);
        TestMerge_sort(wert);
        wert = wert + 5000;
       
    }
}


int main(void){
    srand(time(NULL));
    
    TestMerge_sort(50000);
}