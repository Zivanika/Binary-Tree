#include <stdio.h>
#include <stdlib.h>
struct Tree
{
    int data;
    struct Tree *lc;
    struct Tree *rc; 
};
struct Tree *stack[20];
// stack = (struct Tree *)malloc(8 * sizeof(struct Tree));
int TOP = 0;
void inOrderTraversal(struct Tree *ptr)
{
    stack[TOP] = NULL; 
    while (ptr != NULL) //Going Left  
    {
        TOP++;
        stack[TOP] = ptr;
        ptr = ptr->lc;
    }
    while (TOP != 0) //Until stack empty
    {
        ptr = stack[TOP];//popping top element from stack
        TOP--;
        printf("%d ", ptr->data);// printing current data

        if (ptr->rc != NULL)// checking for right child
        {
            ptr = ptr->rc;// going right 
            while (ptr != NULL)//going leftmost
            {
                TOP++;
                stack[TOP] = ptr;
                ptr = ptr->lc;
            }
        }
    }
}

void buildtree(struct Tree *ptr)
{
    struct Tree *New;
    int ch;
    printf("Enter value:\n");
    scanf("%d", &ptr->data);
    ptr->lc = NULL;
    ptr->rc = NULL;
    printf("Do you want to add left child of %d\n (1/0):", ptr->data);
    scanf("%d", &ch);
    if (ch == 1)
    {
        New = (struct Tree *)malloc(sizeof(struct Tree));
        ptr->lc = New;
        buildtree(New);
    }
    printf("Do you want to add the right child of %d\n (1/0):", ptr->data);
    scanf("%d", &ch);
    if (ch == 1)
    {
        New = (struct Tree *)malloc(sizeof(struct Tree));
        ptr->rc = New;
        buildtree(New);
    }
}

int main(void)
{
    struct Tree *root = (struct Tree *)malloc(sizeof(struct Tree));
    buildtree(root);
    inOrderTraversal(root);
    return 0;
}