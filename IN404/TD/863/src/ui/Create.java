package ui;

import stock.Circle;
import stock.Rectangle;
import stock.Shape;
import stock.Stock;

import java.util.Arrays;

public class Create implements Command{
    private String[] args;
    public void setArgs(String... args){
        this.args = args;
    }
    @Override
    public String execute(Stock stock) {
        //exception
        if(args == null || args.length < 1) throw new IllegalArgumentException("Pas assez d'arguments");
        Shape to_create;
        String findShape = args[0];
        String[] remainingArgs = Arrays.copyOfRange(args,1,args.length);
        switch(findShape){
            case "circle": to_create = Circle.parseInput(remainingArgs); break;
            case "rectangle": to_create = Rectangle.parseInput(remainingArgs); break;
            default:
                throw new IllegalArgumentException("Le type de figure que vous voulez créer n'existe pas.");
        }
        stock.create(to_create);
        return findShape + " créé.";
    }
}
