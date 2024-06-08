#include <stdio.h>

int main() {
    int n;
    double arr[100];

    printf("Enter the number of elements (1 to 100): ");
    scanf("%d", &n);
    int i;

    for ( i = 0; i < n; ++i) {
        printf("Enter number %d: ", i + 1);
        scanf("%lf", &arr[i]);
    }

    double largest = arr[0];

    for (i = 1; i < n; ++i) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    printf("Largest element = %.2lf\n", largest);

    return 0;
}

