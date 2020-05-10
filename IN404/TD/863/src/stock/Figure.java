package stock;

import java.io.Serializable;
import java.util.ArrayList;

public class Figure implements Serializable {
    private ArrayList<Shape> comp;

    public Figure(){
        comp = new ArrayList<>();
    }
    public ArrayList<Shape> getShapes(){
        return comp;
    }
    public void addShape(Shape s){
        comp.add(s);
    }
    public void merge(Figure fig){
        comp.addAll(fig.getShapes());
    }
    @Override
    public String toString(){
        StringBuilder s = new StringBuilder();
        for(Shape shape : comp)
            s.append(shape.toString() + " ");
        return s.toString();
    }
    public void move(int deltaX, int deltaY){
        for(Shape s : comp)
            s.move(deltaX,deltaY);
    }
}
