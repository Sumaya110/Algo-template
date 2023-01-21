/// Template :
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define si(a) scanf("%d",&a)
#define si2(a,b) scanf("%d%d",&a,&b)
#define si3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sl(a) scanf("%lld",&a)
#define sl2(a,b) scanf("%lld%lld",&a,&b)
#define sl3(a,b, c) scanf("%lld%lld%lld",&a,&b,&c)
#define pfi(a) printf("%d", a)
#define pfl(a) printf("%lld", a)
#define pf(a) printf("a")
#define el printf("\n");
#define YES printf("YES\n")
#define NO printf("NO\n")
#define Yes printf("Yes\n")
#define No printf("No\n")
#define yes printf("yes\n")
#define no printf("no\n")
#define space printf(" ")
#define loop(i,a,b) for(int i=a; i<=b; i++)
#define pll pair<ll,ll>
#define pii pair<int, int>
#define sq(a) (a)*(a)
#define pb push_back
#define mk make_pair
#define sz size()
#define ff first
#define ss second
#define mem(a,val) memset(a, val, sizeof(a))
#define all(v) v.begin(), v.end()
#define all_r(v) v.rbegin(), v.rend()
#define md 1000000007
#define pi acos(-1.0)
#define inf 1000000000000
#define p(a, b, e) for(int i=b; i<=e; i++) printf("%lld ", a[i]);
#define csh printf("Case #%d: ", ++cs)
#define csc printf("Case %d: ", ++cs)
#define fast1 ios::sync_with_stdio(false);
#define fast2 cin.tie(nullptr);


/*
ll setbit(ll num,ll nth) {return num|=(1LL<<nth);}
ll clearbit(ll num,ll nth) {return num&=~(1LL<<nth);}
ll toggle(ll num,ll nth) {return num^=(1LL<<nth);}
ll check(ll num,ll nth) {return (num>>nth)&1LL;}
ll change(ll num,ll nth,ll val) {return num^=(-val^num)&(1LL<<nth);}
*/

/// template for ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


ll a[50], v[5000010], vis[5000010];
//map<ll,ll>mp;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n,k, sum;


    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>a[i];

    int half=n/2;
    int j=0;
    for(int i=0; i<(1<<half); i++)
    {
        sum=0;
        for(int j=0; j<half; j++)
        {
            if(i & (1<<j)) sum+=a[j];
        }
        v[j]=sum;
        j++;
    }

    int half2=n-half;
    int jj=0;
    for(int i=0; i<(1<<half2); i++)
    {
        sum=0;
        for(int j=0; j<half2; j++)
        {
            if(i & (1<<j)) sum+=a[half+j];
        }
       vis[jj]=sum;jj++;
    }

    sort(vis, vis+jj);

    ll ans=0;
    for(int i=0; i<j; i++)
    {
        ll x=lower_bound(vis, vis+jj, k-v[i])-vis;
        ll y=upper_bound(vis, vis+jj, k-v[i])-vis;

        if(y>x)
        ans+=y-x;
    }

    cout<<ans<<endl;
}
