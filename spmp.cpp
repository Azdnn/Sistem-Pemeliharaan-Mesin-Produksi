#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Pemeliharaan {
    int idMesin;
    string namaMesin, tanggal, keterangan;
};

int main() {
    vector<Pemeliharaan> jadwal;
    int pilihan, id;
    do {
        cout << "\n1. Tambah\n2. Tampilkan\n3. Hapus\n4. Keluar\nPilih: ";
        cin >> pilihan;
        if (pilihan == 1) {
            Pemeliharaan baru;
            cout << "ID Mesin: "; cin >> baru.idMesin; cin.ignore();
            cout << "Nama Mesin: "; getline(cin, baru.namaMesin);
            cout << "Tanggal: "; getline(cin, baru.tanggal);
            cout << "Keterangan: "; getline(cin, baru.keterangan);
            jadwal.push_back(baru);
        }
        else if (pilihan == 2) {
            for (auto& p : jadwal) cout << p.idMesin << " | " << p.namaMesin << " | " << p.tanggal << " | " << p.keterangan << "\n";
        }
        else if (pilihan == 3) {
            cout << "ID Mesin: "; cin >> id;
            auto it = find_if(jadwal.begin(), jadwal.end(), [id](const Pemeliharaan& p) { return p.idMesin == id; });
            if (it != jadwal.end()) { jadwal.erase(it); cout << "Jadwal dihapus.\n"; }
            else cout << "ID tidak ditemukan.\n";
        }
    } while (pilihan != 4);
    return 0;
}
