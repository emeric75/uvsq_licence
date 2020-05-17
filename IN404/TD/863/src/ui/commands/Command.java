package ui.commands;

import stock.Stock;

public interface Command {
    String execute(Stock stock);
}
