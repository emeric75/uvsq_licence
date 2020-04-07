
/**
 * Décrivez votre classe Document ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Document
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    private String title;
    private String artist;
    /**
     * Constructeur d'objets de classe Document
     */
    public Document(String title, String artist)
    {
        // initialisation des variables d'instance
        this.title = title;
        this.artist = artist;
    }
    public String getTitle(){
        return title;
    }
    public String getArtist(){
        return artist;
    }
    public void getInfos(){
        System.out.println("titre : " + title);
        System.out.println("artiste : " + artist);
    }
}
