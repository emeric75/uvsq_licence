package exo51.serveur;
import exo51.client.Client;
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
    private List<Client> clients;
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
