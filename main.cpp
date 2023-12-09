#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <basicas.cpp>
#include <estructuras.cpp>

//datos precargados clientes
//datos precargados trabajadores
// limite

//const string nombreArchivoTra = "..\\trabajadores.txt";
const char limite = '_';

using namespace std;

//INICIALIZADORES DE LISTAS
void inicializarlT(listaEstudiante *LE){
    LE->cab = NULL;
    LE->nT  = 0;
}

void  inicializarlB(listaNotas *LN){
    LN->cab = NULL;
    LN->nN = 0;
}

void inicializarcC(colaClientes *cC){
    cC->adelante = NULL;
    cC->atras = NULL;
    cC->nCli = 0;
}

void inicializarlC(listaCliente *lC){
    lC->cab = NULL;
    lC->nC = 0;
}

void inicializarlV(listaVentas *lV){
    lV->cab = NULL;
    lV->nV = 0;
}

void inicializargZ(grafoCurso *gC){
    gC->nodoZ = NULL;
    gC->aristaZ = NULL;

    zona *info = new zona;
    info->lB = new listaNotas;
    inicializarlB(info->lB);

    info->cC = new colaClientes;
    inicializarcC(info->cC);

    info->lC = new listaCliente;
    inicializarlC(info->lC);
}

void inicializar(circo *c){
    c->info = new informacion;
    c->info->nombre = "Universidad Señor De Sipan";
    c->info->telefono = "950805378";
    c->info->ruc = "20479748102";
    c->info->email = "USS@gmail.com";
    c->info->web = "http://www.uss.edu.pe/";

    c->gC = new grafoCurso;
    inicializargZ(c->gC);

    c->LE = new listaEstudiante;
    inicializarlT(c->LE);

    c->lV = new listaVentas;
    inicializarlV(c->lV);
}
//INICIALIZADORES DE LISTAS

//informacion circo
void mostrarCirco( informacion *inf  ){
    system("cls");
    gotoxy(30, 3 ) ; cout << "NOMBRE       : " << inf->nombre;
    gotoxy(30, 4 ) ; cout << "TELEFONO     : " << inf->telefono;
    gotoxy(30, 5 ) ; cout << "RUC          : " << inf->ruc;
    gotoxy(30, 6 ) ; cout << "EMAIL        : " << inf->email;
    gotoxy(30, 7 ) ; cout << "WEB          : " << inf->web;
    Sleep(3000);
}
//informacion circo




/*------------------------ CURSOS---------------------*/
void inicializarNodoEstudiante(nodoEstudinate *nZ){
    nZ->adyacente = NULL;
    nZ->sgte = NULL;
    nZ->info = new zona;

    nZ->info->lB = new listaNotas;
    inicializarlB(nZ->info->lB);

    nZ->info->cC = new colaClientes;
    inicializarcC(nZ->info->cC);

    nZ->info->lC = new listaCliente;
    inicializarlC(nZ->info->lC);
}

void leerCurso(nodoEstudinate *nuevo){
    system ("cls");
    gotoxy(35,3);cout<<"CURSOS ";
    gotoxy(35,4); nuevo->info->nomZona =leerTexto(" INGRESE EL CURSO : ");
}

void insertarCurso(grafoCurso *gC, nodoEstudinate *nuevo){
    nodoEstudinate *aux= new nodoEstudinate;
    inicializarNodoEstudiante(aux);
    if(gC->nodoZ == NULL){
        gC->nodoZ=nuevo;
    }
    else{
        aux=gC->nodoZ;
                while(aux->sgte!=NULL){
                aux=aux->sgte;
    }
     aux->sgte=nuevo;
    }
    //gotoxy(35,8); cout << "ZONA REGISTRADA";
    //Sleep(2000);
}

//GUARDAR CURSOS

void registrarCurso(grafoCurso *gC){
    nodoEstudinate *nuevo = new nodoEstudinate;
    inicializarNodoEstudiante(nuevo);
    leerCurso(nuevo);
    insertarCurso(gC, nuevo);
    //guardarZona( nuevo );
}

void insertarArista( nodoEstudinate *aux1, nodoEstudinate *aux2, arista *nuevo){

    arista *temp = new arista;
    if ( aux1->adyacente == NULL ){
        aux1->adyacente = nuevo;
        nuevo->destino = aux2;
    }
    else{
        temp = aux1->adyacente;
        while( temp->sgte != NULL ){
            temp = temp->sgte;
        }
        nuevo->destino = aux2;
        temp->sgte = nuevo;
    }


}

