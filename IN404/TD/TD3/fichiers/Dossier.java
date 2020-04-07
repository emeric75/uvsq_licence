import java.util.List;
import java.util.ArrayList;
/**
 * Décrivez votre classe Dossier ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Dossier extends Repertoire
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    private List<Repertoire> content;
    
    /**
     * Constructeur d'objets de classe Dossier
     */
    public Dossier(String name,Dossier pere)
    {
        // initialisation des variables d'instance
        super(name,0,pere);
        content = new ArrayList<>();
    }
    public void addRepertoire(Repertoire r)
    {
        if(!content.contains(r)){
            content.add(r);
            setTaille(getTaille()+r.getTaille());
            r.setPere(this);
            //vérifier qu'on ajoute pas le repertoire comme descendant de lui-meme
            Repertoire temp = this;
            while(temp != null && temp != r){
                temp = temp.getPere();
            }
            if(temp == r){
                this.removeRepertoire(r);
            }
            if(getPere() != null){
                getPere().updateTaille(r.getTaille());
            }
        }
    }
    public void removeRepertoire(Repertoire r)
    {
        if(content.contains(r)){
            content.remove(r);
            setTaille(getTaille()-r.getTaille());
            r.setPere(null);
            if(getPere() != null){
                getPere().setTaille(getPere().getTaille()-r.getTaille());
                getPere().updateTaille(-r.getTaille());
            }
        }
    }
}
