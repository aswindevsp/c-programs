#include <stdio.h>
int main() {
	int mat[10][10];
	int r, c, sum =0;
	
	printf("Enter order of matrix: ");
	scanf("%d", &r);
	scanf("%d", &c);
	
	printf("Enter matrix elements: ");
	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	
	
	printf("\nArray: \n");
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(i > j) {
				mat[i][j] = 0;
			}
		}
	}
	
	printf("\nArray: \n");
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	
	
	
	
}