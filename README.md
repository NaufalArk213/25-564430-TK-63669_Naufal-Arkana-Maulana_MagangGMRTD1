# Penjelasan Solusi Studi Kasus GMRT (Day 1)

Berikut adalah penjelasan singkat mengenai logika dan cara kerja dari program yang telah dibuat untuk menyelesaikan Problem 1 dan Problem 2.

---

### Problem 1: Penyeimbangan Barang antar Kotak
Di problem ini, tugas robot adalah memindahkan barang 2 kg dan 1 kg ke 3 kotak penyimpanan agar jumlah barang dan total berat di tiap kotak menjadi sama persis.

**Logika Penyelesaian:**
- Pertama, dicek dulu apakah jumlah barang 2 kg (`n`) dan 1 kg (`m`) masing-masing habis dibagi 3. Jika tidak, kondisi seimbang tidak mungkin dicapai sehingga program langsung mengeluarkan `-1`.
- Jika bisa dibagi 3, program menghitung langkah pengangkutan robot ke dua kotak tujuan.
- Supaya langkahnya minimal, program membandingkan dua opsi pengangkatan: pengiriman terpisah (bolak-balik per kotak) dan pengiriman digabung (sekali angkut membawa barang untuk dua kotak sekaligus jika kapasitas robot cukup). Opsi dengan jumlah langkah paling sedikit yang akan dipilih.

---

### Problem 2: Manajemen Energi Baterai Robot
Problem ini meminta robot menyelesaikan misi sebanyak mungkin secara berurutan dengan batas kapasitas baterai dan kuota *charging* tertentu.

**Logika Penyelesaian:**
- Misi diproses satu per satu secara berurutan dari awal sampai akhir.
- Strateginya adalah **menunda isi daya**: robot hanya akan *charging* saat energi baterai yang tersisa kurang dari kebutuhan misi yang mau dijalankan. Ini dilakukan agar kuota *charging* tidak cepat habis dan energi baterai tidak terbuang sia-sia karena terbentur kapasitas maksimum (`C`).
- Jika baterai sudah di-charge sampai maksimal tetapi masih tidak cukup untuk misi tersebut, perulangan langsung berhenti dan program menampilkan total misi yang berhasil diselesaikan.
