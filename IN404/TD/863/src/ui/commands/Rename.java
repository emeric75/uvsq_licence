package ui.commands;

import stock.Stock;

public class Rename implements Command{
    String[] args;
    public Rename(String[] args){ this.args = args; }
    @Override
    public String execute(Stock stock) {
        if(args.length != 2) throw new IllegalArgumentException("Nombre d'arguments à rename invalide (2 attendus)");
        stock.rename(args[0],args[1]);
        return args[0]+"->"+args[1];
    }
}
