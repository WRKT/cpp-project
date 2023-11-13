## Projet A : Alizée
### 1. Single Responsability Unique
- **Classe Board**
Cette classe viole le principe dans le sens où elle s'occupe de vérifier la condition de victoire par la méthode `checkWin()`, ce qui devrait être une propriété de la classe Jeu.
De plus, par extension, cette méthode pourrait être sectionnée en différentes méthodes comme : `checkRow()`, `checkColumns()`, `checkDiagonal()`.
La méthode `placeMarker()` serait plus intéressante à implémenter dans la classe Joueur, qui dans une logique métier est responsable de placer les pions.
Cependant, la classe Joueur appliquera une méthode `placeMarker()` qui fera appel à l'interface `iBoard`, qui ensuite procédera à la vérification et déposition du pion.
Enfin, sectionner le mode fonctionnement de cette méthode car elle viole le principe de responsabilité unique dans le fait qu'elle s'occupe à la fois du placement du pion pour `Morpion` et `Puissance4`.
Proposition d'optimisation : Une méthode placeMarkerMorpion + Une méthode placeMarkerPuissance4.

--> A voir plus tard pour l'implémentation de l'interface `iBoard`.

- **Classe Player**
Cette classe, à l'instant t du projet, en principe respecte le Single Responsability car elle implémente une seule fonctionnalité, celui de créer un joueur. 
Cependant, la classe Player, dans sa logique métier, manque beaucoup de fonctionnalités (à implémenter le fait que player **puisse placer les pions**).

- **Classe ComputerPLayer**
Cette classe, qui hérite de la classe `Player`, ne respecte pas le principe responsabilité unique car sa méthode `makeMove()` implémente la fonctionnalités d'effectuer le placement de pions pour tous les jeux présents dans le programme.
--> Proposition d'optimisation : sectionner la méthode makeMove en deux méthodes, l'un pour le jeu Morpion, l'autre pour la Puissance, un autre pour un nouveau jeu.

- **Classe Game**
La classe `Game` a été pensée comme étant l'interface de jeu abstraite, qui sera héritée des différents jeux (TicTacToe, ConnectFour). 
Cependant, la méthode `MakeMove()`, et `displayBoard()` dans la logique métier de l'application ne devront être pas implémentées sur la classe Game, mais sur les autres classes comme : Player et Board.

- **Classe TicTacToe**
Cette classe n'est pas conforme au principe de responsabilité unique dans le sens où la méthode `makeMove` n'a pas vocation d'être sur la classe TicTacToe, car elle devrait être une méthode de la classe Player.
De même pour la méthode `displayBoard`, qui devrait être une appel à l'interface `ìBoard` qui se chargera de faire l'intercommunication entre les différentes classes afin d'éviter un couplage fort.

- **Classe ConnectFour**
Cette classe, tout comme TicTacToe ne respecte pas le principe de responsabilité unique pour les mêmes raisons, notamment de par ses méthodes.

- **Fonction ``main``**
La programme `main()` ne respecte pas le principe de responsabilité unique en terme de la POO dans le sens où elle créé de nouvelles fonctions pour pouvoir intéragir avec le jeu. 
Ce qui serait optimisé est de créé une classe pour gérer le déroulement du jeu.
### 2. Principe Ouvert/Fermé (O)
- **Classe Board**
Cette classe viole le principe d'Ouvert/Fermé par sa méthode `placeMarker()`, car elle nécessite l'ajout de nouveaux paramètres (ex: gravity pour `Puissance4`) pour s'adapter au jeu instancié.

- **Classe Player et ComputerPlayer**
A l'instant présent, ces classes respectent le principe d'ouvert/fermé car elle est ouverte à l'extension et fermé à la modification par ses méthodes constante.

- **Classe Game**
Cette classe abstraite respecte en globalité le principe Ouvert/Fermé car déjà elle est une classe virtuelle pure, et que de ce fait, si une classe fille hérite de cette super-classe, alors les méthodes qu'elle implémente devrait être fermé à la modification.
Mais l'ajout de nouvelle méthode est possible.

- **Classe TicTacToe** et ConnectFour
Les classes TicTacToe et ConnectFour par contre ne respectent pas le principe d'Ouvert/Fermé dans le fait où leur constructeur des jeux a un couplage fort à la classe `Board`.
Ainsi, à la modification de la classe `Board`, les classes `TicTacToe` devraient également être modifiées dû au couplage gort présent, violant ainsi le principe d'Ouvert/Fermé.

