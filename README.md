# TextEncyption 

TextEncryption est un programme en C qui traduit un message saisi par l'utilisateur dans 2 façons différentes de chiffrer (César et Vigenere), l'utilisateur peut retrouver un historique des différents messages traduits dans un fichier .txt (HistoriqueChiffrement.txt).

Nous retrouvons plusieurs plusieurs variable comme des tableaux comprenant l'Alphabet avec les lettres majuscule (AlphabetMajus) et les lettres en minuscule (AlphabetMinus).

Pour la validiter des caractères j'ai "ANormCaract" qui permet au programme de ne pas prendre de caractère qu'il ne pourra pas retranscrire
dans le chiffrement voulu. Deux autres tableaux dont 1 comprenant les lettres accentuées afin de les remplacer par le second tableau les lettres non accentuées.
Il y aussi le tableau de caractères "message" ainsi que "clée". Et d'autres variables qui permettent la bon fonctiennement du programme mais qui sont peu interressantes.
Dans les fonctions, les entrés principales sont : le message (Vigenere et Cesar), la clée (Vigenere) et le décalage (Cesar).
La sortie des fonctions et le texte traduit donc le message.

A contrario il y a deux erreurs dans ce programme, le premier est le fait que lorsque j'ai commencé à developper j'ai laissé tomber la fonction "ConvertirAccents". 
Arrivant à la fin du programme j'ai réalisé qu'il fallait que je rajoute wchar_t sur tous mes tableaux ce qui a impacté beaucoup de chose, j'ai laissé des traces de ma tentative mais par manque de temps ce fût impossible (tentative : Wchar.c).

La seconde est le makefile n'est pas fonctionnel du tout, ne l'ayant jamais utiliser (j'ai laissé mon makefile quand même mais non fonctionnel).
J'ai eu aussi un problème avec le tableau de caractère "message", des problèmes d'entrées dans les fonctions ce qu'il fait qu'il se retrouve en global.

Le programme est entièrement fonctionnel et réalise tous les chiffrements voulus sans erreurs comprenant les majuscules et minuscules.
Le programme est assez simple, sans prise de tête facile d'utilisation et ergonomique.

Merci et bonne expérience de TextEncryption.

**Written by :** Jean Guiraud
