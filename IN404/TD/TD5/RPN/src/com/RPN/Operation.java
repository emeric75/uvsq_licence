package com.RPN;

public enum Operation {
    PLUS("+") {
        @Override public Float eval(Float a, Float b) throws ValueException{
            CalculatriceRPN.checkValue(a + b);
            return a+b;
        }
        },
    MINUS("-"){
        @Override public Float eval(Float a, Float b) throws ValueException{
            CalculatriceRPN.checkValue(a - b);
            return a-b;
        }
        },
    MULT("*") {
        @Override public Float eval(Float a, Float b) throws ValueException{
            CalculatriceRPN.checkValue(a * b);
            return a*b;
        }
        },
    DIV("/")  {
        @Override public Float eval(Float a, Float b) throws ValueException{
            CalculatriceRPN.checkValue(a / b);
            return a/b;
        }
        };
    private String symbole;
    Operation(String symbole){
        this.symbole = symbole;
    }

    public abstract Float eval(Float a, Float b) throws ValueException;
    public static Operation parseSymbol(String s) throws NotAnOperationException{
        for (Operation op : Operation.values()) {
            if (s.equals(op.symbole)) {
                return op;
            }
        }
        throw new NotAnOperationException("pas une operation");
    }
}
