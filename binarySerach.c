#include <stdio.h>
int main() {
    int arr[5] = {1,22,25,26,33};
    int key = 33;

    int start = 0;
    int end = sizeof(arr)/sizeof(arr[0]);

    int mid;
    while(end != start) {
        mid = (start + end) / 2; 
        if(arr[mid] == key) {
            printf("Key found at %d \n", mid);
            return 0;
        }

        if(key < arr[mid]) {
            end = mid;
        } else  {
            start = mid;
        }
    }
}