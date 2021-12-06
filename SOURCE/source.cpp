#include "source.h"

double timeSort(char* nameSort, int*& a, int n)
{
    //time_t start, end;
    //double temp;
    if (strcmp("selection-sort", nameSort) == 0) {
        auto start = chrono::high_resolution_clock::now(); 
        selectionSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto temp = chrono::duration_cast<chrono::microseconds>(end - start).count();
        return temp/1000.0;
    }
    if (strcmp("binary-insertion-sort", nameSort) == 0) {
        auto start = chrono::high_resolution_clock::now(); 
        insertionSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto temp = chrono::duration_cast<chrono::microseconds>(end - start).count();
        return temp/1000.0;
    }
    if (strcmp("bubble-sort", nameSort) == 0) {
        auto start = chrono::high_resolution_clock::now(); 
        bubbleSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto temp = chrono::duration_cast<chrono::microseconds>(end - start).count();
        return temp/1000.0;
    }
    if (strcmp("shaker-sort", nameSort) == 0) {
        auto start = chrono::high_resolution_clock::now(); 
        shakerSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto temp = chrono::duration_cast<chrono::microseconds>(end - start).count();
        return temp/1000.0;
    }
    if (strcmp("shell-sort", nameSort) == 0) {
        auto start = chrono::high_resolution_clock::now(); 
        shellSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto temp = chrono::duration_cast<chrono::microseconds>(end - start).count();
        return temp/1000.0;
    }
    if (strcmp("heap-sort", nameSort) == 0) {
        auto start = chrono::high_resolution_clock::now(); 
        heapSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto temp = chrono::duration_cast<chrono::microseconds>(end - start).count();
        return temp/1000.0;
    }
    if (strcmp("merge-sort", nameSort) == 0) {
        auto start = chrono::high_resolution_clock::now(); 
        mergeSort(a, 0, n-1);
        auto end = chrono::high_resolution_clock::now();
        auto temp = chrono::duration_cast<chrono::microseconds>(end - start).count();
        return temp/1000.0;
    }
    if (strcmp("quick-sort", nameSort) == 0) {
        auto start = chrono::high_resolution_clock::now(); 
        quickSort(a, 0, n-1);
        auto end = chrono::high_resolution_clock::now();
        auto temp = chrono::duration_cast<chrono::microseconds>(end - start).count();
        return temp/1000.0;
    }
    if (strcmp("counting-sort", nameSort) == 0) {
        auto start = chrono::high_resolution_clock::now(); 
        countingSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto temp = chrono::duration_cast<chrono::microseconds>(end - start).count();
        return temp/1000.0;
    }
    if (strcmp("radix-sort", nameSort) == 0) {
        auto start = chrono::high_resolution_clock::now(); 
        radixSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto temp = chrono::duration_cast<chrono::microseconds>(end - start).count();
        return temp/1000.0;
    }
    if (strcmp("flash-sort", nameSort) == 0) {
        auto start = chrono::high_resolution_clock::now(); 
        flashSort(a, n);
        auto end = chrono::high_resolution_clock::now();
        auto temp = chrono::duration_cast<chrono::microseconds>(end - start).count();
        return temp/1000.0;
    }
    return -1;
}

unsigned long long compareSort(char* nameSort, int*& a, int n)
{
    unsigned long long compare;
    if (strcmp("selection-sort", nameSort) == 0) {
        compare = 0;
        selectionSort(a, n, compare);
        return compare;
    }
    if (strcmp("binary-insertion-sort", nameSort) == 0) {
        compare = 0;
        insertionSort(a, n, compare);
        return compare;
    }
    if (strcmp("bubble-sort", nameSort) == 0) {
        compare = 0;
        bubbleSort(a, n, compare);
        return compare;
    }
    if (strcmp("shaker-sort", nameSort) == 0) {
        compare = 0;
        shakerSort(a, n, compare);
        return compare;
    }
    if (strcmp("shell-sort", nameSort) == 0) {
        compare = 0;
        shellSort(a, n, compare);
        return compare;
    }
    if (strcmp("heap-sort", nameSort) == 0) {
        compare = 0;
        heapSort(a, n, compare);
        return compare;
    }
    if (strcmp("merge-sort", nameSort) == 0) {
        compare = 0;
        mergeSort(a, 0, n-1, compare);
        return compare;
    }
    if (strcmp("quick-sort", nameSort) == 0) {
        compare = 0;
        quickSort(a, 0, n-1, compare);
        return compare;
    }
    if (strcmp("counting-sort", nameSort) == 0) {
        compare = 0;
        countingSort(a, n, compare);
        return compare;
    }
    if (strcmp("radix-sort", nameSort) == 0) {
        compare = 0;
        radixSort(a, n, compare);
        return compare;
    }
    if (strcmp("flash-sort", nameSort) == 0) {
        compare = 0;
        radixSort(a, n, compare);
        return compare;
    }
    return 0;
}

