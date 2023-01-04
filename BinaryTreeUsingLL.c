#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;



void insert(struct node **node)
{
    struct node *newNode = *node;

    int temp = 'n';

    if (root == NULL)
    {
        root = newNode;
        printf("Enter the root node: ");
        scanf("%d", &newNode->data);
    }
    

    printf("Does %d have a left chlid? ", newNode->data);

    int f1=0, f2=0;

    scanf("\n%c", &temp);
    if (temp == 'y')
    {
        struct node *newNewNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value of left node: ");
        scanf("%d", &newNewNode->data);

        newNode->left = newNewNode;
        f1 = 1;
    }
    else
    {
        newNode->left = NULL;
    }

    temp = 'n';

    printf("Does %d have a right chlid? ", newNode->data);
    scanf("\n%c", &temp);
    if (temp == 'y')
    {
        struct node *newNewNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value of right node: ");
        scanf("%d", &newNewNode->data);

        newNode->right = newNewNode;
        f2 = 1;
    }
    else
    {
        newNode->right = NULL;
    }


    if(f1 == 1) {
        insert(&newNode->left);
    } 

    if(f2 == 1) {
        insert(&newNode->right);
    }
}



void inOrder(struct node **node)
{
    if ((*node)->left != NULL)
        inOrder(&(*node)->left);
    printf("%d ", (*node)->data);
    if ((*node)->right != NULL)
        inOrder(&(*node)->right);
}

void preOrder(struct node **node)
{
    printf("%d ", (*node)->data);
    if ((*node)->left != NULL)
        inOrder(&(*node)->left);
    if ((*node)->right != NULL)
        inOrder(&(*node)->right);
}

void postOrder(struct node **node)
{
    if ((*node)->left != NULL)
        inOrder(&(*node)->left);
    if ((*node)->right != NULL)
        inOrder(&(*node)->right);
    printf("%d ", (*node)->data);
     
}

int main()
{
    int choice;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;

    while (1)
    {
        printf("1. Insert node \n");
        printf("2. Traversal\n");
        printf("Choice: ");
    
        scanf("%d", &choice);

        if (choice == 1)
        {
            insert(&newNode);
        }
        else if (choice == 2)
        {
            printf("\n");
            printf("1. PreOrder Traversal\n");
            printf("2. InOrder Traversal\n");
            printf("3. PostOrder Traversal\n");
            printf("Choice: ");
            scanf("%d", &choice);
            
            
            if (choice == 1)
            {
                preOrder(&root);
                printf("\n");
            }
            else if (choice == 2)
            {
                inOrder(&root);
                printf("\n");
            }
            else if (choice == 3)
            {
                postOrder(&root);
                printf("\n");
            }
        }
    }
}