#include<bits/stdc++.h>

using namespace std;//galti

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    map<pair<string,string>,int> m;
    map<pair<string,string>,int>::iterator it,it1,it2;
    vector<int> v;
    string a;
    string b;
    int x;
    for(int i=0;i<t;i++)
    {
        cin >>a >>b >>x;
        pair<string,string> p(a,b);
        m[p]=x;
    }
    it=m.begin();
    for( ;it!=m.end();it++)
    {
        if (++it == m.end())
            break;
        it++
        string s1=((*it).first).first;
        string s2=((*it).first).second;
        for(it2=it;it2!=m.end();it2++)
        {
            if(it2==it) {
                it2++;
            }
            string s3=((*it2).first).first;
            string s4=((*it2).first).second;
            if(s1==s3)
            {
                v.push_back((*it).second+(*it2).second);
            }
            if(s1==s4)
            {
                v.push_back((*it).second+(*it2).second);
            }
            if(s2==s3)
            {
                v.push_back((*it).second+(*it2).second);
            }
            if(s2==s4)
            {
                v.push_back((*it).second+(*it2).second);
            }
        }
    }
    for(int i=0;i<v.size();i++)
        {
            if(v[0]<v[i])
            v[0]=v[i];
            
        }
        cout<< v[0] << endl;
}
//lad chato mera
