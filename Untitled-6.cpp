#include <iostream>
using namespace std;


int findMin(int *arr, int size) {
    int min = *arr; 
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) < min)
        {  
            min = *(arr + i);    
        }
    }
    return min;
}

int main()
{
    int arr[] = {5, 2, 9, 1, 6, 3, 7, 8}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    int minElement = findMin(arr, size); 
    cout << "The minimum element in the array is: " << minElement << endl;
    return 0;
}

