//斐波那契数列

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    //递归版
        int fib(int N){
            if(N<2)return N;
            return fib(N-1)+fib(N-2);
        }
    //遍历版
        int ftb(int N){
        if(N<=1)return N;
        vector<int>dp(N+1,0);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=N;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[N];
    }
};
//输入和输出
void inputFormat(){
    int N;
    cin>>N;
    int sum;
    Solution obj;
    sum=obj.fib(N);
    cout<<sum;
}
