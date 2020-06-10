#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define ESC 27
#define fileCL "clientes.bin"

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
} stCliente;

typedef struct
{
    int id;              /// AUTOINCREMENTAL UNICO
    int idCliente;
    int anio;
    int mes;             /// 1 - 12
    int dia;             /// 1 - … (DEPENDE DEL MES)
    int datosConsumidos; /// MBs.
    int baja;            /// 0 = ACTIVO / 1 = INACTIVO
} stConsumos;

///Prototipados

void menu();
void subcli();
void subcon();

int validaEmail (char email[]);
int cantRegistros();
int validaExistencia(int dni);
void guardarCliente(stCliente c);

stCliente cargarCliente();

int main()
{

stCliente cliente;

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

                    guardarCliente(cargarCliente());

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

/// MENU ///

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

/// FUNCIONES ///

stCliente cargarCliente()
{
    stCliente c;

    int valem;

    c.id = cantRegistros();

    printf("\nNombre: ");
    fflush(stdin);
    gets(c.nombre);

    printf("\nApellido: ");
    fflush(stdin);
    gets(c.apellido);

    printf("\nDNI: ");
    scanf("%d", &c.dni);

    c.dni = validaExistencia(c.dni);

    printf("\nEmail: ");
    fflush(stdin);
    gets(c.email);
    valem = validaEmail(c.email);

    while(!valem)
    {
        system("cls");
        printf("\nERROR: Email invalido, ingrese nuevamente: ");
        fflush(stdin);
        gets(c.email);
        valem = validaEmail(c.email);

    }

    printf("\nDomicilio: ");
    fflush(stdin);
    gets(c.domicilio);

    printf("\nT. Celular: ");
    scanf("%d", &c.movil);

    c.baja = 0;

    return c;
}

void guardarCliente(stCliente c)
{
  FILE *pArchCliente = fopen(fileCL, "ab");
  if(pArchCliente)
  {
   fwrite(&c, sizeof(stCliente), 1, pArchCliente);
  }
  fclose(pArchCliente);
}

int cantRegistros()
{
 stCliente c;
 int cont=0;

 FILE *pArchCliente = fopen(fileCL, "rb");
 if(pArchCliente)
 {
   fseek(pArchCliente, 0, SEEK_END);
   cont = ftell(pArchCliente)/sizeof(stCliente);
  fclose(pArchCliente);
 }

return cont;
}

/// VALIDACIONES ///

int validaEmail(char email[])
{

    int validos = strlen(email);
    int i=0;
    int flag = 0;

    while (i<validos && flag == 0)
    {
        if (email[i] == 64)
        {
            flag = 1;
        }
        i++;
    }
    return flag;
}

int validaExistencia(int dni)
{
 stCliente c;

 FILE *pArchCliente = fopen(fileCL, "rb");

 if(pArchCliente)
 {
 while(dni == c.dni)
 {
  while(fread(&c, sizeof(stCliente), 1, pArchCliente) > 0)
   {
    system("cls");
    printf("\nEse DNI ya existe en la base de datos, ingrese otro: ");
    scanf("%d", &dni);
   }
  }
  fclose(pArchCliente);
 }

return dni;
}




























