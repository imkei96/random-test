#include <stdio.h>

int main()
{
    // variable declaration
    int n, x, countx;
    int i, j, a;
    int input[10], factor[20], prime[20];
    
    // input banyak angka
    printf("Insert number: ");
    scanf("%d", &n);
    
    // loop besar masukan
    for(i=0; i<n; i++)
    {
        printf("\nMasukan number ke %d:", i+1);
        scanf("%d",&input[i]);
    }
    
    // loop hitung faktor seluruh data
    for(a=0; a<n; a++)
    {
        // reset faktor
        for(i=0;i<20;i++)
        {
            prime[i]=0;
            factor[i]=0;
        }
        
        // mulai loop cari seluruh faktor
        x = input[a];
        j = 0;
        while (x != 1)
        {
            for (int i=2; i<=x; i++)
            {
                if ( x % i == 0)
                {
                    x = x/i;
                    factor[j] = i;
                    j++;
                    break;
                }
            }
        }
        
        
        // buat faktor prima nya saja dari vektor sebelumnya
        int z = 0;
        for (i = 0; i<j; i++) // dari semua factor
        {
            printf("Now Checking %d .. ", factor[i]);
            int found = 0;
            for(int k=0;k<j; k++) // cek seluruh prima
            {
                if (prime[k] == factor[i]) // kalau tidak ada, tambah
                {
                    printf("Found %d\n", factor[i]);
                    found ++;
                }
                if (found == 0)
                {
                    printf("Not Found %d, add!\n", factor[i]);
                    prime[z] = factor[i];
                    z++;
                    break;
                }
            }
            for(int b=0;b<20;b++)
            {
                if(prime[b]!=0)
                    printf("%d ",prime[b]);
            }
        }
        
        
        //print factor
        printf("\nFACTOR: ");
        for(i=0;i<20;i++)
            if(factor[i] !=0)
                printf("%d ",factor[i]);
        
        //print prime
        printf("\nPRIME: ");
        for(i=0;i<20;i++)
            if(prime[i] != 0)
                printf("%d ",prime[i]);
        
        // print vektor prima serta banyak kemunculannya di vektor faktor seluruh
        printf("\nFaktor dari %d: ", input[a]);
        for (i=0;i<j;i++)
        {
            int count = 0;
            if (i != 0 && prime[i] != 0)
                printf(" * ");
            if (prime[i] == 0)
                break;
            printf("%d",prime[i]);
            
            for (int k=0; k<j; k++)
            {
                if (factor[k] == prime[i])
                count++;
            }
            if (count>1)
            {
                printf("^%d",count);
            }
        }
        printf("\n");
    }
    printf("\nDone");
    
    return 0;
}
