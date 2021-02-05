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
short ergebnis_ausgeben(int, int);
int zahl_einlesen();
void print_error_message(char*);
// Funktionsprotoypen für unsere Funktionen erstellen.
short rechenoperation_einlesen();
int rechne(short, int, int);
int addiere(int , int );
int subtrahiere(int , int );
int multipliziere(int , int );
int dividiere(int , int );
int rechne_modulo(int , int );
int potenzieren_rekursiv(int , int );
int potenzieren_schleife(int , int );

/*
Globale Variablen
	Globale Variablen sind für alle Gültigkeitsbereiche im Modul
	sichtbar. Das heißt, die main() Funktion kann genauso eine globale
	Variable lesen/schreiben wie es eine andere Funktion (z.B. addiere() )
	kann.
*/
enum Zahlensystem { hex, bin, dez, oct };
enum Rechenart { addition = 1, subtraktion, multiplikation, division, modulo, potenzieren };
char Ziffern[] = { '0','1','2','3','4','5','6','7','8','9','A','B', 'C', 'D', 'E', 'F' };


/*
main() Funktion ist der Einstiegspunkts ins C Programm
(damit man die Musterlösung ausführen kann, muss das in main() umbenannt werden)
(außerdem ist die datei musterloesung_taschenrechner.c vom Build ausgeschlossen)
(im Notfall also STRG+C STRG+V)
*/
int main_muster(void)
{
	printf("Groesse der Datentypen:"
		"\nint\t\t%d byte"
		"\nshort\t\t%d byte"
		"\nlong\t\t%d byte"
		"\nlong long\t%d byte\n\n",
		sizeof(int),
		sizeof(short),
		sizeof(long),
		sizeof(long long));
	int ergebnis = 0;

	do
	{
		// erste Zahl einlesen	
		printf("Was soll die erste Zahl sein? (Summand / Diminuend / Faktor/ Dividend / Basis)\n");
		int x = zahl_einlesen();

		// zweite Zahl einlesen
		printf("Was soll die zweite Zahl sein? (Summand / Subtrahend / Faktor / Divisor / Exponent)\n");
		int y = zahl_einlesen();

		// Rechenoperation abfragen
		short rechenoperation = rechenoperation_einlesen();

		// die richtige Operation auf die Zahlen anwenden
		ergebnis = rechne(rechenoperation, x, y);

		// Ergebnis ausgeben	
		ergebnis_ausgeben(dez, ergebnis);

	} while (1);

	return 0;
}

/*
input parameter		short rechenart
returns				none
*/
int rechne(short rechenart, int zahl1, int zahl2)
{
	int berechnetes_ergebnis = 0;

	switch (rechenart)
	{
	case addition:
		berechnetes_ergebnis = addiere(zahl1, zahl2);
		break;
	case subtraktion:
		berechnetes_ergebnis = subtrahiere(zahl1, zahl2);
		break;
	case multiplikation:
		berechnetes_ergebnis = multipliziere(zahl1, zahl2);
		break;
	case division:
		berechnetes_ergebnis = dividiere(zahl1, zahl2);
		break;
	case modulo:
		berechnetes_ergebnis = rechne_modulo(zahl1, zahl2);
		break;
	case potenzieren:
		// Variante 1
		berechnetes_ergebnis = potenzieren_rekursiv(zahl1, zahl2);
		// Variante 2
		berechnetes_ergebnis = potenzieren_schleife(zahl1, zahl2);
		break;
	default:
		print_error_message("Unbekannte Rechenoperation!");
	}

	return berechnetes_ergebnis;
}

/*
input parameter		int zahl1 (Summand)
					int zahl2 (Summand)
returns				ergebnis
*/
int addiere(int zahl1, int zahl2)
{
	return zahl1 + zahl2;
}

/*
input parameter		int zahl1 (Diminuend)
					int zahl2 (Subtrahend)
returns				ergebnis
*/
int subtrahiere(int zahl1, int zahl2)
{
	return zahl1 - zahl2;
}

/*
input parameter		int zahl1 (Faktor)
					int zahl2 (Faktor)
returns				ergebnis
*/
int multipliziere(int zahl1, int zahl2)
{
	return zahl1 * zahl2;
}

/*
input parameter		int zahl1 (Dividend)
					int zahl2 (Divisor)
returns				ergebnis
*/
int dividiere(int zahl1, int zahl2)
{
	return zahl1 / zahl2;
}

/*
input parameter		int zahl1 (keine Ahnung wie sich des schimpft 1)
					int zahl2 (keine Ahnung wie sich des schimpft 2)
returns				ergebnis
*/
int rechne_modulo(int zahl1, int zahl2)
{
	return zahl1 % zahl2;
}

/*
input parameter		int basis
					int exponent
returns				ergebnis
*/
int potenzieren_rekursiv(int basis, int exponent)
{
	// Abbruchbedingung
	if (exponent == 0)
	{
		return 1;
	}

	// Rekursionsvorschrift: Exponent wird pro Durchlauf um 1 reduziert
	return basis *= potenzieren_rekursiv(basis, exponent - 1);
}

/*
input parameter		int basis
					int exponent
returns				ergebnis
*/
int potenzieren_schleife(int basis, int exponent)
{
	int ergebnis = 1;

	// Sonderfall
	if (exponent == 0)
	{
		return 1;
	}

	// Normaler Ablauf
	for (short i = 0; i < exponent; i++)
	{
		ergebnis *= basis;
	}

	return ergebnis;
}

/*
input parameter		none
returns				die gelesene Rechenoperation (kodiert im Rechenart enum)
*/
short rechenoperation_einlesen()
{
	printf("Bitte gib die gewuenschte Rechenoperation ein:"
		"\n1\tAddition"
		"\n2\tSubtraktion"
		"\n3\tMultiplikation"
		"\n4\tDivision"
		"\n5\tModulo"
		"\n6\tPotenzieren"
		"\nRechenoperation: ");

	int operation = 0;
	scanf(" %d", &operation);

	return (short) operation;
}

/*
input parameter		int zahlensystem (spezifiziert, in welchem Zahlensystem das Ergebnis dargestellt wird)
returns				(0 = success, 1 = error)
----------------------------------------------------------------------------------------------------------------
Gibt das berechnete Ergebnis in der Konsole aus
*/
short ergebnis_ausgeben(int zahlensystem, int ergebnis)
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
	scanf(" %d", &zahl);

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