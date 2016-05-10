/*
 *
 *   Este é o único arquivo que você irá modificar durante toda esta atividade.
 *
 */


#include <stdlib.h>
#include <iostream>
#include "Lista.h"

#define VALOR_QUALQUER -10000

No CriarNo(int);
bool DestruirNo(No);

/**
    Função que aloca memória para uma instância da estrutura Lista e inicializa os seus campos.
 */
Lista LIS_Criar(){
    Lista lista = (Lista)malloc(sizeof(tpLista));
    if( lista == NULL ){
        return NULL;
    }

    lista->cabeca = CriarNo(VALOR_QUALQUER);
    if( lista->cabeca == NULL ){
        return NULL;
    }

    lista->cauda = CriarNo(VALOR_QUALQUER);
    if( lista->cauda == NULL ){
        return NULL;
    }


    lista->cabeca->proximo  = lista->cauda;
    lista->cauda->anterior = lista->cabeca;
    lista->cabeca->anterior = NULL;
    lista->cauda->proximo = NULL;

    return lista;
}

/*
    Função que busca a posição de uma determinada chave numa lista.
    @param lista - lista em que será feita a busca
    @param chave - chave a ser buscada na lista
    @return índice que indica a posição do elemento cujo valor é igual a chave. Retorna -1 caso a chave não seja encontrada na lista.
 */
int LIS_Buscar(Lista lista, int chave){
  No no = lista->cabeca->proximo;
  for (int i = 0; i < lista->tamanho; i++){
    if (no->valor == chave) {
      i++;
      return i;
    }
    no = no->proximo;
  }

    return -1;
}

/*
 Função que retorna o valor de um elemento na lista que está na posição indicada pelo parâmetro i.
 @param lista - lista em que será feita a busca
 @param i - indica a posição do elemento cujo valor se deseja retornar
 @return valor do elemento na i-esima posição da lista. Retorna -1 se não existir elemento na i-esima posição
 */
int LIS_PegarValor(Lista lista, int i)
{
    No no = lista->cabeca->proximo;
    int x = 0;
    if (i > lista->tamanho){
      return -1;
    }

    else {
      while (x < i) {
        no = no->proximo;
      }
      return no->valor;
    }
}

/*
 Função que insere um valor no início da lista. Após a execução desta função, o elemento inserido será o primeiro elemento da lista.
 @param lista - lista em que será feita a inserção
 @param v - valor a ser inserido na lista
 @return true se inseriu com sucesso, false caso contrário
 */
bool LIS_InserirInicio(Lista lista, int v)
{
    No no = CriarNo(v);
    if( no == NULL ){
        return false;
    }

    No primeiro = lista->cabeca->proximo;


    lista->cabeca->proximo = no;
    no->anterior = lista->cabeca;
    no->proximo = primeiro;
    primeiro->anterior = no;

    return true;
}

/*
 Função que insere um valor no fim da lista. Após a execução desta função, o elemento inserido será o último elemento da lista.
 @param lista - lista em que será feita a inserção
 @param v - valor a ser inserido na lista
 @return true se inseriu com sucesso, false caso contrário
 */
bool LIS_InserirFim(Lista lista, int v)
{
    No no = CriarNo(v);
    if( no == NULL ){
        return false;
    }
    
    No ultimo = lista->cauda->anterior;

    lista->cauda->anterior = no;
    no->proximo = lista->cauda;
    no->anterior = ultimo;    
    ultimo->proximo = no;

    lista->tamanho++;
    return true;
}



/*
 Função que insere um valor numa determinada posição da lista. Após a execução desta função, o elemento inserido será o i-esimo elemento da lista.
 @param lista - lista em que será feita a inserção
 @param v - valor a ser inserido na lista
 @param i - indica a posição que o novo elemento ocupará após a inserção
 @return true se inseriu com sucesso, false caso contrário
 */
bool LIS_Inserir(Lista lista, int v, int i)
{
    No novo = CriarNo(v);
    if( novo == NULL ){
        return false;
    }
    
    No no = lista->cabeca;

    if (i > lista->tamanho+1 || i <= 0){  
        return false;
    }
    
    if(i == lista->tamanho+1){
        return LIS_InserirFim(lista,v);
    }
    if(lista->tamanho == 0){
        return LIS_InserirInicio(lista,v);
    }
    
    while (--i){   
        no = no->proximo;
    }
    
    novo->anterior = no;
    novo->proximo = no->proximo;
    no->proximo->anterior = novo;
    no->proximo = novo;
    lista->tamanho++;

    return true;
}

