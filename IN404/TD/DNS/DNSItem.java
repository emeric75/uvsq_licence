public class DNSItem {
    private AdresseIP IP;
    private NomMachine name;
    public DNSItem(AdresseIP IP, NomMachine name){
        this.IP = IP;
        this.name = name;
    }
    public AdresseIP getIP(){
        return IP;
    }
    public NomMachine getName(){
        return name;
    }
    @Override
    public String toString(){
        return name.toString() + " " + IP.toString();
    }
}
