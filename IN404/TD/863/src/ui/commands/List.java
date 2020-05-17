package ui.commands;

import stock.Stock;

public class List implements Command{
    private String[] args;

    public List(String[] args) {
        this.args = args;
    }

    @Override
    public String execute(Stock stock) {
        return stock.toString();
    }
}
