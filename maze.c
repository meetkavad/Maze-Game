#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

char maze[32][32];

int start ,end;
int  pi,pj;

char name[20];
char pname[20];
char p1name[20];
char p2name[20];


int opt1;
int times;
int hs;
char bin;
char bin2;
char bin3;
char diamond ='\4';
char heart ='\3';
char club ='\5';
char arrow =16;
char wall =176;
char vbound=178;
char hbound=22;
char fruit =149;
char pii=227;
char enter;
int score1;

int lifeline= 3;
int moves=120;
char armour=233;
int score=800;


void printrules();
void printintro();
void resetmaze();//clearing everything by generating space at every place.
void printmaze();
void setmaze();//generating fruit,hearts,etc.
void move();
int checkll();
void printresult();
// void copymain(); if x is pressed then to perform same things we cant call main from move function thats why !!
int ispossiblepath();
void singleplayer();
void setdoubleplayer();
void doubleplayer();


int main()
{
printintro();

printf("\nselect Mode(1 or 2):\n1.single player\n2.Two players\n");
scanf("%d", &opt1);

if(opt1==1)
{
singleplayer();
}

if(opt1==2)
{
  setdoubleplayer();
}

}

void printmaze()
{

  printf("\n");
for (int i =0;i<lifeline;i++)
{
    printf("%c ",heart);
}

printf("\t%c:%d",armour,moves);
printf("\n");



int z=0;
printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 printf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",  maze[z][0], maze[z][1], maze[z][2], maze[z][3], maze[z][4], maze[z][5], maze[z][6], maze[z][7],maze[z][8], maze[z][9],maze[z][10],maze[z][11],maze[z][12], maze[z][13], maze[z][14], maze[z][15], maze[z][16], maze[z][17], maze[z][18], maze[z][19],maze[z][20], maze[z][21],maze[z][22],maze[z][23],maze[z][24], maze[z][25], maze[z][26], maze[z][27], maze[z][28], maze[z][29], maze[z][30], maze[z][31],maze[z][32]);
 z++;
 
}
 
void resetmaze()
{
for(int i =1; i<31 ;i++)
{
    for (int j =1; j<31; j++)
    {
        maze[i][j]=' ';
    }
}
}

