/**
 * Raymond Rowland
 * Project 1
 * 20 OCT 24
 *
 * Class representing data for polygon attributes, including height, width, 
 * position, offset, sides, radius, and text. It includes a builder method 
 * to parse and populate these attributes from a lexer, handling token verification 
 * and flag setting to track which attributes have been defined. 
*/

import java.awt.Point;
import java.io.IOException;

public class PolygonData {
    public int height;
    public int width;
    public Point position;
    public int offset;
    public int sides;
    public int radius;
    public String text;

    public long flags;

    private static Token token;
    private static Lexer lexer;

    public static PolygonData PolygonDataBuilder (Lexer _lexer) throws LexicalError, IOException, SyntaxError {
        lexer = _lexer;
        token = null;

        PolygonData pd = new PolygonData();
        while ((token = lexer.getNextToken()) != Token.SEMICOLON) {
            switch(token) {
                case HEIGHT:
                    verifyNextToken(Token.NUMBER);
                    pd.height = lexer.getNumber();
                    pd.flags |= PolygonFlags.HEIGHT.flag();
                    break;
                case WIDTH:
                    verifyNextToken(Token.NUMBER);
                    pd.width = lexer.getNumber();
                    pd.flags |= PolygonFlags.WIDTH.flag();    
                    break;
                case LEFT_PAREN:
                    int[] location = getNumberListInside(2);
                    pd.position = new Point(location[0], location[1]); 
                    pd.flags |= PolygonFlags.POINT.flag();  
                    break;               
                case OFFSET:
                    verifyNextToken(Token.NUMBER);
                    pd.offset = lexer.getNumber();
                    pd.flags |= PolygonFlags.OFFSET.flag();
                    break;
                case SIDES:
                    verifyNextToken(Token.NUMBER);
                    pd.sides = lexer.getNumber();
                    pd.flags |= PolygonFlags.SIDES.flag();    
                    break;
                case RADIUS:
                    verifyNextToken(Token.NUMBER);
                    pd.radius = lexer.getNumber();
                    pd.flags |= PolygonFlags.RADIUS.flag();    
                    break;
                case QUOTE:
                    pd.flags |= PolygonFlags.TEXT.flag();
                    pd.text = lexer.getLexeme();
                    break;
                default:
                    break;
            }
        }

        return pd;
    }

    // Verifies that the next token is the expected token
    private static void verifyNextToken(Token expectedToken) throws LexicalError, SyntaxError, IOException {
        token = lexer.getNextToken();
        verifyCurrentToken(expectedToken);
    }

    // Verifies that the current token is the expected token
    private static void verifyCurrentToken(Token expectedToken) throws SyntaxError {
        if (token != expectedToken)
            throw new SyntaxError(lexer.getLineNo(), "Expecting token " + expectedToken + " not " + token);
    }

    private static int[] getNumberListInside(int count) throws LexicalError, SyntaxError, IOException {
        int[] list = new int[count];
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
}