void Command1(char* nameSort, char* givenInput, char* parameter)
{
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << nameSort << endl;
    cout << "Input file: " << givenInput << endl;
    int n;
    int* a;
    ifstream fi(givenInput);
    if (fi.fail())
    {
        cout << "ERROR OPEN FILE! TRY AGAIN!\n";
        return;
    }
    fi >> n;
    cout << "Input size: " << n << endl;
    cout << "-------------------------\n";
    a = new int[n];
    for (int i=0; i<n ;i++)
        fi >> a[i];
    fi.close();

    ofstream fo("output.txt", ios::trunc);
    fo << n << endl;
    if (strcmp("-time", parameter) == 0) {
        double time = timeSort(nameSort, a, n);
        if (time < 0)
        {
            cout << "Error Name Sort\n";
            MenuSort();
            return;
        }
        cout << "Running time: " << time << " ms" << endl;
    }
    else if (strcmp("-comp", parameter) == 0) {
        unsigned long long compare = compareSort(nameSort, a, n);
        if (compare <= 0)
        {
            cout << "Error Name Sort\n";
            MenuSort();
            return;
        }
        cout << "Comparisions: " << compare << endl;
    }
    else if (strcmp("-both", parameter) == 0) {
        int* b = new int[n];
        for (int i = 0; i < n; i++)
            b[i] = a[i];
        double time = timeSort(nameSort, a, n);
        if (time < 0)
        {
            cout << "Error Name Sort\n";
            MenuSort();
            return;
        }
        cout << "Running time: " << time << " ms" << endl;
        unsigned long long compare = compareSort(nameSort, b, n);
        if (compare <= 0)
        {
            cout << "Error Name Sort\n";
            MenuSort();
            return;
        }
        cout << "Comparisions: " << compare << endl;
        delete[] b;
    }
    else {
        MenuParameter();
        return;
    }

    for (int i = 0; i < n; i++)
        fo << a[i] << " ";
    fo.close();

    delete[] a;
}

void Command2(char* nameSort, char* inputSize, char* inputOrder, char* parameter)
{
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << nameSort << endl;
    cout << "Input size: " << inputSize <<endl;
    int type;
    if (strcmp("-rand", inputOrder) == 0) {
        cout << "Input order: Randomize\n";
        type = 0;
    }
    else if (strcmp("-sorted", inputOrder) == 0) {
        cout << "Input order: Sorted\n";
        type = 1;
    }
    else if (strcmp("-rev", inputOrder) == 0) {
        cout << "Input order: Reversed\n";
        type = 2;
    }
    else if (strcmp("-nsorted", inputOrder) == 0) {
        cout << "Input order: Nearly Sorted\n";
        type = 3;
    }
    else {
        MenuOrder();
        return;
    }
    cout << "-------------------------\n";
    int n = atoi(inputSize);
    int* a = new int[n];
    
    GenerateData(a, n, type);
    ofstream fo1("input.txt", ios::trunc);
    fo1 << n << endl;
    for (int i = 0; i < n; i++)
        fo1 << a[i] << " ";
    fo1.close();

    ofstream fo("output.txt", ios::trunc);
    fo << n << endl;
    if (strcmp("-time", parameter) == 0) {
        double time = timeSort(nameSort, a, n);
        if (time < 0)
        {
            cout << "Error Name Sort\n";
            MenuSort();
            return;
        }
        cout << "Running time: " << time << " ms" << endl;
    }
    else if (strcmp("-comp", parameter) == 0) {
        unsigned long long compare = compareSort(nameSort, a, n);
        if (compare <= 0)
        {
            cout << "Error Name Sort\n";
            MenuSort();
            return;
        }
        cout << "Comparisions: " << compare << endl;
    }
    else if (strcmp("-both", parameter) == 0) {
        int* b = new int[n];
        for (int i = 0; i < n; i++)
            b[i] = a[i];
        double time = timeSort(nameSort, a, n);
        if (time < 0)
        {
            cout << "Error Name Sort\n";
            MenuSort();
            return;
        }
        cout << "Running time: " << time << " ms" << endl;
        unsigned long long compare = compareSort(nameSort, b, n);
        if (compare <= 0)
        {
            cout << "Error Name Sort\n";
            MenuSort();
            return;
        }
        cout << "Comparisions: " << compare << endl;
        delete[] b;
    }
    else {
        MenuParameter();
        return;
    }

    for (int i = 0; i < n; i++)
        fo << a[i] << " ";
    fo.close();

    delete[] a;

}

