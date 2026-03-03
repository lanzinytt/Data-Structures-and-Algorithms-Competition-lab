#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct hotel{
    int D,C;
    bool operator<(const hotel& o) const {
        return D<o.D||(D==o.D&&C<o.C);
    }
}hotel;


int main(){
    int N,tD,tC,cnt,i,j,MinC,MinCP;
    bool flag;
    vector<hotel> lst;
    while(cin>>N&&N!=0){
        cnt=0;
        lst.resize(N);
        for(int i=0;i<N;i++){
            cin>>tD>>tC;
            lst[i]={tD,tC};
        }
        sort(lst.begin(),lst.end());
        i=0,cnt=0,MinCP=1e9;
        while(i<N){
            j=i;
            MinC=1e9;
            while(j<N&&lst[j].D==lst[i].D){
                MinC=min(MinC,lst[j].C);
                j++;
            }
            if(MinC<MinCP){
                cnt++;
                MinCP=MinC;
            }
            i=j;
        }
        cout<<cnt<<endl;
    }
    return 0;
}