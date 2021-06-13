// Dutch National Flag algorithm with 4 colors
// C++ program to sort an array
// with 0, 1, 2, and 3 in a single pass

#include <iostream>
using namespace std;

// Function to sort the input array,
// the array is assumed
// to have values in {0, 1, 2, 3}
void sort0123(int arr[], int arr_size)
{
    int low = 0;
    int mid_1 = 0;
    int mid_2 = arr_size - 1;
    int high = arr_size - 1;

    // iterate till unknown part's size becomes 0
    while (mid_1 <= mid_2) {
      
        switch (arr[mid_1]) {
            
        // if the number is 0
        case 0: {
            swap(arr[mid_1], arr[low]);
            low++;
            mid_1++;
            break;
        }
            
        // if the number is 1
        case 1: {
            mid_1++;
            break;
        }
            
        // if the number is 2
        case 2: {
            swap(arr[mid_1], arr[mid_2]);
            mid_2--;
            break;
        }
            
        // if the number is 3
        case 3: {
            swap(arr[mid_1], arr[mid_2]);
            swap(arr[mid_2], arr[high]);
            high--;
            mid_2--;
            break;
        }
            
        }
    }
}

// Util method to print the array
void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " , ";
    }
    cout << endl;
}

// Driver method conataining the inputs and the function
// call
int main()
{
    // Example 1
    int arr[] = { 3, 2, 0, 1, 2, 0, 1 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
  
    sort0123(arr, arr_size);
  
    cout << "for array 1\n";
    print_arr(arr, arr_size);

  
    // Example 2
    int arr_2[]
        = { 1, 2, 0, 3, 3, 2, 0, 1, 2, 3, 0, 1, 3, 3, 1 };
    int arr_size_2 = sizeof(arr_2) / sizeof(arr_2[0]);
  
    sort0123(arr_2, arr_size_2);
  
    cout << "for array 2\n";
    print_arr(arr_2, arr_size_2);
  
    return 0;
}
