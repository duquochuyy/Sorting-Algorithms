#pragma once
#include "DataGenerator.h"

void selectionSort(int*& a, int n, unsigned long long& compare);

void insertionSort(int*& a ,int n, unsigned long long& compare);

void bubbleSort(int*& a, int n, unsigned long long& compare);

void shakerSort(int*& a, int n, unsigned long long& compare);

void shellSort(int*& a, int n, unsigned long long& compare);

void sift(int*& a, int left, int right, unsigned long long& compare);
void heapSort(int*& a, int n, unsigned long long& compare);

void merge(int a[], int l, int m, int r, unsigned long long& compare);
void mergeSort(int*& a, int l, int r, unsigned long long& compare);

void quickSort(int* a, int l, int r, unsigned long long& compare);

void countingSort(int*& a, int n, unsigned long long& compare);

void countSort(int*& a, int n, int exp, unsigned long long& compare);
void radixSort(int*& a, int n, unsigned long long& compare);

void flashSort(int*& a, int n, unsigned long long& compare);