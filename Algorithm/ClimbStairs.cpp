/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的⽅法可以爬到楼顶呢？
注意：给定 n 是⼀个正整数。

⽰例 1：
输⼊： 2
输出： 2
解释： 有两种⽅法可以爬到楼顶。
1 阶 + 1 阶
2 阶

⽰例 2：
输⼊： 3
输出： 3
解释： 有三种⽅法可以爬到楼顶。
1 阶 + 1 阶 + 1 阶
1 阶 + 2 阶
2 阶 + 1 阶
*/
//dp[i]:爬到地i层楼梯有dp[i]种方法，即i代表层数，dp[i]的值代表方法数
//上i-1层楼有dp[i-1]种方法，上i-2就有dp[i-2]种方法
//那么上i层楼就有dp[i-1]+dp[i-2]种方法，即dp[i]=dp[i-1]+dp[i-2];
//例如：上1层楼有1种方法，上两层有2种方法，上3层就是2+1种方法
#include<iostream>
#include<vector>
using namespace std;
class ClimbStairs{
    public:
        int def(int N){
            if(N<2)return N;
            vector<int>dp(N+1,0);
            dp[1]=1;
            dp[2]=2;
            for(int i=3;i<=N;i++){
                dp[i]=dp[i-1]+dp[i-2];
            }
            return dp[N];
        }
        //空间复杂度优化,不需要长度为N，直接设置长度为3
        int def_n(int N){
            if(N<2)return N;
            int dp[3];
            dp[1]=1;
            dp[2]=2;
            for(int i=3;i<=N;i++){
                int sum=dp[2]+dp[1];
                dp[1]=dp[2];
                dp[2]=sum;
            }
            return dp[2];
        }
        
};
/*
拓展
这道题⽬还可以继续深化，就是⼀步⼀个台阶，两个台阶，三个台阶，直到 m个台阶，有
多少种⽅法爬到n阶楼顶。
*/
//输入和输出
void ClimbStairsFormat(){
    int N;
    cin>>N;
    int sum;
    ClimbStairs obj;
    sum=obj.def_n(N);
    cout<<sum;
}