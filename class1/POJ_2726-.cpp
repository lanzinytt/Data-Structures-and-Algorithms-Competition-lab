#include <iostream>
#include <vector>
using namespace std;

typedef struct hotel{
    int D,C;
    bool operator<(const hotel& o){
        return (D<=o.D&&C<o.C)||(D<o.D&&C<=o.C);
    }
}hotel;


int main(){
    int N,tD,tC,cnt;
    bool flag;
    vector<hotel> lst;
    while(cin>>N&&N!=0){
        cnt=0;
        lst.resize(N);
        for(int i=0;i<N;i++){
            cin>>tD>>tC;
            lst[i]={tD,tC};
        }
        for(int i=0;i<N;i++){
            flag=true;
            for(int j=0;j<N&&flag;j++){
                if(lst[j]<lst[i])flag=false;
            }
            if(flag){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}