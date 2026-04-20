public class PalindromeScroll extends Scroll {
    public PalindromeScroll(String content) {
        super(content);
    }

    @Override
    public String process() {
        return new StringBuilder(content).reverse().toString();
    }

    public boolean isPalindrome() {
        if (content == null) return false;
        String cleaned = content.replaceAll("\\s+", "").toLowerCase();
        int left = 0;
        int right = cleaned.length() - 1;
        while (left < right) {
            if (cleaned.charAt(left) != cleaned.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    @Override
    public String toString() {
        return "[PALINDROME] " + content;
    }
}
