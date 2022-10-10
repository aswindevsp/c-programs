#include <stdio.h>
#define size 4
int Top = -1, inp_array[size];
void Push();
void Pop();
void show();

int main() {
    int choice;

    while(1){
        printf("\nOperations perfomed by Stack");
        printf("\n1.Push the elements\n2.Pop the elments\n3.Show\n4.End");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1: Push();
                        break;
            case 2: Pop();
                        break;
            case 3: show();
                        break;
            default: printf("Invalid selection");
        }

    }


}