void setmaze()
{
 
srand(time(0));
start=rand()%31;
end=rand()%31; 
while(start ==0 || end==0)
{
start = rand()%31;
end=rand()%31;
}

  pi=start;
  pj=1;

  int x,y,m,n;
  srand(time(0));

  for(int i =0; i<300;i++)
  {
      x=rand()%31;
      y=rand()%31;

      if(x!=0 && y!=0)
      maze[x][y]=wall;
      else
      i--;
    
  }
  for(int i =0;i<2;i++)
  {

      m=rand()%31;
      n=rand()%31;

      if(m!=0 && n!=0)
      maze[m][n]=heart;
      else
      i--;
  }
  for(int i =0;i<2;i++)
  {

      m=rand()%31;
      n=rand()%31;

      if(m!=0 && n!=0 && maze[m][n]!=heart)
      maze[m][n]=armour;
      else
      i--;
  }
  for(int i =0;i<1;i++)
  {

      m=rand()%31;
      n=rand()%31;

      if(m!=0 && n!=0 && maze[m][n]!=heart && maze[m][n]!=armour )
      maze[m][n]=fruit;
      else
      i--;
  }

    for(int i =0;i<1;i++)
  {

      m=rand()%31;
      n=rand()%31;

      if(m!=0 && n!=0 && maze[m][n]!=heart && maze[m][n]!=armour && maze[m][n]!=fruit )
      maze[m][n]=pii;
      else
      i--;
  }

for (int i =0; i<32;i++)
{
  maze[0][i]=hbound;
  maze[31][i]=hbound;
  maze[i][0]=vbound;
  maze[i][31]=vbound;
}
maze[0][31]=' ';
maze[0][0]=' ';
maze[31][0]=' ';
maze[31][31]=' ';


maze[start][1]='S';
maze[end][30]='E';

maze[start][0]=' ';
maze[end][31]=' ';

}

 int ispossiblepath()
 {
  
//     while((maze[pi+1][pj] !='|'   || maze[pi][pj+1] !='|' )  && pi!=10)
//   {
//     while(maze[pi][pj+1]!='|')
//     {
//       pj++;
//     }
//     while(maze[pi+1][pj]!='|' && maze[pi+1][pj]!='-')
//     {
//       pi++;
//     }
//   }
 

//   while((maze[pi+1][pj] !='-'   || maze[pi][pj+1] !='|' )  && pi==10)
//   {
//     while(maze[pi][pj+1]!='|')
//     {
//       pj++;
//     }
  
//   }

//   if(pi==1 && pj==1)
//   return 0; 
//   if(pi==10 && pj==10)
//   return 1;


//   if(maze[pi+1][pj]=='-' && maze[pi][pj+1]=='|')
//  {
//   if(maze[pi-1][pj]=='|')
//   pj--;

//   while(maze[pi][pj+1]=='|' || maze[pi][pj+2]=='|')
//   {
//     pi--;
//   }
  
// while((maze[pi+1][pj] !='|'   || maze[pi][pj+1] !='|' )  && pi!=10)
//   {
//     while(maze[pi][pj+1]!='|')
//     {
//       pj++;
//     }
//     while(maze[pi+1][pj]!='|' && maze[pi+1][pj]!='-')
//     {
//       pi++;
//     }
//   }
 

//   while((maze[pi+1][pj] !='-'   || maze[pi][pj+1] !='|' )  && pi==10)
//   {
//     while(maze[pi][pj+1]!='|')
//     {
//       pj++;
//     }
   
//   }
  
//  }
//   if(pi==10 && pj==10)
//   return 1;



//   for (int k =0 ; k<20; k++)
//   {

    
      
//   if(maze[pi+1][pj]=='-' && maze[pi][pj+1]=='|')
//  {
//   if(maze[pi-1][pj]=='|')
//   pj--;

//   while(maze[pi][pj+1]=='|' || maze[pi][pj+2]=='|')
//   {
//     pi--;
//   }
 
//   while((maze[pi+1][pj] !='|'   || maze[pi][pj+1] !='|' )  && pi!=10)
//   {
//     while(maze[pi][pj+1]!='|')
//     {
//       pj++;
//     }
//     while(maze[pi+1][pj]!='|' && maze[pi+1][pj]!='-')
//     {
//       pi++;
//     }
//   }
 

//   while((maze[pi+1][pj] !='-'   || maze[pi][pj+1] !='|' )  && pi==10)
//   {
//     while(maze[pi][pj+1]!='|')
//     {
//       pj++;
//     }
   
//   }
//      if(pi==10 && pj==10 )
//     return 1;

//     }
     
    
    
    
     
//     else if(maze[pi][pj-1]!='|')
//     {
//     pj--;
//     if(maze[pi+1][pj]!='|' || maze[pi+1][pj]!='-')
//     {
//     while((maze[pi+1][pj] !='|'   && maze[pi][pj+1] !='|' )  && pi!=10)
//   {
//     while(maze[pi][pj+1]!='|')
//     {
//       pj++;
//     }
//     while(maze[pi+1][pj]!='|' || maze[pi+1][pj]!='-')
//     {
//       pi++;
//     }
//   }
 

//   while((maze[pi+1][pj] !='-'   || maze[pi][pj+1] !='|' )  && pi==10)
//   {
//     while(maze[pi][pj+1]!='|')
//     {
//       pj++;
//     }
    
//   }
//     }
//      if(pi==10 && pj==10 )
//  return 1;
//  }

   
    
//     else
//     {
//       pi--;
//       if(maze[pi][pj+1]!=1)
//       {
//          while((maze[pi+1][pj] !='|'   && maze[pi][pj+1] !='|' )  && pi!=10)
//   {
//     while(maze[pi][pj+1]!='|')
//     {
//       pj++;
//     }
//     while(maze[pi+1][pj]!='|' || maze[pi+1][pj]!='-')
//     {
//       pi++;
//     }
//   }
 

//   while((maze[pi+1][pj] !='-'   || maze[pi][pj+1] !='|' )  && pi==10)
//   {
//     while(maze[pi][pj+1]!='|')
//     {
//       pj++;
//     }
  
//   }
      
//       }
      
//     if(pi==10 && pj==10 )
//  return 1;
//     }

//   }
 
//  if(pi==10 && pj==10 )
//  return 1;
//  else
//  return 0;

 

 
 }

