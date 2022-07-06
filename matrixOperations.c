#include <stdio.h>
#define ROWS 10
#define COLS 10
int matrix1[ROWS][COLS], r1, c1;
int matrix2[ROWS][COLS], r2, c2;
int out[ROWS][COLS];

void matrixPrint(int matrix[ROWS][COLS], int r, int c){
    printf("\n");
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void matrixRead() {
    printf("Enter first matrix column and row: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter matrix elements: ");
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter second matrix column and row: ");
    scanf("%d%d", &r2, &c2);
    printf("Enter matrix elements: ");
    for(int i=0; i<r2; i++) {
        for(int j=0; j<c2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("Matrix 1: \n");
    matrixPrint(matrix1, r1, c1);
    printf("Matrix 2: \n");
    matrixPrint(matrix2, r2, c2);
    
}

void matrixSum(){
    matrixRead();

    if((r1 != r2) || (c1 != c2)) {
        printf("Order of matrices doesn't match, exiting..");
        return;
    }

    for(int i=0; i<r1; i++) {
        for(int j=0; j<c1; j++) {
            out[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("Sum of two matrices: \n");
    matrixPrint(out, r1, c1);

}
void matrixMuliplication() {
    matrixRead();
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            out[i][j]=0;
            for(int k=0; k<c1; k++) {
                out[i][j] += matrix1[i][k] * matrix2[k][j];
            } 
        }
    }
    printf("Product of two matrices: \n");
    matrixPrint(out, r1, c2);
}
void matrixTranspose(){
    int matrix[ROWS][COLS], r, c;
    printf("Enter order of matrix: ");
    scanf("%d %d", &r, &c);
    printf("Enter matrix elements: \n");
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int x=0, y=0;
    for(int i=0; i<c; i++) {
        y=0;
        for(int j=0; j<r; j++) {
            out[x][y]=matrix[j][i];
            y++;
        }
        x++;
    }
    printf("\nMatrix transpose: \n");
    matrixPrint(out, c, r);
    
}
int main() {
    int choice;
    printf("1. Sum of two matrix \n");
    printf("2. Product of two matrix \n");
    printf("3. Transpose of a matrix \n");
    printf("Enter a choice: ");
    scanf("%d", &choice);

    if(choice == 1) 
        matrixSum();
    else if(choice == 2)
        matrixMuliplication();
    else if(choice == 3)
        matrixTranspose();
    
    return 0;
}