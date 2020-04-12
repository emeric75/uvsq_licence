package com.RPN;
import java.util.Scanner;
public class SaisieRPN {
    MoteurRPN m;

    public SaisieRPN() {
        m = new MoteurRPN();
    }

    public void start() {
        Scanner sc = new Scanner(System.in);
        m.printPile();
        String res = sc.nextLine();
        while (!res.equals("exit")) {
            try {
                Float operand = Float.parseFloat(res);
                CalculatriceRPN.checkValue(operand);
                m.push(operand);
            } catch (ValueException e) {
                System.out.println(e.getMessage());
            } catch (NumberFormatException e) {
                try {
                    Operation op = Operation.parseSymbol(res);
                    m.applyOp(op);
                } catch (NotAnOperationException ex) {
                    System.out.println("ni un flottant, ni une opération");
                }
            }
            m.printPile();
            res = sc.nextLine();
        }
    }
}
