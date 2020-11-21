#include <stdio.h>

void create_array(int a[], int length)
{
    int center = (length-1)/2;
    for(int i=0;i<=center;i++)
    {
        if (i%2==0)
            a[i]=1;
        else
            a[i]=i+2;
    }
    for(int i=center+1;i<length;i++)
    {
        if (i%2==0)
            a[i]=1;
        else
            a[i]=(length-i)+1;
    }
}

void print_line(int x, int length)
{
    int center = (length-1)/2;
    for(int i=0; i<center-(x-1)/2;i++)
        printf(" ");
    for(int i=center-(x-1)/2;i<=center+(x-1)/2;i++)
        printf("*");
    for(int i=center+(x-1)/2+1;i<length;i++)
        printf(" ");
}

int main()
{
    int input;
    scanf("%d",&input);
    if(input==1)
    {
        printf("*");
    }
    else
    {
        int center = 2*(input-1);
        int length = 2*center - 1;
        int array[length];
        create_array(array,length);
        for(int i=0;i<length;i++)
        {
            print_line(array[i],length);
            if(i!=length-1)
                printf("\n");
        }
    }

    return 0;
}
