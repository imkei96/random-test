#include <stdio.h>

//Global Variable
int len_x,len_y,start_i,start_j,end_i,end_j;
int min_count = 1000;

//Copy Map to temp, change current x,y to # to avoid backtrack
void copy_map(char map[len_x][len_y],char map_temp[len_x][len_y],int x, int y)
{
    for(int i=0;i<len_x;i++)
    {
        for(int j=0;j<len_y;j++)
        {
            if(i==x && j==y)
                map_temp[i][j] = '#';
            else
                map_temp[i][j] = map[i][j];
        }
    }
}

//Find path
int find_path(char map[len_x][len_y], int count, int x, int y)
{
    // Debug print
    // printf("%d %d %d %d\n",x,y,end_i,end_j);
    
    if(y!=end_j || x!=end_i)
    {
        //Change x,y to # , avoid going same path
        char map_temp[len_x][len_y];
        copy_map(map,map_temp,x,y);
        
        //Check Right
        if(y<len_y-1 && map[x][y+1]!='#')
            find_path(map_temp,count+1,x,y+1);
        //Check Left
        if(y>0 && map[x][y-1]!='#')
            find_path(map_temp,count+1,x,y-1);
        //Check Down
        if(x<len_x-1 && map[x+1][y]!='#')
            find_path(map_temp,count+1,x+1,y);
        //Check Up
        if(x>0 && map[x-1][y]!='#')
            find_path(map_temp,count+1,x-1,y);
    }
    else if(y==end_j && x==end_i)
    {
        if(count<min_count)
            min_count = count;
        // Debug Print
        // printf("%d\n",count);
        return count;
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
    
    printf("%d",min_count);
 
    return 0;
}
