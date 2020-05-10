package stock;

public class Circle extends Shape{
    int centerX;
    int centerY;
    int radius;

    public Circle(int centerX, int centerY, int radius) {
        this.centerX = centerX;
        this.centerY = centerY;
        this.radius = radius;
    }

    public static Circle parseInput(String[] args){
        if(args == null || args.length != 3)  throw new IllegalArgumentException("Pas assez d'arguments");
        int[] toGive = new int[3];
        for(int i = 0; i<3; i++){
            try{
                toGive[i] = Integer.parseInt(args[i]);
            }catch(NumberFormatException e){
                throw new IllegalArgumentException("Des entiers sont attendus pour créer le cercle");
            }
        }
        return new Circle(toGive[0],toGive[1],toGive[2]);
    }
    @Override
    public String toString(){
        return "Cercle (c = ("+centerX+","+centerY+"), r = "+radius+")";
    }

    @Override
    public void move(int deltaX, int deltaY) {
        centerX += deltaX;
        centerY += deltaY;
    }
}
