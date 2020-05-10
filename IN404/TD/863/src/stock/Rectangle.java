package stock;

public class Rectangle extends Shape{
    int c1x,c1y,c2x,c2y;

    public Rectangle(int c1x, int c1y, int c2x, int c2y) {
        this.c1x = c1x;
        this.c1y = c1y;
        this.c2x = c2x;
        this.c2y = c2y;
    }

    public static Rectangle parseInput(String[] args){
        if(args == null || args.length != 4) throw new IllegalArgumentException("Pas assez d'arguments");
        int[] toGive = new int[4];
        for(int i = 0; i<4; i++){
            try{
                toGive[i] = Integer.parseInt(args[i]);
            }catch(NumberFormatException e){
                throw new IllegalArgumentException("Des entiers sont attendus pour créer le rectangle");
            }
        }
        return new Rectangle(toGive[0],toGive[1],toGive[2],toGive[3]);
    }
    @Override
    public String toString(){
        return "Rectangle (c1 = ("+c1x+","+c1y+"), c2 = ("+c2x+","+c2y+"))";
    }

    @Override
    public void move(int deltaX, int deltaY) {
        c1x += deltaX; c2x += deltaX;
        c1y += deltaY; c2y += deltaY;
    }
}
