public class RepeatMessage extends Pesan {
    private int n;

    public RepeatMessage(String konten, int n) {
        super(konten);
        this.n = n;
    }

    public int getN() {
        return n;
    }

    @Override
    public String process() {
        if (konten == null || konten.isEmpty()) {
            return "";
        }
        String[] words = konten.split("\\s+");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < n; j++) {
                sb.append(words[i]);
                if (!(i == words.length - 1 && j == n - 1)) {
                    sb.append(" ");
                }
            }
        }
        return sb.toString();
    }

    @Override
    protected String getType() {
        return "REPEAT";
    }
}
