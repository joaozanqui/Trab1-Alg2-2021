//SENHA: 123abc

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define baixo 80
#define cima 72
#define esc 27
#define enter 13

void gotoxy (int x, int y)
{
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int color (char color)
{
  HANDLE h;
  h = GetStdHandle(STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute(h,color);
}

void texto(int x, int y, char texto[], int cor)
{
	color(cor);
	gotoxy(y,x);
	printf("    %s    ", texto);
}

void selecao(int x, int y, char texto[], int cor)
{
	color(cor);
	gotoxy(y,x);
	printf("--> %s <--", texto);
}

void menu(int opc)
{
	int i;
	char x[4][70] = {"Escolha A Operacao Desejada", "Retirar Um Valor", "Preenchimento de Cheque", "SAIR DA SUA CONTA"};
	
	for(i=0; i<4; i++)
	{
		if(i>0)
			texto(i+1, (80-strlen(x[i]))/2-4, x[i], 15);
		else
			texto(0, (80-strlen(x[i]))/2-4, x[i], 15);
	}
	
	for(i=0; i<4; i++)
	{
		if(i>0)
		{
			if(opc==i)
			{
				if(opc==3)
					selecao(i+1, (80-strlen(x[i]))/2-4, x[i], 4);
				else 
					selecao(i+1, (80-strlen(x[i]))/2-4, x[i], 15);
			}
			else
				texto(i+1, (80-strlen(x[i]))/2-4, x[i], 15);
		}
		else
			texto(0, (80-strlen(x[i]))/2-4, x[i], 15);
	}
	
}

void notas(double valor)
{
	int x100=0, x50=0, x20=0, x10=0, x5=0, x2=0, x1=0, x05=0, x025=0, x010=0, x001=0;
	float x;
	
	while(valor>=100) {
		x100++;
		valor-=100;
	}
	
	while(valor>=50) {
		x50++;
		valor-=50;
	}
	
	while(valor>=20) {
		x20++;
		valor-=20;
	}
	
	while(valor>=10) {
		x10++;
		valor-=10;
	}
	
	while(valor>=5) {
		x5++;
		valor-=5;
	}
	
	while(valor>=2) {
		x2++;
		valor-=2;
	}
	
	while(valor>=1) {
		x1++;
		valor-=1;
	}
	
	while(valor>=0.5) {
		x05++;
		valor-=0.5;
	}
	
	while(valor>=0.25) {
		x025++;
		valor-=0.25;
	}
	
	while(valor>=0.09) {
		x010++;
		valor-=0.1;
	}
	
	while(valor>0.005) {
		x001++;
		valor-=0.01;
	}

	gotoxy(0, 4);
	printf("Serao entregues:\n");
	
	if(x100>0)
		printf("%d nota(s) de B$ 100,00\n", x100);
	if(x50>0)
		printf("%d nota(s) de B$ 50,00\n", x50);
	if(x20>0)
		printf("%d nota(s) de B$ 20,00\n", x20);
	if(x10>0)
		printf("%d nota(s) de B$ 10,00\n", x10);
	if(x5>0)
		printf("%d nota(s) de B$ 5,00\n", x5);	
	if(x2>0)
		printf("%d nota(s) de B$ 2,00\n", x2);	
	if(x1>0)
		printf("%d moeda(s) de B$ 1,00\n", x1);	
	if(x05>0)
		printf("%d moeda(s) de B$ 0,50\n", x05);	
	if(x025>0)
		printf("%d moeda(s) de B$ 0,25\n", x025);
	if(x010>0)
		printf("%d moeda(s) de B$ 0,10\n", x010);	
	if(x001>0)
		printf("%d moeda(s) de B$ 0,01\n", x001);
		
	printf("\n\n");
}

void escrever_centena(int u, int d, int c)
{
	switch(c)
	{
		case 900: printf("Novecentos ");
				break;
		case 800: printf("Oitocentos ");
				break;
		case 700: printf("Setecentos ");
				break;
		case 600: printf("Seiscentos ");
				break;
		case 500: printf("Quinhentos ");
				break;
		case 400: printf("Quatrocentos ");
				break;
		case 300: printf("Trezentos ");
				break;
		case 200: printf("Duzentos ");
				break;
		case 100: if(d!=0 || u!=0)
				 	printf("Cento ");
				  else
					printf("Cem ");
				break;
	}
				
	if(d!=0 || u!=0)
		printf("e ");
}

void escrever_dezena(int u, int d)
{
	switch(d)
	{
		case 90: printf("Noventa ");
				break;
		case 80: printf("Oitenta ");
				break;
		case 70: printf("Setenta ");
				break;
		case 60: printf("Sessenta ");
				break;
		case 50: printf("Cinquenta ");
				break;
		case 40: printf("Quarenta ");
				break;
		case 30: printf("Trinta ");
				break;
		case 20: printf("Vinte ");
				break;
		case 10: if(u!=0)
				 {
					switch(u) 
					{
						case 9:	printf("Dezenove ");
								break;
						case 8:	printf("Dezoito ");	
								break;
						case 7:	printf("Dezessete ");
								break;
						case 6: printf("Dezesseis ");
								break;
						case 5: printf("Quinze ");
								break;
						case 4:	printf("Quatorze ");
								break;
						case 3:	printf("Treze ");
								break;
						case 2: printf("Doze ");
								break;
						case 1:	printf("Onze ");
								break;
					}
				 }
				 else
					printf("Dez ");
	}

				
		if(d>10 && u!=0)
			printf("e ");
}

void escrever_unidade(int u)
{
	switch(u)
	{
		case 9: printf("Nove ");
				break;
		case 8: printf("Oito ");
				break;
		case 7: printf("Sete ");
				break;
		case 6: printf("Seis ");
				break;
		case 5: printf("Cinco ");
				break;
		case 4: printf("Quatro ");
				break;
		case 3: printf("Tres ");
				break;
		case 2: printf("Dois ");
				break;
		case 1: printf("Um ");
				break;
	}
	
}

void escrever_valores(double valor)
{
	int u, d, c;
	for(u=0; u<10; u++)
		if(((int)valor-u)%10==0)
			break;
	for(d=0; d<100; d+=10)
		if(((int)valor-u-d)%100==0)
			break;
	for(c=0; c<1000; c+=100)
		if(((int)valor-u-d-c)==0)
			break;
	
	if(c!=0)
		escrever_centena(u, d, c);
	if(d!=0)
		escrever_dezena(u, d);
	if(u!=0 && d!=10)
		escrever_unidade(u);
}

void zerar_vetor(char vetor[], int n)
{
	int i;
	
	for(i=0; i<n; i++)
		vetor[i]='\0';
}

char organizar_valor(char* v, int ponto)
{
	int i, n=strlen(v), p;

	if(ponto==1)
	{
		for(i=0; i<n; i++)
			if(v[i]==',' || v[i]=='.')
			{
				p=i;
				break;
			}
		
		while(n-3<p && n-3<p) 
		{
			v[strlen(v)]='0';
			n++;
		}
		
		while(n-3>p && n-3>p)
		{
			if((int)v[n-1]>=53)
			{
				v[(strlen(v)-1)]='\0';
				(int)v[n-2]++;
			}
			else
				v[(strlen(v)-1)]='\0';
			
			n--;
		}
		
	}
	
	else
	{
		v[n]=',';
		v[n+1]='0';
		v[n+2]='0';
		n+=3;
	}
	
	while((n-3)%3!=0)
	{
		for(i=n; i>0; i--)
		{
			v[i]=v[i-1];
		}
		n++;
		v[0]='0';
	}

	return *v;
}

void separar_valor(char* v)
{
	int i, j, bi=0, mi=0, mil=0, cem=0, cent=0;
	int n=strlen(v)/3, nv=strlen(v);
	char valores[n][3];
	
	for(i=0; i<n; i++)
	{
		for(j=2; j>=0; j--)
		{
			if(i==0 && j==0)
				valores[i][j]='0';
			else
				valores[i][j]=v[nv-1];
			
			nv--;
		}
	}
	
	for(i=0; i<n; i++)
		switch(i)
		{
			case 0: cent = ((int)valores[i][0]-48)*100 +  ((int)valores[i][1]-48)*10 + (int)valores[i][2]-48;
					break;
			case 1: cem = ((int)valores[i][0]-48)*100 +  ((int)valores[i][1]-48)*10 + (int)valores[i][2]-48;
					break;
			case 2: mil = ((int)valores[i][0]-48)*100 +  ((int)valores[i][1]-48)*10 + (int)valores[i][2]-48;
					break;
			case 3: mi = ((int)valores[i][0]-48)*100 +  ((int)valores[i][1]-48)*10 + (int)valores[i][2]-48;
					break;
			case 4: bi = ((int)valores[i][0]-48)*100 +  ((int)valores[i][1]-48)*10 + (int)valores[i][2]-48;
					break;
		}
				
	color(4);
	printf("\n\nPAGUE POR ESTE CHEQUE A QUANTIA DE: ");
	color(9);
		
	if(bi!=0)
	{
		escrever_valores(bi);
		if(bi>1)
			printf("Bilhoes");
		else
			printf("Bilhao");
		
		if(mi!=0 || mil!=0 || cem!=0)
			printf(", ");
		else
			printf(" De");
	}
	
	if(mi!=0)
	{
		escrever_valores(mi);
		if(mi>1)
			printf("Milhoes");
		else
			printf("Milhao");
		
		if(mil!=0 || cem!=0)
			printf(", ");
		else
			printf(" De");
	}
	
	if(mil!=0)
	{
		escrever_valores(mil);
		printf("Mil");
			
		if(cem!=0)
			printf(", ");
	}
	
	if(cem!=0)
	{
		escrever_valores(cem);
		printf("Bits ");
	}
	
	else if(mil!=0 || mi!=0 || bi!=0)
		printf(" Bits ");
		
				
	if(cent!=0)
	{
		if(cem!=0 || mil!=0 || mi!=0 || bi!=0)
			printf("e ");
		escrever_valores(cent);
		printf("CentBits");
	}

}


void ler_valor()
{
	int i, j, aux=0, ponto, depois_ponto;
	char valor[20];
	
	do {
		zerar_vetor(valor, 20);
		
		printf("\nDigite o Valor do Cheque: B$ ");
		scanf("%s", valor);
		ponto=0;
		depois_ponto=0;
		
		for(i=0; i<16; i++)
		{
			if(ponto==1 && (int)valor[i]<=57 && (int)valor[i]>=48)
				depois_ponto++;
			
			if((int)valor[i]>57 && (int)valor[i]!=0|| (int)valor[i]<48 && (int)valor[i]!=0)
			{
					
				if(valor[i]==',' || valor[i]=='.')
				{
					ponto++;
					if(ponto>1)
					{
						color(4);
						printf("Por favor digite um valor valido\n\n");
						color(15);
						system("pause");
						system("cls");
						aux=1;
						break;
					}
					else
						aux=0;
				}
				
				else
				{
					color(4);
					printf("Por favor digite um valor valido\n\n");
					color(15);
					system("pause");
					system("cls");
					aux=1;
					break;
				}
			}
				
			else
				aux=0;
		}
		
		if(strlen(valor)>15 && aux==0|| ponto==0 && strlen(valor)>12 && aux==0 || depois_ponto<=1 && aux==0 && strlen(valor)>13)
		{
			color(4);
			printf("Por favor digite um valor menor\n");
			color(15);
			system("pause");
			system("cls");
			aux=1;
		}
	} while(aux==1);

	*valor = organizar_valor(valor, ponto);
	separar_valor(valor);		
}


int main()
{
	int opc, dia, ano;
	char t, senha[]="123abc", s[6], mes[10];
	double valor;
	
	do {
		system("cls");
			gotoxy(20, 2);
			color(14);
			printf("'ENTER' --> Acessar o programa");
			gotoxy(20, 3);
			printf("'ESC' --> Fechar o programa");
			color(4);
			t=getch();
			
			if(t==esc)
				break;
			else if(t!=enter)
				continue;
		
		do {
			system("cls");
			gotoxy(20, 2);
			color(14);
			printf("Digite a Senha de 6 Digitos Para Acessar Sua Conta: ");
			color(4);
			gets(s);
						
			if(strcmp(s, senha)!=0)
			{
				gotoxy(20, 3);
				printf("SENHA INCORRETA TENTE NOVAMENTE\n\n");
				color(15);
				system("pause");
			}
		}while(strcmp(s, senha)!=0);
		system("cls");
		opc=1;
		
		do {
			valor=0;
			menu(opc);
			fflush(stdin);
			t=getch();
			if(t<=0) 
			{
				t=getch();
				if (t==baixo)
				{
			    	opc++;
			    	if(opc>3)
			    		opc=1;
					menu(opc);
			 	}
			  	
				else if(t==cima) 
				{
			  		opc--;
			  		if(opc<1)
			  			opc=3;
			  		menu(opc);
			  	}
		    }
		    
		    else if(t==enter)
		    {
		    	switch(opc)
		    	{
					case 1: system("cls");
							gotoxy(0, 2);
							printf("Digite o Valor Que Deseja Retirar: B$ ");
							scanf("%lf", &valor);
							notas(valor);
							system("pause");
							break;
							
					case 2: system("cls");
							gotoxy(0, 2);
						
							printf("\nDigite a data do Cheque:\nDia: ");
							scanf("%d", &dia);
							printf("Mes (Por extenso): ");
							scanf("%s", mes);
							printf("Ano: ");
							scanf("%d", &ano);
							
							ler_valor();
						
							printf("\n\nBauru, %d de %s de %d.\n\n\n\n", dia, mes, ano);
							color(15);
							system("pause");
							break;
							
					case 3: system("cls");
							opc=0;
							break;
				}
			}
				
			system("cls");
			
		}while(opc!=0);
				
	}while(t!=esc);	

	return 0;	
}
