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
bool cmp(const PA &a, const PA &b){
    return a.first < b.first;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,string> > lst(m);
    for(int i=0;i<m;i++){
        cin>>lst[i].second;
        lst[i].first=cal(lst[i].second);
    }
    sort(lst.begin(), lst.end(), cmp);
    for(int i=0;i<m;i++){
        cout<<lst[i].second<<'\n';
    }
    system("pause");
    return 0;
}