void registrarConexion( grafoCurso *gC ){
    system("cls");
    arista *nuevo = new arista;
    string Facultad1, ciudadDestino;
    nodoEstudinate *aux1, *aux2;

    if ( gC->nodoZ == NULL ){
        system("cls");
        gotoxy(20,20);cout<<"NO HAY CURSOS";
        Sleep(3000);
        return;
    }
    nuevo->sgte = NULL;
    gotoxy(20,19); Facultad1 =  leerTexto("INGRESE EL CURSO: ");
    gotoxy(20,21); ciudadDestino = leerTexto("INGRESE EL CURSO A UNIR: ");

    aux1 = aux2 = gC->nodoZ;

    while( aux2 ){
        if( aux2->info->nomZona == ciudadDestino ){
            break;
        }
        aux2 = aux2->sgte;

    }
    while( aux1 ){
        if( aux1->info->nomZona == Facultad1 ){
            insertarArista(aux1, aux2, nuevo);
            return;
        }
        aux1 = aux1->sgte;
    }
}

void mostrarConexiones(grafoCurso *gC ){
    system("cls");
    nodoEstudinate *aux = new nodoEstudinate;
    arista *temp = new arista;
    aux = gC->nodoZ;

    if ( gC->nodoZ == NULL ){
        gotoxy(20,30);cout<<"NO HAY CURSOS";
        Sleep(3000);
        return;
    }
    int x = 0;
    int y;
    while( aux != NULL ){
        y = 0;
        gotoxy(22, 19 + x ); cout << aux->info->nomZona;

        if ( aux->adyacente != NULL ){
            temp = aux->adyacente;
            while( temp ){
                gotoxy(44 + y, 19 + x ); cout << temp->destino->info->nomZona;
                y += 15;
                temp = temp->sgte;
            }
        }
        aux = aux->sgte;
        x++;
    }
}

void listarCurso(grafoCurso *gC){
    system("cls");
    nodoEstudinate *aux = new nodoEstudinate;
    aux = gC->nodoZ;
    int x = 0;
    if (aux == NULL){
        gotoxy (20, 6); cout << "NO HAY CURSOS";
    }
    else{
        gotoxy(20, 5 ); cout << "LISTA DE CURSOS";

    while (aux != NULL ) {
        gotoxy(20, 6 + x ); cout << x + 1 << ". " << aux->info->nomZona;
        x++;
        aux = aux->sgte;
    }
    }

    Sleep(2500);
}

void buscarCurso(grafoCurso *gC){
    system ("cls");
        nodoEstudinate *aux = new nodoEstudinate;
        aux = gC->nodoZ;
        bool band=false;
        if( aux == NULL){
             gotoxy(40,5);cout << "NO HAY CURSOS ";
        }else{
            string datobuscar;
             gotoxy(40,5);datobuscar = leerTexto( "INGRESE LOS CURSOS: ");
            while (aux != NULL){
                if(aux->info->nomZona == datobuscar){
                    system("cls");
                      gotoxy(40, 5);cout<< "NOMBRE DEL CURSO   : ";cout <<aux->info->nomZona;
                      band = true;
                    break;
                }
                aux = aux->sgte;
            }
            if(band==false){
            gotoxy(40, 7); cout<<"NO SE ENCONTRO EL CURSO";
            }
        }
    Sleep( 2500 );
}

void Facultad(grafoCurso *gC){
    int opc;
        do{
            opc = menuZonas();
            switch (opc ) {
                case 1: registrarCurso(gC);break;
                case 2: registrarConexion( gC );break;
                case 3: mostrarConexiones(gC);break;
                case 4: listarCurso(gC);break;
                case 5: buscarCurso(gC);break;
            }
        }while(!( opc == 6  ));
 }

nodoEstudinate *elegirCurso( grafoCurso *gC ){
    system("cls");
    nodoEstudinate *aux = new nodoEstudinate;
    aux = gC->nodoZ;
    int x = 0;
    int opc;
    gotoxy(2, 1 ); cout << "LISTA DE CURSOS";
    while (aux != NULL ) {
        gotoxy(2, 2 + x ); cout << x + 1 << ". " << aux->info->nomZona;
        x++;
        aux = aux->sgte;
    }
    do{
        gotoxy(2,30 ); cout << "\n\tELIJA CURSO: ";
    cin >> opc;
    }while(!( opc > 0 && opc <= x  ));
    aux = gC->nodoZ;
    x = 0;
   while( x < opc - 1 ){
        aux = aux->sgte;
        x++;
    }
    return aux;
}
//CURSOS

