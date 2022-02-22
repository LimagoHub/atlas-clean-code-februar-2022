package de.limago;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Fenster extends Frame  {


    public Fenster()  {

        setSize(300, 300);
        Button button = new Button("Drück mich");
        button.addActionListener(new MyActionListener());
        add(button);
    }

    public static void main(String[] args) {
	    new Fenster().setVisible(true);
    }

    private void ausgabe() {
        System.out.println("Button wurde gedrückt");
    }
   class MyActionListener implements ActionListener {

       @Override
       public void actionPerformed(ActionEvent e) {
           ausgabe();
       }
   }
}
