#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // Para usar a função sleep


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

   // sleep(1);
    printf("\n\t\t----------- Impressão por percusos ----------\n\n");

   // sleep(1);
    printf("Imprime arvore em pré ordem: \n");
    PercusoPreOrdemMF(&minha_arv);
    printf("\n\n");

   // sleep(1);
    printf("\nImprime arvore em ordem: \n");
    PercusoOrdemMF(&minha_arv);
    printf("\n\n");

   // sleep(1);
    printf("\nImprime arvore em pós ordem: \n");
    PercusoPosOrdemMF(&minha_arv);
    printf("\n");

    int ValorBusca;
    printf ("\nBusque um valor: ");
    scanf("%d", &ValorBusca);
    printf("\n\t[ Buscando valor %d ... ]\n ", ValorBusca);
    //sleep(2);
    BuscaArvMF(&minha_arv, ValorBusca);

   // sleep(1);
    printf("\n\t\t----------- Buscando maior valor da árvore ----------\n\n");
   // sleep(1);
    BuscaMaiorVlArvMF(&minha_arv);

   // sleep(1);
    printf("\n\t\t----------- Buscando menor valor da árvore ----------\n\n");
   // sleep(1);
    BuscaMenorVlArvMF(&minha_arv);

   // sleep(1);
    int QtdNo = contabilizaNosArvMF(&minha_arv);
    printf("A quantidade de nós é: %d\n\n", QtdNo);

    //sleep(1);
    int QtdValores = ContabilizaValores(&minha_arv);
    printf("A quantidade de Valores na arvore é: %d\n\n", QtdValores);

    //sleep(1);
    int qtdfolhas = ContabilizaFolhas(&minha_arv);
    printf("Quantidade de nós folhas : %d\n\n", qtdfolhas);

    //sleep(1);
    int altura = AlturaArvMF(minha_arv);
    printf("Altura da arvore: %d\n\n", altura);

    //sleep(1);
    int nivel;
    printf("Digite o nível que deseja imprimir: ");
    scanf ("%d", &nivel);
    if (nivel > AlturaArvMF(minha_arv)){
        printf("[ERRO]");
    }else{
        ImprimeNivelArvMF(minha_arv, nivel);

    }

    printf("\n\t\t----------- REMOÇÃO ----------\n\n");

    int RemovaValor;
    printf("Digite o valor que deseja remover: ");
    scanf("%d",&RemovaValor);
    printf("\n");
    RemoveArvMF(&minha_arv, RemovaValor);

    printf ("impressão em pré ordem após a remoção: \n");
    PercusoPreOrdemMF(&minha_arv);
    printf("\n\n");
    
    printf ("impressão em ordem após a remoção: \n");
    PercusoOrdemMF(&minha_arv);
    printf("\n\n");

    printf ("impressão em pós ordem após a remoção: \n");
    PercusoPosOrdemMF(&minha_arv);
    printf("\n\n");

    return EXIT_SUCCESS;
}