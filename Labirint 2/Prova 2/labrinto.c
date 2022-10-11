#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "le_teclas.h"
#include "my_lib.h"

#define linhas_tela_1      10
#define colunas_tela_1     10
#define linhas_tela_2      15
#define colunas_tela_2     15
#define linhas_tela_3      15
#define colunas_tela_3     15
#define linhas_tela_4      20
#define colunas_tela_4     20
#define linhas_tela_5      20
#define colunas_tela_5     20

#define desl_x      7//posição inicial cursor
#define desl_y      7//posição inicial cursor

#define posx_inicial 6//posição inicial mapa
#define posy_inicial 6//posição inicial mapa

int i=0,j=0,x=0,y=0,a,b,mapas=1,porta_secreta=0,movimentos=0,count, pontuacao_final, destruicao, tela_aberta, mira=2;
int classificacao;
char KEY;
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
    
    unsigned char tela_3[linhas_tela_3][colunas_tela_3]={{219,219,219,219,219,219,219,219,219,219,219,219,219,219,219},
                                                          {219,' ',' ',219,' ',' ',219,' ',219,219,219, 219,' ',' ',219},
                                                          {219,219,' ',' ',219,' ',219,' ',' ',' ',' ', ' ',219,' ',219},
                                                          {219,' ',207,219,' ',' ',207,' ',219,' ',219, ' ',' ',' ',219},
                                                          {219,' ',219,219,' ',219,219,219,219,' ',219, ' ',219,219,219},
                                                          {219,' ',207,' ',' ',' ',' ',' ',219,' ',219, ' ',' ',207,219},
                                                          {219,207,219,219,219,219,219,207,' ',' ',219, ' ',219,' ',219},
                                                          {219,' ',' ',' ',219,' ',' ',' ',219,' ',219, 207,219,' ',219},
                                                          {219,' ',219,219,219,' ',219,219,219,' ',219, 219,207,' ',219},
                                                          {219,' ',' ',' ',' ',' ',219,' ',' ',' ',207, ' ',219,207,219},
                                                          {219,219,219,219,219,219,219,219,219,219,219,219,219,42 ,219}};

    unsigned char tela_4[linhas_tela_4][colunas_tela_4]={{219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219},
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
    
    unsigned char tela_5[linhas_tela_5][colunas_tela_5]={{219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219},
                                                         {219,' ',' ',' ',' ',219,219,' ',' ',' ',' ',' ',219,' ',219,' ',' ',' ',' ',219},
                                                         {219,' ',219,219,' ',207,219,' ',219,' ',219,' ',219,' ',' ',207,219,219,' ',219},
                                                         {219,' ',207,' ',219,219,219,' ',219,' ',219,' ',' ',' ',219,' ',219,' ',' ',219},
                                                         {219,' ',219,' ',219,' ',219,' ',' ',219,219,219,219,219,219,' ',219,' ',219,219},
                                                         {219,' ',' ',' ',219,' ',219,' ',219,' ',' ',' ',' ',' ',219,' ',219,' ',' ',219},
                                                         {219,' ',219,219,219,' ',' ',' ',219,' ',219,219,219,219,219,' ',219,219,' ',219},
                                                         {219,' ',' ',207,' ',' ',219,' ',219,' ',219,' ',' ',' ',' ',' ',219,' ',' ',219},
                                                         {219,' ',219,' ',219,219,219,' ',219,' ',219,219,219,219,219,' ',219,' ',219,219},
                                                         {219,' ',219,' ',' ',' ',219,' ',219,' ',' ',' ',219,' ',219,219,219,207,' ',219},
                                                         {219,' ',219,' ',219,' ',219,' ',207,' ',219,' ',219,' ',' ',' ',' ',' ',' ',219},
                                                         {219,' ',219,' ',219,' ',219,' ',219,' ',207,' ',219,207,219,219,219,219,219,219},
                                                         {219,' ',219,' ',219,' ',219,' ',219,219,219,' ',207,' ',' ',' ',' ',' ', ' ',' '},
                                                         {219,' ',' ',' ',219,' ',219,' ',219,' ',219,219,' ',219,219,' ',219,219,207,219},
                                                         {219,' ',219,219,219,' ',219,' ',' ',' ',219,219,' ',' ',219,219,219,219,' ',219},
                                                         {219,' ',207,' ',' ',' ',219,219,219,219,219,' ',219,' ',219,207,' ',' ',' ',219},
                                                         {219,' ',219,219,219,219,219,' ',219,' ',' ',219,' ',' ',219,' ',219,219,219,219},
                                                         {219,' ',219,' ',' ',' ',219,' ',' ',' ',219,219,' ',219,219,' ',219,' ',' ',219},
                                                         {219,' ',' ',' ',219,' ',' ',' ',219,' ',219,' ',' ',' ',219,' ',' ',' ',219,219},
                                                         {219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219, 42,219,219}};
        
FILE *fp;

//****************************************************************************
int teclas(char tela[a][b], int linha, int coluna, char arq[10])
{
int lim_left = posy_inicial + 1;
int lim_right = posy_inicial + coluna - 1;
int lim_top = posx_inicial + 1;
int lim_down = posx_inicial + linha - 1;

  do
    {
      le_tela(tela,a,b,arq);
      placar_jogo();

        gotoxy(x,y); // cursor
        printf("%c",64);
        KEY = tecla();
        porta_secreta=rand()%10;

        if(KEY == 1)//sobe
          {
              gotoxy(60,15);
              //printf("Seta para cima");
              y--;
              movimentos++;
              mira = 1;
                if (x == desl_x + porta_secreta && x < posy_inicial + 1)
              {
                gotoxy(60,5);
                printf("uma porta secreta");
              }
            else if(tela[y-desl_y + 1][x-desl_x + 1] == -37||tela[y-desl_y + 1][x-desl_x + 1] == -49)
                  {

                    gotoxy(60,10); // texto informativo só para saber se encntrou uma barreira
                    //printf("Alvo da Tela = %d",tela[y-desl_y + 1][x-desl_x + 1]);
                    y++;
                  }
                else if(tela[y-desl_y + 1][x-desl_x + 1] == 42)
                        {
                            //printf("Vc ganhou");
                            break;
                        }
              //*********************************************
              else if(y < lim_top)
                y = lim_top;
          }

        else if(KEY == 2)//desce
          {
            gotoxy(60,15);
            //printf("Seta para baixo");
            y++;
            movimentos++;
            mira = 2;

            if (x == desl_x + porta_secreta && x > lim_down)
            {
            gotoxy(60,5);
            printf("uma porta secreta");
              }
            else if(tela[y-desl_y + 1][x-desl_x + 1] == -37||tela[y-desl_y + 1][x-desl_x + 1] == -49)
            {
                gotoxy(60,10);
                //printf("Alvo da Tela = %d",tela[y-desl_y + 1][x-desl_x + 1]);
                y--;
                }
            else if(tela[y-desl_y + 1][x-desl_x + 1] == 42)
              {
                //printf("Vc ganhou");
                break;
              }

            else if(y > lim_down)
            y = lim_down;
            }

          else if(KEY == 3)//esquerda
            {
            gotoxy(60,15);
            //printf("Seta para esquerda");
            x--;
            movimentos++;
            mira = 3;

            if (x == desl_x + porta_secreta && x > lim_left)
                {
                gotoxy(60,5);
                printf("uma porta secreta");
              }
            else if(tela[y-desl_y + 1][x-desl_x + 1] == -37||tela[y-desl_y + 1][x-desl_x + 1] == -49)
                  {
                gotoxy(60,10);
                //printf("Alvo da Tela = %d",tela[y-desl_y + 1][x-desl_x + 1]);
                x++;
                  }
            else if(tela[y-desl_y + 1][x-desl_x + 1] == 42)
            {
              //printf("Vc ganhou");
              break;
            }

              //*********************************************
              else if(x < lim_left)
                x = lim_left;
            }

          else if(KEY == 4)//direita
            {
            gotoxy(60,15);
            //printf("Seta para direita");
            x++;
            movimentos++;
            mira = 4;

            if (x == desl_x + porta_secreta && x < lim_right)
              {
            gotoxy(60,5);
            printf("uma porta secreta");
              }

            else if(tela[y-desl_y + 1][x-desl_x + 1] == -37||tela[y-desl_y + 1][x-desl_x + 1] == -49)
                  {
                gotoxy(60,10);
                //printf("Alvo da Tela = %d",tela[y-desl_y + 1][x-desl_x + 1]);
                x--;
                  }
              else if(tela[y-desl_y + 1][x-desl_x + 1] == 42)
              {
                //printf("Vc ganhou");
                break;
              }
              //*********************************************
             else if(x > lim_right)
                x = lim_right;
                gotoxy(60,10);
            }

          else if(KEY == 5)//espaço tiros
            {
                count = 0;
                if (mira==1)//tiro para cima
                {
                    while(1)
                    {
                        if (tela[(y - desl_y) - count][(x - desl_x) + 1] == -37)
                        {
                            break;
                        }
                        else if (tela[(y - desl_y) - count][(x - desl_x) + 1] == -49)
                            {
                            fp = fopen(arq, "w");
                            gotoxy(60,25);  
                            //printf("Bummmm");
                            fscanf(fp, "%d", tela[(y - desl_y) - count][(x - desl_x) + 1] = 0);
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
                        if (tela[(y - desl_y) + count + 2][(x - desl_x) + 1] == -37)
                        {
                            break;
                        }
                        else if (tela[(y - desl_y) + count + 2][(x - desl_x) + 1] == -49)
                            {
                            fp = fopen(arq, "w");
                            gotoxy(60,25);
                            //printf("Bummmm");
                            fscanf(fp, "%d", tela[(y - desl_y) + count + 2][(x - desl_x) + 1] = 0);
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
                        if (tela[(y - desl_y + 1)][(x - desl_x)  - count] == -37)
                        {
                            break;
                        }
                        else if (tela[(y - desl_y + 1)][(x - desl_x) - count] == -49)
                            {
                            fp = fopen(arq, "w");
                            gotoxy(60,25);
                            //printf("Bummmm");
                            fscanf(fp, "%d", tela[(y - desl_y) + 1][(x - desl_x) - count] = 0);
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
                        if (tela[(y - desl_y + 1)][(x - desl_x)  + count + 2] == -37)
                        {
                            break;
                        }
                        else if (tela[(y - desl_y + 1)][(x - desl_x) + count + 2] == -49)
                            {
                            gotoxy(60,25);
                            fp = fopen(arq, "w");
                            //printf("Bummmm");
                            fscanf(fp, "%d", tela[(y - desl_y) + 1][(x - desl_x) + count + 2] = 0);
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
        }while(1);
}

int escreve_tela(char tela[a][b],int linha,int coluna, char arq[10])
{
    //printf("\n\tAbertura do arquivo %s para criacao", arq);

    if((fp = fopen(arq,"w"))==NULL)
    {
        printf("\n\tNao e possivel criar o arquivo %s", arq);
        exit(1);
    }
    //else
        //printf("\n\tO arquivo %s foi criado\n\n\t", arq);

    for(i = 0; i < linha; i++)
        {
            for(j = 0; j < coluna; j++)
            {
                fprintf(fp,"%d\n", tela[i][j]);
            }
        }

    fclose(fp);
    return(0);
}

int le_tela(char tela[a][b],int linha, int coluna, char arq[10])
{
      if((fp = fopen(arq,"r"))==NULL)
          {
            printf("\n\tNao e possivel abrir o arquivo");
            exit(1);
          }
      else
          {
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
          }


  return 0;
}
 
int placar_final()
{
  int i;
  char *resultado[3];

  classificacao = pontuacao_final; 
  fp = fopen("Placar.txt","a");
  fprintf(fp,"%d\n",classificacao);
  fclose(fp);

  fp = fopen("Placar.txt","r");
  gotoxy(60,4);
  printf("Placar:");

  for (i=0;feof(fp)==0;i++)
  {
    fgets(resultado, 5, fp);
    if (feof(fp)==0)
    {
      gotoxy(60,5+i);
      printf("%s\n",resultado);
    }

  }
  fclose(fp);
  pontuacao_final = 0;
  return 0;
}

int placar_jogo()
{
  int i;
  char *resultado[5];

  fp = fopen("Placar.txt","r");
  gotoxy(60,4);
  printf("Placar:");

  for (i=0;feof(fp)==0;i++)
  {
    fgets(resultado, 5, fp);
    if (feof(fp)==0)
    {
      gotoxy(60,5+i);
      printf("%s\n",resultado);
    }

  }
  fclose(fp);
  return 0;
}

int main()
{
  char arquivo[10];
  mapas=1;
  
  while(mapas<=1)
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
        escreve_tela(tela_1,a,b,arquivo);
        teclas(tela_1,a,b,arquivo);
    }

    else if(mapas==2)
    {
        a=linhas_tela_2;
        b=colunas_tela_2;
        strcpy(arquivo, "Tela_2.txt");
        escreve_tela(tela_2,a,b,arquivo);
        teclas(tela_2,a,b,arquivo);
    }

    else if(mapas==3)
    {
        a=linhas_tela_3;
        b=colunas_tela_3;
        strcpy(arquivo, "Tela_3.txt");
        escreve_tela(tela_3,a,b,arquivo);
        teclas(tela_3,a,b,arquivo);
    }
    
    else if(mapas==4)
    {
        a=linhas_tela_4;
        b=colunas_tela_4;
        strcpy(arquivo, "Tela_4.txt");
        escreve_tela(tela_4,a,b,arquivo);
        teclas(tela_4,a,b,arquivo);
    }
    
    else if(mapas==5)
    {
        a=linhas_tela_5;
        b=colunas_tela_5;
        strcpy(arquivo, "Tela_5.txt");
        escreve_tela(tela_5,a,b,arquivo);
        teclas(tela_5,a,b,arquivo);
    }
    clrscr();
    pontuacao_final = pontuacao_final + movimentos - destruicao;
    printf("Sua pontuacao ate agora: %d", pontuacao_final);
    getch();
    Sleep(1000);
    clrscr();
    cursor_off();
    textcolor(2);
    mapas++;
  }

  system("cls");
  gotoxy(10,2); // posição do texto informativo de qual seta foi usada
  printf("\n Voce fez %d pontos\n ", pontuacao_final);
  placar_final();
  Sleep(5000);
  getch();
  clrscr();
  printf("\nTecle para fechar o programa...");
  getch();
  return 0;
}