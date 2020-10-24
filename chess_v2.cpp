#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //Deklarasi Variable
    
    //Input case
    int n, pawn;
    cin >> n >> pawn;
    int board[n][n];
    
    
    //Makes Board 0
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            board[i][j]=0;
    }
    
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
            
        // Check UpLeft
        int qxl = qx;
        int qyl = qy;
        while(qxl>=0 && qyl>=0)
        {
            if(board[qxl][qyl] == 1 && qxl!= qx && qyl!=qy)
            {
                count_bishop++;
                qxl=0;
                qyl=0;
            }
            qxl--;
            qyl--;
        }

        // Check UpRight
        qxl = qx;
        qyl = qy;
        while(qxl< n && qyl >=0)
        {
            if(board[qxl][qyl] == 1 && qxl!= qx && qyl!=qy)
            {
                count_bishop++;
                qxl=n-1;
                qyl=0;
            }
            qxl++;
            qyl--;
        }

        // Check DownLeft
        qxl = qx;
        qyl = qy;
        while(qxl>=0 && qyl < n)
        {
            if(board[qxl][qyl] == 1 && qxl!= qx && qyl!=qy)
            {
                count_bishop++;
                qxl=0;
                qyl=n-1;
            }
            qxl--;
            qyl++;
        }

        // Check DownRight
        qxl = qx;
        qyl = qy;
        while(qxl< n && qyl < n)
        {
            if(board[qxl][qyl] == 1 && qxl!= qx && qyl!=qy)
            {
                count_bishop++;
                qxl=n-1;
                qyl=n-1;
            }
            qxl++;
            qyl++;
        }
        
        //Check Rook
        int count_rook=0;
        //Check Top
        qxl = qx;
        qyl = qy;
        while(qxl>=0)
        {
            if(board[qxl][qy] == 1 && qxl!=qx)
            {
                count_rook++;
                qxl=0;
            }
            qxl--;
        }
        
        //Check Down
        qxl = qx;
        qyl = qy;
        while(qxl<n)
        {
            if(board[qxl][qy] == 1 && qxl!=qx)
            {
                count_rook++;
                qxl=n-1;
            }
            qxl++;
        }
        
        //Check Left 
        qxl = qx;
        qyl = qy;
        while(qyl>=0)
        {
            if(board[qx][qyl] == 1 && qyl!=qy)
            {
                count_rook++;
                qyl=0;
            }
            qyl--;
        }
        
        //Check Right
        qxl = qx;
        qyl = qy;
        while(qyl<n)
        {
            if(board[qx][qyl] == 1 && qyl!=qy)
            {
                count_rook++;
                qyl=n-1;
            }
            qyl++;
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
