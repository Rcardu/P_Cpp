/*
我们在两条独⽴的⽔平线上按给定的顺序写下 A 和 B 中的整数。
现在，我们可以绘制⼀些连接两个数字 A[i] 和 B[j] 的直线，只要 A[i] == B[j]，且我们绘制的
直线不与任何其他连线（⾮⽔平线）相交。
以这种⽅法绘制线条，并返回我们可以绘制的最⼤连线数。
输入：A=[1,4,2] B=[1, 2 4]
输出:2

输入：A=[2,5,1,2,5] B=[10,5,2,1,5,2]
输出：3

输入：A=[1,3,7,1,7,5]   B=[1,9,2,5,1]
输出：2
*/
#include<iostream>
#include<vector>

using namespace std;

class DisjointLines{
public:
    //动态规划，不相交的线
    int DisjointLines_A(vector<int>&numsA,vector<int>&numsB){
    vector<vector<int>>dp(numsA.size()+1,vector<int>(numsB.size()+1,0));
    for(int i=1;i<=numsA.size();i++){
        for(int j=1;j<=numsB.size();j++){
            if(numsA[i-1]==numsB[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[numsA.size()][numsB.size()];
}
};
/*
绘制一些连接两个相同数字的直线，也就是A[i]==B[j]时将其连接，且不能相交，也就是说，找到相对顺序不变的最长相同子序列
*/
//输入输出
void DisjoinLinesFormat(){
    int N,M;
    cin>>N>>M;
    vector<int>numsA(N);
    vector<int>numsB(M);
    for(int i=0;i<N;i++)cin>>numsA[i];
    for(int i=0;i<M;i++)cin>>numsB[i];

    DisjointLines obj;
    int val=obj.DisjointLines_A(numsA,numsB);
    cout<<val;
}
