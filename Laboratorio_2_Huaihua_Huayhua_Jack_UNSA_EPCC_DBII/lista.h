
template <class L>
class Lista
{
	int size;
	Nodo<L> *head;
		
	public:
		Lista();
		Lista(const Lista &copia);

		void insertar(const L valor);
		void remover(const int pos);
		int buscar(const L valor);
		bool estaVacio();
		Nodo<L>* getHead();

		void print();
				
		~Lista();
};

// CONSTRUCTORES ----------------------------------------------------------------------------

//Constructor por defecto
template <class L>
Lista<L>::Lista()
{
	head = nullptr;
	size = 0;
}

//Constructor copia
template <class L>
Lista<L>::Lista(const Lista &copia)
{
	size = copia.size;
	head  = copia.head;
}


//PRINT ----------------------------------------------------------------------------------------
template <class L>
void Lista<L>::print()
{
	//Se itera sobre todos los elementos y se imprimen sus datos miembro
	Nodo<L> *puntero = head;
	int k = 0;
	while(puntero)
    {
    	std::cout<< " No "<< k + 1<< ": "<< puntero->getElem().show()<< std::endl;
        puntero = puntero->getNext();
        k++;
    }
}

// INSERT -----------------------------------------------------------------------------------------
template <class L>
void Lista<L>::insertar(const L valor)
{
	Nodo<L> *new_Nodo = new Nodo<L>(valor);

	if (size == 0)
	{
		head = new_Nodo;
	}
	else
	{		
    	Nodo<L> *puntero = head;
    	while(puntero->getNext() != nullptr )
    	{
	       	puntero = puntero->getNext();
	   	}

	    puntero->setNext( new_Nodo);
	}
	
	size++;
}


// REMOVE --------------------------------------------------------------------------------------
template <class L>
void Lista<L>::remover(const int pos)
{
	int posicion = pos;
	
	if(posicion == 0 )
    {
        Nodo<L> *temp = head;
        head = head->getNext();
        delete temp;
    }
	else
	{
    	Nodo<L> *puntero = head;
    	while(puntero->getNext()!=nullptr && --posicion)
	       	puntero = puntero->getNext();

	    if(puntero->getNext()==nullptr && posicion > 0)  return;

	    Nodo<L> *temp = puntero->getNext();
    	puntero->setNext(temp->getNext());
		delete temp;
	}
	size--;
}

// SEARCH --------------------------------------------------------------------------------
template <class L>
int Lista<L>::buscar(const L valor)
{
	Nodo<L> * temp = head;
	int contador = 0;
	while(temp != nullptr)
	{
		if (temp->getElem() == valor)
		{
			return contador;
		}
		temp = temp->getNext();
		contador++;
	}
	return -1;
}

// EMPTY
template <class L>
bool Lista<L>::estaVacio()
{
	if (size == 0)
	{
		std::cout<< "Aun no se han llenado datos"<< std::endl;
		return true;
	}
	else
	{
		return false;
	}
	
}


// GETHEAD
template <class L>
Nodo<L> *Lista<L>::getHead()
{
	return head;
}


//Destructor -----------------------------------------------------------------------------
template <class L>
Lista<L>::~Lista()
{
	Nodo<L> *puntero = head;
	Nodo<L> *siguiente2 = nullptr;
	
	//Se libera la memoria asignada con new
	while(puntero != nullptr)
    {
        siguiente2 = puntero->getNext();
        delete puntero;
        puntero = siguiente2;
    }
}