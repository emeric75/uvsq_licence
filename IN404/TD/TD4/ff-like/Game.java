import java.io.FileNotFoundException;
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
/**
 * Décrivez votre classe Game ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Game
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    private static int remaining_time;
    private static ArrayList<Room> rooms = new ArrayList<>();
    private static Room current_room;
    public static void parseRooms(String filename){
        File f = null;
        Scanner sc = null;
        try {
            f = new File(filename);
            sc = new Scanner(f);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        int nb_rooms = Integer.parseInt(sc.nextLine());
        for(int i = 0; i<nb_rooms; i++)
            rooms.add(i,new Room(sc.nextLine()));
        for(int i = 0; i<nb_rooms; i++) {
            String indexes = sc.nextLine();
            String[] ints = indexes.split(" ");
            System.out.println(indexes);
            if(ints[0] == "0")
                continue;
            for(int j = 0; j<ints.length/2; j++)
                rooms.get(i).setExit(ints[2*j+1],rooms.get(Integer.parseInt(ints[2*j])-1));
        }
    }
    public static void helpString(){

    }
    public static void initGame(){
        remaining_time = (int)(Math.random()*30+30);
        parseRooms("test.txt");
        System.out.println("You are a police officer sent in a big castle to defuse a bomb.");
        System.out.println(remaining_time + " minutes remaining before the bomb explodes.");
        System.out.println("Be careful, enemies might be inside.");
        System.out.println("Good luck!");
        current_room = rooms.get(0);
        current_room.printStatus();
    }
    public static void main(String[] args){
        Player p = new Player("You",Attributes.PLAYER);
        Player enemy = new Player("enemy",Attributes.MEDIUM_ENEMY);
        Parser parser = new Parser();
        initGame();
        Scanner sc = new Scanner(System.in);
        while(p.getCurrentHp() > 0 && enemy.getCurrentHp() > 0){
            String in = sc.nextLine();
            switch(parser.parse(in)){
                case SEARCH:
                    p.search(current_room);
                    remaining_time -= 2;
                    break;
                case MOVE:
                    Room new_room = parser.dirParse(current_room,in);
                    if(new_room == current_room) {
                        System.out.println("unrecognized direction");
                    }else {
                        current_room = new_room;
                        current_room.printStatus();
                    }
                    remaining_time -= 1;
                    break;
                case INVENTORY:
                    p.printInventory();
                    break;
                case HELP:
                   helpString();
                    break;
                case QUIT:
                    p.attacked(p.getCurrentHp());
                    break;
                case STATUS:
                    current_room.printStatus();
                    break;
                case UNKNOWN:
                    System.out.println("not recognized");
                    break;
            }
            System.out.println(remaining_time + " minutes remaining before the bomb explodes.");
        }
        if(enemy.getCurrentHp() <= 0 && p.getCurrentHp() <= 0){
            System.out.println("tie");
        }   
        else if(enemy.getCurrentHp() <= 0){
            System.out.println("You won!");
        }else{
            System.out.println("game over");
        }
    }

}
