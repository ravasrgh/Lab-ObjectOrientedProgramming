import java.util.ArrayList;

public class Kotak<T extends Barang> {
    private ArrayList<T> items;
    private int kapasitas;

    public Kotak(int kapasitas) {
        // TODO: implementasi
        this.kapasitas = kapasitas;
        this.items = new ArrayList<>();
    }

    public boolean tambah(T item) {
        // TODO: implementasi
        if (penuh()) return false;
        items.add(item);
        return true;
    }

    public T ambil() {
        // TODO: implementasi (LIFO - ambil item terakhir)
        if (kosong()) return null;
        return items.remove(items.size() - 1);
    }

    public T lihat(int index) {
        // TODO: implementasi
        if (index < 0 || index >= items.size()) return null;
        return items.get(index);
    }

    public int jumlah() {
        // TODO: implementasi
        return items.size();
    }

    public int kapasitas() {
        // TODO: implementasi
        return kapasitas;
    }

    public boolean penuh() {
        // TODO: implementasi
        return items.size() == kapasitas;
    }

    public boolean kosong() {
        // TODO: implementasi
        return items.isEmpty();
    }
}
