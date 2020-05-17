package ui.commands;

import stock.Stock;

public class Move implements Command{
    String[] args;

    public Move(String[] args) {
        this.args = args;
    }
    @Override
    public String execute(Stock stock) {
        if(args.length != 3) throw new IllegalArgumentException("Nombre invalide d'arguments pour move (3 attendus)");
        int[] params = new int[2];
        for(int i = 0; i<2; i++){
            try{
                params[i] = Integer.parseInt(args[i+1]);
            }catch(NumberFormatException e){
                throw new IllegalArgumentException("Des nombres sont attendus.");
            }
        }
        stock.move(args[0],params[0],params[1]);
        return "Figure " +args[0] +" déplacée de (" + params[0]+","+params[1]+")";
    }
}
