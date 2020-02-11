#include <stdio.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

#define AZUL 			printf("\033[1;34m");
#define PRETO			printf("\033[1;40m");
#define PRETOF			printf("\033[1;30m");
#define AMARELO			printf("\033[1;43m");
#define AMARELOF		printf("\033[1;33m");
#define VERMELHO		printf("\033[1;31m");
#define CIANO	 		printf("\033[1;46m");
#define CINZAESCURO		printf("\033[1;100m");
#define CINZAESCUROF	printf("\033[1;90m");
#define CINZACLARO  	printf("\033[1;47m");
#define CINZACLAROF		printf("\033[1;37m");
#define VERDEESCURO 	printf("\033[1;42m");
#define VERDECLARO  	printf("\033[1;102m");
#define MAGENTAF  		printf("\033[1;35m");


#define RESET		printf("\033[0;0m");

#define LAR 		72
#define ALT 		36
#define CAMINHO 	0
#define PAREDE 		1
#define ENTRADA 	
#define SAIDA 		3
#define OBJETO		4
#define CANTO       5
#define JAIME		6
#define INIMIGO     7
#define BUSTOS 		9
#define GRAMA		2
#define RUA			8
#define RUA2		10
#define CAMINHO2	4
#define CHAVE 		11
#define FLOR		15
#define FLOR2		16
#define CARRO 		20
#define PORTA 		21
#define LANTERNA 	22

int getch(void);

