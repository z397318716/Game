#include<stdio.h>

#define E 1e-6

////��������д�����
////  ���� ��ʽ �˻���ָ��
////�����ɶ�ά���� arr[][]  �ڶ����������е����ֲ���ʡ��  
////     int(*arr)[5] ָ�������ָ��
//void Func(int arr[]){
//
//}
//void Func(int* arr){
//
//}


//�������е����ֿ���ʡ��  Ӱ�첻��
void Test(int arr[]){

}

void Test1(){

}

int main(){

	//unsigned char i = 0;//0-255
	////unsigned char ->  0-255
	////unsigned short -> 0-65535
	////                   -> 42�ھ�ǧ��
	//for (i = 0; i <= 255; ++i){
	//	printf("123\n");
	//}

	//int n = 9;
	//float* p = (float*)&n;
	//*p = 9.0;
	//printf("%d\n", n);
	//printf("%f\n", *p);

	////��10���ƽǶ�������, float ��ʾ�����ֵľ���Ϊ7λ��Ч����,double ��ʾ�����ֵľ���Ϊ16λ��Ч����
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


	////���ַ��������Ԫ�ر������ַ����͵�ָ����
	//char* p = "hello world";
	//printf("%s\n", p);

	//char str1[] = "hello.";
	//char str2[] = "hello.";
	//char* str3 = "hello.";
	//char* str4 = "hello.";
	//if (str1 == str2){
	//	printf("��ͬ\n");
	//}
	//else
	//	printf("����ͬ\n");
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

	////���� ���ĵĴ���
	//(*(void(*)())0)();  //ԭʼ����1
	//(*(void(*)())0)   (); //���1  ���()  ���ں�������
	//
	//(
	//	*(void(*)()) 0   //�� 0�ŵ�ַ ǿ��ת����һ������ָ���ڽ��к�������   ������� * ��ʾ��һ������ָ��,ֻ�����������ָ��û������(û�б�����,ֻ������)
	//	)    ();

	//void(*signal(int, void(*)(int)))(int); //ԭʼ����2
	//void                   
	//	(
	//	*signal(int, void(*)(int))   )       //���1
	//	(int);  //��������,�����Ĳ�������һ�� int ���͵ı���
	////signal ����ָ��,���ָ��ָ��ĺ����Ĳ���,���������� int,��һ������ָ��
	////��������ķ���ֵ,Ҳ��һ������ָ��,�������ָ��ָ��ĺ�����һ�� int ���� ����ֵ�� void

	//typedef void(*pfunc_t)(int);
	//pfunc_t signal(int, pfunc_t);

	//����ָ������(����ʹ�� typedef �򻯴��� �����Ķ�)

	//ָ����ָ�������ָ�� : ָ����ָ�������ָ����һ��ָ��,ָ��ָ��һ������,�����Ԫ�ض��� ����ָ��
	//(���� typedef  )


	system("pause");
	return 0;
}