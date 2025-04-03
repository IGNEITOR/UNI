#include <stdio.h>
#include <stdlib.h>


int main(){
    int MAX = 10;
    char name[MAX];
    scanf("%9[^\n]",&name);

    printf("%s\n",name);
}