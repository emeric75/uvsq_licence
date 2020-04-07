package com.RPN;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) throws NotAnOperationException{
        MoteurRPN m = new MoteurRPN();
        Scanner sc = new Scanner(System.in);
        m.printPile();
        String res = sc.nextLine();
        while(!res.equals("exit")){
            try {
                Float operand = Float.parseFloat(res);
                m.push(operand);
            }catch(NumberFormatException e){
                try{
                    Operation op = Operation.parseSymbol(res);
                    m.applyOp(op);
                }catch (NotAnOperationException ex) {
                    System.out.println("ni un flottant, ni une opération");
                }catch (ValueException ex) {
                    System.out.println(ex.getMessage());
                }catch (NoOperandsException ex) {
                    System.out.println(ex.getMessage());
                }
            }
            m.printPile();
            res = sc.nextLine();
        }
    }
}
