import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Set;

public class Room {
    private String name;
    private HashMap<String,Room> exits;
    private List<Item> onFloor;

    public Room(String name) {
        this.name = name;
        this.exits = new HashMap<>();
        this.onFloor = new ArrayList<>();
    }
    public HashMap<String, Room> getExits() {
        return exits;
    }
    public void setExit(String dir, Room go_to) {
        this.exits.put(dir,go_to);
    }
    public String getExitString(){
        String out = new String();
        Set<String> keys = exits.keySet();
        for(String k : keys){
            out += keys + " ";
        }
        return out;
    }
    public List<Item> getOnFloor(){
        return onFloor;
    }
    public void printStatus(){
        String out = new String();
        out += "You are " + name + "\n";
        out += "Exits : " + getExitString();
        System.out.println(out);
    }
}
