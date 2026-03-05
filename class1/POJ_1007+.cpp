#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int cal(string s){
    int l=s.length(),cnt=0;
    for(int i=0;i<l-1;i++){
        for(int j=i+1;j<l;j++){
            if(s[i]>s[j])cnt++;
        }
    }
    return cnt;
}

typedef pair<int,string> PA;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,string>> lst(m);
    for(int i=0;i<m;i++){
        cin>>lst[i].second;
        lst[i].first=cal(lst[i].second);
    }
    sort(lst.begin(),lst.end(),[](PA a,PA b){
        return a.first<b.first;
    });
    for(PA p:lst){
        cout<<p.second<<'\n';
    }
    system("pause");
    return 0;
}
