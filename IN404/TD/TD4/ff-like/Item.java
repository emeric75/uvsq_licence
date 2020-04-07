
/**
 * Décrivez votre classe Item ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Item
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    private String name;
    private Attributes bonus;
    
    /**
     * Constructeur d'objets de classe Item
     */
    public Item(String name, Attributes a)
    {
        // initialisation des variables d'instance
        this.name = name;
        this.bonus = a;
    }
    public String getName(){
        return name;
    }
    public Attributes getAttributes(){
        return bonus;
    }
}
