#include "snake.h"


int main() {

	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cci);

	srand(time(NULL));//�������������

	initWall();
	initSnake(&snake1);
	initSnake(&snake2);

	initFood();

	initUI_console();
	//initUI_easyX();

	playGame();
	showScore();
	system("pause");
	return 0;
}


void initSnake(struct snake *snake) {
	snake->size = 2;

	//��ʼ����ͷ
	snake->body[0].X = rand() % WIDTH;
	snake->body[0].Y = rand() % HEIGHT;

	//��ʼ��һ���ߵ�����
	snake->body[1].X = rand() % WIDTH - 1;
	snake->body[1].Y = rand() % HEIGHT;
}


void initFood() {
	//��ʼ��ʳ�������
	food.X = rand() % WIDTH;
	food.Y = rand() % HEIGHT;
}

//��ʼ������
void initUI_console() {

	COORD pos = { 0 };

	for (size_t i = 0; i < snake1.size; i++)
	{
		pos.X = snake1.body[i].X;
		pos.Y = snake1.body[i].Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		if (i == 0) {
			putchar('@');
		}
		else
		{
			putchar('*');
		}

	}

	// ȥ����β
	pos.X = lastX1;
	pos.Y = lastY1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	putchar(' ');

	for (size_t i = 0; i < snake2.size; i++)
	{
		pos.X = snake2.body[i].X;
		pos.Y = snake2.body[i].Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		if (i == 0) {
			putchar('@');
		}
		else
		{
			putchar('+');
		}

	}

	
	// ȥ����β
	pos.X = lastX2;
	pos.Y = lastY2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	putchar(' ');


	//��ʳ��
	pos.X = food.X;
	pos.Y = food.Y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	putchar('#');

}


void playGame() {



	//转向
	while (snake1.body[0].X >=0 && snake1.body[0].X < WIDTH
		&& snake1.body[0].Y >=0 && snake1.body[0].Y < HEIGHT &&
		snake2.body[0].X >=0 && snake2.body[0].X < WIDTH
		&& snake2.body[0].Y >=0 && snake2.body[0].Y < HEIGHT)
	{
		
		initUI_console();

		play(&snake1,&lastX1,&lastY1,&kx1,&ky1);
		play(&snake2,&lastX2,&lastY2,&kx2,&ky2);

		Sleep(sleepSecond);

		//system("cls");

	}

}

void play(struct snake *snake,int *lastX,int *lastY,int *kx,int *ky){
		char key = 'q';
		if (_kbhit()) {
			key = _getch();
		}

		switch (key)
		{
		case 72:
			if(ky2==0){
				kx2 = 0; ky2 = -1;
			} 
			break;
		case 80:
			if(ky2==0){
				kx2 = 0; ky2 = +1;
			} 
			break;
		case 77:
			if(kx2==0){
				kx2 = +1; ky2 = 0;
			} 
			break;
		case 75:
			if(kx2==0){
				kx2 = -1; ky2 = 0;
			}  
			break;
		case 'w':
			if(ky1==0){
				kx1 = 0; ky1 = -1;
			} 
			break;
		case 's':
			if(ky1==0){
				kx1 = 0; ky1 = +1;
			} 
			break;
		case 'd':
			if(kx1==0){
				kx1 = +1; ky1 = 0;
			} 
			break;
		case 'a':
			if(kx1==0){
				kx1 = -1; ky1 = 0;
			}  
			break;
		default:
			break;
		}
	//撞击
		for (size_t i = 1; i < snake->size; i++)
		{
			if (snake->body[0].X == snake->body[i].X
			&& snake->body[0].Y == snake->body[i].Y)
			{
				return;//失败
			}
		}
		//吃东西
		if (snake->body[0].X == food.X && snake->body[0].Y == food.Y)
		{
			initFood();
			snake->size++;
			score = score + 5;
			sleepSecond -= 10;	// 加快速度
		}

		//更新蛇
		*lastX = snake->body[snake->size - 1].X;
		*lastY = snake->body[snake->size - 1].Y;

		for ( size_t i = snake->size -1 ; i >0; i--)
		{
			snake->body[i].X = snake->body[i - 1].X;

			snake->body[i].Y = snake->body[i - 1].Y;
		}
		snake->body[0].X += *kx;
		snake->body[0].Y += *ky;
}


void initWall(void)
{
	for (size_t i = 0; i <= HEIGHT; i++)	// ����
	{
		for (size_t j = 0; j <= WIDTH; j++)			// һ���еĶ���
		{
			if (j == WIDTH)
			{
				printf("|");
			}
			else if (i == HEIGHT)
			{
				printf("-");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}


void showScore() {

	COORD pos;
	pos.X = 0;
	pos.Y = HEIGHT + 2;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	printf("Game over!!\n");
	printf("score is %d\n",score);
}





