#include<bits/stdc++.h>
using namespace std;
/*int lcs(string x,string y,int m,int n)
{
    if(n==0||m==0)
        return 0;
    if(x[m-1]==y[n-1])
    {
        return 1+lcs(x,y,m-1,n-1);
    }
    else
    {
        return max(lcs(x,y,m-1,n),lcs(x,y,m,n-1));
    }
}*/
int lcs(string x,string y,int m,int n)
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
            if(x[i-1]==y[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
void printlcs(string x,string y,int m,int n)
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
            if(x[i-1]==y[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string res;
    int i=m,j=n;
    while(i>0&&j>0)
    {
        if(x[i-1]==y[j-1])
        {
            res.push_back(x[i-1]);
            i--;
            j--;

        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;

}
int main()
{
    string x,y;
    cin>>x>>y;
    int m=x.length();
    int n=y.length();
    int ans=lcs(x,y,m,n);
    cout<<ans<<endl;
    printlcs(x,y,m,n);
}
