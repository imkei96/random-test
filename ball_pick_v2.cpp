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
        cin >> length;
        
        vector<int> array;
        vector<int> array_prime;
        
        int length_prime=0;
        //Scan array
        for(int i=0;i<length;i++)
        {
            int input;
            cin >> input;
            array.push_back(input);
            
            if(array_prime.empty() && i==0)
            {
                array_prime.push_back(input);
                length_prime++;
            }
            else if(array_prime[length_prime-1] != input)
            {
                array_prime.push_back(input);
                length_prime++;
            }
        }
        long long int sum =0;
        
        //Loop sum tiap angka
        for(int i=0;i<length_prime;i++)
        {
            int count=0;
            for(int j=0;j<length;j++)
            {
                if(array_prime[i] == array[j])
                    count++;
            }
            if(count>=3)
            sum += count*(count-1)*(count-2)/6;
        }
        cout <<"Case #"<<x+1<<": "<<sum<<"\n";
    }

    return 0;
}
