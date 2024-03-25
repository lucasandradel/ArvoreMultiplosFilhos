#include <stdio.h>
#include <stdlib.h>

#ifndef __ARVOREMF_H__
#define __ARVOREMF_H__

#define t 3

struct est_arv_mult_filhos
{
    int valores[t];
    struct est_arv_mult_filhos *filhos [t + 1];
    int contador;
    
};
typedef struct est_arv_mult_filhos tipo_arv_MF;

tipo_arv_MF *AlocaNo(int);
void InsereArvMF(tipo_arv_MF**, int);//ok
int BuscaArvMF(tipo_arv_MF**, int);//ok
void PercusoPreOrdemMF(tipo_arv_MF**);//ok
void PercusoOrdemMF(tipo_arv_MF**);//ok
void PercusoPosOrdemMF(tipo_arv_MF**);//ok
int contabilizaNosArvMF(tipo_arv_MF**);//ok
int ContabilizaValores(tipo_arv_MF**);//ok
int ContabilizaFolhas(tipo_arv_MF**);//ok
int AlturaArvMF(tipo_arv_MF*);//ok
void ImprimeNivelArvMF(tipo_arv_MF*, int);//ok
int BuscaMaiorVlArvMF(tipo_arv_MF**);//ok
int BuscaMenorVlArvMF(tipo_arv_MF **);//ok
int Ehfolha(tipo_arv_MF*);//ok
void RemoveArvFolha(tipo_arv_MF**, int);//falta





#endif