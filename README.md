# Projet INF224 / 0EL11

Auteur : Frédéric SRICHANWIT

Vous trouverez ici mon travail sur le projet de set-top box multimédia dans le cadre de l'UE CSC_0EL11_TP / INF224.

## Code source

Vous trouverez le code source de la partie C++ dans le dossier `cpp` et celui de la partie Swing dans le dossier `swing`

## Compilation et exécution

Pour compiler les fichiers, il suffit de lancer `make` dans un terminal de commande dans les dossiers `cpp` et `swing`. Les deux Makefile sont parfaitement opérationnels.

Pour l'exécution, vous pouvez lancer `make run` dans `cpp` pour lancer le serveur de set-top box multimédia et dans `swing` pour lancer la télécommande. Une interface client en ligne de commande est également disponible dans le dossier `cpp`, vous pouvez l'exécuter en tapant `make run-client`.

ATTENTION : Les fichiers vidéos ne sont pas fournis. Vous pouvez modifier le main de sorte à pouvoir manipuler vos propres vidéos.

## Documentation

Un `Doxyfile` est disponible à la racine du projet. Vous pouvez donc utiliser Doxygen pour générer la documentation du projet, en tapant `doxygen Doxyfile`.

## Réponses aux questions

### Partie C++

#### 4ème étape

La méthode ```play()``` est une méthode virtuelle pure. La déclaration se fait comme suit :
```virtual void play() const = 0;```. Le ```=0``` avec ```virtual``` donne les caractéristiques d'une méthode virtuelle pure.

Après avoir déclaré ```play()``` comme ci-dessus, on ne pourra plus créer d'instances de la classe de base (ici ```Base```) car cette classe est devenu une classe abstraite par la présence d'une méthode virtuelle pure.

#### 5ème étape
- La propriété caractéristique de l'orienté objet permettant de faire cela est le polymorphisme.
- En C++, on doit déclarer les méthodes `play()`et `printValues()` en `virtual`, contrairement à Java par exemple où toutes les méthodes sont virtuelles par défaut.
- Le tableau doit contenir des pointeurs vers les objets Base. En C++, le polymorphisme fonctionne uniquement avec des pointeurs ou des références. Si on stockait des objets directement, on perdrait l’information sur leur type dérivé.
En Java, tous les objets sont par défaut manipulés comme des références, donc ce problème ne se pose pas. En C++ en revanche, on est obligés d'utiliser des pointeurs pour avoir un comportement similaire.

#### 7ème étape

Il faut modifier la classe `Film`. En effet, cette classe contient un tableau d'entiers en attribut, et s'il n'est pas correctement détruit, il y aura une présence de fuite mémoire.

Le problème de la copie d'objet lorsqu'il contient des variables d'instance qui sont des pointeurs est au niveau de la copie de ces pointeurs. Si on copie les pointeurs, on ne crée pas de nouvel objet mais on crée un nouveau pointeur qui pointe vers le même objet, ce qui n'est généralement pas ce que l'on cherche et de plus est une mauvaise idée. En effet, si un programme détruit cet objet, alors les deux pointeurs ne pointerait plus vers rien et seront des `nullptr`, ce qui pourrait poser problème pour le programme.

Pour résoudre ce problème, j'ai créé un constructeur par copie pour la classe `Film`, qui prend en argument un Film et qui renverra une copie profonde de ce film (donc chacun avec son propre tableau de chapitres).

#### 8ème étape

La liste doit être une liste de pointeurs d'objets pour une meilleure gestion et optimisation de la mémoire. De plus, on est dans un cas de polymorphisme, donc utiliser une liste de pointeurs d'objets est indispensable pour créer une liste d'éléments appartenant à des sous-classes de `Base`, sinon on ne pourrait que faire des listes de même classe si on n'utilise pas les pointeurs.

En Java, c'est toujours des pointeurs donc la question ne se pose pas. Les listes d'objets en Java sont forcément des listes de pointeurs d'objets.

#### 10ème étape

Pour interdire la création d'objets multimédias en dehors du gestionnaire, j'ai passé les constructeurs des objets concernés (Base, Photo, Video, Film; Groupe) en `protected` ou `private`, tout dépend de la position hiérarchique des classes (même si on aurait pu tout mettre en `protected`, cela serait possible aussi). En plus de cela, j'ai ajouté la classe `Gestionnaire` qui est la classe de ma base de données en `friend` pour les objets multimédias et les groupes pour que ma base de données (et elle seule) puisse créer de nouveaux objets.

J'ai implémenté cette classe en utilisant le pattern singleton, qui va également empêcher d'avoir plusieurs instances de bases de données.

#### 11ème étape

Les commandes disponibles pour le serveur sont :
- `showmulti` qui va rechercher et afficher (s'il existe) un objet multimédia
- `showgrp` qui va rechercher et afficher (s'il existe) un objet multimédia
- `play` pour jouer un objet multimédia sur le serveur
- `save` pour sauvegarder la base de données vers un fichier dont le nom est passé en argument
- `load` pour charger une nouvelle base de données par dessus l'ancienne dont le nom est passé en argument
- le client peut faire `quit` pour se déconnecter du serveur

#### Sérialisation

J'ai implémenté les méthodes de sérialisation (sauvegarde / charge) pour les objets multimédias et pour la base de données, mais je ne l'ai pas effectué pour les groupes.

### Partie Swing

#### 1ère étape

En ne mettant pas le `JTextArea` dans un `JScrollPane`, on peut remarquer que lorsque la zone de texte est remplie, si on appuie à nouveau sur un bouton pour écrire en plus sur la zone de texte, celui-ci ne s'affiche pas car il sera en dessous du contenu précédent et on ne pourra pas défiler vers le bas pour l'afficher. Mettre la zone de texte dans un `JScrollPane` permet de pallier à ce problème.

#### Suite

La télécommande est équipée d'une zone de texte qui affichera les réponses de la set-top box multimédias et est équipée d'une MenuBar et de cinq boutons. Dans le MenuBar, vous trouverez deux onglets :
- un onglet Fichier où vous trouverez les options pour sauvegarder la base de données dans un fichier ou de charger une nouvelle base de données
- un onglet Rechercher où vous trouverez deux options pour rechercher tous les objets multimédias de la base de données ou tous les groupes.
Sur la télécommande, vous avez cinq boutons :
- un bouton pour se connecter au serveur (une fois connecté, ce bouton se grise et les autres boutons seront accessibles)
- un bouton pour rechercher un objet multimédia
- un bouton pour jouer un objet multimédia
- un bouton pour rechercher un groupe
- un bouton pour fermer la télécommande, qui va se déconnecter du serveur