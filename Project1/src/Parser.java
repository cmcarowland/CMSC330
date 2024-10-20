


import java.awt.*;
import java.io.*;
import java.util.*;
import javax.swing.*;

// This class provides the skeleton parser for project 1

class Parser {
    private JFrame window;
    private Token token;
    private Lexer lexer;

    // Constructor to create new lexical analyzer from input file

    public Parser(File file) throws IOException {
        lexer = new Lexer(file);
    }

    // Parses the production
    // scene -> SCENE IDENTIFIER number_list images END '.'

    public Scene parseScene() throws LexicalError, SyntaxError, IOException {
        verifyNextToken(Token.SCENE);
        verifyNextToken(Token.IDENTIFIER);
        String window = lexer.getLexeme();
        int[] dimensions = getNumberList(2);
        Scene scene = new Scene(window, dimensions[0], dimensions[1]);
        parseImages(scene, lexer.getNextToken());
        verifyNextToken(Token.PERIOD);
        return scene;
    }

    // Parses the following productions

    // images -> image images | image
    // image -> right_triangle | rectangle
    // right_triangle -> RIGHT_TRIANGLE COLOR number_list AT number_list HEIGHT NUMBER WIDTH NUMBER ';'
    // rectangle -> RECTANGLE_ COLOR number_list AT number_list HEIGHT NUMBER WIDTH NUMBER ';'

    private void parseImages(Scene scene, Token imageToken) 
        throws LexicalError, SyntaxError, IOException {
        
        verifyNextToken(Token.COLOR);
        int[] colors = getNumberList(3);
        Color color = new Color(colors[0], colors[1], colors[2]);
        verifyNextToken(Token.AT);
        int[] location = getNumberList(2);
        Point point = new Point(location[0], location[1]);
        PolygonData pd = PolygonData.PolygonDataBuilder(lexer);

        if (imageToken == Token.RIGHT_TRIANGLE || imageToken == Token.RECTANGLE) {
            scene.addImage(parseHollowPolygon(color, point, imageToken, pd));
        } else if (imageToken == Token.ISOSCELES) {
            scene.addImage(new IsoscelesTriangle(color, point, pd.height, pd.width));
        } else {
            //throw new SyntaxError(lexer.getLineNo(), "Unexpected image name " + imageToken);
        }

        token = lexer.getNextToken();
        if (token != Token.END)
            parseImages(scene, token);
    }

    private HollowPolygon parseHollowPolygon(Color color, Point point, Token token, PolygonData pd) 
        throws LexicalError, SyntaxError, IOException {
        if(token == Token.RIGHT_TRIANGLE) 
            return new RightTriangle(color, point, pd.height, pd.width);
        else
            return new Rectangle(color, point, pd.height, pd.width);
            
    }

    // Parses the following productions

    // number_list -> '(' numbers ')'
    // numbers -> NUMBER | NUMBER ',' numbers

    // Returns an array of the numbers in the number list
    private int[]  getNumberList(int count) throws LexicalError, SyntaxError, IOException {
        int[] list = new int[count];
        verifyNextToken(Token.LEFT_PAREN);
        for (int i = 0; i < count; i++) {
            verifyNextToken(Token.NUMBER);
            list[i] = lexer.getNumber();
            token = lexer.getNextToken();
            if (i < count - 1)
                verifyCurrentToken(Token.COMMA);
            else
                verifyCurrentToken(Token.RIGHT_PAREN);
        }
        return list;
    }

    // Verifies that the next token is the expected token
    private void verifyNextToken(Token expectedToken) throws LexicalError, SyntaxError, IOException {
        token = lexer.getNextToken();
        verifyCurrentToken(expectedToken);
    }

    // Verifies that the current token is the expected token
    private void verifyCurrentToken(Token expectedToken) throws SyntaxError {
        if (token != expectedToken)
            throw new SyntaxError(lexer.getLineNo(), "Expecting token " + expectedToken + " not " + token);
    }
}