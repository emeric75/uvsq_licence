package ui;

import stock.Stock;

public interface Command {
    void setArgs(String... args);
    String execute(Stock stock);
}
