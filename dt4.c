#include <stdio.h>

int main() {
    int arr[] = {12, 3, 4, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    int i;

    for ( i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("Sum of given array is %d\n", sum);
    return 0;
}

