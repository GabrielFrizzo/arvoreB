#include "../include/arvoreb.h"

void caso1(Arvore* a){
    a = remover(a, 21);

    imprimir(a, 0);
}

void caso2A(Arvore* a){
    a = remover(a, 6);

    imprimir(a, 0);
}

void caso2B(Arvore* a){
    a = remover(a, 50);

    imprimir(a, 0);
}

void caso2C(Arvore* a){
    a = remover(a, 44);

    imprimir(a, 0);
}

void caso3A(Arvore* a){
    a = remover(a, 7);

    imprimir(a, 0);
}

void caso3B(Arvore* a){
    a = remover(a, 2);

    imprimir(a, 0);
}


 /*Função principal:*/
int main () {

    Arvore *a = criar();

    /*Exercicio 18-2.1 Cormen*/
//    a = inserir (a, 'F');
//    a = inserir (a, 'S');
//    a = inserir (a, 'Q');
//    a = inserir (a, 'K');
//    a = inserir (a, 'C');
//    a = inserir (a, 'L');
//    a = inserir (a, 'H');
//    a = inserir (a, 'T');
//    a = inserir (a, 'V');
//    a = inserir (a, 'W');
//    a = inserir (a, 'M');
//    a = inserir (a, 'R');
//    a = inserir (a, 'N');
//    a = inserir (a, 'P');
//    a = inserir (a, 'A');
//    a = inserir (a, 'B');
//    a = inserir (a, 'X');
//    a = inserir (a, 'Y');
//    a = inserir (a, 'D');
//    a = inserir (a, 'Z');
//    a = inserir (a, 'E');
    a = inserir (a, 91);
    a = inserir (a, 90);
    a = inserir (a, 80);
    a = inserir (a, 71);
    a = inserir (a, 72);
    a = inserir (a, 50);
    a = inserir (a, 45);
    a = inserir (a, 47);
    a = inserir (a, 10);
    a = inserir (a, 8);
    a = inserir (a, 7);
    a = inserir (a, 5);
    a = inserir (a, 2);
    a = inserir (a, 3);
    a = inserir (a, 22);
    a = inserir (a, 44);
    a = inserir (a, 55);
    a = inserir (a, 66);
    a = inserir (a, 68);
    a = inserir (a, 17);
    a = inserir (a, 6);
    a = inserir (a, 21);
    a = inserir (a, 67);
    a = inserir (a, 73);
    a = remover(a, 0);

    imprimir(a, 0);
     printf("----------------------------\n");
    caso1(a);
    printf("----------------------------\n");
    caso2A(a);
     printf("----------------------------\n");
    caso2B(a);
     printf("----------------------------\n");
    caso2C(a);
     printf("----------------------------\n");
    caso3A(a);
     printf("----------------------------\n");
    caso3B(a);
     printf("----------------------------\n");
    return 0;
}
