#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>




int main(){

	////ָ�������7:
	//char* a[] = { "work", "at", "alibaba" };// a ��һ��ָ������,�����ÿ��Ԫ����һ�� char*   (char*ָ���˶�Ӧ���ַ�������Ԫ��)
	//char**pa = a;
	//pa++;
	//printf("%s\n", *pa);
	////  //�൱��
	////typedef char* Charptr;
	////Charptr a[] = { "work", "at", "alibaba" };
	////Charptr* pa = a;
	////pa++;
	////printf("%s\n", *pa);
	
	////ָ�������8:
	//char* c[] = { "enter", "new", "point", "first" };
	//char** cp[] = { c + 3, c + 2, c + 1, 1 };
	//char*** cpp = cp;
	////�ȼ��� ++  ,�ڼ��� *
	//printf("%s\n", **++cpp);
	////�ȼ��� ++ �� *������, �� -- ,�� *������,��� +3 
	//printf("%s\n", *--*++cpp + 3);// er
	////�� [],�� *
	//printf("%s\n", *cpp[-2] + 3);//st
	//��[-1] Ȼ������� ��[-1]  �� +1
	//printf("%s\n", cpp[-1][-1] + 1);//ew

	//��ȻC������ʹ���ַ���������ʾ�ַ���,��ʵ����,�ַ������е�Ԫ�ظ����ܿ����Ǻ��ַ����ĳ��Ȳ���ͬ��
	//����ַ������������ʱ��,����������˼·����ʾ�ַ����ĳ���:
	//1.ʹ�����������Ϊ�������  ('\0'); C����
	//2.����ʹ��һ����������¼�ַ����ĳ���(�ַ������е���Ч����. C����֮��Ķ���ø÷���
	//C���������еĺ��ַ���������صĿ⺯��,������Ҫ�� \0 ���д򽻵�
	
	//char str[100] = "hello";
	//printf("%d\n", sizeof(str));//100
	//printf("%d\n", strlen(str));//5

	//char str[] = "hello";
	//const char* p = str;//const  �޶���   �����޸� *p ָ������� 
	////char const *p  �ȼ���  const char *p
	//char* const p = str;// ָ���ָ���ܷ����仯

	//const char* p = "hello";
	//char str[1024] = { 0 };
	//strcpy(str, p);
	//printf("%s\n", str);

	//strcat
	//char str1[1024] = "hello";
	//char str2[1024] = "world";
	//strcat(str1, str2);//Ŀ���еĿռ�����㹻��,�ܹ�����ƴ��֮��Ľ��(����\0)
	//printf("%s\n", str1);


	////strcmp
	//char str1[1024] = "hello";
	//char str2[1024] = "world";
	//int ret = strcmp(str1, str2);//str1 ���� str2  ����һ������0����
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