#include "Sort.h"


//selection sort
void selectionSort(int*& a, int n)
{
    int i, j, minIndex;
    for (i = 0; i < n-1; i++)
    {
        minIndex = i;
        //tim vi tri nho nhat trong phan chua sap xep
        for (j = i+1; j < n; j++)
            if (a[j] < a[minIndex])
                minIndex = j;
        //hoan doi vi tri 
        swap(a[i], a[minIndex]);
    }
}

//insertion sort
void insertionSort(int*& a ,int n)
{
	int l, r, m, v;
	for (int i = 1; i < n; i++)
	{
		l = 0; r = i - 1; v = a[i];
        //tim kiem nhi phan de tim dung vi tri cua phan tu can chen
		while (l <= r)
		{
			m = (r + l) / 2;
			if (a[m] > v)
				r = m - 1;
			else
				l = m + 1;
		}
        //chen phan tu
		for (int j = i - 1; j >= l; j--)
			a[j + 1] = a[j];
		a[l] = v;
	}
}

//bubble sort
void bubbleSort(int*& a, int n)
{
	bool kt;
	int k = n-1, temp;
	do
	{
		kt = false;
		for (int j = 0; j < k; j++)
			if (a[j] > a[j+1])
			{
				swap(a[j], a[j+1]);
				kt = true;    //co su sap xep
                temp = j + 1;
			}
		//neu ko co sap xep -> mang da dung
		if (kt == false)
			break;
        k = temp;    //luu lai vi tri sap xep cuoi cung
	} while (true);
}

//shaker sort
void shakerSort(int*& a, int n)
{
    int l = 1, r = n - 1, k = n - 1;
    do
    {
        //duyet tu tren xuong
        for (int j = r; j >= l; j--)
            if (a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
                k = j;
            }
        l = k + 1;
        //duyet tu duoi len
        for (int j = l; j <= r; j++)
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
                k = j;
            }
        r = k - 1;

    } while (l <= r);
}

//shell sort
void shellSort(int*& a, int n)
{
    int interval, i, j, temp;
    for (interval = n/2; interval > 0; interval /= 2)   //chia khoang
    {
        for (i = interval; i < n; i++)
        {
            //insertion Sort
            temp = a[i];
            for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
                a[j] = a[j-interval];
            a[j] = temp;
        }
    }
}

//heap sort
//xay dung cau truc heap
void sift(int*& a, int left, int right)
{
	int i = left;
	int j = 2 * i + 1;
	int x = a[i];
	while (j <= right)
	{
		if (j < right)
			if (a[j] < a[j+1]) /**/
				j = j + 1;
		if (x >= a[j]) /**/
			break;
		a[i] = a[j];
		i = j;
		j = 2 * i + 1;
	}
	a[i] = x;
}

void heapSort(int*& a, int n)
{
	int left = (n - 1) / 2;
	int right = n - 1;
	//tao cau truc heap cho mang
	while (left >= 0)
	{
		sift(a,left,right);
		left--;
	}
	//hoan doi vi tri de tao ra mang co thu tu dung
	while (right > 0)
	{
		swap(a[0], a[right]);
		right--;
		sift(a,0,right);
	}
}

//merge sort
void merge(int a[], int l, int m, int r)
{
	int i, j, k = l;
	int n1 = m - l + 1;
	int n2 = r - m;
    int* L = new int [n1];
    int* R = new int [n2];
	for (i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (j=0; j < n2; j++)
		R[j] = a[m + j + 1];
	i = 0; j = 0;
	//gop 2 mang con
	while (i < n1 && j < n2)
	{
		if (L[i] < R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	//neu con sot phan tu o mang L
	while (i < n1)
	{
		a[k] = L[i];
		k++; i++;
	}
	//neu con sot phan tu o mang R
	while (j < n2)
	{
		a[k] = R[j];
		k++; j++;
	}
    delete[] L;
    delete[] R;
}

//merge sort
void mergeSort(int*& a, int l, int r)
{
	if (l >= r)
		return;
	//chia mang lam 2 nua
	int m = ( r + l ) / 2;
	mergeSort(a, l, m);
	mergeSort(a, m + 1, r);
	//gop 2 mang con
	merge(a, l, m, r);
}

//quick sort
void quickSort(int* a, int l, int r)
{
	int x = (l + r) / 2;
	int pivot = a[x]; // chon phan tu o giua lam pivot
	int i, j;
	i = l;
	j = r;
	do
	{
		while (a[i] < pivot)
			i++; // neu nho hon pivot thi xet so ke tiep
		while (a[j] > pivot)
			j--; // neu lon hon pivot thi lui ve truoc de xet
		if (i <= j)    
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i < j);
	//swap(a[i], a[j]);
	if (l < j)
		quickSort(a, l, j); 
	if (i < r)
		quickSort(a, i, r); 
}

//counting sort
void countingSort(int*& a, int n)
{
	int* b= new int [n];
    int max = a[0];
    int min = a[0];
    int i;
    //Tim max min cua mang
    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }
    int k = max - min + 1;
    int* count = new int[k];    //size cua mang dem
    for (i = 0; i < k; i++)
        count[i] = 0;
    for (i = 0; i < n; i++)     //nhot phan tu vao
        count[a[i] - min]++;
    for (i = 1; i < k; i++)     //gop lai
        count[i] += count[i-1]; 
    //dua phan tu vao b
    for (i = 0; i < n; i++)
    {
        b[count[a[i] - min] - 1] = a[i];
        count[a[i] - min]--;
    }
    for (i = 0; i < n; i++)
        a[i] = b[i];
	delete[] b;
    delete[] count;
}

//radix sort
void countSort(int*& a, int n, int exp)
{
    int* b = new int [n];
    int i, count[10] = {0};
    //dem so phan tu co tan cung la 0->9
    for (i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;
    //su dung counting sort
    for (i = 1; i < 10; i++)
        count[i] += count[i-1];
    //tao mang b la mang sap xep
    for (i = n - 1; i >= 0; i--) 
    {
        b[count[(a[i] / exp) % 10] - 1] = a[i]; 
        count[(a[i] / exp) % 10]--; //sau khi lay ra 1 phan tu
    }
    //copy mang b vao a
    for (i = 0; i < n; i++)
        a[i] = b[i];
    delete[] b;
}

//radix sort
void radixSort(int*& a, int n)
{
    int max = a[0];
    //tim max cua mang
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    //duyet tung chu so 
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(a, n, exp);
}

//flash sort
void flashSort(int*& a, int n)
{
    //Giai doan 1: xac dinh phan lop
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* L = new int[m];
	for (int i = 0; i < m; i++)
		L[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++L[k];
	}
	for (int i = 1; i < m; i++)
		L[i] += L[i - 1];
	

    //Giai doan 2: dua cac phan tu ve dung phan lop
	swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		while (j > L[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != L[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --L[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] L;
    
	//Giai doan 3: sap xep toan cuc bang insertion Sort
    int left, right, mid, v;
	for (int i = 1; i < n; i++)
	{
		left = 0; right = i - 1; v = a[i];
		while (left <= right)
		{
			mid = (right + left) / 2;
			if (a[mid] > v)
				right = mid - 1;
			else
				left = mid + 1;
		}
		for (j = i - 1; j >= left; j--)
			a[j + 1] = a[j];
		a[left] = v;
	}
}


