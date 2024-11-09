/**
 * Raymond Rowland
 * Project 1
 * 20 OCT 24
 * 
 * Represents an isosceles triangle as a solid polygon.
 * Inherits from SolidPolygon and initializes the triangle's vertices
 * based on the provided location, height, and width.
 */

import java.awt.*;

public class IsoscelesTriangle extends SolidPolygon {

    private int[] xVerts;
    private int[] yVerts;

    public IsoscelesTriangle(Color color, Point location, int height, int width) {
        super(color, 3);
        xVerts = new int[3];
        yVerts = new int[3];
        width = width / 2;

        xVerts[0] = (int)location.getX();
        xVerts[1] = xVerts[0] - width;
        xVerts[2] = xVerts[0] + width;
        
        yVerts[0] = (int)location.getY();
        yVerts[1] = yVerts[0] + height;
        yVerts[2] = yVerts[0] + height;

        createPolygon(xVerts, yVerts);
    }

}
