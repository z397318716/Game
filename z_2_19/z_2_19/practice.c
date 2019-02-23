#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int tolower(char c){
	//1.如果当前字符不是字母,不需要转换
	//2.如果当前字符是小写字母,不需要转换
	//3.如果当前字符是大写字母,转换
	if (c >= 'A'&&c <= 'Z'){
		return c + ('a' - 'A');
	}
	return c;
}

////第一种实现方式
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

//第二种实现,(不创建临时变量) 递归
int Mystrlen(const char* str){
	if (str == NULL){
		return -1;
	}
	if (str == '\0'){
		//空字符串
		return 0;
	}
	return 1 + Mystrlen(str + 1);
}

char* Mystrcpy(char* dest, const char* source){
	//if (dest == NULL || source == NULL){
	//	return NULL;
	//}

	//assert 断言中填一个表达式,如果表达式的值为 真,断言通过,无事发生
	//如果表达式的值为 假,断言失败,会引起程序崩溃.
	assert(source != NULL);
	assert(dest != NULL);
	char* ret = dest;
	while (*source != '\0'){
		*dest = *source;
		++source;
		++dest;
	}
	// strcpy  需要拷贝最终的  \0 
	*dest = '\0';//比较容易遗漏
	return ret;
}


char* Mystrcat(char* dest, const char* src){
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	//1. 先找到 dest 指向的字符串的结束位置
	while (*dest != '\0'){
		++dest;
	}
	//2. 然后再把 src 中的内容依次拷贝到 dest 的结束位置
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
	//此处需要保证让 str1 先结束的时候,不认为两个字符串相等
	//str2 先结束的时候,才能认为是相等

	////Mystrstr 函数调用时,需要注释 下面部分  当str1 或 str2 遇到 \0 时,Mystrstr函数比较结束
	////到这一步,某个 str 遇到了 \0
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


//  在 str1 中尝试查找 str2
//例如:打一次的时候,str1 指向字符串的起始位置,然后比较str1 和 str2
//但是此处不考虑长度不相同的情况
// str1 => hello world
// str2 => hello
// str1 指向的内容 和 str2 指向的内容相同
char* Mystrstr(const char* str1, const char* str2){
	assert(str1 != NULL);
	assert(str2 != NULL);
	// 通常情况下,不允许把一个 const 类型的指针赋值给 非const 类型的指针
	// 可以写成 const char* p=str1;
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
		// 先将 void* 强转成 char* 然后在 解引用  在进行 赋值 (void*不能直接解引用 因为不知道房间大小)
		*(char*)dest = *(char*)src;
		//本来应该是 ++dest  但是因为指针自增是需要跳过完整的元素的,由于 void* 不知道大小,所以不知道该跳过几个 ,会导致程序出错
		// 所以在 ++ 之前,先进行 指针类型的强转
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
	// 判定一下当前的 dest 是否和 src 重合.如果不重合,那就正常拷贝.
	//如果重合了,就倒着拷贝
	//区间重合的含义是: dest 在 [src,src+num)
	if (dest <= src||(char*)dest>=(char*)src+num){
		//没有重合,按照正常思路拷贝
		for (size_t i = 0; i < num; ++i){
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	} else{
		//区间重合了,反着拷贝
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

//错误的分级
//FATAL     致命的
//ERROR     严重的
//WARNING     警告
//INFO        提示(一般不认为是错误)


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