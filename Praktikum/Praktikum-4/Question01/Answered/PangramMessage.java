public class PangramMessage extends Pesan {
    public PangramMessage(String konten) {
        super(konten);
    }

    @Override
    public String process() {
        if (konten == null || konten.trim().isEmpty()) {
            return "";
        }
        String[] words = konten.trim().split("\\s+");
        StringBuilder sb = new StringBuilder();
        for (int i = words.length - 1; i >= 0; i--) {
            sb.append(words[i]);
            if (i > 0) {
                sb.append(" ");
            }
        }
        return sb.toString();
    }

    public boolean isPangram() {
        String lower = konten.toLowerCase();
        boolean[] present = new boolean[26];
        int count = 0;
        for (int i = 0; i < lower.length(); i++) {
            char c = lower.charAt(i);
            if (c >= 'a' && c <= 'z') {
                if (!present[c - 'a']) {
                    present[c - 'a'] = true;
                    count++;
                }
            }
        }
        return count == 26;
    }

    @Override
    protected String getType() {
        return "PANGRAM";
    }
}
