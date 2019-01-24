//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//#define MINE_COUNT 10
//#define ROW 9
//#define COL 9
//
////使用二维数组来表示扫雷的地图.此处需要使用两个二维数组
////第一个二维数组表示地雷的雷阵
////第二个二维数组表示用户看到的地图
////扫雷的地图大小是 9*9 ,但是我们准备把这个二维数组定义成 11*11
////此时,我们的地图的有效范围就相当于 [1,ROW] 和 [1,COL] 第零行是边框 其余类似
////对于 mine_map,使用 '0' 表示不是地雷,使用 '1' 表示是地雷
//char mine_map[ROW + 2][COL + 2];
////show_map ,表示 '*' ,表示未打开的方块,对于打开的方块,就使用具体的数字来表示
//char show_map[ROW + 2][COL + 2];
//
//int Menu(){
//	printf("1.开始游戏\n");
//	printf("0.退出游戏\n");
//	printf("请输入您的选择: ");
//	int choice = 0;
//	scanf("%d", &choice);
//	return choice;
//}
//void Init(char mine_map[ROW + 2][COL + 2], char show_map[ROW + 2][COL + 2]){
//	//1.把数组进行初始化
//	//对于 mine_map,先把里面的所有元素都设置成 '0'
//	memset(mine_map, '0', (ROW + 2)*(COL + 2));
//	//对于 show_map,先把所有的元素都设置成 '*'
//	memset(show_map, '* ', (ROW + 2)*(COL + 2));
//	//2.随机的布置雷阵
//	srand(time(0));
//	int mine_count = MINE_COUNT;
//	while (mine_count > 0){
//		//在这个循环中随机设置地雷,每次设置完成一个,就 --mine_count
//		//[1,ROW]
//		int row = rand() % 9 + 1;
//		int col = rand() % 9 + 1;
//		if (mine_map[row][col]=='0'){
//			mine_map[row][col] = '1';
//			--mine_count;
//		}
//	}
//}
//void Displaymap(char map[ROW + 2][COL + 2]){
//	printf("    ");
//	//打印第一行的内容,列的坐标
//	for (int col = 1; col <= COL; ++col){
//		printf("%d", col);
//	}
//	printf("\n");
//	//打印具体的地图
//	//打印第二行,地图的上边框
//	for (int col = 1; col <= COL; ++col){
//		printf("---");
//	}
//	printf("\n");
//	//按行打印地图中的具体内容
//	for (int row = 1; row <= ROW; ++row){
//		//先打印出行号
//		//1 =>01  2  =>02  10  =>10
//		printf("%02d| ", row);
//		for (int col = 1; col <= COL; ++col){
//			printf("%c", map[row][col]);
//		}
//		printf("\n");
//	}
//}
//
//void UpdateShowmap(char show_map[ROW + 2][COL + 2],
//	char mine_map[ROW+2][COL+2],int row,int col){
//	int mine_count = 0;
//
//	//第一种实现统计给定方框周围八个方框地雷的个数的方法
//	//if (mine_count[row - 1][col - 1] == '1'){
//	//	++mine_count;
//	//}
//	//if (mine_count[row - 1][col] == '1'){
//	//	++mine_count;
//	//}
//	//if (mine_count[row - 1][col + 1] == '1'){
//	//	++mine_count;
//	//}
//	//if (mine_count[row][col - 1] == '1'){
//	//	++mine_count;
//	//}
//	//if (mine_count[row][col + 1] == '1'){
//	//	++mine_count;
//	//}
//	//if (mine_count[row + 1][col - 1] == '1'){
//	//	++mine_count;
//	//}
//	//if (mine_count[row + 1][col] == '1'){
//	//	++mine_count;
//	//}
//	//if (mine_count[row + 1][col + 1] == '1'){
//	//	++mine_count;
//	//}
//	
//	
//	//第二种实现统计给定方框周围八个方框地雷的个数的方法
//	mine_map = (mine_map[row - 1][col - 1] - '0')
//		+ (mine_map[row - 1][col] - '0')
//		+ (mine_map[row - 1][col + 1] - '0')
//		+ (mine_map[row][col - 1] - '0')
//		+ (mine_map[row][col + 1] - '0')
//		+ (mine_map[row + 1][col - 1] - '0')
//		+ (mine_map[row + 1][col] - '0')
//		+ (mine_map[row + 1][col + 1] - '0');
//	
//	show_map[row][col] = '0' + mine_map;
//
//}
//
//
//void Game(){
//	//1.初始化地图(mine_map,show_map),布置雷阵
//	int not_mine_count = 0;
//	Init(mine_map, show_map);
//	//2.先打印出 show_map.
//	Displaymap(show_map);
//	while (1){
//		//3.提示用户进行输入坐标[1,ROW][1,COL]
//		int row = 0;
//		int col = 0;
//		printf("请输入要翻开的方块坐标(row,col):");
//		scanf("%d %d", &row, &col);
//		//4.对用户输入的合法性进行判定,如果不合理,提示用户重新输入
//		if (row <= 0 || row > ROW || col <= 0 || col > COL){
//			printf("您的输入不合法!请重新输入!\n");
//			continue;//使当前循环不继续向下执行,重新开始新的循环
//		}
//		//5.判定玩家当前是否踩雷,如果踩雷,游戏结束,并且打印雷阵
//		if (mine_map[row][col] == '1'){
//			printf("游戏结束!\n");
//			Displaymap(mine_map);
//			break;
//		}
//		//6.如果没踩雷,就需判定一下玩家是否胜利(胜利条件是,已经翻开的方块数,达到了 地图方块总数 - 地雷个数),
//		++not_mine_count;
//		if (not_mine_count == ROW*COL - MINE_COUNT){
//			printf("扫雷成功!\n");
//			Displaymap(mine_map);
//			break;
//		}
//		//7.如果游戏没有胜利,就需要统计当前位置周围有几个雷,打印 show_map 回到第 3 步
//		UpdateShowmap(show_map,mine_map,row,col);
//		Displaymap(show_map);
//	}
//}
//
//
//void Start(){
//	while (1){
//		int choice = Menu();
//		if (choice == 0){
//			printf("退出游戏!\n");
//			break;
//		}
//		Game();
//	}
//}
//
//int main(){
//	Start();
//
//	system("pause");
//	return 0;
//}