/**
 * Raymond Rowland
 * Project 1
 * 20 OCT 24
 *
 * Unit tests for validating the parsing of scene files in the project.
 * Each test attempts to parse a specific scene file and asserts that 
 * the parsing succeeds, checking various polygon types and text elements.
*/

import static org.junit.Assert.assertEquals;

import java.io.File;
import java.io.IOException;
import org.junit.Test;

public class Project1Tests {
    private boolean AttemptParse(String sceneFileName) {
        try {
            File sceneFile = new File(sceneFileName);
            Parser parser = new Parser(sceneFile);
            parser.parseScene();
        } catch (SyntaxError error) {
            return false;
        } catch (LexicalError error) {
            return false;
        } catch (IOException error) {
            return false;
        }

        return true;
    }

    @Test
    public void TestStandard() {
        assertEquals(true, AttemptParse("/Volumes/Hard Drive/Documents/College/CMSC330/Project1/scene.txt"));
    }

    @Test
    public void TestIso() {
        assertEquals(true, AttemptParse("/Volumes/Hard Drive/Documents/College/CMSC330/Project1/scene_iso.txt"));
    }
    
    @Test
    public void TestParallogram() {
        assertEquals(true, AttemptParse("/Volumes/Hard Drive/Documents/College/CMSC330/Project1/scene_para.txt"));
    }

    @Test
    public void TestRegular() {
        assertEquals(true, AttemptParse("/Volumes/Hard Drive/Documents/College/CMSC330/Project1/scene_regular.txt"));
    }

    @Test
    public void TestText() {
        assertEquals(true, AttemptParse("/Volumes/Hard Drive/Documents/College/CMSC330/Project1/scene_text.txt"));
    }

    @Test
    public void TestStandardInvalid() {
        assertEquals(false, AttemptParse("/Volumes/Hard Drive/Documents/College/CMSC330/Project1/sceneBad.txt"));
    }

    @Test
    public void TestIsoBad() {
        assertEquals(false, AttemptParse("/Volumes/Hard Drive/Documents/College/CMSC330/Project1/scene_isoBad.txt"));
    }
    
    @Test
    public void TestParallogramBad() {
        assertEquals(false, AttemptParse("/Volumes/Hard Drive/Documents/College/CMSC330/Project1/scene_paraBad.txt"));
    }

    @Test
    public void TestRegularBad() {
        assertEquals(false, AttemptParse("/Volumes/Hard Drive/Documents/College/CMSC330/Project1/scene_regularBad.txt"));
    }

    @Test
    public void TestTextBad() {
        assertEquals(false, AttemptParse("/Volumes/Hard Drive/Documents/College/CMSC330/Project1/scene_textBad.txt"));
    }
}
