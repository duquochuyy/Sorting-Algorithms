#pragma once
#include <iostream>
#include "DataGenerator.h"

void selectionSort(int*& a, int n);

void insertionSort(int*& a ,int n);

void bubbleSort(int*& a, int n);

void shakerSort(int*& a, int n);

void shellSort(int*& a, int n);

void sift(int*& a, int left, int right);
void heapSort(int*& a, int n);

void merge(int a[], int l, int m, int r);
void mergeSort(int*& a, int l, int r);

void quickSort(int* a, int l, int r);

void countingSort(int*& a, int n);

void countSort(int*& a, int n, int exp);
void radixSort(int*& a, int n);

void flashSort(int*& a, int n);