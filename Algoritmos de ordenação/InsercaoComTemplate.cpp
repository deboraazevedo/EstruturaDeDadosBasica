#include <iostream>
#include <stdlib.h>
#define MAX 10
using namespace std;
template <class T>
T INSERCAO(T vetor ){
int i, j;
for (i = 0; i<= MAX-1; i++){
	int novo = vetor[i];
	j = i-1;
	while (j >= 0 && novo< vetor[j]){
		vetor[j+1] = vetor[j];
		j = j-1;
	}
	vetor[j+1] = novo;
	}
	//imprimir
	for (i = 0; i <= MAX-1; i++){
		cout << vetor[i] << endl;
	}
	return 0;
}

int main(){

	int vetor1[MAX] = {9,8,7,6,5,4,3,2,1,0};
	int vetor2[MAX] = {3,6,9,8,5,2,1,4,7,0};

	INSERCAO(vetor1);

	return 0;

}

