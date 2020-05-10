package ui;

import stock.Stock;

public class Load implements Command{
    private String[] args;
    public void setArgs(String... args){
        this.args = args;
    }
    @Override
    public String execute(Stock stock) {
        if(args == null || args.length != 1) throw new IllegalArgumentException("Pas assez d'arguments");
        try {
            stock.load(args[0]);
            return "Figures chargées depuis " + args[0];
        }catch (Exception e){
            e.printStackTrace();
            return e.getMessage();
        }
    }
}
