#include<stdio.h>

//FILE

//FILE* fopen(const char* filename,const char* mode)
// fopen,fclose

// r 只读方式
// a 追加打开方式
//`

//以读的方式打不开不存在的文件,以 写 的方式打开不存在的文件会创建新的文件.

// 文件的沟通
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