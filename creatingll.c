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
        buildtree(ptr->lc);
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
void inOrderTraversal(struct Tree *ptr)
{
    if(ptr)
    {
     inOrderTraversal(ptr->lc);
    printf("%d ",ptr->data);
    inOrderTraversal(ptr->rc);
    }
}

void preOrderTraversal(struct Tree *ptr)
{
    if(ptr)
    {
        printf("%d ",ptr->data);
        preOrderTraversal(ptr->lc);
        preOrderTraversal(ptr->rc);
    }
}
void postOrderTraversal(struct Tree *ptr)
{
    if(ptr)
    {
        postOrderTraversal(ptr->lc);
        postOrderTraversal(ptr->rc);
        printf("%d ",ptr->data);
    }
}
int main (void)
{
struct Tree *root;
root=(struct Tree*)malloc(sizeof(struct Tree));
buildtree(root);
printf("\nInorder Traversal:\n");
inOrderTraversal(root);
printf("\nPreorder Traversal:\n");
preOrderTraversal(root);
printf("\nPostorder Traversal:\n");
postOrderTraversal(root);
return 0;
}