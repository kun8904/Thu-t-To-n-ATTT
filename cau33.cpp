#include <iostream>
#include <vector>
using namespace std;

void printExp(const vector<int>& poly){
    for (size_t x = 0; x < poly.size(); ++x) {
        cout << poly[x] << "*x^" << x;
        if (x < poly.size() - 1) {
            cout << " + ";
        }
    }
    cout << endl;
}

int degree(const vector<int>& poly){
    int k = 0;
    for(size_t i = 0; i < poly.size(); ++i){
        if (poly[i] == 1) {
            k = i;
        }
    }
    return k;
}

vector<int> XOR(const vector<int>& a, const vector<int>& b){
    vector<int> s(a.size());
    for (size_t x = 0; x < a.size(); ++x){
        s[x] = a[x] ^ b[x];
    }
    return s;
}

vector<int> Nhan(const vector<int>& a, const vector<int>& b){
    vector<int> c(a.size() + b.size() - 1, 0);
    
    for(size_t i = 0; i < a.size(); ++i){
        for(size_t j = 0; j < b.size(); ++j){
            c[i + j] = (c[i + j] + a[i] * b[j]) % 2;
            if(c[i + j] < 0){
                c[i + j] = c[i + j] + 2;
            }
        }
    }
    return c;
}

vector<int> Chia(vector<int>& a, vector<int>& b){
    vector<int> F(a.size());
    vector<int> M(a.size() - degree(b) + 1);
    vector<int> K = a;
    vector<int> H(a.size());
    vector<int> E(a.size());
    E[0] = 1;
    
    if(degree(a) < degree(b)){
        return H;
    }
    
    if(degree(a) == degree(b)){
        return E;
    }
    
    if(degree(b) == 0){
        return a;
    }
    
    while(degree(K) >= degree(b)){
        fill(F.begin(), F.end(), 0);
        
        for(size_t i = 0; i < b.size(); ++i){
            if(b[i] == 1){
                F[i + degree(K) - degree(b)] = 1;
            }
        }
        
        M[degree(K) - degree(b)] = 1;
        
        for(size_t i = 0; i < K.size(); ++i){
            if (F[i] != K[i]){
                K[i] = 1;
            }else{
                K[i] = 0;
            }
        }
    }
    
    return M;
}

vector<int> euclide(vector<int>& a, vector<int>& b){
    int s = 0;
    vector<int> d(5);
    vector<int> x(5);
    vector<int> y(5);
    vector<int> x1(5);
    vector<int> y1(5);
    vector<int> x2(5);
    vector<int> y2(5);
    vector<int> q(5);
    vector<int> r(5);
    
    for (size_t i = 0; i < b.size(); ++i){
        if(b[i] != 0){
            s++;
        }
    }
    
    if(s == 0){
        d = a;
        x[0] = 1;
        return x;
    }
    
    x2[0] = 1;
    x1[0] = 0;
    y2[0] = 0;
    y1[0] = 1;
    bool all = false;
    
    while (all == false){
        q = Chia(a, b);
        r = XOR(a, Nhan(q, b));
        x = XOR(x2, Nhan(q, x1));
        y = XOR(y2, Nhan(q, y1));
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
        
        all = true;
        
        for (size_t i=0; i<b.size(); ++i){
            if(b[i] != 0){
                all = false;
                break;
            }
        }
    }
    
    d = a;
    x = x2;
    y = y2;
    return y;
}

int main() {
    vector<int> a = {1, 0, 1, 1};
    vector<int> g = {0, 1, 1, 1};
    vector<int> x = euclide(a,g);

    cout << "Inverse of a modulo g: ";
    printExp(x);

    return 0;
}