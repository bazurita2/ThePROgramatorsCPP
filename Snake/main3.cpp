//Created by Raza Ul Mustafa
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include<ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>
int n;
using namespace std;
bool GO;
const int w= 40;
const int h= 20;
int x,y,appleX,appleY,sco1;
int snakeX[150],snakeY[150];
int nSnake;
enum eDirection{ STOP=0, LEFT, RIGHT, UP, DOWN };
eDirection direction ;

void initial()
{
    GO=false;
    direction= STOP;
    x=w/2 ;
    y=h/2;
    appleX=rand()%w;
    appleY=rand()%h;
    sco1=0;
}
void board()
{
    system("cls");

    for(int i=0;i<w+2;i++)//to make first border(upper)
    {
        cout<< "*";
    }
    cout<< "\n";
        for(int i=0;i<h;i++)//inner loop and outer loop to print border sequentially
        {
            for(int j=0;j<w;j++)
            {
                if (j == 0)
                {
                    cout<< "*";//to make left border
                }
                    if(i==y&&j==x)//To initialize head of snake in middle
                    {
                        cout<< "O";
                    }
                    else if(i==appleY&&j==appleX)//set apple and When O comes to the apple that snake needs to eat it will print another one in a random position
                            {
                            cout<< "a";
                            }
                   else
                   {
                       bool print =false;
                       for(int k=0;k< nSnake; k++)
                       {
                           if(snakeX[k]==j&&snakeY[k]==i)//When  O comes to apple it will print another o behind it
                           {
                               cout<< "o";
                               print = true;
                           }
                     }
                               if(!print)//if it doesnt eat anything it will print spaces
                     cout<< " ";
                   }
                if (j==w-1)
                {
                    cout<<"*";//to make the right border
                }
            }
            cout<<"\n";
        }
    for(int i=0;i<w+2;i++)
    {
        cout<< "*";//to make the last border
    }
    cout<< "\n";
    cout<< "Score:  " <<sco1;//will print score
}

void Input()
{
  if(_kbhit())//Command for pressing any key on keyboard
  {
      switch(_getch())//will get a character
      {
      case 'a'://direction specified
        direction = LEFT;
        break;
        case 'd':
        direction = RIGHT;
        break;
        case 'w':
        direction = UP;
        break;
        case 's':
        direction = DOWN;
        break;
        case 'x':
        GO = true;//to exit program in middle of the game
        break;
      }
  }
}
void function()
{
    int lastX = snakeX[0];
    int lastY = snakeY[0];
    int last2X, last2Y;
    snakeX[0]=x;
    snakeY[0]=y;

    for(int i=1;i<nSnake;i++)//loop for increment in snake size by pacing o's
    {
        last2X=snakeX[i];
        last2Y=snakeY[i];
        snakeX[i]=lastX;
        snakeY[i]=lastY;
        lastX=last2X;
        lastY=last2Y;

    }

 switch(direction)// to get snake into direction by x and y axis
 {
     case LEFT:
     x--;//x-axis decrement(-x)
     break;
       case RIGHT:
     x++;//x-axis increment(+x)
     break;
       case UP:
     y--;//y-axis decrement(-y)
     break;
       case DOWN:
     y++;//y-axis increment(+y)
     break;
       default:
        break;
 }
 if (n==1)
 {
     if(x<0 || x>w-1 || y<0 || y>h-1)
     {
       for (int i=0;i<nSnake;i++)
    {
    if(snakeX[i]==x && snakeY[i]==y)//if the snake collides then game over
    {
     GO=true;
    }
    }
    }
 }
 else if (n==2)
 {
   if(x>=w)//if the snake gets out the width of border it will intialize it with 0 from initial
   {
       x=0;
    }
   else if (x<0)// if the snake is less than the initial value it will initialize it from the max width
   {
       x=w-1;
   }
   if(y >=h )//same goes for y-axis both incase of height
   {
       y=0;
   }
   else if (y<0)
   {
       y=h-1;
   }
    for (int i=0;i<nSnake;i++)
    {
    if(snakeX[i]==x && snakeY[i]==y)//if the snake collides then game over
    {
     GO=true;
    }
    }
 }
   if(x==appleX && y==appleY )
   {
       sco1+=2;
       appleX = rand() % w;//will position apple anywhere between x and y axis
       appleY = rand() % h;
       nSnake++;//increase the length of the snake
   }
}
int main()
{
    int n;
    cout <<"\t\t********Welcome to Snake Game*******\n\n";
    cout <<"1. Every apple has 2 score\n";
    cout <<"2. Game Over if you eat yourself\n";
    cout <<"3. Press X anytime to exit\n";
    cout<<"Press any key to continue\n";
    getch();
    system("cls");
    cout<<"What Mode would you like to play?\n";
    cout <<"1. Soft Borders(Pass Through Borders)\n";
    cout <<"2. Hard Borders(Solid borders but no collision)\n";
    cin>>n;

    initial();
    while(!GO)
    {
        board();
        Input();
     int lastX = snakeX[0];
    int lastY = snakeY[0];
    int last2X, last2Y;
    snakeX[0]=x;
    snakeY[0]=y;

    for(int i=1;i<nSnake;i++)//loop for increment in snake size by pacing o's
    {
        last2X=snakeX[i];
        last2Y=snakeY[i];
        snakeX[i]=lastX;
        snakeY[i]=lastY;
        lastX=last2X;
        lastY=last2Y;

    }

 switch(direction)// to get snake into direction by x and y axis
 {
     case LEFT:
     x--;//x-axis decrement(-x)
     break;
       case RIGHT:
     x++;//x-axis increment(+x)
     break;
       case UP:
     y--;//y-axis decrement(-y)
     break;
       case DOWN:
     y++;//y-axis increment(+y)
     break;
       default:
        break;
 }
 if (n==2)
 {
     if(x<0 || x>w-1 || y<0 || y>h-1)
     {
         GO=true;
       for (int i=0;i<nSnake;i++)
    {
    if(snakeX[i]==x && snakeY[i]==y)//if the snake collides then game over
    {
     GO=true;
    }
    }
    }
 }
 else if (n==1)
 {
   if(x>=w)//if the snake gets out the width of border it will intialize it with 0 from initial
   {
       x=0;
    }
   else if (x<0)// if the snake is less than the initial value it will initialize it from the max width
   {
       x=w-1;
   }
   if(y >=h )//same goes for y-axis both incase of height
   {
       y=0;
   }
   else if (y<0)
   {
       y=h-1;
   }
    for (int i=0;i<nSnake;i++)
    {
    if(snakeX[i]==x && snakeY[i]==y)//if the snake collides then game over
    {
     GO=true;
    }
    }
 }
   if(x==appleX && y==appleY )
   {
       sco1+=2;
       appleX = rand() % w;//will position apple anywhere between x and y axis
       appleY = rand() % h;
       nSnake++;//increase the length of the snake
   }
        //Sleep(40); //Open this previous comment if you want to slow down the game by 4 sec
    }
    return 0;
}
