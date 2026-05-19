public class MatrixMultiplication {
    
    // Di dalam method run() dalam runnable WAJIB panggil ThreadTracker.mark();
    // Misal :
    // new Thread(() -> {
    //     ThreadTracker.mark(); <- tambahkan ini ketika ingin submit jawaban
    //     //kode lainnya
    // });
    //
    // Atau
    //
    // run(){
    //   ThreadTracker.mark(); <- tambahkan ini ketika ingin submit jawaban
    //   //kode lainnya
    // }
    
    public static int[][] multiply(int[][] A, int[][] B) {
        int m = A.length;
        int n = A[0].length;
        int p = B[0].length;

        int[][] C = new int[m][p];

        int numThreads = 10;
        Thread[] threads = new Thread[numThreads];

        for (int t = 0; t < numThreads; t++) {
            final int threadId = t;
            threads[t] = new Thread(() -> {
                ThreadTracker.mark();
                for (int i = threadId; i < m; i += numThreads) {
                    for (int j = 0; j < p; j++) {
                        for (int k = 0; k < n; k++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            });
            threads[t].start();
        }

        for (int t = 0; t < numThreads; t++) {
            try {
                threads[t].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        return C;
    }
}
