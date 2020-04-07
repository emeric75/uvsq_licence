package exo51;
import exo51.client.Client;
import exo51.serveur.Serveur;
/**
 * Décrivez votre classe Main ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Main
{
    public static void main(String[] args){
        Serveur s = new Serveur();
        Client c1 = new Client("jean-claude");
        Client c2 = new Client("louis");
        c1.seConnecter(s);
        c2.seConnecter(s);
        Client c3 = new Client("marie");
        c3.seConnecter(s);
        c3.envoyer(s,"salut");
    }
}
