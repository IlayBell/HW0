#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 10000

void twoSum(int nums[], int nums_size, int target);
int partition(int arr[], int n);
void quick_sort(int arr[], int n);
void swap(int* a, int* b);
int* arr_copy(int arr[], int n);
int find(int arr[], int n, int target);


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



void twoSum(int nums[], int nums_size, int target) {
	/* YOUR CODE HERE */
    int* nums_copy = arr_copy(nums, nums_size);
    quick_sort(nums_copy, nums_size);

    int left = 0;
    int right = nums_size - 1;

    while (left <= right) {
        int sum = nums_copy[left] + nums_copy[right];
        if (sum  == target) {
            int left_old_idx = find(nums, nums_size, nums_copy[left]);
            int right_old_idx = find(nums, nums_size, nums_copy[right]);
            printf("(%d, %d)", left_old_idx, right_old_idx);

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



void quick_sort(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    int pivot_idx = partition(arr, n);
    quick_sort(arr, pivot_idx);
    quick_sort(arr + pivot_idx + 1, n - pivot_idx - 1);
}

int partition(int arr[], int n) {
    // To improve the complexity by adding a bit of rand
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

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int* arr_copy(int arr[], int n) {
    int* copied = (int*) malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        copied[i] = arr[i];
    }
    return copied;
}

int find(int arr[], int n, int target){
    for(int i = 0; i < n; i++) {
        if (arr[i] == target){
            return i;
        }
    }

    return -1;
}
