public interface PegSolitaireGame {

    public void buildFrame(PegSolitire myGame);

    public void reset();

    public void undo();

    public void keeper(int row,int column);

}