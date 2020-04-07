import java.util.HashMap;

/**
 * Décrivez votre classe Attributes ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public enum Attributes
{
    PLAYER(10,20,5,12,10,20),
    WEAK_ENEMY(5,16,3,8,10,20),
    MEDIUM_ENEMY(10,20,5,12,10,20),
    STRONG_ENEMY(15,27,8,15,10,20);
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    private int max_hp;
    private int atk;
    private int speed;
    private int weight;
    /**
     * Constructeur d'objets de classe Attributes
     */
    Attributes(int minhp, int maxhp, int minatk, int maxatk, int minweight, int maxweight)
    {
        max_hp=(int)(minhp+Math.random()*(maxhp-minhp));
        atk=(int)(minatk+Math.random()*(maxatk-minatk));
        speed=(int)(2+Math.random()*15);
        weight=(int)(minweight+Math.random()*(maxweight-minweight));
    }
    public int getMax_hp(){
        return max_hp;
    }
    public int getAtk(){
        return atk;
    }
    public int getSpeed(){
        return speed;
    }
    public int getWeight(){
        return weight;
    }

    public void setMax_hp(int max_hp) {
        this.max_hp = max_hp;
    }

    public void setAtk(int atk) {
        this.atk = atk;
    }

    public void setSpeed(int speed) {
        this.speed = speed;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public String toString(){
        return "HP " + max_hp + " ATK " + atk + " SPD " + speed + " WGT " + weight;
    }
}
