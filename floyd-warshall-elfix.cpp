#include <iostream>
#include <vector>

using namespace std;

int main() {
    int v,e;
    cin>>v>>e;
    vector<int> a(v*v, 1000000);
    for (int i=0; i<v; i++) {
        a[i*(v+1)]=0;
    }
    for (int i=0; i<e; i++) {
        int tmp,tmp1,tmp2;
        cin>>tmp>>tmp1>>tmp2;
        a[tmp*v+tmp1]=tmp2;
    }
    for (int i=0; i<v; i++) {
        for (int j=0; j<v; j++) {
            for (int k=0; k<v; k++) {
                if (a[j*v+i]!=1000000 && a[j*v+i]+a[i*v+k]<a[j*v+k]) { a[j*v+k]=a[j*v+i]+a[i*v+k]; }
            }
        }
    }
    for (int i=0; i<a.size(); i++) {
        cout<<a[i]<<" ";
        if (i%v==v-1) { cout<<endl; }
    }

    return 0;
}