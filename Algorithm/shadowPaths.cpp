/*
⼀个机器⼈位于⼀个 m x n ⽹格的左上⾓ （起始点在下图中标记为 “Start” ）。
机器⼈每次只能向下或者向右移动⼀步。机器⼈试图达到⽹格的右下⾓（在下图中标记为
“Finish” ）。
问总共有多少条不同的路径？

⽰例 1：
输⼊：m = 3, n = 7
输出：28

⽰例 2：
输⼊：m = 2, n = 3
输出：3
解释：
从左上⾓开始，总共有 3 条路径可以到达右下⾓。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右

⽰例 3：
输⼊：m = 7, n = 3
输出：28

⽰例 4：
输⼊：m = 3, n = 3
输出：6

提⽰：
1 <= m, n <= 100
题⽬数据保证答案⼩于等于 2 * 10^
*/
#include<iostream>
#include<vector>
using namespace std;
class shadowPaths{
    public:
        //深度优先搜索
        //i,j代表位置，m,n代表网格
        //每次走到终点时返回1，越界返回0
        //分为i+1和j+1开始搜索
        //将两个结果累加返回
        int desired_depth(int i,int j,int m,int n){
            if(i>m||j>n)return 0;//越界
            if(i==m&&j==n)return 1;//到达终点了
            return desired_depth(i+1,j,m,n)+desired_depth(i,j+1,m,n);
        }
        //动态规划，从（0，0）出发，终点就是（m-1，n-1）
        //dp[i][j]:从（0，0）出发到（i，j）有dp[i][j]种路径
        //例如从（0，0）到（1，1）dp[1][1]=2,到（0，2）dp[0][2]=1,到（1，2）dp[1][2]=3;
        //dp[i][j]就是从dp[i-1][j]+dp[i][j-1];
        //例如dp[1][2]=dp[0][2]+dp[1][1]=3
        //若i或者j为0 时，到达目标地点只有一种方法
        //即dp[i][0]=1;dp[0][j]=1;只能向下走或者向右走
        //开始时从左上向右下推导，那么就从左开始，一层层遍历
        //例如从（0，0）到（0，1）为1，从（0，0）到（1，0）为1，那么，从（0，0）到（1，1）就为2
        //即可以从（0，1）过去，也可以从（1，0）过去
        /*
            0   1   2   3   4   5   6
        0   1   1   1   1   1   1   1   
        1   1   2   3   4   5   6   7
        2   1   3   6   10  15  21  28
        3   1   4   10  20  35  56  84
        4   1   5   15  35  70  126 210
        */
        int shadowPaths_i(int m,int n){
            vector<vector<int>>dp(m,vector<int>(n,0));
            for(int i=0;i<m;i++)dp[i][0]=1;
            for(int j=0;j<n;j++)dp[0][j]=1;
            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
            return dp[m-1][n-1];
        }
        //问题转化，m=2,n=2时需要2步(是步数，不是走法)；m=2，n=1需要1步；m=1，n=2需要1步
        //n(0,0)=0;n(1,1)=1;n(2,2)=2;n(3,3)=4;n(4,4)=6;
        //无论怎么走总有m-1步是向下走的，n-1步是向右走的
        //也就是总共走了m+n-2步！
        //既然总共走了m+n-2步那么什么时候走的m-1步呢
        //例如总共走4步，就有6种走法，4步中必须要向下走2步，什么时候走无所谓
        //也就是一个组合数，C(4,2)，对于本题来说就是C(m+n-2,m-1);
        int combinations(int m,int n){
            long long numerator=1;//分子
            int denominator=m-1;//分母
            int count=m-1;
            int t=m+n-2;
            while(count--){//需要除的次数
                numerator*=(t--);//分母自身的阶乘累积
                while(denominator!=0&&numerator%denominator==0){//下一次计算分母前先除以分子，且保证在整数中可以除掉
                    numerator/=denominator;
                    denominator--;
                }
            }
            return numerator;
        }
};
//输入输出
void shadowFormat(){
    int i=1,j=1;
    int m,n;
    cin>>m>>n;
    shadowPaths obj;
    //int val=obj.desired_depth(i,j,m,n);
    int val=obj.combinations(m,n);//shadowPaths_i(m,n);
    cout<<val;
}