import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FenetrePrincipale extends JFrame {
    private static final long serialVersionUID = 1L;

    private JTextArea textArea;
    private JButton button1, button2, button3;

    public static void main(String[] args) {
        new FenetrePrincipale();
    }

    public FenetrePrincipale() {
        setTitle("Fenêtre Principale");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        textArea = new JTextArea(10,30);
        textArea.setEditable(false);
        add(new JScrollPane(textArea), BorderLayout.CENTER);

        JPanel panelBoutons = new JPanel();
        panelBoutons.add(button1 = new JButton("Bouton 1"));
        panelBoutons.add(button2 = new JButton("Bouton 2"));
        panelBoutons.add(button3 = new JButton("Bouton 3"));
        add(panelBoutons, BorderLayout.SOUTH);

        button1.addActionListener(new ButtonListener("premier bouton !!!"));
        button2.addActionListener(new ButtonListener("Bouton 2 : ajoute une ligne"));
        button3.addActionListener(new QuitListener());

        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    class ButtonListener implements ActionListener {
        private String texte;

        public ButtonListener(String texte) {
            this.texte = texte;
        }

        public void actionPerformed(ActionEvent e) {
            textArea.append(texte + "\n");
        }
    }

    class QuitListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }
}