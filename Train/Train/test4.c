////�ݹ�ͷǵݹ�ֱ�ʵ��strlen 
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//
////�ǵݹ�ʵ�� strlen
//int Strlen1(char* string){
//	int i = 0;
//	while (1){
//		if (*string != '\0'){
//			++i;
//			*string++;
//		}
//		else{
//			break;
//		}
//	}
//	return i;
//}
//
//////�ݹ�ʵ�� strlen
////int Strlen2(char* string){
////	int i = 0;
////	if(*string != '\0'){
////		*string++;
////		i=Strlen2(string)+1;
////
////	}
////
////	return i;
////}
//
//
//
//
//int main(){
//	char* str = "abcde";
//	//Strlen1(str);
//	printf("%d\n", Strlen1(str));
//	//printf("%d\n", Strlen2(str));
//
//
//
//
//	system("pause");
//	return 0;
//}