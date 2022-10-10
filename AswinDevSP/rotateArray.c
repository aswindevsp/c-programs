#include <stdio.h>
int main() {
	int arr[100];
	int n, rot;
	printf("Enter element limit: ");
	scanf("%d", &n);
	
	printf("Enter array elements: ");
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	
	printf("Enter no of rotations: ");
	scanf("%d", &rot);
	
	rot = (rot % n) -1;
	
	for(int i = n-rot-1; i<n; i++) {
		printf("%d ", arr[i]);	
	} 
	
	for(int i=0; i<n-rot-1; i++) {
		printf("%d ", arr[i]);
	}
		
	return 0;
	
}



/*
#include <stdio.h>
int main() {	
	int arr[4] = {1,2,3,4};
	int n = 4;
	
	int j;
	
	for(int k=0; k<4; k++) {
	
	
	for(int i=0; i<n; i++) {
		j = n-1-i;
		int temp = arr[j];
		arr[j] = arr[j-1];
		arr[j-1] = temp;
		
	}
	
	}
	
	
	
	for(int i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
}
*/
