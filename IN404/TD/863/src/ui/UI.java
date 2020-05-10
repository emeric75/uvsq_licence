package ui;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class UI {
    private static HashMap<String, Command> l;
    static{
        l = new HashMap<>();
        l.put("create",new Create());
        l.put("group" ,new Group());
        l.put("save"  ,new Save());
        l.put("load"  ,new Load());
        l.put("list"  ,new List());
        l.put("quit"  ,new Quit());
        l.put("move"  ,new Move());
    }
    private Scanner sc;
    public UI(){
        sc = new Scanner(System.in);
    }
    public Command getCommand(){
        System.out.print("> ");
        String input = sc.nextLine();
        String[] words = input.split(" ");
        String firstWord = words[0];
        String[] remainingArgs = Arrays.copyOfRange(words,1,words.length);
        for(String match : l.keySet()){
            if(firstWord.equalsIgnoreCase(match)) {
                Command to_return = l.get(match);
                to_return.setArgs(remainingArgs);
                return to_return;
            }
        }
        throw new IllegalArgumentException("Commande invalide.");
    }
    public void display(String s){
        System.out.println(s);
    }
}
