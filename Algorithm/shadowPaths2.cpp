/*⼀个机器⼈位于⼀个 m x n ⽹格的左上⾓ （起始点在下图中标记为“Start” ）。
机器⼈每次只能向下或者向右移动⼀步。机器⼈试图达到⽹格的右下⾓（在下图中标记为
“Finish”）。
现在考虑⽹格中有障碍物。那么从左上⾓到右下⾓将会有多少条不同的路径？
⽹格中的障碍物和空位置分别⽤ 1 和 0 来表⽰。


⽰例 1：
输⼊：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：
3x3 ⽹格的正中间有⼀个障碍物。
从左上⾓到右下⾓⼀共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

⽰例 2：
输⼊：obstacleGrid = [[0,1],[0,0]]
输出：1

提⽰：
m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] 为 0 或 1*/
#include<iostream>
#include<vector>
using namespace std;
class shadowPaths2{
    public:
        //当出现障碍物时，将dp[i][j]设置为0，也就是不能从障碍物处经过
        //即（1，1）有障碍物时
        /*
        1   1   1
        1   0   1
        1   1   2
        */
       //路径如上，到达(3,3)只有了2种走法

       //因为只能往下或者往右走，当一条边上的某个地方出现障碍物时，此障碍物包括后面的边都不能走了
       /*
        1   0   0
        1   1   1
        1   2   3
       */
      //路径如上，到达(3,3)只有3种走法
      int shadowPath2_i(vector<vector<int>>&obstacleGird){
        int m=obstacleGird.size();
        int n=obstacleGird[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        //初始化
        for(int i=0;i<m&&obstacleGird[i][0]==0;i++)dp[i][0]=1;//当网格边有障碍物时，障碍物包括后面都为0
        for(int j=0;j<n&&obstacleGird[0][j]==0;j++)dp[0][j]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGird[i][j]==1)dp[i][j]=0;//当网格内有障碍物时
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];

      }
};

//输入和输出
void shadow2Format(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>obstacleGrid(m,vector<int>(n,0));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>obstacleGrid[i][j];
    shadowPaths2 obj;
    int val=obj.shadowPath2_i(obstacleGrid);
    cout<<val;
}
