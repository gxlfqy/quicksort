#include "quicksort.h"

void swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a -= *b;
}

//比较器
int compare(int a, int b)
{
	return a - b;
}

//快速排序
void quicksort(int data[], int left, int right, int(*compare)(int, int))
{
	int i = left;
	int j = right;
	int key = data[i];			/*基准值*/
	if (left >= right)
		return;
	while (i < j)
	{
		//找到一个比基准值小的元素, 并与i下标所对应的元素调换位置
		while (j > i && compare(data[j], key) >= 0)
			j--;
		if (compare(data[j], key) < 0)
			swap(&data[j], &data[i]);
		//找到一个比基准值大的元素, 并与j下标所对应的元素调换位置
		while (i < j && compare(data[i], key) <= 0)
			i++;
		if (compare(data[i], key) > 0)
			swap(&data[i], &data[j]);
	}
	quicksort(data, left, i - 1, compare);
	quicksort(data, i + 1, right, compare);
}

//排序函数
void sort(int data[], int len, int(*compare)(int, int))
{
	quicksort(data, 0, len - 1, compare);
}
