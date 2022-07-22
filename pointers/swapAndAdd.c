#include <stdio.h>
void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int sum(int *p1, int *p2) {
    return(*p1 + *p2);
}
int main() {

    int a, b;
    int *ptr1 = &a, *ptr2 = &b;

    printf("Enter two number: ");
    scanf("%d %d", &a, &b);

    printf("\nA = %d  ", a);
    printf("B = %d\n", b);

    printf("Sum = %d \n", sum(ptr1, ptr2));

    swap(ptr1, ptr2);

    printf("After Swapping: \n");
    printf("A = %d  ", a);
    printf("B = %d \n", b);
}