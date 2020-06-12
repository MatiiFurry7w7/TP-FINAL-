#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define ESC 27
#define FILECL "clientes.bin"
#define FILEALTA "clientesALTA.bin"
#define FILEBAJA "clientesBAJA.bin"

typedef struct	//cliente
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

typedef struct	//consumo
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
void mostrarCliente(stCliente c);
void muestraClientes();
stCliente copiaCliente(int dni);


/// USAR ///
stCliente cargarCliente();
stCliente cargarModificado(stCliente c);
stCliente copiarClienteDelArchivo(int id);
int devolverIdXDNI(int dni);
int buscapos(int id);
int nuevoId();
void guardarNuevoCliente(stCliente c);
void modificaCliente(stCliente c);
void menuDarDeBaja ();
void modificarDatosCliente(int dni);

void ordenarClientesBaja(stCliente c[], int v);	/// seleccion
int posMenorEmail(stCliente c[], int v, int pos);
void listarClientesEnBaja();
int copiarBajas2Arr(stCliente c[], int v);

///

int main()
{

    stCliente cliente;
    int dni;

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
                    menuDarDeBaja();
                    printf("\n\n\n");
                    system("pause");
                    break;
                case 51: /// opcion 3
                    printf("\t\t\t\t<<<<---MODIFICACION DE CLIENTES--->>>");
                    printf("\n\nIngrese DNI del usuario a Modificar: ");
                    scanf("%d", &dni);
                    system("cls");
                    modificarDatosCliente(dni);
                    printf("\n\n\n");
                    system("pause");
                    break;

                case 52: /// opcion 4
                    printf("\t\t\t\t<<<<---LISTAR CLIENTES ACTIVOS--->>>");
                    muestraClientes();
                    printf("\n\n\n");
                    system("pause");
                    break;
                case 53: /// opcion 5
                    printf("\t\t\t\t<<<<---LISTAR CLIENTES INACTIVOS POR E-MAIL--->>>");
                    listarClientesEnBaja();
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
    printf("\t-----------------\n\n\n");
    printf("\t[1] - CLIENTES.\n\n");
    printf("\t[2] - CONSUMOS.\n\n");
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
    int dniingresado;
    int valid;

    int valem;

    printf("\nDNI: ");
    scanf("%d", &dniingresado);
    valid = validaExistencia(dniingresado);

/// Si validaExistencia retorna -1 el DNI esta repetido y corta el ciclo, si no es -1, este retorna un DNI valido y continua ///

    if(valid != -1)
    {

        c.dni = valid;

        c.id = nuevoId(); /// Incrementa el ID ///

        printf("\nNombre: ");
        fflush(stdin);
        gets(c.nombre);

        printf("\nApellido: ");
        fflush(stdin);
        gets(c.apellido);

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
    else /// El ID retornara -1 en caso de ser repetido el DNI y no se cargara ///
    {
        c.id = -1;
        return c;
    }
}

void mostrarCliente(stCliente c)
{
    printf("\nID..........:[%d]",c.id);
    printf("\n\nNOMBRE......:%s\n",c.nombre);
    printf("APELLIDO....:%s\n",c.apellido);
    printf("DNI.........:%d\n",c.dni);
    printf("EMAIL.......:%s\n",c.email);
    printf("DOMICILIO...:%s\n",c.domicilio);
    printf("CELULAR.....:%d\n",c.movil);
    printf("BAJA........:%s\n",(c.baja)? "SI":"NO");
    puts("-----------------------------------");


}

void muestraClientes()
{
    stCliente c;
    int flag = 0;
    FILE *pArchCliente = fopen(FILECL,"rb");
    if (pArchCliente)
    {
        while (fread(&c,sizeof(stCliente),1,pArchCliente) > 0)
        {
            if (c.baja == 0)
            {
                mostrarCliente(c);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("\n\n\n No hay clientes ACTIVOS en el REGISTRO!\n");
        }
        fclose(pArchCliente);
    }

}

void guardarCliente(stCliente c)
{
    FILE *pArchCliente = fopen(FILECL, "ab");
    if(pArchCliente)
    {
        if(c.id != -1) /// Si recibe un ID = -1, no se cargara al archivo ///
        {
            fwrite(&c, sizeof(stCliente), 1, pArchCliente);
            fclose(pArchCliente);
        }
    }

}

int cantRegistros()
{
    stCliente c;
    int cont=0;

    FILE *pArchCliente = fopen(FILECL, "rb");
    if(pArchCliente)
    {
        fseek(pArchCliente, 0, SEEK_END);
        cont = ftell(pArchCliente)/sizeof(stCliente);
        fclose(pArchCliente);
    }

    return cont;
}

int devolverIdXDNI(int dni)
{
    stCliente c;
    FILE *pArchCliente = fopen(FILECL,"rb");
    int flag = -1;

    if (pArchCliente)
    {
        while (flag == -1 && fread(&c,sizeof(stCliente),1,pArchCliente) > 0)
        {
            if (c.dni == dni)
            {
                flag = c.id;
            }
        }
        fclose(pArchCliente);
    }

    return flag;
}

stCliente copiarClienteDelArchivo(int id)
{
    stCliente c;
    FILE *pArchCliente=fopen(FILECL,"rb");

    if (pArchCliente)
    {
        fseek(pArchCliente,sizeof(pArchCliente)*id,SEEK_SET);

        fread(&c,sizeof(stCliente),1,pArchCliente);

        fclose(pArchCliente);
    }

    return c;
}

stCliente copiaCliente(int dni)
{
    stCliente c;
    int flag = 0;
    FILE *pArchCliente=fopen(FILECL,"rb");

    if (pArchCliente)
    {
        while (flag == 0 && fread(&c,sizeof(stCliente),1,pArchCliente) > 0)
        {
            if (c.dni == dni)
            {
                flag = 1;
            }
        }

        fclose(pArchCliente);
    }

    return c;
}

void modificaCliente(stCliente c)
{
    stCliente aux;
    int flag = 0;

    FILE *pArchCliente = fopen(FILECL,"r+b");
    if (pArchCliente)
    {
        while(flag == 0 && fread(&aux, sizeof(stCliente), 1, pArchCliente) > 0)
        {
            if(c.id == aux.id)
            {
                fseek(pArchCliente, -sizeof(stCliente), SEEK_CUR);
                fwrite(&c,sizeof(stCliente),1,pArchCliente);
                flag=1;
            }
        }
        fclose(pArchCliente);
    }
}

int buscapos(int id)
{
    int pos = -1;
    stCliente c;
    FILE *pArchClientes = fopen(FILECL,"rb");
    if (pArchClientes)
    {
        while (pos == -1 && fread(&c,sizeof(stCliente),1,pArchClientes) > 0)
        {
            if (c.id == id)
            {
                pos = ftell(pArchClientes)/sizeof(stCliente);
            }
        }
        fclose(pArchClientes);
    }

    return pos;
}

void guardarNuevoCliente(stCliente c)
{
    FILE *pArchCliente = fopen(FILECL, "ab");

    if(pArchCliente)
    {
        c.id=nuevoId();
        fwrite(&c, sizeof(stCliente), 1, pArchCliente);
    }
    fclose(pArchCliente);
}

void menuDarDeBaja()
{
    stCliente c;
    char opcion = 's';
    int dni,pos,id;

    printf("\n\nIngrese DNI de la linea a dar de baja: ");
    fflush(stdin);
    scanf("%d",&dni);
    c=copiaCliente(dni);

    if (c.dni == dni)
    {
        if(c.baja == 1)
        {
            printf("\n\nDicho DNI ya se encuentra dado de BAJA");
        }
        else
        {
            mostrarCliente(c);

            printf("\nDesea dar de baja?\n");
            fflush(stdin);
            opcion = getch();

            if (opcion == 's')
            {
                c.baja = 1;
                modificaCliente(c);
                system("cls");
                printf("\n\nCLIENTE MODIFICADO!\n");
            }
        }

    }
    else
    {
        printf("\n\nNo existe el DNI solicitado!");
    }

}

int nuevoId()
{
    int maxID;
    stCliente c;
    FILE *pArchCliente= fopen(FILECL,"rb");

    if(fread(&c,sizeof(stCliente),1,pArchCliente)>0)
    {
        maxID=c.id;
    }
    else
    {
        maxID=-1;
    }

    while (fread(&c,sizeof(stCliente),1,pArchCliente) > 0)
    {
        if (c.id > maxID)
        {
            maxID=c.id;
        }
    }

    return maxID+1;
}

void modificarDatosCliente(int dni)
{
    stCliente c;

    int flag = 0;
    FILE *pArchCliente = fopen(FILECL,"rb");
    if (pArchCliente)
    {
        while (flag == 0 &&fread(&c,sizeof(stCliente),1,pArchCliente) > 0)
        {
            if (c.dni == dni)
            {
                c = cargarModificado(c);
                modificaCliente(c);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("\n\nNo se encontro el DNI ingresado!");
        }
        fclose(pArchCliente);
    }

}

stCliente cargarModificado(stCliente c)
{
    stCliente m;
    int dniingresado;
    int valid;
    int valem;
    char op;

    do
    {
        op = 'n';
        printf("\nUsuario a Modificar: \n");
        mostrarCliente(c);

        printf("\nIngrese Nuevo DNI: ");
        scanf("%d", &dniingresado);
        valid = validaExistencia(dniingresado);

        if(valid == -1 && dniingresado != c.dni)
        {
            c.id = -1;
            return m;
        }

        if(dniingresado == c.dni)
        {
            printf("\nSe modificara el DNI: [%d]", c.dni);
            printf("\n\nContinuar? s/n");
            op = getch();
        }
        else
        {
            op = 's';
        }

        if(op == 's')
        {
            system("cls");

            m.dni = dniingresado;
            printf("\nNuevo DNI ingresado: [%d]", m.dni);

            m.id = c.id;

            printf("\n\nNombre: ");
            fflush(stdin);
            gets(m.nombre);

            printf("\nApellido: ");
            fflush(stdin);
            gets(m.apellido);

            printf("\nEmail: ");
            fflush(stdin);
            gets(m.email);
            valem = validaEmail(m.email);

            while(!valem)
            {
                system("cls");
                printf("\nERROR: Email invalido, ingrese nuevamente: ");
                fflush(stdin);
                gets(m.email);
                valem = validaEmail(m.email);
            }

            printf("\nDomicilio: ");
            fflush(stdin);
            gets(m.domicilio);

            printf("\nT. Celular: ");
            scanf("%d", &m.movil);

            printf("\nEstado de BAJA actual: %d", c.baja);
            printf("\n\nModificar BAJA 1/0: ");
            scanf("%d", &m.baja);

            while(m.baja < 0 || m.baja > 1)
            {
                system("cls");
                printf("\nModificar BAJA 1/0: ");
                scanf("%d", &m.baja);
            }

            return m;
        }
    }
    while(op == 's');

    if(op=='n')
    {
        system("cls");
        printf("\nUsted eligio no continuar");
        c.id = -1;
        return m;
    }
}

// VALIDACIONES ///

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
    char opcion='s';

    FILE *pArchCliente = fopen(FILECL, "rb");
    if(pArchCliente)
    {
        while(fread(&c, sizeof(stCliente), 1, pArchCliente) > 0)
        {
            if(dni == c.dni)
            {
                system("cls");
                printf("\nEse DNI ya existe en la base de datos!\n");

                return -1;
            }
        }
        fclose(pArchCliente);
    }

    return dni;
}

int copiarBajas2Arr(stCliente c[],int v)
{
    FILE *pArch=fopen(FILECL,"rb");
    stCliente aux;

    if (pArch)
    {
        while (fread(&aux,sizeof(stCliente),1,pArch) > 0)
        {
            if (aux.baja == 1)
            {
                c[v]=aux;
                v++;
            }
        }
        fclose(pArch);
    }

    return v;
}

int posMenorEmail(stCliente c[], int v, int pos) /// BUSCAR MENOR ///
{
    int i=pos;
    int posMenor=i;
    char minEmail[30];

    strcpy(minEmail, c[i].email);

    i++;

    while(i<v)
    {
        if (strcmp(c[i].email, minEmail) < 0)
        {
            strcpy(minEmail, c[i].email);
            posMenor=i;
        }
        i++;
    }

    return posMenor;
}

void listarClientesEnBaja()              ///LISTAR BAJA ///
{
    stCliente c[30];
    int v=0, i=0;

    v=copiarBajas2Arr(c, v);

    ordenarClientesBaja(c, v);

    printf("Clientes ordenados por E-mail: \n");

    while(i<v)
    {
        mostrarCliente(c[i]);
        i++;
    }
}

void ordenarClientesBaja(stCliente c[], int v)	/// seleccion
{
    int i, posMenor;
    stCliente aux;

    while(i<v)
    {
        posMenor=posMenorEmail(c,v,i);
        aux=c[i];
        c[i]=c[posMenor];
        c[posMenor]=aux;
        i++;
    }
}

/*
void archi2pila (Pila *p)
{
    stCliente c;
    FILE *pArchiCliente = fopen(FILECL,"rb");
    if (pArchiCliente)
    {
        while (fread(&c,sizeof(stCliente),1,pArchiCliente) > 0)
        {
            if (c.baja == 0)
            {
                apilar(p,c.dni);
            }
        }
        fclose(pArchiCliente);
    }
}
*/

/*void archi2archi () /// ESTA FUNCION CREA 2 ARCHIVOS APARTE DEL YA CARGADO CON CLIENTES. SI EL CLIENTE ESTA EN ALTA LO PASA A -ALTA- , SINO LO PASA A
                    /// -BAJA-. NOS AHORRAMOS LA FUNCION DE MOSTRAR SI ESTA EN BAJA O NO PORQUE SOBREESCRIBIRIA EL ARCHIVO ESTA MISMA FUNCION.
{
    stCliente c;
    FILE *pArchiCliente     = fopen(FILECL,"rb");
    FILE *pArchiClienteAlta = fopen(FILEALTA,"ab");
    FILE *pArchiClienteBaja = fopen(FILEBAJA,"ab");
    if (pArchiCliente && pArchiClienteAlta && pArchiClienteBaja)
    {
        while (fread(&c,sizeof(stCliente),1,pArchiCliente) > 0)
        {
            if (c.baja == 1)
            {
                fwrite(&c,sizeof(stCliente),1,pArchiClienteBaja);

            }
            else
            {
                fwrite(&c,sizeof(stCliente),1,pArchiClienteAlta);

            }
        }
        fclose(pArchiCliente);
        fclose(pArchiClienteAlta);
        fclose(pArchiClienteBaja);
    }

}
*/