void Command3(char* nameSort, char* inputSize, char* parameter)
{
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << nameSort << endl;
    cout << "Input size: " << inputSize << "\n\n";
    int n = atoi(inputSize);
    int* a;
    int type[] = {0, 3, 1, 2};

    
    for (int k = 0; k < 4; k++)
    {
        if (type[k] == 0) {
            cout << "Input order: Randomize\n";
            a = new int[n];
            GenerateData(a, n, 0);
            ofstream fo1("input_1.txt", ios::trunc);
            fo1 << n << endl;
            for (int i = 0; i < n; i++)
                fo1 << a[i] << " ";
            fo1.close();
        }
        else if (type[k] == 1) {
            cout << "Input order: Sorted\n";
            a = new int[n];
            GenerateData(a, n, 1);
            ofstream fo3("input_3.txt", ios::trunc);
            fo3 << n << endl;
            for (int i = 0; i < n; i++)
                fo3 << a[i] << " ";
            fo3.close();
        }
        else if (type[k] == 2) {
            cout << "Input order: Reversed\n";
            a = new int[n];
            GenerateData(a, n, 2);
            ofstream fo4("input_4.txt", ios::trunc);
            fo4 << n << endl;
            for (int i = 0; i < n; i++)
                fo4 << a[i] << " ";
            fo4.close();
        }
        else {
            cout << "Input order: Nearly Sorted\n";
            a = new int[n];
            GenerateData(a, n, 3);
            ofstream fo2("input_2.txt", ios::trunc);
            fo2 << n << endl;
            for (int i = 0; i< n; i++)
                fo2 << a[i] << " ";
            fo2.close();
        }
        cout << "-------------------------\n";

        if (strcmp("-time", parameter) == 0) {
            double time = timeSort(nameSort, a, n);
            if (time < 0)
            {
            cout << "Error Name Sort\n";
            MenuSort();
            return;
            }
            cout << "Running time: " << time << " ms" << endl;
        }
        else if (strcmp("-comp", parameter) == 0) {
            unsigned long long compare = compareSort(nameSort, a, n);
            if (compare <= 0)
            {
            cout << "Error Name Sort\n";
            MenuSort();
            return;
            }
            cout << "Comparisions: " << compare << endl;
        }
        else if (strcmp("-both", parameter) == 0) {
            int* b = new int[n];
            for (int i = 0; i < n; i++)
                b[i] = a[i];
            double time = timeSort(nameSort, a, n);
            if (time < 0)
            {
                cout << "Error Name Sort\n";
                MenuSort();
                return;
            }
            cout << "Running time: " << time << " ms" << endl;
            unsigned long long compare = compareSort(nameSort, b, n);
                if (compare <= 0)
            {
                cout << "Error Name Sort\n";
                MenuSort();
                return;
            }
            cout << "Comparisions: " << compare << endl;
            delete[] b;
        }
        else {
            MenuParameter();
            return;
        }
        delete[] a;
        cout << endl;
    }
}

