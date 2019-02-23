#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>




int main(){

	////指针笔试题7:
	//char* a[] = { "work", "at", "alibaba" };// a 是一个指针数组,里面的每个元素是一个 char*   (char*指向了对应的字符串的首元素)
	//char**pa = a;
	//pa++;
	//printf("%s\n", *pa);
	////  //相当于
	////typedef char* Charptr;
	////Charptr a[] = { "work", "at", "alibaba" };
	////Charptr* pa = a;
	////pa++;
	////printf("%s\n", *pa);
	
	////指针笔试题8:
	//char* c[] = { "enter", "new", "point", "first" };
	//char** cp[] = { c + 3, c + 2, c + 1, 1 };
	//char*** cpp = cp;
	////先计算 ++  ,在计算 *
	//printf("%s\n", **++cpp);
	////先计算 ++ 在 *解引用, 在 -- ,在 *解引用,最后 +3 
	//printf("%s\n", *--*++cpp + 3);// er
	////先 [],在 *
	//printf("%s\n", *cpp[-2] + 3);//st
	//先[-1] 然后解引用 在[-1]  在 +1
	//printf("%s\n", cpp[-1][-1] + 1);//ew

	//虽然C语言中使用字符数组来表示字符串,但实际上,字符数组中的元素个数很可能是和字符串的长度不相同的
	//设计字符串这个东西的时候,可以用两种思路来表示字符串的长度:
	//1.使用特殊符号作为结束标记  ('\0'); C语言
	//2.单独使用一个变量来记录字符串的长度(字符数组中的有效长度. C语言之后的多采用该方案
	//C语言中所有的和字符串操作相关的库函数,都必须要和 \0 密切打交道
	
	//char str[100] = "hello";
	//printf("%d\n", sizeof(str));//100
	//printf("%d\n", strlen(str));//5

	//char str[] = "hello";
	//const char* p = str;//const  限定了   不能修改 *p 指向的内容 
	////char const *p  等价于  const char *p
	//char* const p = str;// 指针的指向不能发生变化

	//const char* p = "hello";
	//char str[1024] = { 0 };
	//strcpy(str, p);
	//printf("%s\n", str);

	//strcat
	//char str1[1024] = "hello";
	//char str2[1024] = "world";
	//strcat(str1, str2);//目标中的空间必须足够大,能够容纳拼接之后的结果(包含\0)
	//printf("%s\n", str1);


	////strcmp
	//char str1[1024] = "hello";
	//char str2[1024] = "world";
	//int ret = strcmp(str1, str2);//str1 大于 str2  返回一个大于0的数
	//printf("%d\n", ret);

	////strncpy
	//char str1[1024] = "hello";
	//char str2[1024] = "world";
	//int ret = strncpy(str1, str2,3);
	//printf("%d\n", ret);


	//strtok
	char str[1024] = "a,b,c,d";
	char* p = strtok(str, ",");
	while (p != NULL){
		printf("%s\n", p);
		p = strtok(NULL, ",");
	}

	system("pause");
	return 0;
}