
/**
 * Décrivez votre classe Repertoire ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Repertoire
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    private int taille;
    private String name;
    private Dossier pere;
    /**
     * Constructeur d'objets de classe Repertoire
     */
    public Repertoire(String name, int taille, Dossier pere)
    {
        // initialisation des variables d'instance
        this.name=name;
        this.taille=taille;
        this.pere=pere;
        if(pere != null){
            pere.addRepertoire(this);
        }
    }
    public String getName(){
        return name;
    }
    public int getTaille(){
        return taille;
    }
    public Dossier getPere(){
        return pere;
    }
    public void setTaille(int taille){
        this.taille = taille;
    }
    public void setPere(Dossier pere){
        this.pere = pere;
    }
    public void updateTaille(int delta){
        this.taille += delta;
        if(pere != null){
            pere.updateTaille(delta);
        }
    }
}
