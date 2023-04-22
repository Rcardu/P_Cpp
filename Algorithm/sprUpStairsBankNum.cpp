/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的⽅法可以爬到楼顶呢？
注意：给定 n 是⼀个正整数。
⽰例 1：
输⼊： 2
输出： 2
解释： 有两种⽅法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶
⽰例 2：
输⼊： 3
输出： 3
解释： 有三种⽅法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
改为：⼀步⼀个台阶，两个台阶，三个台阶，.......，直到 m个台阶。问有多少种不同的⽅
法可以爬到楼顶呢？
1阶，2阶，.... m阶就是物品，楼顶就是背包。
每⼀阶可以重复使⽤，例如跳了1阶，还可以继续跳1阶。
问跳到楼顶有⼏种⽅法其实就是问装满背包有⼏种⽅法。
此时⼤家应该发现这就是⼀个完全背包问题了！
*/

#include <iostream> 	// cout, endl, istream, istringstream, fstream, string, cin,
#include<vector>

using namespace std;

class sprUpStairsBankNum{
    public:
        //爬到i个台阶的楼梯，有dp[i]种方法
        //爬到dp[i]个台阶可以来源于dp[i-1],dp[i-2],dp[i-3]等等
        //dp[i]+=dp[i-j];
        //dp[0]=1
        //考虑到，每次上1、2步或者上2、1步上的层数相同但先后不同，这是一个排列数
        //即要先遍历背包再遍历物品，也就是先遍历楼顶，在遍历阶梯
        /*
                00  01  02  03  04
        dp[i]   01  01  02  04  07
        */
       int sprUpStairsBankNum_A(int n,int m){
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=0;i<=n;i++){//遍历背包
            for(int j=1;j<=m;j++){//遍历物品
                if(i-j>=0)dp[i]+=dp[i-j];
            }
        }
        return dp[n];//you get it. it is the sum of all ways to get to n steps in the sequence of steps of the sequence of
       }

};



//输入和输出
void sprUpStairsFormat(){
    int n,m;		//number of steps in the ladder
    cin>>n>>m;

    sprUpStairsBankNum obj;	//object of the class to call the method to get the answer.
    int val=obj.sprUpStairsBankNum_A(n,m);	//call the method and pass the parameters.
    cout<<val;	//print the result.
}