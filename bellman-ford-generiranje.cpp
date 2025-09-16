#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class rebro {
    public:
    int pocetok;
    int tezina;
    int kraj;
    rebro (int a, int b ,int c) : pocetok(a),kraj(b),tezina(c) {}
};

int main () {
    srand(time(0));
    int v=rand()%49+2;
    vector<rebro> drvo;
    vector<int> distanci(v,INT_MAX);
    distanci[0]=0;
    for (int i=0; i<v; i++) {
        for (int j=0; j<rand()%9+1; j++) {
            drvo.push_back({i,rand()%v,rand()%101-5});
        }
    }
    /*
    for (int i=0; i<e; i++) {
        int tmp,tmp1,tmp2;
        cin>>tmp>>tmp1>>tmp2;
        drvo.push_back({tmp,tmp1,tmp2});
    }*/
    for (int i=0; i<v; i++) {
        for (int j=0; j<drvo.size(); j++) {
            if (distanci[drvo[j].pocetok]+drvo[j].tezina< distanci[drvo[j].kraj] && distanci[drvo[j].pocetok]!=INT_MAX) {
                if (i==v-1) {
                    cout<<"Negativen ciklus!";
                    return 0;
                }
                else distanci[drvo[j].kraj]=distanci[drvo[j].pocetok]+drvo[j].tezina;
            }
        }
    }
    for (int i=0; i<v; i++) {
        cout<<i<<"("<<distanci[i]<<")"<<endl;
    }
} 