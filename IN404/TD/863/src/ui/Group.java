package ui;

import stock.Stock;

public class Group implements Command{
    private String[] args;
    public void setArgs(String... args){
        this.args = args;
    }
    @Override
    public String execute(Stock stock) {
        //exception
        if(args == null || args.length != 2) throw new IllegalArgumentException("Pas assez d'arguments");
        int[] to_group = new int[2];
        for(int i = 0; i<2; i++){
            try{
                to_group[i] = Integer.parseInt(args[i]);
            }catch(NumberFormatException e){
                throw new IllegalArgumentException("Des nombres sont attendus.");
            }
        }
        int res = stock.group(to_group[0],to_group[1]);
        return to_group[0]+"+"+to_group[1]+"->"+res;
    }
}
