/*
给定⼀个字符串，你的任务是计算这个字符串中有多少个回⽂⼦串。
具有不同开始位置或结束位置的⼦串，即使是由相同的字符组成，也会被视作不同的⼦串。
⽰例 1：
输⼊："abc"
输出：3
解释：三个回⽂⼦串: "a", "b", "c"
⽰例 2：
输⼊："aaa"
输出：6
解释：6个回⽂⼦串: "a", "a", "a", "aa", "aa", "aaa"
提⽰：
输⼊的字符串长度不会超过 1000 。
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class PalindormicSubstring{
public:
/*
暴力解法，使用两层for循环，每有一个回文就加一，字符本身就是回文
            a   b   a   c
        a   1   0   2   0   
        b   0   3   0   0
        a   0   0   4   0
        c   0   0   0   5
*/
    int PalindormicSubstring_A(string str){
        int count=0;
        bool flag=1;
        for(int i=0;i<str.size();i++){
            for(int j=i;j<str.size();j++){
                flag=1;
                if(str[i]==str[j]&&(i==j||j-i==1)){
                    count++;
                }else if(str[i]==str[j]){
                    for(int k=0;k<=(j-i)/2;k++){
                        if(str[k+i]!=str[j-k])flag=0;
                    }
                    if(flag)count++;
                }
            }
        }
        return count;
    }
/*
动态规划
***dp数组
    bool类型的dp[i][j]表示区间为[i,j]的范围内的字串是否为回文字串，如果是，就返回true否则返回false
***递推公式
    str[i]!=str[j]则为false
    str[i]==str[j]:
        ~   i=j也即是说是同一个字符，当然是回文
        ~   下标i与j相差为1，例如aa，也是回文字串
        ~   相差大于1此时str[i]==str[j]了，现在就要看dp[i+1][j-1]了
***初始化
dp[i][j]刚开始默认全部不匹配
***遍历顺序
由于dp[i][j]是由dp[i+1][j-1]决定的，所以遍历顺序应从下到上，从左到右
***举例推导
        "aaa"
        a   a   a
    a   1   1   1
    a   0   1   1
    a   0   0   1
    有6个true故count=6;
*/
    int PalindromicSubstring_B(string str){
        vector<vector<bool>>dp(str.size(),vector<bool>(str.size(),false));
        int count=0;
        for(int i=str.size()-1;i>=0;i--){
            for(int j=i;j<=str.size()-1;j++){
                if(str[i]==str[j]){
                    if(j-i<=1){
                        dp[i][j]=true;
                        count++;
                    }else if(dp[i+1][j-1]){
                        dp[i][j]=true;
                        count++;
                    }
                }
            }
        }
        return count;
    }

/*
双指针法
以一个元素为中心点
以两个元素为中心点
判断是否从中心点扩散
*/
    int PalindormicSubstring_C(string str){
        int result;
        for(int i=0;i<str.size();i++){
            result+=C_extend(str,i,i,str.size());//以i为中心
            result+=C_extend(str,i,i+1,str.size());//以i与i+1为中心
        }
        return result;
    }
private:
    //C方案辅助函数
    int C_extend(const string&str,int i,int j,int n){
        int res=0;
        while(i>=0&&j<n&&str[i]==str[j]){//扩散的条件，中心点左边有，右边也有，且中心点本身就是回文
            i--;//往左边扩散
            j++;//同时往右边扩散
            res++;
        }
        return res;
    }
};

//输入输出
void PalindromicFormat(){
    string str;
    cin>>str;
    PalindormicSubstring obj;
    //int val=obj.PalindormicSubstring_A(str);
    //int val=obj.PalindromicSubstring_B(str);
    int val=obj.PalindormicSubstring_C(str);
    cout<<val;
}