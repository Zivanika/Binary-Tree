//wrong code
#include <stdio.h>
#include <stdlib.h>
struct Tree
{
    int data;
    struct Tree *lc;
    struct Tree *rc;
};
struct Tree *stack[20];
//stack = (struct Tree *)malloc(8 * sizeof(struct Tree));
int TOP = 0;
void preOrderTraversal(struct Tree *ptr)
{
    while(TOP!=-1)
    {
        printf("%d ",ptr->data);
        TOP++;
        stack[TOP]=ptr;
        TOP--;
        if(ptr->rc!=NULL)
        {
            TOP++;
            stack[TOP]=ptr->rc;
        }
        else{
            TOP--;
            ptr=stack[TOP];
        }
        if(ptr->lc!=NULL)
        {
            //TOP++;
            //stack[TOP]=ptr->lc;
            ptr=ptr->lc;
           // if(ptr->rc!=NULL)
            //{
              //  TOP++;
               // stack[TOP]=ptr->rc;
           // }
            //if(ptr->lc!=NULL)
            //{
               // TOP++;
                //stack[TOP]=ptr->lc;
                

           // }

        }
        else
        {
            TOP--;
            ptr=stack[TOP];
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