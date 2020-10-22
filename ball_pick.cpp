#include <iostream>

using namespace std;

int main()
{
    //Deklarasi Variable
    
    //Input case
    int t;
    cin >> t;
    long long int length;
    
    //Loop
    for(int x=0;x<t;x++)
    {
        cin >> length;
        
        int array[length];
        
        //Scan array
        for(int i=0;i<length;i++)
            cin >> array[i];

        long long int sum =0;
        
        //Loop sum tiap angka
        for(int i=0; i<length; i++)
        {
            int temp=0;
            //Cari yg sama brp, simpan di temp
            if(i!=length-1) //tidak boleh angka terakhir
            {
                for(int j=i+1; j<length; j++)
                {
                    if(array[i]==array[j])
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
