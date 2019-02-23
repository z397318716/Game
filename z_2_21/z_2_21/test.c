#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

// Student ��һ����������(�ṹ������)
// ����:�Ѿ���������бȽϹ��ĵ���Ϣ��ȡ�����ڴ����б�ʾ


typedef struct Student{
	char name[1024];
	int score;
}Student;

// �ڴ������Ϊ��Ӳ����������Ч�ʸ��߶���Ƶ�.
typedef struct S1{
	double d;
	char i;
	int c2;
}S1;

 struct S2{
	char c1;//8
	struct S1;//16
	double d2;//8
}S2;

struct Node{
	int data;
	struct Node* n;
};

#define OFFSET(a,b)  ((char*)(&b)-(char*)(&a))

struct Data{
	int arr[1000];
	int size;
};

// �����˻���ָ��
//�ṹ�������Ϊ����������ʱ��,һ����Ҫ��ָ��ķ�ʽ������
//Ŀ��ֻ��һ��,�ܹ����ٺ�������ʱ�Ŀ�������
void PrintData(struct Data data){
	printf("%d\n", sizeof(data));
	printf("%d\n", data.size);
}

struct A{
	int _a : 2;//��ʾ ֻռ����������λ
	int _b : 5;//��ʾ ֻռ���������λ
	int _c : 10;//��ʾ ֻռ10��������λ
	int _d : 30;//��ʾ ֻռ30��������λ
};

enum Day{//����
	mon=1,
	tues,
	wed,
	thur,
	fri,
	sat,
	sun     //���һ����Ա����  ���Լ� ','   Ҳ���Բ���  ','
};


//<<Effective C++>>
//��һ��:
//C++ ��һ�� "��������"
//C++ ֧�ֶ��ֱ�̷��
// 1.���� C �Ĳ���
// 2.�������Ĳ���
// 3.���ͱ��
// 4.STL ��׼ģ���
// 5.����ʽ��̵Ĳ���

//�ڶ���:
//������Ҫʹ�ú� define
//����ʹ�� const,enum,template,inline ����궨�峣��




//C++��һ���汾     C++ 98
//C++�ڶ����汾     C++ 2003     �����98,�仯����(�޸��˲���bug)
//C++�������汾     C++ 0x  =>C++ 11(2011�귢��), ���츲�صİ汾
//C++���ĸ��汾     C++ 14       С�汾(����ܶ��ִ��ı�����Ե�����)
//C++������汾     C++ 17       �ֽ����°汾

//   [](){}    ��C++��  ������൱��һ�� ��������


union Un{
	int a;
	char i;
};


// ip ��ַ :
// 192.168.86.1  
//    1. ���ʮ���Ʊ�ʾ��ʽ)�ĸ����� ÿ������ 0-255  
//    2. Ҳ����ʹ��һ�� 32λ��������ʾ    
// ���ֱ�ʾ��ʽ��Ҫ����ת��

union IP{
	
	uint32_t ip;         //�൱�� unsigned int   ��Ҫʹ��Ԥ����ָ�� #include<stdint.h>
	struct{
		uint8_t a;
		uint8_t b;
		uint8_t c;
		uint8_t d;
	} ip_;

};



int main(){

	////ʹ�� typedef �� struct Student ������ �� Student 
	////�Ӷ�����ʡ��д struct ֱ��д�� Student student
	////struct Student student;
	//Student student = {"zhangsan",100};
	//strcpy(student.name, "zhangsan");//���ַ�ʽҲ���Գ�ʼ��


	////����һ��δ����ʼ���ı���,����δ������Ϊ
	//printf("%s\n", student.name);//   .  ��ʾ ��Ա���ʲ���

	
	//printf("%d\n", sizeof(struct s2));
	
	 //S1 s1 ;
	 //printf("%d\n", OFFSET(s1, s1.i));

	//struct Data d = { {0},0 };
	//PrintData(&d);

	//printf("%d\n", sizeof(struct A));

	//printf("%d\n", tues);

	//union Un u;
	//printf("%d\n", sizeof(u));
	//printf("%p\n", &u);
	//printf("%p\n", &u.a);
	//printf("%p\n", &u.i);

	union IP ip;
	ip.ip = 0x12345678;
	printf("%d.%d.%d.%d\n", ip.ip_.a, ip.ip_.b, ip.ip_.c, ip.ip_.d);




	system("pause");
	return 0;
}