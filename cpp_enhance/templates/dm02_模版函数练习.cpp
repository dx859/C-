#include <iostream>
#include "string.h"
using namespace std;

template <typename T, typename T2>
int mySort(T *array, T2 size)
{
    T2 i, j;
    T tmp;
    if (array == NULL)
        return -1;

    for (i=0; i<size; i++) {
        for (j=i+1; j<size; j++) {
            if (array[i] > array[j]) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }

}

template <typename T, typename T2>
int myPrint(T *array, T2 size)
{
    T2 i=0;
    for (i=0; i<size; i++)
        cout << array[i] << " ";

    cout << endl;
    return 0;
}

int main()
{
    int size;

    int arr[] = {11, 33,44, 33,22, 2, 3, 6, 9};
    size = sizeof(arr) / sizeof(*arr);
    mySort<int , int>(arr, size);
    myPrint(arr, size);

    char buf[] = "helloworld";
    size = strlen(buf);
    mySort(buf, size);
    myPrint(buf, size);

    return 0;
}
