package com.RPN;

public enum Operation {
    PLUS("+") {
        @Override public Float eval(Float a, Float b) throws ValueException{
            if(Math.abs(a+b) > MAX_VAL){
                throw new ValueException("Valeur trop élevée");
            }
            if(Math.abs(a+b) < MIN_VAL){
                throw new ValueException("Valeur trop petite");
            }
            return a+b;
        }
        },
    MINUS("-"){
        @Override public Float eval(Float a, Float b) throws ValueException{
            if(Math.abs(a-b) > MAX_VAL){
                throw new ValueException("Valeur trop élevée");
            }
            if(Math.abs(a-b) < MIN_VAL){
                throw new ValueException("Valeur trop petite");
            }
            return a-b;
        }
        },
    MULT("*") {
        @Override public Float eval(Float a, Float b) throws ValueException{
            if(Math.abs(a*b) > MAX_VAL){
                throw new ValueException("Valeur trop élevée");
            }
            if(Math.abs(a*b) < MIN_VAL){
                throw new ValueException("Valeur trop petite");
            }
            return a*b;
        }
        },
    DIV("/")  {
        @Override public Float eval(Float a, Float b) throws ValueException{
            if(Math.abs(a/b) > MAX_VAL){
                throw new ValueException("Valeur trop élevée");
            }
            if(Math.abs(a/b) < MIN_VAL){
                throw new ValueException("Valeur trop petite");
            }
            return a/b;
        }
        };
    private String symbole;
    private static Float MAX_VAL = 100000.0f;
    private static Float MIN_VAL = 0.000001f;
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
