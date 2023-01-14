#include <stdio.h>
#include<stdlib.h>
struct Tree{
    int data;
    struct Tree *lc;
    struct Tree *rc;
};
struct Tree *stack1[20];
struct Tree *stack2[20];
int TOP1=0;
int TOP2=0;
void postOrderTraversal(struct Tree *root)
{
    stack1[TOP1]=NULL;
    stack2[TOP2]=NULL;
    struct Tree *ptr=root;
    stack1[++TOP1]=ptr;
    while(TOP1!=0)
    {
    //struct Tree *ptr=root;
   // TOP1--;
    //stack1[++TOP1]=ptr;
    ptr=stack1[TOP1];
    TOP1--;
    stack2[++TOP2]=ptr;
    if(ptr->lc!=NULL)
    {
        stack1[++TOP1]=ptr->lc;
    }
    if(ptr->rc!=NULL)
    {
        stack1[++TOP1]=ptr->rc;
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
void traversal(struct Tree *root)
{
    struct Tree *ptr=stack2[TOP2];
    while(TOP2!=0)
    {
        printf("%d ",ptr->data);
        TOP2--;
        ptr=stack2[TOP2];
        
    }
}
int main (void)
{
struct Tree *root=(struct Tree*)malloc(sizeof(struct Tree));
buildtree(root);
postOrderTraversal(root);
traversal(root);
return 0;
}