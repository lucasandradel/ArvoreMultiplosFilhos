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
    
    int i;
    //verifica se arvore é nula
    if((*arv) == NULL){
        (*arv) = AlocaNo(vl);
    }else{//caso o no já exista, verificar as situações:

        if((*arv) -> contador < t){ //verificar se o noh tem espaço, se tiver:
            //inserir ordenadamente 
            i = (*arv) -> contador -1; 
            while ((i >= 0) && ((*arv) -> valores[i] > vl))
            {
                (*arv) -> valores [i+1] = (*arv) -> valores [i];
                i--;
            }
            (*arv) -> valores[i+ 1] = vl;
            (*arv) -> contador ++;

        }else{ //se não tem espaço, buscar pelo filho a descer, identifica o filho e faz a chamad recursiva 
            i = 0;//inicializa o i com 0
            while ((i  < t) && (*arv) -> valores [i] < vl)//enquanto o i for menor que o tamanho do no e o valor da posição que i está for maior que o valor que quero inserir faça:
            {
                i ++;
            }
            InsereArvMF(&(*arv) -> filhos [i], vl);
        }
        
    }
}

int BuscaArvMF(tipo_arv_MF ** arv, int valor){

    if ((*arv) == NULL){
        printf("[BUSCA INVÁLIDA], Valor não encontrado ou árvore nula\n\n");
        return 0;

    }else{
        int i = 0;
        
        while ((i < t) && (valor > (*arv) -> valores [i]))
        {
            i++;
        }
        
        if ((i < t) && (valor == (*arv) -> valores[i]))
        {
            printf("\nValor %d encontrado\n\n", (*arv) -> valores[i]);
            return (*arv) -> valores [i];

        }else {
            return BuscaArvMF(&(*arv) -> filhos [i], valor);
        }
    }   
}

int BuscaMaiorVlArvMF(tipo_arv_MF ** arv){
    if (arv == NULL){
        return 0;
    }else{
        
        int i = (*arv) ->contador;
        if((*arv) -> filhos [i] == NULL){
            printf("Maior valor encontrado: %d \n\n", (*arv)-> valores [i -1]);
            return (*arv)-> valores [i -1];
        }else{
            BuscaMaiorVlArvMF(&(*arv) -> filhos[i]);
        }
    }
}

int BuscaMenorVlArvMF(tipo_arv_MF **arv){
    if ((*arv) == NULL) {
        return 0;
    }else{
        int i = 0;
        if ((*arv) -> filhos[i] == NULL){
                printf("Menor valor encontrado: %d \n\n", (*arv) -> valores[i]);
                return (*arv) -> valores[i];
        }else{
                return BuscaMenorVlArvMF(&(*arv) -> filhos [i]);
        }
        
    }
} 

int contabilizaNosArvMF(tipo_arv_MF ** arv){
    int i = 0;
    if((*arv) == NULL){
        return 0;

    }else{
        int ContaNo = 1;

        while (i <= (*arv) -> contador )
        {
            if ((*arv) -> filhos [i] != NULL){
                ContaNo = ContaNo + contabilizaNosArvMF (&(*arv) -> filhos[i]);
            }
            i++;
        }
        return ContaNo;
    }   

    
}

int ContabilizaValores(tipo_arv_MF** arv){
    int total, i;
    total = 0;
    if ((*arv) != NULL){
        
       /* for ( i = 0; i <= (*arv)-> contador; i++){
            total += contabilizaNosArvMF(&(*arv) -> filhos[i]);
        }
        total += (*arv) -> contador;*/

        for (i = 0; i <= (*arv)->contador; i++) total += ContabilizaValores(&(*arv)->filhos[i]);
        total += (*arv)->contador;
        
    }else{
        return 0;
    }
    return total;
}

int ContabilizaFolhas(tipo_arv_MF **arv) {
    int i, flag;

    if ((*arv) == NULL) {
        return 0; // Nó nulo
    } else {
        flag = 0; // Inicializa a contagem de folhas para este nó como 0
        for (i = 0; i <= (*arv) -> contador; i++){
            flag = flag + contabilizaNosArvMF(&(*arv) -> filhos[i]);
        }
        if(flag == 0){
            return 1;
        }else{
            return flag; // Retorna o total de folhas para este nó
        }
  
    }
}

int Ehfolha(tipo_arv_MF *arv){
    int i, flag;
    flag = 1;
    i = 0;
    do {
        if (arv->filhos[i] != NULL) {
            flag = 0;
        }
        i++;
    } while (i <= arv->contador);
    return flag;
}

int AlturaArvMF(tipo_arv_MF * arv){
    int i, maior, h_atual;
    if( arv == NULL){
        return -1;
    }else{
        maior = AlturaArvMF (arv -> filhos[0]);
        for (i = 0; i <= arv -> contador; i++){
            h_atual = AlturaArvMF(arv -> filhos[i]);
            if (h_atual > maior){
                maior = h_atual;
            }
        }
        return maior + 1;
    }
}

void PercusoPreOrdemMF(tipo_arv_MF**arv){
    int i;
    //imprime valores

    if((*arv) !=NULL){
        for (i =0; i < (*arv) -> contador; i++){
            printf("%d ", (*arv)-> valores[i]);
        }

        for (i = 0; i <= (*arv)-> contador; i++){
            PercusoPreOrdemMF(&(*arv) -> filhos[i]);
        }
    
    }

}

void PercusoOrdemMF(tipo_arv_MF**arv){
    int i;
    //imprime valores

    if((*arv) != NULL){
        for (i = 0; i < (*arv)-> contador; i++)
        {
            PercusoOrdemMF(&(*arv) -> filhos[i]);
            printf("%d ",(*arv)-> valores[i]);
        }

        PercusoOrdemMF(&(*arv)-> filhos[i]);

    }


}

void PercusoPosOrdemMF(tipo_arv_MF** arv){
    int i;
    //imprime valores

    if((*arv )!= NULL){
        for (i = 0; i <= (*arv)-> contador; i++)
        {
            PercusoPosOrdemMF(&(*arv) -> filhos[i]);
        }

        for (i =0; i < (*arv) -> contador; i++){
            printf("%d ", (*arv) -> valores[i]);
        }
    }
}

void ImprimeNivelArvMF(tipo_arv_MF *arv, int nvl){

    if (arv != NULL){

        if (nvl > AlturaArvMF(arv)){
            printf ("\n[ERRO]\n\n");
        }else{
            if (nvl == 0){
                printf("[ ");
                for (int i = 0; i < arv -> contador; i++)
                {
                    printf("%d ", arv -> valores[i]);
                }
                printf("]\n");
                
            }else{
                for (int i = 0; i <= arv -> contador; i++)
                {
                    ImprimeNivelArvMF(arv -> filhos[i], nvl - 1);
                }
            }
        }
    }

}

