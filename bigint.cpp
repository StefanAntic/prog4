#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class GolemBroj {
    vector <int> broj;
public:
    GolemBroj (string a="0") {
        for (int i=a.length()-1; i>-1; i--) {
            this->broj.push_back(a[i]-'0');
        }
    }
    GolemBroj (const GolemBroj &a) {
        for (int i=0; i<a.broj.size(); i++) {
            this->broj.push_back(a.broj[i]);
        }
    }
    void print () {
        for (int i=broj.size()-1; i>-1; i--) {
            cout<<broj[i];
        }
    }
    bool sporedi (const GolemBroj &b) const {
        if (this->broj.size()>b.broj.size()) { return true; }
        else if (this->broj.size()<b.broj.size()) { return false; }
        else {
            for (int i=this->broj.size()-1; i>-1; i--) {
                if (this->broj[i]>b.broj[i]) { return true; }
                else if (this->broj[i]<b.broj[i]) { return false; }
            }
        }
        return true;
    }
    void dodadi (int b) {
        this->broj.push_back(0);
        this->broj[0]=this->broj[0]+b;
        for (int i=0; i<this->broj.size(); i++) {
            if (this->broj[i]<10) { break; }
            this->broj[i+1]=this->broj[i+1]+this->broj[i]/10;
            this->broj[i]=this->broj[i]%10; 
        }
        if (this->broj[this->broj.size()-1]==0) { this->broj.pop_back(); }
    }
    GolemBroj mnozi (int b) {
        GolemBroj tmp=*this;
        tmp.broj.push_back(0);
        int br=0;
        for (int i=0; i<tmp.broj.size(); i++) {
            tmp.broj[i]=tmp.broj[i]*b+br;
            if (tmp.broj[i]>9) {
                br=tmp.broj[i]/10;
                tmp.broj[i]=tmp.broj[i]%10;
            }
        }
        if (tmp.broj[tmp.broj.size()-1]==0) { tmp.broj.pop_back(); }
        return tmp;
    }
    GolemBroj operator+(const GolemBroj &b) {
        GolemBroj tmp,tmp1;
        if (this->broj.size()>=b.broj.size()) {
            tmp=*this;
            tmp1=b;
        }
        else {
            tmp=b;
            tmp1=*this;
        }
        int br=tmp.broj.size();
        tmp.broj.push_back(0);
        while (tmp1.broj.size()!=tmp.broj.size()) {
            tmp1.broj.push_back(0);
        }
        for (int i=0; i<br; i++) {
            tmp.broj[i]=tmp.broj[i]+tmp1.broj[i];
            if (tmp.broj[i]>9) {
                tmp.broj[i+1]=tmp.broj[i+1]+tmp.broj[i]/10;
                tmp.broj[i]=tmp.broj[i]%10;
            }
        }
        if (tmp.broj[tmp.broj.size()-1]==0) { tmp.broj.pop_back(); }
        return tmp;
    }
    GolemBroj operator-( GolemBroj b) {
        GolemBroj tmp=*this;
        while (tmp.broj.size()>b.broj.size()) { b.broj.push_back(0); }
        int pozajmuva=0;
        for (int i=0; i<tmp.broj.size(); i++) {
            tmp.broj[i]=tmp.broj[i]-b.broj[i]-pozajmuva;
            if (tmp.broj[i]<0) {
                tmp.broj[i]=tmp.broj[i]+10;
                pozajmuva=1;
            }
            else pozajmuva=0;
        }
        while (tmp.broj[tmp.broj.size()-1]==0) {
            tmp.broj.pop_back();
        }
        return tmp;
    }
    GolemBroj operator*(GolemBroj b) {
        GolemBroj tmp;
        while (tmp.broj.size()<this->broj.size()+b.broj.size()) {
            tmp.broj.push_back(0);
        }
        for (int i=0; i<this->broj.size(); i++) {
            for (int j=0; j<b.broj.size(); j++) {
                tmp.broj[i+j]=tmp.broj[i+j]+this->broj[i]*b.broj[j];
                if (tmp.broj[i+j]>9) {
                    tmp.broj[i+j+1]=tmp.broj[i+j+1]+tmp.broj[i+j]/10;
                    tmp.broj[i+j]=tmp.broj[i+j]%10;
                }
            }
        }
        while (tmp.broj[tmp.broj.size()-1]==0) { tmp.broj.pop_back(); }
        return tmp;
    }
    GolemBroj operator/(GolemBroj b) {
        GolemBroj tmp,tmp1,ostatok;
        tmp1.broj.clear();
        GolemBroj deset("10");
        for (int i=this->broj.size()-1; i>-1; i--) {
            ostatok=deset*ostatok;
            ostatok.dodadi(this->broj[i]);
            int j=0;
            if (ostatok.sporedi(b)) {
                j=1;
                while (b.mnozi(j).sporedi(ostatok)==false && j<10) {
                    j++;
                }
                j--;
            }
            tmp.broj.push_back(j);
            ostatok=ostatok-b.mnozi(j);
        }
        for (int i=tmp.broj.size()-1; i>-1; i--) {
            tmp1.broj.push_back(tmp.broj[i]);
        }
        while (tmp1.broj[tmp1.broj.size()-1]==0) { tmp1.broj.pop_back(); }
        return tmp1;
    }
    GolemBroj operator%(GolemBroj b) {
        GolemBroj tmp,tmp1,ostatok;
        tmp1.broj.clear();
        GolemBroj deset("10");
        for (int i=this->broj.size()-1; i>-1; i--) {
            ostatok=deset*ostatok;
            ostatok.dodadi(this->broj[i]);
            int j=0;
            if (ostatok.sporedi(b)) {
                j=1;
                while (b.mnozi(j).sporedi(ostatok)==false && j<10) {
                    j++;
                }
                j--;
            }
            tmp.broj.push_back(j);
            ostatok=ostatok-b.mnozi(j);
        }
        return ostatok;
    }
};


int main() {
    
}