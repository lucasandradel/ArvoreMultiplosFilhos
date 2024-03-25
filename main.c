#include <stdlib.h>
#include <stdio.h>

#include "ArvoreMF.h"

int main(int argc , char *argv[]){
    tipo_arv_MF *minha_arv;
    minha_arv = NULL;
    

    InsereArvMF(&minha_arv, 50);
    InsereArvMF(&minha_arv, 20);
    InsereArvMF(&minha_arv, 30);
    InsereArvMF(&minha_arv, 40);
    InsereArvMF(&minha_arv, 5);
    InsereArvMF(&minha_arv, 18);
    InsereArvMF(&minha_arv, 99);
    InsereArvMF(&minha_arv, 23);
    InsereArvMF(&minha_arv, 1);
    InsereArvMF(&minha_arv, 24);
    InsereArvMF(&minha_arv, 9);



    return EXIT_SUCCESS;
}