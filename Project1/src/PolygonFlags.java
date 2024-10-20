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
