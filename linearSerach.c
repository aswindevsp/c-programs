#include <stdio.h>
int main() {

    int arr[100];
    int limit, key, i;

    printf("Enter array limit: "); //Taking array limit
    scanf("%d", &limit);

    printf("Enter %d values: \n", limit); 

    for(i=0; i<limit; i++) { //Taking array values
        scanf("%d", &arr[i]);
    }

    printf("Enter key to serach: ");
    scanf("%d", &key);

    for(int i=0; i<limit; i++) {
        if(arr[i] == key) {
            printf("Key found at position %d \n", i+1);
            return 0; 
        }
    }

    printf("Key not found in array");

}



// OUTPUT
// Enter array limit: 5
// Enter 5 values: 
// 32 3 2 1 2
// Enter key to serach: 2
// Key found at position 3 