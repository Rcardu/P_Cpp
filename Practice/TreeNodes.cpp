#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<list>
#include<stack>
#include<queue>
#endif

using namespace std;

template <typename T>
class BiTreeNode{
public: 
    T data;
    BiTreeNode<T>*left;
    BiTreeNode<T>*right;
    BiTreeNode(T data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

template <typename T>
class BiTree{
private:
    int size;//树中结点的个数
public:
    BiTreeNode<T>*root;//根结点的指针

    BiTree(){size=0;root=NULL;};
    ~BiTree(){remove(root);};

    bool insert_left(BiTreeNode<T>* node,T data);//将data插入node的左孩子
    bool insert_right(BiTreeNode<T>*node,T data);//将data插入node的右孩子
    bool remove(BiTreeNode<T>*&node);//删除以node为根的子树
    bool preorderR(BiTreeNode<T>*node,list<T>* l);//递归实现，先序遍历以node为根的树，将结果保存到l中
    bool preorderI(BiTreeNode<T>*node,list<T>*l);//迭代实现，先序遍历以node为根的树，将结果保存到l中
    bool inorderR(BiTreeNode<T>*node,list<T>*l);//递归实现，中序遍历以node为根的树，将结果保存到l中
    bool inorderI(BiTreeNode<T>*node,list<T>*l);//迭代实现，中序遍历以node为根的树，将结果保存到l中
    bool postorderR(BiTreeNode<T>*node,list<T>*l);//递归实现，后序遍历以node为根的树，将结果保存到l中
    bool postorderI(BiTreeNode<T>*node,list<T>*l);//迭代实现，后序遍历以node为根的树，将结果保存到l中
    bool level(BiTreeNode<T>*node,list<T>*l);//层次遍历以node为根的树，并将结果保存到l中
    int height(BiTreeNode<T>*node);//以node为根的树的高度
    //参数（输入数组，数组当前位置，数组长度，当前节点结构体指针指向的地址）
    void CreateBiTree(T S[],int sub,int len,BiTreeNode<T>* &tree);
};
/**************************************************************************
Function:insert_left
Description:将data插入到node的左孩子
Input:二叉树结点node,数据data
Output:插入是否成功
***************************************************************************/
template<typename T>
bool BiTree<T>::insert_left(BiTreeNode<T>*node,T data){
    if(node==NULL){//允许树插入结点
        if(size>0)
            return false;
        else 
            root=new BiTreeNode<T>(data);
    }else{
        if(node->left!=NULL)
            return false;
        else
            node->left=new BiTreeNode<T>(data);
    }
    size++;
    return true;
}
/**************************************************************************
Function:insert_right
Description:将data插入到node的左孩子
Input:二叉树结点node,数据data
Output:插入是否成功
***************************************************************************/
template<typename T>
bool BiTree<T>::insert_right(BiTreeNode<T>*node,T data){
    if(node==NULL){
        if(size>0)
            return false;
        else   
            root=new BiTreeNode<T>(data);
    }else{
        if(node->right!=NULL)
            return false;
        else
            node->right=new BiTreeNode<T>(data);
    }
}
/*
Function:remove
Description:删除以node为根的子树
Input:二叉树结点node的引用
Output:删除是否成功
*/
template<typename T>
bool BiTree<T>::remove(BiTreeNode<T>*&node){
    //传入指针引用在于要将node的保存地址设置为空
    if(node==NULL)
        return false;
    if(remove(node->left)&&remove(node->right)){
        delete node;//释放node指向的空间
        node=NULL;//清空node内的地址
        size--;
        return true;
    }else
        return false;
}
/*
Function:preorderR、preorderI
Description:先序遍历以node为根的数，并将遍历结果保存到l中
Input:二叉树结点node，列表l
Output:遍历是否成功
*/
template <typename T>
bool BiTree<T>::preorderR(BiTreeNode<T>*node,list<T>* l){
    if(node==NULL)
        return false;
    l->push_back(node->data);
    preorderR(node->left,l);
    preorderR(node->right,l);
    return true;
}
template <typename T>
bool BiTree<T>::preorderI(BiTreeNode<T>*node,list<T>* l){
    if(node==NULL||l==NULL)
        return false;
    stack<BiTreeNode<T>*> s;
    BiTreeNode<T>*p=node;
    while(p!=NULL||s.empty()){
        if(p!=NULL){
            l->push_back(p->data);
            s.push(p);
            p=p->left;
        }else{
            p=s.top();
            s.pop();
            p=p->right;
        }
    }
    return true;
}
/*
Function:inorderR、inorderI
Description:中序遍历以node为根的数，并将遍历结果保存到l中
Input:二叉树结点node，列表l
Output:遍历是否成功
*/
template<typename T>
bool BiTree<T>::inorderR(BiTreeNode<T>*node,list<T>*l){
    if(node==NULL||l==NULL);
        return false;
    inorderR(node->left,l);
    l->push_back(node->data);
    inorderR(node->right,l);
    return true;
}
template<typename T>
bool BiTree<T>::inorderI(BiTreeNode<T>*node,list<T>*l){
    if(node==NULL||l==NULL)
        return false;
    stack<BiTreeNode<T>*> s;
    BiTreeNode<T>*p=node;
    while(!s.empty()||p!=NULL){
        if(p!=NULL){
            s.push(p);
            p=p->left;//先访问左结点
        }else{
            p=s.top();
            s.pop();//要访问就弹出
            l->push_back(p->data);
            p=p->right;
        }
    }
    return true;
}
/*
Function:postorderR、postorderI
Description:后序遍历以node为根的数，并将遍历结果保存到l中
Input:二叉树结点node，列表l
Output:遍历是否成功
*/
template <typename T>
bool BiTree<T>::postorderR(BiTreeNode<T>*node,list<T>*l){
    if(node==NULL||l==NULL)
        return false;
    postorderR(node->left,l);
    postorderR(node->right,l);
    l->push_back(node->data);
    return true;
}
template<typename T>
bool BiTree<T>::postorderI(BiTreeNode<T>*node,list<T>*l){
    if(node==NULL||l==NULL)
        return false;
    stack<BiTreeNode<T>*> s;
    BiTreeNode<T>* p=node;
    BiTreeNode<T>*pre=NULL;//用于标记访问过的结点
    while(!s.empty()||p!=NULL){
        if(p!=NULL){
            s.push(p);
            p=p->left;
        }else{
            BiTreeNode<T>*right=s.top()->right;
            if(right!=NULL&&right!=pre){
                p=right;
            }else{
                //在p==NULL且right!=NULL&&right!=pre时
                //说明要访问栈顶结点了
                pre=s.top();
                l->push_back(pre->data);
                s.pop();
            }
            
        }
    }
    return true;
}
/*
Function:level
Description:层次遍历以node为根的树，并将变量结果保存到l中
Input:二叉树结点node，列表l
Output:遍历是否成功
*/
template<typename T>
bool BiTree<T>::level(BiTreeNode<T>*node,list<T>*l){
    if(node==NULL||l==NULL)
        return false;
    queue<BiTreeNode<T>*> q;
    q.push(node);
    BiTreeNode<T>*p=NULL;
    while(!q.empty()){
        p=q.front();
        q.pop();
        l->push_back(p);
        if(p->left!=NULL)q.back(p->left);
        if(p->right!=NULL)q.back(p->right);
    }
    return true;
}
/*
Function:height
Description:以node为根的树的高度
Input:二叉树结点node
Output:树的高度
*/
template<typename T>
int BiTree<T>::height(BiTreeNode<T>*node){
    if(node==NULL)
        return 0;
    int left_hight=height(node->left);
    int right_hight=height(node->right);
    return max(left_hight,right_hight)+1;
}
/*
使用数组建立二叉树
*/
template <typename T>
void BiTree<T>::CreateBiTree(T S[],int sub,int len,BiTreeNode<T>* &root){
    if((S[0]=='#')||len==0)//对特殊情况进行分析，例如输入空数组，或者'#'开头的数组
        return ;
    if(sub>=len) //超过数组长度返回
        return ;
    if(S[sub]=='#'){
        root=NULL;
    }
    else{
        root=new BiTreeNode<int>(S[sub]);
        CreateBiTree(S,sub*2+1,len,root->left);     //建立左子树
        CreateBiTree(S,sub*2+2,len,root->right);    //建立右子树
    }
}

