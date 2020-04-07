/**
 * Décrivez votre classe Fraction ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Fraction
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    private int num;
    private int denom;
    public static Fraction ZERO = new Fraction(0,1);
    public static Fraction ONE = new Fraction(1,1);
    public static Fraction fromNumDenom(int num, int denom){
        return new Fraction(num, denom);
    }
    public static Fraction fromNum(int num){
        return new Fraction(num, 1);
    }
    /**
     * Constructeur d'objets de classe Fraction
     */
    private Fraction(int num, int denom)
    {
        this.num = num;
        this.denom = denom;
    }

    /**
     * Un exemple de méthode - remplacez ce commentaire par le vôtre
     *
     * @param  y   le paramètre de la méthode
     * @return     la somme de x et de y
     */
    public int getNum(){
        return num;
    }
    public int getDenom(){
        return denom;
    }
    public double getValue(){
        return ((double)num)/denom;
    }
    public static Fraction add(Fraction add1, Fraction add2){
        return new Fraction(add1.getNum()*add2.getDenom()+add2.getNum()*add1.getDenom(), add1.getDenom()*add2.getDenom());
    }
    public static boolean equals(Fraction f1, Fraction f2){
        //return (f1.getNum()*f2.getDenom()-f2.getNum()*f1.getDenom()) == 0;
        return f1.getValue()==f2.getValue();
    }
    public String toString(){
        return num+"/"+denom;
    }
    public static boolean leq(Fraction f1, Fraction f2){
        //return (f1.getNum()*f2.getDenom()-f2.getNum()*f1.getDenom()) * (f1.getDenom()*f2.getDenom()) <= 0;
        return f1.getValue()<=f2.getValue();
    }
}
