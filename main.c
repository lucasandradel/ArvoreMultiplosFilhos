#include <stdlib.h>
#include <stdio.h>

#include "ArvoreMF.h"

int main(int argc , char *argv[]){
    tipo_arv_MF *minha_arv;
    minha_arv = NULL;
    

    InsereArvMF(&minha_arv, 5);
    InsereArvMF(&minha_arv, 10);
    InsereArvMF(&minha_arv, 15);
    InsereArvMF(&minha_arv, 2);
    InsereArvMF(&minha_arv, 3);
    InsereArvMF(&minha_arv, 6);
    InsereArvMF(&minha_arv, 7);
    InsereArvMF(&minha_arv, 20);
    InsereArvMF(&minha_arv, 23);
    InsereArvMF(&minha_arv, 50);
    InsereArvMF(&minha_arv, 51);
    InsereArvMF(&minha_arv, 52);
    InsereArvMF(&minha_arv, 8);
    InsereArvMF(&minha_arv, 9);
    InsereArvMF(&minha_arv, 4);

    printf("\n\t\t----------- Impresão por percusos ----------\n\n");
    printf("Imprime arvore em pré ordem: \n");
    PercusoPreOrdemMF(&minha_arv);
    printf("\n\n");

    printf("\nImprime arvore em ordem: \n");

    PercusoOrdemMF(&minha_arv);
    printf("\n\n");

    printf("\nImprime arvore em pós ordem: \n");
    PercusoPosOrdemMF(&minha_arv);
    printf("\n");

    printf("\n\n\t[ Buscando valor ]\n ");
    BuscaArvMF(&minha_arv, 20);

    BuscaMaiorVlArvMF(&minha_arv);

    BuscaMenorVlArvMF(&minha_arv);

    int QtdNo = contabilizaNosArvMF(&minha_arv);
    printf("A quantidade de nós é: %d\n\n", QtdNo);

    int QtdValores = ContabilizaValores(&minha_arv);
    printf("A quantidade de Valores na arvore é: %d\n\n", QtdValores);

    int qtdfolhas = contabilizaNosArvMF(&minha_arv);
    printf(" Quantidade de nós folhas : %d\n\n", qtdfolhas);

    int altura = AlturaArvMF(minha_arv);
    printf("Altura da arvore: %d\n\n", altura);

    int nivel;
    printf("Digite o nível que deseja imprimir: ");
    scanf ("%d", &nivel);
    ImprimeNivelArvMF(minha_arv, nivel);

    return EXIT_SUCCESS;
}