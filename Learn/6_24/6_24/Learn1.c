#include<stdio.h>

//FILE

//FILE* fopen(const char* filename,const char* mode)
// fopen,fclose

// r ֻ����ʽ
// a ׷�Ӵ򿪷�ʽ
//`

//�Զ��ķ�ʽ�򲻿������ڵ��ļ�,�� д �ķ�ʽ�򿪲����ڵ��ļ��ᴴ���µ��ļ�.

// �ļ��Ĺ�ͨ
int main()
{
	

	//FILE *fpr = NULL;

	//fpr = fopen("F:\\1.txt", "r");
	//if (fpr == NULL)
	//{
	//	
	//}
	//while ()
	//c = fgets(fpr);
	//putchar(c)

	//fclose(fpr);
	//fp = NULL;



	//char c;
	//while (c = getchar()) != '\n';
	//{
	//	putchar(c);
	//}


	//fscanf,fprintf
	FILE* fpr = fopen("F:\\1.txt", "r");
	FILE* fpw = fopen("F:\\2.txt", "w");

	system("pause");
	return 0;
}