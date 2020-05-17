package ui;

import ui.commands.*;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
import java.util.function.Function;

public class UI {
    private static HashMap< String, Function<String[], Command> > l;
    static{
        l = new HashMap<>();
        l.put("create",i->new Create(i));
        l.put("group" ,i->new Group(i));
        l.put("save"  ,i->new Save(i));
        l.put("load"  ,i->new Load(i));
        l.put("list"  ,i->new List(i));
        l.put("quit"  ,i->new Quit(i));
        l.put("move"  ,i->new Move(i));
        l.put("rename",i->new Rename(i));
        l.put("split",i->new Split(i));
        l.put("remove",i->new Remove(i));
    }
    private Scanner sc;
    public UI(){
        sc = new Scanner(System.in);
    }

    public Command getCommand() {
        System.out.print("> ");
        String input = sc.nextLine();
        String[] words = input.split(" ");
        String firstWord = words[0];
        String[] remainingArgs = Arrays.copyOfRange(words, 1, words.length);
        try{
            return l.get(firstWord).apply(remainingArgs);
        }catch(NullPointerException e) {
            //si firstWord ne correspond à rien dans le HashMap
            throw new IllegalArgumentException("Commande invalide.");
        }
    }
    public Command saveOnQuit(){
        this.display("Voulez-vous sauvegarder votre dessin ? (o/n)");
        String query = null;
        while(true){
            query = sc.nextLine();
            if(query.equalsIgnoreCase("o") ||  query.equalsIgnoreCase("n"))
                break;
            else
                this.display("Réponse attendue o/n");
        }
        if(query.equalsIgnoreCase("o")) {
            this.display("A quel nom?");
            return new Save(new String[]{sc.nextLine()});
        }
        return null;
    }
    public void display(String s){
        System.out.println(s);
    }
}
