#include <iostream>
#include <stdlib.h>
#define MAX 10
#include <string>
using namespace std;

template <class T>
T BubbleSort(T vetor, int tamanho ){
  int aux;
  for(int i=tamanho-1; i >= 1; i--) {
    for(int j=0; j < i ; j++) {
      if(vetor[j]>vetor[j+1]) {
        aux = vetor[j];
        vetor[j] = vetor[j+1];
        vetor[j+1] = aux;

      }
   }
}
   for( int r = 0; r < 10; ++r){
    cout<<vetor[r];
   }
}

template <>
char BubbleSort(char vetor, int tamanho ){
  int aux;
  for(int i=tamanho-1; i >= 1; i--) {
    for(int j=0; j < i ; j++) {
      if(vetor[j]>vetor[j+1]) {
        aux = vetor[j];
        vetor[j] = vetor[j+1];
        vetor[j+1] = aux;

      }
   }
}
   for( int r = 0; r < 10; ++r){
    cout<<vetor[r];
   }
}


int main(){

	int vetor1[MAX] = {9,8,7,6,5,4,3,2,1,0};
	int vetor2[MAX] = {3,6,9,8,5,2,1,4,7,0};
	char v[5][10] = {"aviao", "gato", "papagaio", "nadegas", "violencia"};
	

	BubbleSort(v,10);

	return 0;

}

