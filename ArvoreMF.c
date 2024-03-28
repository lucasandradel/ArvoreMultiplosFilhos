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
        printf("\n[BUSCA INVÁLIDA], Valor não encontrado ou árvore nula\n\n");
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
            printf("Maior valor encontrado: %d \n\n", (*arv)-> valores [i - 1]);
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
        
       /*for ( i = 0; i <= (*arv)-> contador; i++){
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
            flag = flag + ContabilizaFolhas(&(*arv) -> filhos[i]);
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
        for (i = 1; i <= arv -> contador; i++){
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

int FilhoProx(tipo_arv_MF * arv, int idx){
    int i, cont_esq, contd_dir;
    cont_esq = 0;

    for (i = idx; (i > 0) && (arv -> filhos[i] == NULL); i--){
        cont_esq++;
    }

    if (arv -> filhos[i] == NULL){
        cont_esq = t * t ; 
    }

    contd_dir = 0;

    for (i= idx; (i < arv -> contador) && (arv -> filhos[i] == NULL) ; i ++){
        contd_dir++;
    }

    if (arv -> filhos[i] == NULL){
        contd_dir = t * t ; 
    }

    if (cont_esq > contd_dir){
        return cont_esq;
    }else{
        return contd_dir;
    }

}

void RemoveArvMF(tipo_arv_MF ** arv, int vl){
    int i, novoValor;

    if ((*arv) != NULL){
        i = 0;
        while ( (i < (*arv) -> contador) && ((*arv) -> valores[i] < vl)){/*enquanto valor na posição do indice for menor que o contador, 
        e o valor que quero remover for maior que o valor que está no indice indicado, vou para o indice da frente*/
            i++;
        
        }
        if( (i < (*arv) -> contador) && ((*arv) -> valores[i] == vl)){ //se o indice for menor que o contador e o valor que quero remover for igual ao valor do indice da arvore
            if (Ehfolha((*arv))){ // verifico se o nó é folha e for folha:
                if ((*arv) -> contador > 1){ //verifico se o nó tem mais de um valor
                    for (; i < (*arv) -> contador - 1; i++){//se tiver mais de um valor, reposiciono todos os valores
                        (*arv) -> valores [i] = (*arv) -> valores [i + 1];// reposiciono todos os valores, até que o valor que quero remover vá para o ultimo indice 
                    }
                    (*arv) -> contador --;//decremento o contador e elimino o valor 
                }else{// caso tenha apenas um valor:
                    free (*arv);//elimino todo o nó
                    (*arv) = NULL;//aponto o nó pai do nó removido para nulo
                }
            }else{// caso o nó não for folha faça:

                if ((*arv) -> filhos[i] != NULL){//verifcar se existe filho esquerdo
                    novoValor = BuscaMaiorVlArvMF(&(*arv) -> filhos [i]);//se existir filho esquerdo, busco o maior valor do filho esquerdo, neste caso usei a função que busca o maior valor do filho esquerdo e guardo na váriavel novo valor
                    (*arv) -> valores [i] = novoValor; //após achar o o maior valor do lado direito, e armazenar em novo valor, substituo o filho esquerdo do indice por novo valor
                    RemoveArvMF(&(*arv) -> filhos[i], novoValor);// faço chamada recursiva passando o filho esquerdo do indice, e novo valor

                }else{// caso o nó não tenha filho esquerdo , buscar o filho direito 
                    if ((*arv) -> filhos[i + 1] != NULL){//verifcar se existe filho direito
                        novoValor = BuscaMenorVlArvMF(&(*arv)-> filhos[i + 1]);//se houver, buscar o menor valor do do filho direito e armazenar em novo valor   
                        (*arv) -> valores [i + 1] = novoValor;//substituir o filho direito do indice por
                        RemoveArvMF(&(*arv) -> filhos [ i + 1 ], novoValor);//chamada recursiva, passando com parâmetro o filho direito e o novo valor

                    }else{// caso o não seja folha e não tenha filho esquerdo e nem direto 

                        int i_filho = FilhoProx((*arv), i);// busco o valor com o filho mais próximo, tanto a esquerda tanto a direita e comparo eles (feito nessa função)
                        if (i > i_filho){// se o filho mais próximo estiver a esquerda faça:
                            while ( i > i_filho)//enquanto o o valor que tem o filho for menor que o valor que quero remover
                            {
                                (*arv) -> valores [i] = (*arv) -> valores[i -1];//reposiciono os valores até chegar nele 
                                i --;
                            }
                            novoValor = BuscaMaiorVlArvMF((&(*arv) -> filhos[i_filho]));//cheguei no valor que tenho o filho, busco o maior valor do seu ramo esquerdo
                            (*arv) -> valores [i] = novoValor;//substituo o maior valor do seu ramo esquerdo pelo valor que quero remover 
                            RemoveArvMF(&(*arv) -> filhos[i_filho], novoValor);
 
                        }else{
                            if (i < i_filho){
                                while (i < i_filho)
                                {
                                    (*arv) -> valores [i] = (*arv) -> valores [i + 1];
                                    i++;
                                }

                                novoValor = BuscaMenorVlArvMF(&(*arv) -> filhos [i_filho]);
                                (*arv) -> valores[i] = novoValor;
                                RemoveArvMF(&(*arv) -> filhos[i_filho], novoValor);
                                
                            }
                        }
                    }
                }
            }  
        }else{
            //se o valor não for encontrado na busca, faço chamada recursia para o filho
            RemoveArvMF(&(*arv) -> filhos [i], vl);
        }
    }
}
