class Libro
{
    std::string ISBN;
    std::string titulo;
    int year;
    std::string resumen;
    std::string editorial;
    Lista<Autor> autores;
    public:
        void setISBN(std::string s);
        std::string getISBN();
        void setTitulo(std::string s);
        std::string getTitulo();
        void setYear(int y);
        int getYear();
        void setResumen(std::string s);
        std::string getResumen();
        void setEditorial(std::string s);
        std::string getEditorial();
        void setAutores();
        Lista<Autor> getAutores();
        void show();
};

void Libro::setISBN(std::string newISBN)
{
    ISBN = newISBN;
}
std::string Libro::getISBN()
{
    return ISBN;
}

void Libro::setTitulo(std::string newTitulo)
{
    titulo = newTitulo;
}
std::string Libro::getTitulo()
{
    return titulo;
}

void Libro::setYear(int newYear)
{
    year = newYear;
}
int Libro::getYear()
{
    return year;
}

void Libro::setResumen(std::string newResumen)
{
    resumen = newResumen;
}
std::string Libro::getResumen()
{
    return resumen;
}

void Libro::setEditorial(std::string newEditorial)
{
    editorial = newEditorial;
}
std::string Libro::getEditorial()
{
    return editorial;
}

void Libro::setAutores()
{
    Autor new_autor;
    int cantidadDeAutores;
    
    std::cout<< "Ingrese la cantidad de Autores que tiene el libro:  ";
    std::cin>> cantidadDeAutores;
    std::string Nombres;
    std::cin.ignore();
    for (int k = 0; k  < cantidadDeAutores ;k++)
    {
        std::cout<< "Ingrese los nombres y apellidos del Autor No "<< k + 1<< ": ";
        
        std::getline(std::cin, Nombres);
        new_autor.setNombresCompletos(Nombres);
        autores.insertar(new_autor);
    }
}
Lista<Autor> Libro::getAutores()
{
    return autores;
}
void Libro::show()
{
    std::cout<< "--------------------------------------------"<< std::endl;
    std::cout<< "//  ISBN: "<< ISBN<< std::endl;
    std::cout<< "//  Titulo: "<< titulo<< std::endl;
    std::cout<< "//  Anio: "<< year<< std::endl;
    std::cout<< "//  Resumen: "<< resumen<< std::endl;
    std::cout<< "//  Editorial: "<< editorial<<std::endl;
    std::cout<< "//  Autores: "<<std::endl;
    autores.print();
    std::cout<< "--------------------------------------------"<< std::endl;

}
