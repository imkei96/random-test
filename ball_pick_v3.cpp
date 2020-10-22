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
        long long int sum =0;
        int count =0 ;
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
                count=0;
            }
            else if(array_prime[length_prime-1] == input)
            {
                count++;   
            }
            
            if(count>=2)
                sum += count*(count-1)/2;
        }

        cout <<"Case #"<<x+1<<": "<<sum<<"\n";
    }

    return 0;
}
