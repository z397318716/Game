//// 1.定义用二维数组表示棋盘
////2.需要对棋盘进行初始化(例如可以把数组初始化成全是空格)
////3.先打印一下棋盘.
////4.玩家落子,顺便检查一下游戏是否结束
////5.电脑落子,顺便检查一下游戏是否结束
//
//#define _CRT_SECURE_NO_WARNINGS
//#define ROW 3
//#define COL 3
//#include<stdio.h>
//#include<stdlib.h>
////此处对于数组的长度,最好定义成宏.
////方便未来对程序进行扩展,如果需要修改数组的元素个数,直接修改宏即可
//
//char g_chess_board[ROW][COL];
//// 1.定义用二维数组表示棋盘
//
//void Init(){
//	// 对棋盘进行初始化
//	for (int row = 0; row < ROW; ++row){
//		for (int col = 0; col < COL; ++col){
//			g_chess_board[row][col] = ' ';
//		}
//	}
//}
//
//void Print(){
//	//tu do 打印棋盘
//	for (int row = 0; row < ROW; ++row){
//		printf("| %c | %c | %c |\n", g_chess_board[row][0],
//			g_chess_board[row][1], g_chess_board[row][2]);
//		if (row == ROW - 1){
//			//避免最后一行还输出一个边界
//			break;
//		}
//		printf("|---|---|---|\n");
//	}
//}
//
//void PlayerMove(){
//	// 玩家落子
//	while (1){
//		//1.提示玩家输入一个坐标
//		printf("请输入(输入坐标): ");
//		//2.读取玩家的输入
//		int row = -1;
//		int col = -1;
//		scanf("%d %d", &row, &col);
//		//3.对玩家的输入进行校验.(永远也不要相信用户的输入)
//		//     a).校验输入的坐标是否是合理范围
//		//     b).玩家的输入坐标对应的位置上是否已经有子
//		if (row < 0 || row >= ROW || col < 0 || col >= COL){
//			printf("输入的坐标非法,请重新输入!\n");
//			continue;
//		}
//		//b).玩家的输入坐标对应的位置上是否已经有子
//		if (g_chess_board[row][col] != ' '){
//			//当前位置被占用,不能落子
//			printf("当前位置已经有子了,请重新输入!\n");
//			continue;
//		}
//		//4.如果玩家输入合法,就把棋盘上的对应位置设为 'x'
//		g_chess_board[row][col] = 'x';
//		break;
//	}
//}
//
////棋盘满了返回 1, 没满返回 0
//int IsFull(){
//	for (int row = 0; row < ROW; ++row){
//		for (int col = 0; col < COL; ++col){
//			if (g_chess_board[row][col] == ' '){
//				return 0;
//			}
//		}
//	}
//	return 1;
//}
//
//// 使用 x 表示玩家,使用 o 表示电脑
////约定 CheckWinner 函数,返回 x 表示玩家胜利
////如果返回 o 表示电脑胜利,返回一个 q 表示和棋
////如果返回 空格 表示胜负未分
//char CheckWinner(){
//	//检测游戏是否结束
//	//1.先检测所有的行看是不是三个字连在一起
//	for (int row = 0; row < ROW; ++row){
//		if (g_chess_board[row][0] == g_chess_board[row][1]
//			&& g_chess_board[row][0] == g_chess_board[row][2]
//			&& g_chess_board[row][0] != ' '){
//			return g_chess_board[row][0];
//		}
//	}
//	//2.在检查所有的列是否连在一起
//	for (int col = 0; col < COL; ++col){
//		if (g_chess_board[0][col] == g_chess_board[1][col]
//			&& g_chess_board[0][col] == g_chess_board[2][col]
//			&& g_chess_board[0][col] != ' '){
//			return g_chess_board[0][col];
//		}
//	}
//	//3.检查对角线
//	if (g_chess_board[0][0] == g_chess_board[1][1]
//		&& g_chess_board[0][0] == g_chess_board[2][2]
//		&& g_chess_board[0][0] != ' '){
//		return g_chess_board[0][0];
//	}
//	if (g_chess_board[2][0] == g_chess_board[1][1]
//		&& g_chess_board[2][0] == g_chess_board[0][2]
//		&& g_chess_board[2][0] != ' '){
//		return g_chess_board[2][0];
//	}
//	//4.检查是否和棋
//	if (IsFull()){
//		return 'q';
//	}
//	return 'f';
//}
//
//void ComputerMove(){
//	//电脑落子,随机落子
//	//靠随机数产生一个行,随机数产生一个列
//	//如果产生的位置上已经有子了,就在产生一次
//	printf("请电脑落子!\n");
//	int row = 0;
//	int col = 0;
//	while (1){
//		row = rand() % ROW;//[0,2]
//		col = rand() % COL;//[0,2]
//		if (g_chess_board[row][col] == ' '){
//			g_chess_board[row][col] = 'o';
//			break;
//		}
//	}
//}
//int main(){
//	char winner = ' ';
//	Init();
//	while (1){
//		//3.先打印一下棋盘.
//		Print();
//		//4.玩家落子,顺便检查一下游戏是否结束
//		PlayerMove();
//		winner = CheckWinner();
//		if (winner != 'f'){
//			//游戏结束
//			break;
//		}
//		//5.电脑落子,顺便检查一下游戏是否结束
//		ComputerMove();
//		winner = CheckWinner();
//		if (winner != 'f'){
//			//游戏结束
//			break;
//		}
//	}
//	if (winner == 'x'){
//		printf("玩家获胜!\n");
//	}
//	else if (winner == 'o'){
//		printf("电脑获胜!\n");
//
//	}
//	else if (winner == 'q'){
//		printf("和棋!\n");
//	}
//
//	system("pause");
//	return 0;
//}