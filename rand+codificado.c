#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	FILE *alfabeto;
	char *ruedas[9][9][3][26];
	char rueda1[26];
	printf ("iniciando secuencia aleatoria de alfabeto.\n");
	alfabetos();//escribe al empezar la secuencia aleatoria de los alfabetos en el fichero
	printf ("secuencia realizada con exito.\n");
	alfabeto= fopen("alfabetos.odt", "r");
	
	fscanf(alfabeto, "%26s", rueda1);//guarda la primera rueda en un char
	printf ("Rueda 1: %26s\n", rueda1);
	fclose (alfabetos);
	
}


int alfabetos()
{
	FILE *pf;
	int rn,rc;//variables para numeros aleatrorios//
	int a,b,c,d; //variables de la rueda + letra//
	int comp[25]; //matriz auxiliar de comparación de igualdad//
	int i,n,e; //variables auxiliares/
	srand((unsigned)time(NULL));
	pf=fopen("alfabetos.odt","w");
	if(pf==NULL){
		printf("Error de fichero\n");
		return -1;
	}
	else
	{
		for(a=0;a<10;a++)
		{
			for(b=0;b<10;b++)
			{
				for(c=0;c<3;c++)
				{
					for(e=0;e<25;e++)
					{
						comp[e]=0;//devolvemos el vector comparador a todo valores 0//
					}
					for(d=0;d<25;d++)//aquí es donde se genera el alfabeto//
					{
						n=0;
						rn=rand();
						if(rn>122||rn<97)
						{
							d--;
						}
						else
						{
							for(i=0;i<d;i++)
							{
								if(comp[i]==rn)//cuenta el numero de veces que se repite un numero//
								{
									n++;
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
				fprintf (pf, "\n", rc);	
				}
			}
		}
		fclose(pf);
	}
	return(0);	
}
