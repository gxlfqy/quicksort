#include "quicksort.h"

void swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a -= *b;
}

//�Ƚ���
int compare(int a, int b)
{
	return a - b;
}

//��������
void quicksort(int data[], int left, int right, int(*compare)(int, int))
{
	int i = left;
	int j = right;
	int key = data[i];			/*��׼ֵ*/
	if (left >= right)
		return;
	while (i < j)
	{
		//�ҵ�һ���Ȼ�׼ֵС��Ԫ��, ����i�±�����Ӧ��Ԫ�ص���λ��
		while (j > i && compare(data[j], key) >= 0)
			j--;
		if (compare(data[j], key) < 0)
			swap(&data[j], &data[i]);
		//�ҵ�һ���Ȼ�׼ֵ���Ԫ��, ����j�±�����Ӧ��Ԫ�ص���λ��
		while (i < j && compare(data[i], key) <= 0)
			i++;
		if (compare(data[i], key) > 0)
			swap(&data[i], &data[j]);
	}
	quicksort(data, left, i - 1, compare);
	quicksort(data, i + 1, right, compare);
}

//������
void sort(int data[], int len, int(*compare)(int, int))
{
	quicksort(data, 0, len - 1, compare);
}
