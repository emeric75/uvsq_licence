
/**
 * Décrivez votre classe DVDDocument ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class DVDDocument extends Document
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    private int releaseYear;
    /**
     * Constructeur d'objets de classe DVDDocument
     */
    public DVDDocument(String title, String director, int releaseYear)
    {
        // initialisation des variables d'instance
        super(title, director);
        this.releaseYear = releaseYear;
    }
    @Override
    public void getInfos(){
        System.out.println("titre : " + getTitle());
        System.out.println("réalisateur : " + getArtist());
        System.out.println("année de sortie : " + releaseYear);
    }
}
