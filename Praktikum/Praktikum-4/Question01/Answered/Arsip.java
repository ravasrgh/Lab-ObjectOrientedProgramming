public class Arsip {
    private Pesan[] pesans;
    private int count;

    public Arsip() {
        pesans = new Pesan[100];
        count = 0;
    }

    public void tambah(Pesan p) {
        if (count < 100) {
            pesans[count] = p;
            count++;
        }
    }

    public Pesan get(int idx) {
        if (idx >= 1 && idx <= count) {
            return pesans[idx - 1];
        }
        return null;
    }

    public int cari(String keyword) {
        int found = 0;
        String lowerKeyword = keyword.toLowerCase();
        for (int i = 0; i < count; i++) {
            if (pesans[i].getKonten().toLowerCase().contains(lowerKeyword)) {
                found++;
            }
        }
        return found;
    }

    public int jumlah() {
        return count;
    }
}
