public class Umandana {

    private static boolean isVowel(char c) {
        c = Character.toLowerCase(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    private static boolean isConsonant(char c) {
        c = Character.toLowerCase(c);
        return (c >= 'a' && c <= 'z') && !isVowel(c);
    }

    /**
     * Mengembalikan kata yang telah diubah menjadi bahasa Umandana
     * Huruf a menjadi "aiden"
     * Huruf i menjadi "ipri"
     * Huruf u menjadi "upru"
     * Huruf e menjadi "epre"
     * Huruf o menjadi "opro"
     * Huruf mati yang tidak diikuti huruf vokal menjadi huruf tersebut + "es"
     * Suku kata "ng" yang tidak diikuti huruf vokal menjadi "strengen"
     * Suku kata "ng" yang diikuti huruf vokal tetap menjadi "ng"
     * Suku kata "ny" yang diikuti huruf vokal tetap menjadi "ny"
     * Selain ketentuan di atas, huruf/karakter tidak diubah
     * *
     * 
     * @param words
     * @return kata yang telah diubah menjadi bahasa Umandana
     * 
     */
    public static String toUmandana(String words) {
        if (words == null) return null;
        StringBuilder sb = new StringBuilder();
        int n = words.length();
        for (int i = 0; i < n; i++) {
            char c = words.charAt(i);
            if (isVowel(c)) {
                switch (Character.toLowerCase(c)) {
                    case 'a': sb.append("aiden"); break;
                    case 'i': sb.append("ipri"); break;
                    case 'u': sb.append("upru"); break;
                    case 'e': sb.append("epre"); break;
                    case 'o': sb.append("opro"); break;
                }
            } else if (isConsonant(c)) {
                if (c == 'n' && i + 1 < n && words.charAt(i+1) == 'g') {
                    boolean followedByVowel = (i + 2 < n && isVowel(words.charAt(i+2)));
                    if (followedByVowel) {
                        sb.append("ng");
                    } else {
                        sb.append("strengen");
                    }
                    i++;
                } else if (c == 'n' && i + 1 < n && words.charAt(i+1) == 'y' && (i + 2 < n && isVowel(words.charAt(i+2)))) {
                    sb.append("ny");
                    i++;
                } else {
                    boolean followedByVowel = (i + 1 < n && isVowel(words.charAt(i+1)));
                    if (followedByVowel) {
                        sb.append(c);
                    } else {
                        sb.append(c).append("es");
                    }
                }
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }

    /**
     * Mengembalikan kata Umandana ke bentuk normal
     * *
     * 
     * @param words kata dalam bahasa Umandana
     * @return kata telah diubah ke bentuk normal
     */
    public static String deUmandana(String words) {
        if (words == null) return null;
        StringBuilder sb = new StringBuilder();
        int i = 0;
        int n = words.length();
        while (i < n) {
            if (words.startsWith("aiden", i)) {
                sb.append('a');
                i += 5;
            } else if (words.startsWith("ipri", i)) {
                sb.append('i');
                i += 4;
            } else if (words.startsWith("upru", i)) {
                sb.append('u');
                i += 4;
            } else if (words.startsWith("epre", i)) {
                sb.append('e');
                i += 4;
            } else if (words.startsWith("opro", i)) {
                sb.append('o');
                i += 4;
            } else if (words.startsWith("strengen", i)) {
                sb.append("ng");
                i += 8;
            } else if (isConsonant(words.charAt(i))) {
                char c = words.charAt(i);
                sb.append(c);
                if (i + 2 < n && words.charAt(i+1) == 'e' && words.charAt(i+2) == 's') {
                    i += 3;
                } else {
                    i += 1;
                }
            } else {
                sb.append(words.charAt(i));
                i++;
            }
        }
        return sb.toString();
    }
}
