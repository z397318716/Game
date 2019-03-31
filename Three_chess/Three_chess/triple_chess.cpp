// 1.初始化棋盘
// 2.打印棋盘
// 3.提示玩家落子(并检查游戏结果  玩家赢 or 电脑赢 or 平局 or 继续)
// 4.打印电脑落子
//重复 3 4 

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define LINE 3
#define COL 3

char chess_broad[LINE][COL];
//初始化棋盘
void Initialize(){
	for (int line = 0; line < LINE; ++line){
		for (int col = 0; col < COL; ++col){
			chess_broad[line][col] = ' ';
		}
	}
}

//打印棋盘
void Print_chess_broad(){
	int a = 0;
	int b = 1;
	int c = 2;
	printf(" |  %d  |  %d  |  %d  |\n", a, b, c);
	printf(" |-----|-----|-----| \n");
	for (int line = 0; line < LINE; ++line){
			printf("%d|  %c  |  %c  |  %c  |\n",a, chess_broad[line][0], chess_broad[line][1], chess_broad[line][2]);
			printf(" |-----|-----|-----| \n");
			++a;
	}
}


//玩家落子
//校验玩家落子是否符合要求;
// 1.不符合,重新输入
// 2.符合,打印
void Player_move(){
	while (1){
		int line = 0;
		int col = 0;
		printf("请落子:(x,y)0<x<4,0<y<4\n");
		scanf("%d,%d", &line, &col);
		if (line<0 || line>2 || col<0 || col>2){
			printf("非法输入,请重新输入\n");
		} 
		else if (chess_broad[line][col] != ' '){
			printf("该位置已有子了,重新输入\n");
		} else{
			chess_broad[line][col] = 'x';
			break;
		}
	}

}

//电脑落子,
//靠随机数落子 
// 1.如果待落子位置已有子 则重新生成一个随机数
// 2.如果待落子位置无子,则打印落子情况
void Computer_move(){
	while (1){
		int line = rand() % LINE;
		int col = rand() % COL;
		if (chess_broad[line][col] == ' '){
			chess_broad[line][col] = 'o';
			break;
		} else{
			continue;
		}
	}
}
//检查棋盘是否满了
int He_qi(){
	for (int line = 0; line < LINE; ++line){
		for (int col = 0; col < COL; ++col){
			if (chess_broad[line][col] == ' '){
				return 0;
			}
		}
	}
	return 1;
}

//判定游戏是否结束
// 1.玩家胜利
// 2.电脑胜利
// 3.和棋
int Check_result(){
	//检查行
	for (int line = 0; line < 3; ++line){
		if (chess_broad[line][0] == chess_broad[line][1]&&
			chess_broad[line][0] == chess_broad[line][2]&&
			chess_broad[line][0]=='x'){
			return 0;
		} else if (chess_broad[line][0] == chess_broad[line][1]&&
			chess_broad[line][0] == chess_broad[line][2] &&
			chess_broad[line][0] == 'o'){
			return 1;
		}
		continue;
	}
	//检查列
	for (int col = 0; col < 3; ++col){
		if (chess_broad[0][col] == chess_broad[1][col] &&
			chess_broad[0][col] == chess_broad[2][col] &&
			chess_broad[0][col] == 'x'){
			return 0;
		} else if (chess_broad[0][col] == chess_broad[1][col] &&
			chess_broad[0][col] == chess_broad[2][col] &&
			chess_broad[0][col] == 'o'){
			return 1;
		}
	}
	//检查对角线
	if (chess_broad[0][0] == chess_broad[1][1] &&
		chess_broad[0][0] == chess_broad[2][2] &&
		chess_broad[0][0] == 'x'){
		return 0;
	} else if (chess_broad[0][0] == chess_broad[1][1] &&
		chess_broad[0][0] == chess_broad[2][2] &&
		chess_broad[0][0] == 'o'){
		return 1;
	} else if (chess_broad[0][2] == chess_broad[1][1] &&
		chess_broad[0][2] == chess_broad[2][0] &&
		chess_broad[1][1] == 'x'){
		return 0;
	} else if (chess_broad[0][2] == chess_broad[1][1] &&
		chess_broad[0][2] == chess_broad[2][0] &&
		chess_broad[1][1] == 'o'){
		return 1;
	}
	//检查和棋
	//棋盘满了
	else if (He_qi() == 1){
		return 2;
	}
	return 3;
	
}

int main(){
	Initialize();
	Print_chess_broad();

	while (1){
		Player_move();

		if (Check_result() == 0){
			printf("玩家胜利\n");
			Print_chess_broad();
			break;
		} else if (Check_result() == 1){
			printf("电脑胜利\n");
			Print_chess_broad();
			break;
		} else if (Check_result() == 2){
			printf("和棋\n");
			Print_chess_broad();
			break;
		}

		Computer_move();
		Print_chess_broad();
		
		if (Check_result() == 0){
			printf("玩家胜利\n");
			Print_chess_broad();
			break;
		} else if (Check_result() == 1){
			printf("电脑胜利\n");
			Print_chess_broad();
			break;
		} else if (Check_result() == 2){
			printf("和棋\n");
			Print_chess_broad();
			break;
		}
		
	}
	system("pause");
	return 0;
}