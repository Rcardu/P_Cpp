/*
你是⼀个专业的⼩偷，计划偷窃沿街的房屋。每间房内都藏有⼀定的现⾦，影响你偷窃的唯
⼀制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同⼀晚上被⼩
偷闯⼊，系统会⾃动报警。
给定⼀个代表每个房屋存放⾦额的⾮负整数数组，计算你 不触动警报装置的情况下 ，⼀夜
之内能够偷窃到的最⾼⾦额。
⽰例 1：
输⼊：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (⾦额 = 1) ，然后偷窃 3 号房屋 (⾦额 = 3)。
 偷窃到的最⾼⾦额 = 1 + 3 = 4 。
⽰例 2：
输⼊：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (⾦额 = 2), 偷窃 3 号房屋 (⾦额 = 9)，接着偷窃 5 号房屋 (⾦额 = 1)。
 偷窃到的最⾼⾦额 = 2 + 9 + 1 = 12 。
提⽰：
0 <= nums.length <= 100
0 <= nums[i] <= 400
*/
#include<iostream>
#include<vector>

using namespace std;

class Robbery{
    public: 
        //dp[i]:考虑下标i（包括i）以内的房屋，最多可以偷到的金额为dp[i];
        //决定dp[i]的因素就是第i间房偷还是不偷
        //如果要偷第i间房，那么第i-1间房就不考虑dp[i]=dp[i-2]+value[i];
        //即最多偷到的金额为dp[i-2]加上第i间房屋的价值
        //如果不偷第i间房，那么dp[i]=dp[i-1]，（注意这里是考虑，不是一定要偷第i-1间房）
        //然后dp[i]取最大值，即dp[i]=max(dp[i-1],dp[i-2]+value[i])
        //由递推公式可知dp[0]和dp[1]是公式的基础
        //从定义来看dp[0]就是value[0]，dp[1]则要取value[0]和value[1]的最大值
        //即dp[1]=max(dp[0],dp[1]);
        //dp[i]由dp[i-1]与dp[i-2]推导出，遍历顺序由前往后
        /*以[2 7 9 3 1]为例
        00  01  02  03  04
        02  07  11  10  12
        */
       int Robbery_A(vector<int>&value){
        vector<int>dp(value.size(),0);
        dp[0]=value[0];
        dp[1]=max(value[0],value[1]);

        for(int i=2;i<value.size();i++){
            dp[i]=max(dp[i-1],dp[i-2]+value[i]);
        }
        return dp[value.size()-1];
       }
};

//输入输出
void RobberyForamt(){
    int N;
    cin>>N;
    vector<int>value;
    while(N--){
        int m;
        cin>>m;
        value.push_back(m);
    }

    Robbery obj;
    int val=obj.Robbery_A(value);
    cout<<val;

}