/*Shortest path to reach one prime 
to other by changing single digit at a time*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define l long
#define sz size()
#define vt vector<int>
#define FOR(n) for (int i = 0; i < n; i++)
#define FORV(n) for (int v = 0; v < n; v++)
#define FORJ(n) for (int j = 0; j < n; j++)
#define RFOR(n) for (int i = n - 1; i >= 0; i--)
vt values;
void Print(vector<int> v){
    FOR(v.sz) cout<<values[v[i]]<<' '; 
    cout<<endl;
}
void Print(vector<vt> v){
    FOR(v.sz) {
    FORJ(v[i].sz)
        cout<<v[i][j]+1<<' ';
    cout<<endl;
    }
}
void Print(vector<bool> x){
    FOR(x.sz) if(x[i]) cout<<"1 ";
    else cout<<"0 ";
    cout<<endl;
}
bool if_prime(int x){
    for(int i=2;i<sqrt(x)+1;i++)  if(x%i==0) return false; 
    return true;
}
vt Generate_prime(int x,int y){
    vt answer;
    FOR(y+1){
        if(i<2) continue;
        if(i>=x&&if_prime(i)) answer.pb(i); 
    }
    return answer;
}
bool check(int i,int j){
    string f=to_string(i);
    string s=to_string(j);
  
    int once=0;
    FOR(s.length()) if(s[i]!=f[i]) once++;
    return once==1;
    
}
int BFS(vector<vt> adj_list,vt values){
    queue <pair<int,int>> q;
    q.push(pair<int,int>(0,0));
    pair<int,int> p ;
    vector<bool> visited(adj_list.sz,false);
    while(!q.empty()){
        p=q.front();q.pop();
        //cout<<values[p.first]<<' '<<p.second<<endl;
        if(p.first==adj_list.sz-1) return p.second;
        FOR(adj_list[p.first].sz){
            if(!visited[adj_list[p.first][i]])q.push(pair<int,int>(adj_list[p.first][i],p.second+1));
        }
    }
    cout<<endl;
    return 0;
}
int main(){
    int x,y;
    cin>>x>>y;
    string f=to_string(x);
    string s=to_string(y); if(f.sz!=s.sz) {cout<<0<<endl;return 0;}
    values=Generate_prime(x,y);
    vector<vt> adj_list(values.sz);
    //Print(values);
    FOR(values.sz){
        for(int j=i+1;j<values.sz;j++){
            if(check(values[i],values[j])){
               // if(!i)cout<<values[i]<<' '<<values[j]<<endl;
                adj_list[i].pb(j);
                adj_list[j].pb(i);
            }
        }
    }
  //  cout<<values[0]<<endl;
  //  Print(adj_list[0]);
    cout<<BFS(adj_list,values)<<endl;
}
/*

*/