/*
 Função que remove um valor no início da lista.
 @param lista - lista em que será feita a remoção
 @return retorna o valor do elemento removido. Retorna -1 caso a lista esteja vazia.
 */
int LIS_RemoverInicio(Lista lista)
{
        if (lista->cabeca->proximo == lista->cauda) {
          return -1;
        }

        else{
          No primeiro = lista->cabeca->proximo;

          lista->cabeca->proximo = primeiro->proximo;
          primeiro->proximo->anterior = lista->cabeca;
          int valorretirado = primeiro->valor;

          DestruirNo(primeiro);

          lista->tamanho--;

          return valorretirado;
        }
}

/*
 Função que remove um valor no fim da lista.
 @param lista - lista em que será feita a remoção
 @return retorna o valor do elemento removido. Retorna -1 caso a lista esteja vazia.
 */
int LIS_RemoverFim(Lista lista)
{
    if (lista->tamanho == 0){
        return -1;
    }

    else{
        No ultimo = lista->cauda->anterior;

        lista->cauda->anterior = ultimo->anterior;
        ultimo->anterior->proximo = lista->cauda;
        int valorremovido = ultimo->valor;

        DestruirNo(ultimo);

        lista->tamanho--;

        return valorremovido;
    }
    
}

/*
 Função que remove um valor numa determinada posição da lista.
 @param lista - lista em que será feita a remoção
 @param indice - indica a posição na lista do elemento que se deseja remover
 @return retorna o valor do elemento removido. Retorna -1 caso a lista esteja vazia, ou caso o índice não aponte para uma posição válida da lista.
 */
int LIS_Remover(Lista lista, int indice)
{
    if (indice > lista->tamanho || indice <= 0){  
        return -1;
    }
    
    if(lista->tamanho == 0){
        return -1;
    }
    if (indice == 1){
        return LIS_RemoverInicio(lista);
    }
    
    No no = lista->cabeca;

    while (--indice){   
        no = no->proximo;
    }

    int valorremovido = no->valor;

    no->anterior->proximo = no->proximo;
    no->proximo->anterior = no->anterior;
    lista->tamanho--;

    return valorremovido;
}

/*
    Função que ordena a lista. (Obs.: Implemente os algoritmos: selection sort, insertion sort e bubble sort.)
 */


void SelectionSort (Lista lista) {
    No temporario = lista->cabeca->proximo;
    No auxiliar;

    int k;

    for (int i =0; i < lista->tamanho; i++) {
        auxiliar = temporario->proximo;
	    for (int j = i; j < lista->tamanho; j++) {
	        if (temporario->valor > auxiliar->valor) {
		        k = temporario->valor;
		        temporario->valor = auxiliar->valor;
		        auxiliar->valor = k;
	        }

	        auxiliar = auxiliar->proximo;

	    }
	    temporario = temporario->proximo;
    }

}



void InsertionSort(Lista lista) {
    int i, j, t;
    No temporario = lista->cabeca->proximo;
    No auxiliar;

    for (j = 1; j < lista->tamanho; j++){
	i = j -1;
	auxiliar = temporario->proximo;
	while (i >=0 && temporario->valor > auxiliar->valor) {
	    t = temporario->valor;
	    temporario->valor = auxiliar->valor;
            i = i - 1;
	    auxiliar = auxiliar->proximo;
	}
	temporario = temporario->proximo;
    }        

}




void LIS_Ordenar(Lista lista) {

    SelectionSort(lista);


/*
    int aux;

    No no = lista->cabeca->proximo;

    for(int i=1; i < lista->tamanho;i++){
        if (no->valor > no->proximo->valor){
            aux = no->valor;
            no->valor = no->proximo->valor;
            no->proximo->valor = aux;
        }
        no = no->proximo;
    }

    
*/}

/*
    Função que intercala duas listas ordenadas, retornando uma nova lista contendo a intercalação das duas listas de entrada.
 */
