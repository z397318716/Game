#include<stdio.h>
#include <stdlib.h>

int Islittleendian(){
	int num = 0x1;
	char* p = &num;
	//char* p=(char*)&num;//强制类型转换 (从 int* 到 char* 类型不兼容)
	//强制类型转换是一个非常危险的操作,不要随便滥用
	if (*p == 0x0){
		return 0;
	}
	return 1;
}

int main(){
	//int num = 10;
	//int* p = &num;
	//void* p2 = p;
	//printf("p=%p,p2=%p\n", p, p2);
	//printf("")
	// void* 也是一个指针变量,其它类型的指针变量既知道变量的房间号,也知道房间的大小,
	// 但是 void* 只知道房间号,不知道房间的大小,所以不能用于解引用
	// void* 应用场景非常多,很多场景下都是只需要知道房间号,不关注房间大小

	// 泛型编程,c语言本身不支持泛型编程,但是借助 void* 可以模拟一些类似于泛型编程的操作
	
	//printf("%d\n", Islittleendian());
	

	//char a = -1;
	//signed char b = -1;
	//unsigned char c = -1;
	//printf("a=%d,b=%d,c=%d\n", a, b, c);
	////虽说 a ,b ,c 内存中的存储的内容完全相同,但是程序对这段内存的理解方式是不同的
	////  %d 在尝试对  char 进行隐式类型转换成  int
	////对于 signed char来说 ,转成 int ,就会在高位补符号位
	////对于unsigned char 来说 ,转成 int 的时候,由于当前是无符号数字,前面补0.0xff

	//char a = 128;
	//printf("%d\n", a);
	//printf("%u\n", a);
	////尝试把一个 signed char 隐式转换成 无符号的整数,相当于把这个 signed char 先转成一个有符号的整数,然后在当做无符号的的整数来理解
	////printf 的格式化字符串有点讨厌.

	//int i = -20;
	//unsigned int j = 10;
	////-20在内存中以补码形式存储,相加后结果正确
	//printf("%d\n", i + j);


	////经典的错误, 无符号的数字不可能小于0   导致死循环
	//unsigned int i;
	//for (i = 10; i >= 0; --i){
	//	printf("%u\n", i);
	//}


	//unsigned int a = 1;
	//unsigned int b = 2;
	//printf("%u\n", a - b);


	//char a[1000];
	//for (int i = 0; i <= 1000; ++i){
	//	a[i] = -1 - i;
	//}
	////c 风格字符串规则 是用一个 \0 作为结束符
	//// strlen 就会尝试查找这个 \0  .找到就认为字符结束了.
	//printf("%d\n", strlen(a));


	short num = 32767;
	short int a = num + 1;
	//有没有 int 没有区别  short就是 short int 的简写
	printf("%d\n", a);


	system("pause");
	return 0;
}