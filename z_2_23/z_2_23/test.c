#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//ͨѶ¼,��Ҫ�ڴ����б�ʾ���ɸ���
typedef struct Personinfo{
	char name[1024];
	char iphone[1024];
}Personinfo;
#define SIZE 1000

typedef struct Addrbook{
	//SIZE ��ʾͨѶ¼����Ϣ������
	Personinfo person_info[SIZE];
	//��Ҫ��ע����Щ��Ϣ���������,��Щ��Ϣ��û�������
	//ͨѶ¼�����ǳ���һ����,����� 1000�����ݶ����������
	//[0,1000) ������������
	int size;
}Addrbook;


Addrbook g_addr_book;

enum{
	EXIT = 0,
	ADD,
	DEL,
	MODIFY,       //�޸�
	FIND,         //����ĳ����¼
	PRINT,        //��ӡ��������
	CLEAR,        //�����������
};

void Init() {
	g_addr_book.size = 0;

	//��ʼ�����ַ�ʽ 1.for ѭ����ʽ   2. memset  ��ʽ
	//for (int i = 0; i < SIZE; ++i){
	//	strcpy(g_addr_book.person_info[i].name, "");
	//	strcpy(g_addr_book.person_info[i].iphone, "");
	//}

	memset(g_addr_book.person_info, 0x0, sizeof(g_addr_book.person_info));

};

int Menu(){
	// to do ��ӡ�����û��ṩ�Ĳ���
	//������ʾ�û���������
	//���û�����Ľ�����س���
	printf("===================\n");
	printf("1.���\n");
	printf("2.ɾ��\n");
	printf("3.�޸�\n");
	printf("4.����\n");
	printf("5.��ʾ\n");
	printf("6.���\n");
	printf("0.�˳�\n");
	printf("===================\n");
	printf("����������ѡ��: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Addpersoninfo(){
	// ���һ���û���Ϣ��ͨѶ¼��
	//��ʾ�û�������ص��û���Ϣ,Ȼ��Ѷ�Ӧ�����ݸ��µ�������

	//���Բ��ʺ��� (������Ҫ����)
	//assert(g_addr_book.size < SIZE);
	if (g_addr_book.size >= SIZE){
		printf("��ǰͨѶ¼����,����ʧ��!\n");
		return;
	}

	printf("���һ�����û�!\n");
	printf("�������û���: ");
	// �±�Ϊ size ��λ�þ���������Ҫ���õ���Ԫ�ص�λ��
	scanf("%s", g_addr_book.person_info[g_addr_book.size].name);
	printf("������绰����: ");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].iphone);
	++g_addr_book.size;
	printf("����ɹ�!\n");
	return;
}

// �����û���Ϣ�ı�Ž���ɾ��
void Delpersoninfo(){
	printf("ɾ��ָ����¼!\n");
	printf("������Ҫɾ������Ŀ�ı��: ");
	int num = 0;
	scanf("%d", &num);
	if (num<0 || num>g_addr_book.size){
		printf("����ı�Ų��Ϸ�!ɾ��ʧ��!\n");
		return;
	}
	// ��ʱ��ȡ�򵥵ķ���,
	//1.����û�Ҫɾ���������һ��Ԫ��,��ô��ֱ��  --size
	//2.����û�Ҫɾ������ĳ���м�λ�õ�Ԫ��,�Ͱ����һ��Ԫ����䵽��λ����,��ɾ�����һ����¼

	if (num != g_addr_book.size - 1){
		//2.����û�Ҫɾ������ĳ���м�λ�õ�Ԫ��,�Ͱ����һ��Ԫ����䵽��λ����,��ɾ�����һ����¼
		strcpy(g_addr_book.person_info[num].name, g_addr_book.person_info[g_addr_book.size - 1].name);
		strcpy(g_addr_book.person_info[num].iphone, g_addr_book.person_info[g_addr_book.size - 1].iphone);
		
	} else{
		//����û�Ҫɾ���������һ��Ԫ��,��ô��ֱ��  --size
		// ���Ԫ�ص������Ƿ���Ҫ���ǵ�,���ǻ��߲����Ƕ�����
		--g_addr_book.size;
	}
	printf("ɾ���ɹ�!\n");
	return;

}

//�޸�ĳ���û���Ϣ,�û�����һ����Ҫ�޸ĵı��,Ȼ����ݱ�Ž����޸�
void Modifypersoninfo(){
	printf("�޸�ĳ����¼!\n");
	printf("������Ҫ�޸ĵ���Ϣ�ı��: ");
	int num = 0;
	scanf("%d", &num);
	if (num < 0 || num >= g_addr_book.size){
		printf("����ı�Ų��Ϸ�,�޸�ʧ��!\n");
		return;
	} else{
		printf("�������µ��û���: ");
		scanf("%s", g_addr_book.person_info[num].name);
		printf("�������µ��û�����: ");
		scanf("%s", g_addr_book.person_info[num].iphone);
		printf("�޸ĳɹ�!\n");
	}

}

// �����û������Ҷ�Ӧ�ĵ绰����
void Findpersoninfo(){
	printf("���ҵ绰����!\n");
	printf("������Ҫ���ҵ�����: ");
	char name[1024] = { 0 };
	scanf("%s", name);
	for (int i = 0; i <= g_addr_book.size; ++i){
		if (strcmp(name, g_addr_book.person_info[i].name) == 0){
			printf("�ҵ�һ�����!�绰����Ϊ: %s\n", g_addr_book.person_info[i].iphone);

		}
	}
}

//��ӡ���е��û���Ϣ
void Printpersoninfo(){
	printf("��ӡ�����û���Ϣ!\n");
	for (int i = 0; i < g_addr_book.size; ++i){
		printf("[%d][%s] %s\n",i, g_addr_book.person_info[i].name,
			g_addr_book.person_info[i].iphone);
	}
	printf("��ӡ���! ����ӡ�� %d ����¼!\n", g_addr_book.size);
	return;

}

//  rm -rf /    ɾ����·
void Clearpersoninfo(){
	printf("��������û���Ϣ!\n");
	printf("�Ƿ�ȷ��ɾ�������û���Ϣ?(y/n)\n");
	char input[1024] = { 0 };
	scanf("%s", input);
	if (strcmp(input, "y") != 0){
		printf("ȡ����ɾ������!\n");
		return;
	}
	g_addr_book.size = 0;
	printf("��ճɹ�!\n");

}

int main(){
	// 1.�ȴ���һ�� ͨѶ¼ �ı���,����Ҳ��Ҫ������������г�ʼ��
	Init();
	while (1){
		// 2.����ѭ��,��ӡһ���û��˵�,������ʾ�û����в���
		// ��ɾ���
		int choice = Menu();
		// 3.�û���������Ӧ�ı��֮��,�͵�����Ӧ�Ĳ�������,��ɾ������ɾ���
		switch (choice){
		case ADD:
			Addpersoninfo();
			break;
		case DEL:
			Delpersoninfo();
			break;
		case MODIFY:
			Modifypersoninfo();
			break;
		case FIND:
			Findpersoninfo();
			break;
		case PRINT:
			Printpersoninfo();
			break;
		case CLEAR:
			Clearpersoninfo();
			break;
		case EXIT:
			printf("Goodbye!\n");
			system("pause");
			return 0;
		default:
			break;
		}
	
	}
	system("pause");
	return 0;
}