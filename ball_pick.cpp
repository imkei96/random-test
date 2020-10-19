#include <iostream>

using namespace std;

int main()
{
    //Deklarasi Variable
    
    //Input case
    int t;
    cin >> t;
    int length[t];
    long long int array[t][100];
    
    //Loop
    for(int x=0;x<t;x++)
    {
        cin >> length[x];
        //Scan array
        for(int i=0;i<length[x];i++)
            cin >> array[x][i];
    }
    
    //Count sum
    for(int x=0;x<t;x++)
    {
        long long int sum =0;
        
        //Loop sum tiap angka
        for(int i=0; i<length[x]; i++)
        {
            int temp=0;
            //Cari yg sama brp, simpan di temp
            if(i!=length[x]-1) //tidak boleh angka terakhir
            {
                for(int j=i+1; j<length[x]; j++)
                {
                    if(array[x][i]==array[x][j])
                        temp+=1;
                }
            }
            
            //Ubah temp ke sum
            if(temp>=2)
                sum+=(temp*(temp-1)/2);
        }
        cout <<"Case #"<<x+1<<": "<<sum<<"\n";
    }

    return 0;
}
