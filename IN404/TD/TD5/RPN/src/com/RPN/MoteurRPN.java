package com.RPN;
import java.util.Iterator;
import java.util.List;
import java.util.ArrayList;

public class MoteurRPN {
    private List<Float> pile;
    public MoteurRPN(){
        pile = new ArrayList<>();
    }
    public void push(Float f){
        pile.add(f);
    }
    public Float getTop() throws NoOperandsException{
        try{
            Float f = pile.get(pile.size()-1);
            pile.remove(pile.size()-1);
            return f;
        }catch(IndexOutOfBoundsException e){
            throw new NoOperandsException("La pile est vide.");
        }
    }
    public void applyOp(Operation o) throws NoOperandsException,ValueException{
        Float f1=null,f2=null;
        try {
            f1 = this.getTop();
            f2 = this.getTop();
            this.push(o.eval(f1,f2));
        }catch(NoOperandsException e){
            if(f1 != null) {
                this.push(f1);
            }
            throw new NoOperandsException(e.getMessage());
        }catch(ValueException e){
            this.push(f2);
            this.push(f1);
            throw new ValueException(e.getMessage());
        }
    }
    public void printPile(){
        System.out.println("-------");
        for(Float operand : pile){
            System.out.println(operand.toString());
        }
        System.out.println("-------");
    }
}