//TRABAJADORES
nodoEstudiante *elegirEstudiante(listaEstudiante *LE){
    system("cls");
    nodoEstudiante *aux = new nodoEstudiante;
    aux = LE->cab;
    int x = 0;
    int opc;
    gotoxy(2, 1 ); cout << "LISTA DE ESTUDIANTES";
    while (aux != NULL ) {
        gotoxy(2, 2 + x ); cout << x + 1 << ". " << aux->tra->nombres;
        x++;
        aux = aux->sgte;
    }
    do{
        gotoxy(2,30 + x ); cout << "ELIGA ESTUDIANTE: ";
     cin >> opc;
    }while(!( opc > 0 && opc <= LE->nT));
    aux = LE->cab;
    x = 0;
   while( x < opc - 1 ){
        aux = aux->sgte;
        x++;
    }
    return aux;
}

void inicializarTrabajador( trabajador *tra ){
    tra->edad = 0;
    /*tra->telefono2  = 0;
    /*tra->genero = 1;*/
}

void leerTrabajador( trabajador *tra ){
    system("cls");
    gotoxy(35, 4 ); cout << "=====================================";
    gotoxy(35, 5 ); cout << "          AGREGAR ESTUDIANTE";
    gotoxy(35, 6 ); cout << "=====================================";
    gotoxy(35, 7 ); tra->nombres   = leerTexto("Ingrese Nombres  : ");
    gotoxy(35, 8 ); tra->apellidos = leerTexto("Ingrese Apellidos: ");
    gotoxy(35, 9 ); tra->edad       = leerEdad("Ingrese Edad     : ");
    gotoxy(35, 10); tra->dni       = leerTexto("Ingrese DNI      : ");
    gotoxy(35, 11); tra->codUSS    = leercodUSS("Ingrese Cod USS : ");
    gotoxy(35, 12); tra->telefono2   = leertelefono2("Ingrese Telefono   : ");
}

void insertarTrabajador( listaEstudiante *LE, trabajador *tra ){
    nodoEstudiante *aux = new nodoEstudiante;
    nodoEstudiante *temp = new nodoEstudiante;
    temp->tra = tra;
    temp->sgte = NULL;
    aux = LE->cab;
    if ( LE->cab == NULL ){
        temp->sgte = aux;
        temp->anterior = NULL;
        LE->cab = temp;
    }else{
        while( aux->sgte != NULL ){
            aux = aux->sgte;
        }
        temp->sgte = aux->sgte;
        temp->anterior = aux;
        aux->sgte = temp;
    }
    LE->nT++;
}


/*------------------------guardar ESTUDIANTE---------------------*/

void registrarTrabajador( listaEstudiante *LE){
    trabajador *tra = new trabajador;
    inicializarTrabajador( tra );
    leerTrabajador( tra );
    insertarTrabajador( LE, tra );
    //guardar estudiante (tra)
}

void mostrarTrabajadorLista(trabajador *trab, int x){
    gotoxy(20,x);cout << trab->nombres;
    gotoxy(32,x);cout << trab->apellidos;
    gotoxy(44,x);cout << trab->edad;
    gotoxy(56,x);cout << trab->dni;
    gotoxy(68,x);cout << trab->codUSS;
    /*gotoxy(72,x);cout << trab->genero;*/
    gotoxy(80,x);cout << trab->telefono2 ;
}

void listarTrabajador( listaEstudiante *LE  ){
    system("cls");
   nodoEstudiante *aux = new nodoEstudiante;
    int x = 6;
    aux = LE->cab;
    if ( aux == NULL ){
        gotoxy(45, 5); cout << "NO HAY TRABAJADORES REGISTRADOS";
    }
    else{
        encabezadoTrabajadores();
        while (aux != NULL ) {
            mostrarTrabajadorLista(aux->tra, x);
            x++;
            aux = aux->sgte;
        }
    }
    Sleep( 2000 );
}

void mostrarTrabajadorBuscar( trabajador *tra){
    gotoxy(40, 5 ); cout << tra->nombres;
    gotoxy(40, 6 ); cout << tra->apellidos;
    gotoxy(40, 7 ); cout << tra->edad;
    gotoxy(40, 8 ); cout << tra->dni;
    gotoxy(40, 9 ); cout << tra->codUSS;
    /*gotoxy(40, 10 ); cout << tra->genero;*/
    gotoxy(40, 11 ); cout << tra->telefono2 ;
}

