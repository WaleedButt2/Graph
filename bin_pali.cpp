/*Construct binary palindrome by repeated appending and trimming*/
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
    FOR(v.sz) cout<<v[i]; 
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
void fill(int n,int k){
    vt hold(n);
    FOR(n){
        hold[i]=i%k;
    }
    map<int,int> dict;
    dict.insert(pa(0,1));
    FOR(n/2+1){
        int replace;
        if(dict.find(hold[i])==dict.end()){
            if(dict.find(hold[hold.sz-1-i])==dict.end()){
                hold[i]=0;
                hold[hold.sz-1-i]=0;
                dict.insert(pa(hold[hold.sz-1-i],0));
                dict.insert(pa(hold[i],0));
            }
            else{
                hold[i]=dict.find(hold[hold.sz-1-i])->second;
                hold[hold.sz-1-i]=dict.find(hold[hold.sz-1-i])->second;
                dict.insert(pa(hold[hold.sz-1-i],0));
            }
        }
        else{
            if(dict.find(hold[hold.sz-1-i])==dict.end()){
                hold[hold.sz-1-i]=dict.find(hold[ i])->second;;
                dict.insert(pa(hold[hold.sz-1-i],hold[hold.sz-1-i]));
                hold[i]=hold[hold.sz-1-i];
            }
            else{
                hold[i]=dict.find(hold[hold.sz-1-i])->second;
                hold[hold.sz-1-i]=hold[i];
            }           
        } 
    }
    Print(hold);
}
int main(){
    int n,k;
    cin>>n>>k;
    fill(n,k);
}
/*

*/