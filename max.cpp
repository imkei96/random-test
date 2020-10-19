#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,temp;

    cin >> n; //input test case
    int a[n][100];
    vector<int> r;
    
    //Input arrays
    for(int x=0;x<n;x++)
    {
        cin >> temp;
        r.push_back(temp);
        for(int i=0;i<temp;i++)
        {
            cin>>a[x][i];
        }
    }
    
    //Find max
    for(int x=0;x<n;x++)
    {
        cout<<"Case #"<<x+1<<": ";
        int max=0 , max2=0;
        int max_index;
        //Find max 1
        for(int i=0;i<r[x];i++)
        {
            if (a[x][i] > max)
            {
                max = a[x][i];
                max_index = i;
            }
        }
        //Find max 2
        for(int i=0;i<r[x];i++)
        {
            if (a[x][i] > max2 && a[x][i] <= max && max_index!=i)
            {
                max2 = a[x][i];
            }
        }
        cout<<max+max2<<"\n";
    }

    return 0;
}
