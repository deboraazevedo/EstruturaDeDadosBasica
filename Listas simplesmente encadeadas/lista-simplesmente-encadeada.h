#ifndef _LISTA_SIMPLESMENTE_ENCADEADA_H_
#define _LISTA_SIMPLESMENTE_ENCADEADA_H_

#include<iostream>

template<typename T>
class Node
{
private:
    T m_valor; 
    Node* m_proximo;
    
public:
    Node(void);    
    Node(T val);
    Node(T val, Node* prox);
    T getValor(void);
    Node* getProximo(void);
    void setProximo (Node* prox);
};

template<typename T>
Node<T>::Node(void): 
	m_proximo(NULL) {}

template<typename T>
Node<T>::Node(T val): 
	m_valor(val), m_proximo(NULL) {}

template<typename T>
Node<T>::Node(T val, Node* prox): 
	m_valor(val), m_proximo(prox) {}

template<typename T>
T Node<T>::getValor(void)
{ 
	return this->m_valor; 
}

template<typename T>
Node<T>* Node<T>::getProximo(void)
{ 
	return this->m_proximo; 
}

template<typename T>
void Node<T>::setProximo(Node<T>* prox)
{ 
	this->m_proximo = prox; 
}

template<typename TDADO>
class ListaSimplesmenteEncadeada
{
private:
    Node<TDADO>* m_inicio; 
    int m_totalElementos;  
public:
    ListaSimplesmenteEncadeada(void);
    ListaSimplesmenteEncadeada(TDADO val);
    ~ListaSimplesmenteEncadeada(void);

    void InserirNoInicio(TDADO val);
    void InserirNoFinal(TDADO val);
    void InserirNaPosicao(TDADO val, int i);
    TDADO RemoverDaPosicao(int i);
    TDADO RemoverDoInicio(void);
	TDADO RemoverDoFinal(void);
	bool Vazia(void);
	int GetTamanho();
	void Listar();
};

template<typename TDADO>
ListaSimplesmenteEncadeada<TDADO>::ListaSimplesmenteEncadeada()
{
    this->m_inicio = NULL;
    this->m_totalElementos = 0;
}

template<typename TDADO>
ListaSimplesmenteEncadeada<TDADO>::ListaSimplesmenteEncadeada(TDADO val)
{
    this->m_inicio = new Node<TDADO>(val);
    this->m_totalElementos++;
}

template<typename TDADO>
ListaSimplesmenteEncadeada<TDADO>::~ListaSimplesmenteEncadeada()
{
}

template<typename TDADO>
int ListaSimplesmenteEncadeada<TDADO>::GetTamanho(void)
{
	return this->m_totalElementos;
}

template<typename TDADO>
void ListaSimplesmenteEncadeada<TDADO>::InserirNoInicio(TDADO val)
{
	Node<TDADO>* novo = new Node<TDADO>(val);
	
	if( !Vazia() )
	{
		novo->setProximo( this->m_inicio );
	}
	
	this->m_inicio = novo;
	
	this->m_totalElementos++;
}

template<typename TDADO>
void ListaSimplesmenteEncadeada<TDADO>::InserirNoFinal(TDADO val)
{
	if( Vazia() )
	{
		InserirNoInicio(val);
	}
	
	Node<TDADO>* novo = new Node<TDADO>(val);
	
	Node<TDADO> *p = this->m_inicio;
	while (p->getProximo() != NULL) {
        p = p->getProximo();
    }
    p->setProximo(novo);

	this->m_totalElementos++;
}

template<typename TDADO>
void ListaSimplesmenteEncadeada<TDADO>::InserirNaPosicao(TDADO val, int i)
{
	if( (i < 1) || (i > m_totalElementos) ) /* Posicao fora dos limites */
	{
		std::cout << "Posicao fora dos limites!" << std::endl;
	} 
	else 
	{
		Node<TDADO>* novo = new Node<TDADO>(val);
		
		Node<TDADO> *p = this->m_inicio;
		int pos = 1;
		while (p->getProximo() != NULL && pos < i-1) {
	        p = p->getProximo();
	        pos++;
	    }
	    novo->setProximo(p->getProximo());
	    p->setProximo(novo);

		this->m_totalElementos++;
	}
}


template<typename TDADO>
TDADO ListaSimplesmenteEncadeada<TDADO>::RemoverDaPosicao(int i)
{
	/* A lista eh vazia? */
    if ( Vazia() ) {
        std::cout << "A lista esta vazia." << std::endl;
        return 0;
    } 
    else if( (i < 1) || (i > m_totalElementos) ) /* Posicao fora dos limites */
	{
		std::cout << "Posicao fora dos limites!" << std::endl;
		return 0;
	} 
	else if( !Vazia() && (i == 1) ) /* Excluir o primeiro elemento */
	{
		RemoverDoInicio();
	} else if( !Vazia() && (i == this->m_totalElementos) ) /* Excluir o ultimo elemento */
	{
		RemoverDoFinal();
	} 
	else /* Remover algum elemento no meio da lista */
	{
		Node<TDADO>* removido;
		
		Node<TDADO>* p = this->m_inicio;
		Node<TDADO>* anterior;
		int pos = 1;
		while (p->getProximo() != NULL && pos < i) {
			anterior = p;
	        p = p->getProximo();
	        pos++;
	    }
	    removido = p;
	    anterior->setProximo(removido->getProximo());
	    
	    TDADO res = removido->getValor();
		delete removido;
		this->m_totalElementos--;
		return res;
	}
}

template<typename TDADO>
TDADO ListaSimplesmenteEncadeada<TDADO>::RemoverDoInicio(void)
{
	/* A lista eh vazia? */
    if ( Vazia() ) {
        std::cout << "A lista esta vazia." << std::endl;
        return 0;
    }

	Node<TDADO> *removido = this->m_inicio;
	this->m_inicio = removido->getProximo();
	TDADO res = removido->getValor();
	delete removido;
	this->m_totalElementos--;
	return res;
}

template<typename TDADO>
TDADO ListaSimplesmenteEncadeada<TDADO>::RemoverDoFinal(void)
{
	/* A lista eh vazia? */
    if ( Vazia() ) {
        std::cout << "A lista esta vazia." << std::endl;
        return 0;
    }

	Node<TDADO> *p = this->m_inicio;
	Node<TDADO>* anterior;
	while (p->getProximo() != NULL) {
		anterior = p;
        p = p->getProximo();
    }
    
    anterior->setProximo(NULL);
    
    TDADO res = p->getValor();
	delete p;
	this->m_totalElementos--;
	return res;
}

template<typename TDADO>
bool ListaSimplesmenteEncadeada<TDADO>::Vazia(void)
{
	return (this->m_inicio == NULL);
}

template<typename TDADO>
void ListaSimplesmenteEncadeada<TDADO>::Listar()
{
    Node<TDADO> *p = this->m_inicio;
    
    /* A lista eh vazia? */
    if ( Vazia() ) {
        std::cout << "A lista esta vazia." << std::endl;
        return;
    }
    
    std::cout << "Elementos: ";
    while (p != NULL) {
        std::cout << p->getValor() << "\t";
        p = p->getProximo();
    }
    std::cout << std::endl;
}

#endif // _LISTA_SIMPLESMENTE_ENCADEADA_H_