#include <iostream>
#include <vector>

using namespace std;

int main () {
    int v,e;
    cin>>v>>e;
    vector<vector <int> > a(v, vector<int> (v, 1000000));
    for (int i=0 ;i<e; i++) {
        int tmp,tmp1,tmp2;
        cin>>tmp>>tmp1>>tmp2;
        a[tmp][tmp1]=tmp2;
    }
    for (int i=0 ;i<v; i++) { a[i][i]=0; }
    for (int i=0; i<v; i++) {
        for (int j=0; j<v; j++) {
            for (int k=0; k<v; k++) {
                if (a[j][k]>a[j][i]+a[i][k]) { a[j][k]=a[j][i]+a[i][k]; }
            }
        }
    }
    for (int i=0; i<v; i++) {
        for (int j=0; j<v; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}