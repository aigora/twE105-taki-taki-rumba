#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
#define X 100

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
			printf("escoja una opcion:\n 1.cifrar \t 2.descifrar\n");
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
				printf("1. Generar nuevo alfabeto. \t2. Usar alfabeto exixtente\n");
				scanf ("%i", &s);
				if (s<1||s>2)
				{
					printf ("opcion no valida\n");
				}
				if (s == 1)
				{
					rand_alfabetos();
				}
				code();	
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
	printf ("Generando alfabeto...\n");
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
	printf ("Alfabeto generado con exito.\n\n");
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
{
	char s[X];//mensaje
	int var = 'a'-'A';
	int n;//posicion del alfabeto
	int len=0;
	int i=0;
	int a=0;
	int b;
	printf ("\n");
	printf ("introduce una frase\n");
	scanf ("%[^88]s", s);
	printf ("%s\n", s);
	while (s[a] != '\0')
	{
		if (s[a]== ' ')
		{
			s[a] = '/';
		}
		a++;
	}
  	printf("%s\n", s); //Imprime el resultado
	len = strlen(s);
	printf ("%d\n", len);
	alfabeto vector;//alfabeto para copiar del fichero
	alfabeto *pvector = &vector;//puntero al alfabeto
	alfabeto matriz[b];//matriz de alfabetos
	for (i=0; i<b; i++)
	{
		copia (i, &vector);
		strcpy (matriz[i].unidad, vector.unidad);
		
	}
	
	for (i=0; i<len; i++)
	{
		if (s[i]>='a' && s[i]<='z')//si la letra esta contenida en el rango del alfabeto, se codifica
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
