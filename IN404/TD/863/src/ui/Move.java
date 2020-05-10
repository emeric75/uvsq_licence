package ui;

import stock.Stock;

public class Move implements Command{
    String[] args;
    @Override
    public void setArgs(String... args) {
        this.args = args;
    }

    @Override
    public String execute(Stock stock) {
        if(args == null || args.length != 3) throw new IllegalArgumentException("Pas assez d'arguments");
        int[] params = new int[3];
        for(int i = 0; i<3; i++){
            try{
                params[i] = Integer.parseInt(args[i]);
            }catch(NumberFormatException e){
                throw new IllegalArgumentException("Des nombres sont attendus.");
            }
        }
        stock.move(params[0],params[1],params[2]);
        return "Figure " +params[0] +" déplacée de (" + params[1]+","+params[2]+")";
    }
}
