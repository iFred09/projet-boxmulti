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

    private JTextArea textArea;                                 // zone de texte multi-lignes
    private JButton button1, button2, button3, button4, button5;         // les cinq boutons de l'interface

    private JMenuBar menuBar;                                   // menubar
    RemoteClient remoteClient;                                  // Client

    /**
     * @brief Fonction main (programme) qui va lancer la télécommande
     * @param args
     */
    public static void main(String[] args) {
        // System.setProperty("apple.laf.useScreenMenuBar", "true");   // Pour macOS
        new RemoteControl();
    }
    
    /**
     * @brief Constructeur de la classe RemoteControl
     */

    public RemoteControl() {
        setTitle("Télécommande Swing");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Création de la zone de texte
        textArea = new JTextArea(20,30);
        textArea.setEditable(false);
        add(new JScrollPane(textArea), BorderLayout.CENTER);

        // Création des boutons
        JPanel panelBoutons = new JPanel();
        panelBoutons.add(button1 = new JButton("Se connecter au serveur"));
        panelBoutons.add(button2 = new JButton("Rechercher un objet multimédia"));
        panelBoutons.add(button3 = new JButton("Jouer un objet multimédia"));
        panelBoutons.add(button4 = new JButton("Rechercher un groupe d'objets"));
        panelBoutons.add(button5 = new JButton("Quitter"));
        add(panelBoutons, BorderLayout.SOUTH);

        // Ajout des listeners aux boutons
        button1.addActionListener(new ConnectListener());
        button2.addActionListener(new SearchMultimediaListener());
        button3.addActionListener(new PlayMultimediaListener());
        button4.addActionListener(new SearchGroupListener());
        button5.addActionListener(new QuitListener());

        setupMenuBar();         // Création de la barre de menu
        setInteractionButtonsEnabled(false);    // Désactiver les boutons 2 et 3 avant connexion

        // Affichage de la fenêtre
        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    /**
     * @brief Création de la barre de menu
     */
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
    /**
     * @brief Affiche une boîte de dialogue pour demander une entrée à l'utilisateur (pour les boutons de recherche et de lecture)
     * @param message
     * @param commandPrefix
     */
    private void showInputDialog(String message, String commandPrefix) {
        String input = JOptionPane.showInputDialog(this, message);
        if (input != null && !input.trim().isEmpty()) {
            sendRequest(commandPrefix + " " + input);
        }
    }
    /**
     * @brief Activer ou désactiver les boutons de recherche et de lecture (après connexion/déconnexion)
     * @param enabled
     */
    private void setInteractionButtonsEnabled(boolean enabled) {
        button2.setEnabled(enabled);
        button3.setEnabled(enabled);
        button4.setEnabled(enabled);
    }
    /**
     * @brief Envoie une requête au serveur et affiche la réponse dans la zone de texte
     * @param request
     */
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
    /**
     * @brief Classe interne pour gérer l'événement de connexion
     */
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
    /**
     * @brief Classe interne pour gérer l'événement de recherche de tous les multimédias
     */
    class MultimediaListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            sendRequest("affichermulti all");
        }
    }
    /**
     * @brief Classe interne pour gérer l'événement de recherche de tous les groupes
     */
    class GroupListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            sendRequest("affichergrp all");
        }
    }
    /**
     * @brief Classe interne pour gérer l'événement de recherche d'un objet multimédia
     */
    class SearchMultimediaListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            showInputDialog("Entrez le nom de l'objet multimédia à rechercher :", "affichermulti");
        }
    }
    /**
     * @brief Classe interne pour gérer l'événement de recherche d'un groupe
     */
    class SearchGroupListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            showInputDialog("Entrez le nom du groupe d'objets à rechercher :", "affichergrp");
        }
    }
    /**
     * @brief Classe interne pour gérer l'événement de lecture
     */
    class PlayMultimediaListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            showInputDialog("Entrez le nom de l'objet multimédia à jouer :", "play");
        }
    }
    /**
     * @brief Classe interne pour gérer l'événement de sauvegarde de la base de données
     */
    class SaveDatabaseListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            showInputDialog("Entrez le chemin du fichier de sauvegarde :", "save");
        }
    }
    /**
     * @brief Classe interne pour gérer l'événement de chargement d'une nouvelle base de données
     */
    class LoadDatabaseListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            showInputDialog("Entrez le chemin du fichier à charger :", "load");
        }
    }
    /**
     * @brief Classe interne pour gérer l'événement de quitter
     */
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