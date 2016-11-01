#include <iostream>
#include "lista-simplesmente-encadeada.h"

int main(int argc, char const *argv[])
{
	ListaSimplesmenteEncadeada<int> lista;
	lista.InserirNoInicio(23);
	lista.Listar();
	lista.InserirNoInicio(33);
	lista.Listar();
	lista.InserirNoInicio(43);
	lista.Listar();
	std::cout << lista.GetTamanho() << " elementos" << std::endl;
	lista.InserirNoFinal(11);
	lista.Listar();
	lista.InserirNaPosicao(55,3);
	lista.Listar();
	lista.InserirNaPosicao(66,0);
	lista.Listar();
	lista.InserirNaPosicao(88,12);
	lista.Listar();
	lista.RemoverDoInicio();
	lista.Listar();
	lista.RemoverDoFinal();
	lista.Listar();
	lista.RemoverDaPosicao(3);
	lista.Listar();

	ListaSimplesmenteEncadeada<std::string> palavras;
	palavras.InserirNoInicio("Ana");
	palavras.InserirNoFinal("Paulo");
	palavras.InserirNoFinal("Silvio");
	palavras.InserirNaPosicao("Carla",2);
	palavras.Listar();
	palavras.RemoverDaPosicao(3);
	palavras.Listar();
	return 0;
}