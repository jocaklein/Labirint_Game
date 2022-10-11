#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "le_teclas.h"
#include "my_lib.h"

#define linhas      10
#define colunas     10

#define lim_x_left  7
#define lim_x_right 14
#define lim_y_top    7
#define lim_y_down  14

#define desl_x      7
#define desl_y      7

#define posx_inicial 6
#define posy_inicial 6

//****************************************************************************
unsigned char tela_1[linhas][colunas]= { {219,219,219,219,219,219,219,219,219,219},
                                         {219,' ',219,' ',' ',219,' ',219,' ',219},
                                         {219,' ',219,' ',' ',219,' ',219,' ',219},
                                         {219,' ',219,' ',' ',219,' ',' ',' ',219},
                                         {219,' ',219,' ',219,' ',' ',219,' ',219},
                                         {219,' ',219,219,219,' ',219,219,' ',219},
                                         {219,' ',219,' ',' ',' ',' ',219,' ',219},
                                         {219,' ',219,' ',219,219,' ',219,' ',219},
                                         {219,' ',' ',' ',219,' ',' ',219,42 ,219},
                                         {219,219,219,219,219,219,219,219,' ',219}};

unsigned char tela_2[linhas][colunas]= { {219,219,219,219,219,219,219,219,219,219},
                                         {219,' ',219,' ',' ',219,' ',' ',' ',219},
                                         {219,' ',' ',' ',' ',219,' ',219,' ',219},
                                         {219,' ',219,219,' ',219,' ',219,' ',219},
                                         {219,' ',' ',' ',219,' ',' ',219,' ',219},
                                         {219,219,219,' ',219,' ',219,219,' ',219},
                                         {219,' ',' ',' ',' ',' ',' ',219,' ',219},
                                         {219,' ',219,' ',219,219,' ',219,' ',219},
                                         {219,' ',' ',' ',' ',' ',219,219,42 ,219},
                                         {219,219,219,219,219,219,219,219,' ',219}};

unsigned char tela_3[linhas][colunas]= { {219,219,219,219,219,219,219,219,219,219},

                                         {219,' ',219,' ',' ',219,' ',' ',' ',219},
                                         {219,' ',' ',' ',' ',219,' ',219,' ',219},
                                         {219,' ',219,219,' ',219,' ',219,' ',219},
                                         {219,' ',' ',' ',219,' ',' ',219,' ',219},
                                         {219,219,219,' ',219,' ',219,219,' ',219},
                                         {219,' ',' ',' ',' ',' ',' ',219,' ',219},
                                         {219,' ',219,' ',219,219,' ',219,' ',219},
                                         {219,' ',' ',' ',' ',' ',219,219,42 ,219},
                                         {219,219,219,219,219,219,219,219,' ',219}};

int i=0,j=0,x=0,y=0,num_map=1, porta_secreta=0;
char KEY;
//****************************************************************************
int main()
{
        cursor_off();
        textcolor(2);
        printf("\n\tNivel %d", num_map);
        textcolor(15);
        x = desl_x;
        y = desl_y;
        //****************************************************
        gotoxy(60,1);
        printf("\tX = %2d -- Y = %2d", x ,y);
        gotoxy(x,y);
        printf("%c",64);
    do
    {

        for(i = 0; i < linhas; i++)
        {
        for(j = 0; j < colunas; j++)
            {
            gotoxy(j + posx_inicial ,i + posy_inicial );
            if (num_map == 1){
                printf("%c", tela_1[i][j]);
                }
                else if (num_map == 2){
                    printf("%c", tela_2[i][j]);
                }
                else if (num_map == 3){
                    tela_1[i][j]==tela_3[i][j];
                }
                else{break;}
            }
        }

        gotoxy(x,y); // cursor
        printf("%c",64);

        KEY = tecla();
        gotoxy(69,3); // posição do texto informativo de qual seta foi usada
        printf("                         ");
        gotoxy(69,3);
        porta_secreta=rand()%10;

        if(KEY == 1)//sobe
          {
              printf("Seta para cima");
              y--;
                if (x == desl_x + porta_secreta && x < lim_y_top)
              {
                gotoxy(60,10);
                printf("uma porta secreta");
              }
              else if(tela_1[y-desl_y + 1][x-desl_x + 1] == 219)
                  {

                    gotoxy(60,17); // texto informativo só para saber se encntrou uma barreira
                    printf("Alvo da Tela = %d",tela_1[y-desl_y + 1][x-desl_x + 1]);
                    y++;
                  }
                else if(tela_1[y-desl_y + 1][x-desl_x + 1] == 42)
                        {
                            printf("Vc ganhou");
                            break;
                        }
              //*********************************************
              else if(y < lim_y_top)
                y = lim_y_top;
          }

        else if(KEY == 2)//desce
          {
            printf("Seta para baixo");
            y++;
            if (x == desl_x + porta_secreta && x < lim_y_down)
            {
            gotoxy(60,10);
            printf("uma porta secreta");
              }
            else if(tela_1[y-desl_y + 1][x-desl_x + 1] == 219)
            {
                gotoxy(60,17);
                printf("Alvo da Tela = %d",tela_1[y-desl_y + 1][x-desl_x + 1]);
                y--;
                }

            else if(y > lim_y_down)
            y = lim_y_down;
            }

          else if(KEY == 3)//esquerda
            {
            printf("Seta para esquerda");
            x--;
            if (x == desl_x + porta_secreta && x < lim_x_left)
                {
                gotoxy(60,10);
                printf("uma porta secreta");
              }
              else if(tela_1[y-desl_y + 1][x-desl_x + 1] == 219)
                  {
                gotoxy(60,17);
                printf("Alvo da Tela = %d",tela_1[y-desl_y + 1][x-desl_x + 1]);
                x++;
                  }

              //*********************************************
              else if(x < lim_x_left)
                x = lim_x_left;
            }

          else if(KEY == 4)//direita
            {
            printf("Seta para direita");
            x++;

            if (x == desl_x + porta_secreta && x < lim_x_right)
              {
            gotoxy(60,10);
            printf("uma porta secreta");
              }
            else if(tela_1[y-desl_y + 1][x-desl_x + 1] == 219)
                  {
                gotoxy(60,17);
                printf("Alvo da Tela = %d",tela_1[y-desl_y + 1][x-desl_x + 1]);
                x--;
                  }
              //*********************************************
             else if(x > lim_x_right)
                x = lim_x_right;
                gotoxy(60,10);
            }

          else if(KEY == 5)
            printf("Barra de espaco");
          else if(KEY == 7)
            printf("Tab esquerdo");
          else if(KEY == 8)
            printf("Tab direito");
          else if(KEY == 6)
          {
              printf("ESC");
              break;
          }

          else if(tela_1[y-desl_y + 1][x-desl_x + 1] == 42)//vitoria
            {
            system("cls");
            break;
            }

            //clrscr();
            gotoxy(x-1,y-1); // cursor
            printf("%c",64);

        }while(1);

         printf("Saiu da rotina de teclas....");
         printf("Tecle para fechar o programa..");
         getch();
     //*************************************************
     //  aqui pode ser feita outro loop para outra fase
     //*************************************************


     //*************************************************
 return 0;
}
