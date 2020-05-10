package stock;

import java.io.Serializable;

public abstract class Shape implements Serializable {
    public abstract void move(int deltaX, int deltaY);
}
