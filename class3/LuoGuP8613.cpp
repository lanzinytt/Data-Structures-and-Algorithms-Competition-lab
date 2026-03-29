#include <bits/stdc++.h>
using namespace std;

int lowbit(int x){
    return x&(-x);
}
void update(vector<int>& c,int x){
    int n=c.size()-1;
    while(x<=n){
        c[x]++;
        x+=lowbit(x);
    }
}

int get(const vector<int>& c,int x){
    int res=0;
    while(x>0){
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> lst(n),b;
    for(int i=0;i<n;i++){
        cin>>lst[i];
        b.push_back(lst[i]);
    }

    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());

    vector<int> a(n);
    for(int i=0;i<n;i++){
        a[i]=lower_bound(b.begin(),b.end(),lst[i])-b.begin()+1;
    }

    int m=b.size();
    vector<int> c(m+1,0);
    vector<long long> cnt(n,0);

    for(int i=0;i<n;i++){
        int le=get(c,a[i]);
        cnt[i]+=i-le;
        update(c,a[i]);
    }

    fill(c.begin(),c.end(),0);
    for(int i=n-1;i>=0;i--){
        int lt=get(c,a[i]-1);
        cnt[i]+=lt;
        update(c,a[i]);
    }

    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=cnt[i]*(cnt[i]+1)/2;
    }

    cout<<ans;
    return 0;
}