/**
 * @file RemoteControl.java
 * @author Frédéric SRICHANWIT (frederic.srichanwit@telecom-paris.fr)
 * @brief Classe pour la télécommande Java Swing
 * @version 1.0
 * @date 2025-01-27
 *
 * @copyright Copyright (c) 2025
 */

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

/**
 * @class RemoteControl
 * @brief Classe pour la télécommande Java Swing
 */
public class RemoteControl extends JFrame {
    private static final long serialVersionUID = 1L;

    private JTextArea textArea;
    private JButton button1, button2, button3, button4, button5;

    private JMenuBar menuBar;
    RemoteClient remoteClient = null;

    public static void main(String[] args) {
        new RemoteControl();
    }

    public RemoteControl() {
        setTitle("Fenêtre Principale");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        textArea = new JTextArea(20,30);
        textArea.setEditable(false);
        add(new JScrollPane(textArea), BorderLayout.CENTER);

        JPanel panelBoutons = new JPanel();
        panelBoutons.add(button1 = new JButton("Se connecter au serveur"));
        panelBoutons.add(button2 = new JButton("Rechercher un objet multimédia"));
        panelBoutons.add(button3 = new JButton("Rechercher un groupe"));
        panelBoutons.add(button4 = new JButton("Jouer un objet multimédia"));
        panelBoutons.add(button5 = new JButton("Quitter"));
        add(panelBoutons, BorderLayout.SOUTH);

        button1.addActionListener(new ConnectListener());
        button2.addActionListener(new SearchMultimediaListener());
        button3.addActionListener(new SearchGroupListener());
        button4.addActionListener(new PlayMultimediaListener());
        button5.addActionListener(new QuitListener());

        setupMenuBar();
        setInteractionButtonsEnabled(false);

        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    private void setupMenuBar() {
        menuBar = new JMenuBar();

        JMenu menuFichier = new JMenu("Fichier");
        JMenuItem saveItem = new JMenuItem("Sauvegarder la base de données");
        JMenuItem loadItem = new JMenuItem("Importer une base de données");
        JMenuItem quitItem = new JMenuItem("Quitter");
        saveItem.addActionListener(new SaveDatabaseListener());
        loadItem.addActionListener(new LoadDatabaseListener());
        quitItem.addActionListener(new QuitListener());
        menuFichier.add(saveItem);
        menuFichier.add(loadItem);
        menuFichier.add(quitItem);

        JMenu menuRecherche = new JMenu("Rechercher");
        JMenuItem searchAllMultimedia = new JMenuItem("Rechercher tous les objets multimédias");
        JMenuItem searchAllGroups = new JMenuItem("Rechercher tous les groupes");
        searchAllMultimedia.addActionListener(new MultimediaListener());
        searchAllGroups.addActionListener(new GroupListener());
        menuRecherche.add(searchAllMultimedia);
        menuRecherche.add(searchAllGroups);

        menuBar.add(menuFichier);
        menuBar.add(menuRecherche);

        setJMenuBar(menuBar);
    }

    private void showInputDialog(String message, String commandPrefix) {
        String input = JOptionPane.showInputDialog(this, message);
        if (input != null && !input.trim().isEmpty()) {
            sendRequest(commandPrefix + " " + input);
        }
    }

    private void setInteractionButtonsEnabled(boolean enabled) {
        button2.setEnabled(enabled);
        button3.setEnabled(enabled);
        button4.setEnabled(enabled);
    }

    private void sendRequest(String request) {
        if (remoteClient == null) {
            textArea.append("RemoteClient non connecté.\n");
            return;
        }
        String response = remoteClient.send(request);
        response = response.replace(';', '\n');
        if (response != null) {
            textArea.append("> " + request + "\nRéponse: " + response + "\n");
        } else {
            textArea.append("Erreur de communication avec le serveur.\n");
        }
    }

    class ConnectListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            try {
                remoteClient = new RemoteClient(RemoteClient.DEFAULT_HOST, RemoteClient.DEFAULT_PORT);
                textArea.append("Connecté au serveur.\n");
                button1.setEnabled(false); // Désactiver le bouton après connexion réussie
                setInteractionButtonsEnabled(true);
            } catch (IOException ex) {
                textArea.append("Erreur de connexion au serveur.\n");
            }
        }
    }

    class MultimediaListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            sendRequest("afficher multimédias");
        }
    }

    class GroupListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            sendRequest("afficher groupes");
        }
    }

    class SearchMultimediaListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            showInputDialog("Entrez le nom de l'objet multimédia :", "afficher");
        }
    }

    class SearchGroupListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            showInputDialog("Entrez le nom du groupe :", "afficher");
        }
    }

    class PlayMultimediaListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            showInputDialog("Entrez le nom de l'objet multimédia à jouer :", "play");
        }
    }

    class SaveDatabaseListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            showInputDialog("Entrez le chemin du fichier de sauvegarde :", "save");
        }
    }

    class LoadDatabaseListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            showInputDialog("Entrez le chemin du fichier à charger :", "load");
        }
    }

    class QuitListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            try {
                if (remoteClient != null) {
                    remoteClient.send("quit");
                }
            } finally {
                System.exit(0);
            }
        }
    }
}