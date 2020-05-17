package ui.commands;

import stock.Stock;

public class Load implements Command{
    private String[] args;
    public Load(String[] args) {
        this.args = args;
    }
    @Override
    public String execute(Stock stock) {
        if(args.length != 1)
            throw new IllegalArgumentException("Nombre invalide d'arguments pour load (1 attendu)");
        try {
            stock.load(args[0]);
            return "Figures chargées depuis " + args[0];
        }catch (Exception e){
            e.printStackTrace();
            return e.getMessage();
        }
    }
}
