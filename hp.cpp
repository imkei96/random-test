#include <vector>
#include <iostream>
#include <string>
//#include <numeric>

using namespace std;

// Main Program
int main()
{
    // Deklarasi Variable
    int length, input, count;
    int min, temp;
    vector<int> hp;
	vector<int> input_int;

    // Read Count
    cin >> count;
    
    // Loop
    for (int x = 0 ; x < count ; x++)
    {
        // Clear
        input_int.clear();
        
        // Read Banyak Angka
        cin >> length;

        // Read Line of int
        for(int i=0;i<length; i++)
        {
            cin >> input;
            input_int.push_back(input);
        }
        
        // Find Minimum HP
        min = input_int[0];
        temp = 0;
        for (int i = 0; i < length; i++)
        {
            temp += input_int[i];
            if (temp < min)
                min = temp;
        }
        
        // Masukan nilai min sebagai HP = 1 - min
        if (min > 0)
            min = 0;
        hp.push_back(1 - min);
    }
    
    //Print Result HP
    for (int x = 0 ; x < count ; x++)
    {
        cout << "Case #" << x+1 << ": " <<  hp[x] << \n;
    }
    
}
