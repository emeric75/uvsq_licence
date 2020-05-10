package ui;

import stock.Stock;

public class Quit implements Command{
    private String[] args;
    public void setArgs(String... args){
        this.args = args;
    }
    @Override
    public String execute(Stock stock) {
        //TODO : demander à sauvegarder avant
        return "fermeture de l'application";
    }
}
