#ifndef __SNAKE_H__
#define __SNAKE_H__

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#include<conio.h>


#define WIDTH 60
#define HEIGHT 20

//�������������
struct BODY
{
	int X;
	int Y;
};

//�����߶���
struct snake
{
	struct BODY body[WIDTH * HEIGHT];
	int size;
} snake1,snake2;

//����ʳ����� 
struct FOOD
{
	int X;
	int Y;
} food;


int score = 0;

int kx1 = 1;
int ky1 = 0;

int lastX1 = 0;		// ��β�����ꡣ
int lastY1 = 0;

int kx2 = 1;
int ky2 = 0;

int lastX2 = 0;		// ��β�����ꡣ
int lastY2 = 0;


int sleepSecond = 400;


//��������
void initSnake(struct snake *snake);

void initFood();

void initUI_console();

void play(struct snake *snake,int *lastX,int *lastY,int *kx,int *ky);

void initUI_easyX();

void playGame();

void initWall();

void showScore();

#endif // !__SNAKE_H__
