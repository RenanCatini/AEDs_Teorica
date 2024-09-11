#include <stdio.h>

typedef struct{
    int chave;
    int valor;
}no;

// n=cabeca
int busca1(no L[], int n, int x){
    for(int i = 0; i <= n; i++){
        if(L[i].chave == x) return i;
    }
    return -1;
}

int busca(no L[], int n, int x){
    L[n+1].chave = x;
    int i = 0;
    while(L[i].chave != x) i++;
    if(i != n+1) return i;
    else return -1;
}

int busca_ord(no L[], int n, int x){
    L[n+1].chave = x;
    int i = 0;
    while(L[i].chave < x)i++;
    if(i == n+1 || L[i].chave != x) return -1;
    else return i;
}

int busca_bin(no L[], int n, int x){
    int inf = 0, sup = n-1;
    int meio;
    while(inf <= sup){
        meio = (inf+sup)/2;
        if(L[meio].chave == x) return meio;
        else if(L[meio].chave < x){
            inf = meio+1;
        }else{
            sup = meio-1;
        }
    }
    return -1;
}

int main(){
    no L[10];
    L[0].chave = 0;
    L[1].chave = 3;
    L[2].chave = 7;

    //Testes

    puts("0");
    printf("Busca1: %d\n", busca1(L, 3, 0));
    printf("Busca: %d\n", busca(L, 3, 0));
    printf("Busca_ord: %d\n",busca_ord(L, 3, 0));
    printf("Busca_bin: %d\n",busca_bin(L, 3, 0));

    puts("");
    puts("3");
    printf("Busca1: %d\n", busca1(L, 3, 3));
    printf("Busca: %d\n", busca(L, 3, 3));
    printf("Busca_ord: %d\n",busca_ord(L, 3, 3));
    printf("Busca_bin: %d\n",busca_bin(L, 3, 3));

    puts("");
    puts("7");
    printf("Busca1: %d\n", busca1(L, 3, 7));
    printf("Busca: %d\n", busca(L, 3, 7));
    printf("Busca_ord: %d\n",busca_ord(L, 3, 7));
    printf("Busca_bin: %d\n",busca_bin(L, 3, 7));

    puts("");
    puts("1");
    printf("Busca1: %d\n", busca1(L, 3, 1));
    printf("Busca: %d\n", busca(L, 3, 1));
    printf("Busca_ord: %d\n",busca_ord(L, 3, 1));
    printf("Busca_bin: %d\n",busca_bin(L, 3, 1));
}