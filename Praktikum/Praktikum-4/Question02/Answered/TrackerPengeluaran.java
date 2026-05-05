public class TrackerPengeluaran {
    private Catatan[][] matriks;

    public TrackerPengeluaran() {
        matriks = new Catatan[4][3];
    }

    public void setCatatan(int minggu, int kategori, int nominal, String deskripsi) {
        if (minggu >= 1 && minggu <= 4 && kategori >= 0 && kategori <= 2) {
            matriks[minggu - 1][kategori] = new Catatan(nominal, deskripsi);
        } else {
            System.out.println("Indeks tidak valid!");
        }
    }
    
    public int totalPerMinggu(int minggu) {
        if (minggu >= 1 && minggu <= 4) {
            int total = 0;
            for (int k = 0; k < 3; k++) {
                if (matriks[minggu - 1][k] != null) {
                    total += matriks[minggu - 1][k].getNominal();
                }
            }
            return total;
        }
        return 0;
    }

    public void cetakLaporan() {
        System.out.println("Minggu\tMakan\t\t\tTransportasi\t\t\tTugas");
        for (int m = 0; m < 4; m++) {
            System.out.print((m + 1) + "\t");
            for (int k = 0; k < 3; k++) {
                if (matriks[m][k] != null) {
                    System.out.print(matriks[m][k].getNominal() + " (" + matriks[m][k].getDeskripsi() + ")\t");
                } else {
                    System.out.print("Kosong\t\t\t");
                }
            }
            System.out.println();
        }
    }
}