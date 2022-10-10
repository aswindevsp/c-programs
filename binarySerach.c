#include <stdio.h>
int main() {

    int arr[100];
    int limit, key, i, j, start, end, mid;

    printf("Enter array limit: "); //Taking array limit
    scanf("%d", &limit);

    printf("Enter %d values: \n", limit); 

    for(i=0; i<limit; i++) { //Taking array values
        scanf("%d", &arr[i]);
    }


    for(i=0; i<limit; i++) {
        for(j=0; j<limit-i-1; j++) {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted array: \n");
    for(i=0; i<limit; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    printf("Enter key to serach: ");
    scanf("%d", &key);
 
    start = 0; //Left most index
    end = limit - 1; //Right most index

    while(end != start) {
        mid = (start + end) / 2; 
        if(arr[mid] == key) {
            printf("Key found at postion %d \n", mid+1);
            return 0;
        }

        if(key < arr[mid]) {
            end = mid;
        } else  {
            start = mid;
        }
    }

    printf("Key not found in array \n");


}

// OUTPUT
// Enter array limit: 5
// Enter 5 values: 
// 12 23 2 54 32
// Sorted array:        
// 2 12 23 32 54        
// Enter key to serach: 32
// Key found at position 4 