#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int valor;
    int chave;
}No;


int main(){
    int x = 10;
    int *p = &x;

    printf("%d\n", x);
    printf("%d\n", *p);
    printf("%d\n", p);

}