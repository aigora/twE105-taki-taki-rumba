#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
#define X 100

typedef struct//la unidad del vector de alfabetos
{
	char unidad[26];
}alfabeto;

void copia (int i, alfabeto *vector);

void main()
{
	char s[100];
	int n;
	int len=0;
	int i=0;
	int b=80;
	alfabeto vector;//alfabeto para copiar del fichero
	alfabeto *pvector = &vector;//puntero al alfabeto
	alfabeto matriz[b];//matriz de alfabetos
	printf ("iniciando secuencia aleatoria de alfabeto....\n");
	rand_alfabetos();//escribe al empezar la secuencia aleatoria de los alfabetos en el fichero
	printf ("secuencia realizada con exito.\n");
	for (i=0; i<b; i++)
	{
		copia (i, &vector);
		strcpy (matriz[i].unidad, vector.unidad);
		
	}
	printf ("\n");
	printf ("introduce una frase\n");
	scanf ("%100s", s);
	len = strlen(s);
	printf ("%d\n", len);
	for (i=0; i<len; i++)
	{
		if (s[i]>'a' && s[i]<'z')//si la letra esta contenida en el rango del alfabeto, se codifica
		{
			n = s[i] - 97;
			printf ("%c", matriz[i].unidad[n]);
		}
		else //si la letra no esta contenida, se deja como esta
		{
			printf ("%c", s[i]);
		}
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
