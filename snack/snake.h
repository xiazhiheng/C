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
} snake;

//����ʳ����� 
struct FOOD
{
	int X;
	int Y;
} food;


int score = 0;

int kx = 0;
int ky = 0;

int lastX = 0;		// ��β�����ꡣ
int lastY = 0;


int sleepSecond = 200;


//��������
void initSnake();

void initFood();

void initUI_console();

void initUI_easyX();

void playGame();

void initWall();

void showScore();

#endif // !__SNAKE_H__
