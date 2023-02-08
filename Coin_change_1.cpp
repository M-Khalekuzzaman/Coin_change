#include<bits/stdc++.h>
using namespace std;

const int N = 60;
const int M = 1001;
const int MOD = 100000007;

int dp[N][M];
int coin[N],limit[N];

int Coin_change(int n,int k)
{
    // 1. Base case
    if(n == 0)
    {
        if(k == 0) return 1;
        return 0;
    }
    if(dp[n][k] != -1)
    {
        return dp[n][k];
    }

    int ans = Coin_change(n-1,k);
    for(int i = 1; i<=limit[n]; i++)
    {
        if(k-i*coin[n] < 0) break;
        int ret = Coin_change(n-1,k-i*coin[n]);
        ans = (ans+ret)%MOD;
    }
    dp[n][k] = ans;
    return ans;

}
int main()
{
    int t,tst = 0;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;

        for(int i = 1; i<=n; i++)
        {
            cin>>coin[i];
        }
        for(int j = 1; j<=n; j++)
        {
            cin>>limit[j];
        }

        for(int i = 0; i<=n; i++)
        {
            for(int j = 0; j<=k; j++)
            {
                dp[i][j] = -1;
            }
        }

        cout<<Coin_change(n,k)<<endl;


    }






    return 0;
}
