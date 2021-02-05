/*
Includes
	Includes "kopieren" fremden Quellcode an genau diese Stelle, 
	so dass man die fremden Variablen/Funktionen im eigenen Code/Modul
	verwenden kann
*/
#include<stdio.h>

/*
Globale Variablen
	Globale Variablen sind f�r alle G�ltigkeitsbereiche im Modul 
	sichtbar. Das hei�t, die main() Funktion kann genauso eine globale 
	Variable lesen/schreiben wie es eine andere Funktion (z.B. addiere() ) 
	kann.
*/

/*
Funktionsprototypen
	Da C eine prozedurale Sprache ist, arbeitet der Compiler den Code 
	"von oben nach unten" ab. Das hei�t auch, dass wenn wir eine Funktion addiere()
	in der main() Funktion aufrufen wollen, diese dem Compiler zu diesem Zeitpunkt 
	schon bekannt sein muss. Sonst wei� er nicht, wo er hinspringen soll.
	Deshalb deklariert man am Beginn der Datei immer die Funktionsprototypen, die dem
	Compiler schon mal alle verwendeten Funktionen und deren Struktur bekannt machen.
*/

// TODO Funktionsprotoypen f�r unsere Funktionen erstellen.



/*
main() Funktion ist der Einstiegspunkts ins C Programm
*/
int main(void)
{
	printf("Hello World");
	// neuer kommentar
	// kommentar f�r pull request
	return 0;
}