void buscarTrabajador( listaEstudiante *LE  ){
    system("cls");
    nodoEstudiante *aux = new nodoEstudiante;
    bool band=false;
    aux = LE->cab;
    if ( aux == NULL ){
        gotoxy(45, 5); cout << "NO HAY ESTUDIANTES REGISTRADOS";
    }
    else{
        string datoBuscar;
        gotoxy(40, 10 ); datoBuscar = leerTexto("Ingrese nombre del ESTUDIANTE que busca: ");
        while (aux != NULL ) {
            if ( aux->tra->nombres == datoBuscar ){
                system("cls");
                mostrarTrabajadorBuscar( aux->tra );
                band = true;
                break;
            }
            aux = aux->sgte;
        }
        if(band==false){
        gotoxy(40, 7); cout<<"NO SE ENCONTRO EL ESTUDIANTE";
        }
    }
    Sleep( 2000 );
}

void mTrabajador(listaEstudiante *LE){
    int opc;
        do{
           opc = menuTrabajadores();
           switch (opc ) {
               case 1: registrarTrabajador(LE);break;
               case 2: listarTrabajador(LE);break;
              case 3: buscarTrabajador(LE);break;
           }
      }while(!( opc == 4  ));

}
nodoCliente *elegirClientes(listaCliente *lC){
    system("cls");
    nodoCliente *aux = new nodoCliente;
    aux = lC->cab;
    int x = 0;
    int opc;
    gotoxy(2, 1 ); cout << "LISTA DE DOCENTES";
    while (aux != NULL ) {
        gotoxy(2, 2 + x ); cout << x + 1 << ". " << aux->cli->nombres<<" , "<<aux->cli->apellidos;
        x++;
        aux = aux->sgte;
    }
    do{
        gotoxy(2, 30 + x ); cout << "ELIGA DOCENTE: ";
        cin >> opc;
    }while(!( opc > 0 && opc <= lC->nC));
    aux = lC->cab;
    x = 0;
   while( x < opc - 1 ){
        aux = aux->sgte;
        x++;
    }
    return aux;
}

void inicializarCliente(cliente *cli){
    cli->edad = 0;
}

void leerCliente(cliente *cli){
    gotoxy(35,6);cli->nombres = leerTexto("Ingrese Nombres: ");
    gotoxy(35,7);cli->apellidos = leerTexto("Ingrese Apelllidos: ");
    gotoxy(35,8);cli->dni = leerTexto("Ingrese DNI: ");
    gotoxy(35,9);cli->edad = leerEdad("Ingrese Edad: ");
    gotoxy(35,10);cli->correo = leerTexto("Ingrese Correo: ");
}

void encolar(colaClientes *cC, cliente *cli){
    nodoColaClientes *aux = new nodoColaClientes;
    aux->info = cli;
    aux->sgte = NULL;
    if ( cC->adelante == NULL ){
        cC->adelante = aux;
    }
    else{
        cC->atras->sgte = aux;
    }
    cC->atras = aux;
    cC->nCli++;
}
void registrarColaCliente(colaClientes *cC){
    system("cls");
    cliente *cli = new cliente;
    inicializarCliente( cli );
    leerCliente( cli );
    encolar( cC, cli);
}

void desencolar(colaClientes *cC){
    cliente *clie;
    nodoColaClientes *aux= new nodoColaClientes;
    aux = cC->adelante;
    clie = aux->info;
    cC->adelante = cC->adelante->sgte;
    cC->nCli--;
    delete aux;
}

void mostrarCola(colaClientes *cC){
    gotoxy(20, 5);cout << "Nombre      : "<<cC->adelante->info->nombres;
    gotoxy(20, 6);cout << "Apellidos   : "<<cC->adelante->info->apellidos;
    gotoxy(20, 7);cout << "DNI         : "<<cC->adelante->info->dni;
    gotoxy(20, 8);cout << "Edad        : "<<cC->adelante->info->edad;
    gotoxy(20, 9);cout << "Genero      : "<<cC->adelante->info->genero;
    gotoxy(20, 10);cout <<"Correo      : "<<cC->adelante->info->correo;
}
//COLA CLIENTES

//CLIENTES
void insetarClientes(listaCliente *lC, cliente *cli){
    nodoCliente *aux = new nodoCliente;
    nodoCliente *temp = new nodoCliente;
    temp->cli = cli;
    temp->sgte = NULL;
    aux = lC->cab;
    if ( aux == NULL ){
        temp->sgte = aux;
        temp->sgte = NULL;
        lC->cab = temp;
    }
    else{
        while( aux->sgte != NULL ){
            aux = aux->sgte;
        }
        temp->sgte = aux->sgte;
        aux->sgte = temp;
    }
    lC->nC++;
}

