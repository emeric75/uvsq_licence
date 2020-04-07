import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
/**
 * Décrivez votre classe Client ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Client
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    private String name;
    private List<Serveur> serveurs;
    /**
     * Constructeur d'objets de classe Client
     */
    public Client(String name)
    {
        this.name = name;
        this.serveurs = new ArrayList<>();
    }
    public String getName(){
        return name;
    }
    public void seConnecter(Serveur s){
        if(s != null && !serveurs.contains(s)){
            s.connecter(this);
            serveurs.add(s);
        }
    }
    public void seDeconnecter(Serveur s){
        if(s != null && serveurs.contains(s)){
            s.deconnecter(this);
            serveurs.remove(s);
        }
    }
    public void envoyer(Serveur s, String message){
        if(s != null && serveurs.contains(s)){
            s.diffuser(name + " : " + message);
        }
    }
    public void recevoir(String message){
        System.out.println(message + " -> " + name);
    }
    public static void main(String[] args){
        assert args.length > 0;
        Client c = new Client(args[0]);
        c.seConnecter(Serveur.allServeurs.get(0));
        while(true){
            Scanner sc = new Scanner(System.in);
            String newMsg = sc.nextLine();
            c.envoyer(Serveur.allServeurs.get(0),newMsg);
        }
    }
}
