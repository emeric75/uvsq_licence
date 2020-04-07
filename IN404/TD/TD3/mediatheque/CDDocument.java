
/**
 * Décrivez votre classe CDDocument ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class CDDocument extends Document
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    private int nbTitles;
    /**
     * Constructeur d'objets de classe CDDocument
     */
    public CDDocument(String title, String group, int nbTitles)
    {
        // initialisation des variables d'instance
        super(title,group);
        this.nbTitles = nbTitles;
    }
    @Override
    public void getInfos(){
        System.out.println("titre : " + getTitle());
        System.out.println("groupe : " + getArtist());
        System.out.println("nombre titres : " + nbTitles);
    }
}
