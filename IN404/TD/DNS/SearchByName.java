public class SearchByName implements Command {
    NomMachine m;
    public SearchByName(NomMachine m){
        this.m = m;
    }
    @Override
    public String execute(DNS db) {
        AdresseIP i = db.getItem(m);
        if (i == null) return "pas de résultat";
        return i.toString();
    }
}
