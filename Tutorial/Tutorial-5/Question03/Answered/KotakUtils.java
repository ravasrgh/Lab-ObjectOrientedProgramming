public class KotakUtils {

    // Upper-bounded wildcard: membaca dari Kotak yang berisi subtype Barang apapun
    public static void tampilkanSemua(Kotak<? extends Barang> kotak) {
        // TODO: implementasi
        // Cetak info() setiap item, satu per baris
        // Jika kosong, cetak "Kotak kosong"
        if (kotak.kosong()) {
            System.out.println("Kotak kosong");
            return;
        }
        for (int i = 0; i < kotak.jumlah(); i++) {
            System.out.println(kotak.lihat(i).info());
        }
    }

    // Upper-bounded wildcard: menghitung total harga
    public static int totalHarga(Kotak<? extends Barang> kotak) {
        // TODO: implementasi
        int total = 0;
        for (int i = 0; i < kotak.jumlah(); i++) {
            total += kotak.lihat(i).getHarga();
        }
        return total;
    }

    // Upper-bounded wildcard: mencari item termahal
    public static Barang termahal(Kotak<? extends Barang> kotak) {
        // TODO: implementasi
        // Kembalikan null jika kosong
        if (kotak.kosong()) return null;
        Barang max = kotak.lihat(0);
        for (int i = 1; i < kotak.jumlah(); i++) {
            if (kotak.lihat(i).getHarga() > max.getHarga()) {
                max = kotak.lihat(i);
            }
        }
        return max;
    }

    // Bounded wildcard dengan type parameter (PECS: Producer Extends, Consumer Super)
    // src menggunakan ? extends T (producer/pembaca), item diambil dari src
    // dst menggunakan ? super T (consumer/penulis), item ditambahkan ke dst
    public static <T extends Barang> int pindahkan(Kotak<? extends T> src, Kotak<? super T> dst) {
        // TODO: implementasi
        // Pindahkan item dari src ke dst secara LIFO
        // Berhenti jika src kosong atau dst penuh
        // Kembalikan jumlah item yang dipindahkan
        int count = 0;
        while (!src.kosong() && !dst.penuh()) {
            dst.tambah(src.ambil());
            count++;
        }
        return count;
    }

    // Unbounded wildcard: hanya perlu menghitung jumlah
    public static int hitungItem(Kotak<?> kotak) {
        // TODO: implementasi
        return kotak.jumlah();
    }
}
