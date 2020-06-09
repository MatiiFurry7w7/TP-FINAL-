#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define ESC 27

typedef struct
{
int id; /// AUTOINCREMENTAL UNICO
char nombre[30];
char apellido[30];
int dni;
char email[30];
char domicilio[45];
int movil;
int baja;
}stCliente;

typedef struct
{
int id;              /// AUTOINCREMENTAL UNICO
int idCliente;
int anio;
int mes;             /// 1 - 12
int dia;             /// 1 - … (DEPENDE DEL MES)
int datosConsumidos; /// MBs.
int baja;            /// 0 = ACTIVO / 1 = INACTIVO
}stConsumos;

///Prototipados

void menu();
void subcli();
void subcon();

int main()
{

///Menu
    char opcion;
    system("color d");

    do
    {
        system("cls");
        menu();
        opcion = getch();
        system("cls");

        switch (opcion)
        {
        case 49: ///                                     SUBMENU CLIENTES

            printf("\t\t\t\t<<<<---SUBMENU CLIENTES--->>>");

            do
            {
                system("cls");
                subcli();
                opcion = getch();
                system("cls");

                switch (opcion)
                {
                case 49: /// opcion 1
                    printf("\t\t\t\t<<<<---ALTA DE CLIENTES--->>>");

                    printf("\n\n\n");
                    system("pause");
                    break;

                case 50: /// opcion 2
                    printf("\t\t\t\t<<<<---BAJA DE CLIENTES--->>>");

                    printf("\n\n\n");
                    system("pause");
                    break;
                case 51: /// opcion 3
                    printf("\t\t\t\t<<<<---MODIFICACION DE CLIENTES--->>>");

                    printf("\n\n\n");
                    system("pause");
                    break;

                case 52: /// opcion 4
                    printf("\t\t\t\t<<<<---LISTAR CLIENTES ACTIVOS--->>>");

                    printf("\n\n\n");
                    system("pause");
                    break;
                case 53: /// opcion 5
                    printf("\t\t\t\t<<<<---LISTAR CLIENTES INACTIVOS--->>>");

                    printf("\n\n\n");
                    system("pause");
                    break;
                }

            }
            while (opcion!='6');
            break;

        case 50: /// opcion 2                             SUBMENU CONSUMOS

            printf("\t\t\t\t<<<<---SUBMENU CONSUMOS--->>>");
            do
            {
                system("cls");
                subcon();
                opcion = getch();
                system("cls");

                switch (opcion)
                {
                case 49: /// opcion 1
                    printf("\t\t\t\t<<<<---ALTA DE CONSUMOS--->>>");

                    printf("\n\n\n");
                    system("pause");
                    break;

                case 50: /// opcion 2
                    printf("\t\t\t\t<<<<---BAJA DE CONSUMOS--->>>");

                    printf("\n\n\n");
                    system("pause");
                    break;

                case 51: /// opcion 3
                    printf("\t\t\t\t<<<<---MODIFICACION DEL CONSUMO--->>>");

                    printf("\n\n\n");
                    system("pause");
                    break;

                case 52: /// opcion 4
                    printf("\t\t\t\t<<<<---LISTADO DE CONSUMOS--->>>");

                    printf("\n\n\n");
                    system("pause");
                    break;
                case 53: /// opcion 5
                    printf("\t\t\t\t<<<<---ESTADISTICAS DE LOS CONSUMOS--->>>");

                    printf("\n\n\n");
                    system("pause");
                    break;
                }

            }
            while (opcion!='6');
            break;
        }

    }
    while (opcion!=ESC);

    system("cls");
    system("color a");
    printf("\n\n\n\n\n\n\n\t\t\t<<<<---GRACIAS POR ELEGIR UT MOVIL, ESPERAMOS VERLO/A PRONTO!--->>>\n\n\n\n\n\n\n\n\n\n\n");
      puts("\n\n\n\n\t------------------------------------------------------------------------------------------------------\n");
    printf("\tCOMICOS CUBICOS. TM - 2020");
    getch();
    system("cls");

    return 0;
}


void menu()
{
    printf("\n\n\t\t\t\t<<<<---UT Movil - MAIN MENU--->>>\n\n\n\n");
    printf("\tSelect an option.\n");
    printf("\t-----------------\n\n");
    printf("\t[1] - SUBMENU CLIENTES.\n\n");
    printf("\t[2] - SUBMENU CONSUMOS.\n\n");
      puts("\n\n\n\t------------------------------------------------------------------------------\n");
    printf("\tCOMICOS CUBICOS. TM - 2020");
    printf("\t\t\t\t\t[ESC] TO QUIT.");
}

void subcli()
{
    printf("\n\n\t\t\t\t<<<<---UT Movil - SUBMENU CLIENTES--->>>\n\n\n\n");
    printf("\tSelect an option.\n");
    printf("\t-----------------\n\n");
    printf("\t[1] - ALTA DE CLIENTES.\n");
    printf("\t[2] - BAJA DE CLIENTES.\n");
    printf("\t[3] - MODIFICACION DE CLIENTES.\n");
    printf("\t[4] - LISTAR CLIENTES ACTIVOS.\n");
    printf("\t[5] - LISTAR CLIENTES INACTIVOS.\n");
      puts("\n\n\t------------------------------------------------------------------------------\n");
    printf("\tCOMICOS CUBICOS. TM - 2020");
    printf("\t\t\t      [6] RETURN TO MAIN MENU.");
}

void subcon()
{
    printf("\n\n\t\t\t\t<<<<---UT Movil - SUBMENU CONSUMOS--->>>\n\n\n\n");
    printf("\tSelect an option.\n");
    printf("\t-----------------\n\n");
    printf("\t[1] - ALTA DE CONSUMO.\n");
    printf("\t[2] - BAJA DE CONSUMO.\n");
    printf("\t[3] - MODIFICACION DE CONSUMO.\n");
    printf("\t[4] - LISTADO DE CONSUMOS.\n");
    printf("\t[5] - ESTADISTICAS DE LOS CONSUMOS.\n");
      puts("\n\n\t------------------------------------------------------------------------------\n");
    printf("\tCOMICOS CUBICOS. TM - 2020");
    printf("\t\t\t      [6] RETURN TO MAIN MENU.");
}



