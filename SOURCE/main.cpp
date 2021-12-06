#include "DataGenerator.h"
#include "Sort.h"
#include "CountCompare.h"
#include "source.h"

//selectionSort(a, n)
//insertionSort(a, n)
//bubbleSort(a, n)
//shakerSort(a, n)
//shellSort(a, n)
//heapSort(a, n)
//mergeSort(a, 0, n-1)
//quickSort(a, 0, n-1)
//countingSort(a, n)
//radixSort(a, n)
//flashSort(a, n)


int main(int argc, char* argv[])
{
    // Menu();
    // MenuOrder();
    // MenuParameter();
    if (argc == 5)
    {
        if (strcmp("-a", argv[1]) == 0)
        {
            int temp = atoi(argv[3]);
            if (temp == 0)
            {
                Command1(argv[2], argv[3], argv[4]);
                cout << "\n\n";
            }
            else if (temp > 0)
            {
                Command3(argv[2], argv[3], argv[4]);
                cout << "\n";
            }
            else
                Menu();
        }
        else { 
            if (strcmp("-c", argv[1]) == 0)
            {
                Command4(argv[2], argv[3], argv[4]);
                cout << "\n\n";
            }
            else
                Menu();
        }
    }
    else if (argc == 6)
    {
        if (strcmp("-a" , argv[1]) == 0)
        {
            Command2(argv[2], argv[3], argv[4], argv[5]);
            cout << "\n\n";
        }
        else if (strcmp("-c", argv[1]) == 0)
        {
            Command5(argv[2], argv[3], argv[4], argv[5]);
            cout << "\n\n";
        }
        else 
            Menu();
    }
    else 
        Menu();

    return 0;
}