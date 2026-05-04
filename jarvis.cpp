#include <iostream>
#include <vector>

using namespace std;

class tocka {
    public:
    int x;
    int y;
    tocka (int x, int y) : x(x), y(y) {}
};

bool counter (tocka p1, tocka p2, tocka p3) {
    int tmp=(p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
    if ( tmp < 0) { return true; }
    else return false;
}

int main() {
    int n;
    cin>>n;
    vector <tocka> tocki;
    vector <tocka> hull;
    for (int i=0; i<n; i++) {
        int tmp,tmp1;
        cin>>tmp>>tmp1;
        tocki.push_back(tocka(tmp,tmp1));
    }
    int l=0;
    for (int i=0; i<tocki.size(); i++) {
        if (tocki[i].x<tocki[l].x) { l=i; }
    }
    int p=l,q;
    do {
        hull.push_back(tocki[p]);
        q=(p+1)%n;
        for ( int i=0; i<tocki.size(); i++) {
            if (counter(tocki[p],tocki[i],tocki[q])) { q=i; }
        }
        p=q;
    } while (p!=l);

    for (int i=0; i<hull.size(); i++) {
        cout<<"("<<hull[i].x<<","<<hull[i].y<<")"<<endl;
    }

    return 0;
}