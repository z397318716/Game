#include<stdio.h>



int foo()
{
	return 1;
}
int bar()
{
	return 2;
}

int main1()
{
	int a = foo(), bar();
	int b;
	b = (foo(), bar());
	printf("%d,%d\n", a, b);
	system("pause");
	return 0;
}