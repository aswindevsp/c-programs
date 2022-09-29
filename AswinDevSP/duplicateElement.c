#include <stdio.h>

int dup[100];
int arr[100];
int n, d=0;
int check(int num) {
	for(int i=0; i<d; i++) {
		if(dup[i] == num) {
			return 1;
		}
	}
	return 0;
}
int main() {
	printf("Enter element limit: ");
	scanf("%d", &n);
	
	printf("Enter array elements: ");
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if((arr[i] == arr[j]) && (i != j)){
				if(check(arr[i]) == 0) {
					dup[d] = arr[i];
					d++;	
				} 
			}
		}
	}
	
	
	printf("Duplicate elements: ");
	for(int i=0; i<d; i++) {
		printf("%d ", dup[i]);
	}
	printf("\n");
		
	return 0;
	
}
