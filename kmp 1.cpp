#include<bits/stdc++.h>
using namespace std;
#define endl        "\n"

void lps_arr( string pat, int m, int lps[])
{
    int i=1, len=0; lps[0]=0;
    while(i<m)
    {
        if(pat[i]==pat[len])
            {len++; lps[i]=len;i++;}
        else
        {
            if(len)
             len=lps[len-1];
            else
            {
                lps[i]=0;i++;
            }
        }
    }
    //for(int i=0; i<m; i++)
        //cout<<lps[i]<<" ";
}
int kmp_search( string text, string pat)
{
    int n=text.size(), m=pat.size(), i=0,j=0;
    int lps[m+5];
    lps_arr(pat, m, lps);

    while(i<n)
    {
        if(pat[j]==text[i])
        {
            i++,j++;
            if(j==m)
            {
               //cout<<"found pattern at "<<i-j<<endl;
               j=lps[j-1];
            }
        }
        else
        {
            if(j)
              j=lps[j-1];
            else i++;
        }
    }
    //cout<<j<<endl;
    return j;
}

int main()
{
    string text, pat;
    cin>>text>>pat;

    int p= kmp_search(text, pat);
    cout<<p<<endl;
}

