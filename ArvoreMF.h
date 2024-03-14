#include <stdio.h>
#include <stdlib.h>

#ifndef __ARVOREMF_H__
#define __ARVOREMF_H__

#define t 3

struct est_arv_mult_filhos
{
    int valores[t];
    struct est_arv_mult_filhos **filhos [t + 1];
    int contador;
    
};
typedef struct est_arv_mult_filhos tipo_arv_MF;

tipo_arv_MF *AlocaNo(int);
void InsereArvMF(tipo_arv_MF**, int);
int BuscaArvMF(tipo_arv_MF*, int);
void PercusoPreOrdemMF(tipo_arv_MF*);
void PercusoOrdemMF(tipo_arv_MF*);
void PercusoPosOrdemMF(tipo_arv_MF*);
int contabilizaNosArvMF(tipo_arv_MF*);
int AlturaArvMF(tipo_arv_MF*);
void ImprimeNivelArvMF(tipo_arv_MF*);
int BuscaMaiorVlArvMF(tipo_arv_MF*);
int BuscaMenorVlArvMF(tipo_arv_MF*);





#endif