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
vector<vector<float>> rotacija (vector<vector<float>> a, float agol, int oska) {
    agol=agol*M_PI/180;
    if (oska==0) {
        return mnozenje_mca(a,{{1,0,0},{0,cos(agol),-1*sin(agol)},{0,sin(agol),cos(agol)}});
    }
    else if (oska==1) {
        return mnozenje_mca(a,{{cos(agol),0,sin(agol)},{0,1,0},{-1*sin(agol),0,cos(agol)}});
    }
    else return mnozenje_mca(a,{{cos(agol),-1*sin(agol),0},{sin(agol),cos(agol),0},{0,0,1}});
    
}
pair<float, float> skaliranje (pair<float,float> a, float skalar) {
    vector<vector<float>> a1={{a.first},{a.second}};
    vector <vector<float>> b={{skalar,0},{0,skalar}};
    vector<vector<float>> c=mnozenje_mca(b,a1);
    return {c[0][0],c[1][0]};
}


int main () {
    float a,b,c;
    cin>>a>>b>>c;
    vector<vector<float>> x={{a},{b},{c}};
    vector<vector<float>> d=rotacija(x,90,0);
    for (int i=0; i<d.size(); i++) {
        for (int j=0; j<d[i].size(); j++) {
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }

}