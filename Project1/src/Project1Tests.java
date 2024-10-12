

import static org.junit.Assert.assertEquals;

import java.io.File;
import java.io.IOException;
import org.junit.Test;

public class Project1Tests {
    private boolean AttemptParse(String sceneFileName) {
        try {
            File sceneFile = new File(sceneFileName);
            Parser parser = new Parser(sceneFile);
            Scene scene = parser.parseScene();
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
}
