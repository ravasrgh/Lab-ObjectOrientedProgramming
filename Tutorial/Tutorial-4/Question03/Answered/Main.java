import java.util.Scanner;
import java.util.Locale;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) {
            sc.close();
            return;
        }
        int n = sc.nextInt();

        Courier[] couriers = new Courier[n];
        String[] items = new String[n];

        int sumSpeed = 0;
        boolean isFast = false;

        for (int i = 0; i < n; i++) {
            String type = sc.next();
            String name = sc.next();
            int speed = sc.nextInt();
            String item = sc.nextLine().trim();

            if (type.equals("B")) {
                couriers[i] = new BikeCourier(name, speed);
            } else if (type.equals("C")) {
                couriers[i] = new CarCourier(name, speed);
            }

            items[i] = item;
            sumSpeed += speed;
            if (speed > 40) {
                isFast = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (couriers[i] != null) {
                System.out.println(couriers[i].toString());
                System.out.println(couriers[i].deliver(items[i]));
            }
        }

        double averageSpeed = 0.0;
        if (n > 0) {
            averageSpeed = (double) sumSpeed / n;
        }

        System.out.printf(Locale.US, "Average speed: %.2f\n", averageSpeed);
        System.out.println("Fast? " + isFast);

        sc.close();
    }
}