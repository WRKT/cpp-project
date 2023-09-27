# TD1 C++ - Premier programme :

## Compil du programme
- Lancer la compilation grâce au Makefile avec la commande : `make` 
- Si vous voulez supprimer les fichiers générées : `make clean`

## Utilisation du programme
- Naviguez entre les menus en saisissant les bons numéros. Si un mauvais numéro est saisie, le programme se relance.
- **Attention!**, la gestion d'erreur en cas de saisie de chaine de caractères sur les options n'est pas encore pris en charge.

## Consignes TD1

### I- Manipulation de nombres
- Ecrivez une fonction qui prenne en paramètre deux int, et qui renvoie la somme de ces
deux entiers.
- Ecrivez une autre fonction qui prenne en paramètre trois entiers, et qui remplace la
valeur du troisième par la somme des deux premiers. Faites ceci deux fois, une fois à
l’aide des pointeurs, une fois à l’aide des références.
- Ecrivez un programme générant un tableau d’entiers rempli de valeurs aléatoires toutes
positives.
Affichez les valeurs successives du tableau dans la console. En utilisant une des
méthodes écrites pour la question 1.2, effectuez un tri du tableau par ordre croissant et
affichez le dans la console.
- Bonus : Faites en sortes que la taille du tableau soit générée en fonction d’une saisie
de l’utilisateur, et que le tri soit croissant ou décroissant en fonction d’une saisie
utilisateur également.
- Bonus 2 : après avoir effectué un tri (croissant ou décroissant), faites le tri inverse
toujours en utilisant la méthode développée en 1.2, en faisant aussi peu d’appels que
possible

### II- Jeu de Tennis
Ecrivez une fonction qui permette de déterminer le score d’un jeu de tennis, en
fonction du nombre d’échanges qui ont été remportés par chaque joueur.
Le système de pointage est assez simple :
1. Chaque joueur peut avoir l'un ou l'autre de ces points dans un jeu 0 15 30 40
2. Si vous avez 40 et que vous gagnez l’échange, vous gagnez le jeu, mais il existe
des règles spéciales.
3. Si les deux ont 40, les joueurs sont à égalité.
    - Si le jeu est à égalité, le gagnant d'une balle aura l'avantage et la balle de jeu.
    - Si le joueur avec l'avantage gagne la balle, il gagne le jeu.
    - Si le joueur sans avantage gagne, ils sont à égalité.

### III- Inscription dans la console et récupération des saisies.
- Ecrivez un programme qui demande son prénom à l’utilisateur, puis qu’il salue
l’utilisateur.
- Modifiez-le ensuite pour qu’il demande le nom ET le prénom (en une seule saisie), et
qu’il salue l’utilisateur en réutilisant son nom et son prénom.
Bonus : quel que soit le format de saisie de l’utilisateur, seule la première lettre du
prénom doit être en majuscule, toutes les lettres du nom de famille doivent être mises
en majuscules.
- Écrivez un programme en C++ permettant d’afficher un texte dans la console et de
générer un nombre aléatoire entre 0 et 1000. Demandez ensuite à l’utilisateur de saisir
un nombre, et affichez un texte qui indique si le nombre saisi était plus grand ou plus
petit que le nombre généré aléatoirement.
- Modifiez le programme pour que le joueur doive continuer à saisir des nombres
jusqu’à ce qu’il ait deviné le nombre généré aléatoirement. Une fois le nombre deviné,
un message de félicitations doit s’afficher, avec le nombre d’essais avant de deviner.
- Bonus : Ecrivez un programme qui permette à l’utilisateur de choisir un nombre entre
0 et 1000, et qui fasse deviner l’ordinateur en lui disant si le nombre choisi est plus
grand ou plus petit que le nombre qu’il a affiché. L’ordinateur devra deviner avec le
moins d’essais possible.
