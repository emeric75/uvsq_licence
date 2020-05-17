package ui.commands;

import stock.Stock;

public class Group implements Command{
    private String[] args;
    public Group(String[] args) {
        this.args = args;
    }
    @Override
    public String execute(Stock stock) {
        if(args.length != 2)
            throw new IllegalArgumentException("Nombre invalide d'arguments pour group (2 attendus)");
        stock.group(args[0],args[1]);
        return args[0]+"+"+args[1]+"->"+args[0];
    }
}
