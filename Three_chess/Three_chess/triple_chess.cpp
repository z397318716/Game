// 1.��ʼ������
// 2.��ӡ����
// 3.��ʾ�������(�������Ϸ���  ���Ӯ or ����Ӯ or ƽ�� or ����)
// 4.��ӡ��������
//�ظ� 3 4 

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define LINE 3
#define COL 3

char chess_broad[LINE][COL];
//��ʼ������
void Initialize(){
	for (int line = 0; line < LINE; ++line){
		for (int col = 0; col < COL; ++col){
			chess_broad[line][col] = ' ';
		}
	}
}

//��ӡ����
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


//�������
//У����������Ƿ����Ҫ��;
// 1.������,��������
// 2.����,��ӡ
void Player_move(){
	while (1){
		int line = 0;
		int col = 0;
		printf("������:(x,y)0<x<4,0<y<4\n");
		scanf("%d,%d", &line, &col);
		if (line<0 || line>2 || col<0 || col>2){
			printf("�Ƿ�����,����������\n");
		} 
		else if (chess_broad[line][col] != ' '){
			printf("��λ����������,��������\n");
		} else{
			chess_broad[line][col] = 'x';
			break;
		}
	}

}

//��������,
//����������� 
// 1.���������λ�������� ����������һ�������
// 2.���������λ������,���ӡ�������
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
//��������Ƿ�����
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

//�ж���Ϸ�Ƿ����
// 1.���ʤ��
// 2.����ʤ��
// 3.����
int Check_result(){
	//�����
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
	//�����
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
	//���Խ���
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
	//������
	//��������
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
			printf("���ʤ��\n");
			Print_chess_broad();
			break;
		} else if (Check_result() == 1){
			printf("����ʤ��\n");
			Print_chess_broad();
			break;
		} else if (Check_result() == 2){
			printf("����\n");
			Print_chess_broad();
			break;
		}

		Computer_move();
		Print_chess_broad();
		
		if (Check_result() == 0){
			printf("���ʤ��\n");
			Print_chess_broad();
			break;
		} else if (Check_result() == 1){
			printf("����ʤ��\n");
			Print_chess_broad();
			break;
		} else if (Check_result() == 2){
			printf("����\n");
			Print_chess_broad();
			break;
		}
		
	}
	system("pause");
	return 0;
}