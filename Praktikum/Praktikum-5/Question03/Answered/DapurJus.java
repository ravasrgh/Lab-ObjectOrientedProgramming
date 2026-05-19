import java.util.List;

public class DapurJus {

    private DapurJus() {
        // Private constructor to prevent instantiation of utility class
    }

    public static void cekBahan(List<? extends Buah> daftarBahan) {
        for (Buah b : daftarBahan) {
            System.out.println(b.deskripsi());
        }
    }

    public static int hitungTotalManis(List<? extends Buah> daftarBahan) {
        int total = 0;
        for (Buah b : daftarBahan) {
            total += b.getTingkatManis();
        }
        return total;
    }

    public static void buatJusApelDefault(List<? super JusApel> daftarMinuman) {
        daftarMinuman.add(new JusApel("Jus Apel Original"));
        daftarMinuman.add(new JusApel("Jus Apel Madu"));
    }

    public static void cetakRakUmum(List<?> rak) {
        for (Object o : rak) {
            System.out.println(o);
        }
    }
}
