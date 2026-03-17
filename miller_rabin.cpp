#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int stepen (int a, int b, int p){
    int tmp=1;
    for (int i=0; i<b; i++) {
        tmp*=a;
        tmp%=p;
    }
    return tmp;
}

bool miller_rabin (int a) {
    int k=0,m,p=a;
    a-=1;
    while (a%2==0) {
        a=a/2;
        k++;
    }
    m=a;
    for (int j=0; j<10; j++) {
        int x=rand()%(p-4)+2;
        x=stepen(x,m,p);
        if (x==p-1 || x==1) {
            continue;
        }
        bool t=0; 
        for (int i=0; i<k-1; i++) {
            x=x*x%p;
            if (x==p-1) { 
                t=1;
                break;
            }
            else if (x==1) { return false; }
        }
        if (t!=1) { return false; }
    }
    return true;
}

int main () {
    srand(time(NULL));
    int a;
    cin>>a;
    cout<<miller_rabin(a);
    return 0;
}