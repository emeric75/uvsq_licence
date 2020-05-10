import stock.Stock;
import ui.Command;
import ui.Quit;
import ui.UI;

public class App {
    public static void main(String[] args){
        UI ui = new UI();
        Stock stock = new Stock();
        Command c = null;
        while(!(c instanceof Quit)){
            try {
                c = ui.getCommand();
                String res = c.execute(stock);
                ui.display(res);
            }catch(IllegalArgumentException e){
                ui.display(e.getMessage());
            }
        }
    }
}
