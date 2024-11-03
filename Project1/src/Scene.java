/**
 * Raymond Rowland
 * Project 1
 * 20 OCT 24
 * 
 * Scene class that defines a graphical scene within a JFrame.
 *
 * This class manages the creation of a window for drawing and provides functionalities to add
 * graphic objects and display the scene.
 *
 * Key Functionalities:
 * - Constructor: Initializes the scene with a specified name, height, and width, setting up the 
 *   JFrame and adding a DrawingPanel for rendering graphics.
 * - `addImage`: Method to add a graphic object (Image) to the scene's drawing panel.
 * - `draw`: Displays the window and repaints the drawing panel to reflect any updates.
 *
 * Menus:
 * - The scene includes a menu bar with a "File" menu that allows the user to open a scene file,
 *   triggering the `setFile` and `parseScene` methods from the Main class.
 *
 * Error Handling: 
 * - Errors related to scene file parsing are managed by the Main class, with appropriate UI feedback.
 */


import java.awt.event.ActionEvent;

import javax.swing.*;

// Class that defines a scene

class Scene {

    private JFrame window;
    private DrawingPanel drawing;

    // Constructor that must be supplied the height and width of the drawing window for the scene

    public Scene(String name, int height, int width) {
        window = new JFrame(name);
        window.setSize(width, height);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        drawing = new DrawingPanel();
        window.add(drawing);
        JMenuBar menuBar = new JMenuBar();
        JMenu fileMenu = new JMenu("File");
        JMenuItem openItem = new JMenuItem(new AbstractAction("Open") {
            @Override
            public void actionPerformed(ActionEvent e) {
                Main.setFile();
                Main.parseScene();
            }
        });

        fileMenu.add(openItem);

        menuBar.add(fileMenu);
        window.setJMenuBar(menuBar);
    }

    // Adds a graphic object to the scene's drawing panel

    public void addImage(Image image) {
        drawing.addImage(image);
    }

    // Causes the drawing panel to be repainted

    public void draw() {
        window.setVisible(true);
        drawing.repaint();
    }
}