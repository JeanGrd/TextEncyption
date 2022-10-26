# Text Encryption

## Preamble

 TextEncryption was developed during my first year at University, you'll excuse me for the quality of the code which can be imperfect, but it works correctly :D !

## Program description

TextEncrytion is a C program that translates a message entered by the user in two different ways of encryption (in my case : Caesar and Vigenere), the user can find a history of the different translated messages in a .txt file (HistoryEncryption.txt).

We find several variables such as arrays including the alphabet with upper case letters (CapitalLetters) and lower case letters (LowerCaseLetters).

For the validation of the characters I have "ANormCaract" which allows the program not to take any characters that it will not be able to retranscribe in the desired encryption.

In the functions, the main inputs are : the message (Caesar or Vigenere), the key (Vigenere) and the offset (Caesar). The output of the functions is the encrypted or decrypted message.

A contrario, j'ai noté deux erreurs dans ce programme :

- La fonction "convertiraccent" n'est pas fonctionnelle,
- le makefile n'est pas fonctionnel aussi.

On the other hand, I noticed two errors in this program :

- The "convertiraccent" function doesn't work,
- The makefile doesn't work too.

Le programme est entièrement fonctionnel et réalise tous les chiffrements voulus sans erreurs comprenant les majuscules et minuscules. Le programme est facile d'utilisation et ergonomique.

The program is fully functionnal and performs all the encryptions desired without bugs including upper case letters and lower case letters. The program is easy to use and ergonomic.

I wish you a good experience with TextEncryption.

---

**Year of project completion :** 2019
\
**Written by :** Jean GUIRAUD
