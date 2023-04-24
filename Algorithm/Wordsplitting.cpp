/*
给定⼀个⾮空字符串 s 和⼀个包含⾮空单词的列表 wordDict，判定 s 是否可以被空格拆分
为⼀个或多个在字典中出现的单词。
说明：
拆分时可以重复使⽤字典中的单词。
你可以假设字典中没有重复的单词。
⽰例 1：
输⼊: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
⽰例 2：
输⼊: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 注意你可以重复使⽤字典中的单词。
⽰例 3：
输⼊: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
*/
#include <iostream> // for cout, cin, endl, fstream, operator<<, filebuf, file_descriptor,
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;

class Wordsplitting{
    public:
        //dp[i]:字符串长度为i的话dp[i]为true,表示可以拆分为1个或多个在字典里出现的单词
        //如果确定dp[j]是true，且[j,i]这个区间的字串出现在字典里，那么dp[i]一定是true(j<i)
        //所以递推公式为if([j,i]这个区间的字串出现在字典里&&dp[j]是true)那么dp[i]=ture;
        //dp[i]是由dp[j]是否为true决定的，也就是说初始dp[0]不为true的话以后的都是false
        //所以dp[0]=true;
        //那么下标非0的就都初始化为false
        /*      leetcode        ["leet,code"]
            0   1   2   3   4   5   6   7   8
            0   0   0   0   1   0   0   0   1
        
        */
       bool Wordsplitting_A(string s,vector<string>&wordDict){
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end()); //creating a set of words from the wordDict
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.size();i++){//背包
            for(int j=0;j<i;j++){
                string word=s.substr(j,i-j);//substr(起始位置，截取个数) 函数返回字符串从起始位置到结束位置的字符串。 参数起始位置和截

                if(dp[j]&&wordSet.find(word)!=wordSet.end()){
                    dp[i]=true;
                }
            }
        }
        return dp[s.size()];

       }
};

// 输入输出
void WordsplittingFormat(){
    string s;
    cin>>s;
    int N;
    cin>>N; // number of words to be split by spaces.
    vector<string> wordDict; // word dictionary.  strings are copied.  no need to reference.  delete.  strings are immutable.
    for(int i=0;i<N;i++){ // read in the words from the user.  strings are copied.  no need to
        string t; // for loop variable.  strings are immutable.  delete.  strings are immutable.  strings are immutable.  delete.  strings
        cin>>t;
        wordDict.push_back(t); // copy the string to the vector.  strings are immutable.  delete.  strings are immutable.  delete
    }
    Wordsplitting obj;
    bool val=obj.Wordsplitting_A(s,wordDict); // call the function to split the string.  returns true or false.  strings
    cout<<val; // print the result.  true or false.  strings.  copy from the vector.  strings are immutable.  delete.  strings.  delete

}