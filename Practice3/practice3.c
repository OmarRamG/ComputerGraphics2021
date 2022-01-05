#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

void fotogram(int height, int width);
void fill(int height, int width);
void archive(int cont);
void welcome();

FILE *archive;

struct pixels{
    int Red;
    int Green;
    int Blue;   
}RGB[2000];

struct image{
    struct pixels RGB[2000];
}foto[2000];

int main(){

	int cont, page=0;
	system("color f4");
	initwindow(720,480);
	setbkcolor(15);
	clearviewport();
	welcome();

	for(int ciclo=0;ciclo<10;ciclo++)
	{
    		for(cont=1;cont<7;cont++)
    		{
        		setactivepage(0);
        		setvisualpage(1);
        		cleardevice();
        		archive(cont);
    		}
	}
	closegraph();

}

void welcome()
{
    setcolor(BLACK);
    settextstyle(2,0,8);
    outtextxy(40,40,"H");Beep(200,100);delay(500);outtextxy(70,40,"O");Beep(200,100);delay(500);
    outtextxy(100,40,"L");Beep(200,100);delay(500);outtextxy(130,40,"A");Beep(200,100);delay(500);
}


void archive(int cont)
{
    int  height=0, width=0, aux=0;
    char nombre[20];
    switch(cont)
    {
    case 1:
            strcpy(nombre,"foto1.txt");     fflush(stdin);      
	    break;  
    case 2:
            strcpy(nombre,"foto2.txt");     fflush(stdin);      
	    break;
    case 3:
            strcpy(nombre,"foto3.txt");     fflush(stdin);      
	    break;
    case 4:
            strcpy(nombre,"foto4.txt");     fflush(stdin);      
	    break;
    case 5:
            strcpy(nombre,"foto5.txt");     fflush(stdin);      
	    break;
    case 6:
            strcpy(nombre,"foto6.txt");     fflush(stdin);      
	    break;
    }
    archive=fopen(nombre,"r");
        if(archive==NULL)
        {
            system("CLS");
            gotoxy(20,20);printf("Error: file couldn't be created");
            system("pause");
            return;
        }
    setcolor(BLACK);
    settextstyle(11,0,1);
    //outtextxy(2,690,"File has been opened successfully");
    fscanf(archive,"%d %d",&height,&width);
    fscanf(archive,"%d",&aux);
    fill(height, width);
}

void fill(int height, int width){   
    for(int i=0;i<width;i++)
    {
        for(int j=0; j<height;j++)
        {
            int auxR=0, auxG=0,auxB=0;
            fscanf(archive,"%d %d %d",&auxR,&auxG,&auxB);
            foto[j].RGB[i].Blue=auxB; foto[j].RGB[i].Red=auxR; foto[j].RGB[i].Green=auxG;
        }
    }
    fotogram(height,width);
}

void fotogram(int height, int width){   
    for(int i=0;i<width;i++)
    {
        for(int j=0; j<height;j++)
        {
        	putpixel(j+20,i+20,COLOR(foto[j].RGB[i].Red,foto[j].RGB[i].Green,foto[j].RGB[i].Blue));
        }
    }
    fclose(archive);
}
