#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 10000

void twoSum(int nums[], int nums_size, int target);
int partition(int arr[], int n);
void quick_sort(int arr[], int n);
void swap(int* a, int* b);
int* arr_copy(int arr[], int n);
int find_l(int arr[], int n, int target);
int find_r(int arr[], int n, int target);


int main() {
	int target;
	int nums[MAX_ARRAY_SIZE] = {0};
	int array_size = 0;

	scanf("%d", &target);

	while (scanf("%d", &nums[array_size++]) == 1);
	array_size--;

	twoSum(nums, array_size, target);

	return (0);
}


/**
 * @brief Finds the indices of the pair that sums up to target
 * @param nums - Array of given numbers
 * @param nums_size
 * @param target - The desired number
 * @return None
 */
void twoSum(int nums[], int nums_size, int target) {
	/* YOUR CODE HERE */
    int* nums_copy = arr_copy(nums, nums_size);
    quick_sort(nums_copy, nums_size);

    int left = 0;
    int right = nums_size - 1;

    while (left <= right) {
        int sum = nums_copy[left] + nums_copy[right];

        /* If a pair is found, then find the indices at the original order */
        if (sum  == target) {
            int left_old = find_l(nums, nums_size, nums_copy[left]);
            int right_old = find_r(nums, nums_size, nums_copy[right]);
            printf("(%d, %d)", left_old, right_old);

            free(nums_copy);
            return;
        }

        if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    free(nums_copy);
}

/**
 * @brief Basic quicksort algorithm
 * @param arr - Array desired to be sorted
 * @param n - Array length
 * @return None
 */
void quick_sort(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    int pivot_idx = partition(arr, n);
    quick_sort(arr, pivot_idx);
    quick_sort(arr + pivot_idx + 1, n - pivot_idx - 1);
}

/**
 * @brief Basic partition function for quicksort
 * @param arr - Array desired to be sorted
 * @param n - Array length
 * @return pivot index
 */
int partition(int arr[], int n) {
    /* To improve the complexity by adding a bit of rand */
    swap(arr, arr + (n/2));

    int pivot = arr[0];
    int left = 1;
    int right = n-1;

    while (right >= left) {
        if (arr[left] < pivot) {
            left++;
        }

        else if (arr[right] >= pivot) {
            right--;
        }

        else {
            swap(arr + left, arr + right);
            left++;
            right--;
        }
    }

    swap(arr, arr + right);

    return right;
}

/**
 * @brief Swaps two elements
 * @param a - Pointer to the first element
 * @param b - Pointer to the second element
 * @return None
 */
void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

/**
 * @brief Copies an array
 * @param arr - Array desired to be copied
 * @param n - Array length
 * @return A pointer to the head of the copy
 */
int* arr_copy(int arr[], int n) {
    int* copied = (int*) malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        copied[i] = arr[i];
    }
    return copied;
}

/**
 * @brief Finds the index of the given target, searches from left.
 * @param arr - Array desired to be searched
 * @param n - Array length
 * @param target - The desired number
 * @return The desired index
 */
int find_l(int arr[], int n, int target){
    for(int i = 0; i < n; i++) {
        if (arr[i] == target){
            return i;
        }
    }

    return -1;
}

/**
 * @brief Finds the index of the given target, searches from right.
 * @param arr - Array desired to be searched
 * @param n - Array length
 * @param target - The desired number
 * @return The desired index
 */
int find_r(int arr[], int n, int target){
    for(int i = n-1; i >= 0; i--) {
        if (arr[i] == target){
            return i;
        }
    }

    return -1;
}
