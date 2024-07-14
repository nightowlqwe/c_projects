#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

#define forn(i, n) for (int i = 0; i < n; ++i)
#define HEIGHT 20
#define WIDTH 20

int i, j, height = HEIGHT, width = WIDTH, gameover, score, x, y, fruitx, fruity, flag;

void setup() {
    gameover = 0;
    x = height / 2;
    y = width / 2;

    do {
        fruitx = rand() % 20;
    } while (fruitx == 0);

    do {
        fruity = rand() % 20;
    } while (fruity == 0);

    score = 0;
}

void draw() {
    system("cls");
    printf("Press w for UP, s for DOWN, a for LEFT, d for RIGHT\n\n\n");

    forn(i, height) {
        forn(j, width) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("#");
            } else {
                if (i == x && j == y)
                    printf("0");
                else if (i == fruitx && j == fruity)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }

    printf("Score = %d\n", score);
    printf("Press X to quit the game\n\n");
    printf("Developed by Alif Sarkar CSE-15, BRUR\n\n");
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                flag = 1;
                break;
            case 's':
                flag = 2;
                break;
            case 'd':
                flag = 3;
                break;
            case 'w':
                flag = 4;
                break;
            case 'x':
                gameover = 1;
                break;
        }
    }
}

void logic() {
    usleep(1000);  

    switch (flag) {
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

    if (x < 0 || x >= height || y < 0 || y >= width)
        gameover = 1;

    if (x == fruitx && y == fruity) {
        do {
            fruitx = rand() % 19;
        } while (fruitx == 0);

        do {
            fruity = rand() % 19;
        } while (fruity == 0);

        score += 10;
    }
}

int main() {
    setup();
    while (!gameover) {
        draw();
        input();
        logic();
    }

    printf("\n          GAME OVER                 \n");
    printf("\n         Score : %d                 \n", score);
    printf("\n\nDeveloped by Alif Sarkar CSE-15, BRUR\n\n");

    getchar(); 
    return 0;
}
