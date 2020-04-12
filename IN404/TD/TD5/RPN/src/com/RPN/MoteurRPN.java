package com.RPN;

import java.util.ArrayList;
import java.util.List;

public class MoteurRPN {
    private List<Float> pile;
    public MoteurRPN(){
        pile = new ArrayList<>();
    }
    public void push(Float f){
        pile.add(f);
    }
    public Float getTop() throws NoOperandsException {
        try {
            Float f = pile.get(pile.size() - 1);
            pile.remove(pile.size() - 1);
            return f;
        } catch (IndexOutOfBoundsException e) {
            throw new NoOperandsException("Pas assez d'éléments dans la pile.");
        }
    }

    public void applyOp(Operation o) {
        Float f1 = null, f2 = null;
        try {
            f1 = this.getTop();
            f2 = this.getTop();
            this.push(o.eval(f2, f1));
        } catch (NoOperandsException e) {
            if (f1 != null)
                this.push(f1);
            System.out.println(e.getMessage());
        } catch (ValueException e) {
            this.push(f2);
            this.push(f1);
            System.out.println(e.getMessage());
        }
    }
    public void printPile(){
        System.out.println("-------");
        for (Float operand : pile)
            System.out.println(operand.toString());
        System.out.println("-------");
    }
}
