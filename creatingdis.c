#include <stdio.h>
#include<stdlib.h>
struct Tree{
    int data;
    struct Tree *lc;
    struct Tree *rc;
};
void buildtree(struct Tree *ptr)
{
    struct Tree *New;
    int ch;
    printf("Enter value:\n");
    scanf("%d",&ptr->data);
    ptr->lc=NULL;
    ptr->rc=NULL;
    printf("Do you want to add left child of %d\n (1/0):",ptr->data);
    scanf("%d",&ch);
    if(ch==1)
    {
        New=(struct Tree*)malloc(sizeof(struct Tree));
        ptr->lc=New;
        buildtree(New);
    }
    printf("Do you want to add the right child of %d\n (1/0):",ptr->data);
    scanf("%d",&ch);
    if(ch==1)
    {
        New=(struct Tree*)malloc(sizeof(struct Tree));
        ptr->rc=New;
        buildtree(New);
    }
}
void display(struct Tree *ptr)
{
    if(ptr)
    {
    display(ptr->lc);
    printf("%d ",ptr->data);
    display(ptr->rc);
    }
}
int main (void)
{
struct Tree *root;
root=(struct Tree*)malloc(sizeof(struct Tree));
buildtree(root);
printf("\nThe contents of the binary tree :\n");
display(root);
return 0;
}