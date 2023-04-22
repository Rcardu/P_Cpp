/*
给定⼀个由正整数组成且不存在重复数字的数组，找出和为给定⽬标正整数的组合的个数。
⽰例:
nums = [1, 2, 3]
target = 4
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。
因此输出为 7
*/
#include<iostream>
#include<vector>

using namespace std; 	//makes everything work like a normal C++ program

class resumehanding{
    public:
        //dp[i]:凑成目标正整数为i的排列个数dp[i];
        //递推公式:dp[j]+=dp[j-nums[i]] for all 0<=i<numElements and 0<=j<numElements.
        //dp[0]=1;当给出的数字数量为0时，只有一种方式
        //组合数先i（物品）后j（背包）
        //排列数先j（背包）后i（物品）
        /*  
                 
                    00  01  02  03  04
            dp[i]:  01  01  02  04  07    
        */
       int resumehanding_A(vector<int>& nums,int target){
            vector<int>dp(target+1,0);
            dp[0]=1;//dp[0=1;当给出的数字数量为0时，只有一种方式
            for(int j=1;j<=target;j++){
                for(int i=0;i<nums.size();i++){
                    if(j>=nums[i])dp[j]+=dp[j-nums[i]];//dp[j-nums[i]]+=dp[j-nums[i]],dp[j-nums[i]] is the number of ways to assemble the j'th bar by choosing the ith element.
                }
            }
            return dp[target];//dp[target] = # of ways to assemble the target by choosing all elements.
       }
};

//输入输出
void resumehandFormat(){
    int N,traget;
    cin>>N>>traget; //input number of numbers to be inputed and put in N.
    vector<int> nums(N,0); //creates a vector of size N and puts 0s in it.
    for(int i=0;i<N;i++){ //loops through the vector and puts 1s in the vector with the number of
        cin>>nums[i]; //inputs of the numbers put into the vector.
    }

    resumehanding obj;
    int val=obj.resumehanding_A(nums,traget); //call the function and put the return value in val.;
    cout<<val; //print the number of ways to assemble the target.

}