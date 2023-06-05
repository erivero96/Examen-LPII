#include <iostream>
#include <string>

using namespace std;

class Fecha {
    private:
        int hora;
        int minuto;
        int segundo;

    public:
        Fecha () { }
        Fecha(int h, int m, int s) : hora(h), minuto(m), segundo(s) {}

        friend std::ostream& operator<<(std::ostream& os, const Fecha& fecha) {
            os << "Hora: " << fecha.hora << ", Minuto: " << fecha.minuto << ", Segundo: " << fecha.segundo;
            return os;
        }

        friend std::istream& operator>>(std::istream& is, Fecha& fecha) {
            is >> fecha.hora >> fecha.minuto >> fecha.segundo;
            return is;
        }
};

//Persona normal

class Persona
{
    private:
        static int numPersonas;
    protected:
        int edad;
        string nombre;

    public:
        Persona() { }
        
        virtual void trabajar()
        {
            cout << nombre << " empezo a trabajar" << endl;
        }

        virtual void ingresar()
        {
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Edad: ";
            cin >> edad;
        }

        virtual void mostrar()
        {
            cout << "Nombre: " << nombre << endl;
            cout << "Edad: " << edad << endl;
        }

        static void personaNueva()
        {
            numPersonas += 1;
        }

        ~Persona() { }
};



//Persona Abstracta
/*
class Persona
{
    private:
        static int numPersonas;
    protected:
        int edad;
        string nombre;

    public:
        Persona() { }
        
        virtual void trabajar() = 0;
        virtual void ingresar() = 0;
        virtual void mostrar() = 0;
        virtual void cobrarIngresos() = 0;

        static void personaNueva()
        {
            numPersonas += 1;
        }
        
        friend class Docente; //declaracion de clase amiga Docente
        ~Persona() { }
};
*/
//Estudiante Normal
/*
class Estudiante : public Persona
{
    protected:
        int codigo;
        int yearOfBirth;
        string nombreApoderado;
        Fecha fechaMatricula;
        double &promedio;
        const int celular, dni;
    
    public:
        Estudiante(int nombre, int edad, int codigo, int yearOfBirth, string nombreApoderado, Fecha fechaMatricula, double &promedio, int celular_, int dni_) : celular(celular_), dni(dni_)
        {
            this->edad = edad;
            this->nombre = nombre;
            this->codigo = codigo;
            this->yearOfBirth = yearOfBirth;
            this->nombreApoderado = nombreApoderado;
            this->fechaMatricula = fechaMatricula;
            this->promedio = promedio;
        }
};
*/

//Estudiante Concreta
class Estudiante : public Persona
{
    protected:
        int codigo;
        int yearOfBirth;
        string nombreApoderado;
        Fecha fechaMatricula;
        double &promedio;
        const int dni,celular;


    public:
        Estudiante(string nombre, int edad, int codigo, int yearOfBirth, string nombreApoderado, Fecha fechaMatricula,
         double &promedio_, int celular_, int dni_) : celular(celular_), dni(dni_), promedio(promedio_)
        {
            this->nombre = nombre;
            this->edad = edad;
            this->codigo = codigo;
            this->yearOfBirth = yearOfBirth;
            this->nombreApoderado = nombreApoderado;
            this->fechaMatricula = fechaMatricula;
        }
        virtual void trabajar () 
        {
            cout <<"Estudiante "<< nombre << " empezo a trabajar" << endl;
        }

        void ingresar () 
        {
            cout << "Apoderado: ";
            cin >> nombreApoderado;
        }

        void mostrar () 
        {
            Persona::mostrar();
            cout<<"Promedio: "<<promedio<<endl;
        }

        void cobrarIngresos() { }

        friend void mostrarEstudiante(Estudiante& estu);
};

class Trabajador : public Persona
{
    private:
        int sueldo;
        int saldoCuenta;

    public:
        Trabajador(string nombre, int edad, int sueldo, int saldoCuenta)
        {
            this->nombre = nombre;
            this->edad = edad;
            this->sueldo = sueldo;
            this->saldoCuenta = saldoCuenta;
        }

        virtual void trabajar() 
        { 
            cout << "Trabajador " <<  nombre << " empezo a trabajar" << endl;
        }
         
        void ingresar() { 
            cout << "Ingrese el sueldo: ";
            cin >> sueldo;
        }

        void mostrar() { 
            Persona::mostrar();
            cout << "Sueldo: " << sueldo << endl;
            cout << "Saldo cuenta: "<< saldoCuenta << endl;
        }

        void cobrarIngresos()
        {
            saldoCuenta += sueldo;
            cout << nombre << "ha cobrado su sueldo de : " << sueldo;
        }
};
class Docente : public Persona
{
    protected:
        string respuesta;
    public:
        Docente(string n,string r, int e)
        {
            nombre = n;
            respuesta = r;
            edad = e;
        }
        void afiliar()
        {
            cout<<"Desea afiliarse? "<<endl;
                if(respuesta=="si" or respuesta == "SI")
                {
                    cout<<nombre<<" se ha afiliado"<<endl;
                }
                else
                {
                    cout<<nombre<<" no se ha afiliado"<<endl;
                }
        }
        virtual void trabajar() { 
            cout << "Docente " << nombre << " empezo a trabajar" <<endl;
        }

        void ingresar() { 
            cout << "Modificar respuesta: ";
            cin >> respuesta;
        }

        void mostrar() { 
            Persona::mostrar();
            cout << "Respuesta: " << respuesta << endl;
        }

        void cobrarIngresos() { 

        }
};
//funcion amiga
void mostrarEstudiante(Estudiante& estu)
{
    estu.mostrar(); //como arreglamos esta vaina xd
    cout<<"Datos del estudiante"<<endl;
    cout<<"Nombre: "<<estu.nombre<<endl;
    cout<<"Edad: "<<estu.edad<<endl;
    cout<<"Codigo: "<<estu.codigo<<endl;
    cout<<"Anno de nacimiento: "<<estu.yearOfBirth<<endl;
    cout<<"Nombre del apoderado: "<<estu.nombreApoderado<<endl;
    cout<<"Fecha de matricula: "<<estu.fechaMatricula<<endl;
}


int Persona::numPersonas = 0; //xd

int main()
{   
    Persona* personas[3];
    double promedioEstudiante = 85.5;  // Supongamos un valor de promedio para el estudiante
    Fecha fechaMatriculaEstudiante(2022, 9, 1);  // Supongamos una fecha de matrícula para el estudiante

    Persona* estudiante = new Estudiante("Juan", 18, 12345, 2005, "Pedro", fechaMatriculaEstudiante, promedioEstudiante, 987654321, 123456789);
    Persona* trabajador = new Trabajador("Julio",30,3, 2000);
    Persona* docente = new Docente("Mario","si",65);

    personas[0] = estudiante;
    personas[1] = trabajador;
    personas[2] = docente;

    Persona ** personasDinamico = new Persona*[3];

    personasDinamico[0] = estudiante;
    personasDinamico[1] = trabajador;
    personasDinamico[2] = docente;

    for (int i = 0; i < 3; i++)
    {
        personas[i]->trabajar();  
        personas[i]->mostrar();
        personas[i]->ingresar();
    }

    for (int i = 0; i < 2; i++)
    {
        personasDinamico[i]->trabajar();  
        personasDinamico[i]->mostrar();
        personasDinamico[i]->ingresar();
    }
}
