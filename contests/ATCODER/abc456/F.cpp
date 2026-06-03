#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#define forn(i, n) for (int i = 0; i < n; ++i)
#define for1(i, n) for (int i = 1; i <= n; ++i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)x.size()
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define mod 1000000007
#define inf 1e18


class Node{
    public:
        ll dp[2][2];
        bool id;

        Node(){
            id=false;
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    dp[i][j]=inf;
                }
            }
        }

        Node(int d){
            id= true;
        }


        Node operator+(const Node &other) const {
            if(id) return other;
            if(other.id) return *this;

            Node res;
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    for(int k=0;k<2;k++){
                        for(int l=0;l<2;l++){
                            if(j==0 && k==0 ) continue;
                            res.dp[i][l] = min(res.dp[i][l], dp[i][j] + other.dp[k][l]);
                        }
                    }
                }
            }
            return res;
        }

};





template<typename segT>
class SegementTree{
private:
    int n;
    vector<segT> tree;

    // lc rc
    segT merge(segT leftC,segT rightC){
        return leftC+rightC;
    }

    // 0., -inf =min +inf=max
    segT identity(){
        return segT(1);
    }


    void build(int node,int s,int e,const vector<segT> &arr){
        if(s==e){
            tree[node]=arr[s];
            return;
        }
        int mid = s+(e-s)/2;
        build(2*node,s,mid,arr);
        build(2*node+1,mid+1,e,arr);
        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }


    void update(int node,int s,int e,int idx,segT val){
        if(s==e){
            tree[node]=val;
            return;
        }
        int mid = s+(e-s)/2;
        if(idx<=mid) update(2*node,s,mid,idx,val);
        else update(2*node+1,mid+1,e,idx,val);
        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }

    segT query(int node,int s,int e,int l,int r){
        if(r<s || e<l) return identity();
        if(l<=s && e<=r) return tree[node];
        int mid = s+(e-s)/2;
        segT leftC = query(2*node,s,mid,l,r);
        segT rightC = query(2*node+1,mid+1,e,l,r);
        return merge(leftC,rightC);
    }
public:
    SegementTree(const vector<segT> &arr){
        n=arr.size();
        tree.resize(4*n,identity());
        if(n>0) build(1,0,n-1,arr);    
    }


    void update(int idx,segT val){
        update(1,0,n-1,idx,val);
    }

    segT query(int l,int r){
        return query(1,0,n-1,l,r);
    }

};

void solve() {
    int n,k;
    cin>>n>>k;
    vi a(n);
    forn(i,n) cin>>a[i];

    vector<Node> N(n);
    forn(i,n){
        N[i].dp[1][1]=a[i];
        N[i].dp[0][0]=0;
    }

    SegementTree<Node> ST(N);

    ll ans=inf;
    for(int i=0;i<k;i++){
        Node res=ST.query(i,i+k-1);
        ans=min(ans,res.dp[1][1]);
    }

    for(int i=0;i<=n-k-1;i++){
        Node res=ST.query(i,i+k);
        ans=min(ans,res.dp[1][1]);
    }

    cout<<ans<<endl;




    
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    cin>>test;
    
    while (test--) {
        solve();
    }
    return 0;
}