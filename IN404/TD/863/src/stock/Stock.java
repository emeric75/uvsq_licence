package stock;

import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class Stock {
    private HashMap<String,Figure> figs;

    public Stock(){
        figs = new HashMap<>();
    }

    public int getNbFigs(){
        return figs.size();
    }
    public boolean isNameGiven(String to_check){
        return figs.containsKey(to_check);
    }

    public void create(String name, Shape s){
        Figure fig = new Figure();
        fig.addShape(s);
        figs.put(name,fig);
    }
    public void remove(String name){
        if(!this.isNameGiven(name))
            throw new IllegalArgumentException("La figure à retirer n'existe pas");
        figs.remove(name);
    }
    public void group(String name1, String name2){
        Figure fig1 = figs.get(name1);
        Figure fig2 = figs.get(name2);
        if(fig1 == null || fig2 == null)
            throw new IllegalArgumentException("Les figures que vous voulez fusionner n'existent pas");
        if(name1.equals(name2))
            throw new IllegalArgumentException("Vous ne pouvez pas fusionner une figure avec elle-même");
        fig1.merge(fig2);
        figs.remove(name2);
    }
    public void rename(String to_change, String to_give){
        Figure f = figs.get(to_change);
        if(f == null) throw new IllegalArgumentException("La figure que vous voulez renommer n'existe pas");
        if(this.isNameGiven(to_give))
            throw new IllegalArgumentException("Le nom que vous voulez attribuer est déjà donné");
        figs.remove(to_change);
        figs.put(to_give,f);
    }
    public void move(String name, int deltaX, int deltaY){
        Figure fig = figs.get(name);
        if(fig == null)
            throw new IllegalArgumentException("La figure à laquelle vous tentez d'accéder n'existe pas");
        fig.move(deltaX,deltaY);
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
            figs = (HashMap<String, Figure>) ois.readObject();
        }
    }
    public void split(String name){
        Figure f = figs.get(name);
        if(f == null) throw new IllegalArgumentException("La figure que vous voulez splitter n'existe pas");
        for(Shape s : f.getShapes())
            this.create(this.getNbFigs()-1+"",s);
        figs.remove(name);
    }

    @Override
    public String toString(){
        StringBuilder s = new StringBuilder();
        for(Map.Entry<String,Figure> e : figs.entrySet())
            s.append("["+e.getKey()+"] " + e.getValue().toString() + "\n");
        return s.toString();
    }
}
