#include<stdio.h>
#include<stdlib.h>
#include<string.h>
////Cmpare �� qsort �ıȽϺ���,Cmpare �ĵ���ʱ�������ɳ���Ա������,������ qsort �ڲ���������
////�����ַ��ĺ���,���� "�ص�����".
//int Cmpare(void* p1,void* p2){
//	int* a = (int*)p1;
//	int* b = (int*)p2;
//	//��� *a<*b,�൱���ú���������.  *a>=*b,�����ͷ��ؼ�
//	// p1 �� p2,������� p2 ָ���Ԫ���� p1 ��ǰ��,������
//	return *a < *b;
//}
//
//
int main(){
	//	//int arr[] = { 9, 5, 2, 7 };
	//	////qsort ʵ���ǻ��ڿ��������㷨
	//	//qsort(arr,sizeof(arr)/sizeof(arr[0]),sizeof(arr[0]),&Cmpare);//ȡ��ַ����д�ɲ�д
	//	//for (int i = 0; i < 4; ++i){
	//	//	printf("%d\n", arr[i]);
	//	//}
	//
	//	int a[] = { 1, 2, 3, 4 };
	//	printf("%d\n", sizeof(a));//16
	//	printf("%d\n", sizeof(a+0));//4  a �Ѿ���ʽת������ָ��  �����ּӼ������� �õ���ָ�� �����ָ��Ĵ�С
	//	printf("%d\n", sizeof(*a));//4  
	//	printf("%d\n", sizeof(a+1));//4
	//	printf("%d\n", sizeof(a[1]));//4
	//	printf("%d\n", sizeof(&a));//4   &a ����ָ��
	//	printf("%d\n", sizeof(*&a));//16 &a ����ָ��  *&a  �� &a����ָ�� �����õõ�����Ȼ��ԭ��������
	//	printf("%d\n", sizeof(&a+1));//4
	//	printf("%d\n", sizeof(&a[0]));//4
	//	printf("%d\n", sizeof(&a[0]+1));//4
	//
	//
	//	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	//	printf("%d\n", sizeof(arr));//6
	//	printf("%d\n", sizeof(arr + 0));//4   ��ʽת����ָ��
	//	printf("%d\n", sizeof(*arr));//1
	//	printf("%d\n", sizeof(arr[1]));//1
	//	printf("%d\n", sizeof(&arr));//4     &arr ����ָ��
	//	printf("%d\n", sizeof(&arr+1));//4
	//	printf("%d\n", sizeof(&arr[0]+1));//4
	//
	//
	//	printf("%d\n", strlen(arr));//ֵ��ȷ��  ��һֱ�����ҵ� \0   
	//	printf("%d\n", strlen(arr+0));//ͬ��
	//	printf("%d\n", strlen(*arr));//�������   *arr ������arr ȡ�����ǵ�һ���ַ�,��ʱ��Ӧ�ý��� strlen ���� ���Ͳ���ͬ
	//	printf("%d\n", strlen(arr[1]));//ͬ��
	//	printf("%d\n", strlen(&arr));//  strlen ���������黹��ָ�� ����һֱ������ \0 
	//	printf("%d\n", strlen(&arr+1));//ͬ��
	//	printf("%d\n", strlen(&arr[0]+1));//ָ��  ͬ��
	//	//����δ������Ϊ
	//
	//	char arr[] = "abcdef";// ��ʱ arr �оͰ�����  \0
	//	printf("%d\n", sizeof(arr));//7   \0 Ҳ��������
	//	printf("%d\n", sizeof(arr+0));//4    ��ʽת���� ָ��
	//	printf("%d\n", sizeof(*arr));//1     ȡ��������Ԫ��
	//	printf("%d\n", sizeof(arr[1]));//1
	//	printf("%d\n", sizeof(&arr));//4   ָ��
	//	printf("%d\n", sizeof(&arr+1));//4
	//	printf("%d\n", sizeof(&arr[0])+1);//4
	//	
	//	printf("%d\n", strlen(arr));//strlen ���ַ������ȵ�ʱ��,�������ĩβ��  \0
	//	printf("%d\n", strlen(arr + 0));//6
	//	printf("%d\n", strlen(*arr));//�������  
	//	printf("%d\n", strlen(arr[1]));
	//	printf("%d\n", strlen(&arr));//6
	//	printf("%d\n", strlen(&arr + 1));//  ����ָ�� +1  �������������������  ���� \0 
	//	printf("%d\n", strlen(&arr[0] + 1));//5   ��Ԫ�� + 1 ����һ��Ԫ�� Ȼ�� �� strlen
	//
	//
	//	char* p = "abcdef";
	//	printf("%d\n", sizeof(p));//4
	//	printf("%d\n", sizeof(p+1));//4
	//	printf("%d\n", sizeof(*p));//1
	//	printf("%d\n", sizeof(p[0]));//1
	//	printf("%d\n", sizeof(&p));//4     ָ���� & ��� ����ָ��
	//	printf("%d\n", sizeof(&p+1));//4
	//	printf("%d\n", sizeof(&p[0]+1));//4
	//	
	//
	//	printf("%d\n", strlen(p));//6
	//	printf("%d\n", strlen(p+1));// ��ָͨ�� ֻ����һ��Ԫ��  ����ָ�� +1 ��������������
	//	printf("%d\n", strlen(*p));// �������        
	//	printf("%d\n", strlen(p[0]));//ͬ��
	//	printf("%d\n", strlen(&p));//
	//	printf("%d\n", strlen(&p+1));//
	//	printf("%d\n", strlen(&p[0]+1));//

	//   int a[3][4] = { 0 };
	//printf("%d\n", sizeof(a));//48
	//printf("%d\n", sizeof(a[0][0]));//4
	//printf("%d\n", sizeof(a[0]));//16
	//printf("%d\n", sizeof(a[0]+1));//4  ֻҪ������ ��ѧ���� �ͱ���� ����ָ��
	//printf("%d\n", sizeof(*(a[0]+1)));//4   �ȼ��� a[0][1]
	//printf("%d\n", sizeof(a+1));//4
	//printf("%d\n", sizeof(*(a+1)));//16     *(a+1)  �൱�� a[1]
	//printf("%d\n", sizeof(&a[0]+1));//4
	//printf("%d\n", sizeof(*(&a[0]+1)));//16   ����ָ������� �õ� ����
	//printf("%d\n", sizeof(*a));//16   *a �൱�� a[0]
	//printf("%d\n", sizeof(a[3]));//16

	////ָ�������1:

	//int a[5] = { 1, 2, 3, 4, 5 };
	//int* ptr = (int*)(&a + 1);// ptr ָ��ȽϹؼ� &a+1 �õ��Ľ����һ��ָ���������һ��Ԫ�ص���һ��λ�õĵ�ַ
	//printf("%d,%d", *(a + 1), *(ptr - 1));//2  5

	////ָ�������3:
	//int a[4] = { 1, 2, 3, 4 };
	//int* ptr1 = (int*)(&a + 1);
	//int* ptr2 = (int*)((int)a + 1);
	//printf("%x,%x", ptr1[-1], *ptr2);
	
	////ָ�������4:;
	//int a[3][2] = { (0, 1), (2, 3), (4, 5) };//(0,1)  ���ű��ʽ,ֵ���Ƕ��ź��Ԫ�� 1
	//int* p;
	//p = a[0];
	//printf("%d", p[0]);

	//int y = 1;
	//int z = 0;
	//z = y++;
	//printf("%d\n", z);

	////ָ�������5:
	//int a[5][5];
	//int(*p)[4];//����ָ��
	//p = a;
	//printf("a_ptr=%#p,p_ptr=%#p\n", &a[4][2], &p[4][2]);
	//printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);

	////ָ��������6:
	//int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//int* ptr1 = (int*)(&aa + 1);// ptr1 ��һ��ָ���ά�����ָ��, +1,��������������ά����
	//int* ptr2 = (int*)(*(aa + 1));//  ptr2 ָ���˵ڶ��е���Ԫ��
	//printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));




	system("pause");
	return 0;
}