Lista LIS_Intercalar(Lista lista1, Lista lista2)
{
    Lista listaResultado = LIS_Criar();
    listaResultado->tamanho = lista1->tamanho + lista2->tamanho;

    listaResultado->tamanho = 0;

    No no1 = lista1->cabeca->proximo;
    No no2 = lista2->cabeca->proximo;
    int j;
    int k = 1;


    if (lista1->tamanho <= lista2->tamanho) {
	do {
	    if (k%2) {
		LIS_Inserir(listaResultado, no1->valor, k);
		no1 = no1->proximo;	    
	    }

	    else {
		LIS_Inserir(listaResultado, no2->valor, k);
		no2 = no2->proximo;	    
	    }
	    j++;
	} while (no1->proximo);

	
	while (no2->proximo) {
	    LIS_Inserir(listaResultado, no2->valor, k);	
	    no2 = no2->proximo;
	    k++;
	
	}
	

    else {
	do {
	    if (k%2) {
		LIS_Inserir(listaResultado, no1->valor, k);
		no1 = no1->proximo;
	    }

	    else {
		LIS_Inserir(listaResultado, no2->valor, k);
		no2 = no2->proximo;
	    }
	    k++;
	} while (no1->proximo);
	
	while (no1->proximo) {
	    LIS_Inserir (listaResultado, no1->valor, k);
	    no1 = no1->proximo;
	    k++;
	}

    }
}
 	   LIS_Ordenar(listaResultado);

    return listaResultado;


}


}



/*
	Função que insere um valor na lista mantendo-a orenadada.
*/
bool LIS_InserirOrdenado(Lista lista, int v)
{
    No prov = lista->cabeca->proximo;
    int contador = 1;
    while(v > prov->valor && prov != lista->cauda){
        prov = prov->proximo;
        contador ++;
    }
    LIS_Inserir(lista, v, contador);
    return true;
}





/*
    Função que verifica se uma determinda instância da estrutura lista obedece a todas suas invariantes.
 */
 LIS_tpVerificacao LIS_Verificar(Lista lista)
 {
     if( lista->cabeca == NULL )
     {
         returnLIS_CabecaNula;
     }
     elseif( lista->cabeca->proximo == NULL )
     {
         returnLIS_CabecaProximoNulo;
     }
     elseif( lista->cabeca->proximo->anterior != lista->cabeca )
     {
         returnLIS_EncadeamentoErrado;
     }
     elseif( lista->cabeca->anterior != NULL )
     {
         returnLIS_CabecaAnterior;
     }

     if( lista->cauda == NULL )
     {
         returnLIS_CaudaNula;
     }
     elseif( lista->cauda->anterior == NULL )
     {
         returnLIS_CaudaAnteriorNulo;
     }
     elseif( lista->cauda->anterior->proximo != lista->cauda )
     {
         returnLIS_EncadeamentoErrado;
     }
     elseif( lista->cauda->proximo != NULL )
     {
         returnLIS_CaudaProximo;
     }

     if(lista->tamanho == 0)
     {
         if( lista->cabeca->proximo != lista->cauda )
         {
             returnLIS_CabecaCauda;
         }

         if( lista->cabeca != lista->cauda->anterior )
         {
             returnLIS_CabecaCauda;
         }
     }
     else
     {
         // Verifica encadeamento dos elementos
         for(No i = lista->cabeca->proximo; i != lista->cauda; i=i->proximo)
         {
             if( i->proximo->anterior != i )
             {
                 returnLIS_EncadeamentoErrado;
             }
             if( i->anterior->proximo != i )
             {
                 returnLIS_EncadeamentoErrado;
             }
         }
     }

     returnLIS_OK;

 }
/*
    Função que imprime todos os elementos de uma lista.
 */
void LIS_Imprimir(Lista lista)
{
    std::cout << "Tamanho " << lista->tamanho << std::endl;
    for(No i = lista->cabeca->proximo; i != lista->cauda; i = i->proximo)
    {
        std::cout << "[" << i->valor << "]->";
    }
    std::cout << std::endl;
}

/**
 Função que libera a memória de uma instância da estrutura Lista, liberando a memória de todos os nós encadeados na lista, incluindo os nós cabeça e cauda.
 */
void LIS_Destruir(Lista lista)
{
    No atual = lista->cabeca;
    while( atual != NULL )
    {
        No destruido = atual;
        atual = atual->proximo;
        DestruirNo(destruido);
    }
    free(lista);
}

/*
 Função que aloca a memória para um nó e inicializa os atributos do nó.
 */
No CriarNo(int v)
{
    No no = (No) malloc( sizeof( tpNo ) );
    if( no == NULL )
    {
        return NULL;
    }

    no->proximo = NULL;
    no->anterior = NULL;

    no->valor = v;

    return no;
}

/*
 Função que libera a memória alocada para um nó.
 */
bool DestruirNo(No no)
{
    free(no);
    return true;
}
