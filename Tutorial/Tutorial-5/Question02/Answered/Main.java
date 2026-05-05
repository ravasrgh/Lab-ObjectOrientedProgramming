import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String endpoint1 = sc.nextLine();
        String payload1 = sc.nextLine();
        int statusCode1 = Integer.parseInt(sc.nextLine());
        String message1 = sc.nextLine();
        int responseData1 = Integer.parseInt(sc.nextLine());

        APIRequest<String> req1 = new APIRequest<>(endpoint1, payload1);
        APIResponse<Integer> res1 = req1.execute(statusCode1, message1, responseData1);
        res1.printResponse();

        String endpoint2 = sc.nextLine();
        int payload2 = Integer.parseInt(sc.nextLine());
        int statusCode2 = Integer.parseInt(sc.nextLine());
        String message2 = sc.nextLine();
        String responseData2 = sc.nextLine();

        APIRequest<Integer> req2 = new APIRequest<>(endpoint2, payload2);
        APIResponse<String> res2 = req2.execute(statusCode2, message2, responseData2);
        res2.printResponse();
    }
}
