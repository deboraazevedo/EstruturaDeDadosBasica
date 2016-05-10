#include <iostream>
#include <stdlib.h>
#define MAX 10
using namespace std;

template <class T>
T SELECAO(T vetor ){
int i, j;
for (i = 0; i<= MAX-1; i++){
	int min = i;
	for (j = i+1; j<= MAX-1; j++){
		if (vetor[j] < vetor[min]){
			min = j;
			}
		if (i != min){
			int aux_min = vetor[min];
			vetor[min] = vetor[i];
			vetor[i] = aux_min;
			}
		}
	}

	for (i = 0; i <= MAX-1; i++){
	cout << vetor[i] << endl;
		}

	return 0;
  }




int main(){
	int vetor1[MAX] = {9,8,7,6,5,4,3,2,1,0};
	int vetor2[MAX] = {3,6,9,8,5,2,1,4,7,0};

	 SELECAO(vetor1);

	return 0;

}

