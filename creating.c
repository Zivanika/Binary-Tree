#include <stdio.h>
void buildtree(int t[], int index, int value)
{
    int data;
    int ch;
    t[index] = value;
    printf("\nDo you want to add Left child of %d(1/0): ", value);
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("Enter left child :");
        scanf("%d", &data);
        buildtree(t, 2 * index + 1, data);
    }
    printf("Do you want to add Right child of %d (1/0): ", value);
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("\nEnter the Right child: ");
        scanf("%d", &data);
        buildtree(t, 2 * index + 2, data);
    }
}

int main(void)
{
    int t[8]; 
    int value, i;
    for (i = 0; i < 8; i++)
    {
        t[i] = -1;
    }
    printf("Enter the value of root Node: \n");
    scanf("%d", &value);
    buildtree(t, 0, value);
    for (i = 0; i < 8; i++)
    {
        if (t[i] == -1)
            printf("- ");
        else
        {
            printf("%d ", t[i]);
        }
    }
    return 0;
}