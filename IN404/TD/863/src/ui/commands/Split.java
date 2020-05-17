package ui.commands;

import stock.Stock;

public class Split implements Command{
    public String[] args;

    public Split(String[] args){ this.args = args; }

    @Override
    public String execute(Stock stock) {
        if(args.length != 1)
            throw new IllegalArgumentException("Nombre d'arguments invalide pour split (1 attendu)");
        stock.split(args[0]);
        return "Figure "+args[0]+" splitée";
    }
}
