public class PlainScroll extends Scroll {
    public PlainScroll(String content) {
        super(content);
    }

    @Override
    public String process() {
        if (content == null || content.trim().isEmpty()) {
            return "";
        }
        String[] words = content.trim().split("\\s+");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length; i++) {
            if (words[i].length() > 0) {
                sb.append(Character.toUpperCase(words[i].charAt(0)));
                sb.append(words[i].substring(1).toLowerCase());
            }
            if (i < words.length - 1) {
                sb.append(" ");
            }
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        return "[PLAIN] " + content;
    }
}
