public class Laci<T> {
    private String label;
    private T[] items;
    private int size;
    private static final int CAPACITY = 10;

    @SuppressWarnings("unchecked")
    public Laci(String label) {
        this.label = label;
        this.items = (T[]) new Object[CAPACITY];
        this.size = 0;
    }

    public boolean simpan(T item) {
        if (size >= CAPACITY) {
            return false;
        }
        items[size++] = item;
        return true;
    }

    public T ambil(int i) {
        if (i < 1 || i > size) {
            return null;
        }
        return items[i - 1];
    }

    public void set(int i, T item) {
        if (i < 1 || i > size) {
            return;
        }
        items[i - 1] = item;
    }

    public int ukuran() {
        return size;
    }

    public String getLabel() {
        return label;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Laci[").append(label).append("]: [");
        for (int i = 0; i < size; i++) {
            sb.append(items[i]);
            if (i < size - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }
}
