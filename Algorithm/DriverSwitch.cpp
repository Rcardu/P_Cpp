/*
	有一系列资源，ID分别为0,1,2,3,......,N-1，它们之间存在着一定的依赖关系，一个资源可以
依赖除自身外的多个任意资源。
	现在应用开始向资源管理器请求资源，如果被请求的资源没有被加载，那么资源管理器会加载该资源，
该资源所依赖的资源也会被加载，如果资源已经被加载，则不会重复加载。
	注意可能存在资源A依赖资源B，资源B依赖资源C，同时资源C又依赖资源A的情况，
这种情况下把三个资源都进行加载即可。
	应用使用完成被请求的资源后，应用会告知资源管理器会对满足条件的资源进行卸载，
具体为：对应用请求的资源，只有当应用告知使用完毕，并且该资源没有被任何已加载资源依赖时
，才会被卸载；对于非应用请求的资源，没有被任何已加载的资源依赖，则执行卸载，对于不满足
卸载条件的资源，则驻留在资源管理器中。
	应用会执行一系列的请求资源和使用完毕操作，请给出这一系列操作过程中，资源管理
器中驻留的资源数量的最大值。

输入描述：
	第一行：输入一个整数N（1<N<=10000），和一个整数X（10<=X<=1000），相互
之间由空格隔开，N为资源的个数，X为应用请求资源和使用完毕操作的总次数。
	接下来的N行，每行输入若干个整数，相互之间由空格隔开，第一个数表示该行对应的
资源所依赖的资源的数量n，之后的n个数表示依赖资源的ID（0<=ID<= N-1）。
	接下来的X行，每行输入两个整数，相互之间由空格隔开。第一个数为0或1，0表示用完
毕，1表示请求资源。第二个数为操作资源的ID

输出描述：
	一个整数，表示整个过程中，资源管理器最多驻留的资源的数量。
    ..
*/
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int mainl(){
    //资源个数，及操作个数
    int N,X;
    cin>>N>>X;
    //先输入依赖资源
    vector<vector<int>>ID(N);
    for(int i=0;i<N;i++){
        //所依赖资源个数
        int nums;
        cin>>nums;
        for(int j=0;j<nums;j++){
            //所依赖资源ID
            int ids;
            cin>>ids;
            ID[j].push_back(ids);
        }
    }
    //使用一个队列来标记资源使用情况
    queue<int> dp;
    //使用一个数组来记录每个资源的请求，卸载情况
    vector<int>count(N,0);
    //使用一个数组来记录资源的遍历状态
    vector<bool>scree(N,0);
    //操作
    bool flag;
    //被操作ID
    int id;
    //先遍历资源,再遍历操作
    int MAX_I=0;
    for(int i=0;i<X;i++){
                for(int i=0;i<N;i++){    //先将每个资源的使用标记为true,每次刷新资源状态
                    scree[i]=true;
                }
            cin>>flag>>id;
            if(flag==0)flag=-1;//如果是要卸载资源
            dp.push(id);//将要被操作的资源入队
            while(!dp.empty()){//如果队列里有要被操作的资源
                //先将资源赋给一个中间变量
                int temp=dp.front();
                //将此资源的情况计入对应情况数组中
                count[temp]+=flag;
                //将此资源标记为已使用过
                scree[temp]=false;
                //将此资源出列
                dp.pop();
                for(int j=0;j<ID[temp].size();j++){//看查依赖资源
                    if(scree[ID[temp][j]]==false)continue;//如果所依赖资源已被遍历过
                    dp.push(ID[temp][j]);//否则入队
                }
            }
             //每完成一个操作就计算此操作后资源管理器中资源的数量
            int mount=0;
            for(int m=0;m<N;m++){
                if(count[m]>0)mount++;
            }  
            MAX_I=max(MAX_I,mount);//每次取最大资源数记录
    }
    cout<<MAX_I;
    while(getchar()!='\n')
    continue;
    getchar();

    return 0;
}

































/*
int main() {
    //资源个数和操作总数
    int N,M;
    cin>>N>>M;
    //用来计算个资源的使用情况
    vector<int>count(N);
    //标识资源的调用或卸载情况
    vector<bool>screen(N);
    //所依赖资源的ID
    vector<vector<int>>register1(N);
    for(int i=0;i<N;i++){
        //所依赖的资源数量
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            //所依赖资源的ID
            int num;
            cin>>num;
            register1[i].push_back(num);
        }
    }
    //用来调度资源
    queue<int>Queue;
    int MAXstop=0;
    for(int i=0;i<M;i++){//第i个操作
        for(int j=0;j<N;j++){//第j个资源
            screen[j]=true;//开始时资源都在准备阶段
        }
        //卸载或者请求，当前资源的ID
        int flag,number;
        cin>>flag>>number;
        //如果要卸载资源，就将资源-1即卸载
        if(flag==0)flag=-1;
        Queue.push(number);
        while(!Queue.empty()){//若队列不为空
            int sTop=Queue.front();//获取队首元素
            count[sTop]+=flag;//记录资源使用状态
            screen[sTop]=false;//表示当前元素已卸载
            Queue.pop();//将队首元素出列
            for(int j=0;j<register1[sTop].size();j++){//查询此资源依赖项
                if(screen[register1[sTop][j]]==false)continue;//所依赖资源已经被卸载
                Queue.push(register1[sTop][j]);//将所依赖资源进队
            }
        }
        //本次操作资源使用状态
        int mcount=0;
        for(int ss=0;ss<N;ss++){
            if(count[ss]>0)mcount++;
        }
        //最后取资源最多的一次操作
        MAXstop=max(MAXstop,mcount);
    }
    cout<<MAXstop<<endl;
    while(getchar()!='\n')
    continue;
    getchar();
}
*/
