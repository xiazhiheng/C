#include "snake.h"


int main() {

	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cci);

	srand(time(NULL));//�������������

	initWall();
	initSnake();

	initFood();

	initUI_console();
	//initUI_easyX();

	playGame();
	showScore();
	system("pause");
	return 0;
}


void initSnake() {
	snake.size = 2;

	//��ʼ����ͷ
	snake.body[0].X = WIDTH / 2;
	snake.body[0].Y = HEIGHT / 2;

	//��ʼ��һ���ߵ�����
	snake.body[1].X = WIDTH / 2 - 1;
	snake.body[1].Y = HEIGHT / 2;
}


void initFood() {
	//��ʼ��ʳ�������
	food.X = rand() % WIDTH;
	food.Y = rand() % HEIGHT;
}

//��ʼ������
void initUI_console() {

	

	COORD pos = { 0 };

	for (size_t i = 0; i < snake.size; i++)
	{
		pos.X = snake.body[i].X;
		pos.Y = snake.body[i].Y;
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
	pos.X = lastX;
	pos.Y = lastY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	putchar(' ');
	


	//��ʳ��
	pos.X = food.X;
	pos.Y = food.Y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	putchar('#');



}


void playGame() {


	char key = 'd';


	//�ж���ײǽ
	while (snake.body[0].X >=0 && snake.body[0].X < WIDTH
		&& snake.body[0].Y >=0 && snake.body[0].Y < HEIGHT)
	{
		
		initUI_console();

		if (_kbhit()) {
			key = _getch();
		}

		switch (key)
		{
		case 'w':
			if(ky==0){
				kx = 0; ky = -1;
			} 
			break;
		case 's':
			if(ky==0){
				kx = 0; ky = +1;
			} 
			break;
		case 'd':
			if(kx==0){
				kx = +1; ky = 0;
			} 
			break;
		case 'a':
			if(kx==0){
				kx = -1; ky = 0;
			}  
			break;
		default:
			break;
		}



		//�ж���ײ����
		for (size_t i = 1; i < snake.size; i++)
		{
			if (snake.body[0].X == snake.body[i].X
			&& snake.body[0].Y == snake.body[i].Y)
			{
				return;//��ͷײ����
			}
		}
		//��ͷײʳ��
		if (snake.body[0].X == food.X && snake.body[0].Y == food.Y)
		{
			initFood();
			snake.size++;
			score = score + 5;
			sleepSecond -= 10;	// ����
		}

		// �洢��β����
		lastX = snake.body[snake.size - 1].X;
		lastY = snake.body[snake.size - 1].Y;

		for ( size_t i = snake.size -1 ; i >0; i--)
		{
			snake.body[i].X = snake.body[i - 1].X;

			snake.body[i].Y = snake.body[i - 1].Y;
		}
		snake.body[0].X += kx;
		snake.body[0].Y += ky;

		Sleep(sleepSecond);

		//system("cls");

	}

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





