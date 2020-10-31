#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int input[n];
    for(int i=0;i<n;i++)
        scanf("%d", &input[i]);
    
    char chart[10][n+1];
    for(int i=9;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            if(input[j]>0)
            {
                chart[i][j]='#';
                input[j]--;
            }
            else
                chart[i][j]='*';
        }
    }
    
    for(int i=1;i<10;i++)
    {
        for(int j=0;j<n;j++)
            printf("%c",chart[i][j]);
        if(i!=9)
            printf("\n");
    }

    return 0;
}
