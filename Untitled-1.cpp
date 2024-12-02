#include <iostream>
using namespace std;

void removeDuplicates(int arr[], int& size)
 {
    for (int i = 0; i < size; i++) 
    {

        for (int j = i + 1; j < size; j++)
         {
            if (arr[i] == arr[j]) 
            {
                
                for (int k = j; k < size - 1; k++) 
                {
                    arr[k] = arr[k + 1];
                }
                size--;  
                j--;  
            }
        }
    }
}

void displayArray(int arr[], int size)
 {
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " "; 
    }
    cout << endl;
}

int main() {
    int arr[10];
    int size = 10;

    cout << "Enter 10 integers:" << endl;
    for (int i = 0; i < size; i++) 
    {
        cin >> arr[i];  
    }

    removeDuplicates(arr, size);

    cout << "Array after removing duplicates:" << endl;
    displayArray(arr, size);

    return 0;
}

