#include <bits/stdc++.h>
using namespace std;

int hitungTrip(int jumlahBarang, int kapasitas);
int hitungLangkah(int target, int cap);

int main() {
    int k, n, m;
    cout << "Masukkan beban maksimal: ";
    cin >> k;
    cout << "Masukkan jumlah barang pada kotak 1: ";
    cin >> n;
    cout << "Masukkan jumlah barang pada kotak 2: ";
    cin >> m;

    if (n % 3 == 0 && m % 3 == 0) {
        int cap2 = k / 2;
        int cap1 = k;
        if ((n > 0 && cap2 == 0) || (m > 0 && cap1 == 0)) {
            cout << -1 << endl;
            return 0;
        }
        int totalLangkah = hitungLangkah(n / 3, cap2) + hitungLangkah(m / 3, cap1);
        cout << totalLangkah << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}

int hitungTrip(int jumlahBarang, int kapasitas) {
    if (jumlahBarang <= 0) {
        return 0;
    }
    int trip = 0;
    int barang = jumlahBarang;
    while (barang > 0) {
        barang = barang - kapasitas; 
        trip++;                     
    }
    return trip;
}

int hitungLangkah(int target, int cap) {
    if (target == 0) {
        return 0;
    }
    int tripA = hitungTrip(target, cap);
    int tripB = hitungTrip(target, cap);
    int langkahTerpisah = (tripA + tripB) * 2;
    if (cap >= 2) {
        int bawaA = min(target, cap - 1);
        int bawaB = min(target, cap - bawaA);
        int sisaA = target - bawaA;
        int sisaB = target - bawaB;
        int tripSisaA = hitungTrip(sisaA, cap);
        int tripSisaB = hitungTrip(sisaB, cap);
        int langkahGabung = 3 + (tripSisaA + tripSisaB) * 2;
        if (langkahGabung < langkahTerpisah) {
            return langkahGabung;
        }
    }
    return langkahTerpisah;
}

