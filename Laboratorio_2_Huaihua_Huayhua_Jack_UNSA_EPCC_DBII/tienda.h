class Tienda
{
    Lista<Libro> libros;
    public:
        Tienda();
        void agregarLibro();           
        void borrarLibro();            
        void buscarLibroPorISBN();     
        void buscarLibroPorTitulo();   
        void buscarLibrosPorAutor();   
        void mostrarTodosLosLibros();  
        void Ejecutar();
        ~Tienda();
};

Tienda::Tienda()
{
    std::cout<< "//////////////////////////////////////////////////"<< std::endl;
    std::cout<< "////////// Bienvenido a nuestra Tienda ///////////"<< std::endl;;
    std::cout<< "//////////////////////////////////////////////////"<< std::endl;
}

void Tienda::agregarLibro()
{
    std::cout<< "--------------------------------------------"<< std::endl;
    Libro libro;
    std::string ISBN;
    std::string titulo;
    int year;
    std::string resumen;
    std::string editorial;

    std::cout<< "//  Ingrese el ISBN: ";
    std::cin>> ISBN;
    std::cout<< "//  Ingrese el titulo: ";
    std::cin.ignore();
    std::getline(std::cin, titulo);
    std::cout<< "//  Ingrese el anio: ";
    std::cin>> year;
    std::cout<< "//  Ingrese el resumen: ";
    std::cin.ignore();
    std::getline(std::cin, resumen);
    std::cout<< "//  Ingrese el editorial: ";
    std::getline(std::cin, editorial);
        
    libro.setISBN(ISBN);
    libro.setTitulo(titulo);
    libro.setYear(year);
    libro.setResumen(resumen);
    libro.setEditorial(editorial);
    libro.setAutores();
    libros.insertar(libro);
    std::cout<< "********************************************"<< std::endl;
    std::cout<< "***** Libro Registrado Exitosamente ********"<< std::endl;
    std::cout<< "********************************************"<< std::endl;
}

void Tienda::buscarLibroPorISBN()
{
    std::string ISBN;
    std::cout<< "//  Ingrese el ISBN: ";
    std::cin>> ISBN;

   	Nodo<Libro> * temp = libros.getHead();
  	while(temp != nullptr)
   	{
	    if (temp->getElem().getISBN() == ISBN)
	    {
            temp->getElem().show();
   			return;
	    }
	    temp = temp->getNext();
    }

    std::cout<< "********************************************"<< std::endl;
    std::cout<< "********* Libro No Encontrado **************"<< std::endl;
    std::cout<< "********************************************"<< std::endl;
    
    
    
}

void Tienda::borrarLibro()
{
    std::string ISBN;
    std::cout<< "//  Ingrese el ISBN: ";
    std::cin>> ISBN;

    Nodo<Libro> *temp = libros.getHead();
    int contador = 0;
  	while(temp != nullptr)
   	{
	    if (!libros.estaVacio())
	    {
   			if (temp->getElem().getISBN() == ISBN)
            {
                libros.remover(contador);
                std::cout<< "********************************************"<< std::endl;
                std::cout<< "****** Libro Eliminado Exitosamente ********"<< std::endl;
                std::cout<< "********************************************"<< std::endl;
                return;
            }
            contador++;
        }
        else
        {
                std::cout<< "********************************************"<< std::endl;
                std::cout<< "*********** Libro NO Eliminado *************"<< std::endl;
                std::cout<< "******** porque no se ha encontrado ********"<< std::endl;
                std::cout<< "********************************************"<< std::endl;
	    }
	    temp = temp->getNext();
        
    }

    if (temp == nullptr)
    {
        std::cout<< "********************************************"<< std::endl;
        std::cout<< "*********** Libro NO Eliminado *************"<< std::endl;
        std::cout<< "******** porque no se ha encontrado ********"<< std::endl;
        std::cout<< "********************************************"<< std::endl;
    }
}

void Tienda::buscarLibroPorTitulo()
{
    std::string titulo;
    std::cout<< "//  Ingrese el Titulo: ";
    std::cin.ignore();
    std::getline(std::cin, titulo);
    
    Nodo<Libro> * temp = libros.getHead();
  	while(temp != nullptr)
   	{
	    if (temp->getElem().getTitulo() == titulo)
	    {
            temp->getElem().show();
   			return;
	    }
	    temp = temp->getNext();
    }

    std::cout<< "********************************************"<< std::endl;
    std::cout<< "*********** Libro No Encontrado ************"<< std::endl;
    std::cout<< "********************************************"<< std::endl;
}


void Tienda::buscarLibrosPorAutor()
{
    std::string nombresCompletos;
    std::cout<< "//  Ingrese los nombres: ";
    std::cin.ignore();
    std::getline(std::cin, nombresCompletos);

    int contador = 0;
    Nodo<Libro> * temp = libros.getHead();
  	while(temp != nullptr)
   	{
        Nodo<Autor> * temp2 = temp->getElem().getAutores().getHead();
        while(temp2 != nullptr)
   	    {
            if (temp2->getElem().show() == nombresCompletos)
            {
                contador++;
                std::cout<< "Libro No " << contador<< ": "<< std::endl;
                temp->getElem().show();
                break;
            }
            temp2 = temp2->getNext();
	    }
	    temp = temp->getNext();
    }

    if (contador == 0)
    {
        std::cout<< "********************************************"<< std::endl;
        std::cout<< "*********** Libro No Encontrado ************"<< std::endl;
        std::cout<< "********************************************"<< std::endl;
    }
}


void Tienda::mostrarTodosLosLibros()
{
    std::cout<< "********************************************"<< std::endl;
    std::cout<< "************* Lista de Libros **************"<< std::endl;
    std::cout<< "********************************************"<< std::endl;
    int contador = 0;

    Nodo<Libro> * temp = libros.getHead();
    while(temp != nullptr)
   	{
        temp->getElem().show();
	    temp = temp->getNext();
        contador++;
    }

    if (contador == 0)
    {
        std::cout<< "-------------    Lista  Vacia     -----------"<< std::endl;
        std::cout<< std::endl;
    }
}

void Tienda::Ejecutar()
{
    int opcion = 0;
    while( opcion != 10)
    {
        std::cout<< "1-Agregar Libro            2-Borrar Libro"<< std::endl;
        std::cout<< "3-Buscar Libro por ISBN    4-Buscar Libro por Titulo"<< std::endl;
        std::cout<< "5-Buscar Libro por Autor   6-Mostrar todos los Libros           10-Salir"<< std::endl;
        std::cin>> opcion;

        switch (opcion)
        {
            case 1: agregarLibro();
                break;
            case 2: borrarLibro();
                break;
            case 3: buscarLibroPorISBN();
                break;
            case 4: buscarLibroPorTitulo();
                break;
            case 5: buscarLibrosPorAutor();
                break;
            case 6: mostrarTodosLosLibros();
                break;
            case 10: break;
        
            default: std::cout<< "Ingrese una opcion valida"<< std::endl;
                break;
        }
    }
}

Tienda::~Tienda()
{
    std::cout<< "//////////////////////////////////////////////////"<< std::endl;
    std::cout<< "//////////////////// Hasta luego /////////////////"<< std::endl;;
    std::cout<< "//////////////////////////////////////////////////"<< std::endl;
}