#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<vector <float> > mnozenje_mca (vector<vector<float>> a, vector<vector<float>> b) {
    vector<vector<float>> rez(a.size(), vector<float>(b[0].size(),0));
    for (int i=0; i<rez.size(); i++) {
        for (int j=0; j<rez[0].size(); j++) {
            float br=0;
            for (int k=0; k<a[0].size(); k++) {
                br+=a[i][k]*b[k][j];
            }
            rez[i][j]=br;
        }
    }
    return rez;
}
pair<float, float> Translacija (pair<float,float> a, float x1, float y1) {
    vector<vector<float>> a1={{a.first},{a.second},{1}};
    vector <vector<float>> b={{1,0,x1},{0,1,y1},{0,0,1}};
    vector<vector<float>> c=mnozenje_mca(b,a1);
    return {c[0][0],c[1][0]};
}
pair<float, float> rotacija (pair<float,float> a, float agol) {
    vector<vector<float>> a1={{a.first},{a.second}};
    vector <vector<float>> b={{cos(agol), -sin(agol)},{sin(agol),cos(agol)}};
    vector<vector<float>> c=mnozenje_mca(b,a1);
    return {c[0][0],c[1][0]};
}
pair<float, float> skaliranje (pair<float,float> a, float skalar) {
    vector<vector<float>> a1={{a.first},{a.second}};
    vector <vector<float>> b={{skalar,0},{0,skalar}};
    vector<vector<float>> c=mnozenje_mca(b,a1);
    return {c[0][0],c[1][0]};
}


int main () {
    float a,b;
    cin>>a>>b;
    pair<float, float> c=Translacija({a,b}, 2,2);
    cout<<c.first<<" "<<c.second<<endl;
    pair<float,float> d=rotacija (c,M_PI/2);
    cout<<d.first<<" "<<d.second<<endl;
    pair<float,float> e=skaliranje(d,2);
    cout<<e.first<<" "<<e.second<<endl;
}