//
//  main.cpp
//  Aula11-qsort
//
//  Created by Eiji Adachi Medeiros Barbosa on 08/09/16.
//  Copyright (c) 2016 Eiji Adachi Medeiros Barbosa. All rights reserved.
//

#include <iostream>
#include <cassert>

int partition(int[], int, int);
bool isPartitioned(int[], int, int);

void printVector(int v[], int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout <<std::endl;
}

int main(int argc, const char * argv[]) {
    
    // Teste 1: vetor em ordem crescente
    int v1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17}, n1 = 17;
    int pivo1 = v1[n1-1];
    int iPivo1 = partition(v1, 0, n1-1);

    assert( v1[iPivo1] == pivo1 );
    assert( isPartitioned(v1, n1, iPivo1) );
    
    printVector(v1, n1);
    
    // Teste 2: vetor em ordem decrescente
    int v2[] = {17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1}, n2 = 17;
    int pivo2 = v2[n2-1];
    int iPivo2 = partition(v2, 0, n2-1);

    assert( v2[iPivo2] == pivo2 );
    assert( isPartitioned(v2, n2, iPivo2) );
    
    printVector(v2, n2);
    
    // Teste 1: vetor aleatório
    int v3[] = {0,1,11,2,12,3,13,4,14,5,15,6,16,7,17,8,18,9,19,10}, n3 = 20;
    int pivo3 = v3[n3-1];
    int iPivo3 = partition(v3, 0, n3-1);

    assert( v3[iPivo3] == pivo3 );
    assert( isPartitioned(v3, n3, iPivo3) );
    
    printVector(v3, n3);
    
    return 0;
}

bool isPartitioned(int v[], int size, int iPivot)
{
    for( int i = 0; i < iPivot; i++ )
    {
        if( v[i] > v[iPivot] )
        {
            return false;
        }
    }
    for( int i = iPivot+1; i < size; i++ )
    {
        if( v[i] < v[iPivot] )
        {
            return false;
        }
    }
    
    return true;
}



//  Created by Débora Karoline Silva de Azevedo on 08/09/16.

//Função que particiona o vetor e o ordena sem vetor auxiliar (quick sort).

int partition(int v[], int left, int right)
{
    int pivo = v[right];

    int i = left;
    int j = right - 1;

    int aux;
    int aux_right;

    while (j>= i){

        while (v[i] < pivo) {
            i++;
        }

        while (v[j] > pivo){
            j--;
        }

        if (j >= i){
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }

    }

    aux_right = v[i];
    v[i] = v[right];
    v[right] = aux_right;



    // Obrigatoriamente, o pivo deve pivo = v[right];
    return i;
}
