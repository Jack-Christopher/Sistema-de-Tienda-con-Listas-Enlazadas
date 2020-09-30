class Autor
{
    std::string nombresCompletos;
    public:
        void setNombresCompletos(std::string nombres_y_apellidos);
        std::string show();
};

void Autor::setNombresCompletos(std::string nombres_y_apellidos)
{
    nombresCompletos = nombres_y_apellidos;
}

std::string Autor::show()
{
    return nombresCompletos;
}