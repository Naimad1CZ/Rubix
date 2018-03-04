#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> //v pripade potreby nepouzivat tento import lze prejmenovat void 'tisk2' na 'tisk',
					//void 'tisk' zakomentovat a taky zakomentovat prvni prikaz v int 'main'
#include <time.h>

typedef struct{
	char i;
	char j;
	char k;
}souradnice;

void inicializace(char kostka[5][5][5]){
	int i, j, k;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			for(k = 0; k < 5; k++)
			{
				kostka[i][j][k] = 0;
			}
		}
	}
	//bila
	kostka[0][1][1] = 6;
	kostka[0][1][2] = 1;
	kostka[0][1][3] = 7;
	kostka[0][2][1] = 4;
	kostka[0][2][2] = 5;
	kostka[0][2][3] = 2;
	kostka[0][3][1] = 9;
	kostka[0][3][2] = 3;
	kostka[0][3][3] = 8;
	//zluta
	kostka[4][1][1] = 56;
	kostka[4][1][2] = 51;
	kostka[4][1][3] = 57;
	kostka[4][2][1] = 54;
	kostka[4][2][2] = 55;
	kostka[4][2][3] = 52;
	kostka[4][3][1] = 59;
	kostka[4][3][2] = 53;
	kostka[4][3][3] = 58;
	//oranzova
	kostka[3][4][1] = 36;
	kostka[3][4][2] = 31;
	kostka[3][4][3] = 37;
	kostka[2][4][1] = 34;
	kostka[2][4][2] = 35;
	kostka[2][4][3] = 32;
	kostka[1][4][1] = 39;
	kostka[1][4][2] = 33;
	kostka[1][4][3] = 38;
	//cervena
	kostka[3][0][3] = 16;
	kostka[3][0][2] = 11;
	kostka[3][0][1] = 17;
	kostka[2][0][3] = 14;
	kostka[2][0][2] = 15;
	kostka[2][0][1] = 12;
	kostka[1][0][3] = 19;
	kostka[1][0][2] = 13;
	kostka[1][0][1] = 18;
	//modra
	kostka[3][3][4] = 26;
	kostka[3][2][4] = 21;
	kostka[3][1][4] = 27;
	kostka[2][3][4] = 24;
	kostka[2][2][4] = 25;
	kostka[2][1][4] = 22;
	kostka[1][3][4] = 29;
	kostka[1][2][4] = 23;
	kostka[1][1][4] = 28;
	//zelena
	kostka[3][1][0] = 46;
	kostka[3][2][0] = 41;
	kostka[3][3][0] = 47;
	kostka[2][1][0] = 44;
	kostka[2][2][0] = 45;
	kostka[2][3][0] = 42;
	kostka[1][1][0] = 49;
	kostka[1][2][0] = 43;
	kostka[1][3][0] = 48;
}

void tisk2(char kostka[5][5][5]){
	unsigned char barvy[5][5][5];
	int i, j, k;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5 ; j++)
		{
			for(k = 0; k < 5; k++)
			{
				if( (kostka[i][j][k] > 0) && (kostka[i][j][k] < 10) ) barvy[i][j][k] = 'W'; //white
				else if(kostka[i][j][k] < 20) barvy[i][j][k] = 'R'; //red
				else if(kostka[i][j][k] < 30) barvy[i][j][k] = 'B'; //blue
				else if(kostka[i][j][k] < 40) barvy[i][j][k] = 'O'; //orange
				else if(kostka[i][j][k] < 50) barvy[i][j][k] = 'G'; //green
				else if(kostka[i][j][k] < 60) barvy[i][j][k] = 'Y'; //yellow
			}
		}
	}
	printf("Takhle nyni vypada kostka:\n");
	
	//prvni ctvrerec 
	printf("       |%c|%c|%c|\n", barvy[3][4][1], barvy[3][4][2], barvy[3][4][3]);
	printf("       |%c|%c|%c|\n", barvy[2][4][1], barvy[2][4][2], barvy[2][4][3]);
	printf("       |%c|%c|%c|\n", barvy[1][4][1], barvy[1][4][2], barvy[1][4][3]);	
	
	//prostredni prvni radek
	printf("|%c|%c|%c|", barvy[3][3][0], barvy[2][3][0], barvy[1][3][0]);
	printf("|%c|%c|%c|", barvy[0][3][1], barvy[0][3][2], barvy[0][3][3]);
	printf("|%c|%c|%c|", barvy[1][3][4], barvy[2][3][4], barvy[3][3][4]);
	printf("|%c|%c|%c|\n", barvy[4][3][3], barvy[4][3][2], barvy[4][3][1]);
		
	//prostredni druhy radek
	printf("|%c|%c|%c|", barvy[3][2][0], barvy[2][2][0], barvy[1][2][0]);
	printf("|%c|%c|%c|", barvy[0][2][1], barvy[0][2][2], barvy[0][2][3]);
	printf("|%c|%c|%c|", barvy[1][2][4], barvy[2][2][4], barvy[3][2][4]);
	printf("|%c|%c|%c|\n", barvy[4][2][3], barvy[4][2][2], barvy[4][2][1]);
	
	//prostredni treti radek
	printf("|%c|%c|%c|", barvy[3][1][0], barvy[2][1][0], barvy[1][1][0]);
	printf("|%c|%c|%c|", barvy[0][1][1], barvy[0][1][2], barvy[0][1][3]);
	printf("|%c|%c|%c|", barvy[1][1][4], barvy[2][1][4], barvy[3][1][4]);
	printf("|%c|%c|%c|\n", barvy[4][1][3], barvy[4][1][2], barvy[4][1][1]);
	
	//posledni ctverec
	printf("       |%c|%c|%c|\n", barvy[1][0][1], barvy[1][0][2], barvy[1][0][3]);
	printf("       |%c|%c|%c|\n", barvy[2][0][1], barvy[2][0][2], barvy[2][0][3]);
	printf("       |%c|%c|%c|\n\n", barvy[3][0][1], barvy[3][0][2], barvy[3][0][3]);		
}

void tisk(char kostka[5][5][5]){

/*	
*	normalni text = 15
*	blue = 17
*	green = 34
*	red = 204
*	yellow = 237
*	white = 255
*	orange = 102 //try 85 or 221
*/

	unsigned char barvy[5][5][5];
	int i, j, k;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5 ; j++)
		{
			for(k = 0; k < 5; k++)
			{
				if( (kostka[i][j][k] > 0) && (kostka[i][j][k] < 10) ) barvy[i][j][k] = 255;
				else if(kostka[i][j][k] < 20) barvy[i][j][k] = 204;
				else if(kostka[i][j][k] < 30) barvy[i][j][k] = 17;
				else if(kostka[i][j][k] < 40) barvy[i][j][k] = 85;
				else if(kostka[i][j][k] < 50) barvy[i][j][k] = 34;
				else if(kostka[i][j][k] < 60) barvy[i][j][k] = 237;
			}
		}
	}
	printf("Takhle nyni vypada kostka:\n");
	//prvni ctvrerec
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); 
	printf("       |");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[3][4][1]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[3][4][2]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[3][4][3]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|\n");
	
	printf("       |");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[2][4][1]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[2][4][2]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[2][4][3]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|\n");
	
	printf("       |");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[1][4][1]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[1][4][2]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[1][4][3]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|\n");
	
	
	//prostredni prvni radek
	printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[3][3][0]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[2][3][0]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[1][3][0]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	
	printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[0][3][1]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[0][3][2]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[0][3][3]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
		
	printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[1][3][4]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[2][3][4]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[3][3][4]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	
	printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[4][3][3]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[4][3][2]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[4][3][1]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|\n");
	
	
	//prostredni druhy radek
	printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[3][2][0]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[2][2][0]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[1][2][0]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	
	printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[0][2][1]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[0][2][2]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[0][2][3]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	
	printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[1][2][4]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[2][2][4]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[3][2][4]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	
	printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[4][2][3]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[4][2][2]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[4][2][1]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|\n");
	
	
	//prostredni treti radek
	printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[3][1][0]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[2][1][0]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[1][1][0]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	
	printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[0][1][1]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[0][1][2]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[0][1][3]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	
	printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[1][1][4]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[2][1][4]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[3][1][4]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	
	printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[4][1][3]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[4][1][2]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[4][1][1]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|\n");
	
	
	//posledni ctverec
	printf("       |");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[1][0][1]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[1][0][2]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[1][0][3]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|\n");
		
	printf("       |");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[2][0][1]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[2][0][2]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[2][0][3]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|\n");
	
	printf("       |");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[3][0][1]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[3][0][2]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barvy[3][0][3]); printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); printf("|\n\n");
}

