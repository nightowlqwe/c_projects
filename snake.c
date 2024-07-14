#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>

#define forn(i, n) for (int i = 0; i < n; ++i)

int i,j,height = 20, width = 20, gameover ,score,x,y,fruitx,fruity,flag;

void setup(){
	gameover=0;

	x=height/2;
	y=width/2;

	label1 :
		fruitx= rand()%20;
		if(fruitx==0)
			goto label1;

	label2 :
		fruity=rand()%20;
		if(fruity==0)
			goto label2;

	score=0;

}


void draw(){
	system("cls");

	printf(" press w for UP s for DOWN press a for LEFT press d for RIGHT\n\n\n");


	forn(i,height){
		forn(j,width){
			if(i==0||i==width-1||j==0||j==height-1){
				printf("#");
			}
			else {
                if (i == x && j == y)
                    printf("0");
                else if (i == fruitx && j == fruity)
                    printf("m");
                else
                    printf(".");
            }
		}
		printf("\n");
	}

	printf("score = %d", score);
    printf("\n");
    printf("press X to quit the game\n\n");

    printf("Developed by Alif Sarkar CSE-15,BRUR\n\n");
}

void input(){
	if(kbhit()){
		switch(getch()){
			case 'a':
				flag=1;
				break;

			case 's':
				flag=2;
				break;

			case 'd':
				flag=3;
				break;

			case 'w':
				flag=4;
				break;

			case 'x':
				gameover=1;
				break;
		}
	}
}

void logic(){
	sleep(0.001);

	switch(flag){
		case 1:
			y--;
			break;
		case 2:
			x++;
			break;
		case 3:
			y++;
			break;
		case 4:
			x--;
			break;
		default:
			break;
	}

	if(x<0||x>=height||y<0||y>=height)
		gameover=1;

	if(x==fruitx&&y==fruity){
		label3:
			fruitx=rand()%19;
				if(fruitx==0)
					goto label3;

		label4:
			fruity=rand()%19;
				if(fruity==0)
					goto label4;

		score+=10;
	}
}

int main(){
	int m,n;
	setup();





	while(!gameover){
        draw();
        input();
        logic();
	}

    //system("cls");

	printf("\n          GAMEOVER                 \n");
    printf("\n         score : 990                 \n",score);

    printf("\n\nDeveloped by Alif Sarkar CSE-15,BRUR\n\n");


    char c;
    scanf("%c",&c);


}


