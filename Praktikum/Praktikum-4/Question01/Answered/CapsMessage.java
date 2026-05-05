public class CapsMessage extends Pesan {
    public CapsMessage(String konten) {
        super(konten);
    }

    @Override
    public String process() {
        return konten.toUpperCase();
    }

    public int countVowels() {
        int count = 0;
        String lower = konten.toLowerCase();
        for (int i = 0; i < lower.length(); i++) {
            char c = lower.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                count++;
            }
        }
        return count;
    }

    @Override
    protected String getType() {
        return "CAPS";
    }
}
