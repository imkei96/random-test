#include <iostream>

using namespace std;

int main()
{
    //Deklarasi Variable
    
    //Input case
    int x, y;
    cin >> x >> y;
    int board[x][y];
    
    
    //Input Board XxY
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
            cin >> board[i][j];
    }
    
    //Input Changes
    int t;
    cin >> t;
    
    for(int a=0;a<t;a++)
    {
        int tx, ty, c;
        cin >> tx >> ty >> c;
        board[tx-1][ty-1] = c;
    }
    
    //Print Board
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
            cout << board[i][j] << " ";
        cout <<"\n";
    }

    return 0;
}
