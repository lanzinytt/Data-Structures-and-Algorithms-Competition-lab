#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N,num,sign;
    cin>> N;
    vector<pair<int,int>> H;
    vector<int> J(N,0);
    for(int i=0;i<N;i++){
        cin>>num;
        if(H.empty()){
            H.push_back({num,i+1});
        }
        else{
            while((!H.empty()) && num>H.back().first){
                sign=H.back().second;
                H.pop_back();
                J[sign-1]=i+1;
            }
            H.push_back({num,i+1});
        }
    }
    for(int i=0;i<N;i++){
        cout<<J[i]<<endl;
    }
    return 0;
}