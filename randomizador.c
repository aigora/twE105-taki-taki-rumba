#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	FILE *pf;
	int rn,rc;//variables para numeros aleatrorios//
	int a,b,c,d; //variables de la rueda + letra//
	int comp[25]; //matriz auxiliar de comparación de igualdad//
	int i,n,e; //variables auxiliares//
	srand((unsigned)time(NULL));
	pf=fopen("alfabetos.txt","w");
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
								printf("%i %c\n",rc, rc);
								fprintf(pf,"%c ", rc);
							}	
						}
					}	
				}
			}
		}
		fclose(pf);
	}
	return(0);	
}
	
	


/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
    char randChar = ' ';
    int counter = 0;
    int randNum = 0;
    srand(time(NULL));
    for (counter = 0; counter < 10; counter++)
    {
    	randNum = 26 * (rand() / (RAND_MAX +1.0));
        randNum = randNum + 97;
        randChar = (char) randNum;
		printf ("Random char: %c\n", randChar);
      }
  }
  */
