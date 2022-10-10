#include <stdio.h>
int main() {
	int arr[100];
	int n;
	printf("Enter element limit: ");
	scanf("%d", &n);
	
	printf("Enter array elements: ");
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	
	for(int i=0; i<n/2; i++) {
		int temp = arr[i];
		arr[i] = arr[n-i-1];
		arr[n-i-1] = temp;
	} 
	
	
	for(int i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	
	printf("\n");
	
	
		
	return 0;
	
}
