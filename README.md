## Projet A : Alizée Hett ([lien du projet](https://gitlab.com/dinholu1/CPP-TP01-HETTALIZEE/-/tree/main/TP3_Hett_Alizee?ref_type=heads))

### 1. Single Responsability Unique (SRP)

- La classe `Board` viole le SRP du fait que : la méthode `checkWin()` devrait être une propriété de la classe Jeu, et que la méthode `placeMarker()` pourrait être déplacée vers la classe Joueur, qui, par logique métier, est responsable du placement des pions.
  - Proposition d'optimisation : Sectionner `checkWin()` en méthodes distinctes (`checkRow()`, `checkColumns()`, `checkDiagonal()`).
- La classe `ComputerPlayer` viole le SRP car sa méthode `makeMove()` gère le placement des pions pour tous les jeux (morpion et puissance4), ce qui devrait être sectionné par jeu.
    - Proposition d'optimisation : passer par une interface de jeu dont les classes héritées implémenteront la méthode `makeMove()` spécifique au règle de jeu.
- La classe `Game`, `TicTacToe`, et `ConnectFour` viole également le SRP car les  méthodes `makeMove()` et `displayBoard()` ne devraient pas être implémentées dans Game, mais dans les classes Player et Board respectivement.

### 2. Principe Ouvert/Fermé (OCP)

- La classe `Board` viole le principe OCP car la méthode `placeMarker()` nécessite des paramètres supplémentaires pour s'adapter à différents jeux. Ainsi, en cas de rajout de nouveaux jeux, il est nécessaire d'aller modifier cette classe. 
- La classe `TicTacToe` et `ConnectFour` viole le principe OCP, car le constructeur de ces classes est fortement couplé à la classe `Board`. De ce fait, des modifications à `Board` nécessiteraient des modifications dans ces classes.

### 3. Principe de Substitution de Liskov (LSP)

Ce principe est globalement bien respectée du fait que l'outil utilisé (QtCreator) nous empêche de faire des erreurs de non-implémentation de méthode d'une clase abstraite dans une classe fille.
Notamment sur la classe `Game` -> `Tictactoe` et `ConnectFour`.
Cependant, la classe `ComputerPlayer` par exemple ne pourrait pas se substituer à sa super-classe `Player` du fait qu'elle implémente une méthode `makeMove()`.

### 4. Principe de Ségrégation Interface (ISP)

L'unique interface présente dans le code est la classe `Game`, signifiant ainsi que toutes les classes communiquent entre eux directement sans passer par des interfaces.
Ainsi, comme optimisation, il serait plus intéressant de **créer des interfaces spécifiques** pour chaque fonctionnalités au niveau du code :
-> iBoard pour Board
-> iPlayer pour Player
-> iGame pour TicTacToe et ConnectFour

Par ces ajouts, les classes de jeux `TicTacToe` et `ConnectFour` n'auront pas à implémenter une instance des classes spécifiques `Board` et `Player`, mais passer par les interfaces pour permettre l'appel des méthodes adaptés au jeu.

Enfin, évitez de polluer le fichier `main.cpp` par de nouvelles fonctions, mais créer des interfaces spécifiques pour ces fonctionnalités.

### 5. Principe d'Inversion de Dépendances (DIP)

A présent, au niveau du code, à l'absence des interfaces comme mentionné précédemment, les classes intéragissent entre eux directement sans **passer par des interfaces**, et viole donc le principe d'inversion de dépendance.
Aussi, à l'état actuel, les classes de haut niveau comme `TicTacToe` et `ConnectFour` ont une dépendance forte au classes de bas niveau (`Board` et `Player`), et cela dû à l'absence des interfaces pour les classes de bas niveau.

Dans le cadre d'une optimisation, si des interfaces seraient amenés à être implémentées pour les différentes classes `Board` et `Player`, il est nécessaire de faire en sorte que ce sont les classes `Board` et `Player` qui dépendront de l'implémentation de l'interface, et non l'interface qui s'adaptera par leur implémentation.

## Projet B : Winness Rakotozafy ([lien du projet](https://gitlab.com/WRKT1/td-cpp-winness-rakoto/-/tree/main/TP3?ref_type=heads))

### 1. Principe de responsabilité unique (SRP)

- Les classes `Jeu`, `JeuMorpion`, et `JeuPuissance4` semblent avoir plusieurs responsabilités, comme la gestion de l'interface utilisateur (UI), la logique du jeu, et la gestion des joueurs. Il serait préférable de séparer ces responsabilités en différentes classes pour une meilleure maintenance et évolutivité.
- `Classe morpion`, `classe force4` : La méthode JouerTour() doit être différente si joueur vs joueur ou computer vs joueur
- La classe `Grille` gère à la fois la représentation de la grille et la logique de vérification des conditions de victoire, ainsi que les mouvements des joueurs es responsabilités pourraient être séparées.
- Actuellement, la logique de jeu et l'interface utilisateur sont mélangées (par exemple, affichage dans la console et logique de jeu dans les mêmes classes). Il faudrait les séparer en créant des classes dédiées à l'UI qui peuvent interagir avec les classes de jeu via l'interface `JeuInterface`.

### 2. Principe Ouvert/Fermé (OCP)

Le code ne semble pas facilement extensible sans modification. Par exemple, l'ajout d'un nouveau jeu nécessiterait des modifications dans les méthodes `StartJeu` et `ChoixJeu` de la classe `Match`. Utiliser une stratégie ou un design pattern de factory pourrait améliorer l'extensibilité. Voir Factory() ou faire une énumération de jeux pour éviter à changer la classe match.

Proposition d'amélioration :

