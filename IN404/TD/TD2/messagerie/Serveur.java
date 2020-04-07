import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
/**
 * Décrivez votre classe Serveur ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Serveur
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    public static List<Serveur> allServeurs = new ArrayList<>();
    private List<Client> clients;
    
    static{
        allServeurs.add(new Serveur());
    }
    /**
     * Constructeur d'objets de classe Serveur
     */
    public Serveur()
    {
        clients = new ArrayList<>();
    }
    public void connecter(Client c){
        if(!clients.contains(c)){
            clients.add(c);
        }
        diffuser("Serveur : " + c.getName() + " est connecté");
    }
    public void deconnecter(Client c){
        if(clients.contains(c))
            clients.remove(c);
    }
    public void diffuser(String message){
        for(Client c : clients){
            c.recevoir(message);
        }
    }
}
