package ui;

import stock.Figure;
import stock.Stock;

import java.util.ArrayList;

public class List implements Command{
    private String[] args;
    public void setArgs(String... args){
        this.args = args;
    }
    @Override
    public String execute(Stock stock) {
        ArrayList<Figure> l = stock.getFigs();
        StringBuilder s = new StringBuilder();
        int i = 0;
        for(Figure fig : l){
            s.append("["+i+"] " + fig.toString() + "\n");
            i++;
        }
        return s.toString();
    }
}
