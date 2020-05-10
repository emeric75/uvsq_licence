import java.util.Scanner;

public class DNSApp {
    public static void main(String[] args){
        DNSTui ui = new DNSTui();
        DNS db = new DNS();
        Scanner s = new Scanner(System.in);
        Command c = null;
        while(!( c instanceof Quit )){
            System.out.print("> ");
            try {
                c = ui.nextCommand(s.nextLine());
                ui.affiche(c.execute(db));
            }catch(ArithmeticException | NoMatchException e){
                System.out.println("commande invalide (" + e.getMessage() + ")");
            }
        }
    }
}
