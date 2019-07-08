#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ͨѶ¼,��Ҫ�ڴ����б�ʾ���ɸ���

typedef struct personInfo{
	char name[1024];
	char phone[1024];
}personInfo;

#define SIZE 1000

typedef struct AddrBook{
	//SIZE ��ʾ��ͨѶ¼����Ϣ������
	personInfo person_info[SIZE];
	//ͨѶ¼�����ǳ���һ����,����� 1000 �����ݶ����������
	//������Ҫ��ע������Щ��Ϣ���������,��Щ��Ϣ��û�������
	// [0,size) �����������
	int size;
}AddrBook;

//����һ��ͨѶ¼�ı���,(�������г�ʼ��)
AddrBook g_addr_book;

enum{
	EXIT = 0,
	ADD,
	DEL,
	MODIFY,     //�޸�
	FIND,
	PRINT,
	CLEAR,
	SORT
};

void Init(){
	g_addr_book.size = 0;

	//����1 (��ʼ��)
	for (int i = 0; i < SIZE; ++i)
	{
		strcpy(g_addr_book.person_info[i].name, "");
		strcpy(g_addr_book.person_info[i].phone, "");
	}
	//����2 
	memset(g_addr_book.person_info, 0x0, sizeof(g_addr_book.person_info));
}

int Menu(){
	// ��ӡ�����û��ṩ�Ĳ���,
	// ��ʾ�û���������
	// ���û�����Ľ������
	printf("==========================\n");
	printf("1.���\n");
	printf("2.ɾ��\n");
	printf("3.�޸�\n");
	printf("4.����\n");
	printf("5.��ʾ\n");
	printf("6.���\n");
	printf("7.����\n");
	printf("0.�˳�\n");
	printf("==========================\n");
	printf("������ѡ��:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}


void AddPersonInfo()   
{

	//���һ���û���Ϣ��ͨѶ¼��
	//��ʾ�û�������ص��û���Ϣ,Ȼ��Ѷ�Ӧ�����ݸ��µ�������

	//assert(g_addr_book.size < SIZE);  //�˴�����ʹ�ö���,���ͨѶ¼������,sizeԽ��ᵼ�³������
	if (g_addr_book.size >= SIZE)
	{
		printf("��ǰͨѶ¼����,������Ϣʧ��!\n");
		return;
	}
	printf("���һ�����û�\n");
	printf("�������û���:\n");
	//�±�Ϊ size ��λ�þ���������Ҫ���õ���Ԫ�ص�λ��
	scanf("%s", g_addr_book.person_info[g_addr_book.size].name);
	printf("������绰����: ");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].phone);
	++g_addr_book.size;
	printf("����ɹ�!\n");
	return;
}

//�����û���Ϣ�ı�Ž���ɾ��
void DelPersonInfo()
{
	printf("ɾ��ָ����¼!\n");
	printf("������Ҫɾ������Ŀ�ı��: ");
	int num = 0;
	scanf("%d", &num);
	if (num < 0 || num > g_addr_book.size)
	{
		printf("����ı�Ų��Ϸ�!ɾ��ʧ��!\n");
		return;
	}
	//��ʱ��ȡһ�ֱȽϼ򵥵ķ���
	//1. ����û�Ҫɾ���������һ��Ԫ��, ֱ�� --g_addr_book.size
	if (num != g_addr_book.size - 1)
	{
		//��λ��Ԫ�� �ɸ���,Ҳ�ɲ�����
		//2. ����û�Ҫɾ�������м�ĳ��λ��Ԫ��,�Ͱ����һ��Ԫ����䵽��λ��
		strcpy(g_addr_book.person_info[num].name, g_addr_book.person_info[g_addr_book.size - 1].name);
		strcpy(g_addr_book.person_info[num].phone, g_addr_book.person_info[g_addr_book.size - 1].phone);
	}
	--g_addr_book.size;
	printf("ɾ���ɹ�!\n");
	return;
}