void tah(char ch, int kolikrat, char kostka[5][5][5], char vypsat){
	int pom;
	switch(ch)
	{
		case 'R':
			{
				tah_R(kostka, kolikrat);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("R ");
					if(kolikrat == 2) printf("R2 ");
					if(kolikrat == 3) printf("R' ");
				}				
			}
			break;
		case 'U':
			{
				tah_U(kostka, kolikrat);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("U ");
					if(kolikrat == 2) printf("U2 ");
					if(kolikrat == 3) printf("U' ");
				}				
			}
			break;
		case 'L':
			{
				tah_L(kostka, kolikrat);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("L ");
					if(kolikrat == 2) printf("L2 ");
					if(kolikrat == 3) printf("L' ");
				}				
			}
			break;
		case 'D':
			{
				tah_D(kostka, kolikrat);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("D ");
					if(kolikrat == 2) printf("D2 ");
					if(kolikrat == 3) printf("D' ");
				}				
			}
			break;
		case 'F':
			{
				tah_F(kostka, kolikrat);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("F ");
					if(kolikrat == 2) printf("F2 ");
					if(kolikrat == 3) printf("F' ");
				}				
			}
			break;
		case 'B':
			{
				tah_B(kostka, kolikrat);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("B ");
					if(kolikrat == 2) printf("B2 ");
					if(kolikrat == 3) printf("B' ");
				}				
			}
			break;
		case 'M':
			{
				tah_M(kostka, kolikrat);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("M ");
					if(kolikrat == 2) printf("M2 ");
					if(kolikrat == 3) printf("M' ");
				}				
			}
			break;
		case 'S':
			{
				tah_S(kostka, kolikrat);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("S ");
					if(kolikrat == 2) printf("S2 ");
					if(kolikrat == 3) printf("S' ");
				}				
			}
			break;
		case 'E':
			{
				tah_E(kostka, kolikrat);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("E ");
					if(kolikrat == 2) printf("E2 ");
					if(kolikrat == 3) printf("E' ");
				}				
			}
			break;
		case 'r':
			{
				pom = (kolikrat * 3) % 4;
				tah_R(kostka, kolikrat);
				tah_M(kostka, pom);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("r ");
					if(kolikrat == 2) printf("r2 ");
					if(kolikrat == 3) printf("r' ");
				}				
			}
			break;
		case 'u':
			{
				pom = (kolikrat * 3) % 4;
				tah_U(kostka, kolikrat);
				tah_E(kostka, pom);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("u ");
					if(kolikrat == 2) printf("u2 ");
					if(kolikrat == 3) printf("u' ");
				}			
			}
			break;
		case 'l':
			{
				tah_L(kostka, kolikrat);
				tah_M(kostka, kolikrat);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("l ");
					if(kolikrat == 2) printf("l2 ");
					if(kolikrat == 3) printf("l' ");
				}				
			}
			break;
		case 'd':
			{
				tah_D(kostka, kolikrat);
				tah_E(kostka, kolikrat);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("d ");
					if(kolikrat == 2) printf("d2 ");
					if(kolikrat == 3) printf("d' ");
				}				
			}
			break;
		case 'f':
			{
				tah_F(kostka, kolikrat);
				tah_S(kostka, kolikrat);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("f ");
					if(kolikrat == 2) printf("f2 ");
					if(kolikrat == 3) printf("f' ");
				}			
			}
			break;
		case 'b':
			{
				pom = (kolikrat * 3) % 4;
				tah_B(kostka, kolikrat);
				tah_S(kostka, pom);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("b ");
					if(kolikrat == 2) printf("b2 ");
					if(kolikrat == 3) printf("b' ");
				}	
			}
			break;
		case 'x':
			{
				pom = (kolikrat * 3) % 4;
				tah_R(kostka, kolikrat);
				tah_M(kostka, pom);
				tah_L(kostka, pom);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("x ");
					if(kolikrat == 2) printf("x2 ");
					if(kolikrat == 3) printf("x' ");
				}
			}
			break;
		case 'y':
			{
				pom = (kolikrat * 3) % 4;
				tah_U(kostka, kolikrat);
				tah_E(kostka, pom);
				tah_D(kostka, pom);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("y ");
					if(kolikrat == 2) printf("y2 ");
					if(kolikrat == 3) printf("y' ");
				}				
			}
			break;
		case 'z':
			{
				pom = (kolikrat * 3) % 4;
				tah_F(kostka, kolikrat);
				tah_S(kostka, kolikrat);
				tah_B(kostka, pom);
				if(vypsat == 1)
				{
					if(kolikrat == 1) printf("z ");
					if(kolikrat == 2) printf("z2 ");
					if(kolikrat == 3) printf("z' ");
				}
			}
			break;
	}
}

void tah_R(char kostka[5][5][5], int kolikrat){
	int i;
	int pom;
	for(i = 0; i < kolikrat; i++)
	{
		pom = kostka[3][4][3];
		kostka[3][4][3] = kostka[0][3][3];
		kostka[0][3][3] = kostka[1][0][3];
		kostka[1][0][3] = kostka[4][1][3];
		kostka[4][1][3] = pom;
		
		pom = kostka[2][4][3];
		kostka[2][4][3] = kostka[0][2][3];
		kostka[0][2][3] = kostka[2][0][3];
		kostka[2][0][3] = kostka[4][2][3];
		kostka[4][2][3] = pom;
		
		pom = kostka[1][4][3];
		kostka[1][4][3] = kostka[0][1][3];
		kostka[0][1][3] = kostka[3][0][3];
		kostka[3][0][3] = kostka[4][3][3];
		kostka[4][3][3] = pom;
		
		pom = kostka[3][3][4];
		kostka[3][3][4] = kostka[1][3][4];
		kostka[1][3][4] = kostka[1][1][4];
		kostka[1][1][4] = kostka[3][1][4];
		kostka[3][1][4] = pom;
		
		pom = kostka[2][3][4];
		kostka[2][3][4] = kostka[1][2][4];
		kostka[1][2][4] = kostka[2][1][4];
		kostka[2][1][4] = kostka[3][2][4];
		kostka[3][2][4] = pom;
	}
}

void tah_U(char kostka[5][5][5], int kolikrat){
	int i;
	int pom;
	for(i = 0; i < kolikrat; i++)
	{
		pom = kostka[3][4][1];
		kostka[3][4][1] = kostka[3][3][4];
		kostka[3][3][4] = kostka[3][0][3];
		kostka[3][0][3] = kostka[3][1][0];
		kostka[3][1][0] = pom;
		
		pom = kostka[3][4][2];
		kostka[3][4][2] = kostka[3][2][4];
		kostka[3][2][4] = kostka[3][0][2];
		kostka[3][0][2] = kostka[3][2][0];
		kostka[3][2][0] = pom;
		
		pom = kostka[3][4][3];
		kostka[3][4][3] = kostka[3][1][4];
		kostka[3][1][4] = kostka[3][0][1];
		kostka[3][0][1] = kostka[3][3][0];
		kostka[3][3][0] = pom;
		
		pom = kostka[4][3][1];
		kostka[4][3][1] = kostka[4][3][3];
		kostka[4][3][3] = kostka[4][1][3];
		kostka[4][1][3] = kostka[4][1][1];
		kostka[4][1][1] = pom;
		
		pom = kostka[4][3][2];
		kostka[4][3][2] = kostka[4][2][3];
		kostka[4][2][3] = kostka[4][1][2];
		kostka[4][1][2] = kostka[4][2][1];
		kostka[4][2][1] = pom;
	}
}

void tah_L(char kostka[5][5][5], int kolikrat){
	int i;
	int pom;
	for(i = 0; i < kolikrat; i++)
	{
		pom = kostka[3][4][1];
		kostka[3][4][1] = kostka[4][1][1];
		kostka[4][1][1] = kostka[1][0][1];
		kostka[1][0][1] = kostka[0][3][1];
		kostka[0][3][1] = pom;
		
		pom = kostka[2][4][1];
		kostka[2][4][1] = kostka[4][2][1];
		kostka[4][2][1] = kostka[2][0][1];
		kostka[2][0][1] = kostka[0][2][1];
		kostka[0][2][1] = pom;
		
		pom = kostka[1][4][1];
		kostka[1][4][1] = kostka[4][3][1];
		kostka[4][3][1] = kostka[3][0][1];
		kostka[3][0][1] = kostka[0][1][1];
		kostka[0][1][1] = pom;
		
		pom = kostka[3][3][0];
		kostka[3][3][0] = kostka[3][1][0];
		kostka[3][1][0] = kostka[1][1][0];
		kostka[1][1][0] = kostka[1][3][0];
		kostka[1][3][0] = pom;
		
		pom = kostka[2][3][0];
		kostka[2][3][0] = kostka[3][2][0];
		kostka[3][2][0] = kostka[2][1][0];
		kostka[2][1][0] = kostka[1][2][0];
		kostka[1][2][0] = pom;
	}
}

void tah_D(char kostka[5][5][5], int kolikrat){
	int i;
	int pom;
	for(i = 0; i < kolikrat; i++)
	{
		pom = kostka[1][4][1];
		kostka[1][4][1] = kostka[1][1][0];
		kostka[1][1][0] = kostka[1][0][3];
		kostka[1][0][3] = kostka[1][3][4];
		kostka[1][3][4] = pom;
		
		pom = kostka[1][4][2];
		kostka[1][4][2] = kostka[1][2][0];
		kostka[1][2][0] = kostka[1][0][2];
		kostka[1][0][2] = kostka[1][2][4];
		kostka[1][2][4] = pom;
		
		pom = kostka[1][4][3];
		kostka[1][4][3] = kostka[1][3][0];
		kostka[1][3][0] = kostka[1][0][1];
		kostka[1][0][1] = kostka[1][1][4];
		kostka[1][1][4] = pom;
		
		pom = kostka[0][3][1];
		kostka[0][3][1] = kostka[0][1][1];
		kostka[0][1][1] = kostka[0][1][3];
		kostka[0][1][3] = kostka[0][3][3];
		kostka[0][3][3] = pom;
		
		pom = kostka[0][3][2];
		kostka[0][3][2] = kostka[0][2][1];
		kostka[0][2][1] = kostka[0][1][2];
		kostka[0][1][2] = kostka[0][2][3];
		kostka[0][2][3] = pom;
	}
}

