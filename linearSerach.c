#include <stdio.h>
int main() {
	int arr[100];
	int n, key;
	printf("Enter element limit: ");
	scanf("%d", &n);
	
	printf("Enter array elements: ");
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	
	printf("Enter key: ");
	scanf("%d", &key);
	
	for(int i=0; i<n; i++) {
		if(key == arr[i]) {
			printf("Key found in array index %d\n", i);
			return 0;
		}
	}
	
	printf("Key not found in array.");
	
	return 0;
	
}
