// 快速排序(从小到大)
/**
 * @file
 * @brief Quick sort algorithm
 *
 * Implementation Details -
 *      Quick Sort is a divide and conquer algorithm. It picks and element as
 *      pivot and partition the given array around the picked pivot. There
 *      are many different versions of quickSort that pick pivot in different
 *      ways.
 *
 *      1. Always pick the first element as pivot
 *      2. Always pick the last element as pivot (implemented below)
 *      3. Pick a random element as pivot
 *      4. Pick median as pivot
 *
 *      The key process in quickSort is partition(). Target of partition is,
 *      given an array and an element x(say) of array as pivot, put x at it's
 *      correct position in sorted array and put all smaller elements (samller
 *      than x) before x, and put all greater elements (greater than x) after
 *      x. All this should be done in linear time
 *
 */

#include <cstdlib>
#include <iostream>

namespace sorting {
/**
 *      This function takes last element as pivot, places
 *      the pivot element at its correct position in sorted
 *      array, and places all smaller (smaller than pivot)
 *      to left of pivot and all greater elements to right
 *      of pivot
 *       
 *      以最后一个元素为主元，将主元放在排好序的数组中正确的位置，
 *      并将所有小于主元的元素放在主元的左边，所有大于主元的元素放在主元的右边，
 *      再利用递归，分别处理主元左边和右边的数组。
 */

// 以初始数组的最后一个元素为主元，返回处理之后主元的下标
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // taking the last element as pivot
    int i = (low - 1);      // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) { // 找到小于等于主元的元素
            i++;  // increment index of smaller element
            int temp = arr[i];  // swap(arr[i], arr[j])
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // 循环结束之后, [0, i]的元素均小于等于pivot, [i+1, high-1]的元素均大于pivot, arr[high]为主元pivot
    // 最后将pivot放置到中间位置
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

/**
 *      The main function that implements QuickSort
 *      arr[] --> Array to be sorted,
 *      low --> Starting index,
 *      high --> Ending index
 *      采用递归的方法实现
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high); // p为主元的下标
        quickSort(arr, low, p - 1);        // 处理主元的左边部分
        quickSort(arr, p + 1, high);       // 处理主元的右边部分
    }
}

}  // namespace sorting

using sorting::quickSort;

// prints the array after sorting
void show(int arr[], int size) {
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
}

/** Driver program to test above functions */
int main() {
    int size;
    std::cout << "\nEnter the number of elements : ";

    std::cin >> size;

    int *arr = new int[size];

    std::cout << "\nEnter the unsorted elements : ";

    for (int i = 0; i < size; ++i) {
        std::cout << "\n";
        std::cin >> arr[i];
    }
    quickSort(arr, 0, size-1);
    std::cout << "Sorted array\n";
    show(arr, size);
    delete[] arr;
    return 0;
}
