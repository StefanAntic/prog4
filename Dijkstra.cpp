#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class rebro {
    public:
    int pocetok;
    int tezina;
    int kraj;
    rebro (int a, int b ,int c) : tezina(a),pocetok(b),kraj(c) {}
};

void sort (vector <rebro> &a) {
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<a.size(); j++) {
            if (a[i].tezina>a[j].tezina) {
                rebro tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
}

int main () {
    int n, ulici;
    cin>>n>>ulici;
    int a[n]={0};
    a[0]=1;
    vector<vector<rebro> > drvo;
    vector <rebro> pq;
    vector <int> dp;
    dp.resize(n);
    dp[0]={0};
    drvo.resize(n);
    for (int i=0; i<ulici; i++) {
        int tmp,tmp1,tmp2;
        cin>>tmp>>tmp1>>tmp2;
        drvo[tmp].push_back({tmp2,tmp,tmp1});
        drvo[tmp1].push_back({tmp2,tmp1,tmp});
    }
    for (int i=0; i<drvo[0].size(); i++) {
        pq.push_back(drvo[0][i]);
    }
    sort(pq);
    while (pq.size()!=0) {
        rebro momentalno=pq.back();
        pq.pop_back();
        int dist=momentalno.tezina;
        if (a[momentalno.kraj]==0) {
            dp[momentalno.kraj]=dist;
        }
        else if (dp[momentalno.kraj]>dist) {
            dp[momentalno.kraj]=dist;
        }
        cout<<momentalno.pocetok<<"->"<<momentalno.kraj<<"["<<momentalno.tezina<<"]"<<endl;
        cout<<momentalno.kraj<<"("<<dp[momentalno.kraj]<<")"<<endl;
        if (a[momentalno.kraj]!=1) {
            for (int i=0; i<drvo[momentalno.kraj].size(); i++) {
                rebro tmp(drvo[momentalno.kraj][i].tezina+momentalno.tezina ,drvo[momentalno.kraj][i].pocetok, drvo[momentalno.kraj][i].kraj);
                pq.push_back(tmp);
            }
            a[momentalno.kraj]=1;
        }
        sort(pq);
    }
    for (int i=0; i<dp.size(); i++) {
        cout<<i<<"("<<dp[i]<<")"<<endl;
    }
}