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
        for(i=0;i<n;i++)
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
        
        int z = 0;
        // buat faktor prima nya saja dari vektor sebelumnya
        for (i = 0; i<j; i++) // dari semua factor
        {
            int found = 0;
            for(int k=0;k<j; k++) // cek seluruh prima
            {
                if (prime[k] == factor[i]) // kalau tidak ada, tambah
                {
                    found = 1;
                }
                if (found < 1)
                {
                    prime[z] = factor[i];
                    z++;
                    break;
                }
            }
        }
        
        // print vektor prima serta banyak kemunculannya di vektor faktor seluruh
        printf("Faktor dari %d: ", input[a]);
        for (i=0;i<j;i++)
        {
            printf("%d ",prime[i]);
            int count=0;
            for (int k=0; k<j; k++)
            {
                if (factor[k] = prime[i])
                count++;
            }
            if (count>1)
            {
                printf("^%d",count);
            }
            if (j != i-1)
                printf(" * ");
        }
        printf("\n");
    }
    printf("\nDone");
    
    return 0;
}
