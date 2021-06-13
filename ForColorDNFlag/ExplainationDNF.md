
#### You may already know about the Dutch National Flag algorithm. It is an algorithm to sort an array containing N entries. Each entry will be one of the 3 distinct numbers. This will work in O(n) time complexity and O(1) space complexity.

You can learn more about Dutch National Flag algorithm [here](https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/).

Dutch National Flag algorithm is a prerequisite for important algorithms such as the 3-way quicksort as mentioned [here](https://www.geeksforgeeks.org/3-way-quicksort-dutch-national-flag/).

### Today, we'll discuss a slightly more complex variant of the DNF problem with 4 colors.

It can be used to sort an array containing 4 distinct types of numbers.

// Example 1:
input:  {3,2,0,1,2,0,1} 
output: {0,0,1,1,2,2,3}

//Example 2:
input:  {1,2,0,3,3,2,0,1,2,3,0,1,3,3,1} 
output: {0,0,0,1,1,1,1,2,2,2,3,3,3,3,3}

### Approach:

_Originally, the problem was devised considering colors. We'll consider those colors as 0,1,2, and 3._

1.  arr[ 0 .. low -1 ] contains 0
2.  arr[ low .. mid1 -1 ] contains 1
3.  arr[ mid1 .. mid2 ] is unknown
4.  arr[ mid2 + 1 .. high - 1 ] contains 2
5.  arr[ high .. n-1 ] contains 3
6.  In each turn, we decrease the unknown part by 1.
7.  if the element on mid1 position is 0, we swap it with the element at low position, and increment both low and mid1 by 1.
8.  if the element on mid1 position is 1, we increment mid1 by 1.
9.  if the element on mid1 position is 2, we swap it with the element at mid2 position, and decrement mid2 by 1.
10.  if the element on mid1 position is 3, we swap it with the element at mid_2 position. Then we swap the element at mid2 with the element at high. At last, we decrement both high and mid2 by 1.
11.  we repeat this procedure until the length of the unknown part becomes zero.

![Logic of how 4 color DNF works](https://media.geeksforgeeks.org/wp-content/uploads/20210608175013/logicof4colordnf.jpg)

### Algorithm:

1.  Initially, Low := 1; Mid_1 := 1; Mid_2 := Size; High := Size;
2.  while Mid_1 <= Mid_2 do
    1.  case arr[Mid_1] in
        -   0: swap arr[Mid_1] and arr[Low]. Mid_1++, Low++
        -   1: Mid_1++
        -   2: swap arr[Mid_1] and arr[Mid_2]. Mid_2--,
        -   3: swap arr[Mid_1] and arr[Mid_2]. swap arr[Mid_2] and arr[High]. High--, Mid_2--.

### Implementation:

C++

```cpp
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

// Code contributed by Shikhar Sahu
```

Output:
for array 1
0 , 0 , 1 , 1 , 2 , 2 , 3 ,
for array 2
0 , 0 , 0 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 3 ,

### **Complexity Analysis:**

-   **Time Complexity: O(n):**
    -   Only one traversal of the array is needed. In each iteration, the size of unknown part decreases by 1.
-   **Space Complexity: O(1):**
    -   Since no extra space is used here, This algorithm is optimal when counting sort cannot be 