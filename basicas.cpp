#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x,int y){
     HANDLE hcon;
     hcon = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD dwPos;
     dwPos.X = x;
     dwPos.Y= y;
     SetConsoleCursorPosition(hcon,dwPos);
}

// Función para cambiar el color del texto en Windows
void changeTextColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int menu(){
    int opc;
    do{
        system("cls");
    changeTextColor ( FOREGROUND_RED );
            system("cls");
        changeTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        gotoxy(50, 3 ); cout << "           _____                    _____                    _____               ";
        gotoxy(50, 4 ); cout << "          /\\    \\                  /\\    \\                  /\\    \\              ";
        gotoxy(50, 5 ); cout << "         /::\\____\\                /::\\    \\                /::\\    \\             ";
        gotoxy(50, 6 ); cout << "        /:::/    /               /::::\\    \\              /::::\\    \\            ";
        gotoxy(50, 7 ); cout << "       /:::/    /               /::::::\\    \\            /::::::\\    \\           ";
        gotoxy(50, 8 ); cout << "      /:::/    /               /:::/\\:::\\    \\          /:::/\\:::\\    \\          ";
        gotoxy(50, 9 ); cout << "     /:::/    /               /:::/__\\:::\\    \\        /:::/__\\:::\\    \\         ";
        gotoxy(50, 10); cout << "    /:::/    /                \\:::\\   \\:::\\    \\       \\:::\\   \\:::\\    \\        ";
        gotoxy(50, 11); cout << "   /:::/    /      _____    ___\\:::\\   \\:::\\    \\    ___\\:::\\   \\:::\\    \\           ";
        gotoxy(50, 12); cout << "  /:::/____/      /\\    \\  /\\   \\:::\\   \\:::\\    \\  /\\   \\:::\\   \\:::\\    \\      ";
        gotoxy(50, 13); cout << " |:::|    /      /::\\____\\/::\\   \\:::\\   \\:::\\____\\/::\\   \\:::\\   \\:::\\____\\     ";
        gotoxy(50, 14); cout << " |:::|____\\     /:::/    /\\:::\\   \\:::\\   \\::/    /\\:::\\   \\:::\\   \\::/    /        ";
        gotoxy(50, 15); cout << "  \\:::\\    \\   /:::/    /  \\:::\\   \\:::\\   \\/____/  \\:::\\   \\:::\\   \\/____/        ";
        gotoxy(50, 16); cout << "   \\:::\\    \\ /:::/    /    \\:::\\   \\:::\\    \\       \\:::\\   \\:::\\    \\            ";
        gotoxy(50, 17); cout << "    \\:::\\    /:::/    /      \\:::\\   \\:::\\____\\       \\:::\\   \\:::\\____\\            ";
        gotoxy(50, 18); cout << "     \\:::\\__/:::/    /        \\:::\\  /:::/    /        \\:::\\  /:::/    /                 ";
        gotoxy(50, 19); cout << "      \\::::::::/    /          \\:::\\/:::/    /          \\:::\\/:::/    /                   ";
        gotoxy(50, 20); cout << "       \\::::::/    /            \\::::::/    /            \\::::::/    /                      ";
        gotoxy(50, 21); cout << "        \\::::/    /              \\::::/    /              \\::::/    /                       ";
        gotoxy(50, 22); cout << "         \\::/    /                \\::/    /                \\::/    /                        ";
        gotoxy(50, 23); cout << "          \\/____/                  \\/____/                  \\/____/                         ";
        changeTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        gotoxy(50, 24); cout << "       _______________________________________________________________                         ";


    changeTextColor ( FOREGROUND_RED );
        gotoxy(5, 6); cout << "||====================================||";
        gotoxy(5, 7); cout << "||      MENU DE OPCIONES              ||";
        gotoxy(5, 8); cout << "||====================================||";
        gotoxy(5, 9); cout << "|| 1. Mostrar datos del la univesidad ||";
        gotoxy(5, 10); cout <<"|| 2. Control de Cursos               ||";
        gotoxy(5, 11); cout <<"|| 3. Control Estudiantes             ||";
        /*gotoxy(5, 12); cout <<"|| 4. Control Docentes                ||";*/
        gotoxy(5, 13); cout <<"|| 5. Control Docente               ||";
       /* gotoxy(5, 14); cout <<"|| 6. Control Ventas                  ||";*/
        gotoxy(5, 15); cout <<"|| 7. Salir                           ||";
        gotoxy(5, 16); cout <<"|| Elije una opcion:                  || ";
        gotoxy(5, 17); cout <<"||====================================||";
        gotoxy(5, 18); cout <<"->";
        cin >> opc;
    }while(!( opc > 0 && opc < 8 ));
    return opc;
}
int menuZonas(){
    int opc;
    do{
        system("cls");
    changeTextColor ( FOREGROUND_GREEN );
        gotoxy(45, 6); cout << "||==========================||";
        gotoxy(45, 7); cout << "||     MENU DE CURSOS   ||";
        gotoxy(45, 8); cout << "||==========================||";
        gotoxy(45, 9); cout << "|| 1. Registrar Curso       ||";
        gotoxy(45, 10); cout <<"|| 2. Unir Curso            ||";
        gotoxy(45, 11); cout <<"|| 4. Lista De Curso        ||";
        gotoxy(45, 12); cout <<"|| 5. Buscar Curso          ||";
        gotoxy(45, 13); cout <<"|| 6. Regresar              ||";
        gotoxy(45, 14); cout <<"|| Elije una opcion:        || ";
        gotoxy(45, 15); cout <<"||==========================||";
        gotoxy(45, 16); cout <<"->";
        cin >> opc;
    }while(!( opc > 0 && opc < 7 ));
    return opc;
}

