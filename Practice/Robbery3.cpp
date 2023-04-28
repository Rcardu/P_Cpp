/*
在上次打劫完⼀条街道之后和⼀圈房屋后，⼩偷又发现了⼀个新的可⾏窃的地区。这个地区
只有⼀个⼊⼜，我们称之为“根”。 除了“根”之外，每栋房⼦有且只有⼀个“⽗“房⼦与之相
连。⼀番侦察之后，聪明的⼩偷意识到“这个地⽅的所有房屋的排列类似于⼀棵⼆叉树”。
如果两个直接相连的房⼦在同⼀天晚上被打劫，房屋将⾃动报警。
计算在不触动警报的情况下，⼩偷⼀晚能够盗取的最⾼⾦额。

输入：
[3,2,3,null,3,null,1]
            3
        2       3
           3      1
输出:7
解释：小偷一晚能偷的最高金额为3+3+1=7

输入：
[3,4,5,1,3,null,1]

            3
        4       5
      1   3       1
输出：9
解释：小偷一晚能偷到额度最高金额为4+5=9
*/
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include"TreeNodes.cpp"
#endif


class Robbery3{
public:
    //确定递归函数的参数及返回值
    //要求一个结点，偷与不偷的两个状态所得到的金钱，那么返回值就是一个长度为2的数组
    //vector<int> roTree(BiTreeNode* root){     }
    //既然是长度为2，那么小标0就是记录不偷的，1就是记录偷的
    //如果遇到空间点，偷与不偷都是0，返回即可
    //if(root==NULL)return vector<int>(0,0);
    //使用后序遍历，因为通过递归函数的返回值来做下一步计算
    //通过递归左结点，得到左结点是否偷
    //通过递归右结点，得到右节点是否偷
    //vector<int>left=roTree(root->left)
    //vector<int>right=roTree(root->right)
    //如果偷当前结点，那么当前结点的左右孩子就不能偷,val1=root->val+left[0]+right[0];
    //如果不偷当前结点，那么左右孩子就可以偷，那么就需要考虑偷哪个,val2=max(left[0],left[1])+max(right[0],right[1])
    //当前结点的状态就是{val1,val2}，即{偷当前结点得到的最大金钱，不偷当前结点得到的最大金钱}
    //return {val2,val1};
    int Robbery3_A(BiTreeNode<int>*root){
        vector<int>result=roTree(root);
        return max(result[0],result[1]);
    }
    vector<int>roTree(BiTreeNode<int>*root){
        if(root==NULL)return vector<int>{0,0};
        vector<int>left=roTree(root->left);
        vector<int>right=roTree(root->right);
        int val1=root->data+left[0]+right[0];
        int val2=max(left[0],left[1])+max(right[0],right[1]);

        return {val2,val1};
    }

};

//输入输出
void Robbery3Format(){
    int data[]={3,2,3,'#',3,'#',1};
    int sub=0;
    int len=sizeof(data)/sizeof(data[0]);
    BiTree<int>* biTree=new BiTree<int>();
    biTree->CreateBiTree(data,sub,len,biTree->root);

    Robbery3 obj;
    int val=obj.Robbery3_A(biTree->root);
    cout<<val;
}