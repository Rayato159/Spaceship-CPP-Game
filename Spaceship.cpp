#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
//This game is for my skill practice with C++.
//Spaceship by Rayato159

bool gameover;
const int width = 4, hight = 20;

int x, y, score;
int enemyX, enemyY;

enum eDirection {STOP = 0, LEFT, RIGHT, SHOOT};
eDirection dir;

void setup(){
    gameover = false;
    dir = STOP;
    x = width/2;
    y = hight-1;
    enemyX = rand() % width;
    enemyY = rand() % hight/4;
    score = 0;
}

void Draw(){
    system("cls");
    for(int i=0; i<width+2; i++)
        cout << "#";
    cout << endl;

    for(int i=0; i<hight; i++){
        for(int j=0; j<width+1; j++){
            if(j==0 || j==width)
                cout << "#";
            if(j==x && i==y)
                cout << "S";
            else if(j==enemyX && i==enemyY)
                cout << "*";
            else
                cout << " ";
        }cout << endl;
    }

    for(int i=0; i<width+2; i++)
        cout << "#";
    cout << endl;
    cout << "Score : " << score << endl;
}

void input(){
    if(_kbhit()){
        switch(_getch()){
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'x':
                gameover = true;
                break;
        }
    }
}

void logic(){
    switch(dir){
        case LEFT:
            if(x==0){
                x=0;
                enemyY++;
            }
            else{
                x--;
                enemyY++;
            }
            break;
        case RIGHT:
            if(x==width-1){
                x=width-1;
                enemyY++;
            }
            else{
                x++;
                enemyY++;
            }
            break;
        default:
            break;
    }
    if(enemyY == hight){
        enemyX = rand() % width;
        enemyY = rand() % hight/4;
        score++;
    }
    if(x == enemyX && y == enemyY){
        gameover = true;
    }
}

int main(){
    setup();
    while(!gameover){
        Draw();
        input();
        logic();
        Sleep(30);
        // gameover = true;
    }
    cout << "Game Over";
    return 0;
}
