public abstract class Scroll {
    protected String content;

    public Scroll(String content) {
        this.content = content;
    }

    public String getContent() {
        return content;
    }

    public abstract String process();

    @Override
    public abstract String toString();
}
