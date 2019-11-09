#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,smax,s,s1,x,y;
int t[1000][1000],sk[1000][1000],sw[1000][1000];
int main()
{
    cin>> n>>m;

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>t[i][j];
        }

    }
    cin>>a>>b;
    for(int i=1; i<=n; i++)
    {
        sk[1][i]=t[1][i];
    }

    for(int i=1; i<=m; i++)
    {
        sw[i][1]=t[i][1];

    }
    for(int i=2; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            sk[i][j]=sk[i-1][j]+t[i][j];

        }

    }

    for(int i=1; i<=m; i++)
    {
        for(int j=2; j<=n; j++)
        {
            sw[i][j]=sw[i][j-1]+t[i][j];

        }

    }

    for(int i=1; i<=b; i++)
    {
        s1+=sw[i][a];
    }
    for(int i=1; i<=m-b+1; i++)
    {
        s=s1;
        for(int j=1; j<=n-a+1; j++)
        {

            if(s>smax)
            {
                smax=s;
                x=i;
                y=j;
            }
            s-=(sk[i+b-1][j]-sk[i-1][j]);
            s+=(sk[i+b-1][j+a]-sk[i-1][j+a]);
        }

        s1-=sw[i][a];
        s1+=sw[i+b][a];


    }
    cout<<smax<<endl<<x<<" "<<y;
}
