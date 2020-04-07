import java.util.HashMap;

public class Parser {
    private HashMap<String,Command> convert;
    public Parser() {
        convert = new HashMap<>();
        convert.put("move", Command.MOVE);
        convert.put("m", Command.MOVE);
        convert.put("search", Command.SEARCH);
        convert.put("s", Command.SEARCH);
        convert.put("quit", Command.QUIT);
        convert.put("q", Command.QUIT);
        convert.put("help", Command.HELP);
        convert.put("h", Command.HELP);
        convert.put("inventory",Command.INVENTORY);
        convert.put("inv",Command.INVENTORY);
        convert.put("i",Command.INVENTORY);
        convert.put("status",Command.STATUS);
        convert.put("stat",Command.STATUS);
        convert.put("st",Command.STATUS);
    }
    public Command parse(String input){
        if(input != null && convert.containsKey(input.split(" ")[0].toLowerCase())) {
            return convert.get(input.split(" ")[0].toLowerCase());
        }
        return Command.UNKNOWN;
    }
    public Room dirParse(Room r, String input){
        if(r.getExits().containsKey(input.split(" ")[1])){
            return r.getExits().get(input.split(" ")[1]);
        }
        return r;
    }
}
