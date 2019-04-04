#include <stdio.h>

int secuencia_inicial(int a, int b, int c);
int main()
{
while (1)
{
	printf("\t BIENVENIDO A ENIGMA \n");
	int o=0;
	int a=0, b=0, c=0;
	while (o<1||o>2)
		{
		printf("escoja una opcion:\n 1.cifrar \t 2.descifrar\n");
		scanf("%i", &o);	
		}
	switch(o)
	{
	case 1:
		printf("has escogido la opcion de cifrar\n");
			while (a<1||a>9)
				{
				printf("introduzca un numero del 1 al 9, el primer numero de la secuencia inicial:\n");
				scanf("%i", &a);
				if (a<1||a>9)
					{
						printf ("numero no valido, ");
					}	
				}
			while (b<1||b>9)
				{
				printf("introduzca un numero del 1 al 9, el segundo numero de la secuencia inicial:\n");
				scanf("%i", &b);
				if (b<1||b>9)
					{
						printf ("numero no valido, ");
					}	
				}
			while (c<1||c>3)
				{
				printf("introduzca un numero del 1 al 3, el tercer numero de la secuencia inicial\n");
				scanf("%i", &c);
				if (a<1||c>3)
					{
						printf ("numero no valido, ");
					}	
				}
			break;
	case 2:
		printf("has escogido la opcion de descifrar\n");
			while (a<1||a>9)
				{
				printf("introduzca un numero del 1 al 9, el primer numero de la secuencia inicial:\n");
				scanf("%i", &a);
				if (a<1||a>9)
					{
						printf ("numero no valido, ");
					}	
				}
			while (b<1||b>9)
				{
				printf("introduzca un numero del 1 al 9, el segundo numero de la secuencia inicial:\n");
				scanf("%i", &b); 
				if (b<1||b>9)
					{
						printf ("numero no valido, ");
					}	
				}
			while (c<1||c>3)
				{
				printf("introduzca un numero del 1 al 3, el tercer numero de la secuencia inicial\n");
				scanf("%i", &c);
				if (a<1||c>3)
					{
						printf ("numero no valido, ");
					}	
				}
	
	break;
	}
}
}

