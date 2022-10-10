#include <stdio.h>
int mat1[10][10];
int sMat[10+1][3];
int tMat[10+1][3];
int r,c, count=0;
int main() {
	
	
	printf("Enter the order of matrix: ");
	scanf("%d %d", &r, &c);


	
	//Taking array elements
	printf("Enter matrix elements: \n");
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++) {
			scanf("%d", &mat1[i][j]);
			if(mat1[i][j] != 0)
				count++;
		}
	}
	
	//Sparse checking
	if(count >= ((r*c)-count)) { 
		printf("Not a sparse matrix. Exiting.. \n");
		return 0;
	}
	
	//Triplet	
	printf("\n%d\n\n", r);
	sMat[0][0] = r;
	sMat[0][1] = c;
	sMat[0][2] = count;
	
	int sI=1;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++) {
			if(mat1[i][j] != 0) {
				sMat[sI][0] = i;
				sMat[sI][1] = j;
				sMat[sI][2] = mat1[i][j];
				sI++;	
			}
		}
	}
	
	printf("\n%d\n\n", sMat[0][0]);
	
	//Printing triplet
	printf("\nTriplet Form \n");
	for(int i=0; i<count+1; i++){
		for(int j=0; j<3; j++) {
			printf("%d ", sMat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	
	//Transpose
	tMat[0][1] = sMat[0][0];
	tMat[0][0] = sMat[0][1];
	tMat[0][2] = sMat[0][2];
	int k=0;
	for(int i=0;i<sMat[0][1];i++)
	{
		for(int j=1;j<=sMat[0][2];j++)
		{
			if(sMat[j][i]==i)
			{
				tMat[k][0]=sMat[j][i];
				tMat[k][1]=sMat[j][0];
				tMat[k][2]=sMat[j][2];
				k++;
			}
		}
	}
	
	//Printing transpose
	printf("Transpose form: \n");
	for(int i=0; i<count+1; i++){
		for(int j=0; j<3; j++) {
			printf("%d ", tMat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	
	
	
	
	
}
