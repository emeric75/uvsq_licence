public class SearchByIP implements Command {
    AdresseIP query;
    public SearchByIP(AdresseIP query){
        this.query = query;
    }
    @Override
    public String execute(DNS db) {
        NomMachine i = db.getItem(query);
        if (i == null) return "pas de résultat";
        return i.toString();
    }
}