### 3. Principe de Substitution de Liskov (L)
Ce principe est globalement bien respectée du fait que l'outil utilisé (QtCreator) nous empêche de faire des erreurs de non-implémentation de méthode d'une clase abstraite dans une classe fille.
Notamment sur la classe `Game` -> `Tictactoe` et `ConnectFour`.
Cependant, la classe `ComputerPlayer` par exemple ne pourrait pas se substituer à sa super-classe `Player` du fait qu'elle implémente une méthode `makeMove()`.

### 4. Principe de Ségrégation Interface (I)
L'unique interface présente dans le code est la classe `Game`, signifiant ainsi que toutes les classes communiquent entre eux directement sans passer par des interfaces.
Ainsi, comme optimisation, il serait plus intéressant de **créer des interfaces spécifiques** pour chaque fonctionnalités au niveau du code :
-> iBoard pour Board
-> iPlayer pour Player
-> iGame pour TicTacToe et ConnectFour

Par ces ajouts, les classes de jeux `TicTacToe` et `ConnectFour` n'auront pas à implémenter une instance des classes spécifiques ``Board`` et ``Player``, mais passer par les interfaces pour permettre l'appel des méthodes adaptés au jeu.

Enfin, évitez de polluer le fichier `main.cpp` par de nouvelles fonctions, mais créer des interfaces spécifiques pour ces fonctionnalités.

### 5. Principe d'Inversion de Dépendances (D)
A présent, au niveau du code, à l'absence des interfaces comme mentionné précédemment, les classes intéragissent entre eux directement sans **passer par des interfaces**, et viole donc le principe d'inversion de dépendance.
Aussi, à l'état actuel, les classes de haut niveau comme `TicTacToe` et `ConnectFour` ont une dépendance forte au classes de bas niveau (`Board` et `Player`), et cela dû à l'absence des interfaces pour les classes de bas niveau.

Dans le cadre d'une optimisation, si des interfaces seraient amenés à être implémentées pour les différentes classes `Board` et `Player`, il est nécessaire de faire en sorte que ce sont les classes `Board` et `Player` qui dépendront de l'implémentation de l'interface, et non l'interface qui s'adaptera par leur implémentation.

## Projet B : Winness
### 1. Principe de responsabilité unique (S)
- Les classes `Jeu`, `JeuMorpion`, et `JeuPuissance4` semblent avoir plusieurs responsabilités, comme la gestion de l'interface utilisateur (UI), la logique du jeu, et la gestion des joueurs. Il serait préférable de séparer ces responsabilités en différentes classes pour une meilleure maintenance et évolutivité.
- `Classe morpion`, `classe force4` : La méthode JouerTour() doit être différente si joueur vs joueur ou computer vs joueur
- La classe `Grille` gère à la fois la représentation de la grille et la logique de vérification des conditions de victoire, ainsi que les mouvements des joueurs es responsabilités pourraient être séparées.
- Actuellement, la logique de jeu et l'interface utilisateur sont mélangées (par exemple, affichage dans la console et logique de jeu dans les mêmes classes). Il faudrait les séparer en créant des classes dédiées à l'UI qui peuvent interagir avec les classes de jeu via l'interface `JeuInterface`. 
### 2. Principe Ouvert/Fermé (O)

Le code ne semble pas facilement extensible sans modification. Par exemple, l'ajout d'un nouveau jeu nécessiterait des modifications dans les méthodes `StartJeu` et `ChoixJeu` de la classe `Match`. Utiliser une stratégie ou un design pattern de factory pourrait améliorer l'extensibilité. Voir Factory() ou faire une énumération de jeux pour éviter à changer la classe match. 

Proposition d'amélioration : 
1. **Utiliser un Design Pattern de Factory pour Créer des Jeux :**
    - Au lieu de modifier la classe `Match` chaque fois qu'un nouveau jeu est ajouté, vous pourriez utiliser un Factory Pattern. Créez une `Factory` de jeux qui peut retourner une instance de jeu en fonction d'un identifiant ou d'un nom.
    - Dans `Match::ChoixJeu`, au lieu d'un `switch` pour instancier des jeux spécifiques (comme Morpion ou Puissance 4), demander à la Factory de donner l'instance de jeu correspondante. Ainsi, pour ajouter un nouveau jeu, on n'aurait qu'à modifier la Factory et non la classe `Match`, ou alors réussir a récupérer un liste de jeux.
