#include<stdio.h>
#include <stdlib.h>

int Islittleendian(){
	int num = 0x1;
	char* p = &num;
	//char* p=(char*)&num;//ǿ������ת�� (�� int* �� char* ���Ͳ�����)
	//ǿ������ת����һ���ǳ�Σ�յĲ���,��Ҫ�������
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
	// void* Ҳ��һ��ָ�����,�������͵�ָ�������֪�������ķ����,Ҳ֪������Ĵ�С,
	// ���� void* ֻ֪�������,��֪������Ĵ�С,���Բ������ڽ�����
	// void* Ӧ�ó����ǳ���,�ܶೡ���¶���ֻ��Ҫ֪�������,����ע�����С

	// ���ͱ��,c���Ա���֧�ַ��ͱ��,���ǽ��� void* ����ģ��һЩ�����ڷ��ͱ�̵Ĳ���
	
	//printf("%d\n", Islittleendian());
	

	//char a = -1;
	//signed char b = -1;
	//unsigned char c = -1;
	//printf("a=%d,b=%d,c=%d\n", a, b, c);
	////��˵ a ,b ,c �ڴ��еĴ洢��������ȫ��ͬ,���ǳ��������ڴ����ⷽʽ�ǲ�ͬ��
	////  %d �ڳ��Զ�  char ������ʽ����ת����  int
	////���� signed char��˵ ,ת�� int ,�ͻ��ڸ�λ������λ
	////����unsigned char ��˵ ,ת�� int ��ʱ��,���ڵ�ǰ���޷�������,ǰ�油0.0xff

	//char a = 128;
	//printf("%d\n", a);
	//printf("%u\n", a);
	////���԰�һ�� signed char ��ʽת���� �޷��ŵ�����,�൱�ڰ���� signed char ��ת��һ���з��ŵ�����,Ȼ���ڵ����޷��ŵĵ����������
	////printf �ĸ�ʽ���ַ����е�����.

	//int i = -20;
	//unsigned int j = 10;
	////-20���ڴ����Բ�����ʽ�洢,��Ӻ�����ȷ
	//printf("%d\n", i + j);


	////����Ĵ���, �޷��ŵ����ֲ�����С��0   ������ѭ��
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
	////c ����ַ������� ����һ�� \0 ��Ϊ������
	//// strlen �ͻ᳢�Բ������ \0  .�ҵ�����Ϊ�ַ�������.
	//printf("%d\n", strlen(a));


	short num = 32767;
	short int a = num + 1;
	//��û�� int û������  short���� short int �ļ�д
	printf("%d\n", a);


	system("pause");
	return 0;
}