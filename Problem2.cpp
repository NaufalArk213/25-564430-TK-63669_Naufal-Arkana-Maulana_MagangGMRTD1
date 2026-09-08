#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, C, R, K;

    cout << "Masukkan jumlah misi (n): ";
    cin >> n;

    cout << "Masukkan kapasitas maksimum baterai (C): ";
    cin >> C;

    cout << "Masukkan penambahan energi sekali charge (R): ";
    cin >> R;

    cout << "Masukkan batas maksimal kali charge (K): ";
    cin >> K;

    int baterai = C;
    int k_sisa = K;
    int misi_selesai = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cout << "Kebutuhan energi misi ke-" << (i + 1) << ": ";
        cin >> x; 

        // Charging jika baterai kurang dan masih ada sisa kuota K
        while (baterai < x && k_sisa > 0) {
            baterai += R;
            if (baterai > C) {
                baterai = C; // Baterai maksimal sebatas kapasitas C
            }
            k_sisa--;
        }

        // Jalankan misi jika baterai mencukupi
        if (baterai >= x) {
            baterai -= x;
            misi_selesai++;
        } else {
            // Berhenti jika baterai tidak cukup
            cout << "Baterai tidak cukup untuk melanjutkan misi ke-" << (i + 1) << "!" << endl;
            break;
        }
    }

    cout << "\nJumlah maksimum misi yang berhasil diselesaikan: " << misi_selesai << endl;

    return 0;
}
