#pragma warning(disable : 4996)

/*
Includes
	Includes "kopieren" fremden Quellcode an genau diese Stelle, 
	so dass man die fremden Variablen/Funktionen im eigenen Code/Modul
	verwenden kann
*/
#include<stdio.h>

/*
Defines
*/
#define SIZE_OUTPUT_BUFFER 20

/*
Funktionsprototypen
	Da C eine prozedurale Sprache ist, arbeitet der Compiler den Code
	"von oben nach unten" ab. Das heißt auch, dass wenn wir eine Funktion addiere()
	in der main() Funktion aufrufen wollen, diese dem Compiler zu diesem Zeitpunkt
	schon bekannt sein muss. Sonst weiß er nicht, wo er hinspringen soll.
	Deshalb deklariert man am Beginn der Datei immer die Funktionsprototypen, die dem
	Compiler schon mal alle verwendeten Funktionen und deren Struktur bekannt machen.
*/
short ergebnis_ausgeben(int);
int zahl_einlesen();
void print_error_message(char*);
// TODO Funktionsprotoypen für unsere Funktionen erstellen.

/*
Globale Variablen
	Globale Variablen sind für alle Gültigkeitsbereiche im Modul 
	sichtbar. Das heißt, die main() Funktion kann genauso eine globale 
	Variable lesen/schreiben wie es eine andere Funktion (z.B. addiere() ) 
	kann.
*/
enum Zahlensystem { hex, bin, dez, oct };
enum Rechenart { plus, minus, mal, geteilt };
char Ziffern[] = { '0','1','2','3','4','5','6','7','8','9','A','B', 'C', 'D', 'E', 'F' };

int ergebnis = 0;


/*
main() Funktion ist der Einstiegspunkts ins C Programm
*/
int main(void)
{
	// TODO erste Zahl einlesen	
	ergebnis = zahl_einlesen();

	// TODO zweite Zahl einlesen

	// TODO Rechenoperation abfragen

	// TODO die richtige Operation auf die Zahlen anwenden

	// TODO Ergebnis ausgeben	
	ergebnis_ausgeben(dez);

	return 0;
}

/*
input parameter		int zahlensystem (spezifiziert, in welchem Zahlensystem das Ergebnis dargestellt wird)
returns				(0 = success, 1 = error)
-------------------------
Gibt das berechnete Ergebnis in der Konsole aus
*/
short ergebnis_ausgeben(int zahlensystem)
{
	// Diese "Arbeitsvariable" wird immer weiter zerlegt.
	// Deshalb kopieren wir das Ergebnis, statt direkt globale Variable zu verwenden.
	int temp = ergebnis;

	// weitere lokale Variablen anlegen
	int rest = 1;
	int currentIndex = SIZE_OUTPUT_BUFFER - 1;
	short base = -1;
	short is_negative_number = 0;

	// Ausgabe Buffer deklarieren und alles mit Leerzeichen initialisieren
	char ausgabe_buffer[SIZE_OUTPUT_BUFFER + 1];

	for (int i = 0; i < 20; i++)
	{
		ausgabe_buffer[i] = ' ';
	}
	// letztes zeichen im C-String muss ein '\0' sein
	ausgabe_buffer[SIZE_OUTPUT_BUFFER] = '\0';

	// wenn das Ergebnis negativ ist, speichern wir das minus und rechnen mit dem Betrag weiter
	if (temp < 0)
	{
		temp *= -1;
		is_negative_number = 1;
	}		

	// je nach auszugebendem Zahlensystem muss die Basis geändert werden
	switch (zahlensystem)
	{
		case hex:
			base = 16;
			break;

		case dez:
			base = 10;
			break;

		case bin:
			base = 2;
			break;

		case oct:
			base = 8;
			break;

		default:
			print_error_message("Ungueltiges Zahlensystem!");
			return 1;
	}

	// wenn etwas schiefgelaufen ist, wurde nichts in die Variable 'base' geschrieben
	// und sie hat immer noch den Wert -1
	if (base == -1)
	{
		print_error_message("Bei der Ausgabe ist etwas schief gelaufen!");
		return 1;
	}

	// Zeichenweise Umwandlung des Ergebnisses in das gewählte Zahlensystem
	if (temp == 0)
	{
		ausgabe_buffer[currentIndex] = Ziffern[0];
		currentIndex--;
	}
	else
	{
		while (temp != 0)
		{
			rest = temp % base;
			temp = temp / base;
			ausgabe_buffer[currentIndex] = Ziffern[rest];
			currentIndex--;
		}
	}	

	// wenn die Zahl ursprünglich negativ war, fügen wir jetzt noch ein '-' an
	if (is_negative_number)
	{
		ausgabe_buffer[currentIndex] = '-';
		currentIndex--;
	}

	// Ausgabe des jetzt hoffentlich gefüllten buffers
	printf("Ergebnis: %s", ausgabe_buffer);

	// ein paar Leerzeilen, dass es schöner aussieht
	printf("\n\n\n\n");

	// return an die aufrufende Funktion (0 = success)
	return 0;
}

/*
input parameter		none
returns				Eine vorzeichenbehaftete, vom Nutzer eingebene Zahl
*/
int zahl_einlesen()
{
	int zahl = 0;
	printf("%s", "Bitte Zahl eingeben: ");	
	scanf("%d", &zahl);

	return zahl;
}

/*
input parameter		char* message (übergebene Fehlermeldung)
returns				none
*/
void print_error_message(char* message)
{
	printf("Fehler: %s", message);
}