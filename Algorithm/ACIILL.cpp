/*一串数字经过解密后的文字是什么，有一个加密规则：给定长度不超过300个字符组成的一串文字（仅有大写字母或者空格组成）
将每个字符转成ASCII码之后再加上一个魔法数X(0<=X<=999)后组成了一串新的数字组合，加密过程就完成了。*/
//解密的第一步，先遍历X
//第二步，用一个指针指向第一个数，若是等于32或者再65-90的范围内，就将其翻译出来
//如果不在范围内，说明解法错了
//返回上一步进行X=1时的遍历
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class ACIILL{
    public:
        //一个数有字母A-Z一共26种解法，加上空格为一种解法，一共27种解法
        //dp[i]为第i个数的解法有dp[i]种
        //那么，N个数就有dp[i]*dp[i-1]*...*dp[0]种解法
        //dp[i]的解法取决于nums[i]是否满足减去魔法数后的值在65-90或者等于32
        //魔法数X在0-999之间，而nums[i]的范围在大于40且小于200
        //也就是说如果num[i]的值为空格，那么32+X要在41-199之间，即X+32>=41且X+32<=199，也就是X>=9且X<=167
        //那么原来的值Y=nums[i]-X
        //若nums[i]为A-Z的值，那么X+65要小于等于199，且X+90要小于等于199即X<=136，且X>=109
        //那么原来的值Y=nums[i]-X
        int  ACCIILL_A(vector<int>&nums,int N){
            //每一个数的解法
            vector<int>dp(N,0);
            //记录解出来的字符
            vector<vector<int>>ct(N,vector<int>());
            //原来的值
            int Y;
            //可能的魔法数X
            int X[2]={0,0};
            //标记
            bool flag=1;
            //总解法数
            long long V=1;
            //提取一种解法
            string str;
            for(int i=0;i<N;i++){
                if(nums[i]<=199&&nums[i]>=90){X[0]=25;X[1]=167;}
                else if(nums[i]>=65&&nums[i]<=90){X[0]=0;X[1]=58;}
                else if(nums[i]>=32&&nums[i]<=65){X[0]=0;X[1]=33;}
                else {flag=0;break;}
                for(;X[0]<=X[1];X[0]++){
                    Y=nums[i]-X[0];
                    if(Y==32){ct[i].push_back(Y);dp[i]++;}
                    else if(Y>=65&&Y<=90){ct[i].push_back(Y);dp[i]++;}
                }
            }
            //for(int i=0;i<N;i++)str+=ct[i][1];
            for(int i=0;i<N;i++)V*=dp[i];
            return V;
        }
        
};

//输入和输出
void ASCIILFormat(){
    int N;
    cin>>N;
    vector<int>nums(N,0);
    for(int i=0;i<N;i++)cin>>nums[i];

    ACIILL obj;
    int val=obj.ACCIILL_A(nums,N);
    if(val==1)cout<<" ";
    cout<<val;
}
