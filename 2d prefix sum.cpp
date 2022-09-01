#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll r,c;
ll a[100][100];
void prefix_sum_2d()
{
    ll psa[r+5][c+5];

    psa[0][0] = a[0][0];

    // Filling first row and first column
    for (int i = 1; i < c; i++)
        psa[0][i] = psa[0][i - 1] + a[0][i];

    for (int i = 1; i < r; i++)
        psa[i][0] = psa[i - 1][0] + a[i][0];

    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1]- psa[i - 1][j - 1] + a[i][j];
    }



    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
            cout<<psa[i][j]<<" ";
        cout<<endl;
    }

}
int main()
{
    cin>>r>>c;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>a[i][j];
        }
    }

    prefix_sum_2d();
}

/*

4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5


*/
