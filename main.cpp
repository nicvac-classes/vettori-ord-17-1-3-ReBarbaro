#include <iostream>
#include <string>
#include <vector>
using namespace std;





int main() {
    srand(time(0));  
    
    int n, p, d, i, j, x, u;

    cout << "quanti numeri devo generare" << endl;
    cin >> n;
    int vp[n];
    int vd[n];

    p = 0;
    d = 0;
    i = 0;
    while (i <= n - 1) {
        x = rand() % (n * 10) + 1;
        if (x % 2 == 0) {
            vp[p] = x;
            p = p + 1;
        } else {
            vd[d] = x;
            d = d + 1;
        }
        i = i + 1;
    }
    int t;
    bool scambio;

    i = 0;
    j = 0;
    scambio = true;
    while (i <= p - 1 && scambio) {
        scambio = false;
        j = 0;
        while (j <= p - 2 - i) {
            if (vp[j] > vp[j + 1]) {
                t = vp[j];
                vp[j] = vp[j + 1];
                vp[j + 1] = t;
                scambio = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    i = 0;
    j = 0;
    scambio = true;
    while (i <= d - 1 && scambio) {
        scambio = false;
        j = 0;
        while (j <= d - 2 - i) {
            if (vd[j] > vd[j + 1]) {
                t = vd[j];
                vd[j] = vd[j + 1];
                vd[j + 1] = t;
                scambio = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    int vu[p + d];

    u = 0;
    i = 0;
    j = 0;
    while (i <= p - 1 && j <= d - 1) {
        if (vp[i] > vd[j]) {
            vu[u] = vp[i];
            i = i + 1;
        } else {
            vu[u] = vd[j];
            j = j + 1;
        }
        u = u + 1;
    }
    while (i <= p - 1) {
        vu[u] = vp[i];
        u = u + 1;
        i = i + 1;
    }
    while (j <= d - 1) {
        vu[u] = vd[j];
        u = u + 1;
        j = j + 1;
    }
    t = 0;
    i = 0;
    j = 0;
    scambio = true;
    while (i <= u - 1 && scambio) {
        scambio = false;
        j = 0;
        while (j <= u - 2 - i) {
            if (vu[j] > vu[j + 1]) {
                t = vu[j];
                vu[j] = vu[j + 1];
                vu[j + 1] = t;
                scambio = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    int valore;

    cout << "quale è il valore da cercare" << endl;
    cin >> valore;
    int inizio, fine, medio, indice;

    indice = (int) (-1);
    inizio = 0;
    fine = n - 1;
    while (inizio <= fine && indice == -1) {
        medio = (int) (inizio + (double) (fine - inizio) / 2);
        if (valore == vu[medio]) {
            indice = medio;
        } else {
            if (valore > vu[medio]) {
                inizio = medio + 1;
            } else {
                fine = medio - 1;
            }
         }
 }
