#include <stdio.h>
int sum(int *ptr, int n) {
    int out = 0;
    for(int i=0; i<n; i++) {
        out += *(ptr+i); 
    }
    return out;
}
int main() {

    int arr[100], n;
    int *ptr = arr;
    printf("Enter array limit: ");
    scanf("%d", &n);
    printf("Enter array elements: ");

    for(int i=0; i<n; i++) { //Taking input
        scanf("%d", &arr[i]);
    }


    printf("Sum of elements: %d \n", sum(ptr, n));

}