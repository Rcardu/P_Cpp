/*
对于多重背包，我在⼒扣上还没发现对应的题⽬，所以这⾥就做⼀下简单介绍，⼤家⼤概了
解⼀下。
有N种物品和⼀个容量为V 的背包。第i种物品最多有Mi件可⽤，每件耗费的空间是Ci ，价
值是Wi 。求解将哪些物品装⼊背包可使这些物品的耗费的空间 总和不超过背包容量，且价
值总和最⼤。
多重背包和01背包是⾮常像的， 为什么和01背包像呢？
每件物品最多有Mi件可⽤，把Mi件摊开，其实就是⼀个01背包问题了。

例如：
背包最⼤重量为10。
物品为：
重量 价值 数量
物品0 1 15 2
物品1 3 20 3
物品2 4 30 2

多重背包
问背包能背的物品最⼤价值是多少？
和如下情况有区别么？
        重量 价值 数量
物品0   1   15      1
物品0   1   15      1
物品1   3   20      1
物品1   3   20      1
物品1   3   20      1
物品2   4   30      1
物品2   4   30      1
毫⽆区别，这就转成了⼀个01背包问题了，且每个物品只⽤⼀次
*/

 #include<iostream>
 #include<vector>

 using namespace std;


class FoundationS{
    public:
        //把每个物品拆分出来，例如物品0数量为2，就拆分成，物品0，物品0
        //dp[i]:重量为i的背包可以装的最大价值为dp[i];
        //dp[j]由dp[j-weight[i]]+value[i]决定
        //即，dp[j]=max(dp[j],dp[j-weight[i]]+value[i])
        //dp[0],即背包重量为0时的价值
        //dp[0]=0;
        //先遍历物品，再遍历背包
        //i=0;i<N;i++
        //j=W;j>=weight[i];j--
        //背包从后往前遍历，保证每个物品只被遍历到1次
        int FoundationS_A(int W,vector<int>&weight,vector<int>&value,vector<int>&nums){
            //拆分前
            /*  重量    价值    数量
            00  01      15      02
            01  03      20      03
            02  04      30      02
            */
            for(int i=0;i<nums.size();i++){
                while(nums[i]>1){
                    weight.push_back(weight[i]);
                    value.push_back(value[i]);
                    nums[i]--;
                }
            }
            //拆分后
            /*  重量        价值            数量
            00  01          15              01
            01  03          20              01
            02  04          30              01
            03  01          15              01
            04  03          20              01
            05  03          20              01
            06  04          30              01
            */

            vector<int>dp(W+1,0);
            dp[0]=0;

            for(int i=0;i<weight.size();i++){
                for(int j=W;j>=weight[i];j--){
                    dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
                }
            }

            //看查数组最终情况
            for(int j=0;j<dp.size();j++){
                cout<<dp[j]<<" ";
            }
            cout<<endl;

            return dp[W];
        }
        //把每种商品的个数再遍历一遍
        /*  00  01  02  03  04  05  06  07  08  09  10
            00  15  30  30  30  30  30  30  30  30  30
            00  15  30  30  35  50  50  55  70  70  70
            00  15  30  30  35  50  60  60  70  80  90

        */
        int FoundationS_B(int W,vector<int>&weight,vector<int>&value,vector<int>&nums){
            vector<int>dp(W+1,0);
            dp[0]=0;
            for(int i=0;i<weight.size();i++){
                for(int j=W;j>=weight[i];j--){
                    for(int k=1;k<=nums[i]&&(j-k*weight[i])>=0;k++){//遍历物品数量
                        dp[j]=max(dp[j],dp[j-k*weight[i]]+k*value[i]);
                    }
                }
            }
            for(int i=0;i<=W;i++)cout<<dp[i]<<" ";
            cout<<endl;

            return dp[W];
        }
};



 //输入输出
void FounfationSFormat(){
    int N,W;
    cin>>N>>W;
    vector<int>weight(N,0);
    vector<int>value(N,0);
    vector<int>nums(N,0);
    for(int i=0;i<N;i++){
        cin>>weight[i]>>value[i]>>nums[i];
    }

    FoundationS obj;
    //int val_A=obj.FoundationS_A(W,weight,value,nums);
    int val_B=obj.FoundationS_B(W,weight,value,nums);
    cout<<val_B;

}