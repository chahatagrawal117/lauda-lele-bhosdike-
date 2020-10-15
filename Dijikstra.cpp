//agrawal117
//chahatagrawal117
#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
typedef long long int ll;
#define MAX 100010
using namespace std;
vector<pair<ll,ll>> v[MAX];
const ll oo=LLONG_MAX ;
ll dis[MAX];
ll trace[MAX];
ll n,m;
bitset<MAX> vis;
void dijkstra()
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> >pq;
    
    for(int i=1;i<=n;i++) dis[i]=oo;
    dis[1]=0;    // taking source node 1
    pq.push({0,1});
    
    while(!pq.empty())
    {
        ll u,du,w,node;
        u=pq.top().second;
        du=pq.top().first;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto i : v[u])
        {
            node=i.second;
            w=i.first;
            if(du+w<dis[node])
            {
                dis[node]=du+w;
                trace[node]=u;
                pq.push({dis[node],node});
            }
        }
    }
}
void _trace(int x)    // printing reverse path
{
    cout<<x<<" ";
    if(x==1){ cout<<endl; return ; }
    _trace(trace[x]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        v[a].push_back({w,b});
        //v[b].push_back({w,a});   // for undirected
    }
    dijkstra();
    for(int i=1;i<=n;i++)
    {
        if(dis[i]!=oo)
        {
            cout<<"The shortest path from 1 to "<<i<<" is: "<<dis[i]<<endl;
            cout<<"And this is the shortest path from "<<i<<" to 1: --> ";
            _trace(i);
        }
        else
        {
            cout<<"There is no shortest path from 1 to "<<i<<endl;
        }

    }
}