int main() {



	srand(time(NULL));
		
	int mapa[ALT][LAR]= {  {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
						   {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
						   {9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9},
						   {9,1,5,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,1,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,1,5,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,1,0,5,0,0,5,1,9},
						   {9,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
						   {9,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
						   {9,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,9},
						   {9,1,5,0,0,0,0,0,0,0,1,5,0,0,5,0,0,5,0,0,5,1,5,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,1,5,5,0,0,5,1,9},
						   {9,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9},
						   {9,1,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
						   {9,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
						   {9,1,5,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,9},
						   {9,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,1,0,0,0,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,5,0,0,0,1,9},
						   {9,1,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
						   {9,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
						   {9,1,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
						   {9,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,1,0,0,0,1,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
						   {9,1,5,0,0,0,0,0,0,1,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,1,0,0,0,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,1,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
						   {9,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,9},
						   {9,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
						   {9,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
						   {9,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,9},
						   {9,1,5,0,0,5,0,5,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,1,0,0,0,0,0,0,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,9},
						   {9,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,22,0,1,9},
						   {9,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,9},
						   {9,1,5,0,5,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,9},
						   {9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,21,21,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9},
						   {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,15,2,4,4,15,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
						   {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,16,2,4,4,16,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
						   {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
						   {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
						   {8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,20,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
						   {8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
			               {8,8,8,8,8,8,8,8,10,10,10,10,10,8,8,8,8,8,8,8,8,10,10,10,10,10,8,8,8,8,8,8,8,8,10,10,10,10,10,8,8,8,8,8,8,8,8,10,10,10,10,10,8,8,8,8,8,8,8,8,10,10,10,10,10,8,8,8,8,8,8,8},
						   {8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
						   {8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
						   
						};
	int lin, col, menu, final, px, py, ix, iy, cx, cy, jx, jy, direcao = 1, dir = 1, passo =0, cont=0, visao = 100;
	int pontos, encontro = 0, temchave = 0, inicio = 0, luz = 0, retornar, gameover;
	char jogada;

	int inimigos[10][5];



	//GERAR JAIME ALEATÓRIO
	for(int i=0; i<1;){
		jx = rand()%ALT;
		jy = rand()%LAR;

		if(mapa[jx][jy]==CANTO){
			i++;
		}	
	}

	//GERAR INIMIGO ALEATÓRIO
	for(int i=0; i<5;){
		ix = rand()%ALT;
		iy = rand()%LAR;

		if(mapa[ix][iy]==CAMINHO){
			mapa[ix][iy] = INIMIGO;
			inimigos[i][3] = ix;
			inimigos[i][4] = iy;
			i++;
		}	
	}

	//GERAR CHAVE ALEATÓRIA
	for(int i=0; i<1;){
		cx = rand()%ALT;
		cy = rand()%LAR;

		if(mapa[cx][cy]==CAMINHO){
			mapa[cx][cy] = CHAVE;
			i++;
		}	
	}

	//POSIÇÃO JOGADOR
	final = 0;
	px = 22;  
	py = 65;

	

	printf("\t\t\t\t\t    ╔══════════════╗\n");
	printf("\t\t\t\t\t   ╞║     MENU     ║╡\n");
	printf("\t\t\t\t\t    ╚══════════════╝\n");

	printf("\t\t\t1-Jogar\n");
	printf("\t\t\t2-Sair\n");

	scanf("%d", &menu);
	system("clear");

	switch(menu){
	case 1: 
		while(final == 0) {
	

		//ENCONTRO
		if(encontro==1){
			jx = px;
			jy = py;
		}

		// CAPTURA TECLA
		if(inicio==0)
			inicio++;
		else
			jogada = getch();

		// TECLA ESPECIAL
		if(jogada == 27) {
			jogada = getch(); 

			if(jogada == 91) {      
				jogada = getch();
				
				// CIMA
				if(jogada == 65) {
					if(px > 0 && mapa[px-1][py] != 1 && mapa[px-1][py] != BUSTOS && mapa[px-1][py] != PORTA) {
						px--;
						direcao = 1;
						if(px==jx&&py==jy){
							jx++;
							encontro = 1;
						}
						else if (px==cx&&py==cy){
							temchave = 1;
							mapa[px][py] = CAMINHO;
						}

						if(encontro==1&&temchave==1){
							for(int i = 0; i<ALT; i++){
								for(int j = 0; j<LAR; j++){
									if(mapa[i][j]==PORTA){
										mapa[i][j]= CAMINHO;
									}
								}	
							}
						}

					}
				}		
	  			// BAIXO
				else if(jogada == 66) {
		    			if(px < ALT-1 && mapa[px+1][py] != 1 && mapa[px+1][py] != BUSTOS && mapa[px+1][py] != PORTA) {
						px++;
						direcao = 2;
						if(px==jx&&py==jy){
							jx--;
							encontro = 1;
						}
						else if (px==cx&&py==cy){
							temchave = 1;
							mapa[px][py] = CAMINHO;
						}

						if(encontro==1&&temchave==1){
							for(int i = 0; i<ALT; i++){
								for(int j = 0; j<LAR; j++){
									if(mapa[i][j]==PORTA){
										mapa[i][j]= CAMINHO;
									}
								}	
							}
						}
					}
				}
				// DIREITA
				else if(jogada == 67) {
					if(py < LAR-1 && mapa[px][py+1] != 1 && mapa[px][py+1] != BUSTOS && mapa[px][py+1] != PORTA) {
						py++;
						direcao = 3;
						if(px==jx&&py==jy){
							jx--;
							encontro = 1;
						}
						else if (px==cx&&py==cy){
							temchave = 1;
							mapa[px][py] = CAMINHO;
						}

						if(encontro==1&&temchave==1){
							for(int i = 0; i<ALT; i++){
								for(int j = 0; j<LAR; j++){
									if(mapa[i][j]==PORTA){
										mapa[i][j]= CAMINHO;
									}
								}	
							}
						}
					}
			    }
				// ESQUERDA
				else if(jogada == 68 && mapa[px][py-1] != 1 && mapa[px][py-1] != BUSTOS && mapa[px][py-1] != PORTA) {
					if(py > 0) {
						py--;
						direcao = 4;
						if(px==jx&&py==jy){
							jx++;
							encontro = 1;
						}
						else if (px==cx&&py==cy){
							temchave = 1;
							mapa[px][py] = CAMINHO;
						}

						if(encontro==1&&temchave==1){
							for(int i = 0; i<ALT; i++){
								for(int j = 0; j<LAR; j++){
									if(mapa[i][j]==PORTA){
										mapa[i][j]= CAMINHO;
									}
								}	
							}
						}
					}
				}
			}
		}
		//cont inimigos
		/*
			inimigos 0 cont
			inimigos 1 passo
			inimigos 2 dir
			inimigos 3 ix
			inimigos 4 iy

		*/
		for(int i = 0; i<5; i++){
			if(inimigos[i][0]==inimigos[i][1]){
				inimigos[i][1]=rand()%20;
				inimigos[i][2]=rand()%4;
				inimigos[i][0]=0;
			}

			if(inimigos[i][0]<inimigos[i][1]){
				if(inimigos[i][2]==0){
					if(mapa[inimigos[i][3]-1][inimigos[i][4]]!=PAREDE && mapa[inimigos[i][3]-1][inimigos[i][4]]!=JAIME && mapa[inimigos[i][3]-1][inimigos[i][4]]!=PORTA){
							mapa[inimigos[i][3]][inimigos[i][4]]=CAMINHO;
							mapa[inimigos[i][3]-1][inimigos[i][4]]=INIMIGO;
							inimigos[i][3]--;
							inimigos[i][0]++;
						}
						else{inimigos[i][0]=inimigos[i][1];}
					}
					else if(inimigos[i][2]==1){
						if(mapa[inimigos[i][3]+1][inimigos[i][4]]!=PAREDE && mapa[inimigos[i][3]+1][inimigos[i][4]]!=JAIME && mapa[inimigos[i][3]+1][inimigos[i][4]]!=PORTA){
							mapa[inimigos[i][3]][inimigos[i][4]]=CAMINHO;
							mapa[inimigos[i][3]+1][inimigos[i][4]]=INIMIGO;
							inimigos[i][3]++;
							inimigos[i][0]++;
						}
						else{inimigos[i][0]=inimigos[i][1];}
					}
					else if(inimigos[i][2]==2){
						if(mapa[inimigos[i][3]][inimigos[i][4]-1]!=PAREDE && mapa[inimigos[i][3]][inimigos[i][4]-1]!=JAIME && mapa[inimigos[i][3]][inimigos[i][4]-1]!=PORTA){
							mapa[inimigos[i][3]][inimigos[i][4]]=CAMINHO;
							mapa[inimigos[i][3]][inimigos[i][4]-1]=INIMIGO;
							inimigos[i][4]--;
							inimigos[i][0]++;
						}
						else{inimigos[i][0]=inimigos[i][1];}
					}
					else if(inimigos[i][2]==3){
						if(mapa[inimigos[i][3]][inimigos[i][4]+1]!=PAREDE && mapa[inimigos[i][3]][inimigos[i][4]+1]!=JAIME && mapa[inimigos[i][3]][inimigos[i][4]+1]!=JAIME && mapa[inimigos[i][3]][inimigos[i][4]+1]!=PORTA){
							mapa[inimigos[i][3]][inimigos[i][4]]=CAMINHO;
							mapa[inimigos[i][3]][inimigos[i][4]+1]=INIMIGO;
							inimigos[i][4]++;
							inimigos[i][0]++;
						}
						else{inimigos[i][0]=inimigos[i][1];}
					}
			}
		}
		if(mapa[px][py]==INIMIGO){
			final = 1;
		}

		if(mapa[px][py]==CARRO){
			final = 1;
		}

		if(mapa[px][py]==LANTERNA){
			visao = 4;
			luz = 1;
			mapa[px][py] = CAMINHO;
		}

		// PAREDE
		else if(jogada == 'P' || jogada == 'p') {		
			mapa[px][py] = PAREDE;
		}
		else if(jogada == '1') {		
			final = 0;
		}
		else if(jogada == '2') {
			system("clear");		
			main();
		}
		// OK - SAIR
		else if(jogada == '0'){		
			system("clear");
			return 0;

		}


		system("clear");
		printf("\t\t\t\t\t    ╔══════════════╗\n");
		printf("\t\t\t\t\t   ╞║SAVE THE JAIME║╡\n");
		printf("\t\t\t\t\t    ╚══════════════╝\n");
		for(lin=0; lin<ALT; lin++) {
			printf("\t\t");
			for(col=0; col<LAR; col++) {
				if((lin>px-visao&&col>py-visao)&&(lin<px+visao&&col<py+visao)){
					if(lin == px && col == py) {
							CINZAESCURO;
						if(direcao == 1){
							AZUL;
							printf("▲");
							RESET;
						}
						if(direcao == 2){
							AZUL;
							printf("▼");
							RESET;
						}
						if(direcao == 3){
							AZUL;
							printf("▶");
							RESET;
						}
						if(direcao == 4){
							AZUL;
							printf("◀");
							RESET;
						}
							RESET
							
					}
					else if(lin==jx&&col==jy) {
						CINZAESCURO;
						printf("😥");
						RESET;
					}
					else if(mapa[lin][col] == CAMINHO) {
						CINZAESCURO;
						printf(" ");
						RESET;
					}
					else if(mapa[lin][col] == PAREDE) {
						CIANO;
						printf(" ");
						RESET;
					}
					else if(mapa[lin][col] == BUSTOS) {
						VERDEESCURO;
						printf(" ");
						RESET;
					}
					else if(mapa[lin][col] == GRAMA) {
						VERDECLARO;
						printf(" ");
						RESET;
					}
					else if(mapa[lin][col] == RUA) {
						CINZAESCURO;
						printf(" ");
						RESET;
					}
					else if(mapa[lin][col] == RUA2) {
						AMARELO;
						printf(" ");
						RESET;
					}
					else if(mapa[lin][col] == SAIDA) {
						PRETO;
						printf(" ");
						RESET;
					}
					else if(mapa[lin][col] == OBJETO) {
						AMARELO;
						AMARELOF;
						printf(" ");
						RESET;
					}
					else if(mapa[lin][col] == CANTO) {
						CINZAESCURO;
						printf(" ");
						RESET;
					}
					else if(mapa[lin][col] == INIMIGO) {
						CINZAESCURO;
						VERMELHO;
						printf("💀");
						RESET;
					}
					else if(mapa[lin][col] == CHAVE) {
						CINZAESCURO;
						AMARELOF;
						printf("🔑");
						RESET;
					}
					else if(mapa[lin][col] == FLOR) {
						AMARELOF;
						VERDECLARO;
						printf("🌻");
						RESET;
					}
					else if(mapa[lin][col] == FLOR2) {
						MAGENTAF;
						VERDECLARO;
						printf("🌷");
						RESET;
					}
					else if(mapa[lin][col] == CARRO) {
						AMARELOF;
						CINZAESCURO;
						printf("🚐");
						RESET;
					}
					else if(mapa[lin][col] == PORTA) {
						AMARELOF;
						CINZAESCURO;
						printf("🚪");
						RESET;
					}
					else if(mapa[lin][col] == LANTERNA) {
						AMARELOF;
						CINZAESCURO;
						printf("🔦");
						RESET;
					}
				}
				else{
					printf(" ");
				}
			}
			if(lin == 10){
				printf("\tENCONTRADOS: ");
				if(encontro==1){
					AMARELOF;
					printf("😍 [Jaime] ");
					RESET;
				}
				if(temchave==1){
					AMARELOF;
					printf("🔑 [Chave] ");
					RESET;
				}
				if(luz==1){
					AMARELOF;
					printf("🔦 [Lanterna] ");
					RESET;
				}
			}

			if(lin == 3){
				printf("\tObjetivos: ");
			}
			if(lin == 4){
				if(luz==0){
					printf("\t- Pegar a lanterna");
				}else if(luz==1){
					AMARELOF;
					printf("\t- Pegar a lanterna ✔️ ");
					RESET;
				}
			}
			if(lin == 5){
				if(temchave==0){
					printf("\t- Encontrar a chave");
				}else if(temchave==1){
					AMARELOF;
					printf("\t- Encontrar a chave ✔️ ");
					RESET;
				}
			}
			if(lin == 6){
				if(encontro==0){
					printf("\t- Encontrar o Jaime");
				}else if(encontro==1){
					AMARELOF;
					printf("\t- Encontrar o Jaime ✔️ ");
					RESET;
				}
			}
			if(lin == 20){
				
					printf("\t1 - Reiniciar jogo");
				
			}
			if(lin == 21){
				
					printf("\t2 - Voltar ao menu");
				
			}
			if(lin == 22){
				
					printf("\t0 - Sair");
			}
			printf("\n");
		}
		//printfs


		}
		system("clear");
		if(final == 1){
			printf("\n\n\n");
			printf("\t\t\t\t\t    ╔══════════════╗\n");
			printf("\t\t\t\t\t   ╞║ FIM DO JOGO! ║╡\n");
			printf("\t\t\t\t\t    ╚══════════════╝\n");
			printf("\n\n\n");
			
			
			printf("\t\t\t\t   1 - Voltar ao menu\n");
			printf("\t\t\t\t   2 - Sair");				   
			printf("\t\t\t");
			scanf("%d", &gameover);
			system("clear");
		
			switch(gameover){
				case 1: 
					  main();
				break;
				case 2:
					return 0;
				break;
			}
	break;

	case 2:
		return 0;
		break;

	case 3:
		return 0;
	break;

	}

	printf("\n");
	return 0;
}
}
int getch(void) {

    struct termios oldattr, newattr;
    int ch;

    tcgetattr( STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO);
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr);

    return ch;
}