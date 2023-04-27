/*
你是⼀个专业的⼩偷，计划偷窃沿街的房屋，每间房内都藏有⼀定的现⾦。这个地⽅所有的
房屋都 围成⼀圈 ，这意味着第⼀个房屋和最后⼀个房屋是紧挨着的。同时，相邻的房屋装
有相互连通的防盗系统，如果两间相邻的房屋在同⼀晚上被⼩偷闯⼊，系统会⾃动报警 。
给定⼀个代表每个房屋存放⾦额的⾮负整数数组，计算你 在不触动警报装置的情况下 ，能
够偷窃到的最⾼⾦额。
⽰例 1：
输⼊：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（⾦额 = 2），然后偷窃 3 号房屋（⾦额 = 2）, 因为他们是相
邻的。
⽰例 2：
输⼊：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（⾦额 = 1），然后偷窃 3 号房屋（⾦额 = 3）。偷窃到的最
⾼⾦额 = 1 + 3 = 4 。
⽰例 3：
输⼊：nums = [0]
输出：0
提⽰：
1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/
#include<iostream>
#include<vector>

using namespace std;

class Robbery2{
    public:
        //现在房屋成了环状
        //有三种情况
        //1.考虑偷不包含首尾元素的房子
        //2.考虑偷不包含尾元素的房子
        //3.考虑偷不包含首元素的房子
        //当只考虑2.3时，情况已经包含1了也就是在2.3中做出选择
        
        //情况选择
        int Select_A(vector<int>&value){
            if(value.size()==0)return 0;
            if(value.size()==1)return value[0];
            int result1=Robbery2_A(value,0,value.size()-1);//情况2
            int result2=Robbery2_A(value,1,value.size());//情况3

            return max(result1,result2);
        }
        //方法
        int Robbery2_A(vector<int>&value,int begin,int end){
            if(begin==(end-1))return value[begin];
            vector<int>dp(value.size());
            dp[begin]=value[begin];
            dp[begin+1]=max(value[begin],value[begin+1]);

            for(int i=begin+2;i<end;i++){
                dp[i]=max(dp[i-1],dp[i-2]+value[i]);
            }

            return dp[end-1];
        }
};

//输入输出
void Robbery2Format(){
    int N;
    cin>>N;
    vector<int>value(N);
    for(int i=0;i<N;i++)cin>>value[i];

    Robbery2 obj;
    int val=obj.Select_A(value);
    cout<<val;
}