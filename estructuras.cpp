#include <iostream>
using namespace std;

//informacion
struct trabajador{
    string nombres;
    string apellidos;
    unsigned short edad;
    string dni;
    string codUSS;
    string telefono2 ;
};

struct butacas{
    string Docente;
    string correo1;
    string correo2;
};

struct cliente{
    string nombres;
    string apellidos;
    int edad;
    string dni;
    string correo;
    string genero;
    butacas *butc;
};
//informacion

//ventas
struct venta{
    string codigo;
    string fecha;
    float venta;
    trabajador *tra;
    cliente *clie;
};

struct nodoVenta{
    venta *ven;
    nodoVenta *sgte;
    nodoVenta *anterior;
};

struct listaVentas{
    unsigned short nV;
    nodoVenta *cab;
};
//ventas

//clientes acpetados
struct nodoCliente{
    cliente *cli;
    nodoCliente *sgte;
    nodoCliente *anterior;
};

struct listaCliente{
    unsigned short nC;
    nodoCliente *cab;
};
//clientes aceptados

//colaClientes
struct nodoColaClientes{
    cliente *info;
    nodoColaClientes *sgte;
};

struct colaClientes{
    nodoColaClientes *adelante;
    nodoColaClientes *atras;
    int nCli;
};
//colaClientes

//butacas
struct nodoNotas{
    butacas *Not;
    nodoNotas *sgte;
    nodoNotas *anterior;
};

struct listaNotas{
    int nN;
    nodoNotas *cab;
};
//butacas

//trabajadores
struct nodoEstudiante{
    trabajador *tra;
    nodoEstudiante *sgte;
    nodoEstudiante *anterior;
};

struct listaEstudiante{
    unsigned short nT;
    nodoEstudiante *cab;
};
//trabajadores

//grafos
struct zona{
    string nomZona;
    listaNotas *lB;
    colaClientes *cC;
    listaCliente *lC;
};

struct nodoEstudinate{
    zona *info;
    nodoEstudinate *sgte;
    struct arista *adyacente;
};

struct arista{
    nodoEstudinate *destino; //duda
    arista *sgte;//duda
};

struct grafoCurso{
    nodoEstudinate *nodoZ;
    arista *aristaZ;
};
//grafos

//principal
struct informacion{
    string nombre;
    string telefono;
    string email;
    string web;
    string ruc;
};

struct circo{
    informacion *info;
    grafoCurso *gC;
    listaEstudiante *LE;
    listaVentas *lV;
};
//principal


