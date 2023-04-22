/*
给定⼀个整数 n，求以 1 ... n 为节点组成的⼆叉搜索树有多少种？

右节点大于左节点以及中间节点，且右子树上的任意一个节点都大于左子树上的节点
*/
#include<iostream>

using namespace std;

class TransactionalFriendlyTreeSet{
    public:
        //当只有n为1时只有1种情况即dp[1]=1;
        //当n为2时有两种情况即dp[2]=2;
        //当n为3时有5种情况
        //1.以1为头结点的树2、3在右边，有两种情况
        //2.以3为头结点的树1、2在左边，有两种情况
        //3.以2为头结点的树1在左边，2在右边，一种情况
        //由此可知
        //dp[i]:当有i个结点时，dp[i]为有几种搜索树
        //dp[i]=dp[i]+[以j为头结点的左子树数量]*[以j为头结点的右子树的数量]
        //例如dp[3]=dp[0]*dp[2]+dp[1]*dp[1]+dp[2]*dp[0];
        //dp[0]也是一颗树，是一颗二叉搜索树即dp[0]=1;
        //dp[i]+=dp[j-1]*dp[i-j];
        //也就是i从1开始，j从i开始遍历
        /*
            0   1   2   3   4   5
            1   1   2   5   14  42
        */
       int TransactionalFriendlyTreeSet_i(int n){
        if(n==0)return 1;
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
       }
};


//输入和输出
void TransactionalFormat(){
    int n;
    cin>>n;

    TransactionalFriendlyTreeSet obj;
    int val=obj.TransactionalFriendlyTreeSet_i(n);
    cout<<val;
}
