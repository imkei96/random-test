// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // variable declaration
    int input, x, countx;
    vector<int> factor, prime;
    
    // input angka
    cout << "Insert number: ";
    cin >> input;
    x = input;
    
    // cek jika input valid (lebih besar dari 1), ini opsional 
    if (input <= 1)
    {
        cout << "Input Invalid!";
        return 0;
    }
    else
    {
        cout << "Input Valid: " << input << "\n";
    }
    
    // mulai loop cari seluruh faktor
    while (x != 1)
    {
        for (int i=2; i<=x; i++)
        {
            if ( x % i == 0)
            {
                x = x/i;
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
    cout << "Faktor : ";
    for (auto i = prime.begin(); i!= prime.end(); ++i)
    {
        countx = count(factor.begin(), factor.end(), *i); //brp banyak faktor nya
        cout << *i;
        if (countx > 1) // jika lebih dari 1, pakai pangkat
            cout << "^" << countx;
        if (*i != prime.back()) // jika plg terakhir, tdk usah print * lagi
            cout << " * ";
        
    }
    cout << "\nDone";
    
    return 0;
}