void tah_F(char kostka[5][5][5], int kolikrat){
	int i;
	int pom;
	for(i = 0; i < kolikrat; i++)
	{
		pom = kostka[3][3][4];
		kostka[3][3][4] = kostka[4][3][1];
		kostka[4][3][1] = kostka[1][3][0];
		kostka[1][3][0] = kostka[0][3][3];
		kostka[0][3][3] = pom;
		
		pom = kostka[2][3][4];
		kostka[2][3][4] = kostka[4][3][2];
		kostka[4][3][2] = kostka[2][3][0];
		kostka[2][3][0] = kostka[0][3][2];
		kostka[0][3][2] = pom;
		
		pom = kostka[1][3][4];
		kostka[1][3][4] = kostka[4][3][3];
		kostka[4][3][3] = kostka[3][3][0];
		kostka[3][3][0] = kostka[0][3][1];
		kostka[0][3][1] = pom;
		
		pom = kostka[3][4][3];
		kostka[3][4][3] = kostka[3][4][1];
		kostka[3][4][1] = kostka[1][4][1];
		kostka[1][4][1] = kostka[1][4][3];
		kostka[1][4][3] = pom;
		
		pom = kostka[2][4][3];
		kostka[2][4][3] = kostka[3][4][2];
		kostka[3][4][2] = kostka[2][4][1];
		kostka[2][4][1] = kostka[1][4][2];
		kostka[1][4][2] = pom;
	}
}

void tah_B(char kostka[5][5][5], int kolikrat){
	int i;
	int pom;
	for(i = 0; i < kolikrat; i++)
	{
		pom = kostka[3][1][4];
		kostka[3][1][4] = kostka[0][1][3];
		kostka[0][1][3] = kostka[1][1][0];
		kostka[1][1][0] = kostka[4][1][1];
		kostka[4][1][1] = pom;
		
		pom = kostka[2][1][4];
		kostka[2][1][4] = kostka[0][1][2];
		kostka[0][1][2] = kostka[2][1][0];
		kostka[2][1][0] = kostka[4][1][2];
		kostka[4][1][2] = pom;
		
		pom = kostka[1][1][4];
		kostka[1][1][4] = kostka[0][1][1];
		kostka[0][1][1] = kostka[3][1][0];
		kostka[3][1][0] = kostka[4][1][3];
		kostka[4][1][3] = pom;
		
		pom = kostka[3][0][3];
		kostka[3][0][3] = kostka[1][0][3];
		kostka[1][0][3] = kostka[1][0][1];
		kostka[1][0][1] = kostka[3][0][1];
		kostka[3][0][1] = pom;
		
		pom = kostka[3][0][2];
		kostka[3][0][2] = kostka[2][0][3];
		kostka[2][0][3] = kostka[1][0][2];
		kostka[1][0][2] = kostka[2][0][1];
		kostka[2][0][1] = pom;
	}
}

void tah_M(char kostka[5][5][5], int kolikrat){
	int i;
	int pom;
	for(i = 0; i < kolikrat; i++)
	{
		pom = kostka[3][4][2];
		kostka[3][4][2] = kostka[4][1][2];
		kostka[4][1][2] = kostka[1][0][2];
		kostka[1][0][2] = kostka[0][3][2];
		kostka[0][3][2] = pom;
		
		pom = kostka[2][4][2];
		kostka[2][4][2] = kostka[4][2][2];
		kostka[4][2][2] = kostka[2][0][2];
		kostka[2][0][2] = kostka[0][2][2];
		kostka[0][2][2] = pom;
		
		pom = kostka[1][4][2];
		kostka[1][4][2] = kostka[4][3][2];
		kostka[4][3][2] = kostka[3][0][2];
		kostka[3][0][2] = kostka[0][1][2];
		kostka[0][1][2] = pom;
	}
}

void tah_S(char kostka[5][5][5], int kolikrat){
	int i;
	int pom;
	for(i = 0; i < kolikrat; i++)
	{
		pom = kostka[3][2][4];
		kostka[3][2][4] = kostka[4][2][1];
		kostka[4][2][1] = kostka[1][2][0];
		kostka[1][2][0] = kostka[0][2][3];
		kostka[0][2][3] = pom;
		
		pom = kostka[2][2][4];
		kostka[2][2][4] = kostka[4][2][2];
		kostka[4][2][2] = kostka[2][2][0];
		kostka[2][2][0] = kostka[0][2][2];
		kostka[0][2][2] = pom;
		
		pom = kostka[1][2][4];
		kostka[1][2][4] = kostka[4][2][3];
		kostka[4][2][3] = kostka[3][2][0];
		kostka[3][2][0] = kostka[0][2][1];
		kostka[0][2][1] = pom;
	}
}

void tah_E(char kostka[5][5][5], int kolikrat){
	int i;
	int pom;
	for(i = 0; i < kolikrat; i++)
	{
		pom = kostka[2][4][1];
		kostka[2][4][1] = kostka[2][1][0];
		kostka[2][1][0] = kostka[2][0][3];
		kostka[2][0][3] = kostka[2][3][4];
		kostka[2][3][4] = pom;
		
		pom = kostka[2][4][2];
		kostka[2][4][2] = kostka[2][2][0];
		kostka[2][2][0] = kostka[2][0][2];
		kostka[2][0][2] = kostka[2][2][4];
		kostka[2][2][4] = pom;
		
		pom = kostka[2][4][3];
		kostka[2][4][3] = kostka[2][3][0];
		kostka[2][3][0] = kostka[2][0][1];
		kostka[2][0][1] = kostka[2][1][4];
		kostka[2][1][4] = pom;
	}
}

int delejTahDokud(char kostka[5][5][5], char t, char kosticka, char souradnice1, char souradnice2, char souradnice3){
	//vraci pocet tahu t(t je char - oznaceni tahu), ktere je potreba udelat, aby kosticka byla na souradnicich 1, 2, 3
	int i;
	for(i = 0; i <= 3; i++)
	{
		tah(t, i, kostka, 0);
		if(kostka[souradnice1][souradnice2][souradnice3] == kosticka)
		{
			tah(t, (3*i)%4, kostka, 0);
			return i;
		}
		tah(t, (3*i)%4, kostka, 0);
	}
	return -1;
}

souradnice najdiSouradnice(char kostka[5][5][5], char kosticka){ //vraci souradnice kosticky
	souradnice s;
	char i, j, k;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			for(k = 0; k < 5; k++)
			{
				if(kostka[i][j][k] == kosticka)
				{
					s.i = i;
					s.j = j;
					s.k = k;
					return s;
				}
			}
		}
	}
}

char hodnotaHrany(char kostka[5][5][5], char kosticka){ //vraci kosticku, ktera je na stejne hrane jako argument
	switch(kosticka)
	{
		case 1:
			return 13;
			break;
		case 2:
			return 23;
			break;
		case 3:
			return 33;
			break;
		case 4:
			return 43;
			break;
		case 13:
			return 1;
			break;
		case 23:
			return 2;
			break;
		case 33:
			return 3;
			break;
		case 43:
			return 4;
			break;
		case 12:
			return 44;
			break;
		case 44:
			return 12;
			break;
		case 14:
			return 22;
			break;
		case 22:
			return 14;
			break;
		case 24:
			return 32;
			break;
		case 32:
			return 24;
			break;
		case 42:
			return 34;
			break;
		case 34:
			return 42;
			break;
		case 51:
			return 11;
			break;
		case 52:
			return 21;
			break;
		case 53:
			return 31;
			break;
		case 54:
			return 41;
			break;
		case 11:
			return 51;
			break;
		case 21:
			return 52;
			break;
		case 31:
			return 53;
			break;
		case 41:
			return 54;
			break;
	}
	printf("chyba hodnota hrany");
	return 0;
}

void uvodniRecicky(){
	printf("Vitej v programu na skladani Rubikovy kostky Rubix.\n\n");
	printf("Doporucuju si nejdriv precist dokumenty Notace, kde je popsane znaceni tahu,\n");
	printf("a Navod, kde je navod na skladani Rubikovky.\n\n");
	printf("Tomuto programu muzes bud zadat scramble (= sled tahu, kterymi se kostka rozlozi),\n");
	printf("nebo si nechat nejaky vygenerovat. Program pote vypise reseni postupne po krocich;\n");
	printf("reseni bude velice podobne reseni pomoci zacatecnicke metody. Program bude take\n");
	printf("prubezne vypisovat stav Rubikovky pomoci site krychle, takze muzes kontrolovat,\n");
	printf("zda mas svoji Rubikovku ve stejnem stavu jako pocitac. Doporucuju se orientovat\n");
	printf("podle barvy ve stredech jednotlivych stran, protoze ty maji vzdy stejnou polohu vuci\n");
	printf("sobe. Z technickych duvodu jsem musel nahradit oranzovou barvu barvou fialovou.\n");
	printf("Pri rozkladani kostky ji drz tak, ze budes mit oranzovy stred pred sebou a bily dole.\n");
	printf("Zavorky slouzi jako logicke oddeleni jednotlivych casti daneho algoritmu.\n");
	printf("V pripade, ze najdes nejaky bug, zkopiruj vygenerovany/precteny scramble a posli mi ho\n");
	printf("na mail DWaloszek@seznam.cz; pripadne ten bug nejak popis.\n\n");
}

