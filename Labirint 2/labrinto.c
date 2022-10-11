#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "le_teclas.h"
#include "my_lib.h"

#define linhas_tela_1      15
#define colunas_tela_1     10
#define linhas_tela_2      15
#define colunas_tela_2     15
#define linhas_tela_3      20
#define colunas_tela_3     20

#define lim_x_left_1        7
#define lim_x_right_1       14
#define lim_y_top_1         7
#define lim_y_down_1        14
#define lim_x_left_2        7
#define lim_x_right_2       19
#define lim_y_top_2         7
#define lim_y_down_2        19
#define lim_x_left_3        7
#define lim_x_right_3       24
#define lim_y_top_3         7
#define lim_y_down_3        24

#define desl_x      7//posição inicial cursor
#define desl_y      7//posição inicial cursor

#define posx_inicial 6//posição inicial mapa
#define posy_inicial 6//posição inicial mapa

int i=0,j=0,x=0,y=0,a,b,num_map=1,porta_secreta=0,movimentos=0,count, pontuacao_final, destruicao, tela_aberta;//, mira=2;
char KEY;//, dir_x, dir_y;
FILE *fp;

//****************************************************************************
/*
int teclas(char tela[a][b], int lim_x, int lim_y, char dir_x, char dir_y, int mira)
{
  if(KEY == 1)//sobe
  {
      gotoxy(60,15);
      printf("Seta para cima");

      if (dir_x == desl_x + porta_secreta && dir_x < lim_y)
      {
        gotoxy(60,5);
        printf("uma porta secreta");
      }

      else if(tela[dir_y-desl_y + 1][dir_x-desl_x + 1] == 219||tela[dir_y-desl_y + 1][dir_x-desl_x + 1] == 207)
      {
        gotoxy(60,10); // texto informativo só para saber se encntrou uma barreira
        printf("Alvo da Tela = %d",tela[dir_y-desl_y + 1][dir_x-desl_x + 1]);
        y++;
      }

      else if(tela[dir_y-desl_y + 1][dir_x-desl_x + 1] == 42)
      {
        printf("Vc ganhou");
        break;
      }
      
    else if(dir_y < lim_y)
    dir_y = lim_y;
  }
  return 0;
}*/

