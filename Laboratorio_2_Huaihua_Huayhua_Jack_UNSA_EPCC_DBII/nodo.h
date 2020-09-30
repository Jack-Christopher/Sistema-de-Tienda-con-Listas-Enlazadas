
template <class N>
class Nodo
{
	N elem;
	Nodo *next;
		
	public:
			
		Nodo(); 
		Nodo(N elem);
		N getElem() const;
		void setElem(const N elemento);
		Nodo *getNext() const;
		void setNext(Nodo *n);
		
};

template <class N>
Nodo<N>::Nodo()
{
	elem = nullptr;
	next = nullptr;
}


template <class N>
Nodo<N>::Nodo(N elemento)
{
	elem = elemento;
	next = nullptr;
}

template <class N>
N Nodo<N>::getElem() const
{
	return elem;
}

template <class N>
void Nodo<N>::setElem(const N elemento) 
{
	elem = elemento;
}

template <class N>
Nodo<N>* Nodo<N>::getNext() const
{
	return next;
}

template <class N>
void Nodo<N>::setNext(Nodo *n)
{
	next = n;
}