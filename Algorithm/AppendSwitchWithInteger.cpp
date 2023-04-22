/*
给定⼀个正整数 n，将其拆分为⾄少两个正整数的和，并使这些整数的乘积最⼤化。 返回
你可以获得的最⼤乘积。
**
⽰例 1:
输⼊: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。

⽰例 2:
输⼊: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。

说明: 你可以假设 n 不⼩于 2 且不⼤于 58。
*/
#include<iostream>
#include<vector>

using namespace std;

class AppendSwitchWithInteger{
    public:
        //dp[i]:拆分的数字为i拆分数字所得到的最大乘积为dp[i];
        //将j从1开始遍历，即j*(i-j);
        //而dp[i]就是最大乘积则j*dp[i-j]就是拆分了(i-j)本身
        //当计算dp[3]时j=1就有max(1*(3-1),1*dp[3-1])
        //因为0与1无法拆分所以dp[2]=1
        //j=2就有max(2*(3-2),2*dp[3-2]);
        //因为dp[0]与dp[1]没有意义，所以当进行到i-j=1时就应该停止即i-1需要大于j;(j<i-1)
        int AppendSwitchWithInteger_i(int n){
            vector<int>dp(n+1,0);
            dp[2]=1;
            for(int i=3;i<=n;i++){
                for(int j=1;j<i-1;j++){
                    dp[i]=max(dp[i],max(j*(i-j),j*dp[i-j]));
                }
            }
            return dp[n];
        }
        //贪心算法,每次拆成n个3，如果剩下是4，则保留4，然后相乘
        int greedy_cover(int n){
            if(n==2)return 1;
            if(n==3)return 2;
            if(n==4)return 4;
            int value=1;
            while(n>4){
                value*=3;
                n-=3;
            }
            return value*=n;
        }
};

//输入和输出
void AppendFormat(){
    int num;
    cin>>num;

    AppendSwitchWithInteger obj;
    int val=obj.greedy_cover(num);//AppendSwitchWithInteger_i(num);
    cout<<val;

}
