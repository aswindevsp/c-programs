#include <stdio.h>
int main() {

    int arr[100], n;
    int *ptr = arr;
    printf("Enter array limit: ");
    scanf("%d", &n);
    printf("Enter array elements: ");

    for(int i=0; i<n; i++) { //Taking input
        scanf("%d",(ptr+i));
    }

    printf("Array elements: ");
    for(int i=0; i<n; i++) { //Taking input
        printf("%d ",*(ptr+i));
    }

    printf("\n");
    
    return 0;
}