void Command4(char* nameSort1, char* nameSort2, char* givenInput)
{
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << nameSort1 << " | " << nameSort2 << endl;
    cout << "Input file: " << givenInput << endl;
    int n;
    int* a;
    ifstream fi(givenInput);
    if (fi.fail())
    {
        cout << "ERROR OPEN FILE! TRY AGAIN!\n";
        return;
    }
    fi >> n;
    cout << "Input size: " << n << endl;
    cout << "-------------------------\n";
    a = new int[n];
    for (int i=0; i <n ;i++)
        fi >> a[i];
    fi.close();
    //a, b: sort1 ; aa,bb: sort 2
    int* b = new int[n];
    int* aa = new int[n];
    int* bb = new int[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
        aa[i] = a[i];
        bb[i] = a[i];
    }
    double time1 = timeSort(nameSort1, a, n);
    if (time1 < 0)
        {
            cout << "Error Name Sort\n";
            MenuSort();
            return;
        }
    double time2 = timeSort(nameSort2, aa, n);
    if (time2 < 0)
        {
            cout << "Error Name Sort\n";
            MenuSort();
            return;
        }
    cout << "Running time: " << time1 << " ms | " << time2 << " ms\n"; 
    unsigned long long compare1 = compareSort(nameSort1, b, n);
    unsigned long long compare2 = compareSort(nameSort2, bb, n);
    cout << "Comparisions: " << compare1 << " | " << compare2 << endl;

    delete[] a;
    delete[] b;
    delete[] aa;
    delete[] bb;
}

void Command5(char* nameSort1, char* nameSort2, char* inputSize, char* inputOrder)
{
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << nameSort1 << " | " << nameSort2 << endl;
    cout << "Input size: " << inputSize << endl;
    int n = atoi(inputSize);
    int* a = new int[n];
    int* b = new int[n];
    int* aa = new int[n];
    int* bb = new int[n];
    if (strcmp("-rand", inputOrder) == 0) {
        cout << "Input order: Randomize\n";
        GenerateData(a, n, 0);
    }
    else if (strcmp("-sorted", inputOrder) == 0) {
        cout << "Input order: Sorted\n";
        GenerateData(a, n, 1);
    }
    else if (strcmp("-rev", inputOrder) == 0) {
        cout << "Input order: Reversed\n";
        GenerateData(a, n, 2);
    }
    else if (strcmp("-nsorted", inputOrder) == 0) {
        cout << "Input order: Nearly Sorted\n";
        GenerateData(a, n, 3);
    }
    else {
        MenuOrder();
        return;
    }
    cout << "-------------------------\n";
    ofstream fo("input.txt", ios::trunc);
    fo << n << endl;
    for (int i = 0; i < n; i++)
    {
        fo << a[i] << " ";
        b[i] = a[i];
        aa[i] = a[i];
        bb[i] = a[i];
    }

    double time1 = timeSort(nameSort1, a, n);
    double time2 = timeSort(nameSort2, aa, n);
    cout << "Running time: " << time1 << " ms | " << time2 << " ms\n"; 
    unsigned long long compare1 = compareSort(nameSort1, b, n);
    unsigned long long compare2 = compareSort(nameSort2, bb, n);
    cout << "Comparisions: " << compare1 << " | " << compare2 << endl;

    delete[] a;
    delete[] b;
    delete[] aa;
    delete[] bb;
}

void Menu()
{
    cout << "*Command 1: \n";
    cout << "Prototype: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)\n";
    cout << "*Command 2: \n";
    cout << "Prototype: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]\n";
    cout << "*Command 3: \n";
    cout << "Prototype: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]\n";
    cout << "*Command 4: \n";
    cout << "Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]\n";
    cout << "*Command 5: \n";
    cout << "Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]\n";
}

void MenuOrder()
{
    cout << "*Data Order\n";
    cout << "-rand: randomized data\n";
    cout << "-nsorted: nearly sorted data\n";
    cout << "-sorted: sorted data\n";
    cout << "-rev: reverse sorted data\n";
}

void MenuParameter()
{
    cout << "*Parameter\n";
    cout << "-time: algorithms's running time\n";
    cout << "-comp: number of comparisions\n";
    cout << "-both: both above options\n";
}

void MenuSort()
{
    cout << "*key Sort\n";
    cout << "selection-sort\n";
    cout << "binary-insertion-sort\n";
    cout << "bubble-sort\n";
    cout << "shaker-sort\n";
    cout << "shell-sort\n";
    cout << "heap-sort\n";
    cout << "merge-sort\n";
    cout << "quick-sort\n";
    cout << "counting-sort\n";
    cout << "radix-sort\n";
    cout << "flash-sort\n";
}