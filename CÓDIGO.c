#include <stdio.h>

int secuencia_inicial(int a, int b, int c);
int main()
{
while (1)
{
	printf("\t BIENVENIDO A ENIGMA \n");
	int o=0;
	int s=0;
	int a=0, b=0, c=0;
	while (o<1||o>2)//elección del método
		{
		printf("escoja una opcion:\n 1.cifrar \t 2.descifrar\n");
		scanf("%i", &o);
		if (o<1||o>2)
			{
				printf ("opcion no valida, ");
			}	
		}
	switch(o)
	{
	case 1://opción de cifrar
		printf("has escogido la opcion de cifrar\n");
			printf ("Escribe las tres claves (a[0,9], b[0,9], c[1,3].)\n");
			printf ("a= ");
			scanf ("%d", &a);
			while (a<0 || a>9)//elección del primer parámetro
			{
				printf ("numero no valido\na= ");
				scanf ("%d", &a);
			}
	
			printf ("b= ");
			scanf ("%d", &b);
			while (b<0 || b>9)//elección del segundo parámetro
			{
				printf ("numero no valido\nb=");
				scanf ("%d", &b);
			}
	
			printf ("c= ");
			scanf ("%d", &c);
			while (c<1 || c>3)//elección del tercer parámetro
			{
				printf ("numero no valido\nc=");
				scanf ("%d", &c);
			}
			printf ("posicion inicial de las ruedas:\n (%d, %d, %d)\n", c, b, a);
			
		printf ("teclee cualquier tecla para iniciar\n");
	scanf ("%c\n", &s);
	while (1)//bucle de pruebas
	{
		/*Las tres ruedas parten  de una posición inicial, y por cada 
		letra que se avance, la primera rueda suma un paso, hasta que 
		llegue a su última posición, que avanzará la segunda un paso, y
		así sucesivamente.*/
			a ++;
			if (a == 10)
			{
				a = 0;
				b ++;
				if (b == 10)
				{
					b = 0;
					c ++;
					if (c == 4)
					{
						c = 1;
					}
				}
			}
		s = (s+a+b)*c;
		/*Cada letra es sumada a los valores de las priemras dos ruedas y
		multiplicada por el tercer valor de la tercera rueda.*/
		while (s > 126)
		{
			s = s - (126);//Devolver el número entre 32 y 127 para que tenga sentido
		}
		if (s < 32)
		{
			s = s + 32;
		}
		printf ("(%d, %d, %d)\n", c, b, a);
		printf (" new= %c %d\n", s, s);
		scanf ("%c\n", &s);
	}
			
	break;
	case 2://opción de descifrar.
				printf("has escogido la opcion de descifrar\n");
					printf ("Escribe las tres claves (a[0,9], b[0,9], c[1,3].)\n");
			
			printf ("a= ");
			scanf ("%d", &a);
			while (a<0 || a>9)
			{
				printf ("numero no valido\na= ");
				scanf ("%d", &a);
			}
	
			printf ("b= ");
			scanf ("%d", &b);
			while (b<0 || b>9)
			{
				printf ("numero no valido\nb=");
				scanf ("%d", &b);
			}
	
			printf ("c= ");
			scanf ("%d", &c);
			while (c<1 || c>3)
			{
				printf ("numero no valido\nc=");
				scanf ("%d", &c);
			}
			printf ("posicion inicial de las ruedas:\n (%d, %d, %d)\n", c, b, a);
	
	break;
	}
}
}

