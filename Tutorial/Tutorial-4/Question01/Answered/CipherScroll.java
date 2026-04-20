public class CipherScroll extends Scroll {
    private int shift;

    public CipherScroll(String content, int shift) {
        super(content);
        this.shift = shift;
    }

    @Override
    public String process() {
        return applyShift(content, shift);
    }

    public String decode() {
        return applyShift(content, -shift);
    }

    private String applyShift(String text, int s) {
        StringBuilder sb = new StringBuilder();
        for (char c : text.toCharArray()) {
            if (Character.isLetter(c)) {
                int base = Character.isUpperCase(c) ? 65 : 97;
                char shifted = (char) (((c - base + s % 26 + 26) % 26) + base);
                sb.append(shifted);
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        return "[CIPHER] " + content;
    }
}
