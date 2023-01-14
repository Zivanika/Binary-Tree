#include <stdio.h>
#include <stdlib.h>
struct Tree
{
    int data;
    struct Tree *lc;
    struct Tree *rc;
};
struct Tree *stack[20];
int TOP = 0;
void preOrderTraversal(struct Tree *root)
{
    stack[TOP] = NULL;
    struct Tree *ptr = root;
    stack[++TOP] = ptr;
    while (TOP != 0)
    {
        ptr = stack[TOP];
        TOP--;
        printf("%d ", ptr->data);
        if (ptr->rc != NULL)
        {
            stack[++TOP] = ptr->rc;
        }
        if (ptr->lc != NULL)
        {
            stack[++TOP] = ptr->lc;
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
    preOrderTraversal(root);
    return 0;
}
