Busca Sequencial nao - ordenada e simples
int busca_sequencial(int k, int colecao[], int tamanho)
{
 int posicao = 0;
 do {
 if( k == colecao[posicao] ){
 return posicao; // SUCESSO
 }
 posicao = posicao + 1;
 } while(posicao < tamanho);
 return -1; // INSUCESSO
}

Busca Sequencial ordenada

int busca_sequencial(int k, int colecao[], int tamanho)
{
 int posicao = 0;
 do {
 if( k == colecao[posicao] ){
 return posicao; // SUCESSO
 }
 else if( k < colecao[posicao] ){
 return -1; // INSUCESSO
 }
 posicao = posicao + 1;
 } while(posicao < tamanho);
 return -1; // INSUCESSO
}

Busca Binaria iterativa- apenas pra vetores ordenados sendo mais eficiente do que a recursiva
int busca_binaria(int k, int colecao[], int tamanho){
 int inicio = 0, fim = tamanho-1, meio;
 while(inicio <= fim){
 meio = (inicio+fim)/2;
 if( k < colecao[meio] ){
 fim = meio -1;
 }
 else if( k > colecao[meio] ){
 inicio = meio + 1;
 }
 else {
 return meio;
 }
 }
 return -1;
}

int busca_binaria recursivo(int k, int colecao[], int inicio, int fim) {
 if( inicio > fim ){
 return -1;
 }
 int meio = (inicio+fim)/2;
 if( k < colecao[meio] ){
 return b(k, colecao, inicio, meio-1);
 }
 else if( k > colecao[meio] ){
 return b(k, colecao, meio+1, fim);
 }
 else{
 return meio;
 }
}
