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
        fruitx = rand() % height;
    } while (fruitx == 0);

    do {
        fruity = rand() % width;
    } while (fruity == 0);

    score = 0;
}

void draw() {
    system("cls");

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
    usleep(10000);

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

    if (x <= 0 || x >= height-1 || y <= 0 || y >= width-1)
        gameover = 1;

    if (x == fruitx && y == fruity) {
        do {
            fruitx = rand() % (height - 1);
        } while (fruitx == 0);

        do {
            fruity = rand() % (width - 1);
        } while (fruity == 0);

        score += 10;
    }
}

void first() {
    printf("   WELCOME   \n\n");
    printf("1. PLAY\n2. How to play\n3. Credits\n4. Exit\n");
}

int main() {
    setup();
    first();
    int n;
    scanf("%d", &n);

    switch (n) {
        case 1:
            while (!gameover) {
                draw();
                input();
                logic();
            }

            printf("\n          GAME OVER                 \n");
            printf("\n         Score : %d                 \n", score);
            printf("\n\nDeveloped by Alif Sarkar CSE-15, BRUR\n\n");

            break;

        case 2:
            system("cls");
            printf("Press w for UP\nPress s for DOWN\nPress a for LEFT\nPress d for RIGHT\nPress X to QUIT\n\n");
            first();
            break;

        case 3:
            system("cls");
            printf("Developed by Alif Sarkar CSE-15, BRUR\n");
            first();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice! Please enter a valid number.\n");
            break;
    }

    int e;
    scanf("%d", &e);

    return 0;
}
