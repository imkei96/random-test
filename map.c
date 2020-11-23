#include <stdio.h>

//Global Variable
int len_x,len_y,start_i,start_j,end_i,end_j;
int min_count=1000;

int find_path(char map[len_x][len_y], int count, int x, int y)
{
    printf("%d %d %d %d",x,y,end_i,end_j);
    if(x==end_i && y==end_j)
    {
        if(count<min_count)
            min_count=count;
        printf("%d",count);
        return count;
    }
    else
    {
        //Check Left
        if(x!=0)
        {
            if(map[x-1][y] == '*')
            {
                printf("%c",map[x][y]);
                count++;
                map[x][y]='#';
                find_path(map,count,x-1,y);
            }
        }
        //Check Right
        else if(x!=len_x-1)
        {
            if(map[x+1][y] == '*')
            {
                printf("%c",map[x][y]);
                count++;
                map[x][y]='#';
                find_path(map,count,x+1,y);
            }
        }
        //Check Up
        else if(y!=0)
        {
            if(map[x][y-1] == '*')
            {
                printf("%c",map[x][y]);
                count++;
                map[x][y]='#';
                find_path(map,count,x,y-1);
            }
        }
        //Check Down
        else if(y!=len_y-1)
        {
            if(map[x][y+1] == '*')
            {
                printf("%c",map[x][y]);
                count++;
                map[x][y]='#';
                find_path(map,count,x,y+1);
            }
        }
    }
    
}



int main()
{
    scanf("%d",&len_x);
    scanf("%d",&len_y);
    
    char map[len_x][len_y];
    
    //Scan Map
    for(int i=0;i<len_x;i++)
    {
        for(int j=0;j<len_y;j++)
        {
            scanf(" %c\n",&map[i][j]);
            if(map[i][j] == 'S')
            {
                start_i = i;
                start_j = j;
            }
            if(map[i][j] == 'E')
            {
                end_i = i;
                end_j = j;
            }
        }
    }
    
    // Find Path
    int count = 0;
    count = find_path(map,0,start_i,start_j);
    
    printf("\n%d %d",count,min_count);
 
    return 0;
}
