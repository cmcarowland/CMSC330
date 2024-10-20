/**
 * Raymond Rowland
 * Project 1
 * 20 OCT 24
 *
 * Enum representing various flags for polygon properties.
 * Each flag corresponds to a specific attribute, and 
 * includes a method to return a unique bit value for 
 * each flag based on its ordinal position.
*/

public enum PolygonFlags {
    WIDTH,
    HEIGHT,
    POINT,
    OFFSET,
    SIDES,
    RADIUS,
    TEXT;

    public long flag () {
        return 1 << this.ordinal();
    }
}
