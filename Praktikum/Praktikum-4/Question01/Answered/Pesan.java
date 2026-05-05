public abstract class Pesan {
    protected String konten;

    public Pesan(String konten) {
        this.konten = konten;
    }

    public String getKonten() {
        return konten;
    }

    public abstract String process();

    protected abstract String getType();

    @Override
    public String toString() {
        return "[" + getType() + "] " + konten;
    }
}
