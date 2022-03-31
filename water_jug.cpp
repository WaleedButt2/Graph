/*Shortest path to reach one prime 
to other by changing single digit at a time*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define l long
#define sz size()
#define vt vector<int>
#define pa pair<int,int>
#define paa pair<pa,int>
#define FOR(n) for (int i = 0; i < n; i++)
#define FORV(n) for (int v = 0; v < n; v++)
#define FORJ(n) for (int j = 0; j < n; j++)
#define RFOR(n) for (int i = n - 1; i >= 0; i--)
void Print(vector<int> v){
    FOR(v.sz) cout<<v[i]<<' '; 
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
int BFS(int j1,int j2,int g){
    queue<paa> q;
    queue<pa> parents;
    paa p=paa(pa(0,0),0);
    map<pa,int> dict;
    q.push(p);
    int co=0;
    dict.insert(paa(pa(0,0),co));
    parents.push(pa(0,-1));
    vt papa;papa.pb(-1);
    co++;
    while(!q.empty()){
        p=q.front();q.pop();
        int peep=parents.front().first;
        parents.pop();
        if((p.first.first==g&&p.second==0)||(p.first.second==g&&p.first.first==0)) break;
        //fill jug1
        if(dict.find(pa(j1,p.first.second))==dict.end()){
            dict.insert(paa(pa(j1,p.first.second),co));co++;
            q.push(paa(pa(j1,p.first.second),p.second+1));
            parents.push(pa(co-1,peep));
            papa.pb(peep);
        }
        //fill jug2
        if(dict.find(pa(p.first.first,j2))==dict.end()){
            dict.insert(paa(pa(p.first.first,j2),co));co++;
            q.push(paa(pa(p.first.first,j2),p.second+1));
            parents.push(pa(co-1,peep));
            papa.pb(peep);
        }
        //empty jug1 or jug2
        //fill jug1
        if(dict.find(pa(0,p.first.second))==dict.end()){
            dict.insert(paa(pa(0,p.first.second),co));co++;
            q.push(paa(pa(0,p.first.second),p.second+1));
            parents.push(pa(co-1,peep));
            papa.pb(peep);
        }
        //fill jug2
        if(dict.find(pa(p.first.first,0))==dict.end()){
            dict.insert(paa(pa(p.first.first,0),co));co++;
            q.push(paa(pa(p.first.first,0),p.second+1));
            parents.push(pa(co-1,peep));
            papa.pb(peep);
        }       
        //pour from jug1 to jug2
        int diffreq1=j1-p.first.first;
        int diffreq2=j2-p.first.second;
        if(diffreq1>p.first.second) diffreq1=p.first.second;
        if(diffreq2>p.first.first) diffreq2=p.first.first;
        
        if(dict.find(pa(p.first.first+diffreq1,p.first.second-diffreq1))==dict.end()){
            dict.insert(paa(pa(p.first.first+diffreq1,p.first.second-diffreq1),co));co++;
            q.push(paa(pa(p.first.first+diffreq1,p.first.second-diffreq1),p.second+1));
            parents.push(pa(co-1,peep));
            papa.pb(peep);
        }

        if(dict.find(pa(p.first.first-diffreq2,p.first.second+diffreq2))==dict.end()){
            dict.insert(paa(pa(p.first.first-diffreq2,p.first.second+diffreq2),co));co++;
            q.push(paa(pa(p.first.first-diffreq2,p.first.second+diffreq2),p.second+1));
            parents.push(pa(co-1,peep));
            papa.pb(peep);
        }
    }
    if(p.first.first!=g&&p.first.second!=g) return 0;
    auto root=dict.find(p.first);
    stack<pa> sta;
    map<int,pa>rev_dict;
    for(auto itr=dict.begin();itr!=dict.end();itr++) rev_dict.insert(pair<int,pair<int,int>>(itr->second,itr->first));
    while(root->second!=0){
        sta.push(root->first);
        root=dict.find(rev_dict.find(papa[root->second])->second);
    }sta.push(pa(0,0));
    while(!sta.empty()){
        cout<<'('<<sta.top().first<< ','<<sta.top().second<<") "<<endl;sta.pop();
    }
    return p.second+1;
}
int main(){
    int jug1,jug2,goal;
    cin>>jug1>>jug2>>goal;
    cout<<BFS(jug1,jug2,goal)<<endl;
}
/*

*/