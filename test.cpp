// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // variable declaration
    int input, countx, a;
    vector<int> x, factor, prime;
    
    // input banyak angka
    //cout << "Insert number: ";
    cin >> input;
    
    // input angka
    for(int i=0; i<input; i++)
    {
        //cout << "Insert number " << i+1 << ":";
        cin >> a;
        x.push_back(a);
    }
    
    int n = 0;
    // loop tiap input
    for (auto j = x.begin(); j!= x.end(); j++)
    {
        // ambil variable angka
        int z = *j;
        factor.clear();
        prime.clear();
        n++;
        
        // mulai loop cari seluruh faktor
        while (z != 1)
        {
            for (int i=2; i<=z; i++)
            {
                if ( z % i == 0)
                {
                    z = z/i;
                    factor.push_back(i);
                    break;
                }
            }
        }
        
        // buat faktor prima nya saja dari vektor sebelumnya
        for (auto i = factor.begin(); i != factor.end(); ++i) 
        {
            // jika belum ada di vektor prima, tambahkan
            if ( count(prime.begin(), prime.end(), *i) == 0)
            {
                prime.push_back(*i);
            }
        }
        
        // print vektor prima serta banyak kemunculannya di vektor faktor seluruh
        cout << "Case #" << n << ": ";
        for (auto i = prime.begin(); i!= prime.end(); ++i)
        {
            countx = count(factor.begin(), factor.end(), *i); //brp banyak faktor nya
            cout << *i;
            cout << " ^ " << countx;
            if (*i != prime.back()) // jika plg terakhir, tdk usah print * lagi
                cout << " * ";
            
        }
        cout << "\n";
    }
    //cout << "\nDone";
    
    return 0;
}
