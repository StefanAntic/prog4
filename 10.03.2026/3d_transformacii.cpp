#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

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
}/*
pair<float, float> Translacija (pair<float,float> a, float x1, float y1) {
    vector<vector<float>> a1={{a.first},{a.second},{1}};
    vector <vector<float>> b={{1,0,x1},{0,1,y1},{0,0,1}};
    vector<vector<float>> c=mnozenje_mca(b,a1);
    return {c[0][0],c[1][0]};
}*/
vector<vector<float>> rotacija (vector<vector<float>> a, float agol, int oska) {
    agol=agol*M_PI/180;
    if (oska==0) {
        return mnozenje_mca({{1,0,0},{0,cos(agol),-sin(agol)},{0,sin(agol),cos(agol)}},a);
    }
    else if (oska==1) {
        return mnozenje_mca({{cos(agol),sin(agol),0},{-sin(agol),cos(agol),0},{0,0,1}},a);
    }
    else return mnozenje_mca({{cos(agol),0,sin(agol)},{0,1,0},{-1*sin(agol),0,cos(agol)}},a);   
}
vector<vector<float>> skaliranje (vector<vector<float>> a, float skalar, int oska) {
    if (oska==0) {
        return mnozenje_mca({{skalar,0,0},{0,1,0},{0,0,1}},a);
    }
    else if (oska==1) {
       return mnozenje_mca({{1,0,0},{0,skalar,0},{0,0,1}},a); 
    }
    else return mnozenje_mca({{1,0,0},{0,1,0},{0,0,skalar}},a);
}


int main () {
    ifstream file("monkey.obj");
    string line;
    while (getline(file,line)) {
        if(line[0]=='v' && line[1]==' ') {
            stringstream ss(line);
            char v;
            float x,y,z;
            ss>>v>>x>>y>>z;
            vector<vector<float>> a= {{x},{y},{z}};
            vector<vector<float>> rez=rotacija(a,45,0);
            rez=rotacija(rez,27,1);
            rez=rotacija(rez,10,2);
            rez=skaliranje(rez,1.5,0);
            rez=skaliranje(rez,-1,1);
            cout<<"v "<<rez[0][0]<<" "<<rez[1][0]<<" "<<rez[2][0]<<endl;
        }
    }

}