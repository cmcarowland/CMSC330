/**
 * Raymond Rowland
 * Project 1
 * 20 OCT 24
 * 
 * Main class for the Project 1 application.
 * 
 * This class provides the entry point for the program and manages the loading and parsing of a scene 
 * definition file, which contains graphic object specifications.
 *
 * Key Functionalities:
 * - `main`: The main method that initializes the program, allowing the user to specify the scene file
 *   via command line input or a file chooser dialog.
 * - `setFile`: Prompts the user to select a file using a file chooser or enter a filename manually.
 * - `parseScene`: Handles the parsing of the scene file using the `Parser` class, and manages errors 
 *   related to syntax, lexical issues, and IO operations.
 *
 * Error Handling:
 * - Displays error messages for syntax or lexical errors using a dialog box and exits the program 
 *   with appropriate status codes.
 */


import java.io.*;
import java.util.*;
import javax.swing.*;

import org.omg.CORBA.Environment;

// Project 1 main class

class Main {

    // The main method of the whole program, allows the name of the scene definition file to be input on the
    // command line or selected using the file chooser dialog window. It calls the parser to parse the scene
    // definition file and add the graphic objects to the scene.
    static public File sceneFile;
    public static void main(String[] args) {
        setFile();
        parseScene();
    }

    public static void setFile() {
        Scanner stdin = new Scanner(System.in);
        String sceneFileName = "";

        JFileChooser choice = new JFileChooser(new File("."));
        int option = choice.showOpenDialog(null);

        if (option == JFileChooser.APPROVE_OPTION)
            sceneFile = choice.getSelectedFile();
        else {
            System.out.print("Enter scene file name or a single space to choose file from window: ");
            sceneFileName = stdin.nextLine();
            sceneFile = new File(sceneFileName);
        }

        stdin.close();
    }

    public static void parseScene() {
        Scene scene;

        try {
            Parser parser = new Parser(sceneFile);
            scene = parser.parseScene();
            scene.draw();
        } catch (SyntaxError error) {
            System.out.println(error.getMessage());
            JOptionPane.showMessageDialog(null, error.getMessage(), "Syntax Error", JOptionPane.ERROR_MESSAGE);
            System.exit(-1);
        } catch (LexicalError error) {
            System.out.println(error.getMessage());
            JOptionPane.showMessageDialog(null, error.getMessage(), "Lexical Error", JOptionPane.ERROR_MESSAGE);
            System.exit(-2);
        } catch (IOException error) {
            System.out.println("IO Error");
            System.exit(-3);
        }
    }
}
