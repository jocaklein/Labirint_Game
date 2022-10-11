#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "le_teclas.h"
#include "my_lib.h"

#define linhas_tela_1      10
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

#define desl_x      7
#define desl_y      7

#define posx_inicial 6
#define posy_inicial 6


int i,j,x,y,a,b,habilita_tela, tela_aberta;

FILE *fp;


int Escreve_tela(char tela[a][b],int linha,int coluna, char arq[10])
{
    printf("\n\tAbertura do arquivo %s para criacao", arq);

    if((fp = fopen(arq,"w"))==NULL)
    {
        printf("\n\tNao e possivel criar o arquivo %s", arq);
        exit(1);
    }
    else
        printf("\n\tO arquivo %s foi criado\n\n\t", arq);

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

int le_tela(char tela[a][b],int linha,int coluna, char arq[10])
{
    printf("\n\tAbertura de arquivo para leitura");

    if((fp = fopen(arq,"r"))==NULL)
        {
            printf("\n\tNao e possivel abrir o arquivo");
            exit(1);
        }
    else
        {
            printf("\n\tO arquivo foi aberto\n\n\t");
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
    return(0);
}

void main()
{
    char arquivo[10];
    tela_aberta=0;

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
    

    a=linhas_tela_1;
    b=colunas_tela_1;
    strcpy(arquivo, "Tela_1.txt");
    Escreve_tela(tela_1,a,b,arquivo);

    a=linhas_tela_2;
    b=colunas_tela_2;
    strcpy(arquivo, "Tela_2.txt");
    Escreve_tela(tela_2,a,b,arquivo);

    a=linhas_tela_3;
    b=colunas_tela_3;
    strcpy(arquivo, "Tela_3.txt");
    Escreve_tela(tela_3,a,b,arquivo);
/*
    if (habilita_tela==1)
    {
        a=linhas_tela_1;
        b=colunas_tela_1;
        strcpy(arquivo, "Tela_1.txt");
        le_tela(tela_1,a,b,arquivo);
        tela_aberta=1;
    }

    else if(habilita_tela==2)
    {
        a=linhas_tela_2;
        b=colunas_tela_2;
        strcpy(arquivo, "Tela_2.txt");
        le_tela(tela_2,a,b,arquivo);
        tela_aberta=2;
    }

    else if(habilita_tela==3)
    {
        a=linhas_tela_3;
        b=colunas_tela_3;
        strcpy(arquivo, "Tela_3.txt");
        le_tela(tela_3,a,b,arquivo);
        tela_aberta=3;
    }

    habilita_tela=0;
*/
    return tela_aberta;
}