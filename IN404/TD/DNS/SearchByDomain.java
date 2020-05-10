import java.util.ArrayList;

public class SearchByDomain implements Command {
    String domain;
    boolean _a;
    public SearchByDomain(String domain, boolean _a){
        this.domain = domain;
        this._a = _a;
    }
    @Override
    public String execute(DNS db) {
        ArrayList<DNSItem> l = db.getItems(domain,_a);
        if(l == null) return "pas de résultat";
        StringBuilder sb = new StringBuilder();
        for (DNSItem i : l)
            sb.append(i.toString() + "\n");
        return sb.toString();
    }
}
