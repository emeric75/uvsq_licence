package ui.commands;

import stock.Stock;

public class Remove implements Command{
    String[] args;
    public Remove(String[] args){ this.args = args; }
    @Override
    public String execute(Stock stock) {
        if(args.length != 1)
            throw new IllegalArgumentException("Nombre d'arguments invalide pour remove (1 attendu)");
        stock.remove(args[0]);
        return "Figure "+args[0] +" retirée";
    }
}
