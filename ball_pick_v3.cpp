#include <iostream>
#include <vector>

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
        // Input Length Array
        cin >> length;
        vector<int> array_prime;
        vector<int> count;
        
        int length_prime=0;
        long long int sum =0;
        
        // Scan setiap input
        for(int i=0;i<length;i++)
        {
            int input;
            int found = 0;
            cin >> input;
            
            // Jika input pertama, tambahkan ke array_prime
            if(array_prime.empty() && i==0)
            {
                array_prime.push_back(input);
                count.push_back(1);
                length_prime++;
            }
            // Cari apakah angka masukan ada di array_prime
            else for(int j=0;j<length_prime;j++)
            {
                // Jika found, tambah count
                if(input == array_prime[j])
                {
                    count[j] += 1;
                    found = 1;
                }
            }
            
            // Jika tidak found, tambahkan ke array_prime
            if (found != 1 && i!=0)
            {
                array_prime.push_back(input);
                count.push_back(1);
                length_prime++;
            }
        }
        
        // Ubah seluruh nilai count jadi sum
        for (int i=0;i<length_prime;i++)
        {
            if(count[i]>=3)
                sum += count[i]*(count[i]-1)*(count[i]-2)/6;
        }
        cout <<"Case #"<<x+1<<": "<<sum<<"\n";
    }

    return 0;
}
