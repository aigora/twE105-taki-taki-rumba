#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
#define X 1000

typedef struct//la unidad del vector de alfabetos
{
	char unidad[26];
}alfabeto;

void code();

void copia (int i, alfabeto *vector);

int main()
{
	printf("\t BIENVENIDO A ENIGMA \n");
		int o=0;
		int s=0;
		while (o<1||o>2)//eleccion del metodo
			{
			printf("escoja una opcion:\n 1.cifrar			2.descifrar\n");
			scanf("%i", &o);
			if (o<1||o>2)
				{
					printf ("opcion no valida\n");
				}	
			}
		switch(o)
		{
		case 1://opcion de cifrar
			printf("has escogido la opcion de cifrar\n");
			while (s<1||s>2)
			{
				printf("1. Generar nueva semilla. \t2. Usar semilla exixtente\n");
				scanf ("%i", &s);
				if (s<1||s>2)
				{
					printf ("opcion no valida\n");
				}
				if (s == 1)
				{
					printf ("Ok.\n");
					rand_alfabetos();
				}
				if (s == 2)
				{
					printf ("Ok.\n");
				}
				code();//funcion que pide una frase y la trata y codifica
			}
			break;		
		case 2://opcion de descifrar.
			printf("has escogido la opcion de descifrar\n");
			
			break;
		}
}

int rand_alfabetos()
/*escribe un numero determinado de alfabetos aleatorios en un fichero
para leerlos o copiarlos a una matriz mas tarde*/
{
	
	FILE *pf;
	int rn,rc;//variables para numeros aleatrorios
	int a; //variable para el bucle de matrices
	int d; //variable para el bucle de alfabetos
	int comp[25]; //matriz auxiliar de comparación de igualdad
	int i,n; //variables auxiliares
	printf ("Generando alfabetos...\n");
	srand((unsigned)time(NULL));
	pf=fopen("alfabetos.odt","w");
	if(pf==NULL){
		printf("Error de fichero\n");
		return -1;
	}
	else
	{
		for(a=0; a<X; a++)
		{
			for(d=0;d<25;d++)//aquí es donde se genera el alfabeto//
			{
				n=0;
				rn=rand();
				
				if(rn>122||rn<97)//si el numero aleatorio no esta entre la a y la z, se repite//
				{
					d--;
				}
				
				else
				{
					for(i=0;i<d;i++)
					{
						if(comp[i]==rn)//cuenta el numero de veces que se repite un numero//
						{
							n++;//flag para ver las repeticiones
						}
					}
					if(n>0)//si se repite con alguno, se deja y d se resta uno para que cree otro numero hasta que no sea repetido//
					{
						d--;
					}
					else
					{
						comp[d]=rn;
						rc=(char)rn;//convertimos el numero en letra//
						fprintf(pf,"%c", rc);
					}	
				}
			}
		}
		fclose(pf);
	}
	printf ("Alfabetos generados con exito.\n\n");
	return(0);	
}

void copia(int i, alfabeto *vector)
/*devuelve segun el numero i que se le ponga el alfabeto
correspondiente a su posición en el fichero*/
{	
	FILE *pf;
	pf = fopen ("alfabetos.odt", "r");
	if (i > 0)//en el caso de un numero superior, la lectura avanza 26 char y empieza a leer desde alli.
	{
		fseek (pf, i*sizeof(char)*26, SEEK_SET);
	}
	fscanf(pf, "%26s", vector->unidad);
	fclose(pf);
}

void code()
/*abre el fichero donde estan guardados los alfabetos y los copia a la matriz segun el numero de letras del mensaje.
Despues, una frase introducida es tratada y codificada por la funcion. 
Una vez terminado el proceso, se pregunta al usuario si desea guardar el mensaje en un fichero por si quiere conservarlo*/
{
	FILE *pd;
	char s[X];//mensaje inicial
	char ss[X];//mensaje codificado
	int var = 'a'-'A';
	int n;//posicion del alfabeto
	int e=0;//variable para la eleccion de ficheros
	int len=0;//valor del numero de letras
	int i=0;//variable de bucle
	int a=0;//variable de bucle
	alfabeto vector;//alfabeto para copiar del fichero
	alfabeto *pvector = &vector;//puntero al alfabeto
	alfabeto matriz[X];//matriz de alfabetos
	//primero, una frase es introducida por el usuario
	printf ("\n");
	printf ("introduce una frase (maximo de letras: %d)\n", X);
	printf ("ADVERTENCIA!! Debes usar el tabulador para indicar el final del mensaje.\n");
	scanf ("%[^\t]s", s);
	len = strlen(s);
	//esta es la parte donde se manipula el mensaje
	while (s[a] != '\0')
	{
		if (s[a]== ' ')//cambia los espacios por barras 
		{
			s[a] = '/';
		}
		if (s[a]>= 'A' && s[a]<= 'Z')//cambia las mayusculas por minusculas
		{
			s[a] = s[a] + var; 
		}
		a++;
	}
	//esta es la parte donde se copian los alfabetos a la matriz
	for (i=0; i<len; i++)
	{
		copia (i, &vector);
		strcpy (matriz[i].unidad, vector.unidad);
	}
	for (i=0; i<len; i++)
	{
		if (s[i]>='a' && s[i]<='z')//si la letra esta contenida en el rango del alfabeto, se codifica
		{
			n = s[i] - 97;
			ss[i] = matriz[i].unidad[n];
		}
		else //si la letra no esta contenida, se deja como esta
		{
			ss[i]= s[i];
		}
	}
	printf ("Mensaje codificado:%s\n", ss);
	//esta es la parte donde se copia (o no) el mensaje a un fichero
	printf ("desea guardar el mensaje en un fichero?\n");
	while (e<1||e>2)
		{
			printf("1. Si.				2. No\n");
			scanf ("%i", &e);
			if (e<1||e>2)
			{
				printf ("opcion no valida\n");
			}
			if (e == 1)
			{
				printf ("guardando fichero...\n");
				pd = fopen ("mensajes.txt", "w");
				if(pd==NULL)
				{
					printf("Error de fichero\n");
				}
				fprintf (pd, "%s", ss);
				printf ("fichero guardado con exito.\n");
				fclose (pd);
			}
			if (e == 2)
			{
				printf ("Ok.\n");
			}
		}
}
