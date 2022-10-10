#include <stdio.h>

int mat1[10][10], r1, c1;
int mat2[10][10], r2, c2;

int tMat1[10][10]; //triplet form
int tMat2[10][10];

void printMat(int mat[10][10], int r, int c) {
    printf("\n");
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void check(int mat[][10], int r, int c){ //Check if a give matrix could be sparcse of not
    int nzCount = 0; //Non zero elemtent count
    int zCount = 0; //Non zero elemtent count
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(mat[i][j] == 0) {
                zCount++;
            } else {
                nzCount++;
            }
        }
    }

    if(zCount < nzCount) {
        printf("Give matrix is not a sparse matrix");
        printf("Add matrix again \n");
    }
}

void addMat1() {
    printf("Enter the order of the matrix: ");
    scanf("%d %d", &r1, &c1); 

    printf("Enter matrix elements \n");
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    
    check(mat1, r1, c1);
}

void addMat2() {
    printf("Enter the order of the matrix: ");
    scanf("%d %d", &r2, &c2); 

    printf("Enter matrix elements \n");
    for(int i=0; i<r2; i++) {
        for(int j=0; j<c2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    
    check(mat2, r2, c2);
}

void findtMat1() {
    tMat1[0][0] = r1;
    tMat1[0][1] = c1;
    int count = 1;
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c1; j++) {
            if(mat1[i][j] != 0) {
                tMat1[count][0] = i;
                tMat1[count][1] = j;
                tMat1[count][2] = mat1[i][j];
                count++;
            }
        }
    }

    tMat1[0][2] = count - 1;
    printMat(tMat1, tMat1[0][2] + 1 , 3);
}

void findtMat2() {
    tMat2[0][0] = r2;
    tMat2[0][1] = c2;
    int count = 1;
    for(int i=0; i<r2; i++) {
        for(int j=0; j<c2; j++) {
            if(mat2[i][j] != 0) {
                tMat2[count][0] = i;
                tMat2[count][1] = j;
                tMat2[count][2] = mat2[i][j];
                count++;
            }
        }
    }

    tMat2[0][2] = count - 1;
    printMat(tMat2, tMat2[0][2] +1 , 3);
}

void findTranspose(int mat[][10], int r, int c) {
    printf("\n");
    int newMat[10][10];
    newMat[0][0] = mat[0][1];
    newMat[0][1] = mat[0][0];
    newMat[0][2] = mat[0][2];

    int k=1;
    for(int i=0; i<mat[0][1]; i++) {
        for(int j=1; j<=mat[0][2]; j++) {
            if(mat[j][1] == i) {
                newMat[k][0] = mat[j][1];
                newMat[k][1] = mat[j][0];
                newMat[k][2] = mat[j][2];
                k++;
            }
        }
    }

    printMat(newMat, r, c);
}

void matAdd(int mat1[][10], int mat2[][10]) {
    //mat1 and mat2 are triplet form of matrices
    int oMat[10][10];
    int r1 = mat1[0][0];
    int c1 = mat1[0][1];

    int r2 = mat2[0][0];
    int c2 = mat2[0][1];

    if(r1 != r2 || c1 != c2) {
        printf("%d\n", r1);
        printf("%d\n", r2);
        printf("%d\n", c1);
        printf("%d\n", c2);
        printf("Addition not possible\n");
        return;
    }
    
    
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c1; j++) {
            
        }
    }
    

}


int main() {

    int choice = 0;
    int sChoice = 0;
    while(1) {
        printf("\n");
        printf("1. Add matrix 1 \n");
        printf("2. Add matrix 2 \n");
        printf("3. Find triplet \n");
        printf("4. Find transpose \n");
        printf("5. Matrix addition\n");
        printf("6. Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);


        switch (choice) {
        case 1:
            addMat1();
            break;

        case 2:
            addMat2();
            break;

        case 3: //Finding and saving triplet
            printf("1. Find triplet of matrix 1 \n");
            printf("2. Find triplet of matrix 2 \n");
            printf("Enter your choice: ");
            scanf("%d", &sChoice);
            if(sChoice == 1) {
                findtMat1();
            }
            else if(sChoice == 2) {
                findtMat2();
            }
            else {
                printf("Invalid selection.");
                return 0;
            }
            
            break;

        case 4: //Only printing transpose not saving
            printf("1. Find transpose of matrix 1 \n");
            printf("2. Find transpose of matrix 2 \n");
            printf("Enter your choice: ");
            scanf("%d", &sChoice);
            if(sChoice == 1) {
                findTranspose(tMat1, tMat1[0][2] + 1, 3); 
            }
            else if(sChoice == 2){
                findTranspose(tMat2, tMat2[0][2] + 1, 3);
            } else {
                printf("Invalid selection.");
                return 0;
            }
            break;

        case 5:
            matAdd(tMat1, tMat2);
            break;

        case 6:
            return 0;
            break;

        default:
            printf("Invalid choice");
            return 0;
        }
    }


}