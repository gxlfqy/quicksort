#ifndef __QUICKSORT_H_INCLUDED__
#define __QUICKSORT_H_INCLUDED__

int compare(int a, int b);

void sort(int data[], int len, int(*compare)(int, int));

#endif // !__QUICKSORT_H_INCLUDED__
