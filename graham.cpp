#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Tocka {
public:
    int x;
    int y;
    Tocka(int x, int y) : x(x), y(y) {}
};

int counter(Tocka p1, Tocka p2, Tocka p3) {
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}

int dist(Tocka a, Tocka b) {
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main() {
    int n;
    cin >> n;
    vector<Tocka> tocki;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tocki.push_back(Tocka(x, y));
    }
    int l = 0;
    for (int i = 1; i < n; i++) {
        if (tocki[i].y < tocki[l].y || (tocki[i].y==tocki[l].y && tocki[i].x < tocki[l].x)) {
            l=i;
        }
    }
    Tocka tmp=tocki[0];
    tocki[0]=tocki[l];
    tocki[l]=tmp;
    Tocka p0 = tocki[0];
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int o=counter(p0, tocki[i], tocki[j]);
            if (o < 0 || (o==0 && dist(p0, tocki[i])>dist(p0, tocki[j]))) {
                Tocka tmp1=tocki[i];
                tocki[i]=tocki[j];
                tocki[j]=tmp1;
            }
        }
    }
    vector<Tocka> hull;
    hull.push_back(tocki[0]);
    hull.push_back(tocki[1]);
    for (int i = 2; i < n; i++) {
        while (hull.size()>=2 && counter(hull[hull.size() - 2], hull[hull.size() - 1], tocki[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(tocki[i]);
    }
    for (Tocka x : hull) {
        cout << "(" << x.x << "," << x.y << ")" << endl;
    }
    return 0;
}