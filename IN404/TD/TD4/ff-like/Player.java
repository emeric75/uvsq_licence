import java.util.List;
import java.util.ArrayList;
/**
 * Décrivez votre classe Player ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Player
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    private String name;
    private int current_hp;
    private Attributes a;
    private List<Item> inventory;
    private List<Item> equipped;
    /**
     * Constructeur d'objets de classe Player
     */
    public Player(String name, Attributes a)
    {
        this.name = name;
        this.a = a;
        this.inventory = new ArrayList<>();
        this.equipped = new ArrayList<>();
        this.current_hp = a.getMax_hp();
    }
    public int getCurrentHp(){
        return current_hp;
    }
    public Attributes getAttributes(){
        return a;
    }
    public void printInventory(){
        System.out.println("-- INVENTORY --");
        for(Item i : inventory){
            System.out.print(i.getName() + " "+ i.getAttributes());
            if(equipped.contains(i)){
                System.out.println("EQUIPPED");
            }else{
                System.out.println("");
            }
        }
    }
    public void equip(Item i){
        if(inventory.contains(i) && !equipped.contains(i)){
            equipped.add(i);
            a.setAtk(a.getAtk() + i.getAttributes().getAtk());
            a.setSpeed(a.getSpeed() + i.getAttributes().getSpeed());
            a.setMax_hp(a.getMax_hp() + i.getAttributes().getMax_hp());
            a.setWeight(a.getWeight() + i.getAttributes().getWeight());
        }
    }
    public void unequip(Item i){
        if(equipped.contains(i)){
            equipped.remove(i);
            a.setAtk(a.getAtk() - i.getAttributes().getAtk());
            a.setSpeed(a.getSpeed() - i.getAttributes().getSpeed());
            a.setMax_hp(a.getMax_hp() - i.getAttributes().getMax_hp());
            a.setWeight(a.getWeight() - i.getAttributes().getWeight());
        }
    }
    public void take(Item i){
        if(!inventory.contains(i)){
            inventory.add(i);
        }
    }
    public void discard(Item i){
        if(inventory.contains(i)){
            unequip(i);
            inventory.remove(i);
        }
    }
    public void attack(Player p){
        p.attacked(a.getAtk());
    }
    public void attacked(int dmg){
        current_hp -= dmg;
    }
    public void printStatus(){
        System.out.println("Health : " + current_hp + "/" + a.getMax_hp() + " HP");
    }
    public void search(Room r){
        for(Item i : r.getOnFloor()) {
            this.take(i);
        }
    }
}
