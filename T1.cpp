/*
    PAA - T1

    Cristian Cesar Martins  - 799714
    Vitor Gabriel Orsin     - 801575
*/


#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

// Merge
void Merge(float notas[], int const esq, int const meio, int const dir){
    int const tamanhoNotasEsq = meio - esq + 1;
    int const tamanhoNotasDir = dir - meio;
 
    float *notasEsq  = new float[tamanhoNotasEsq];
    float *notasDir = new float[tamanhoNotasDir];
 
    // Copia os dados do vetor para os vetores auxiliares
    for (int i = 0; i < tamanhoNotasEsq; i++)
        notasEsq[i] = notas[esq + i];
    for (int j = 0; j < tamanhoNotasDir; j++)
        notasDir[j] = notas[(meio + 1) + j];
 
    int iEsq = 0, iDir = 0;
    int iMerge = esq;
 
    // Ordena o vetor
    while (iEsq < tamanhoNotasEsq && iDir < tamanhoNotasDir) {
        if (notasEsq[iEsq] >= notasDir[iDir]) {
            notas[iMerge] = notasEsq[iEsq];
            iEsq++;
        }
        else {
            notas[iMerge] = notasDir[iDir];
            iDir++;
        }
        iMerge++;
    }

    // Termina de copiar o vetor auxiliar caso exista algum elemento que não está no vetor
    while (iEsq < tamanhoNotasEsq) {
        notas[iMerge] = notasEsq[iEsq];
        iEsq++;
        iMerge++;
    }
    while (iDir < tamanhoNotasDir) {
        notas[iMerge] = notasDir[iDir];
        iDir++;
        iMerge++;
    }

    // Desaloca os vetores auxiliares
    free(notasEsq);
    free(notasDir);
}
 

// Merge Sort recursivo
void MergeSort(float notas[], int const inicio, int const fim){
    if (inicio >= fim) // Caso base
        return;
 
    int meio = inicio + (fim - inicio) / 2;
    MergeSort(notas, inicio, meio);
    MergeSort(notas, meio + 1, fim);
    Merge(notas, inicio, meio, fim);
}

int main(){
    int nVagas = 0;
    int nProximaFase = 0;
    int nConcorrentes = 0;
    float* notasCandidato;

    // Input numero de vagas
    cin >> nVagas;

    for(int vagas = 0; vagas < nVagas; vagas++){
        // Input numero de aceitos no grupo
        cin >> nProximaFase;

        // Input numero total de concorrentes no grupo
        cin >> nConcorrentes;
        notasCandidato = new float[nConcorrentes];

        for(int concorrente = 0; concorrente < nConcorrentes; concorrente++)
            cin >> notasCandidato[concorrente];


        // Merge Sort
        MergeSort(notasCandidato, 0, nConcorrentes-1);

        // Resposta
        cout << notasCandidato[nProximaFase - 1] << endl;
    }

    return 0;
}