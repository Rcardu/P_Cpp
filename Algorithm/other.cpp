#include <iostream>
using namespace std;
int mainl() {
   int n;
    cin>>n;
    float sum=0;
    for(int i=0;i<n;i++){
        string str1,str2;
        cin>>str1>>str2;
        if(str1[0]==str2[0])sum+=2;
        int m=str1.size();
        int m2=str2.size();
        int score1=0;
        if(m==m2){
            for(int i2=1;i2<m-5;i2++){
            if(str1[i2]!=str2[i2])break;
            if(i2==m-6)sum+=3;
        }
        }
        int i1,j1;
        for(int s=m-5;s<m;s++){
            //i1=s;
            for(int k=m2-5;k<m2;k++){
                j1=k;
                i1=s;
                while(str1[i1]==str2[j1]){
                     i1++;
                     j1++;
                    if(i1>=m&&j1>=m2)break;//这一步至关重要
                }
                score1=max(score1,j1-k);
            }
        }
        sum+=score1;
    }
    float score=((sum/10)/n)*100;
    printf("%.2f",score);
    cout<<"%"<<endl;
}
//车位

