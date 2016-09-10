//
//  main.cpp
//  Timer
//
//  Created by Eiji Adachi Medeiros Barbosa
//  Copyright (c) 2016 Eiji Adachi Medeiros Barbosa. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>

using namespace std;

void selection_sort(int[], int);
void insertion_sort(int[], int);
bool isOrdered(int[], int);
void merge_sort(int v[], int esquerda, int direita);
void sort(int[], int);



bool readInput(const string, int[], int);

int main(int argc, const char * argv[]) {
    if(argc != 3){
        cout << "Programa espera argumentos:\n1 - indicando o caminho do arquivo de entrada\n2 - indicando a quantidade de números a serem lidos da entrada" << endl;
        return -1;
    }

    const string path = argv[1];
    const int size = stoi(argv[2]);
    
    int v[size];
    int read = readInput(path, v, size);
    if(!read)
    {
    	return -1;
    }
    
    // inicio da medição
	auto start = std::chrono::high_resolution_clock::now();
        
	sort(v, size);
        
	// fim da medição
	auto end = std::chrono::high_resolution_clock::now();
	
	if( !isOrdered(v, size) )
	{
		cout << "Dados de entrada não estão ordenados corretamente" << endl;
		return -1;
	}
        
	// duração da medição
	auto dur = end - start;
	
	auto f_secs = std::chrono::duration_cast<std::chrono::duration<float>>(dur);
    
	cout << setprecision(4) << f_secs.count() << " s" << endl;
    
    return 0;
}


void imprimir_vetor(int v[], int size){

	for (int i = 0; i <= size; i++){

		cout << v[i] << endl;
	}
}



void selection_sort(int v[], int size)
{
	int i, j;

	//laço que percorre desde o primeiro elevento do vetor até tamanho
	for (i = 0; i < size; i++){

		//variavel p guardar o valor mínimo, à medida que o algoritmo é percorrido
		int min = i;

		for (j = i+1; j < size; j++){

			if (v[j] < v[min]){

				//aqui, verifica se o j é menor que o mínimo, assim, min recebe j (novo minimo)
				min = j;
			}

		}
				//se i não for o mínimo, ele cria um novo auxiliar pra receber o valor da posição v[min]
				int aux_min = v[min];
				//aqui acontece o swap
				v[min] = v[i];
				v[i] = aux_min;
	}
}





void insertion_sort(int v[], int size)
{
	//inteiro auxiliar para receber o valor do proximo elemento do vetor
	int aux;

	//laço que percorre desde o primeiro elevento do vetor até tamanho
	for (int i = 1; i < size; i++){

		//variavel p guardar o valor seguinte, o "proximo"
		aux = v[i];

		int j;

		// aqui, o meu j vai até i - 1, considerando que meu espaço no vetor vai de v [ 0 ... i -1]
		//assim sendo, ele começa com i-1 (ultimo elemento que eu quero considerar) até 0 (primeira posição do vetor), da direita p esquerda
		for(j = i-1; j>=0; j--)
		{
			// nesse caso,  o v[j] já está na posição correta
			if(v[j]<aux)
			{
				break;
			}
			else
			{
				// no caso de v[j] ser maior que o aux, transfiro o valor de v[j + 1] para v[j] (posição v[j] anterior)
				v[j + 1] = v[j];
			}
		}

		v[j + 1] = aux;



	}
}


void bubble_sort(int v[], int size){

	int aux;

	int fim = 0;

	int j = 0;

	bool troca = true;

	while (troca){

		troca = false;
		for (int i = 1; i <= size - fim; i++){
			if (v[j] > v[j + 1]){
				v[i] = aux;
				//v[i] = v[j];
				//v[j] = aux;
				troca = true;
			}
				

		}

		fim++;
	}

	
}



void intersperse(int v[], int inicio1, int inicio2, int fim2){

	int fim1 = inicio2 - 1;
	int i = inicio1;
	int j = inicio2;
	int k = 0;
	int tamanho = fim2 - inicio1 + 1;
	int tmp[tamanho];
	int x = 0;

	while (i <= fim1 && j <=fim2){

		if (v[i] <= v[j]){

			tmp[k] = v[i];
			i++;

		}

		else {

			tmp[k] = v[j];
			j++;
		}
	}


	while (i <= fim1){

		tmp[k] = v[i];
		i++;
		k++;

	}

	while (j <= fim2){

		tmp[k] = v[j];
		j++;
		k++;
		
	}

	while(x <= fim2){

		v[x] = tmp[x];
		x++;
	}

	for(i = inicio1, j = 0; i <= fim2; i++, j++){

		v[i] = tmp[j];

	}

}


void sort(int v[], int size)
{
	merge_sort(v, 0, size-1);
}

void merge_sort(int v[], int esquerda, int direita){

	if (esquerda < direita){

		int meio = (esquerda + direita)/2;

		merge_sort(v, esquerda, meio);

		merge_sort(v, meio + 1, direita);

		intersperse(v, esquerda, meio + 1, direita);


	}
}





bool isOrdered(int v[], int size)
{
    for(int i = 1; i < size; i++)
    {
        if(v[i-1] > v[i])
        {
            return false;
        }
    }
    
    return true;
}

bool readInput(const string path, int v[], int size){
    ifstream file(path);
    
    if(!file.is_open())
    {
    	cout << "Could not open file: " << path << endl;
    	return false;
    }
    
    for( int i = 0; i < size; i++){
        int x;
        file >> x;
        v[i] = x;
    }
    
    file.close();
    
    return true;
}
