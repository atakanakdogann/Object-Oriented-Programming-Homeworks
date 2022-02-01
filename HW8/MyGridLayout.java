import java.awt.*;
import javax.swing.*;
import java.awt.event.*;


public class MyGridLayout extends JFrame implements PegSolitaireGame{
    public static int movecnt = 0;
    public static int cnt = 0;
    public int coordinates[] = new int[4];
    public JFrame f;
    JLabel label;
    public JButton buttons[][];
    public PegSolitire game;
    public int selection;

    public MyGridLayout(){

    }
    /**
     * Mod is for userGame or computerGame.
     * Select for board selection
     * Label for Score.
     * @param mod
     * @param select
     */
    public MyGridLayout(int mod,int select)
    {
        selection = select;
        game = new PegSolitire(select);
        label = new JLabel();
        label.setVisible(false);
        label.setBounds(530,410, 100, 50);
       
        
        if(mod == 1){
            buildFrame(game);
        }
        else if(mod == 2){
            game.playGame();
            buildFrame(game);
            if(game.isFinished() == true){
                f.add(label);
                label.setVisible(true);
                label.setText("Score:"+game.getScore());
                
            }
        }
       
    }
    /**
     * First I created frame f and After initialized special buttons.
     * Last I initialized PegSolitaire buttons for game and added all to JFrame
     * @param myGame
     */
    public void buildFrame(PegSolitire myGame){
        f = new JFrame("Peg Solitaire Game");
        buttons = new JButton[myGame.getSize_()][myGame.getSize_()];
        f.setLayout(null);
        f.setSize(700,630);

        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JButton undoButton = new JButton("Undo");
        f.add(undoButton);
        undoButton.setBounds(550,350,100,50);
        undoButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                if (e.getSource() instanceof JButton) {
                    if(cnt == 0){
                        undo();
                    }

                }
            }
        });
        JButton resetButton = new JButton("Reset");
        f.add(resetButton);
        resetButton.setBounds(550,290,100,50);
        resetButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                if (e.getSource() instanceof JButton) {
                    reset();

                }
            }
        });
        JButton saveFile = new JButton("Save");
        f.add(saveFile);
        saveFile.setBounds(550,230,100,50);
        saveFile.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                if (e.getSource() instanceof JButton) {
                    JFrame f2= new JFrame();  
                    JTextField t = new JTextField("Enter filename");;
                    JButton b = new JButton("Enter");
                    b.setBounds(100,140,100,50);
                    b.addActionListener(new ActionListener(){
                        public void actionPerformed(ActionEvent e){
                            if (e.getSource() instanceof JButton) {
                                myGame.writeToFile(t.getText());
                                f2.dispose();       
                            }
                        }
                    });
                    t.setBounds(50,100, 200,30);  
                    f2.add(t); 
                    f2.add(b);
                    f2.setSize(300,300);  
                    f2.setLayout(null);  
                    f2.setVisible(true);

                }
            }
        });
        JButton loadFile = new JButton("Load");
        f.add(loadFile);
        loadFile.setBounds(550,170,100,50);
        loadFile.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                if (e.getSource() instanceof JButton) {
                    JFrame f2= new JFrame();  
                    JTextField t = new JTextField("Enter filename");;
                    JButton b = new JButton("Enter");
                    b.setBounds(100,140,100,50);
                    b.addActionListener(new ActionListener(){
                        public void actionPerformed(ActionEvent e){
                            if (e.getSource() instanceof JButton) {
                                myGame.readFromFile(t.getText());
                                for(int i = 0;i<myGame.getSize_();i++){
                                    for(int j = 0;j<myGame.getSize_();j++){
                                        if(myGame.board[i][j] == Cell.peg){
                                            buttons[i][j].setText("P");
                                        }
                                        else if(myGame.board[i][j] == Cell.dot){
                                            buttons[i][j].setText(".");
                                        }
                                    }
                                    
                                }
                                f2.dispose();       
                            }
                        }
                    });
                    t.setBounds(50,100, 200,30);  
                    f2.add(t); 
                    f2.add(b);
                    f2.setSize(300,300);  
                    f2.setLayout(null);  
                    f2.setVisible(true);  

                }
            }
        });
        JButton clone = new JButton("Clone");
        f.add(clone);
        clone.setBounds(550,110,100,50);
        clone.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                if (e.getSource() instanceof JButton) {
                    System.out.println("Clone not working");
                }
            }
        });
       


        for(int i = 0;i < myGame.getSize_();i++){
            for(int j = 0;j < myGame.getSize_();j++){
                    if(myGame.board[i][j] == Cell.peg){
                        buttons[i][j] = new JButton("P");
                        buttons[i][j].setBounds(50*j,50*i,50,50);
                        f.add(buttons[i][j]);
                    }
                    else if(myGame.board[i][j] == Cell.dot){
                        buttons[i][j] = new JButton(".");
                        buttons[i][j].setBounds(50*j,50*i,50,50);
                        f.add(buttons[i][j]);

                    }
                    
                    final int r = i,c = j;
                if(myGame.board[i][j] != Cell.empty){
                    buttons[i][j].addActionListener(new ActionListener(){
                        public void actionPerformed(ActionEvent e){
                            if (e.getSource() instanceof JButton) {
                                keeper(r,c);
                            }
                        }
                    });
                }


            }

        }
    }
    /**
     * Recreates PegSolitaire array and changes buttons
     */
    public void reset(){
        game = new PegSolitire(selection);
        for(int i = 0;i<game.getSize_();i++){
            for(int j = 0;j<game.getSize_();j++){
                if(game.board[i][j] == Cell.peg){
                    buttons[i][j].setText("P");
                }
                else if(game.board[i][j] == Cell.dot){
                    buttons[i][j].setText(".");
                }
            }
        }
        movecnt = 0;
    }
    
    /**
     * Coordinates array keeps last 2 mouse click basically.
     * I explicitly initialized size of 4 because only one undo move.
    */
    public void undo(){
        if(movecnt != 0){
            buttons[coordinates[0]][coordinates[1]].setText("P");
            buttons[coordinates[2]][coordinates[3]].setText(".");
            buttons[(coordinates[0]+coordinates[2])/2][(coordinates[1]+coordinates[3])/2].setText("P");
            game.board[coordinates[0]][coordinates[1]] = Cell.peg;
            game.board[coordinates[2]][coordinates[3]] = Cell.dot;
            game.board[(coordinates[0]+coordinates[2])/2][(coordinates[1]+coordinates[3])/2] = Cell.peg;
        }

    }
    /**
     * When mouse is clicked coordinates array stores.
     * If you click 2 times,cnt counter reaches 4 and plays.
     * If play succesfull via true buttons changes and controls is game finished or not
     * If game finished, score will be printed
     * @param row
     * @param column
     */
    public void keeper(int row,int column){
        coordinates[cnt++] = row;
        coordinates[cnt++] = column;
        if(cnt == 4){
            if(game.playUser(coordinates[0],coordinates[1],coordinates[2],coordinates[3]) == true){
                movecnt++;
                buttons[coordinates[0]][coordinates[1]].setText(".");
                buttons[coordinates[2]][coordinates[3]].setText("P");
                buttons[(coordinates[0]+coordinates[2])/2][(coordinates[1]+coordinates[3])/2].setText(".");
            }
            cnt = 0;
            
        }
        if(game.isFinished() == true){
            f.add(label);
            label.setVisible(true);
            label.setText("Score:"+game.getScore());
            
        }
    }

}