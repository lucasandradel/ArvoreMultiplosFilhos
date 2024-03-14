#include "ArvoreMF.h"

//função que aloca um novo nó na memória
tipo_arv_MF *AlocaNo(int vl){
    tipo_arv_MF *novo_no;
    int i;
    novo_no = (tipo_arv_MF*)malloc(sizeof(tipo_arv_MF));

    //inicializa os componentes do novo_no4

    novo_no -> contador = 0;
    
    //novo_no -> contador = 1;
    for (i = 0; i < t + 1; i++)
    {
        novo_no -> filhos[i] = NULL;
    }

    novo_no -> valores[0] = vl;//contador tá valendo 1 quando faço a inserção de um novo no
    novo_no -> contador ++;
    return novo_no;
}
void InsereArvMF(tipo_arv_MF ** arv , int vl ){
    tipo_arv_MF *novo_no;
    novo_no = AlocaNo(vl);
    int i;
    //verifica se arvore é nula
    if((*arv) == NULL){
        (*arv) = novo_no;
    }else{//caso o no já exista, verificar as situações:

        if((*arv) -> contador < t){ //verificar se o noh tem espaço, se tiver:

            //inserir ordenadamente 
            i = (*arv) -> contador -1; 
            while ((i >= 0) && ((*arv) -> valores[i] > vl))
            {
                (*arv) -> valores [i+1] = (*arv) -> valores [i];
                i--;
            }
            (*arv) -> valores[i] = vl;
            (*arv) -> contador ++;

        }else{ //se não tem espaço, buscar pelo filho a descer, identifica o filho e faz a chamad recursiva 
            i = 0;//inicializa o i com 0
            while ((i  < t) && (*arv) -> valores [i] < vl)//enquanto o i for menor que o tamanho do no e o valor da posição que i está for maior que o valor que quero inserir faça:
            {
                i ++;
            }
            InsereArvMF((*arv) -> filhos [i], vl);
        }

        
    }
}

int BuscaArvMF(tipo_arv_MF*, int);
void PercusoPreOrdemMF(tipo_arv_MF*);
void PercusoOrdemMF(tipo_arv_MF*);
void PercusoPosOrdemMF(tipo_arv_MF*);
int contabilizaNosArvMF(tipo_arv_MF*);
int AlturaArvMF(tipo_arv_MF*);
void ImprimeNivelArvMF(tipo_arv_MF*);
int BuscaMaiorVlArvMF(tipo_arv_MF*);
int BuscaMenorVlArvMF(tipo_arv_MF*);