////编写一个函数 reverse_string(char * string)（递归实现） 
////实现：将参数字符串中的字符反向排列。
////要求：不能使用C函数库中的字符串操作函数。
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//char Reverse_string(char* string){
//	if (*string != '\0'){
//		++string;
//		Reverse_string(string);
//		printf("%c\n", *(string - 1));
//	}
//	
//}
//int main(){
//	Reverse_string("abcdef");
//	system("pause");
//	return 0;
//}