void generateRandomMoves(char kostka[5][5][5], int delka){
	srand(time(NULL));
	int smer;
	int minuly1 = 0;
	int minuly2 = 0;
	
	int pocet;
	int i;
	char ch;
	printf("Byl vygenerovan tento scramble:\n");
	for(i = 1; i <= delka; i++)
	{
		smer = rand() %6 + 1;
		while( (smer == minuly1) || (smer == minuly2) )
		{
			smer = rand() %6 + 1;
		}
		pocet = rand() %3 + 1;
		switch(smer)
		{
			case 1: ch = 'R';
				break;
			case 2: ch = 'U';					
				break;
			case 3: ch = 'F';
				break;
			case 4: ch = 'L';					
				break;
			case 5: ch = 'D';					
				break;	
			case 6: ch = 'B';
				break;
		}
		tah(ch, pocet, kostka, 1);

		if((smer + 3)%6 == minuly1) minuly2 = minuly1; //zabranuje se tomu, aby byla sekvence U R U nebo B F B apod.
		else minuly2 = 0;
		
		minuly1 = smer;
	}	
	printf("\n");
	tisk(kostka);
}

void prectiScramble(char kostka[5][5][5]){
	char scramble[201];
	char prvni = '0';
	char nacteny;
	int i;
	
	printf("Napis scramble. Program cte pouze znaky R U L D F B 2 ', takze mozne tahy jsou:\n");
	printf("R, R2, R', U, U2, U', L, L2, L', D, D2, D', F, F2, F', B, B2 a B'.\n");
	scanf(" %200[^\n]s", scramble);
	printf("Precetl jsem nasledujici scramble:\n");
	for(i = 0; i < strlen(scramble); i++)
	{
		nacteny = scramble[i];
		switch(nacteny)
		{
			case 'R':
				{
					if(prvni == '0') prvni = 'R';
					else
					{
						tah(prvni, 1, kostka, 1);
						prvni = 'R';
					}
				}
				break;
			case 'U':
				{
					if(prvni == '0') prvni = 'U';
					else
					{
						tah(prvni, 1, kostka, 1);
						prvni = 'U';
					}
				}
				break;
			case 'L':
				{
					if(prvni == '0') prvni = 'L';
					else
					{
						tah(prvni, 1, kostka, 1);
						prvni = 'L';
					}
				}
				break;	
			case 'D':
				{
					if(prvni == '0') prvni = 'D';
					else
					{
						tah(prvni, 1, kostka, 1);
						prvni = 'D';
					}
				}
				break;
			case 'F':
				{
					if(prvni == '0') prvni = 'F';
					else
					{
						tah(prvni, 1, kostka, 1);
						prvni = 'F';
					}
				}
				break;
			case 'B':
				{
					if(prvni == '0') prvni = 'B';
					else
					{
						tah(prvni, 1, kostka, 1);
						prvni = 'B';
					}
				}
				break;
			case '2':
				{
					if(prvni != '0')
					{
						tah(prvni, 2, kostka, 1);
						prvni = '0';
					}
				}
			case 39:
				{
					if(prvni != '0')
					{
						tah(prvni, 3, kostka, 1);
						prvni = '0';
					}
				}
				
		}
	}
	if(prvni != '0') tah(prvni, 1, kostka, 1);
	printf("\n");
	tisk(kostka);
}

void zacatek(char kostka[5][5][5]){
	int x = 0;
	printf("Pokud si chces nechat vygenerovat scramble, zadej 1\n");
	printf("Pokud chces zadat scramble rucne, zadej 2\n");
	scanf("%d", &x);
	if(x == 1)
	{
		int delka = 0;
		printf("Zadej delku scramble (standardne kolem 20-30): ");
		scanf("%d", &delka);
		generateRandomMoves(kostka, delka);
	}
	else if(x == 2)
	{
		prectiScramble(kostka);
	}
	else
	{
		printf("Zadal jsi spatne cislo, zadej znovu.\n");
		zacatek(kostka);
	}
}

void tiskBarvyDilku(char kosticka){ //vytiskne barvy celeho dilku, at uzivatel vi, ktery roh/hrana se prave vklada
	switch(kosticka)
	{
		case 1:
			printf("Bilo-cervena hrana:\n");
			break;
		case 2:
			printf("Bilo-modra hrana:\n");
			break;
		case 3:
			printf("Bilo-oranzova hrana:\n");
			break;
		case 4:
			printf("Bilo-zelena hrana:\n");
			break;
		case 6:
			printf("Bilo-cerveno-zeleny roh:\n");
			break;
		case 7:
			printf("Bilo-modro-cerveny roh:\n");
			break;
		case 8:
			printf("Bilo-oranzovo-modry roh:\n");
			break;
		case 9:
			printf("Bilo-zeleno-oranzovy roh:\n");
			break;
		case 12:
			printf("Cerveno-zelena hrana:\n");
			break;
		case 44:
			printf("Cerveno-zelena hrana:\n");
			break;
		case 22:
			printf("Modro-cervena hrana:\n");
			break;
		case 14:
			printf("Modro-cervena hrana:\n");
			break;
		case 32:
			printf("Oranzovo-modra hrana:\n");
			break;
		case 24:
			printf("Oranzovo-modra hrana:\n");
			break;
		case 42:
			printf("Zeleno-oranzova hrana:\n");
			break;
		case 34:
			printf("Zeleno-oranzova hrana:\n");
			break;
	}
}

