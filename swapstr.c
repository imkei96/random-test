#include <stdio.h>
#include <string.h>

int main()
{
    int loop;
    char input[100];
    scanf("%d", &loop);
    fgets(input, sizeof(input), stdin);
    for(int x=0; x<loop; x++)
    {
        printf("Case #%d: ", x+1);
        fgets(input, sizeof(input), stdin);
        int length = strlen(input);
        if(input[length-1] == '\n')
            input[length-1] = NULL;
        char * token = strtok(input, " ");
        
        while( token != NULL ) {
            char word[100];
            strcpy(word, token);
            swap(word);
            token = strtok(NULL, " ");
            if (token != NULL)
                printf(" ");
        }
        if(x != loop -1)
            printf("\n");
    }
    
    return 0;
}

void swap(char word[100])
{
    int length = strlen(word);
    if(length>=4)
    {
        if(length%2 == 0)
        {
            for(int i=1; i<length/2; i++)
            {
                char temp;
                temp = word[i];
                word[i] = word[length-1-i];
                word[length-1-i] = temp;
            }
        }
        else
        {
            for(int i=1; i<(length+1)/2; i++)
            {
                char temp;
                temp = word[i];
                word[i] = word[length-1-i];
                word[length-1-i] = temp;
            }
        }
    }
    printf ("%s", word);
}
