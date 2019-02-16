#include<stdio.h>

#define E 1e-6

////以下两种写法差不多
////  数组 隐式 退化成指针
////如果变成二维数组 arr[][]  第二个方括号中的数字不能省略  
////     int(*arr)[5] 指向数组的指针
//void Func(int arr[]){
//
//}
//void Func(int* arr){
//
//}


//方括号中的数字可以省略  影响不大
void Test(int arr[]){

}

void Test1(){

}

int main(){

	//unsigned char i = 0;//0-255
	////unsigned char ->  0-255
	////unsigned short -> 0-65535
	////                   -> 42亿九千万
	//for (i = 0; i <= 255; ++i){
	//	printf("123\n");
	//}

	//int n = 9;
	//float* p = (float*)&n;
	//*p = 9.0;
	//printf("%d\n", n);
	//printf("%f\n", *p);

	////从10进制角度来考虑, float 表示的数字的精度为7位有效数字,double 表示的数字的精度为16位有效数字
	//float i = 19.0;
	//float j = 19.0 / 7.0;
	//if (j*7.0 - i<E&&j*7.0-i>-E){
	//	printf("hehe\n");
	//}
	//else{
	//	printf("haha\n");
	//}

	//char ch = 'a';
	//char* p = &ch;
	//*p = 'b';
	//printf("%c\n", ch);


	////将字符数组的首元素保存在字符类型的指针中
	//char* p = "hello world";
	//printf("%s\n", p);

	//char str1[] = "hello.";
	//char str2[] = "hello.";
	//char* str3 = "hello.";
	//char* str4 = "hello.";
	//if (str1 == str2){
	//	printf("相同\n");
	//}
	//else
	//	printf("不相同\n");
	//if (str3 == str4){
	//	printf("same\n");
	//}
	//else{
	//	printf("not same");
	//}

	//int arr[10] = {0};
	//printf("%p\n", arr);
	////int*
	////int(*)[10] =>&arr
	//printf("%p\n", &arr);
	//printf("%p\n", arr + 1);
	//printf("%p\n", &arr + 1);

	//int arr[3][5] = { 0 };

	//int arr[20] = { 0 };
	//Test(arr);

	//printf("%p\n", Test1);
	//printf("%p\n", &Test1);

	////两端 恶心的代码
	//(*(void(*)())0)();  //原始代码1
	//(*(void(*)())0)   (); //拆解1  这个()  是在函数调用
	//
	//(
	//	*(void(*)()) 0   //把 0号地址 强制转换成一个函数指针在进行函数调用   括号里的 * 表示是一个函数指针,只不过这个函数指针没有名字(没有变量名,只有类型)
	//	)    ();

	//void(*signal(int, void(*)(int)))(int); //原始代码2
	//void                   
	//	(
	//	*signal(int, void(*)(int))   )       //拆解1
	//	(int);  //函数声明,函数的参数是填一个 int 类型的变量
	////signal 函数指针,这个指针指向的函数的参数,有两个参数 int,和一个函数指针
	////这个函数的返回值,也是一个函数指针,这个函数指针指向的函数有一个 int 参数 返回值是 void

	//typedef void(*pfunc_t)(int);
	//pfunc_t signal(int, pfunc_t);

	//函数指针数组(尽量使用 typedef 简化代码 易于阅读)

	//指向函数指针数组的指针 : 指向函数指针数组的指针是一个指针,指针指向一个数组,数组的元素都是 函数指针
	//(借助 typedef  )


	system("pause");
	return 0;
}