#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int tolower(char c){
	//1.�����ǰ�ַ�������ĸ,����Ҫת��
	//2.�����ǰ�ַ���Сд��ĸ,����Ҫת��
	//3.�����ǰ�ַ��Ǵ�д��ĸ,ת��
	if (c >= 'A'&&c <= 'Z'){
		return c + ('a' - 'A');
	}
	return c;
}

////��һ��ʵ�ַ�ʽ
//int Mystrlen(const char* str){
//	if (str == NULL){
//		return -1;
//	}
//	int size = 0;
//	while (*str != '\0'){
//		++size;
//		++str;
//	}
//	return size;
//}

//�ڶ���ʵ��,(��������ʱ����) �ݹ�
int Mystrlen(const char* str){
	if (str == NULL){
		return -1;
	}
	if (str == '\0'){
		//���ַ���
		return 0;
	}
	return 1 + Mystrlen(str + 1);
}

char* Mystrcpy(char* dest, const char* source){
	//if (dest == NULL || source == NULL){
	//	return NULL;
	//}

	//assert ��������һ�����ʽ,������ʽ��ֵΪ ��,����ͨ��,���·���
	//������ʽ��ֵΪ ��,����ʧ��,������������.
	assert(source != NULL);
	assert(dest != NULL);
	char* ret = dest;
	while (*source != '\0'){
		*dest = *source;
		++source;
		++dest;
	}
	// strcpy  ��Ҫ�������յ�  \0 
	*dest = '\0';//�Ƚ�������©
	return ret;
}


char* Mystrcat(char* dest, const char* src){
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	//1. ���ҵ� dest ָ����ַ����Ľ���λ��
	while (*dest != '\0'){
		++dest;
	}
	//2. Ȼ���ٰ� src �е��������ο����� dest �Ľ���λ��
	Mystrcpy(dest, src);
	return ret;
}


int Mystrcmp(const char* str1, const char* str2){
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (*str1 != '\0'&&*str2 != '\0'){
		if (*str1 <*str2){
			return -1;
		}
		else if (*str1>*str2){
			return 1;
		}
		else{
			++str1;
			++str2;
		}
	}
	//�˴���Ҫ��֤�� str1 �Ƚ�����ʱ��,����Ϊ�����ַ������
	//str2 �Ƚ�����ʱ��,������Ϊ�����

	////Mystrstr ��������ʱ,��Ҫע�� ���沿��  ��str1 �� str2 ���� \0 ʱ,Mystrstr�����ȽϽ���
	////����һ��,ĳ�� str ������ \0
	//if (*str1 < *str2){
	//	return -1;
	//}
	//else if (*str1>*str2){
	//	return 1;
	//}
	//else{
	//	return 0;
	//}

	return 0;
}


//  �� str1 �г��Բ��� str2
//����:��һ�ε�ʱ��,str1 ָ���ַ�������ʼλ��,Ȼ��Ƚ�str1 �� str2
//���Ǵ˴������ǳ��Ȳ���ͬ�����
// str1 => hello world
// str2 => hello
// str1 ָ������� �� str2 ָ���������ͬ
char* Mystrstr(const char* str1, const char* str2){
	assert(str1 != NULL);
	assert(str2 != NULL);
	// ͨ�������,�������һ�� const ���͵�ָ�븳ֵ�� ��const ���͵�ָ��
	// ����д�� const char* p=str1;
	char* p = str1;
	for (; *p != '\0'; ++p){
		if (Mystrcmp(p, str2) == 0){
			return p;
		}
	}
	return NULL;
}


void* Mymemcpy(void* dest,const void* src, size_t num){
	void* ret = dest;
	for (size_t i = 0; i < num; ++i){
		// �Ƚ� void* ǿת�� char* Ȼ���� ������  �ڽ��� ��ֵ (void*����ֱ�ӽ����� ��Ϊ��֪�������С)
		*(char*)dest = *(char*)src;
		//����Ӧ���� ++dest  ������Ϊָ����������Ҫ����������Ԫ�ص�,���� void* ��֪����С,���Բ�֪������������ ,�ᵼ�³������
		// ������ ++ ֮ǰ,�Ƚ��� ָ�����͵�ǿת
		dest=(char*)dest+1;
		src = (char*)src + 1;
	}
	return ret;
}


void* Mymemmove(void* dest, void* src, size_t num){
	assert(dest != NULL);
	assert(src != NULL);
	assert(num != 0);
	void* ret = dest;
	// �ж�һ�µ�ǰ�� dest �Ƿ�� src �غ�.������غ�,�Ǿ���������.
	//����غ���,�͵��ſ���
	//�����غϵĺ�����: dest �� [src,src+num)
	if (dest <= src||(char*)dest>=(char*)src+num){
		//û���غ�,��������˼·����
		for (size_t i = 0; i < num; ++i){
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	} else{
		//�����غ���,���ſ���
		dest = (char*)dest + num - 1;
		src = (char*)src + num - 1;
		for (size_t i = 0; i < num; ++i){
			*(char*)dest = *(char*)src;
			dest = (char*)dest - 1;
			src = (char*)src - 1;

		}
	}
	return ret;
}

//����ķּ�
//FATAL     ������
//ERROR     ���ص�
//WARNING     ����
//INFO        ��ʾ(һ�㲻��Ϊ�Ǵ���)


int main(){
	
	

	//int size = Mystrlen("abcdef");

	//printf("%c\n", tolower('A'));
	//printf("%d\n", size);

	//char str1[] = "abcd";
	//char str2[1024] = { 0 };
	//Mystrlen(str2, str1);
	//printf("%s\n", str2);


	//char str1[] = "abcd";
	//char str2[] = "abce";
	//int ret = Mystrcmp(str1, str2);
	//printf("%d\n", ret);


	//char str1[] = "abcd";
	//char str2[] = "abc";
	//char* ret = Mystrstr(str1, str2);
	//printf("%p\n", ret);
	//printf("%p\n", str1);


	//int src[] = { 1, 2, 3, 4 , 5 , 6 , 7 };
	//int dest[10] = { 0, 1, 2, 3 , 4 , 5 };
	//Mymemcpy(dest, src, sizeof(src));
	//for (int i = 0; i < 10; ++i){
	//	printf("%d\n", dest[i]);
	//}


	//int src[100] = { 1, 2, 3, 4 };
	//Mymemmove(src + 1, src, sizeof(src[0])*4);
	//for (int i = 0; i < 10; ++i){
	//	printf("%d\n", src[i]);
	//}

	

	system("pause");
	return 0;
}