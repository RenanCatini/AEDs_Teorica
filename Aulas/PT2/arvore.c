#include <stdio.h>

typedef struct no_{
    char data;
    struct no_ *left;
    struct no_ *right;    
}no;

no *root = NULL;

void visita(no *pt){
    printf("%c ", pt->data);
}

void pre_ordem(no *pt){
    visita(pt);
    if(pt->left != NULL) pre_ordem(pt->left);
    if(pt->right != NULL) pre_ordem(pt->right);
}

void em_ordem(no *pt){
    if(pt->left != NULL) pre_ordem(pt->left);
    visita(pt);
    if(pt->right != NULL) pre_ordem(pt->right);
}

void pos_ordem(no *pt){
    if(pt->left != NULL) pre_ordem(pt->left);
    if(pt->right != NULL) pre_ordem(pt->right);
    visita(pt);
}


int main(){

    no D = {'d', NULL, NULL};
    no E = {'e', NULL, NULL};
    no F = {'f', NULL, NULL};
    no C = {'c', NULL, &F};
    no B = {'b', &D, &E};
    no A = {'a', &B, &C};  
    root = &A;

    pre_ordem(root);
    puts("");
    em_ordem(root);
    puts("");
    pos_ordem(root);
    puts("");

    return 0;
}

