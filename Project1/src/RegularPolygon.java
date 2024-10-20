

import java.awt.*;

public class RegularPolygon extends SolidPolygon {

    private int[] xVerts;
    private int[] yVerts;

    public RegularPolygon(Color color, Point position, int sides, int radius) {
        super(color, sides);
        xVerts = new int[sides];
        yVerts = new int[sides];
        double scale = Math.PI / sides;

        for(int i = 0; i < sides; i++) {
            double side = scale * (1 + 2 * i);
            xVerts[i] = (int)(position.getX() + radius * Math.sin(side));
            yVerts[i] = (int)(position.getY() + radius * Math.cos(side));
        }

        createPolygon(xVerts, yVerts);
    }

}
