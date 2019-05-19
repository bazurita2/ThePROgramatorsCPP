#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct contacto
    {
        char nombre[20];
        int telefono;
        char ciudad[20];
    };

typedef struct contacto Contacto;

 void meterContactosNuevos()
    {

    Contacto primero, segundo, tercero;

    printf ("\n\nIntroduce los datos del primer contacto (nombre telefono ciudad): \n");
    scanf ("%s %d %s", &primero.nombre, &primero.telefono, &primero.ciudad);
    printf ("\nSegundo contacto:\n");
    scanf ("%s %d %s", &segundo.nombre, &segundo.telefono, &segundo.ciudad);
    printf ("\nTercer contacto: \n");
    scanf ("%s %d %s", &tercero.nombre, &tercero.telefono, &tercero.ciudad);

    printf ("\nLos nuevos contactos son: \n");
    printf ("\nNOMBRE\t\tTELEFONO\t\tCIUDAD");
    printf ("\n%s\t\t%d\t\t%s", primero.nombre, primero.telefono, primero.ciudad);
    printf ("\n%s\t\t%d\t\t%s", segundo.nombre, segundo.telefono, segundo.ciudad);
    printf ("\n%s\t\t%d\t\t%s", tercero.nombre, tercero.telefono, tercero.ciudad);

    printf ("\n\nEstos datos se han almacenado en el nuevo fichero contactos.txt. \n(Revisa tu carpeta). \n\n");

    FILE *pf;

    pf=fopen ("contactos.txt", "w+");

    fprintf (pf, "\t\tAGENDA DE CONTACTOS\n");
    fprintf (pf, "\nNOMBRE\t\tTELEFONO\t\tCIUDAD");
    fprintf (pf, "\n%s\t\t%d\t\t%s", primero.nombre, primero.telefono, primero.ciudad);
    fprintf (pf, "\n%s\t\t%d\t\t%s", segundo.nombre, segundo.telefono, segundo.ciudad);
    fprintf (pf, "\n%s\t\t%d\t\t%s", tercero.nombre, tercero.telefono, tercero.ciudad);

    fclose(pf);
    }

    void meterContactosMas ()
    {
        Contacto primero;

    printf ("\n\nIntroduce los datos del nuevo contacto (nombre telefono ciudad): \n");
    scanf ("%s %d %s", &primero.nombre, &primero.telefono, &primero.ciudad);

    printf ("\nEl nuevo contacto es: \n");
    printf ("\nNOMBRE\t\tTELEFONO\t\tCIUDAD");
    printf ("\n%s\t\t%d\t\t%s", primero.nombre, primero.telefono, primero.ciudad);

    printf ("\n\nEstos datos se han almacenado en tu fichero contactos.txt. \n(Compruebalo). \n\n");

    FILE *pf;

    pf=fopen ("contactos.txt", "r+");

    fseek (pf, 0, SEEK_END);

    fprintf (pf, "\n%s\t\t%d\t\t%s", primero.nombre, primero.telefono, primero.ciudad);
    fclose(pf);
    }

    void leerContactos ()
    {
        FILE *pf;
        char c;

        pf=fopen ("contactos.txt", "r");
        printf ("\n");
        while(feof(pf)==0)
        {
         c=getc(pf);
         putchar(c);
        }
        putchar('\n');
        fclose(pf);
        printf ("\n\n");
    }

     void borrarContacto ()
    {
        int l, linea, NUMlineas=0;
        char LINEA[MAX], c, ch;
        FILE *destino, *pf;
        printf ("\nTu lista de contactos es la siguiente: \n");
        leerContactos ();

        printf ("Introduce el numero de contacto que quieres borrar (linea): ");
        scanf ("%d", &l);

        linea=l+3;

        pf=fopen ("contactos.txt", "r+");
        destino=fopen ("contactos2.txt", "w+");

        /*Leemos todas las lineas del archivo*/
      while (fgets (LINEA, MAX, pf)!=NULL)
        {
            if ((ch=getc(pf))!= EOF)
            ungetc(ch, pf);
            NUMlineas++;
            if (NUMlineas!=linea)
            {
                fputs(LINEA, destino);
            }
        }

        printf ("\nEl contacto ha sido eliminado. Revise su archivo.\n");
        fclose(pf);
        fclose(destino);
        remove ("contactos.txt");
        rename ("contactos2.txt", "contactos.txt");

    }

    int main ()
    {
        int opcion;
        FILE *pf;

        pf=fopen ("contactos.txt", "r");

        printf ("\t\tBIENVENIDO A TU AGENDA DE CONTACTOS\n\n");
        printf ("1. Introducir nuevo contacto.\n2. Ver contactos.\n3. Borrar contacto.\n\nIndica la opcion que desees: ");
        scanf ("%d", &opcion);
        switch (opcion)
        {
            case 1:
                {if (pf==NULL)
                {
                fclose(pf);
                printf ("\nTu agenda de contactos esta vacia. Vamos a introducir tus 3 primeros contactos.\n");
                meterContactosNuevos();}
                else
                {
                fclose(pf);
                printf("\nTu agenda ya tiene algunos contactos. Vamos a introducir uno nuevo.\n");
                meterContactosMas();}}
            break;

            case 2:
                {if (pf==NULL)
                {
                fclose(pf);
                printf ("\nLo siento, tu agenda de contactos esta vacia.\n\n");
                }
                else
                {
                fclose(pf);
                leerContactos();}
                }
            break;

            case 3:
                {if (pf==NULL)
                {
                 fclose(pf);
                printf ("\nLo siento, tu agenda de contactos esta vacia.\n\n");
                }
                else
                {
                fclose(pf);
                borrarContacto();
                }
                }
            break;

            default:
            {fclose(pf);
                printf ("\nLa opcion seleccionada no es valida\n.");}
        }

        return 0;
    }
