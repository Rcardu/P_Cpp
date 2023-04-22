/*
有N件物品和⼀个最多能背重量为W的背包。第i件物品的重量是weight[i]，得到的价值是
value[i] 。每件物品都有⽆限个（也就是可以放⼊背包多次），求解将哪些物品装⼊背包⾥
物品价值总和最⼤。

完全背包和01背包问题唯⼀不同的地⽅就是，每种物品有⽆限件。

同样leetcode上没有纯完全背包问题，都是需要完全背包的各种应⽤，需要转化成完全背包
问题，所以我这⾥还是以纯完全背包问题进⾏讲解理论和原理。

在下⾯的讲解中，我依然举这个例⼦：
背包最⼤重量为4。

物品为：
每件商品都有⽆限个！

问背包能背的物品最⼤价值是多少？
01背包和完全背包唯⼀不同就是体现在遍历顺序上，所以本⽂就不去做动规五部曲了，我
们直接针对遍历顺序经⾏分析
            重量        价值
物品0       1           15
物品1       3           20
物品2       4           30
*/
#include<iostream>
#include<vector>

using namespace std;

class completelybackpack
{

    public:
        //背包还是那个背包，物品数量是无限的
        //将每个物品都遍历多次，条件是背包容量不满的前提下
        //当背包容量为j时，第i个物品所放入后能的到的物品的最大价值是dp[j];
        //dp[j]=max(dp[j],dp[j-weight[i]]+value[i])
        /*              00      01      02      03      04
            物品0       00      15      30      45      60    
            物品1       00      15      30      45      60
            物品2       00      15      30      45      60
        */
       //先遍历背包再遍历物品
       int completelybackpack_A(int W,vector<int>&weight,vector<int>&value){
        vector<int>dp(W,0);
        for(int j=0;j<=W;j++){
            for(int i=0;i<weight.size();i++){
                if(j>=weight[i])dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
            }
        }
        return dp[W];
       }

};


//输入输出
void CompleteForamt(){
    int N,W;
    cin>>N>>W;
    vector<int>Weigth(N,0);
    vector<int>value(N,0);
    for(int i=0;i<N;i++){
        cin>>Weigth[i]>>value[i];
    }

    completelybackpack obj;
    int val=obj.completelybackpack_A(W,Weigth,value);
    cout<<val;
    
}