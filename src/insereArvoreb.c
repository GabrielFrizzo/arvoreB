#include "../include/arvoreb.h"

/*Descrição: ????*/
Arvore* dividir_no (Arvore *x, int i, Arvore *y) {
    Arvore* z = criar();
    z->folha = y->folha;
    z->n = T-1;
    int j;
    for (j = 0; j <= T-2; j++) {
       z->chaves[j] = y->chaves[j+T];
    }
    if (!y->folha) {
       for (j = 0; j <= T-1; j++) {
           z->filhos[j] = y->filhos[j+T];
       }
    }
    y->n = T-1;
    for (j = x->n; j >= i+1; j--) {
       x->filhos[j+1] = x->filhos[j];
    }
    x->filhos[i+1] = z;
    for (j = x->n; j >= i; j--) {
       x->chaves[j+1] = x->chaves[j];
    }
    x->chaves[i] = y->chaves[T-1];
    x->n++;
    return x;
}

/*Descrição: ????*/
Arvore* inserir_arvore_nao_cheia (Arvore *x, TIPO k) {
    int i = x->n;
    if (x->folha) {
       while (i >= 1 && k < x->chaves[i-1]) {
           x->chaves[i] = x->chaves[i-1];
           i--;
       }
       x->chaves[i] = k;
       x->n++;
    } else {
       while (i >= 1 && k < x->chaves[i-1]) {
           i--;
       }
       if (x->filhos[i]->n == 2*T-1) {
           x = dividir_no(x, i, x->filhos[i]);
           if (k > x->chaves[i])
               i++;
       }
       x->filhos[i] = inserir_arvore_nao_cheia(x->filhos[i], k);
    }
    return x;
}

/*Função para inserir uma chave em uma árvore B:*/
Arvore *inserir (Arvore *raiz, TIPO chave) {
    Arvore *r = raiz;
    if (r->n == (2*T - 1)) {
      Arvore *s = criar();
      s->folha = FALSE;
      s->filhos[0] = r;
      s = dividir_no (s, 0, r);
      s = inserir_arvore_nao_cheia (s, chave);
      return s;
    }
    else {
      return inserir_arvore_nao_cheia (r, chave);
    }
}




