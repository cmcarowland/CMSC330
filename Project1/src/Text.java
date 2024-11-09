/**
 * Raymond Rowland
 * Project 1
 * 20 OCT 24
 *
 * Represents a text object that can be drawn on a graphical interface.
 * Inherits from the Image class and stores the text data and position,
 * overriding the draw method to render the text using the specified 
 * graphics context and color.  
*/

import java.awt.*;

public class Text extends Image {

    String data;
    Point position;

    public Text(Color color, Point point, String data) {
        super(color);

        position = point;
        this.data = data;
    }

    @Override
    void draw(Graphics graphics) {
        colorDrawing(graphics);
        graphics.drawString(data, position.x, position.y);
    }
}
