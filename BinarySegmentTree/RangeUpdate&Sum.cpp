#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const ll mxN = ((1<<17)+1);
struct node{
    ll level;
    ll value;
};

struct node tree[4*mxN];
ll arr[mxN];
ll n;

void build(ll s=0, ll e=((1<<n)-1), ll idx=1){
    if(s>e) return;
    if(s==e){
        tree[idx].level=1;
        tree[idx].value=arr[s];
        return;
    }
    ll mid=(s+e)/2;
    build(s, mid, 2*idx);
    build(mid+1, e, 2*idx+1);
    
    tree[idx].level = tree[2*idx].level+1;
    if(tree[idx].level & 1)
        tree[idx].value = tree[2*idx].value ^ tree[2*idx+1].value;
    else 
        tree[idx].value = tree[2*idx].value | tree[2*idx+1].value;
}

void pointUpdate(ll pos, ll val, ll s=0, ll e=((1<<n)-1), ll idx=1){
    if(s>e)
        return;
    if(s==e){
        tree[idx].value = val;
        return;
    }
    ll m = (s+e)/2;
    if(pos>=s && pos<=m)
        pointUpdate(pos, val, s, m, 2*idx);
    else 
        pointUpdate(pos, val, m+1, e, 2*idx+1);
    if(tree[idx].level & 1)
        tree[idx].value=tree[2*idx].value ^ tree[2*idx+1].value;
    else 
        tree[idx].value=tree[2*idx].value | tree[2*idx+1].value;
}
int main() {
    ll m;
    cin >> n >> m;
    for(ll i=0; i < (1<<n); i++)
        cin >> arr[i];
    build();
    while(m--){
        ll pos, val;
        cin >> pos >> val;
        --pos;
        pointUpdate(pos, val);
        cout << tree[1].value << endl;
    }
}


// https://www.youtube.com/watch?v=Nnb3oggeVQc
// https://cses.fi/problemset/task/1735/