//�޸�ĳ���û���Ϣ,�û�����һ�������޸ĵı��,Ȼ����ݱ�Ž����޸�
void ModifyPersonInfo()
{
	printf("�޸�ĳ����¼!\n");
	printf("������Ҫ�޸ĵ���Ϣ�ı��: ");
	int num = 0;
	scanf("%d", &num);
	if (num < 0 || num > g_addr_book.size)
	{
		printf("����ı�Ų��Ϸ�,�޸�ʧ��!\n");
		return;
	}
	printf("�������µ��û���: ");
	scanf("%s", g_addr_book.person_info[num].name);
	printf("�������µĵ绰����: ");
	scanf("%s", g_addr_book.person_info[num].phone);
	printf("�޸ĳɹ�!\n");
}

//�����û������Ҷ�Ӧ�ĵ绰����
void FindPersonInfo()
{
	int count = 0;
	printf("���ҵ绰����!\n");
	printf("������Ҫ���ҵ�����: ");
	char name[1024] = { 0 };
	scanf("%s", name);

	for (int i = 0; i < g_addr_book.size; ++i)
	{
		if (strcmp(name, g_addr_book.person_info[i].name) == 0)
		{
			printf("�ҵ�һ�����! �绰����Ϊ: %s\n",g_addr_book.person_info[i].phone);
			++count;
		}
	}
	if (count == 0)
	{
		printf("û�ҵ�ָ������!\n");
	}
	else
	{
		printf("���ҳɹ�!���ҵ� %d ����¼\n",count);
	}
}

//��ӡ�����û���Ϣ
void PrintPersonInfo()
{
	printf("��ӡ�����û���Ϣ!\n");
	for (int i = 0; i < g_addr_book.size; ++i)
	{
		printf("[%d] %s %s\n",i, g_addr_book.person_info[i].name, g_addr_book.person_info[i].phone);
	}
	printf("��ӡ���!����ӡ�� %d ����¼!", g_addr_book.size);
	return;
}

// rm -rf /
void ClearPersonInfo()
{
	printf("��������û���Ϣ!\n");
	printf("ȷ��ɾ��?(y/n)\n");
	char input[1024] = { 0 };
	scanf("%s", input);
	if (strcmp(input, "y") != 0)
	{
		printf("ȡ��ɾ������!\n");
		return;
	}
	g_addr_book.size = 0; 
	printf("��ճɹ�!\n");
}

// ������������
void Sort()
{
	int i, j = 0;
	char tmp[1024] = " ";
	for (i = 0; i < g_addr_book.size - 1;++i)
	{
		for (j = 0; j < g_addr_book.size - i - 1; ++j)
		{
			if (strcmp(g_addr_book.person_info[j].name, g_addr_book.person_info[j + 1].name) > 0)
			{
				strcpy(tmp,g_addr_book.person_info[j].name);
				strcpy(g_addr_book.person_info[j].name,g_addr_book.person_info[j + 1].name);
				strcpy(g_addr_book.person_info[j + 1].name,tmp);

			}
		}
	}
}


int main(){

	// 1. �ȴ���һ�� ͨѶ¼ �ı���,���ҶԸñ������г�ʼ��
	Init();
	while (1)
	{

		// 2. ����ѭ��,��ӡһ���û��˵�,������ʾ�û����в���
		//    ��ɾ���
		
		int choice = Menu();
		// 3. �û���������Ӧ�ı��֮��,�͵��ö�Ӧ�Ĳ�������,��ɾ���� ��ɾ���
		switch (choice)
		{
		case ADD:
			AddPersonInfo();
			break;
		case DEL:
			DelPersonInfo();
			break;
		case MODIFY:
			ModifyPersonInfo();
			break;
		case FIND:
			FindPersonInfo();
			break;
		case PRINT:
			PrintPersonInfo();
			break;
		case CLEAR:
			ClearPersonInfo();
			break;
		case SORT:
			Sort();
			break;
		case EXIT:
			printf("�˳�!\n");
			system("pause");
			return 0;  //��ʱ��� break ����������ǰ���switch���,������ whileѭ��
		default:
			break;
		}
	}

	system("pause");
	return 0;
}