int menuTrabajadores(){
    int opc;
    do{
        system("cls");
        changeTextColor ( FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        gotoxy(45, 6); cout << "||==========================||";
        gotoxy(45, 7); cout << "||   MENU DE ESTUDIANTES    ||";
        gotoxy(45, 8); cout << "||==========================||";
        gotoxy(45, 9); cout << "|| 1. Registrar Estudiante  ||";
        gotoxy(45, 10); cout <<"|| 2. Listar Estudiante     ||";
        gotoxy(45, 11); cout <<"|| 3. Buscar Estudiante     ||";
        gotoxy(45, 12); cout <<"|| 4. Regresar              ||";
        gotoxy(45, 13); cout <<"|| Elije una opcion:        || ";
        gotoxy(45, 14); cout <<"||==========================||";
        gotoxy(45, 15); cout <<"->";
        cin >> opc;
    }while(!( opc > 0 && opc < 5 ));
    return opc;
}

/* int menuButacas(){
    int opc;
    do{
        system("cls");
    changeTextColor ( FOREGROUND_GREEN | FOREGROUND_INTENSITY );
        gotoxy(45, 6); cout << "||==========================||";
        gotoxy(45, 7); cout << "||      MENU DE DOCENTES    ||";
        gotoxy(45, 8); cout << "||==========================||";
        gotoxy(45, 9); cout << "|| 1. Registrar Docente      ||";
        gotoxy(45, 10); cout <<"|| 2. Lista Docente          ||";
        gotoxy(45, 11); cout <<"|| 3. Buscar Docente        ||";
        gotoxy(45, 12); cout <<"|| 4. Regresar              ||";
        gotoxy(45, 13); cout <<"|| Elije una opcion:        || ";
        gotoxy(45, 14); cout <<"||==========================||";
        gotoxy(45, 15); cout <<"->";
        cin >> opc;
    }while(!( opc > 0 && opc < 5 ));
    return opc; */

int menuClientes(){
    int opc;
    do{
        system("cls");
    changeTextColor ( FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
        gotoxy(45, 6); cout << "||==========================||";
        gotoxy(45, 7); cout << "||     MENU DE DOCENTES     ||";
        gotoxy(45, 8); cout << "||==========================||";
        gotoxy(45, 9); cout << "|| 1. Registrar Docente     ||";
        gotoxy(45, 10); cout <<"|| 2. Asignar Docente       ||";
        gotoxy(45, 11); cout <<"|| 3. Buscar                ||";
        gotoxy(45, 12); cout <<"|| 4. Regresar              ||";
        gotoxy(45, 13); cout <<"|| Elije una opcion:        || ";
        gotoxy(45, 14); cout <<"||==========================||";
        gotoxy(45, 15); cout <<"->";
        cin >> opc;
    }while(!( opc > 0 && opc <5 ));
    return opc;
}/*
int menuVentas(){
    int opc;
    do{
        system("cls");
    changeTextColor ( FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        gotoxy(45, 6); cout << "||==========================||";
        gotoxy(45, 7); cout << "||      MENU DE VENTAS      ||";
        gotoxy(45, 8); cout << "||==========================||";
        gotoxy(45, 9); cout << "|| 1. Registrar Venta       ||";
        gotoxy(45, 10); cout <<"|| 2. Listar ventas         ||";
        gotoxy(45, 11); cout <<"|| 3. Listar ventas por dia ||";
        gotoxy(45, 12); cout <<"|| 4. Buscar venta          ||";
        gotoxy(45, 13); cout <<"|| 5. Regresar              || ";
        gotoxy(45, 14); cout <<"|| Elije una opcion:        || ";
        gotoxy(45, 15); cout <<"||==========================||";
        gotoxy(45, 16); cout <<"->";
        cin >> opc;
    }while(!( opc > 0 && opc < 6 ));
    return opc;
}
*/

string leerTexto(string mensaje){
    string valor;
    cout << mensaje;
    fflush( stdin );
    getline( cin, valor);
    return valor;
}


float leerEdad( string mensaje ){
    float valor;
    do{
        cout << mensaje;
        cin >> valor;
    }while(!( valor > 0 && valor<10000));
    return valor;
}

float leercorreo2(string mensaje ){
    float valor;
    do{
        cout << mensaje;
        cin >> valor;
    }while(!( valor > 0 && valor<10000));
    return valor;
}
/*
void leerGenero(string mensaje ){
    string valor;
    do{
        cout << mensaje;
        fflush( stdin );
        getline( cin, valor );
    }while(!( valor =="H" || valor == "M" ));
    if ( valor == "H" )

        return ;
}
*/
float leerPrecio( string mensaje ){
    float valor;
    do{
        cout << mensaje;
        cin >> valor;
    }while(!( valor > 0 && valor < 100000 ));
    return valor;
}
float leertelefono2( string mensaje ){
    float valor;
    do{
        cout << mensaje;
        cin >> valor;
    }while(!( valor > 0 && valor < 100000 ));
    return valor;
}
float leercodUSS( string mensaje ){
    int valor;
    do{
        cout << mensaje;
        cin >> valor;
    }while(!( valor > 0 && valor < 100000 ));
    return valor;
}

void encabezadoTrabajadores(){
    system ("cls");
    gotoxy(20,5); cout<<"Nombre";
    gotoxy(32,5); cout<<"Apellidos";
    gotoxy(44,5); cout<<"Edad";
    gotoxy(56,5); cout<<"DNI";
    gotoxy(68,5); cout<<"Cod USS";
    gotoxy(80,5); cout<<"Telefono";

}

void encabezadoVenta(){
    gotoxy(10,5);cout <<"Codigo";
    gotoxy(18,5);cout <<"Fecha";
    gotoxy(31,5);cout <<"Apellidos trabajador";
    gotoxy(55,5);cout <<"DNI trabajador";
    gotoxy(73,5);cout <<"Apellidos cliente";
    gotoxy(93,5);cout <<"DNI cliente";
    gotoxy(108,5);cout <<"Codigo butaca";
    gotoxy(123,5);cout <<"Precio butaca";
}

/*
void encabezadoVentaFecha(){
    gotoxy(10,5);cout <<"Codigo";
    gotoxy(18,5);cout <<"Apellidos trabajador";
    gotoxy(42,5);cout <<"DNI trabajador";
    gotoxy(60,5);cout <<"Apellidos cliente";
    gotoxy(80,5);cout <<"DNI cliente";
    gotoxy(95,5);cout <<"Codigo butaca";
    gotoxy(110,5);cout <<"Precio butaca";
}

void encabezadoButacas(){
    system ("cls");
    gotoxy(30,2); cout<<"Lista Docente";
    gotoxy(17,3); cout<<"Nombre";
    gotoxy(26,3); cout<<"Correo";

}

*/


