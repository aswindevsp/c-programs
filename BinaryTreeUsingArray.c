#include <stdio.h>

int tree[100];
int currPos = -1;
int insert(int parent) {
    if(parent == -1) {
        printf("Enter the value of root node: ");
        scanf("%d", &tree[++currPos]);
        parent = tree[currPos];
    }


    int f1=0, f2=0;
    int tempLeftParent, tempRightParent;
    char temp;
    printf("Does %d have a left child? (y / n): ", parent);
    scanf("\n%c", &temp);
    if(temp == 'Y' || temp == 'y') {
        printf("Enter the node value: ");
        scanf("%d", &tree[++currPos]);
        tempLeftParent = tree[currPos];
        f1=1;
    } else {
        currPos++;
    }

    printf("Does %d have a right child? (y / n): ", parent);
    scanf("\n%c", &temp);
    if(temp == 'Y' || temp == 'y') {
        printf("Enter the node value: ");
        scanf("%d", &tree[++currPos]);
        tempRightParent = tree[currPos];
        f2=1;
    } else {
        currPos++;
    }


    if(f1 == 1) {
        insert(tempLeftParent);
    } 

    if(f2 == 1) {
        insert(tempRightParent);
    }
}
void print() {
    for(int i=0; i<=currPos; i++) {
        printf("%d ", tree[i]);
    }
}
int main() {
    insert(-1);
    print();
}