/*int teclas(tela[a][b])
{


  else if(KEY == 2)//desce
          {
            gotoxy(60,15);
            printf("Seta para baixo");
            y++;
            movimentos++;
            mira = 2;

            if (x == desl_x + porta_secreta && x > lim_y_down_1)
            {
            gotoxy(60,5);
            printf("uma porta secreta");
              }
            else if(tela_1[y-desl_y + 1][x-desl_x + 1] == 219||tela_1[y-desl_y + 1][x-desl_x + 1] == 207)
            {
                gotoxy(60,10);
                printf("Alvo da Tela = %d",tela_1[y-desl_y + 1][x-desl_x + 1]);
                y--;
                }

            else if(y > lim_y_down_1)
            y = lim_y_down_1;
            }

  else if(KEY == 3)//esquerda
            {
            gotoxy(60,15);
            printf("Seta para esquerda");
            x--;
            movimentos++;
            mira = 3;

            if (x == desl_x + porta_secreta && x > lim_x_left_1)
                {
                gotoxy(60,5);
                printf("uma porta secreta");
              }
            else if(tela_1[y-desl_y + 1][x-desl_x + 1] == 219||tela_1[y-desl_y + 1][x-desl_x + 1] == 207)
                  {
                gotoxy(60,10);
                printf("Alvo da Tela = %d",tela_1[y-desl_y + 1][x-desl_x + 1]);
                x++;
                  }

              else if(x < lim_x_left_1)
                x = lim_x_left_1;
            }

  else if(KEY == 4)//direita
            {
            gotoxy(60,15);
            printf("Seta para direita");
            x++;
            movimentos++;
            mira = 4;

            if (x == desl_x + porta_secreta && x < lim_x_right_1)
              {
            gotoxy(60,5);
            printf("uma porta secreta");
              }

            else if(tela_1[y-desl_y + 1][x-desl_x + 1] == 219||tela_1[y-desl_y + 1][x-desl_x + 1] == 207)
                  {
                gotoxy(60,10);
                printf("Alvo da Tela = %d",tela_1[y-desl_y + 1][x-desl_x + 1]);
                x--;
                  }

             else if(x > lim_x_right_1)
                x = lim_x_right_1;
                gotoxy(60,10);
            }

  else if(KEY == 5)//espaço tiros
            {
                count = 0;
                if (mira==1)//tiro para cima
                {
                    while(1)
                    {
                        if (tela_1[(y - desl_y) - count][(x - desl_x) + 1] == 219)
                        {
                            break;
                        }
                        else if (tela_1[(y - desl_y) - count][(x - desl_x) + 1] == 207)
                            {
                            gotoxy(60,25);
                            printf("Bummmm");
                            tela_1[(y - desl_y) - count][(x - desl_x) + 1] = 0;
                            destruicao = destruicao + 5;
                            break;
                            }
                        else
                        {
                            gotoxy(x, y - count - 1);
                            printf("%c",46);
                            Sleep(250);
                        }

                        count++;
                    }
                }

                else if (mira == 2)//tiro para baixo
                {
                    while(1)
                    {
                        if (tela_1[(y - desl_y) + count + 2][(x - desl_x) + 1] == 219)
                        {
                            break;
                        }
                        else if (tela_1[(y - desl_y) + count + 2][(x - desl_x) + 1] == 207)
                            {
                            gotoxy(60,25);
                            printf("Bummmm");
                            tela_1[(y - desl_y) + count + 2][(x - desl_x) + 1] = 0;
                            destruicao = destruicao + 5;
                            break;
                            }
                        else
                        {
                            gotoxy(x, y + count + 1);
                            printf("%c",46);
                            Sleep(250);
                        }

                        count++;
                    }
                }
                else if (mira == 3)//tiro para esquerda
                {
                    while(1)
                    {
                        if (tela_1[(y - desl_y + 1)][(x - desl_x)  - count] == 219)
                        {
                            break;
                        }
                        else if (tela_1[(y - desl_y + 1)][(x - desl_x) - count] == 207)
                            {
                            gotoxy(60,25);
                            printf("Bummmm");
                            tela_1[(y - desl_y) + 1][(x - desl_x) - count] = 0;
                            destruicao = destruicao + 5;
                            break;
                            }
                        else
                        {
                            gotoxy(x - count - 1, y);
                            printf("%c",46);
                            Sleep(250);
                        }

                        count++;
                    }
                }
                else if (mira == 4)//tiro para direita
                {
                    while(1)
                    {
                        if (tela_1[(y - desl_y + 1)][(x - desl_x)  + count + 2] == 219)
                        {
                            break;
                        }
                        else if (tela_1[(y - desl_y + 1)][(x - desl_x) + count + 2] == 207)
                            {
                            gotoxy(60,25);
                            printf("Bummmm");
                            tela_1[(y - desl_y) + 1][(x - desl_x) + count + 2] = 0;
                            destruicao = destruicao + 5;
                            break;
                            }
                        else
                        {
                            gotoxy(x + count + 1, y);
                            printf("%c",46);
                            Sleep(250);
                        }

                        count++;
                    }
                }
                else
                {
                    gotoxy(60,25);
                    printf("Sem balas");
                }

            }

  else if(KEY == 6)//ESC sai do jogo
          {
              printf("ESC");
              break;
          }

  else if(tela_1[y-desl_y + 1][x-desl_x + 1] == 42)//vitoria
            {
              system("cls");
              pontuacao_final = movimentos - destruicao;
              gotoxy(10,2); // posição do texto informativo de qual seta foi usada
              printf("\n Voce fez %d pontos\n ", pontuacao_final);
              break;
            }

  gotoxy(10,1); // posição do texto informativo de qual seta foi usada
  printf("\n Voce ja andou %d vezes\n ", movimentos);
}
*/

int le_tela(char tela[a][b],int linha,int coluna, char arq[10])
{
    do
    {
      //printf("\n\tAbertura de arquivo para leitura");

      if((fp = fopen(arq,"r"))==NULL)
          {
            printf("\n\tNao e possivel abrir o arquivo");
            exit(1);
          }
      else
          {
           printf("\n\tArquivo aberto");
          }
         for(i = 0; i < linha; i++)
            {
              for(j = 0; j < coluna; j++)
              {
                fscanf(fp,"%d", &tela[i][j]);
              }
            }

            for(i = 0; i < linha; i++)
                {
                  for(j = 0; j < coluna; j++)
                {
                  gotoxy(j + posx_inicial ,i + posy_inicial );
                  printf("%c", tela[i][j]);
                }
              }
            fclose(fp);
            gotoxy(x,y); // cursor
            printf("%c",64);
            KEY = tecla();
            porta_secreta=rand()%10;
    }while(1);

  return 0;
}

