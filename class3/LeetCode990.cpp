#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        if(equations.empty())return true;
        n=(int)equations.size();        
        resort(equations);
        DSU dsu=DSU();
        for(int i=0;i<n;i++){
            if(equations[i][1]=='='){
                dsu.merge(equations[i][0],equations[i][3]);
            }else{
                if(dsu.find(equations[i][0],equations[i][3])){
                    return false;
                }
            }
        }
        return true;
    }
private:

    class DSU{
        public:
            DSU(){
                n=0;
                parent.clear();
                dic.clear();
            }
            int getID(char c){
                if(!dic.count(c)){
                    dic[c]=n;
                    parent.push_back(n);
                    n++;
                }
                return dic[c];
            }
            int find(int a){
                return ((parent[a]==a)?(a):(parent[a]=find(parent[a])));
            }
            void merge(int a,int b){
                int x=find(a),y=find(b);
                if(x==y)return;
                parent[y]=x;
            }
            void merge(char a,char b){
                merge(getID(a),getID(b));
            }
            bool find(char a,char b){
                int x=find(getID(a)),y=find(getID(b));
                return x==y;
            }
        private:
            int n;
            vector<int> parent;
            map<char,int> dic;
    };
    int n;
    void resort(vector<string>& equations){
        deque<string> q;
        for(string e:equations){
            if(e[1]=='='){
                q.push_front(e);
            }else{
                q.push_back(e);
            }
        }
        for(int i=0;i<n;i++){
            equations[i]=q.front();q.pop_front();
        }
    }
};

int main(){
    vector<string> e={"c==c","b==d","x!=z"};
    Solution solve;
    if(solve.equationsPossible(e))cout<<"true";
    else cout<<"false";
    return 0;
}