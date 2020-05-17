package ui.commands;

import stock.Stock;

public class Quit implements Command{
    private String[] args;

    public Quit(String[] args) {
        this.args = args;
    }
    @Override
    public String execute(Stock stock) {
        return "fermeture de l'application";
    }
}
