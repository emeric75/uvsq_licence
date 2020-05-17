package ui.commands;

import stock.Stock;

public class Save implements Command{
    private String[] args;

    public Save(String[] args) {
        this.args = args;
    }
    @Override
    public String execute(Stock stock){
        if(args.length != 1)
            throw new IllegalArgumentException("Nombre invalide d'arguments pour save (1 attendu)");
        try {
            stock.save(args[0]);
            return "Figures enregistrées dans "+args[0];
        } catch (Exception e) {
            e.printStackTrace();
            return e.getMessage();
        }
    }
}
