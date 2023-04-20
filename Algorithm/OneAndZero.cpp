/*
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
请你找出并返回 strs 的最大子集的大小，该子集中最多有 m 个 0 和 n 个 1。
如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的子集。
⽰例 1：
输⼊：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
输出：4
解释：最多有 5 个 0 和 3 个 1 的最⼤⼦集是 {"10","0001","1","0"} ，因此答案是 4 。
其他满⾜题意但较⼩的⼦集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满⾜题意，因
为它含 4 个 1 ，⼤于 n 的值 3 。
⽰例 2：
输⼊：strs = ["10", "0", "1"], m = 1, n = 1
输出：2
解释：最⼤的⼦集是 {"0", "1"} ，所以答案是 2 。
提⽰：
1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] 仅由 '0' 和 '1' 组成
1 <= m, n <= 100
*/
#include<iostream>
#include<string>
#include<vector>
#include<numeric>

using namespace std;

class OneAndZero{
    public:
        //一个大小为m的背包只能装0，一个大小为n的背包只能装1
        //求将物品如何装入这两个背包所得到的子集最大
        //最多有i个0和j个1的strs的最大子集大小为dp[i][j];
        //dp[i][j]可由前一个strs字符串推导，即i减去strs里前一个字符串ZeroNum个0，j减去strs里前一个字符串里OneNem个1
        //dp[i][j]=dp[i-ZeroNum][j-OneNum]+1;
        //先遍历物品
        //从后往前遍历两个背包
        /*  ["10", "0001", "111001", "1", "0"]
            00  01  02  03                      m=3,n=3,ZeroNum=1,OneNum=1
        00  00  01  01  01                      m=3,n=3,ZeroNum=3,OneNum=1
        01  01  01  02  02                      m=3,n=3,ZeroNum=2,OneNum=4
        02  01  02  03  03                      m=3,n=3,ZeroNum=0,OneNum=1
        03  01  02  03  03                      m=3,n=3,ZeroNum=1,OneNum=0
        
        */
       int OneAndZero_A(vector<string>&strs,int m,int n){
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(string str:strs){
            int ZeroNum=0;
            int OneNum=0;
            for(char c:str){
                if(c=='0')ZeroNum++;
                else OneNum++;
            }
            for(int i=m;i>=ZeroNum;i--){
                for(int j=n;j>=OneNum;j--){
                    dp[i][j]=max(dp[i][j],dp[i-ZeroNum][j-OneNum]+1);
                }
            }
        }
        return dp[m][n];
       }
};


//输入输出
void OneZeroFormat(){
    int N,m,n;
    cin>>N>>m>>n;
    vector<string>strs(N,"0");
    for(int i=0;i<N;i++)cin>>strs[i];

    OneAndZero obj;
    int val=obj.OneAndZero_A(strs,m,n);
    cout<<val;

}