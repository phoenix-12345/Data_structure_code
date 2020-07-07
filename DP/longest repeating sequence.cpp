//longest repeating sequence
#include<bits/stdc++.h>
using namespace std;

void lcs(string x,string y,int m,int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<m;i++)
        dp[i][0]=0;
    for(int j=0;j<n;j++)
        dp[0][j]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1]&&i!=j)
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[m][n]<<endl;
    int i=m,j=n;
    string res;
    while(i>0&&j>0)
    {
        if(dp[i][j]==dp[i-1][j-1]+1)
        {
            res.push_back(x[i-1]);
            i--;
            j--;
        }
        else if(dp[i][j]==dp[i-1][j])
        {
            i--;
        }
        else
            j--;
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;

}

int main()
{
    string x,y;
    cin>>x;
    y=x;
    int m=x.length();
    int n=y.length();
    int ans=lcs(x,y,m,n);
    cout<<ans<<endl;
}
