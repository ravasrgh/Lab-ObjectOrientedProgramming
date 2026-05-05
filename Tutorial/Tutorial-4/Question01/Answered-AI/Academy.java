import java.util.ArrayList;
import java.util.List;

public class Academy {
    private List<Scroll> scrolls;

    public Academy() {
        scrolls = new ArrayList<>();
    }

    public void addScroll(Scroll scroll) {
        scrolls.add(scroll);
    }

    public Scroll getScroll(int index) {
        if (index < 1 || index > scrolls.size()) {
            return null;
        }
        return scrolls.get(index - 1);
    }

    public int search(String keyword) {
        int count = 0;
        if (keyword == null) return count;
        String lowerKeyword = keyword.toLowerCase();
        for (Scroll s : scrolls) {
            if (s.getContent() != null && s.getContent().toLowerCase().contains(lowerKeyword)) {
                count++;
            }
        }
        return count;
    }

    public int count() {
        return scrolls.size();
    }
}
