import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;
import java.io.IOException;
import java.util.Random;
public class PegSolitire extends MyGridLayout {

    /**
     * Created board according to parameter and initialize size.
     * @param selection
     */
    public PegSolitire(int selection){
        if(selection == 1){
            size_ = 7;
            board[0][0] = Cell.empty;  board[0][1] = Cell.empty;  board[0][2] = Cell.peg;  board[0][3] = Cell.peg;    board[0][4] = Cell.peg;  board[0][5] = Cell.empty;  board[0][6] = Cell.empty;
            board[1][0] = Cell.empty;  board[1][1] = Cell.peg;  board[1][2] = Cell.peg;  board[1][3] = Cell.peg;    board[1][4] = Cell.peg;  board[1][5] = Cell.peg;  board[1][6] = Cell.empty;
            board[2][0] = Cell.peg;  board[2][1] = Cell.peg;  board[2][2] = Cell.peg;  board[2][3] = Cell.dot;  board[2][4] = Cell.peg;  board[2][5] = Cell.peg;  board[2][6] = Cell.peg;
            board[3][0] = Cell.peg;  board[3][1] = Cell.peg;  board[3][2] = Cell.peg;  board[3][3] = Cell.peg;  board[3][4] = Cell.peg;  board[3][5] = Cell.peg;  board[3][6] = Cell.peg;
            board[4][0] = Cell.peg;  board[4][1] = Cell.peg;  board[4][2] = Cell.peg;  board[4][3] = Cell.peg;  board[4][4] = Cell.peg;  board[4][5] = Cell.peg;  board[4][6] = Cell.peg;
            board[5][0] = Cell.empty;  board[5][1] = Cell.peg;  board[5][2] = Cell.peg;  board[5][3] = Cell.peg;    board[5][4] = Cell.peg;  board[5][5] = Cell.peg;  board[5][6] = Cell.empty;
            board[6][0] = Cell.empty;  board[6][1] = Cell.empty;  board[6][2] = Cell.peg;  board[6][3] = Cell.peg;    board[6][4] = Cell.peg;  board[6][5] = Cell.empty;  board[6][6] = Cell.empty;
        }
        else if(selection == 2){
            size_ = 9;
            board[0][0] = Cell.empty;  board[0][1] = Cell.empty;    board[0][2] = Cell.empty;   board[0][3] = Cell.peg;  board[0][4] = Cell.peg;    board[0][5] = Cell.peg;   board[0][6] = Cell.empty;   board[0][7] = Cell.empty;  board[0][8] = Cell.empty;
            board[1][0] = Cell.empty;  board[1][1] = Cell.empty;    board[1][2] = Cell.empty;   board[1][3] = Cell.peg;  board[1][4] = Cell.peg;    board[1][5] = Cell.peg;   board[1][6] = Cell.empty;   board[1][7] = Cell.empty;  board[1][8] = Cell.empty;
            board[2][0] = Cell.empty;  board[2][1] = Cell.empty;    board[2][2] = Cell.empty;   board[2][3] = Cell.peg;  board[2][4] = Cell.peg;    board[2][5] = Cell.peg;   board[2][6] = Cell.empty;   board[2][7] = Cell.empty;  board[2][8] = Cell.empty;
            board[3][0] = Cell.peg;  board[3][1] = Cell.peg;  board[3][2] = Cell.peg;  board[3][3] = Cell.peg;  board[3][4] = Cell.peg;  board[3][5] = Cell.peg;  board[3][6] = Cell.peg;   board[3][7] = Cell.peg; board[3][8] = Cell.peg;
            board[4][0] = Cell.peg;  board[4][1] = Cell.peg;  board[4][2] = Cell.peg;  board[4][3] = Cell.peg;  board[4][4] = Cell.dot;  board[4][5] = Cell.peg;  board[4][6] = Cell.peg;   board[4][7] = Cell.peg; board[4][8] = Cell.peg;
            board[5][0] = Cell.peg;  board[5][1] = Cell.peg;  board[5][2] = Cell.peg;  board[5][3] = Cell.peg;  board[5][4] = Cell.peg;  board[5][5] = Cell.peg;  board[5][6] = Cell.peg;   board[5][7] = Cell.peg; board[5][8] = Cell.peg;
            board[6][0] = Cell.empty;  board[6][1] = Cell.empty;    board[6][2] = Cell.empty;   board[6][3] = Cell.peg;  board[6][4] = Cell.peg;    board[6][5] = Cell.peg;   board[6][6] = Cell.empty;   board[6][7] = Cell.empty;  board[6][8] = Cell.empty;
            board[7][0] = Cell.empty;  board[7][1] = Cell.empty;    board[7][2] = Cell.empty;   board[7][3] = Cell.peg;  board[7][4] = Cell.peg;    board[7][5] = Cell.peg;   board[7][6] = Cell.empty;   board[7][7] = Cell.empty;  board[7][8] = Cell.empty;
            board[8][0] = Cell.empty;  board[8][1] = Cell.empty;    board[8][2] = Cell.empty;   board[8][3] = Cell.peg;  board[8][4] = Cell.peg;    board[8][5] = Cell.peg;   board[8][6] = Cell.empty;   board[8][7] = Cell.empty;  board[8][8] = Cell.empty;

        }
        else if(selection == 3){
            size_ = 8;
            board[0][0] = Cell.empty;  board[0][1] = Cell.empty;  board[0][2] = Cell.peg;  board[0][3] = Cell.peg;    board[0][4] = Cell.peg;  board[0][5] = Cell.empty;  board[0][6] = Cell.empty; board[0][7] = Cell.empty;
            board[1][0] = Cell.empty;  board[1][1] = Cell.empty;  board[1][2] = Cell.peg;  board[1][3] = Cell.peg;    board[1][4] = Cell.peg;  board[1][5] = Cell.empty;  board[1][6] = Cell.empty; board[1][7] = Cell.empty;
            board[2][0] = Cell.empty;  board[2][1] = Cell.empty;  board[2][2] = Cell.peg;  board[2][3] = Cell.peg;    board[2][4] = Cell.peg;  board[2][5] = Cell.empty;  board[2][6] = Cell.empty; board[2][7] = Cell.empty;
            board[3][0] = Cell.peg;  board[3][1] = Cell.peg;  board[3][2] = Cell.peg;  board[3][3] = Cell.peg;  board[3][4] = Cell.peg;  board[3][5] = Cell.peg;  board[3][6] = Cell.peg;   board[3][7] = Cell.peg;
            board[4][0] = Cell.peg;  board[4][1] = Cell.peg;  board[4][2] = Cell.peg;  board[4][3] = Cell.dot;  board[4][4] = Cell.peg;  board[4][5] = Cell.peg;  board[4][6] = Cell.peg;   board[4][7] = Cell.peg;
            board[5][0] = Cell.peg;  board[5][1] = Cell.peg;  board[5][2] = Cell.peg;  board[5][3] = Cell.peg;  board[5][4] = Cell.peg;  board[5][5] = Cell.peg;  board[5][6] = Cell.peg;   board[5][7] = Cell.peg;
            board[6][0] = Cell.empty;  board[6][1] = Cell.empty;    board[6][2] = Cell.peg;   board[6][3] = Cell.peg;  board[6][4] = Cell.peg;    board[6][5] = Cell.empty;   board[6][6] = Cell.empty;   board[6][7] = Cell.empty;
            board[7][0] = Cell.empty;  board[7][1] = Cell.empty;    board[7][2] = Cell.peg;   board[7][3] = Cell.peg;  board[7][4] = Cell.peg;    board[7][5] = Cell.empty;   board[7][6] = Cell.empty;   board[7][7] = Cell.empty;
        }
        else if(selection == 4){
            size_ = 7;
            board[0][0] = Cell.empty;  board[0][1] = Cell.empty;  board[0][2] = Cell.peg;  board[0][3] = Cell.peg;    board[0][4] = Cell.peg;  board[0][5] = Cell.empty;  board[0][6] = Cell.empty;
            board[1][0] = Cell.empty;  board[1][1] = Cell.empty;  board[1][2] = Cell.peg;  board[1][3] = Cell.peg;    board[1][4] = Cell.peg;  board[1][5] = Cell.empty;  board[1][6] = Cell.empty;
            board[2][0] = Cell.peg;  board[2][1] = Cell.peg;  board[2][2] = Cell.peg;  board[2][3] = Cell.peg;  board[2][4] = Cell.peg;  board[2][5] = Cell.peg;  board[2][6] = Cell.peg;
            board[3][0] = Cell.peg;  board[3][1] = Cell.peg;  board[3][2] = Cell.peg;  board[3][3] = Cell.dot;  board[3][4] = Cell.peg;  board[3][5] = Cell.peg;  board[3][6] = Cell.peg;
            board[4][0] = Cell.peg;  board[4][1] = Cell.peg;  board[4][2] = Cell.peg;  board[4][3] = Cell.peg;  board[4][4] = Cell.peg;  board[4][5] = Cell.peg;  board[4][6] = Cell.peg;
            board[5][0] = Cell.empty;  board[5][1] = Cell.empty;  board[5][2] = Cell.peg;  board[5][3] = Cell.peg;    board[5][4] = Cell.peg;  board[5][5] = Cell.empty;  board[5][6] = Cell.empty;
            board[6][0] = Cell.empty;  board[6][1] = Cell.empty;  board[6][2] = Cell.peg;  board[6][3] = Cell.peg;    board[6][4] = Cell.peg;  board[6][5] = Cell.empty;  board[6][6] = Cell.empty;
        }
    }
    /**
     * Opens file according to parameter and writes board to file 
     * @param fileName
     */
    public void writeToFile(String fileName){
        try {
            File fileObject = new File(fileName);
            FileWriter file = new FileWriter(fileName);
            for(int i = 0;i<size_;i++){
                for(int j = 0;j<size_;j++){
                    if(board[i][j] == Cell.peg){
                        file.write("P");
                    }
                    else if(board[i][j] == Cell.dot){
                        file.write(".");
                    }
                    else if(board[i][j] == Cell.empty){
                        file.write(" ");
                    }

                }
                file.write("\n");
            }
            file.close();
        }
        catch (IOException exception) {
            System.out.println("Warning! There is an error");
            exception.printStackTrace();
        }
    }
    /**
     * Loads from given filename
     * @param filename
     */
    public void readFromFile(String filename){
        try {
            File myObj = new File(filename);
            Scanner myReader = new Scanner(myObj);
            int i = 0;
            while (myReader.hasNextLine()) {
                int j = 0;
                String data = myReader.nextLine();
                if(data.length() != size_){
                    System.out.println("Board and text Board didn't match!");
                    return;
                }
                for(int a = 0;a<data.length();a++){

                    char c = data.charAt(a);
                    if(c == 'P'){
                        board[i][j] = Cell.peg;
                        j++;
                    }
                    else if(c == '.'){
                        board[i][j] = Cell.dot;
                        j++;
                    }
                    else if(c == ' '){
                        board[i][j] = Cell.empty;
                        j++;
                    }    
                }
                i++;
            }  
            myReader.close();
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

    }

    /**
     * Controls game finished or not
     * First controls right and down,left,up
     * If there is pp. trio returns false
     * @return
     */
    public boolean isFinished(){
        for(int i = 0;i<size_;i++){
            for(int j = 0;j<size_-2;j++){
                if(board[i][j] == Cell.peg && board[i][j+1] == Cell.peg && board[i][j+2] == Cell.dot){
                    return false;
                }
            }
        }

        for(int i = 0;i<size_-2;i++){
            for(int j = 0;j<size_;j++){
                if(board[i][j] == Cell.peg && board[i+1][j] == Cell.peg && board[i+2][j] == Cell.dot){
                    return false;
                }
            }
        }

        for(int i = 0;i<size_;i++){
            for(int j = 2;j<size_;j++){
                if(board[i][j] == Cell.peg && board[i][j-1] == Cell.peg && board[i][j-2] == Cell.dot){
                    return false;
                }
            }
        }

        for(int i = 2;i<size_;i++){
            for(int j = 0;j<size_;j++){
                if(board[i][j] == Cell.peg && board[i-1][j] == Cell.peg && board[i-2][j] == Cell.dot){
                    return false;
                }
            }
        }
        return true;
    }
    /**
     * Only plays move. I added and divide 2 for flexibility across the ways
     * @param row1
     * @param column1
     * @param row2
     * @param column2
     * @return
     */
    public boolean playUser(int row1,int column1,int row2,int column2){
        if(row1-2 == row2 || row1+2 == row2 || column1-2 == column2 || column1+2 == column2){
            if(board[row1][column1] == Cell.peg && board[row2][column2] == Cell.dot && board[(row1+row2)/2][(column1+column2)/2] == Cell.peg){
                board[row1][column1] = Cell.dot;
                board[(row1+row2)/2][(column1+column2)/2] =Cell.dot;
                board[row2][column2] = Cell.peg;
                return true;
            }
        }
        return false;
    }
    /**
     * Random number generates and does one move.
     */
    public void playComputer(){
        Random rand = new Random();
        int random = rand.nextInt(4);

        if(random == 0){
            for(int i = 0;i<size_;i++){
                for(int j = 0;j<size_-2;j++){
                    if(board[i][j] == Cell.peg && board[i][j+1] == Cell.peg && board[i][j+2] == Cell.dot){
                        board[i][j] = Cell.dot;
                        board[i][j+1] = Cell.dot;
                        board[i][j+2] = Cell.peg;
                        return;
                    }
                }
            }
        }
        else if(random == 1){
            for(int i = 0;i<size_-2;i++){
                for(int j = 0;j<size_;j++){
                    if(board[i][j] == Cell.peg && board[i+1][j] == Cell.peg && board[i+2][j] == Cell.dot){
                        board[i][j] = Cell.dot;
                        board[i+1][j] = Cell.dot;
                        board[i+2][j] = Cell.peg;
                        return;
                    }
                }
            }
        }
        else if(random == 2){
            for(int i = 0;i<size_;i++){
                for(int j = 2;j<size_;j++){
                    if(board[i][j] == Cell.peg && board[i][j-1] == Cell.peg && board[i][j-2] == Cell.dot){
                        board[i][j] = Cell.dot;
                        board[i][j-1] = Cell.dot;
                        board[i][j-2] = Cell.peg;
                        return;
                    }
                }
            }
        }
        else if(random == 3){
            for(int i = 2;i<size_;i++){
                for(int j = 0;j<size_;j++){
                    if(board[i][j] == Cell.peg && board[i-1][j] == Cell.peg && board[i-2][j] == Cell.dot){
                        board[i][j] = Cell.dot;
                        board[i-1][j] = Cell.dot;
                        board[i-2][j] = Cell.peg;
                        return;
                    }
                }
            }
        }
    }
    /**
     * Computer play till end method.
     * 
     */
    public void playGame(){
        while(!isFinished()){
            playComputer();
        }
        return;
    }
    public int score = 0;
    /**
     * Returns Score
     * @return
     */
    public int getScore(){
        for(int i = 0;i<size_;i++){
            for(int j = 0;j<size_;j++){
                if(board[i][j] == Cell.peg){
                    score++;
                }
            }
        }
        return score;
    }
    public int size_=10;
    /**
     * Returns Size
     * @return
     */
    public int getSize_(){
        return size_;
    }

    Cell board[][] = new Cell[10][10];
}