void move()
{
  
  char move;
  printf("move:\n");
  for(int i =0; i<2; i++)
  scanf("%c",&move);
  
  if(move=='s') 
  {
    moves--;
    if(moves<80)
    score-=10;


    if(maze[pi+1][pj]==' '|| maze[pi+1][pj]=='.' || maze[pi+1][pj]=='E')
    {
    maze[pi][pj]='.';
    pi++;
    maze[pi][pj]='*';
    printmaze();
    }
    else if(maze[pi+1][pj]==hbound|| maze[pi+1][pj]==wall )
    {
        lifeline--;
        Beep(200,500);
        if(checkll()!=0)
        printmaze();
        

    }

    else if(maze[pi+1][pj]==heart)
    {
      if(lifeline<3)
       lifeline++;

       maze[pi][pj]='.';
    pi++;
    maze[pi][pj]='*';
    printmaze();
    }
    else if(maze[pi+1][pj]==armour)
    {
      if(moves<=115)
      {
        
        if(moves<=75)
      {
        score+=50;
      }
        else if(moves>75 && moves<80)
       {score+=(80-moves)*10;
       }
      moves+=5;
      }
      else if(moves >115)
      moves =120;

      
    maze[pi][pj]='.';
    pi++;
    maze[pi][pj]='*';
    printmaze();
    }
     
     else if (maze[pi+1][pj]==fruit)
     {
      score +=50;
      maze[pi][pj]='.';
    pi++;
    maze[pi][pj]='*';
    printmaze();
     }
   
    else if (maze[pi+1][pj]==pii)
     {
      
    maze[pi][pj]='.';
    srand(time(0));
    pi=rand()%31;
    pj=rand()%31;
    
    while(pi==0 || pj==0)
    {
       pi=rand()%31;
       pj=rand()%31;
    }

    maze[pi][pj]='*';
    printmaze();
     }
  } 
  else if(move=='d') 
  {

    moves--;
    if(moves<80)
    score-=10;


    if(maze[pi][pj+1]==' '|| maze[pi][pj+1]=='.'||  maze[pi][pj+1]=='E' )
    {
    maze[pi][pj]='.';
    pj++;
    maze[pi][pj]='*';
    printmaze();
    }

     else if(maze[pi][pj+1]==wall ||maze[pi][pj+1]==vbound )
    {
        lifeline--;
         Beep(200,500);
        if(checkll()!=0)
        printmaze();
        

    }
     else if(maze[pi][pj+1]==heart)
    {   if(lifeline<3)
       lifeline++;

       maze[pi][pj]='.';
    pj++;
    maze[pi][pj]='*';
    printmaze();
    }
    else if(maze[pi][pj+1]==armour)
    {
      if(moves<=115)
      {
        if(moves<=75)
      {
        score+=50;
      }
        else {
      score+=(80-moves)*10;}
      
      moves+=5;
      }
      else if(moves >115)
      moves =120;

      
    maze[pi][pj]='.';
    pj++;
    maze[pi][pj]='*';
    printmaze();
    }
   
     else if (maze[pi][pj+1]==fruit)
     {
      score +=50;
      maze[pi][pj]='.';
    pj++;
    maze[pi][pj]='*';
    printmaze();
     }

     else if (maze[pi][pj+1]==pii)
     {
      
    maze[pi][pj]='.';
    srand(time(0));
    pi=rand()%31;
    pj=rand()%31;
    
    while(pi==0 || pj==0)
    {
       pi=rand()%31;
       pj=rand()%31;
    }

    maze[pi][pj]='*';
    printmaze();
     }
  } 
  else if(move=='a') 
  {
    moves--;
    if(moves<80)
    score-=10;

    if(maze[pi][pj-1]==' '|| maze[pi][pj-1]=='.' || maze[pi][pj-1]=='E')
    {
    maze[pi][pj]='.';
    pj--;
    maze[pi][pj]='*';
    printmaze();
    }
    else if(maze[pi][pj-1]==vbound || maze[pi][pj-1]==wall)
    {
        lifeline--;
         Beep(200,500);
        if(checkll()!=0)
        printmaze();
       

    }
    else if(maze[pi][pj-1]==heart)
    {   if(lifeline<3)
       lifeline++;

       maze[pi][pj]='.';
    pj--;
    maze[pi][pj]='*';
    printmaze();
    }

    else if(maze[pi][pj-1]==armour)
    {
      if(moves<=115)
      {
        if(moves<=75)
      {
        score+=50;
      }
        else if(moves >75){
      score+=(80-moves)*10;}
       
       moves+=5;
      }
    else if(moves >115)
      moves =120;

      
    maze[pi][pj]='.';
    pj--;
    maze[pi][pj]='*';
    printmaze();
    }

     else if (maze[pi][pj-1]==fruit)
     {
      score +=50;
      maze[pi][pj]='.';
    pj--;
    maze[pi][pj]='*';
    printmaze();
     }

     else if (maze[pi][pj-1]==pii)
     {
      
    maze[pi][pj]='.';
    srand(time(0));
    pi=rand()%31;
    pj=rand()%31;
    
    while(pi==0 || pj==0)
    {
       pi=rand()%31;
       pj=rand()%31;
    }

    maze[pi][pj]='*';
    printmaze();
     }
  } 
  else if(move=='w') 
  {
    moves--;
    if(moves<80)
    score-=10;

    if(maze[pi-1][pj]==' '|| maze[pi-1][pj]=='.' ||maze[pi-1][pj]=='E')
    {
    maze[pi][pj]='.';
    pi--;
    maze[pi][pj]='*';
    printmaze();
    }
   
    else if(maze[pi-1][pj]== hbound || maze[pi-1][pj]==wall)
    {
        lifeline--;
         Beep(200,500);
        if(checkll()!=0)
        printmaze();
       

    }
       else if(maze[pi-1][pj]==heart)
    {
      if(lifeline<3)
       lifeline++;

       maze[pi][pj]='.';
    pi--;
    maze[pi][pj]='*';
    printmaze();
    } 

    else if(maze[pi-1][pj]==armour)
    {
      if(moves<=115)
      {
        if(moves<=75)
      {
        score+=50;
      }
        else if(moves >75){
      score+=(80-moves)*10;}
      
      move+=5;
      }
      else if(moves >115)
      moves =120;

      
    maze[pi][pj]='.';
    pi--;
    maze[pi][pj]='*';
    printmaze();
    }
     else if (maze[pi-1][pj]==fruit)
     {
      score +=50;
      maze[pi][pj]='.';
    pi--;
    maze[pi][pj]='*';
    printmaze();
     }
   
   else if (maze[pi-1][pj]==pii)
     {
      
    maze[pi][pj]='.';
    srand(time(0));
    pi=rand()%31;
    pj=rand()%31;
    
    while(pi==0 || pj==0)
    {
       pi=rand()%31;
       pj=rand()%31;
    }

    maze[pi][pj]='*';
    printmaze();
     }
}

else if(move=='x')
{
int play;
printf("1.restart\n2.Exit\n");
scanf("%d", &play);

if(opt1==1)
{
if(play==1 )
{
  singleplayer();
  exit(0);
}
else
exit(0);
}

else if(opt1==2)
{
if(play==1 )
{
  setdoubleplayer();
  exit(0);
}
else
exit(0);
}

}

else if(move =='r')
{
   printf("\nhehe..... here we go....\n");
   printrules();

}

}