1. **Utiliser un Design Pattern de Factory pour Créer des Jeux :**
   - Au lieu de modifier la classe `Match` chaque fois qu'un nouveau jeu est ajouté, vous pourriez utiliser un Factory Pattern. Créez une `Factory` de jeux qui peut retourner une instance de jeu en fonction d'un identifiant ou d'un nom.
   - Dans `Match::ChoixJeu`, au lieu d'un `switch` pour instancier des jeux spécifiques (comme Morpion ou Puissance 4), demander à la Factory de donner l'instance de jeu correspondante. Ainsi, pour ajouter un nouveau jeu, on n'aurait qu'à modifier la Factory et non la classe `Match`, ou alors réussir a récupérer un liste de jeux.
2. **Abstraire la Logique de Jeu :**
   - Dans l'interface ou la classe abstraite `Jeu` mettre seulement les méthodes qui définit les méthodes communes à tous les jeux (par exemple, `Initialiser`, `Jouer`, `AfficherGrille`, etc.).
    - Faire en sorte que `JeuMorpion` et `JeuPuissance4` implémentent cette interface. Cela permettrait à la classe `Match` d'interagir avec une interface commune plutôt qu'avec des implémentations concrètes.

### 3. Principe de Substitution de Liskov (LSP)

- Ce principe est globalement bien respecté, même si certaines classe réelles et classes abstraites ont trop de méthodes qui ne sont pas toutes utilisées. Tel que `Ordinateur` et la classe abstraite `Joueur` ou encore la classe `Grille`.

### 4. Principe de Ségrégation Interface (ISP)

- Les classes (comme `Jeu`, `JeuMorpion`, `JeuPuissance4`, etc.) devraient identifier des groupes de fonctionnalités distincts. Par exemple, la gestion de la grille de jeu, la gestion des tours de jeu, et l'interaction avec l'utilisateur pourraient être considérées comme des fonctionnalités séparées
- Pour chaque groupe de fonctionnalités identifié, on devrait créer interface spécifique. Par exemple, une interface `IGrille` pour la gestion de la grille, une interface `ITourJeu` pour la gestion des tours de jeu, et une interface `IInteractionUtilisateur` pour la gestion des interactions avec l'utilisateur.
- `Joueur` et `Ordinateur` ne devraient pas devoir implémenter la classe `grille` directement
- Dans le code existant, séparez les méthodes et les fonctionnalités en fonction des interfaces nouvellement créées. Par exemple, tout code relatif à l'affichage de la grille devrait être déplacé dans des méthodes définies dans `IGrille`.

### 5. Principe d'Inversion de Dépendances (DIP)

- Pour chaque classe de bas niveau (comme `Grille`, `JeuMorpion`, `JeuPuissance4`), créé une interface correspondante (par exemple, `IGrille`).
- Ces interfaces devraient définir les méthodes nécessaires pour interagir avec la logique spécifique à chaque jeu.
- Au lieu que la classe `Match` crée et interagisse directement avec des instances spécifiques de jeux (comme `morpion` ou `puissance4`), elle devrait interagir avec les interfaces de jeu (`IJeu`).
- Cela signifie que `Match` ne sera plus dépendant des implémentations concrètes des jeux, mais de leurs abstractions.
- Mettre en place une Factory ou un Builder qui sera responsable de la création des instances de jeu. Cela permettra d'isoler la création des objets des classes de haut niveau, ce qui réduit encore plus le couplage.

## Projet gardé : Projet B de Winness

### Argumentation du choix de projet

Nous avons décidé de gardé le projet de Winness car le **squelette de son application** a été le plus facile à remodéliser.
Ainsi, nous avions pensé en terme de temps consacré pour la refactorisation, car son projet étant plus modulable, nous avions repris son squelette en y rajoutant les nouvelles interfaces.
Au terme des réflexions, nous avions également décidé de reprendre quelques idées de design et de méthodes du projet d'Alizée (exemple : initialisation de tableau de vecteurs mais non de pointeurs), pour que le programme soit plus facile à maintenir et évoluer.
Enfin, étant donné que chaque projet ne respectait pas en grande partie certains principes du principe SOLID, ce choix est surtout justifié par la manière dont le projet initial a été pensé mais ne remet pas en cause la qualité du programme de l'autre, et ainsi donné vie à un projet hybride : TP3-Refacto.

#### Nouveaux squelettes

##### 1. Interfaces et Classes Abstraites

**Interface Jeu (IJeu) :**

- Définit les méthodes communes à tous les jeux (Initialiser, Jouer, AfficherGrille, etc.).
  **Interface Grille (IGrille) :**
- Définit les méthodes pour gérer la grille de jeu (InitialiserGrille, AfficherGrille, CaseVide, etc.).
  **Interface InteractionUtilisateur (IInteractionUtilisateur) :**
- Définit les méthodes pour gérer les interactions utilisateur (SaisirCoordonnees, AfficherMenu, etc.).

##### 2. Classes de Jeux

**JeuMorpion et JeuPuissance4 (implémentant IJeu) :**

- Implémentent l'interface IJeu.
- Utilisent des instances de IGrille pour gérer la grille de jeu.
- Utilisent des instances de IInteractionUtilisateur pour interagir avec l'utilisateur.

##### 3. Factory et Injection de Dépendance

**JeuFactory :**

- Responsable de créer des instances de JeuMorpion, JeuPuissance4, etc.
- Utilise l'injection de dépendance pour fournir des instances de `IGrille` et `IJoueur` aux jeux.

##### 4. Classe Principale

**Classe Main :**

- `JeuFactory` pour obtenir des instances de jeux en utilisant l'interface `IJeu`.
- `JoueurFactory` pour créer des joueurs humains et ordinateur en utilisant l'interface `IJoueur`
- Utilisation de la classe `InteractionUtilisateur` pour tout ce qui est saisie de l'utilisateur au programme.
