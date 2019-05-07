#include<stdio.h>
int main()
{
	FILE *pf;
	int a,b,c,d,num;
	char letra;
	char alfabetos[9][9][2][25];
	pf=fopen("alfabetos.txt","r");
	printf("Escribe una letra\n");
	scanf("%c", &letra);
	if(pf==NULL)
	{
		printf("Erro de ficheiro\n");
		return(-1);
	}
	else
	{
		for(a=0;a<10;a++)
		{
			for(b=0;b<10;b++)
			{
				for(c=0;c<3;c++)
				{
					for(d=0;d<26;d++)
					{
						fscanf(pf,"%c",&alfabetos[a][b][c][d]);
					}
				}
			}
		}
	
		num=(int)letra;
		printf("Nueva letra: %c\n", alfabetos[3][4][1][num-97]);
		fclose(pf);
	
	}
	
}