int checkll()
{
    return lifeline;
}

void printresult()
{

  FILE *fname;
  fname=fopen("name.txt","r");
  fscanf(fname,"%s",pname);
  fclose(fname);

  FILE *fhs;
   fhs= fopen("hs.txt","r");
   fscanf(fhs, "%d",&hs);
   fclose(fhs);
   

    if(checkll()==0 || moves==0)
    {
      
    printf("\n\nSHAME ON YOU!! YOU LOST THE EASIEST GAME ON THE PLANET\n\n");
    printf("see the high score : %d\nHIGH SCORER: %s\n\n",hs , pname);
  
    }

    if(pi==end && pj==30)
    {
      if(lifeline!=3){
      printf("\n\nYOU WON!!! \nscore:%d\n", score);
      if(score>hs)
      {
        printf("hurrahh!! you made the high score!!!");
        hs=score;
        fhs=fopen("hs.txt","w");
        fprintf(fhs,"%d",hs);
        fclose(fhs);
        strcpy(pname,name);
        fname=fopen("name.txt","w");
        fprintf(fname,"%s",pname);
        fclose(fname);
        
      }
      else
      {
        printf("\n\nHIGHEST SCORE: %d by %s\n\n", hs,pname );
      }
      }
      else {
      printf("\n\nYOU WON!!! \nscore:%d\n", score+50);
      if((score+50)>hs)
      {
        printf("hurrahh!! you made the high score!!!");
        hs=score+50;
        fhs=fopen("hs.txt","w");
        fprintf(fhs,"%d",hs);
        fclose(fhs);
        strcpy(pname,name);
        fname=fopen("name.txt","w");
        fprintf(fname,"%s",pname);
        fclose(fname);
        
      }
      else
      {
        printf("\n\nHIGHEST SCORE: %d\nHIGH SCORER: %s\n\n", hs,pname );
      }
      }
    }

}
    
