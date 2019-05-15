#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
#define X 1000

typedef struct//la unidad del vector de alfabetos
{
	char unidad[26];
}alfabeto;

void code();//funcion de codificar

void decode();//funcion de decodificar

void copia (int i, alfabeto *vector); //funcion de copiar alfabetos

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
				code();//funcion que pide un mensahe y lo trata y codifica
			}
			break;		
		case 2://opcion de descifrar.
			printf("has escogido la opcion de descifrar\n");
			printf ("Se asume que utilizas la ultima semilla guardada en el fichero.\nSi no es asi, copia la nueva semilla en el fichero y vuelve al programa.\n");
			decode();
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
			for(d=0;d<26;d++)//aquí es donde se genera el alfabeto//
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
	char aux[26];
	FILE *pf;
	pf = fopen ("alfabetos.odt", "r");
	if (i > 0)//en el caso de un numero superior, la lectura avanza 26 char y empieza a leer desde alli.
	{
		fseek (pf, i*sizeof(char)*26, SEEK_SET);
	}
	fscanf(pf, "%26s", aux);
	strcpy (vector->unidad, aux);
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
	int n=0;//posicion del alfabeto
	int e=0;//variable para la eleccion de ficheros
	int h=0;//variable para la eleccion del metodo
	int len=0;//valor del numero de letras
	int i=0;//variable de bucle
	int a=0;//variable de bucle
	alfabeto vector;//alfabeto para copiar del fichero
	alfabeto *pvector = &vector;//puntero al alfabeto
	alfabeto matriz[X];//matriz de alfabetos
	//primero, una frase es introducida por el usuario
	printf ("\n");
	printf ("desea introducir el mensaje por el monitor o copiarlo desde un fichero?\n");
	while (h<1||h>2)	
		{
			printf("1. Escribir manual. \t2. Leer fichero.\n");
			scanf ("%i", &h);
			if (h<1||h>2)
			{
				printf ("opcion no valida\n");
			}
			if (h == 1)
			{
				printf ("introduce el mensaje a cifrar (maximo de letras: %d)\n", X);
				printf ("ADVERTENCIA!! Debes usar el tabulador para indicar el final del mensaje.\n");
				scanf ("%[^\t]s", s);
			}
			if (h == 2)
			{
				printf ("Ok.\n");
			}
		}
	
	len = strlen(s);

	if (len<X)
	{
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
		//esta es la parte donde se codifica el mensaje
		for (i=0; i<len; i++)
		{
			if (s[i]>='a' && s[i]<='z')//si la letra esta contenida en el rango del alfabeto, se codifica
			{
				n = s[i] - 97;
				ss[i] = matriz[i-1].unidad[n];
			}
			
			else //si la letra no esta contenida, se deja como esta
			{
				ss[i]= s[i];
			}
			n=0;
		}
		ss[i]= '\0';//se añade manualmente un final de cadena
		printf ("Mensaje codificado:\n%s\n", ss);
		//esta es la parte donde se copia (o no) el mensaje a un fichero
		printf ("\ndesea guardar el mensaje en un fichero?\n");
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
	else 
	{
		printf ("Has excedido el numero maximo de caracteres.\n");
	}
}

void decode()
/*abre el fichero donde estan guardados los alfabetos y los copia a la matriz segun el numero de letras del mensaje.
Despues, una frase introducida es tratada y decodificada por la funcion. 
Una vez terminado el proceso, se pregunta al usuario si desea guardar el mensaje en un fichero por si quiere conservarlo*/
{
	FILE *pd;
	char s[X];//mensaje inicial
	char ss[X];//mensaje codificado
	int var = 'a'-'A';
	int n=0;//posicion del alfabeto
	int e=0;//variable para la eleccion de ficheros
	int len=0;//valor del numero de letras
	int i=0;//variable de bucle
	int a=0;//variable de bucle
	int d=0;//variable de bucle
	alfabeto vector;//alfabeto para copiar del fichero
	alfabeto *pvector = &vector;//puntero al alfabeto
	alfabeto matriz[X];//matriz de alfabetos
	//primero, una frase es introducida por el usuario
	printf ("\n");
	printf ("introduce el mensaje a cifrar (maximo de letras: %d)\n", X);
	printf ("ADVERTENCIA!! Debes usar el tabulador para indicar el final del mensaje.\n");
	scanf ("%[^\t]s", s);
	len = strlen(s);

	if (len<X)
	{
		//esta es la parte donde se manipula el mensaje
		while (s[a] != '\0')
		{
			if (s[a]== '/')//cambia los espacios por barras 
			{
				s[a] = ' ';
			}
			a++;
		}
		//esta es la parte donde se copian los alfabetos a la matriz
		for (i=0; i<len; i++)
		{
			copia (i, &vector);
			strcpy (matriz[i].unidad, vector.unidad);
		}
		//esta es la parte donde se codifica el mensaje
		for (i=0; i<len; i++)
		{
			if (s[i]>='a' && s[i]<='z')//si la letra esta contenida en el rango del alfabeto, se decodifica
			{
				while (s[i]!= matriz[i-1].unidad[d])
				{
					n++;
					d++;
				}
				ss[i]= d + 97;
				d=0;
				n=0;
			}
			else //si la letra no esta contenida, se deja como esta
			{
				ss[i]= s[i];
			}
			n=0;
		}
		ss[i]= '\0';//se añade manualmente un final de cadena
		printf ("Mensaje decodificado:\n%s\n", ss);
		//esta es la parte donde se copia (o no) el mensaje a un fichero
		printf ("\ndesea guardar el mensaje en un fichero?\n");
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
	else 
	{
		printf ("Has excedido el numero maximo de caracteres.\n");
	}
}
