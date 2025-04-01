#include <stdio.h>

#define MAX_ARRAY_SIZE 10000

void twoSum(int nums[], int nums_size, int target);
int partition(int arr[], int n);
void quick_sort(int arr[], int n);
void swap(int* a, int* b);


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
    quick_sort(nums, nums_size);

    int left = 0;
    int right = nums_size - 1;

    while (left <= right) {
        int sum = nums[left] + nums[right];
        if (sum  == target) {
            printf("(%d, %d)", left, right);
            return;
        }

        if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

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
