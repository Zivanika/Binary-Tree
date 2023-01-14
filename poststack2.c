#include <stdio.h> 
#include <stdlib.h>
#define size 4
int top1 = -1;
int top2 = -1;
struct Tree
{
    int data;
    struct Tree *lc;
    struct Tree *rc;
};
struct Tree *stack1[size];
struct Tree *stack2[size];
// stack1[top1]=NULL;
// stack2[top2]=NULL;
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
void postorder(struct Tree *root)
{
    struct Tree *ptr = root;
    stack1[++top1] = ptr;
    while (top1 != -1)
    {
        ptr = stack1[top1];
        top1--;

        stack2[++top2] = ptr;
        if (ptr->lc != NULL)
        {
            // ptr=ptr->lc;
            top1++;
            stack1[top1] = ptr->lc;
        }
       if (ptr->rc != NULL)
        {
            // ptr=ptr->rc;
            top1++;
            stack1[top1] = ptr->rc;
        }
    }
}
void traversal()
{
    struct Tree *ptr;
    while (top2 != -1)
    {
        ptr = stack2[top2];
        printf("%d ", ptr->data);
        top2--;
    }
}
int main(void)
{
    struct Tree *root = (struct Tree *)malloc(sizeof(struct Tree));
    buildtree(root);
    postorder(root);
    traversal();
    return 0;
}