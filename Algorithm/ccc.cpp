#include <iostream>
using namespace std;
int main(){
    int n,l;
    cin>>n>>l;
    for(int i = l;i<=100;i++){
        if((2*n+i-i*i)%(2*i)==0){
            int temp = (2*n+i-i*i)/(2*i);
            for(int j = 0;j<i;j++){
                cout<<temp++<<" ";
            }
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}