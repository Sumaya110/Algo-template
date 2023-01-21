#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll up[10005][25], depth[10005];
vector<ll>g[10005];

void dfs(ll src)
{
    for(auto child: g[src])
    {
        depth[child]= depth[src]+1;

        for(ll i=0; i<15; i++)
        {
            if(i==0) up[child][i]= src;
            else up[child][i]= up[ up[child][i-1] ] [ i-1];
        }
        dfs(child);
    }
}

ll lca(ll x, ll y)
{

    if(depth[x]< depth[y]) swap(x, y);

    ll k= depth[x]-depth[y]; // 1) Get same depth.

    for(ll i=0; i<15; i++)
    {
        if(k& (1<<i))
        {
            x= up[x][i];
        }
    }


    if(x==y) return x; // 2) if y was ancestor of x then now x==y


    for(ll i=0; i<15; i++)
    //for(ll i=14; i>=0; i--)
    {
        if(up[x][i]!= up[y][i])
        {
            x=up[x][i];
            y=up[y][i];
        }
    }

    return up[x][0];
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n,x,y,q;

    cin>>n;

    for(ll i=0; i<n; i++)
    {
        cin>>x;
        while(x--)
        {
            cin>>y;
            g[i].push_back(y);
        }
    }

    dfs(0LL);

    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        cout<<lca(x,y)<<endl;
    }

}