int main()
{
  char arquivo[10];
  int mapas=1;
  printf("\n\tmapas %d", mapas);

  unsigned char tela_1[linhas_tela_1][colunas_tela_1] ={{219,219,219,219,219,219,219,219,219,219},
                                        {219,' ',219,' ',' ',219,' ',219,' ',219},
                                        {219,' ',219,' ',' ',219,' ',219,' ',219},
                                        {219,' ',219,' ',' ',219,' ',' ',207,219},
                                        {219,207,219,' ',219,207,' ',219,207,219},
                                        {219,' ',219,219,219,' ',219,219,' ',219},
                                        {219,' ',219,' ',' ',' ',' ',219,' ',219},
                                        {219,' ',219,' ',219,219,' ',219,' ',219},
                                        {219,' ',' ',' ',219,' ',' ',219,42 ,219},
                                        {219,219,219,219,219,219,219,219,' ',219}};
    
  unsigned char tela_2[linhas_tela_2][colunas_tela_2]={{219,219,219,219,219,219,219,219,219,219,219,219,219,219,219},
                                                     {219,' ',' ',219,' ',' ',219,' ',219,219,219, ' ',' ',' ',219},
                                                     {219,219,' ',' ',219,' ',219,' ',' ',' ',207, ' ',219,' ',219},
                                                     {219,' ',207,219,' ',' ',' ',' ',219,219,219, ' ',219,' ',219},
                                                     {219,' ',219,219,' ',219,219,219,219,' ',219, 219,' ',' ',219},
                                                     {219,' ',219,' ',' ',' ',' ',' ',219,' ',219, ' ',' ',219,219},
                                                     {219,' ',219,' ',219,219,219,' ',' ',' ',219, ' ',219,' ',219},
                                                     {219,' ',' ',' ',219,' ',' ',' ',219,' ',219, ' ',219,' ',219},
                                                     {219,' ',219,219,219,' ',219,219,219,' ',219, ' ',207,' ',219},
                                                     {219,' ',207,' ',' ',' ',219,' ',' ',' ',219, ' ',219,' ',219},
                                                     {219,219,219,219,219,219,219,219,219,219,219,219,219,42 ,219}};

  unsigned char tela_3[linhas_tela_3][colunas_tela_3]={{219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219},
                                                     {219,' ',' ',' ',' ',219,219,' ',' ',' ',' ',' ',219,' ',219,' ',' ',' ',' ',219},
                                                     {219,' ',219,219,' ',207,219,' ',219,' ',219,' ',219,' ',' ',207,219,219,' ',219},
                                                     {219,' ',207,' ',219,219,219,' ',219,' ',219,' ',' ',' ',219,' ',219,' ',' ',219},
                                                     {219,219,219,' ',219,' ',219,' ',' ',207,219,219,219,219,219,' ',219,' ',219,219},
                                                     {219,' ',' ',' ',219,' ',219,219,219,' ',219,' ',' ',' ',219,' ',219,' ',' ',219},
                                                     {219,' ',219,219,219,' ',' ',' ',219,' ',219,' ',219,219,219,' ',219,219,' ',219},
                                                     {219,' ',' ',207,' ',' ',219,' ',219,' ',219,' ',' ',' ',' ',' ',219,' ',' ',219},
                                                     {219,219,219,' ',219,219,219,219,219,' ',219,' ',219,219,219,' ',219,' ',219,219},
                                                     {219,' ',219,' ',' ',' ',' ',' ',219,' ',219,' ',219,' ',219,219,219,207,' ',219},
                                                     {219,' ',219,' ',219,219,219,' ',219,' ',219,' ',219,' ',' ',' ',' ',' ',' ',219},
                                                     {219,' ',219,' ',219,' ',219,' ',219,' ',219,' ',219,219,219,219,219,219,219,219},
                                                     {219,' ',219,' ',219,' ',219,' ',219,' ',219,' ',207,' ',' ',' ',' ',219, 42,' '},
                                                     {219,' ',' ',' ',219,' ',219,' ',219,' ',219,219,' ',219,219,' ',219,219,207,219},
                                                     {219,' ',219,219,219,' ',219,' ',' ',' ',219,219,' ',' ',219,' ',219,219,' ',219},
                                                     {219,' ',' ',' ',' ',' ',219,219,219,219,219,' ',219,' ',219,207,' ',' ',' ',219},
                                                     {219,' ',219,219,219,219,219,' ',219,' ',' ',219,' ',' ',219,' ',219,219,219,219},
                                                     {219,' ',219,' ',' ',' ',219,' ',' ',' ',219,219,' ',219,219,' ',219,' ',' ',219},
                                                     {219,' ',' ',' ',219,' ',' ',' ',219,' ',219,' ',' ',' ',219,' ',' ',' ',219,219},
                                                     {219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219}};
    
  
  while(mapas<=6)
  {
    cursor_off();
    textcolor(2);
    printf("\n\tNivel %d", mapas);
    textcolor(15);
    x = desl_x;
    y = desl_y;
    movimentos = 0;
    destruicao = 0;

    if (mapas==1)
    {
        a=linhas_tela_1;
        b=colunas_tela_1;
        strcpy(arquivo, "Tela_1.txt");
        le_tela(tela_1,a,b,arquivo);
        tela_aberta=1;
    }

    else if(mapas==2)
    {
        a=linhas_tela_2;
        b=colunas_tela_2;
        strcpy(arquivo, "Tela_2.txt");
        le_tela(tela_2,a,b,arquivo);
        tela_aberta=2;
    }

    else if(mapas==3)
    {
        a=linhas_tela_3;
        b=colunas_tela_3;
        strcpy(arquivo, "Tela_3.txt");
        le_tela(tela_3,a,b,arquivo);
        tela_aberta=3;
    }

    getch();
    Sleep(1000);
    clrscr();
    cursor_off();
    textcolor(2);
    mapas++;
  }

  Sleep(1000);
  clrscr();
  printf("\nTecle para fechar o programa...");
  getch();
  return 0;
}