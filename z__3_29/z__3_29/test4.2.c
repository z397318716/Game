////2.求出0～999之间的所有“水仙花数”并输出。
////“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，如；153＝1＋5＋3 ? ，则153是一个“水仙花数”。
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
//
//int main(){
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	for (int i = 100; i < 1000; ++i){
//		a = i / 100;
//		b = (i % 100 - i % 10) / 10;
//		c = i % 10;
//		if (i == pow(a, 3) + pow(b, 3) + pow(c, 3)){
//			printf("水仙花数:%d\n", i);
//		}
//	}
//
//	system("pause");
//	return 0;
//}