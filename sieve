bool vis[10000005];
vector<ll>prime;
void sieve()
{
    vis[0]=vis[1]=1;
    for(int i=2; i<=10000000;
            i++)
    {
        if(vis[i]==0)
        {
            prime.push_back(i);
            for(int j=i*2; j<=10000000; j+=i) vis[j]=1;
        }
    }
}