void printintro()
{
  

printf("\n\n");
printf("           MEET KAVAD              \n");Beep(300,400);
printf("            presents               \n");Beep(411,400);


printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound);
Beep(300,400);
printf("        THE FUNTASTIC MAZE           \n");Beep(411,400);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound);
Beep(600,400);

}

void printrules()
{
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound);

printf("\nINSTRUCTIONS:\n%cStarting position:S\t\t%cDestination:E\n%cCurrent position :'*'\t\t",arrow,arrow,arrow);
printf("%cBarriers:'%c'\n%cMystery element: '%c'\n",arrow,wall,arrow,pii);
printf("%cLifelines:3\t\t        %cMoves:120\n\n",arrow,arrow);
printf("%cIf you reach E,you WIN!\n%cIf you collide with any wall you lose your lifeline.\n%cWhile going if you lose all your three lifelines or if you are out of moves, you LOSE!\n%cIf at any moment you feel the maze is unsolvable or you want to exit,press X.\n\n%cCollect %c to get extra 5 moves!\n%cCollect %c to get extra 50 points!!\n%cCollect %c to make a mysterious move!!!\n",arrow, arrow ,arrow, arrow , arrow,armour,arrow, fruit,arrow,pii);
printf("%cIf you win with three lifelines in your hand, you get 50 extra points!\n", arrow);
printf("%cPress r to read rules at any instant in the game\n\n", arrow);
printf("%cControls:\n1.press w: up\t\t2.press s: down\t\t3.press a: left\t\t4.press d: right\n\n",arrow);
printf("IMPORTANT: press SPACEBAR prior to the move if it doesn't execute in one go!!\n\n");

printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound,hbound);

printf("press enter to start the game...\n");

for(int i =0 ; i<2;i++)
scanf("%c", &enter);

}

void singleplayer()
{
printf("enter your name:\n");
scanf("%s", name);

int opt2;
printf("\nselect(1 or 2)\n1.read instructions(recommended for new players)\n2.start the game\n");
scanf("%d",&opt2);

if(opt2==1)
printrules();

if(enter =='\n'|| opt2==2)
{
resetmaze();
setmaze();
printf("\n\n              %c GAME ON %c            \n\n\n", diamond, diamond);
printmaze();


while((pi!=end || pj!=30) && lifeline!=0 && moves>0 )
move();

printresult();
}

else 
printf("Follow the instructions to play the game!\n");

}

void setdoubleplayer()

