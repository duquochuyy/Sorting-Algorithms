#pragma once

#include "header.h"
#include "Sort.h"
#include "CountCompare.h"

double timeSort(char* nameSort, int*& a, int n);

unsigned long long compareSort(char* nameSort, int*& a, int n);

void Command1(char* nameSort, char* givenInput, char* parameter);

void Command2(char* nameSort, char* inputSize, char* inputOrder, char* parameter);

void Command3(char* nameSort, char* inputSize, char* parameter);

void Command4(char* nameSort1, char* nameSort2, char* givenInput);

void Command5(char* nameSort1, char* nameSort2, char* inputSize, char* inputOrder);

void Menu();

void MenuOrder();

void MenuParameter();

void MenuSort();

