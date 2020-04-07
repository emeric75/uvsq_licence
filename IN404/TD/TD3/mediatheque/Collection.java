import java.util.List;
import java.util.ArrayList;
/**
 * Décrivez votre classe Collection ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Collection
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    private String name;
    private List<Document> documents;

    /**
     * Constructeur d'objets de classe Collection
     */
    public Collection()
    {
        // initialisation des variables d'instance
        documents = new ArrayList<>();
    }
    public void addDocument(Document d){
        documents.add(d);
    }
    public void removeDocument(Document d){
        documents.remove(d);
    }
    public void listDocuments(){
        System.out.println(name);
        for(int i = 0; i<documents.size(); i++){
            System.out.println("n°"+(i+1));
            documents.get(i).getInfos();
        }
    }
    public void searchTitle(String query){
        System.out.println("Recherche dans" + name + "par titre");
        int nbOk = 0;
        for(Document d : documents){
            if(d.getTitle().toLowerCase().contains(query.toLowerCase())){
                nbOk++;
                d.getInfos();
            }
        }
        System.out.println(nbOk + " résultats");
    }
    public void searchArtist(String query){
        System.out.println("Recherche dans" + name + "par artiste");
        int nbOk = 0;
        for(Document d : documents){
            if(d.getArtist().toLowerCase().contains(query.toLowerCase())){
                nbOk++;
                d.getInfos();
            }
        }
        System.out.println(nbOk + " résultats");
    }
}
