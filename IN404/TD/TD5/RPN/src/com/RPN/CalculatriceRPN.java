package com.RPN;

public enum CalculatriceRPN {
    MIN_VALUE(0.0001f),
    MAX_VALUE(1000.0f);
    Float val;

    CalculatriceRPN(Float val) {
        this.val = val;
    }

    public static void checkValue(Float val) throws ValueException {
        if (Math.abs(val) > MAX_VALUE.val)
            throw new ValueException("Valeur trop grande");
        if (Math.abs(val) < MIN_VALUE.val)
            throw new ValueException("Valeur trop petite");
    }

    public static void main(String[] args) {
        SaisieRPN s = new SaisieRPN();
        s.start();
    }
}