void EvaluarClientes(colaClientes *cC,listaCliente *lC){
    system("cls");
    string rpta;
    if(cC->nCli == 0){
        gotoxy(40,5);cout << "NO HAY DOCENTE ENCOLADOS";
        Sleep(2500);
        return;
    }
    mostrarCola(cC);
    do{
        gotoxy(40,13);cout << "S = ACEPTAR || N = NO ACEPTAR";
        gotoxy(40,14);cout << "¿SE APRUEBA DOCENTE?: ";
        fflush(stdin);
        getline (cin,rpta);
    }while (!(rpta == "S" || rpta == "N"));
    if(rpta == "S"){
        insetarClientes(lC, cC->adelante->info);
    }desencolar(cC);
    Sleep(2000);
}

void asignarButaca (listaNotas *LN, listaCliente *lC){
    nodoCliente *temp =new nodoCliente;
    nodoNotas *temp1= new nodoNotas;
    if ( LN->cab == NULL ){
        system("cls");
        gotoxy(22, 15); cout << "NO HAY DOCENTES REGISTRADOS";
        Sleep(2000);
        return;
    }
    temp = elegirClientes(lC);
   /* temp1 = elegirDocente (LN );*/
    temp->cli->butc = temp1->Not;
    system("cls");
    gotoxy( 20, 15); cout << "DOCENTE ASIGNADO" ;
    Sleep(2000);
}

void registrarClientesLista(grafoCurso *gC){
    system("cls");
    nodoEstudinate *aux = new nodoEstudinate;
    aux = gC->nodoZ;
    if (aux == NULL ){
        gotoxy( 35, 10); cout << "NO HAY CURSOS REGISTRADOS";
        Sleep( 2000 );
        return;
    }
    aux = elegirCurso(gC);// se elige curso
    registrarColaCliente(aux->info->cC); //se encola al docente en el curso
     EvaluarClientes(aux->info->cC,aux->info->lC);//evaluacion de cola e insercion en listaCliente
}

void mostrarClientes( cliente *cli){
    system("cls");
    gotoxy(40, 5);cout << "Nombre      : "<<cli->nombres;
    gotoxy(40, 6);cout << "Apellidos   : "<<cli->apellidos;
    gotoxy(40, 7);cout << "DNI         : "<<cli->dni;
    gotoxy(40, 8);cout << "Edad        : "<<cli->edad;
    gotoxy(40, 9);cout << "Genero      : "<<cli->genero;
    gotoxy(40, 10);cout <<"Correo      : "<<cli->correo;
    gotoxy(40, 11);cout <<"Butaca      : "<<cli->butc->Docente;
}

void buscarCliente(listaCliente *lC){
    system("cls");
    nodoCliente *aux= new nodoCliente;
    aux = lC->cab;
    bool band=false;
    if( aux== NULL){
        gotoxy(45,5); cout<< "NO HAY DOCENTES REGISTRADAS";
    }
    else{
        string datobuscar;
        gotoxy(45, 5); datobuscar = leerTexto("Ingrese DNI a buscar: ");
        while(aux !=NULL){
            if( aux->cli->dni == datobuscar){
                mostrarClientes(aux->cli);
                band = true;
                break;
            }
            aux =aux->sgte;
        }
        if(band==false){
            gotoxy(40, 11); cout<<"No se encontro el Docente";
        }
    }
    Sleep(2000);

}

void buscarClientes(grafoCurso *gC){
    nodoEstudinate *aux = new nodoEstudinate;
    if (aux == NULL ){
        gotoxy( 35, 10); cout << "NO HAY CURSOS REGISTRADOS";
        Sleep( 2000);
        return;
    }
   aux = elegirCurso(gC);
   buscarCliente(aux->info->lC);
}

void registrarClientesButacas(grafoCurso *gC){
    system ("cls");
    nodoEstudinate *aux = new nodoEstudinate;
    aux = gC->nodoZ;
    if (aux == NULL ){
        gotoxy( 35, 10); cout << "NO HAY CURSOS REGISTRADAS";
        Sleep( 2000);
        return;
    }
    aux = elegirCurso(gC);// se elige zona
    asignarButaca (aux->info->lB, aux->info->lC);
}

void mCliente(grafoCurso *gC){
    int opc;
        do{
            opc = menuClientes();
            switch (opc ) {
                case 1: registrarClientesLista(gC);break;
                case 2: registrarClientesButacas(gC);break;
                case 3: buscarClientes(gC);break;
                case 4: break;
            }
        }while(!( opc == 4  ));
     ;

 }



