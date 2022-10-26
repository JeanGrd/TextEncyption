#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

//Variables
char ANormCaract[] = "1234567890()[]{}=*%$^!:/;,'";
char Convers[] = "éèàâêûîôùüëäïö ";
char GoodConvers[] = "eeaaeuiouueaio ";
char AlphabetMinus[] = "abcdefghijklmnopqrstuvwxyz ";
char AlphabetMajus[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

char message[1000];

//Fonctions
int Verification();
void IncorrectVerification();
void ConversionDesAccents();
void Cesar();
void Vigenere();
void Dechiffrage_Cesar();
void Dechiffrage_Vigenere();

//Logo s'affiche dés le lancement du programme
void logo(){

printf("==================================================================================================================================================\n");
printf("           _______  _______  __   __  _______    _______  __    _  _______  ______    __   __  _______  _______  ___   _______  __    _ \n");
printf("          |       ||       ||  |_|  ||       |  |       ||  |  | ||       ||    _ |  |  | |  ||       ||       ||   | |       ||  |  | |\n");
printf("          |_     _||    ___||       ||_     _|  |    ___||   |_| ||       ||   | ||  |  |_|  ||    _  ||_     _||   | |   _   ||   |_| |\n");
printf("            |   |  |   |___ |       |  |   |    |   |___ |       ||       ||   |_||_ |       ||   |_| |  |   |  |   | |  | |  ||       |\n");
printf("            |   |  |    ___| |     |   |   |    |    ___||  _    ||      _||    __  ||_     _||    ___|  |   |  |   | |  |_|  ||  _    |\n");
printf("            |   |  |   |___ |   _   |  |   |    |   |___ | | |   ||     |_ |   |  | |  |   |  |   |      |   |  |   | |       || | |   |\n");
printf("            |___|  |_______||__| |__|  |___|    |_______||_|  |__||_______||___|  |_|  |___|  |___|      |___|  |___| |_______||_|  |__|\n");
printf("\n==================================================================================================================================================\n");
printf("----------------------------------------------------------Bienvenue dans TEXT ENCRYPTION----------------------------------------------------------\n");
printf("==================================================================================================================================================\n\n");

}

//Programme principal
int main () {
  //Création d'un fichier log qui enregistre l'historique des chiffrements
  FILE* log  = fopen("HistoriqueChiffrement.txt", "w");
  char reload = 'Y';

while (reload == 'Y') {

    //Variable utile
    int decalage = 4000;
    char Clee[1000];

    system("clear");
    logo();

    //Conversion des accents non fonctinnel (ajouter wchar_t)
    //ConversionDesAccents();
   
   	printf("\nQuel action voulez vous faire ?\n");
    printf("-------------------------------\n\n");
    printf("- Chiffrer un message en code César [1]\n");
    printf("- Déchiffrer un message en code César [2]\n");
    printf("- Chiffrer un message en code Vigenere [3]\n");
    printf("- Déchiffrer un message en code Vigenere [4]\n");
    printf("- Lecture du ReadMe [5]\n\n");

   int Choix = 6;
   while (Choix > 5 || Choix < 1) {
       printf("Votre choix (nombre compris entre 1 et 5) : ");
       scanf("%d", &Choix);

      if (Choix > 5 || Choix < 1) 
        printf("\nATTENTION : NOMBRE NON COMPRIS ENTRE 1 ET 5, MERCI DE RECOMMENCER\n");
    }

   //Switch permettant d'avoir les différents choix de chiffrement demandé par l'utilisateur (allant de 1 à 5)
   switch(Choix) {
      //Chiffrement Cesar
      case 1 :
         printf("\nQuelle message voulez chiffrer en code César ? ");
         getchar();
         scanf("%[^\n]", message);
         if (Verification(message) == 0)
            IncorrectVerification(message);

         while (decalage > 1000 || decalage < 1) {
            printf("\nQuel décalage pour le chiffrement voulez vous utiliser (nombre compris entre 0 et 1000) ? ");
            scanf("%d", &decalage);
            if (decalage > 1000 || decalage < 1) 
              printf("\nATTENTION : NOMBRE NON COMPRIS ENTRE 1 ET 1000, MERCI DE RECOMMENCER");
    }

         fprintf(log, "Votre message en language naturel : %s\n", message);
         Cesar(message, decalage);
         fprintf(log, "Message en code César chiffrer avec un décalage de %d : %s\n\n", decalage, message);
         break;

      //Déchiffrement Cesar
      case 2 :

         printf("\nQuelle message voulez déchiffrer en code César ? ");
         getchar();
         scanf("%[^\n]", message);
         if (Verification(message) == 0)
            IncorrectVerification(message);

         while (decalage > 1000 || decalage < 1) {
            printf("\nQuel décalage pour le chiffrement voulez vous utiliser (nombre compris entre 0 et 1000) ? ");
            scanf("%d", &decalage);
            if (decalage > 1000 || decalage < 1) 
              printf("\nATTENTION : NOMBRE NON COMPRIS ENTRE 1 ET 1000, MERCI DE RECOMMENCER");
        }
         fprintf(log, "Votre message en code César : %s\n", message);
         Dechiffrage_Cesar(message, decalage);
         fprintf(log, "Message en code César déchiffrer avec un décalage de %d : %s\n\n", decalage, message);
         break;

      //Chiffrement Vigenere
      case 3 :

         printf("\nQuelle message voulez chiffrer en code Vigenere ? ");
         getchar();
         scanf("%[^\n]", message);
         Verification(message);
         if (Verification(message) == 0)
            IncorrectVerification(message);

         printf("Quelle est la clée de chiffrement Vigenere voulez vous utiliser (aucun espace ou caractères spéciaux sont tolérés) ? ");
         scanf ("%s", Clee);
         fprintf(log, "Votre message en language naturel : %s\n", message);
         Vigenere(message, Clee);
         fprintf(log, "Message en code Vigenere chiffrer (clée : %s) : %s\n\n", Clee, message);
         break;

      //Déchiffrement Vigenere
      case 4 :

         printf("\nQuelle message voulez déchiffrer en code Vigenere ? ");
         getchar();
         scanf("%[^\n]", message);
         if (Verification(message) == 0)
            IncorrectVerification(message);

         printf("Quelle est la clée de chiffrement Vigenere voulez vous utiliser (aucun espace ou caractères spéciaux sont tolérés) ? ");
         scanf ("%s", Clee);
         fprintf(log, "Votre message en code Vigenere : %s\n", message);
         Dechiffrage_Vigenere(message, Clee);
         fprintf(log, "Message en code Vigenere déchiffrer (clée : %s) : %s\n\n", Clee, message);
         break;

      //Lecture du ReadMe directement dans le programme
      case 5 :

         printf("\nCréateur : GUIRAUD Jean S2D (seul)\n\n");

          printf("TextEncryption est un programme en C qui traduit un message saisi par l'utilisateur dans 2 façons différentes de chiffrer (César et Vigenere), l'utilisateur \n");
          printf("retrouver un historique des différents messages traduits dans un fichier .txt (HistoriqueChiffrement.txt).\n\n");

          printf("Nous retrouvons plusieurs plusieurs variable comme des tableaux comprenant l'Alphabet avec les lettres majuscule (AlphabetMajus) et les lettres en minuscule\n");
          printf("(AlphabetMinus). Pour la validiter des caractères j'ai ANormCaract qui permet au programme de ne pas prendre de caractère qu'il ne pourra pas retranscrire\n");
          printf("dans le chiffrement voulu. Deux autres tableaux dont 1 comprenant les lettres accentuées afin de les remplacer par le second tableau les lettres non accentuées.\n");
          printf("Il y aussi le tableau de caractères message ainsi que clée. Et d'autres variables qui permettent la bon fonctiennement du programme mais qui sont peu interressantes.\n");
          printf("Dans les fonctions, les entrés principales sont : le message (Vigenere et Cesar), la clée (Vigenere) et le décalage (Cesar).\n");
          printf("La sortie des fonctions et le texte traduit donc le message.\n\n");

          printf("A contrario il y a deux erreurs dans ce programme, le premier est le fait que lorsque j'ai commencé à developper j'ai laissé tomber la fonction ConvertirAccents. \n");
          printf("Arrivant à la fin du programme j'ai réalisé qu'il fallait que je rajoute wchar_t sur tous mes tableaux ce qui a impacté beaucoup de chose, j'ai laissé des traces de\n");
          printf("ma tentative mais par manque de temps ce fût impossible (tentative : Wchar.c).\n");
          printf("Le second est le makefile n'est pas fonctionnel du tout, ne l'ayant jamais utiliser (j'ai laissé mon makefile quand même mais non fonctionnel).\n");
          printf("J'ai eu aussi un problème avec le tableau de caractère message, des problèmes d'entrées dans les fonctions ce qu'il fait qu'il se retrouve en global.\n\n");

          printf("Le programme est entièrement fonctionnel et réalise tous les chiffrements voulus sans erreurs comprenant les majuscules et minuscules.\n");
          printf("Le programme est assez simple, sans prise de tête facile d'utilisation et ergonomique.\n\n");

          printf("Merci et bonne expérience de TextEncryption. \n" );
         break;

      //Si l'utilisateur entre un nombre incorrect il sera redirigé ici et le programme recommencera (Annuler j'ai rajouté une boucle avec condition qui sera plus adapté).
      default :

         printf("Nombre invalide, merci de recommencer.\n" );
         main();
   }

   //Demande s'il refaire un chiffrement ou non
   printf("\nVoulez vous recommencer un chiffrement ?");
   printf("\n- Pour arrêter le programme [N]");
   printf("\n- Pour recommencer [Y]");
   printf("\n\nQuelle est votre choix (Y ou N) : ");
   getchar();
   scanf("%c", &reload);

 }
   printf("\n-------------------\n");
   printf("Merci et aurevoir !\n");
   printf("-------------------\n\n");

   fclose(log);
}

//Vérifie un message (chaine de caractère)
int Verification(char texte[1000]) {

	for (int i=0; i < strlen(texte); i++)
   	{
   		for (int i2=0; i2 < sizeof(ANormCaract); i2++)
   		{
   			if (ANormCaract[i2] == texte[i])
   			{
          return 0;
   			}
  	}
   }

   return 1;
}

//Vérifie que le nouveau message saisi par l'utilisateur soit correct, et recommence à l'infinie tant que le message est incorrect
void IncorrectVerification(char message[1000]) {

    int Verif = 0;
    while (Verif == 0) {
      printf("\n");
      printf("Code incorrect !\n");
      printf("Motif : Contient des caractères illégaux (caractères spéciaux, nombre, etc...)\n");
      printf("Veuillez rentrer un nouveau message à coder : ");
      memset(message, '\0', strlen(message) - 1);
      getchar();
      scanf("%[^\n]", message);
      Verif = Verification(message);
    }

}

//Conversion des accents non fonctionnel (ajouter wchar_t)
void ConversionDesAccents(char texte[1000]) {

      for (int i=0; i < strlen(texte); i++)
      {
         for (int i2=0; i2 < sizeof(Convers); i2++) {
            if (texte[i] == Convers[i2] ) {
               texte[i] = GoodConvers[i2];
            }
         }

}
printf("%s", texte);
}

//Chiffrement en code CESAR
void Cesar(char texte [1000], int decalage) {

      int valeur;

      for (int i = 0; i < strlen(texte); i++) {
         int i2 =0;
         while (AlphabetMinus[i2] != texte[i] || AlphabetMinus[i2] == 27) {
            i2 = i2+1;
         }

         if (i2 < 27) {
            if (texte[i] == ' ') {
               texte[i] = ' ';
            } else if (i2+decalage > 26){
               valeur = i2+decalage;
               texte[i] = AlphabetMinus[valeur % 26];
            } else {
               texte[i] = AlphabetMinus[i2+decalage];
         }
      }
      }

      for (int i = 0; i < strlen(texte); i++) {
         int i2 =0;
         while (AlphabetMajus[i2] != texte[i] || AlphabetMajus[i2] == 27) {
            i2 = i2+1;
         }
         if (i2 < 27) {
            if (texte[i] == ' ') {
               texte[i] = ' ';
            } else if (i2+decalage > 26){
               valeur = i2+decalage;
               texte[i] = AlphabetMajus[valeur % 26];
            } else {
               texte[i] = AlphabetMajus[i2+decalage];
         }
      }
      }

      printf("Le cryptage est : %s\n", texte);

}

//Déchiffrement en code CESAR
void Dechiffrage_Cesar(char texte [1000], int decalage) {

      int valeur;

      for (int i = 0; i < strlen(texte); i++) {
         int i2 =0;
         while (AlphabetMinus[i2] != texte[i] || AlphabetMinus[i2] == 27) {
            i2 = i2+1;
         }
         if (i2 < 27) {
            if (texte[i] == ' ') {
               texte[i] = ' ';
            } else if (i2-decalage < 0){
               valeur = i2-decalage;
               while (valeur < 0) {
                  valeur = valeur+26;
               }
               texte[i] = AlphabetMinus[valeur];
            } else {
               texte[i] = AlphabetMinus[i2-decalage];
         }
      }
      }

      for (int i = 0; i < strlen(texte); i++) {
         int i2 =0;
         while (AlphabetMajus[i2] != texte[i] || AlphabetMajus[i2] == 27) {
            i2 = i2+1;
         }
         if (i2 < 27) {
            if (texte[i] == ' ') {
               texte[i] = ' ';
            } else if (i2-decalage < 0){
               valeur = i2-decalage;
               while (valeur < 0) {
                  valeur = valeur+26;
               }
               texte[i] = AlphabetMajus[valeur];
            } else {
               texte[i] = AlphabetMajus[i2-decalage];
         }
      }
      }

      printf("Déchiffrement du message codé : %s\n", texte);
}

//Chiffrement en code VIGENERE
void Vigenere(char texte [1000], char Clee [1000]) {

    char nouvelleClee[1000];

    for(int i = 0, j = 0; i < strlen(texte); i++, j++){
      if (j == strlen(Clee))
          j = 0;

      if (texte[i] == ' ') {
          nouvelleClee[i] = ' ';
          j = j - 1;

      } else {
        nouvelleClee[i] = Clee[j];
      }
}

    for(int i = 0; i < strlen(texte); i++) {
        int i3;
        int i2;
        int k;
         for (i2 = 0; i2 == 27 || AlphabetMinus[i2] != texte[i]; i2++) {
            k = 0;
         }

         for (i3 = 0; AlphabetMinus[i3] != nouvelleClee[i] || i3 == 27; i3++) {
         }

         if (i2 > 27) {
          for (i2 = 0; AlphabetMajus[i2] != texte[i] || i2 == 27 ; i2++) {
            k = 1;
          }
        }

        if (i3 > 27) {
         for (i3 = 0; AlphabetMajus[i3] != nouvelleClee[i] || i3 == 27; i3++) {
         }
        }

        if (texte[i] == 'a') {
          k = 0;
        }
        if (texte[i] == 'A') {
          k = 1;
        }

         if (i2 < 27 && i3 < 27) {
            if (texte[i] == ' ') {
               texte[i] = ' ';
            } else if (k == 0) {
               texte[i] = AlphabetMinus[(i3 + i2) % 26];
            } else {
              texte[i] = AlphabetMajus[(i3 + i2) % 26];
            }
         }
      }

        printf("\nMessage chiffre : %s\n", texte);
}

//Déchiffrement en code VIGENERE
void Dechiffrage_Vigenere(char texte [1000], char Clee [1000]) {

    char nouvelleClee[1000];

    for(int i = 0, j = 0; i < strlen(texte); i++, j++){
      if (j == strlen(Clee))
          j = 0;

      if (texte[i] == ' ') {
          nouvelleClee[i] = ' ';
          j = j - 1;

      } else {
        nouvelleClee[i] = Clee[j];
      }
}

    for(int i = 0; i < strlen(texte); i++) {
        int i3;
        int i2;
        int k;

         for (i2 = 0; i2 == 27 || AlphabetMinus[i2] != texte[i]; i2++) {
            k = 0;
         }

         for (i3 = 0; AlphabetMinus[i3] != nouvelleClee[i] || i3 == 27; i3++) {
         }

         if (i2 > 27) {
          for (i2 = 0; AlphabetMajus[i2] != texte[i] || i2 == 27; i2++) {
            k = 1;
          }
        }

        if (i3 > 27) {
         for (i3 = 0; AlphabetMajus[i3] != nouvelleClee[i] || i3 == 27; i3++) {
         }
        }

        if (texte[i] == 'a') {
          k = 0;
        }

        if (texte[i] == 'A') {
          k = 1;
        }

         if (i2 < 27 && i3 < 27) {
            if (texte[i] == ' ') {
               texte[i] = ' ';
            } else if (k == 0) {
                if (i2 >= i3) {
                  texte[i] = AlphabetMinus[i2 - i3];
                } else {
                  texte[i] = AlphabetMinus[(i2 - i3) + 26];
                }
            } else {
                if (i2 >= i3) {
                  texte[i] = AlphabetMajus[i2 - i3];
                } else {
                  texte[i] = AlphabetMajus[(i2 - i3) + 26];
                }
            }
         }
      }

      printf("Déchiffrement du message codé : %s\n", texte);
}
