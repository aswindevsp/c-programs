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
