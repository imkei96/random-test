#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //Deklarasi Variable
    
    //Input case
    int n, pawn;
    cin >> n >> pawn;
    int board[n][n] = {0};
    
    //Input posisi pion
    for(int i=0; i<pawn;i++)
    {
        int x,y;
        cin >> x >> y;
        board[x-1][y-1] = 1;
    }
    
    //Input Loop KBR
    int q;
    cin >> q;
    for(int x=0; x<q; x++)
    {
        //Input x,y
        int qx, qy;
        cin >> qx >> qy;
        qx--;
        qy--;
        
        // Check knight
        int count_knight=0;
        //BotLeft
        if(qx-2>=0 && qy-1>=0)
        {
            if(board[qx-2][qy-1]==1)
                count_knight++;
        }
        if(qx-1>=0 && qy-2>=0)
        {
            if(board[qx-1][qy-2]==1)
                count_knight++;
        }
        //TopLeft
        if(qx-2>=0 && qy+1<n)
        {
            if(board[qx-2][qy+1]==1)
                count_knight++;
        }
        if(qx-1>=0 && qy+2<n)
        {
            if(board[qx-1][qy+2]==1)
                count_knight++;
        }
        //BotRight
        if(qx+2<n && qy-1>=0)
        {
            if(board[qx+2][qy-1]==1)
                count_knight++;
        }
        if(qx+1<n && qy-2>=0)
        {
            if(board[qx+1][qy-2]==1)
                count_knight++;
        }
        //TopRight
        if(qx+2<n && qy+1<n)
        {
            if(board[qx+2][qy+1]==1)
                count_knight++;
        }
        if(qx+1<n && qy+2<n)
        {
            if(board[qx+1][qy+2]==1)
                count_knight++;
        }
        
        //Check Bishop
        int count_bishop=0;
        int dif = qx-qy;
        if (dif < 0)
            dif = 0-dif;
            
        // Check TopLeft -> BottomRight
        for(int i=0;i<n-dif;i++)
        {
            if(qx>qy)
            {
                if(board[i+qx-qy][i] == 1)
                    count_bishop++;
            }
            if(qx<qy)
            {
                if(board[i][i-qx+qy] == 1)
                    count_bishop++;
            }
            if(dif == 0)
            {
                if(board[i][i] == 1)
                    count_bishop++;
            }
        }
        
        // Check TopRight -> BottomLeft
        for(int i=0;i<n-dif;i++)
        {
            if(qx>qy)
            {
                if(board[i+qx-qy][n-i-1] == 1)
                    count_bishop++;
            }
            if(qx<qy)
            {
                if(board[i][n-i+qx-qy-1] == 1)
                    count_bishop++;
            }
            if(dif == 0)
            {
                if(board[i][n-i-1] == 1)
                    count_bishop++;
            }
        }
        
        //Check Rook
        int count_rook=0;
        //Check Row 
        for(int i=0;i<n;i++)
        {
            if(board[i][qy] == 1 && i!=qx)
                count_rook++;
        }
        //Check Column
        for(int i=0;i<n;i++)
        {
            if(board[qx][i] == 1 && i!=qy)
                count_rook++;
        }
        
        //Pilih yg mana 
        int max = count_knight;
        int choice = 1;
        
        if(count_bishop>max)
        {
            max = count_bishop;
            choice=2;
        }
        if(count_rook>max)
        {
            max = count_rook;
            choice=3;
        }
        
        cout << choice << "\n";
        ///untuk print setiap count (debug)
        ///cout << count_knight << count_bishop <<count_rook << "\n";
    }

    return 0;
}
