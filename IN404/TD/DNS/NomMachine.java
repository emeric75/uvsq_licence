import java.util.Objects;

public class NomMachine {
    private String name;
    private String domain;

    private NomMachine(String name, String domain){
        this.name = name;
        this.domain = domain;
    }
    public static NomMachine parseNomMachine(String s) throws NoMatchException {
        String[] res;
        if(s.matches("[a-z]*\\.[a-z + \\.]*")) {
            res = s.split("\\.",2);
        }else{
            throw new NoMatchException("pas un nom de machine");
        }
        return new NomMachine(res[0], res[1]);
    }
    public String getName() {
        return name;
    }
    public String getDomain() {
        return domain;
    }
    @Override
    public String toString() { return name + "." + domain; }
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        NomMachine that = (NomMachine) o;
        return Objects.equals(name, that.name) &&
                Objects.equals(domain, that.domain);
    }
    @Override
    public int hashCode() {
        return Objects.hash(name, domain);
    }
}
