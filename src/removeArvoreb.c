#include "../include/arvoreb.h"

/*Descrição ...*/
Arvore* remover_valor_de_no (Arvore *a, int index){
    int i;
    for(i = index; i < a->n; i++){ a->chaves[i] = a->chaves[i+1]; }
    a->n--;
    return a;
}

/*Descrição ...*/
Arvore* remover_de_folha (Arvore *a, int index){
    return remover_valor_de_no(a, index);
}

Arvore* merge(Arvore* a, Arvore* b){
    int i;
    for(i = 0; i < b->n; i++){
        a->chaves[a->n+i] = b->chaves[i];
        a->filhos[a->n+i+1] = b->filhos[i];
    }
    a->n = a->n + b->n;
    a->filhos[a->n+1] = b->filhos[b->n];
    return a;
}


/*Descrição ...*/
Arvore* remover_de_nao_folha (Arvore *a, int index){
    TIPO k = a->chaves[index];
    TIPO predecessor, sucessor;
    Arvore* filho_esquerda = a->filhos[index];
    Arvore* filho_direita = a->filhos[index+1];

    /*Descrição ...*/
    if (filho_esquerda->n >= T){
      predecessor = filho_esquerda->chaves[filho_esquerda->n-1];
      remover(filho_esquerda, predecessor);
      a->chaves[index] = predecessor;
    }
    /*Descrição ...*/
    else if (filho_direita->n >= T){
        sucessor = filho_direita->chaves[0];
        remover(filho_direita, sucessor);
        a->chaves[index] = sucessor;
    }
    /*Descrição ...*/
    else{
        a = remover_valor_de_no(a, index);
        filho_esquerda->chaves[filho_esquerda->n] = k;
        filho_esquerda->n++;
        filho_esquerda = merge(filho_esquerda, filho_direita);
        free(filho_direita);
        remover(filho_esquerda, k);
    }

    return a;
}


//Função para verificar se raiz ficou vazia
Arvore *verificar_raiz_vazia (Arvore *raiz){
    /*Se após a remoção a raiz tiver 0 chaves, tornar o primeiro filho a nova raiz se existir filho; caso contrário ajustar a raiz para NULL. Liberar a raiz antiga*/

    /*Completar!!!! */
    printf("Completar\n");

    return raiz;
}



/*Função que retorna o index da primeira chave maior ou igual à chave*/
int buscar_index_remocao (Arvore *a, TIPO chave) {

    int i = 0;

    /*Procurando a chave no vetor de chaves */
    while ((i < a->n) && (chave > a->chaves[i])) {
     i = i + 1;
    }

    return i;
}

/*Descrição: ????*/
Arvore *remover (Arvore *a, TIPO k){
    int index, i;

    /*Completar!!!!!!!!!!!!!!*/
    if (a == NULL) {
        /*Completar!!!*/
        printf("Completar\n");
    }

    index = buscar_index_remocao (a, k);


    //A chave a ser removida está presente neste nó
    if ( index >= 0 && a->chaves[index] == k){
        if (a->folha){
            a = remover_de_folha (a, index);
        }
        else{
            a = remover_de_nao_folha (a, index);
        }
    }
    else{
        //Se este nó é um nó folha, então a chave não está na árvore
        if (a->folha){
            printf("\nA chave %c não está na árvore.\n",k);
            return a;
        }

        Arvore* filho = a->filhos[index];
        if(filho->n >= T){ a->filhos[index] = remover(a->filhos[index], k); }
        else{
            Arvore* irmao_esq = a->filhos[index-1];
            Arvore* irmao_dir = a->filhos[index+1];
            if(irmao_esq && irmao_esq->n >= T){
                for(i = filho->n; i > 0; i--){ filho[i] = filho[i-1]; }
                filho[0] = irmao_esq[irmao_esq->n];
                irmao_esq->n--;
                filho->n++;
            }
            else if(irmao_dir && irmao_dir->n >= T){
                filho[filho->n] = irmao_dir[0];
                for(i = 0; i < irmao_dir->n-1; i++){ irmao_dir[i] = irmao_dir[i+1]; }
                irmao_dir->n--;
                filho->n++;
            }
            else{
                //TODO: CASO 3c
            }
        }
    }
    a = verificar_raiz_vazia(a);

    return a;
}

