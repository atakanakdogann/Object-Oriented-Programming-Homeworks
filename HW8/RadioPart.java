import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class RadioPart extends JFrame{
    public JRadioButton rb1,rb2,rb3,rb4,rb5,rb6;
    public JButton b;
    public int selection = 1;
    public int mod;

    /**
     * Created radio buttons and 2 button group.
     * First group for select one of boards, other is user or computer selection.
     */
    public RadioPart(){
        rb1=new JRadioButton("Board 1");
        rb1.setBounds(100,50,100,30);
        rb2=new JRadioButton("Board 2");
        rb2.setBounds(100,80,100,30);
        rb3=new JRadioButton("Board 3");
        rb3.setBounds(100,110,100,30);
        rb4=new JRadioButton("Board 4");
        rb4.setBounds(100,140,100,30);
        rb5=new JRadioButton("User Play");
        rb5.setBounds(40,170,100,30);
        rb6=new JRadioButton("Computer Play");
        rb6.setBounds(140,170,120,30);

        ButtonGroup bg=new ButtonGroup();
        bg.add(rb1);bg.add(rb2);bg.add(rb3);bg.add(rb4);
        ButtonGroup bg2 = new ButtonGroup();
        bg2.add(rb5);bg2.add(rb6);
        b=new JButton("click");
        b.setBounds(100,200,80,30);
        add(rb1);add(rb2);add(rb3);add(rb4);add(rb5);add(rb6);add(b);
        setSize(300,300);
        setLayout(null);
        setVisible(true);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        b.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                if(rb1.isSelected()){
                    selection = 1;
                }
                if(rb2.isSelected()){
                    selection = 2;
                }
                if(rb3.isSelected()){
                    selection = 3;
                }
                if(rb4.isSelected()){
                    selection = 4;
                }
                if(rb5.isSelected()){
                    mod = 1;
                }
                if(rb6.isSelected()){
                    mod = 2;
                }
                dispose();
                MyGridLayout a = new MyGridLayout(mod,selection);
            }
        });
    }
    public int getSelection(){
        return selection;
    }
}

/**
 * import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class RadioPart extends JFrame{
    public JRadioButton rb1,rb2,rb3,rb4;
    public JButton b;
    public int selection = 1;
    public RadioPart(){
        rb1=new JRadioButton("Board 1");
        rb1.setBounds(100,50,100,30);
        rb2=new JRadioButton("Board 2");
        rb2.setBounds(100,80,100,30);
        rb3=new JRadioButton("Board 3");
        rb3.setBounds(100,110,100,30);
        rb4=new JRadioButton("Board 4");
        rb4.setBounds(100,140,100,30);
        ButtonGroup bg=new ButtonGroup();
        bg.add(rb1);bg.add(rb2);bg.add(rb3);bg.add(rb4);
        b=new JButton("click");
        b.setBounds(100,200,80,30);
        add(rb1);add(rb2);add(rb3);add(rb4);add(b);
        setSize(300,300);
        setLayout(null);
        setVisible(true);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        b.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                if(rb1.isSelected()){
                    selection = 1;
                }
                if(rb2.isSelected()){
                    selection = 2;
                    System.out.printf("%d", selection);
                }
                if(rb3.isSelected()){
                    selection = 3;
                }
                if(rb4.isSelected()){
                    selection = 4;
                }
                dispose();
                MyGridLayout a = new MyGridLayout(selection);
            }
        });
    }
    public int getSelection(){
        return selection;
    }
}
 */