int slozKriz(char kostka[5][5][5]){
	char flag[5] = {0, 0, 0, 0, 0};
	char i, j, k;
	char kosticka1;
	char kosticka2;
	char kosticka3;
	int pom;
	int pom2;
	int pocety = 0;
	int token;
	souradnice s1;
	souradnice s2;
	
	printf("Slozeni krize:\n");
	//posunuti prvni dobre hrany na bile stene
	for(i = 1; i <= 3; i++)
		for(j = 1; j <= 3; j++)
		{
			if((kostka[0][i][j] > 0) && (kostka[0][i][j] < 5))
			{
				kosticka1 = hodnotaHrany(kostka, kostka[0][i][j]); //vraci cislo kosticky druhe barvy nez je bila
				s1 = najdiSouradnice(kostka, kosticka1 + 2); //najde souradnice stredu barvy jako kosticka1
				pom = delejTahDokud(kostka, 'D', kosticka1, 1, s1.j, s1.k); //kolikrat tah D dokud kosticka1 sousedi se stredem
				if(pom != 0) tiskBarvyDilku(kostka[0][i][j]);
				tah('D', pom, kostka, 1); //samotny tah D
				i = j = 5; //vyskoceni z cyklu
				if(kostka[0][1][2] == 1) flag[1] = 1;	
				if(kostka[0][2][3] == 2) flag[2] = 1;
				if(kostka[0][3][2] == 3) flag[3] = 1;
				if(kostka[0][2][1] == 4) flag[4] = 1;
				if(pom != 0)
				{
					printf("\n");
				}				
				break;
			}
		}
	
	if(kostka[0][1][2] == 1) flag[1] = 1;	
	if(kostka[0][2][3] == 2) flag[2] = 1;
	if(kostka[0][3][2] == 3) flag[3] = 1;
	if(kostka[0][2][1] == 4) flag[4] = 1;

	//vymenovani spatne umistenych hran na bile stene
	for(i = 1; i <= 3; i++)
	{
		for(j = 1; j <= 3; j++)
		{
			while( (kostka[0][i][j] > 0) && (kostka[0][i][j] < 5) && (flag[kostka[0][i][j]] == 0) )
			{
				tiskBarvyDilku(kostka[0][i][j]);
				kosticka1 = hodnotaHrany(kostka, kostka[0][i][j]);
				tah('y', (pocety % 4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byla jako predtim
				
				pom = delejTahDokud(kostka, 'y', kosticka1, 1, 4, 2);
				tah('y', pom, kostka, 1); pocety += pom;
				tah('F', 2, kostka, 1);
				
				pom = delejTahDokud(kostka, 'y', kosticka1 + 2, 2, 4, 2);
				tah('y', pom, kostka, 1); pocety += pom;
				tah('U', ((pom*3)%4), kostka, 1);
				
				tah('F', 2, kostka, 1);	
				
				pocety = pocety % 4;
				tah('y', ((pocety*3)%4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byly stredy v puvodni sestave
								
				if(kostka[0][1][2] == 1) flag[1] = 1;	
				if(kostka[0][2][3] == 2) flag[2] = 1;
				if(kostka[0][3][2] == 3) flag[3] = 1;
				if(kostka[0][2][1] == 4) flag[4] = 1;
				printf("\n");
			}
		}
	}
		
	while ( !( (flag[1] == 1) && (flag[2] == 1) && (flag[3] == 1) && (flag[4] == 1) ) ) //dokud vsude neni bila spravne
	{ 
	//vkladani hran z horni vrstvy
	for(i = 1; i <= 3; i++)
	{
		for(j = 1; j <= 3; j++)
		{
			while( (kostka[4][i][j] > 0) && (kostka[4][i][j] < 5) )
			{
				tiskBarvyDilku(kostka[4][i][j]);
				kosticka1 = hodnotaHrany(kostka, kostka[4][i][j]); //cislo kosticky jine barvy nez je bila
					
				tah('y', (pocety % 4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byla jako predtim
					
				pom = delejTahDokud(kostka, 'y', kosticka1 + 2, 2, 4, 2); //kolikrat otocit kostku, nez bude spravny stred pred nami
				tah('y', pom, kostka, 1); pocety += pom; //provest tah, zvysit pocety
				pom = delejTahDokud(kostka, 'U', kosticka1, 3, 4, 2); //kolikrat udelat U, aby bilo-neco hrana sousedila se stredem
				tah('U', pom, kostka, 1); //provest tah
				tah('F', 2, kostka, 1);	//vlozit hranu	
					
				pocety = pocety % 4;
				tah('y', ((pocety*3)%4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byly stredy v puvodni sestave
						
				if(kostka[0][1][2] == 1) flag[1] = 1;	
				if(kostka[0][2][3] == 2) flag[2] = 1;
				if(kostka[0][3][2] == 3) flag[3] = 1;
				if(kostka[0][2][1] == 4) flag[4] = 1;
				printf("\n");
			}
		}
	}
	//vkladani hran z prostredni vrstvy
	for(i = 0; i <= 4; i++)
	{
		for(j = 0; j <= 4; j++)
		{
			while( (kostka[2][i][j] > 0) && (kostka[2][i][j] < 5) )	
			{
				tiskBarvyDilku(kostka[2][i][j]);
				kosticka1 = hodnotaHrany(kostka, kostka[2][i][j]); //cislo kosticky jine barvy nez je bila
					
				tah('y', (pocety % 4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byla jako predtim
					
				pom = delejTahDokud(kostka, 'y', kosticka1, 2, 4, 1);	
				if (pom == -1) pom = delejTahDokud(kostka, 'y', kosticka1, 2, 4, 3);
				tah('y', pom, kostka, 1); pocety += pom; //provest tah, zvysit pocety
				
				s1 = najdiSouradnice(kostka, kosticka1 + 2);
				kosticka2 = kostka[1][s1.j][s1.k];
				
				pom = delejTahDokud(kostka, 'D', kosticka2, 1, 4, 2); //kolikrat tah D nez bude uvolneny sravny slot
				tah('D', pom, kostka, 1);
				pom2 = delejTahDokud(kostka, 'F', kosticka1, 1, 4, 2); //vsune pozadovanou hranu dolu
				tah('F', pom2, kostka, 1);
				tah('D', ((pom*3)%4) , kostka, 1); //posune D zpatky
				
									
				pocety = pocety % 4;
				tah('y', ((pocety*3)%4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byly stredy v puvodni sestave
						
				if(kostka[0][1][2] == 1) flag[1] = 1;	
				if(kostka[0][2][3] == 2) flag[2] = 1;
				if(kostka[0][3][2] == 3) flag[3] = 1;
				if(kostka[0][2][1] == 4) flag[4] = 1;
				printf("\n");
			}
		}
	}
		
	//vkladani hran z 1. a 3. vrstvy	
	for(i = 1; i <= 3; i += 2)
	{
		for(j = 0; j <= 4; j += 2)
		{
			for(k = 0; k <= 4; k += 2)
			{
				while( (kostka[i][j][k] > 0) && (kostka[i][j][k] < 5) )	
				{
					tiskBarvyDilku(kostka[i][j][k]);
					kosticka1 = hodnotaHrany(kostka, kostka[i][j][k]); //cislo kosticky jine barvy nez je bila
					token = 0; //token bude slouzit k zapamatovani si, kolikrat otocit F zpatky, abych si nic nerozbil
						
					tah('y', (pocety % 4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byla jako predtim	
					
					kosticka3 = kosticka1 + 2; //kosticka3 pro praci pri zjisteni, ze stred spravne barvy je nalevo
					
					pom = delejTahDokud(kostka, 'y', kosticka1, 0, 3, 2);	
					if (pom != -1)
					{
						tah('y', pom, kostka, 1); pocety += pom; //provest tah, zvysit pocety
						if(kostka[2][2][0] == kosticka3) tah('F', 1, kostka, 1); //pokud stred spravne barvy je nalevo
						else tah('F', 3, kostka, 1);						
					}
					else
					{
						pom = delejTahDokud(kostka, 'y', kosticka1, 4, 3, 2);
						tah('y', pom, kostka, 1); pocety += pom;
						if( (kostka[0][3][2] > 0) && (kostka[0][3][2] < 5)) token = 3; //pokud dole uz je bila hrana, token pro zachovani
						if(kostka[2][2][0] == kosticka3) tah('F', 3, kostka, 1); //pokud stred spravne barvy je nalevo
						else tah('F', 1, kostka, 1);
					}

					if(kostka[2][2][0] == kosticka3) //pokud stred spravne barvy je nalevo
					{
						tah('L', 1, kostka, 1);
						if(token == 3) tah('F', 1, kostka, 1); //pokud jsme vyhodili hranu ze spravneho mista, napravime to
					}
					else //ve vsech ostatnich pripadech
					{
						s1 = najdiSouradnice(kostka, kosticka1 + 2);
						kosticka2 = kostka[1][s1.j][s1.k];
						
						pom = delejTahDokud(kostka, 'D', kosticka2, 1, 2, 4); //kolikrat tah D nez bude uvolneny sravny slot
						tah('D', pom, kostka, 1);
						pom2 = delejTahDokud(kostka, 'R', kosticka1, 1, 2, 4); //vsune pozadovanou hranu dolu
						tah('R', pom2, kostka, 1);
						tah('D', ((pom*3)%4) , kostka, 1); //posune D zpatky
						tah('F', token, kostka, 1);			
					}
													
					pocety = pocety % 4;
					tah('y', ((pocety*3)%4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byly stredy v puvodni sestave
							
					if(kostka[0][1][2] == 1) flag[1] = 1;	
					if(kostka[0][2][3] == 2) flag[2] = 1;
					if(kostka[0][3][2] == 3) flag[3] = 1;
					if(kostka[0][2][1] == 4) flag[4] = 1;
					printf("\n");
				}
			}
		}
	}	
		
	} //tohle patri while cyklu :D
	
	tah('y', (pocety % 4), kostka, 0);
	tisk(kostka);
	tah('y', ((pocety*3)%4), kostka, 0);	
	return pocety;
}

int vlozRohy(char kostka[5][5][5], int pocety){
	char flag[5] = {0, 0, 0, 0, 0};
	char i, j, k;
	char kosticka1;
	char kosticka2;
	int pom;
	int pom2;
	int token;
	
	if(kostka[0][1][1] == 6) flag[1] = 1;	
	if(kostka[0][1][3] == 7) flag[2] = 1;
	if(kostka[0][3][3] == 8) flag[3] = 1;
	if(kostka[0][3][1] == 9) flag[4] = 1;
	
	printf("Vkladam rohy:\n");
	
	while ( !( (flag[1] == 1) && (flag[2] == 1) && (flag[3] == 1) && (flag[4] == 1) ) ) //dokud vsude neni bila spravne
	{
	//rohy s bilym z 3. vrstvy	
	for(i = 0; i <= 4; i++)
	{
		for(j = 0; j <= 4; j++)
		{		
			while( (kostka[3][i][j] > 5) && (kostka[3][i][j] < 10) )	
			{
				kosticka1 = kostka[3][i][j]; //cislo bile kosticky
				tiskBarvyDilku(kosticka1);
				
				ROHY: //tady je to za prirazenim kosticky, tudiz se pracuje s kostickou z mista pred goto
				tah('y', (pocety % 4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byla jako predtim
				
				pom = delejTahDokud(kostka, 'y', kosticka1, 3, 4, 1);	
				if (pom != -1)
				{
					tah('y', pom, kostka, 0); //silent tah y pro otoceni k hledanemu rohu
					kosticka2 = kostka[4][3][1]; //melo by to byt *9
					tah('y', ((pom*3)%4), kostka, 0); //silent tah y' pro vraceni
					token = pom; //token k tomu, abychom vedeli, kolikrat navic otocit U
					
					pom2 = delejTahDokud(kostka, 'y', kosticka2 - 4, 2, 4, 2); //kolikrat y, aby byl pred nami stred barvy, u bile je nahore
					tah('y', pom2, kostka, 1); pocety += pom2; //provest tah, zvysit pocety
					tah('U', ((pom2*3 + token)%4), kostka, 1);
					
					printf("(");
					tah('U', 3, kostka, 1);		
					tah('L', 3, kostka, 1);
					tah('U', 1, kostka, 1);	
					tah('L', 1, kostka, 0);	//silent L kvuli mezere pred zavorkou
					printf("L) ");							
				}
				else
				{
					pom = delejTahDokud(kostka, 'y', kosticka1, 3, 4, 3);
					
					tah('y', pom, kostka, 0); //silent tah y pro otoceni k hledanemu rohu
					kosticka2 = kostka[4][3][3]; //melo by to byt *8
					tah('y', ((pom*3)%4) , kostka, 0); //silent tah y' pro vraceni
					token = pom; //token k tomu, abychom vedeli, kolikrat navic otocit U
					
					pom2 = delejTahDokud(kostka, 'y', kosticka2 - 3, 2, 4, 2); //kolikrat y, aby byl pred nami stred barvy, u bile je nahore
					tah('y', pom2, kostka, 1); pocety += pom2; //provest tah, zvysit pocety
					tah('U', ((pom2*3 + token)%4), kostka, 1);
					
					printf("(");
					tah('U', 1, kostka, 1);		
					tah('R', 1, kostka, 1);
					tah('U', 3, kostka, 1);	
					tah('R', 3, kostka, 0);	//silent R' kvuli mezere pred zavorkou
					printf("R') ");
				}	
										
				pocety = pocety % 4;
				tah('y', ((pocety*3)%4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byly stredy v puvodni sestave
							
				if(kostka[0][1][1] == 6) flag[1] = 1;	
				if(kostka[0][1][3] == 7) flag[2] = 1;
				if(kostka[0][3][3] == 8) flag[3] = 1;
				if(kostka[0][3][1] == 9) flag[4] = 1;
				printf("\n");
			}
		}
	}
	
	//rohy s bilym z zlute strany	
	for(i = 1; i <= 3; i += 2)
	{
		for(j = 1; j <= 3; j += 2)
		{
			while( (kostka[4][i][j] > 5) && (kostka[4][i][j] < 10) )	
			{
				kosticka1 = kostka[4][i][j]; //cislo bile kosticky
				tiskBarvyDilku(kosticka1);
				tah('y', (pocety % 4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byla jako predtim
				
				pom = delejTahDokud(kostka, 'y', kosticka1, 4, 3, 3);	
			
				tah('y', pom, kostka, 0); //silent tah y pro otoceni k hledanemu rohu
				kosticka2 = kostka[3][3][4]; //melo by to byt *8
				tah('y', ((pom*3)%4), kostka, 0); //silent tah y' pro vraceni
				token = pom; //token k tomu, abychom vedeli, kolikrat navic otocit U
					
				pom2 = delejTahDokud(kostka, 'y', kosticka2 - 3, 2, 4, 2); //kolikrat y, aby byl pred nami stred barvy, u bile je nahore
				tah('y', pom2, kostka, 1); pocety += pom2; //provest tah, zvysit pocety
				tah('U', ((pom2*3 + token)%4), kostka, 1);
								
				printf("(");
				tah('U', 1, kostka, 1);
				tah('R', 1, kostka, 1);
				tah('U', 2, kostka, 1);
				tah('R', 3, kostka, 0); //silent R' kvuli mezere pred zavorkou
				printf("R') (");
				tah('U', 1, kostka, 1);
				tah('R', 1, kostka, 1);
				tah('U', 3, kostka, 1);
				tah('R', 3, kostka, 0); //silent R' kvuli mezere pred zavorkou
				printf("R') ");
				
				pocety = pocety % 4;
				tah('y', ((pocety*3)%4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byly stredy v puvodni sestave
							
				if(kostka[0][1][1] == 6) flag[1] = 1;	
				if(kostka[0][1][3] == 7) flag[2] = 1;
				if(kostka[0][3][3] == 8) flag[3] = 1;
				if(kostka[0][3][1] == 9) flag[4] = 1;
				printf("\n");
			}
		}
	}
	//rohy z 1. vrstvy
	for(i = 0; i <= 4; i++)
	{
		for(j = 0; j <= 4; j++)
		{
			while( (kostka[1][i][j] > 5) && (kostka[1][i][j] < 10) )	
			{
				kosticka1 = kostka[1][i][j]; //cislo bile kosticky
				tiskBarvyDilku(kosticka1);
				tah('y', (pocety % 4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byla jako predtim
				
				pom = delejTahDokud(kostka, 'y', kosticka1, 1, 4, 3);	
				if (pom != -1)
				{
					tah('y', pom, kostka, 1); pocety += pom; //provest tah, zvysit pocety
					
					printf("(");
					tah('R', 1, kostka, 1);
					tah('U', 3, kostka, 1);
					tah('R', 3, kostka, 0);	//silent R' kvuli mezere pred zavorkou
					printf("R') ");
				}
				else
				{
					pom = delejTahDokud(kostka, 'y', kosticka1, 1, 3, 4);
					tah('y', pom, kostka, 1); pocety += pom; //provest tah, zvysit pocety
					
					printf("(");
					tah('R', 1, kostka, 1);
					tah('U', 1, kostka, 1);
					tah('R', 3, kostka, 0); //silent R' kvuli mezere pred zavorkou
					printf("R') ");
				}
					
				pocety = pocety % 4;
				tah('y', ((pocety*3)%4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byly stredy v puvodni sestave
							
				if(kostka[0][1][1] == 6) flag[1] = 1;	
				if(kostka[0][1][3] == 7) flag[2] = 1;
				if(kostka[0][3][3] == 8) flag[3] = 1;
				if(kostka[0][3][1] == 9) flag[4] = 1;
				
				goto ROHY; //goto misto, kde to neni na zacatku cyklu, ale za prirazenim kosticka1
			}
		}
	}
	
	//rohy ze spodni (bile) strany
	for(i = 1; i <= 3; i += 2)
	{
		for(j = 1; j <= 3; j += 2)
		{
			while( (kostka[0][i][j] > 5) && (kostka[0][i][j] < 10) && (flag[kostka[0][i][j] - 5] == 0) )	
			{
				kosticka1 = kostka[0][i][j]; //cislo bile kosticky
				tiskBarvyDilku(kosticka1);
				tah('y', (pocety % 4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byla jako predtim
				
				pom = delejTahDokud(kostka, 'y', kosticka1, 0, 3, 3);		
				tah('y', pom, kostka, 1); pocety += pom; //provest tah, zvysit pocety
					
				printf("(");	
				tah('R', 1, kostka, 1);
				tah('U', 1, kostka, 1);
				tah('R', 3, kostka, 0);	//silent R' kvuli mezere pred zavorkou
				printf("R') ");			
											
				pocety = pocety % 4;
				tah('y', ((pocety*3)%4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byly stredy v puvodni sestave
							
				if(kostka[0][1][1] == 6) flag[1] = 1;	
				if(kostka[0][1][3] == 7) flag[2] = 1;
				if(kostka[0][3][3] == 8) flag[3] = 1;
				if(kostka[0][3][1] == 9) flag[4] = 1;
			
				goto ROHY;
			}
		}
	}
	
	}//tady konci while cyklus
	
	tah('y', (pocety % 4), kostka, 0);
	tisk(kostka);
	tah('y', ((pocety*3)%4), kostka, 0);
	return pocety;
}

int vlozHrany(char kostka[5][5][5], int pocety){
	char flag[45];
	flag[12] = 0;
	flag[14] = 0;
	flag[22] = 0;
	flag[24] = 0;
	flag[32] = 0;
	flag[34] = 0;
	flag[42] = 0;
	flag[44] = 0;
	flag[5] = 0;
	char i, j, k;
	char kosticka1;
	char kosticka2;
	int pom;
	int pom2;
	souradnice s1;
	
	if(kostka[2][0][1] == 12) flag[12] = 1;
	if(kostka[2][0][3] == 14) flag[14] = 1;	
	if(kostka[2][1][4] == 22) flag[22] = 1;
	if(kostka[2][3][4] == 24) flag[24] = 1;
	if(kostka[2][4][3] == 32) flag[32] = 1;
	if(kostka[2][4][1] == 34) flag[34] = 1;
	if(kostka[2][3][0] == 42) flag[42] = 1;
	if(kostka[2][1][0] == 44) flag[44] = 1;
	if( ((kostka[3][0][2] % 10 == 1) || (kostka[3][0][2] > 50)) && ((kostka[3][2][4] % 10 == 1) || (kostka[3][2][4] > 50)) && ((kostka[3][4][2] % 10 == 1) || (kostka[3][4][2] > 50)) && ((kostka[3][2][0] % 10 == 1) || (kostka[3][2][0] > 50)) )
	{
		flag[5] = 1; //pokud je ve 3. vrstve nebo horni strane zluta, flag[5] = 1
	}
	else flag[5] = 0;
	
	printf("Vkladam hrany:\n");
	while((flag[12] + flag[14] + flag[22] + flag[24] + flag[32] + flag[34] + flag[42] + flag[44]) < 8)
	{
	//hrany, co nejsou spatne vlozene
	while(flag[5] == 0)
	{
	for(i = 0; i <= 4; i += 2)
	{
		for(j = 0; j <= 4; j += 2)
		{	
			if( ( (kostka[3][i][j] % 10 == 4) || (kostka[3][i][j] % 10 == 2) ) && (kostka[3][i][j] < 50) )
			{
				kosticka1 = kostka[3][i][j]; //cislo vkladane kosticky
				tiskBarvyDilku(kosticka1); //je to pred HRANY, aby se to nevypisovalo 2x
			}	
			HRANY: //prikaz goto HRANY je uz s prirazenymi i, j a kosticka1 dane kosticky
			if( (kostka[3][i][j] % 10 == 4) && (kostka[3][i][j] < 50) )
			{
				kosticka2 = kosticka1 + 1; //cislo stredu stejne barvy jako kosticka1
				tah('y', (pocety % 4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byla jako predtim
				
				pom = delejTahDokud(kostka, 'y', kosticka2, 2, 4, 2); //tah y dokud spravny stred pred nami
				tah('y', pom, kostka, 1); pocety += pom; //provest tah, zvysit pocety
				pom2 = delejTahDokud(kostka, 'U', kosticka1, 3, 4, 2); //tah U dokud kosticka1 neladi se stredem
				tah('U', pom2, kostka, 1);
				
				printf("(");
				tah('U', 3, kostka, 1);		
				tah('L', 3, kostka, 1);
				tah('U', 1, kostka, 1);	
				tah('L', 1, kostka, 0); //silent L kvuli mezere pred zavorkou	
				printf("L) ");
				tah('y', 3, kostka, 1); pocety += 3;
				printf("(");
				tah('U', 1, kostka, 1);		
				tah('R', 1, kostka, 1);
				tah('U', 3, kostka, 1);	
				tah('R', 3, kostka, 0);	//silent R' kvuli mezere pred zavorkou
				printf("R')");
				printf("\n");
				
				pocety = pocety % 4;
				tah('y', ((pocety*3)%4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byly stredy v puvodni sestave
							
				if(kostka[2][0][1] == 12) flag[12] = 1;
				if(kostka[2][0][3] == 14) flag[14] = 1;	
				if(kostka[2][1][4] == 22) flag[22] = 1;
				if(kostka[2][3][4] == 24) flag[24] = 1;
				if(kostka[2][4][3] == 32) flag[32] = 1;
				if(kostka[2][4][1] == 34) flag[34] = 1;
				if(kostka[2][3][0] == 42) flag[42] = 1;
				if(kostka[2][1][0] == 44) flag[44] = 1;
				
				if( ((kostka[3][0][2] % 10 == 1) || (kostka[3][0][2] > 50)) && ((kostka[3][2][4] % 10 == 1) || (kostka[3][2][4] > 50)) && ((kostka[3][4][2] % 10 == 1) || (kostka[3][4][2] > 50)) && ((kostka[3][2][0] % 10 == 1) || (kostka[3][2][0] > 50)) )
				{
					flag[5] = 1; //pokud je ve 3. vrstve nebo horni strane zluta, flag[5] = 1
				}
				else flag[5] = 0;
			}
			
			else if( (kostka[3][i][j] % 10 == 2) && (kostka[3][i][j] < 50) )
			{
				kosticka2 = kosticka1 + 3; //cislo stredu stejne barvy jako kosticka1
				tah('y', (pocety % 4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byla jako predtim
				
				pom = delejTahDokud(kostka, 'y', kosticka2, 2, 4, 2); //tah y dokud spravny stred pred nami
				tah('y', pom, kostka, 1); pocety += pom; //provest tah, zvysit pocety
				pom2 = delejTahDokud(kostka, 'U', kosticka1, 3, 4, 2); //tah U dokud kosticka1 neladi se stredem
				tah('U', pom2, kostka, 1);
				
				printf("(");
				tah('U', 1, kostka, 1);		
				tah('R', 1, kostka, 1);
				tah('U', 3, kostka, 1);	
				tah('R', 3, kostka, 0);	//silent R' kvuli mezere pred zavorkou
				printf("R') ");
				tah('y', 1, kostka, 1); pocety += 1;
				printf("(");
				tah('U', 3, kostka, 1);		
				tah('L', 3, kostka, 1);
				tah('U', 1, kostka, 1);	
				tah('L', 1, kostka, 0); //silent L kvuli mezere pred zavorkou
				printf("L) ");
				printf("\n");
				
				pocety = pocety % 4;
				tah('y', ((pocety*3)%4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byly stredy v puvodni sestave
							
				if(kostka[2][0][1] == 12) flag[12] = 1;
				if(kostka[2][0][3] == 14) flag[14] = 1;	
				if(kostka[2][1][4] == 22) flag[22] = 1;
				if(kostka[2][3][4] == 24) flag[24] = 1;
				if(kostka[2][4][3] == 32) flag[32] = 1;
				if(kostka[2][4][1] == 34) flag[34] = 1;
				if(kostka[2][3][0] == 42) flag[42] = 1;
				if(kostka[2][1][0] == 44) flag[44] = 1;
					
				if( ((kostka[3][0][2] % 10 == 1) || (kostka[3][0][2] > 50)) && ((kostka[3][2][4] % 10 == 1) || (kostka[3][2][4] > 50)) && ((kostka[3][4][2] % 10 == 1) || (kostka[3][4][2] > 50)) && ((kostka[3][2][0] % 10 == 1) || (kostka[3][2][0] > 50)) )
				{
					flag[5] = 1; //pokud je ve 3. vrstve nebo horni strane zluta, flag[5] = 1
				}
				else flag[5] = 0;
			}
		}
	}
	} //konec while cyklu s podminkou flag[5] == 0
	
	//hrany, co jsou spatne vlozene
	for(i = 0; i <= 4; i++)
	{
		for(j = 0; j <= 4; j++)
		{	
			while( ( (kostka[2][i][j] % 10 == 4) || (kostka[2][i][j] % 10 == 2) )  && (kostka[2][i][j] < 50) && (flag[kostka[2][i][j]] == 0) )
			{
				kosticka1 = kostka[2][i][j];
				tiskBarvyDilku(kosticka1);
				tah('y', (pocety % 4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byla jako predtim	
					
				pom = delejTahDokud(kostka, 'y', kosticka1, 2, 3, 4);
				if(pom == -1)
				{
					kosticka1 = hodnotaHrany(kostka, kosticka1); //zkusime tu druouhou barvu, ta by mela jet
					pom = delejTahDokud(kostka, 'y', kosticka1, 2, 3, 4);
					if(pom == -1) printf("chyba ;(\n");
				}
				tah('y', pom, kostka, 1); pocety += pom; //provest tah, zvysit pocety
				
				printf("(");	
				tah('U', 1, kostka, 1);		
				tah('R', 1, kostka, 1);
				tah('U', 3, kostka, 1);	
				tah('R', 3, kostka, 0);	//silent R' kvuli mezere pred zavorkou
				printf("R') ");
				tah('y', 1, kostka, 1); pocety += 1;
				printf("(");
				tah('U', 3, kostka, 1);		
				tah('L', 3, kostka, 1);
				tah('U', 1, kostka, 1);	
				tah('L', 1, kostka, 0); //silent L kvuli mezere pred zavorkou
				printf("L) ");
				printf("\n");
				
				pocety = pocety % 4;
				tah('y', ((pocety*3)%4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byly stredy v puvodni sestave
							
				if(kostka[2][0][1] == 12) flag[12] = 1;
				if(kostka[2][0][3] == 14) flag[14] = 1;	
				if(kostka[2][1][4] == 22) flag[22] = 1;
				if(kostka[2][3][4] == 24) flag[24] = 1;
				if(kostka[2][4][3] == 32) flag[32] = 1;
				if(kostka[2][4][1] == 34) flag[34] = 1;
				if(kostka[2][3][0] == 42) flag[42] = 1;
				if(kostka[2][1][0] == 44) flag[44] = 1;
				s1 = najdiSouradnice(kostka, kosticka1);
				i = s1.j;
				j = s1.k;
				goto HRANY;
			}
		}
	}
	} //konec hlavniho while cyklu

	tah('y', (pocety % 4), kostka, 0);
	tisk(kostka);
	tah('y', ((pocety*3)%4), kostka, 0);
	return pocety;
}

int OLL(char kostka[5][5][5], int pocety){
	char flag[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	char i, j, k;
	//char kosticka1;
	//char kosticka2;
	int pom;
	//int pom2;
	//souradnice s1;
	//int token;
	
	printf("Orientuju posledni vrstvu:\n");
	//kriz
	for(i = 1; i <= 3; i++)
	{
		for(j = 1; j <= 3; j++)
		{
			//pokud zluta kosticka je nahore, nastavi se prislusny flag
			if(kostka[4][i][j] == 51) flag[1] = 1;
			if(kostka[4][i][j] == 52) flag[2] = 1;
			if(kostka[4][i][j] == 53) flag[3] = 1;
			if(kostka[4][i][j] == 54) flag[4] = 1;
		}
	}
	//pokud je tecka
	if((flag[1] + flag[2] + flag[3] + flag[4]) == 0)
	{
		tah('y', (pocety % 4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byla jako predtim
		tah('F', 1, kostka, 1);
		printf("(");		
		tah('R', 1, kostka, 1);
		tah('U', 1, kostka, 1);	
		tah('R', 3, kostka, 1);	
		tah('U', 3, kostka, 0); //silent U', aby pred zavorkou nebyla mezera
		printf("U') ");		
		tah('F', 3, kostka, 1);
		
		tah('f', 1, kostka, 1);	
		printf("(");	
		tah('R', 1, kostka, 1);
		tah('U', 1, kostka, 1);	
		tah('R', 3, kostka, 1);	
		tah('U', 3, kostka, 0); //silent U', aby pred zavorkou nebyla mezera
		printf("U') ");		
		tah('f', 3, kostka, 1);
		printf("\n");
		
		tah('y', ((pocety*3)%4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byly stredy v puvodni sestave
	}
	
	//pokud jsou 2
	if((flag[1] + flag[2] + flag[3] + flag[4]) == 2)
	{
		tah('y', (pocety % 4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byla jako predtim
		if( ( (kostka[4][1][2] > 50) && (kostka[4][3][2] > 50) ) || ( (kostka[4][2][1] > 50) && (kostka[4][2][3] > 50) ) )
		{ //pokud je rovna cara
			if(kostka[4][1][2] > 50)
			{
				tah('U', 1, kostka, 1);
				
				tah('F', 1, kostka, 1);	
				printf("(");	
				tah('R', 1, kostka, 1);
				tah('U', 1, kostka, 1);	
				tah('R', 3, kostka, 1);	
				tah('U', 3, kostka, 0); //silent U', aby pred zavorkou nebyla mezera
				printf("U') ");		
				tah('F', 3, kostka, 1);
				printf("\n");
			}
			else
			{
				tah('F', 1, kostka, 1);	
				printf("(");	
				tah('R', 1, kostka, 1);
				tah('U', 1, kostka, 1);	
				tah('R', 3, kostka, 1);	
				tah('U', 3, kostka, 0); //silent U', aby pred zavorkou nebyla mezera
				printf("U') ");		
				tah('F', 3, kostka, 1);
				printf("\n");
			}	
		}
		else //pokud je male Lko
		{
			if(kostka[4][1][2] > 50)
			{
				if(kostka[4][2][1] > 50) pom = 2;
				if(kostka[4][2][3] > 50) pom = 1;
			}
			if(kostka[4][3][2] > 50)
			{
				if(kostka[4][2][1] > 50) pom = 3;
				if(kostka[4][2][3] > 50) pom = 0;
			}
			tah('U', pom, kostka, 1);

			tah('f', 1, kostka, 1);	
			printf("(");	
			tah('R', 1, kostka, 1);
			tah('U', 1, kostka, 1);	
			tah('R', 3, kostka, 1);	
			tah('U', 3, kostka, 0); //silent U', aby pred zavorkou nebyla mezera
			printf("U') ");	
			tah('f', 3, kostka, 1);
			printf("\n");	
		}

		tah('y', ((pocety*3)%4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byly stredy v puvodni sestave
	}
	
	for(i = 1; i <= 3; i += 2)
	{
		for(j = 1; j <= 3; j += 2)
		{
			//pokud zluta kosticka je nahore, nastavi se prislusny flag
			if(kostka[4][i][j] == 56) flag[6] = 1;
			if(kostka[4][i][j] == 57) flag[7] = 1;
			if(kostka[4][i][j] == 58) flag[8] = 1;
			if(kostka[4][i][j] == 59) flag[9] = 1;
		}
	}
	
	//orientace rohu
	while((flag[6] + flag[7] + flag[8] + flag[9]) < 4)
	{
		tah('y', (pocety % 4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byla jako predtim
		if(kostka[4][3][3] > 55) //pokud vpravo dole je zluta
		{
			if(kostka[4][1][3] < 55) pom = 1;
			else
			{
				if(kostka[4][1][1] < 55) pom = 2;
				else
				{
					if(kostka[4][3][1] < 55) pom = 3;
				}
			}
			tah('U', pom, kostka, 1);	
		}
		while(kostka[4][3][3] < 55)
		{
			printf("(");
			tah('R', 3, kostka, 1);
			tah('D', 3, kostka, 1);	
			tah('R', 1, kostka, 1);	
			tah('D', 1, kostka, 0); //silent posledni D kvuli tomu, aby pred zavorkou nebyla mezera
			printf("D) ");
		}
		printf("\n");	
		
		tah('y', ((pocety*3)%4), kostka, 0); //otocit kostku tolikrat (v "silent modu"), aby byly stredy v puvodni sestave
		for(i = 1; i <= 3; i += 2)
		{
			for(j = 1; j <= 3; j += 2)
			{
				//pokud zluta kosticka je nahore, nastavi se prislusny flag
				if(kostka[4][i][j] == 56) flag[6] = 1;
				if(kostka[4][i][j] == 57) flag[7] = 1;
				if(kostka[4][i][j] == 58) flag[8] = 1;
				if(kostka[4][i][j] == 59) flag[9] = 1;
			}
		}
	}
	
	tah('y', (pocety % 4), kostka, 0);
	tisk(kostka);
	tah('y', ((pocety*3)%4), kostka, 0);
	return pocety;
}

void Aperm(char kostka[5][5][5]){
	tah('x', 1, kostka, 0);
	
	tah('R', 3, kostka, 0);
	tah('U', 1, kostka, 0);
	tah('R', 3, kostka, 0);
	tah('D', 2, kostka, 0);
	
	tah('R', 1, kostka, 0);
	tah('U', 3, kostka, 0);
	tah('R', 3, kostka, 0);
	tah('D', 2, kostka, 0);
	tah('R', 2, kostka, 0);
	
	tah('x', 3, kostka, 0);	
	printf("x (R' U R' D2) (R U' R' D2 R2) x'\n");
}

void Uperm(char kostka[5][5][5]){
	tah('R', 2, kostka, 0);
	tah('U', 3, kostka, 0);
	tah('R', 3, kostka, 0);
	tah('U', 3, kostka, 0);
	
	tah('R', 1, kostka, 0);
	tah('U', 1, kostka, 0);
	tah('R', 1, kostka, 0);
	tah('U', 1, kostka, 0);
	tah('R', 1, kostka, 0);
	tah('U', 3, kostka, 0);
	tah('R', 1, kostka, 0);
	
	printf("(R2' U' R' U') (R U R U R U' R)\n");
}

int PLL(char kostka[5][5][5], int pocety){
	char pocetrohu = 0; //kolik dvojic rohu je spravne
	char flaghrany = -1;
	char pocethran = 0; //kolik hran je spravne mezi svymi rohy
	char i, j, k;
	//char kosticka1;
	//char kosticka2;
	int pom;
	//int pom2;
	souradnice s1;
	//int token;
	
	printf("Permutuju posledni vrstvu:\n");
	
	//rohy	
	tah('y', (pocety % 4), kostka, 0);
	
	if( (kostka[3][4][1] / 10) == (kostka[3][4][3] / 10) ) pocetrohu++;
	if( (kostka[3][0][1] / 10) == (kostka[3][0][3] / 10) ) pocetrohu++;
	if( (kostka[3][3][4] / 10) == (kostka[3][1][4] / 10) ) pocetrohu++;
	if( (kostka[3][3][0] / 10) == (kostka[3][1][0] / 10) ) pocetrohu++;
	if(pocetrohu < 4)
	{
		if(pocetrohu == 0)
		{
			Aperm(kostka);
			pocetrohu = 0;
			if( (kostka[3][4][1] / 10) == (kostka[3][4][3] / 10) ) pocetrohu++;
			if( (kostka[3][0][1] / 10) == (kostka[3][0][3] / 10) ) pocetrohu++;
			if( (kostka[3][3][4] / 10) == (kostka[3][1][4] / 10) ) pocetrohu++;
			if( (kostka[3][3][0] / 10) == (kostka[3][1][0] / 10) ) pocetrohu++;
		}
		while(pocetrohu == 1)
		{
			//aby "svetla" byly vzadu
			if( (kostka[3][4][1] / 10) == (kostka[3][4][3] / 10) ) tah('U', 2, kostka, 1);
			else if( (kostka[3][3][4] / 10) == (kostka[3][1][4] / 10) ) tah('U', 3, kostka, 1);
			else if( (kostka[3][3][0] / 10) == (kostka[3][1][0] / 10) ) tah('U', 1, kostka, 1);
			
			Aperm(kostka);
			pocetrohu = 0;
			if( (kostka[3][4][1] / 10) == (kostka[3][4][3] / 10) ) pocetrohu++;
			if( (kostka[3][0][1] / 10) == (kostka[3][0][3] / 10) ) pocetrohu++;
			if( (kostka[3][3][4] / 10) == (kostka[3][1][4] / 10) ) pocetrohu++;
			if( (kostka[3][3][0] / 10) == (kostka[3][1][0] / 10) ) pocetrohu++;
		}
	}
	s1 = najdiSouradnice(kostka, 34);
	pom = delejTahDokud(kostka, 'U', 36, 3, s1.j, s1.k); //delej U dokud oranzovo-zeleno-zluty roh neni nad oranzovo-zelenou hranou
	tah('U', pom, kostka, 1);
	if(pom != 0) printf("\n");
	
	//hrany
	if( (kostka[3][3][0] / 10) == (kostka[3][2][0] / 10) )
	{
		flaghrany = 3; //kolikrat udelat tah y, aby pred nami byla spravna hrana
		pocethran++;
	}
	if( (kostka[3][0][1] / 10) == (kostka[3][0][2] / 10) )
	{
		flaghrany = 2;
		pocethran++;
	}
	if( (kostka[3][3][4] / 10) == (kostka[3][2][4] / 10) )
	{
		flaghrany = 1;
		pocethran++;
	}
	if( (kostka[3][4][1] / 10) == (kostka[3][4][2] / 10) )
	{
		flaghrany = 0;
		pocethran++;
	}
	
	if(pocethran < 4) //pokud nejsou vsechny 4 hrany spravne
	{
		if(pocethran == 0)
		{
			Uperm(kostka);
			pocethran = 1;
			if( (kostka[3][3][0] / 10) == (kostka[3][2][0] / 10) ) flaghrany = 3;
			if( (kostka[3][0][1] / 10) == (kostka[3][0][2] / 10) ) flaghrany = 2;
			if( (kostka[3][3][4] / 10) == (kostka[3][2][4] / 10) ) flaghrany = 1;
			if( (kostka[3][4][1] / 10) == (kostka[3][4][2] / 10) ) flaghrany = 0;
		}
		while(pocethran == 1)
		{
			tah('y', flaghrany, kostka, 1); pocety += flaghrany;
			flaghrany = 0;
			Uperm(kostka);
			pocethran = 0;
			if( (kostka[3][3][0] / 10) == (kostka[3][2][0] / 10) ) pocethran++;
			if( (kostka[3][0][1] / 10) == (kostka[3][0][2] / 10) ) pocethran++;
			if( (kostka[3][3][4] / 10) == (kostka[3][2][4] / 10) ) pocethran++;
			if( (kostka[3][4][1] / 10) == (kostka[3][4][2] / 10) ) pocethran++;
		}
	}
	
	tisk(kostka);
	printf("Kostka je slozena!\n");
	return pocety;
}

int main(int argc, char** argv){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	char kostka[5][5][5];
	char jeToPoprve = 1;
	int pocety;
	int a;
	
	ZACATEK:
	inicializace(kostka);
	
	if(jeToPoprve == 1)
	{
		uvodniRecicky();
		jeToPoprve = 0;
	}
	zacatek(kostka);
		
	pocety = slozKriz(kostka);
	pocety = vlozRohy(kostka, pocety);
	pocety = vlozHrany(kostka, pocety);
	pocety = OLL(kostka, pocety);
	pocety = PLL(kostka, pocety);
	
	printf("Pokud chces skladat znova, zadej 1, pokud chces skoncit, zadej 2:\n");
	scanf("%d", &a);
	if(a == 1) goto ZACATEK;
	else printf("Koncim.");
	
	return 0;
}
