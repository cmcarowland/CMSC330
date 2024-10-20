/**
 * Raymond Rowland
 * Project 1
 * 20 OCT 24
 *
 * Base class for solid polygons that extends the Polygon_ class.
 * It initializes the polygon with a specified color and vertex count,
 * and overrides the drawPolygon method to fill the polygon using 
 * the provided Graphics context.  
*/

import java.awt.*;

public class SolidPolygon extends Polygon_ {

    public SolidPolygon(Color color, int vertexCount) {
        super(color, vertexCount);
    }

    @Override
    public void drawPolygon(Graphics graphics, Polygon polygon) {
        graphics.fillPolygon(polygon);
    }    
}
