#include<iostream>
#include<vector>
using namespace std;
int fib(int N)
{
    if(N<=1)return N;
    vector<int>dp(N+1,0);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=N;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[N];
}
void mainl(){
    int N;
    cin>>N;
    int sum;
    sum=fib(N);
    cout<<sum;
}