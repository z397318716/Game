#include<stdio.h>




int main()
{
	int tmp = 0;
	int arr[10] = { 2, 1, 3, 5, 4, 6, 7, 8, 9, 0 };
	for (int i = 0; i <= 10; ++i)
	{
		for (int j = 0; j < 10 - i; ++j)
		{
			if (arr[j]>arr[j+1])
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}



	system("pause");
	return 0;
}