2.   **Abstraire la Logique de Jeu :**
     - Dans l'interface ou la classe abstraite `Jeu` mettre seulement les méthodes qui définit les méthodes communes à tous les jeux (par exemple, `Initialiser`, `Jouer`, `AfficherGrille`, etc.).
    - Faire en sorte que `JeuMorpion` et `JeuPuissance4` implémentent cette interface. Cela permettrait à la classe `Match` d'interagir avec une interface commune plutôt qu'avec des implémentations concrètes.
### 3. Principe de Substitution (L)

- Ce principe est globalement bien respecté, même si certaines classe réelles et classes abstraites ont trop de méthodes qui ne sont pas toutes utilisées. Tel que `Ordinateur` et la classe abstraite `Joueur` ou encore la classe `Grille`.
### 4. Principe de Ségrégation (I)

- Les classes (comme `Jeu`, `JeuMorpion`, `JeuPuissance4`, etc.) devraient identifier des groupes de fonctionnalités distincts. Par exemple, la gestion de la grille de jeu, la gestion des tours de jeu, et l'interaction avec l'utilisateur pourraient être considérées comme des fonctionnalités séparées
- Pour chaque groupe de fonctionnalités identifié, on devrait créer interface spécifique. Par exemple, une interface `IGrille` pour la gestion de la grille, une interface `ITourJeu` pour la gestion des tours de jeu, et une interface `IInteractionUtilisateur` pour la gestion des interactions avec l'utilisateur.
- `Joueur` et `Ordinateur` ne devraient pas devoir implémenter la classe `grille` directement
- Dans le code existant, séparez les méthodes et les fonctionnalités en fonction des interfaces nouvellement créées. Par exemple, tout code relatif à l'affichage de la grille devrait être déplacé dans des méthodes définies dans `IGrille`.
### 5. Principe d'Inversion de Dépendances (D)

- Pour chaque classe de bas niveau (comme `Grille`, `JeuMorpion`, `JeuPuissance4`), créé une interface correspondante (par exemple, `IGrille`).
- Ces interfaces devraient définir les méthodes nécessaires pour interagir avec la logique spécifique à chaque jeu.
- Au lieu que la classe `Match` crée et interagisse directement avec des instances spécifiques de jeux (comme `morpion` ou `puissance4`), elle devrait interagir avec les interfaces de jeu (`IJeu`).
- Cela signifie que `Match` ne sera plus dépendant des implémentations concrètes des jeux, mais de leurs abstractions.
- Mettre en place une Factory ou un Builder qui sera responsable de la création des instances de jeu. Cela permettra d'isoler la création des objets des classes de haut niveau, ce qui réduit encore plus le couplage.

## Projet gardé : Projet B-Winness

// TO DO : Ajouter le pourquoi avec argumentation
### Nouveaux squelettes

#### 1. Interfaces et Classes Abstraites
 **Interface Jeu (IJeu) :**
- Définit les méthodes communes à tous les jeux (Initialiser, Jouer, AfficherGrille, etc.).
**Interface Grille (IGrille) :**
- Définit les méthodes pour gérer la grille de jeu (InitialiserGrille, AfficherGrille, CaseVide, etc.).
 **Interface InteractionUtilisateur (IInteractionUtilisateur) :**
 - Définit les méthodes pour gérer les interactions utilisateur (SaisirCoordonnees, AfficherMenu, etc.).
#### 2. Classes de Jeux
**JeuMorpion et JeuPuissance4 (implémentant IJeu) :**
 - Implémentent l'interface IJeu.
- Utilisent des instances de IGrille pour gérer la grille de jeu.
 - Utilisent des instances de IInteractionUtilisateur pour interagir avec l'utilisateur.
#### 3. Factory et Injection de Dépendance
**JeuFactory :**
- Responsable de créer des instances de JeuMorpion, JeuPuissance4, etc.
- Utilise l'injection de dépendance pour fournir des instances de IGrille et IInteractionUtilisateur aux jeux.
#### 4. Classe Principale
**Classe Main :**
- Instancie et utilise la Jeu
- Factory pour obtenir des instances de jeux.
- Peut également instancier et passer des dépendances nécessaires (comme des implémentations de IGrille, IInteractionUtilisateur).

// TO DO : Ajouter ici Diagramme UML (évolué au fil des réflexions)
