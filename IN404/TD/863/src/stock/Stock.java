package stock;

import java.io.*;
import java.util.ArrayList;

public class Stock {
    private ArrayList<Figure> figs;

    public Stock(){
        figs = new ArrayList<>();
    }

    public void create(Shape s){
        Figure fig = new Figure();
        fig.addShape(s);
        figs.add(fig);
    }

    public ArrayList<Figure> getFigs(){
        return figs;
    }

    public int group(int f1, int f2){
        if(f1<0 || f1>=figs.size() || f2<0 || f2>=figs.size())
            throw new IllegalArgumentException("Les figures auxquelles vous tentez d'accéder n'existent pas");
        if(f1 == f2)
            throw new IllegalArgumentException("Vous ne pouvez pas fusionner une figure avec elle-même");
        Figure fig1 = figs.get(f1);
        Figure fig2 = figs.get(f2);
        fig1.merge(fig2);
        figs.remove(fig2);
        return figs.size()-1;
    }

    public void save(String filename) throws IOException{
        try (ObjectOutputStream oos =
                     new ObjectOutputStream(
                             new FileOutputStream(filename))
            ) {
            oos.writeObject(figs);
        }
    }
    public void load(String filename) throws IOException, ClassNotFoundException{
        try (ObjectInputStream ois =
                     new ObjectInputStream(
                             new FileInputStream(filename))
        ) {
            figs = (ArrayList<Figure>) ois.readObject();
        }
    }
    public void move(int f, int deltaX, int deltaY){
        if(f<0 || f>=figs.size())
            throw new IllegalArgumentException("La figure à laquelle vous tentez d'accéder n'existe pas");
        figs.get(f).move(deltaX,deltaY);
    }
}
