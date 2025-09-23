#include <iostream>
#include <vector>

using namespace std;

int pat (vector <pair <int, int> > a, int b) {
    for (pair<int, int> i : a) {
        if (i.first==b) {
            return i.second;
        }
    }
    return 1000000; 
}
int find (vector <pair <int, int> > a, int b) {
    for (int i=0; i<a.size(); i++) {
        if (a[i].first==b) { return i; }
    }
    return -1;
}

int main () {
    int v,e;
    cin>>v>>e;
    vector< vector <pair< int, int> > > a(v);
    for (int i=0; i<e; i++) {
        int tmp, tmp1, tmp2;
        cin>>tmp>>tmp1>>tmp2;
        a[tmp].push_back({tmp1,tmp2});
    }
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<v; j++) {
            if (pat(a[j],i)!=1000000) {
                int br=pat(a[j],i);
                for (int k=0; k<v; k++) {
                    if (br+pat(a[i],k)<pat(a[j],k)) { 
                        if (pat(a[j],k)==1000000) { a[j].push_back({k,br+pat(a[i],k)}); } 
                        else a[j][find(a[j],k)].second=br+pat(a[i],k);
                    }
                }
            }
        }
    }
    for (int i=0; i<v; i++) {
        for (int j=0; j<v; j++) {
            if (i!=a[i][j].first) {
                cout<<i<<"->"<<a[i][j].first<<"("<<a[i][j].second<<"), ";
            }
        }
        cout<<endl;
    }
    return 0;
}