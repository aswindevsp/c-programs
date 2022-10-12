#include <stdio.h>
int main() {
	int n;
	printf("Enter array limit: ");
	scanf("%d", &n);
	
	int arr[n];
	printf("Enter array elements: ");
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	
	int key;
	printf("Enter key to be searched: ");
	scanf("%d", &key);
	
	int l=0, u=n-1, flag = 0;
	while(l <= u) {
		int  mid = (l+u)/2;
		if(arr[mid] == key) {
			printf("Key found at %d \n", mid+1);
			flag = 1;
		}
		if(key < arr[mid]){
			u = mid-1;
		} else {
			l = mid+1;
		}
	}
	
	
	if(flag == 0)
		printf("Key not found");
	return 0;
	
	
}
