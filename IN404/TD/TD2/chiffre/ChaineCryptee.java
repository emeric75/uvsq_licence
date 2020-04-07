
/**
 * Décrivez votre classe ChaineCryptee ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class ChaineCryptee
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    private String crypte;
    private int decalage;
    
    public static ChaineCryptee deDecrypte(String clair, int decalage){
        return new ChaineCryptee(decaleChaine(clair,decalage), decalage); 
    }
    public static ChaineCryptee deEncrypte(String crypte, int decalage){
        return new ChaineCryptee(crypte, decalage);
    }
    /**
     * Constructeur d'objets de classe ChaineCryptee
     */
    private ChaineCryptee(String crypte, int decalage)
    {
        this.crypte = crypte;
        this.decalage = decalage;
    }
    public String encrypte(){
        return crypte;
    }
    public String decrypte(){
        return decaleChaine(crypte, -decalage);
    }
    private static String decaleChaine(String s, int decalage){
        String out = new String();
        for(int i = 0; i<s.length(); i++){
            out += decaleCaractere(s.charAt(i), decalage);
        }
        return out;
    }
    private static char decaleCaractere(char c, int decalage){
        return (c < 'A' || c > 'Z')? c : (char)(Math.floorMod((c - 'A' + decalage),26) + 'A');
    }
    public static void main(String[] args){
        ChaineCryptee s1 = ChaineCryptee.deEncrypte(args[0],Integer.parseInt(args[1]));
        System.out.println("decrypte " + s1.decrypte());
        System.out.println("encrypte " + s1.encrypte());
    }
}