{
   char opt3;
  printf("If you are a new player, experience the single player mode to understand the game better!\n");
  printf("press enter continue  or press x to exit : \n");
 for(int i =0 ;i<2;i++)
 scanf("%c", &opt3);


   if(opt3=='\n')
   {
  printf("\nenter names:\nplayer 1: ");
  scanf("%s", p1name);
  printf("player 2: ");
  scanf("%s", p2name);

 printf("\n    TOSS TIME: ");
 printf("\n\n%s : heads",p1name);
 printf("\n%s : tails \n\n",p2name);
 
 printf("press enter to spin the coin : \n");
 for(int i =0 ;i<2;i++)
 scanf("%c", &bin);
 printf("Coin in the Air");

 for(int i=0 ;i<5;i++)
 {
   printf(".");
   Beep(0,400);
 }
 printf("\n\n");

 srand(time(0));
 int j =rand()%2;
 int k;

 if(j==0)
 {
  printf("   HEADS!!!!\n\n");
  printf("%s won the toss!! what do you want to do: \n",p1name);
  printf("1.set a target\n");
  printf("2.chase the target\n");
  scanf("%d", &k);
  

  if(k==1)
  {
  printf("%s's play:\n",p1name);
  printf("press enter to start the game:");
  for(int i =0 ;i<2;i++)
  scanf("%c",&bin3);

  doubleplayer();

  // FILE *fsc;
  // fsc=fopen("score1.txt","w");
  // fprintf(fsc,"%d",score);
  // fclose(fsc);

  score1=score;

  printf("%s's score: %d\n",p1name,score);
  printf("%s need %d to win !!!\n",p2name,score+5);
  
  printf("press enter to start %s's play:\n",p2name);
  for(int i =0 ;i<2;i++)
  scanf("%c",&bin2);

  score=800;
  moves=120;
  lifeline=3;

  doubleplayer();
  printf("%s's score: %d\n",p2name,score);
  if(score1>score)
  printf("\n%s won the game!!",p1name);
  else
  printf("\n%s won the game!!",p2name);
  
  }
  else
  {
  printf("%s's play:\n",p2name);
   printf("press enter to start the game:");
  for(int i =0 ;i<2;i++)
  scanf("%c",&bin3);

  doubleplayer();

   score1=score;

  printf("%s's score: %d\n",p2name,score);
  printf("%s need %d to win !!!\n",p1name,score+5);
  
  printf("press enter to start %s's play:\n",p1name);
  for(int i=0 ;i<2;i++)
  scanf("%c",&bin2);

  score=800;
  moves=120;
  lifeline=3;

  doubleplayer();
  printf("%s's score: %d\n",p1name,score);
  if(score1>score)
  printf("\n%s won the game!!",p2name);
  else
  printf("\n%s won the game!!",p1name);
  }
 }

 else
 {
  printf("   TAILS!!!!\n\n");
  printf("%s won the toss!! what do you want to do: \n",p2name);
  printf("1.set a target\n");
  printf("2.chase the target\n");
  scanf("%d",&k);

  if(k==1)
  {
  printf("%s's play:\n",p2name);
   printf("press enter to start the game:");
  for(int i =0 ;i<2;i++)
  scanf("%c",&bin3);

  doubleplayer();
  
  score1=score;

  printf("%s's score: %d\n",p2name,score);
  printf("%s need %d to win !!!\n",p1name,score+5);
  
  printf("press enter to start %s's play:\n",p1name);
  for(int i=0 ;i<2;i++)
  scanf("%c",&bin2);

  score=800;
   moves=120;
  lifeline=3; 
  doubleplayer();
  printf("%s's score: %d\n",p1name,score);
  if(score1>score)
  printf("\n%s won the game!!",p2name);
  else
  printf("\n%s won the game!!",p1name);

  }
  else
  {
  printf("%s's play:\n",p1name);
   printf("press enter to start the game:");
  for(int i =0 ;i<2;i++)
  scanf("%c",&bin3);

  doubleplayer();
   score1=score;

  printf("%s's score: %d\n",p1name,score);
  printf("%s need %d to win !!!\n",p2name,score+5);
  
  printf("press enter to start %s's play:\n",p2name);
  for(int i =0 ;i<2;i++)
  scanf("%c",&bin2);

  score=800;
    moves=120;
  lifeline=3;
  doubleplayer();
  printf("%s's score: %d\n",p2name,score);
  if(score1>score)
  printf("\n%s won the game!!",p1name);
  else
  printf("\n%s won the game!!",p2name);
  }

 }
}

   else
   exit(0);

}

void doubleplayer()
{
resetmaze();
setmaze();
printf("\n\n              %c GAME ON %c            \n\n\n", diamond, diamond);
printmaze();


while((pi!=end || pj!=30) && lifeline!=0 && moves>0 )
move();

}


