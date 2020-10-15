struct Trie{
    int MX, f, w;
    vector<int> wt;
    vector<vector<pair<int, char> > > v;
    vector<bool> leaf;

    Trie(){
        MX = 2e6 + 6, f = 0;
        wt.resize(MX, 0);
        leaf.resize(MX, 0);
        v.resize(MX);
    }

    int insChar(char ch, int r, bool k){
        int idx = -1;
        for(auto p : v[r]) if(p.ss == ch) idx = p.ff;
        if(idx == -1) v[r].pb(++f, ch), idx = f;
        leaf[idx] = leaf[idx] || k;
        wt[idx] = max(wt[idx], w);
        return idx;
    }

    void insert(string &s){
        int root = 0; bool k = 0;
        rep(i, 0, s.size()){
            char ch = s[i];
            if(i == s.size() - 1) k = 1;
            root = insChar(ch, root, k);
        }
    }

    int chkChar(char ch, int r){
        int idx = -1;
        for(auto p : v[r]) if(p.ss == ch) idx = p.ff;
        return idx;
    }

    int compare(string &s){
        int root = 0;
        rep(i, 0, s.size()){
            char ch = s[i];
            root = chkChar(ch, root);
            if(root == -1) break;
        }
        if(root == -1) return -1;
        else return wt[root];
    }
};


//trie with unordered_map
//agrawal117
//chahatagrawal117
#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
typedef long long int ll;
using namespace std;
#define MAX 100005
struct trie
{
    unordered_map<char,trie*> child;
    bool is_end;
    trie()
    {
        is_end=false;
    }
};
struct trie *root;
void insert(string s)
{
    struct trie *curr=root;
    for(auto ch: s)
    {
        if(!(curr->child.count(ch))){
            curr->child[ch]=new trie;
        }
        curr=curr->child[ch];
    }
    curr->is_end=true;
}
bool search(string s)
{
    struct trie *curr=root;
    for(auto ch: s)
    {
        if(!(curr->child.count(ch))) return false;
        curr=curr->child[ch];
    }
    return curr->is_end;
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        root=new trie;
        ll n; cin>>n;
        for(int i=1;i<=n;i++){
            string s; cin>>s;
            insert(s);
        }
        // ll q; cin>>q;
        ll q; q=1;
        while(q--)
        {
            string s; cin>>s;
            if(search(s)) cout<<"1"<<endl;
            else cout<<0<<endl;
        }
    }
    
}
