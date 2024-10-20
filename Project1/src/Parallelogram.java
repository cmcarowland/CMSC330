

import java.awt.*;

public class Parallelogram extends SolidPolygon {

    private int[] xVerts;
    private int[] yVerts;

    public Parallelogram(Color color, Point upperLeft, Point lowerRight, int offset) {
        super(color, 4);
        xVerts = new int[4];
        yVerts = new int[4];

        xVerts[0] = (int)upperLeft.getX();
        xVerts[1] = (int)lowerRight.getX() + offset;
        xVerts[2] = (int)lowerRight.getX();
        xVerts[3] = (int)upperLeft.getX() - offset;

        yVerts[0] = yVerts[1] = (int)upperLeft.getY();
        yVerts[2] = yVerts[3] = (int)lowerRight.getY();

        createPolygon(xVerts, yVerts);
    }

}
