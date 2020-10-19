#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,temp;

    cin >> n; //input test case
    int a[n][100][100];
    vector<int> r;
    
    //Input arrays
    for(int x=0;x<n;x++)
    {
        cin >> temp;
        r.push_back(temp);
        for(int i=0;i<temp;i++)
        {
            for(int j=0;j<temp;j++)
            {
                cin >> a[x][i][j];
            }
        }
    }
    
    //Count sum
    for(int x=0;x<n;x++)
    {
        cout<<"Case #"<<x+1<<":";
        for(int j=0;j<r[x];j++)
        {
            int sum = 0;
            for(int i=0;i<r[x];i++)
            {
                sum += a[x][i][j];
            }
            cout<<" "<<sum;
        }
        cout<<"\n";
    }

    return 0;
}
