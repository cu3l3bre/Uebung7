#include <iostream>
#include <string>

#define MAX_VERSUCHE 9

using namespace std;

// Funktion zur Ausgeben einer Grafik
void PictureHangman(int Fehlversuche)
{
	switch (Fehlversuche)
	{


	case 1:
		cout << "                                           	     " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "____________________________________________|_______" << endl;
		cout << endl;
		break;

	case 2:
		cout << "                                           	     " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "___________________________________________/|_______" << endl;
		cout << endl;
		break;

	case 3:
		cout << "                               ______________	     " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "___________________________________________/|_______" << endl;
		cout << endl;
		break;

	case 4:
		cout << "                               ______________	     " << endl;
		cout << "                               |            |       " << endl;
		cout << "                               |            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "___________________________________________/|_______" << endl;
		cout << endl;
		break;

	case 5:
		cout << "                               ______________	     " << endl;
		cout << "                               |/           |       " << endl;
		cout << "                               |            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "___________________________________________/|_______" << endl;
		cout << endl;
		break;


	case 6:
		cout << "                               ______________	     " << endl;
		cout << "                               |/           |       " << endl;
		cout << "                               |            |       " << endl;
		cout << "                               O            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "___________________________________________/|_______" << endl;
		cout << endl;
		break;


	case 7:
		cout << "                               ______________	     " << endl;
		cout << "                               |/           |       " << endl;
		cout << "                               |            |       " << endl;
		cout << "                               O            |       " << endl;
		cout << "                               |            |       " << endl;
		cout << "                               |            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "___________________________________________/|_______" << endl;
		cout << endl;
		break;



	case 8:
		cout << "                               ______________	     " << endl;
		cout << "                               |/           |       " << endl;
		cout << "                               |            |       " << endl;
		cout << "                               O            |       " << endl;
		cout << "                              /|/           |       " << endl;
		cout << "                               |            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "                                            |       " << endl;
		cout << "___________________________________________/|_______" << endl;
		cout << endl;
		break;

	case 9:
		cout << "                               ______________	     " << endl;
		cout << "                               |/           |       " << endl;
		cout << "                               |            |       " << endl;
		cout << "      GAME OVER :(             O            |       " << endl;
		cout << "                              /|/           |       " << endl;
		cout << "                               |            |       " << endl;
		cout << "                              / /           |       " << endl;
		cout << "                                            |       " << endl;
		cout << "___________________________________________/|_______" << endl;
		cout << endl;
		break;



	default:
		cout << "                                           	     " << endl;
		cout << "                                                    " << endl;
		cout << "                                                    " << endl;
		cout << "                                                    " << endl;
		cout << "                                                    " << endl;
		cout << "                                                    " << endl;
		cout << "                                                    " << endl;
		cout << "                                                    " << endl;
		cout << "____________________________________________________" << endl;
		cout << endl;
		break;


	}
}


// Funktion zum GROSS machen des Wortes
string SwitchStringToUppercase(string Wort)
{
	int WortLaenge = Wort.length();
	bool IstGross = false;
	int Zahl = 0;

	for (int i = 0; i < WortLaenge; i++)
	{
		if (isupper(Wort[i]))
		{
			// Nichts machen
		}
		else
		{
			int Zahl = char(Wort[i]);
			Zahl = Zahl - 32; //Offset zu den Grossbuchstaben 
			Wort[i] = char(Zahl);
		}
	}

	return Wort;
}



// Funktion zum GROSS eines Buchstaben
char SwitchStringToUppercase(char Letter)
{
	bool IstGross = false;
	int Zahl = 0;

	if (isupper(Letter))
	{
		// Nichts machen
	}
	else
	{
		int Zahl = char(Letter);
		Zahl = Zahl - 32; //Offset zu den Grossbuchstaben 
		Letter = char(Zahl);
	}

	return Letter;
}



int main()
{
	// Uebung 7 Hangman

	// Deklaration der Varianlen

	string Wort = "hangman";
	char Buchstabe = char(0);
	char EingegebeneBuchstaben[26];
	int LaengeWort = 0;
	int Versuche = 0;
	int Fehler = 0;
	bool BuchstabeVorhanden = false;
	bool SpielVerlassen = false;

	// Funktion um den Eingabetext in Gross machn
	Wort = SwitchStringToUppercase(Wort);


	// Ermitteln der Laenge des Wortes
	LaengeWort = Wort.length();


	//Dynamisch Speicher anforden in Abhängkeit der Länge des zu ratenden Wortes
	char* ArrayWort = new char[LaengeWort + 1]; // +1 um den \0 für den string zu ergänzen, um keinen müll zu sehen

												// Neues Array mit _ Initen
	for (int i = 0; i < LaengeWort; i++)
	{
		ArrayWort[i] = char(95);
	}
	ArrayWort[LaengeWort] = '\0';


	// Begruessung zum Spiel
	cout << "Willkommen bei Hangman. Zeit zum Spielen" << endl;


	while (!SpielVerlassen)
	{
		Versuche++;

		PictureHangman(Fehler);

		if (Fehler < MAX_VERSUCHE)
		{

			for (int i = 0; i < LaengeWort; i++)
			{
				cout << ArrayWort[i];
			}
			cout << endl;


			if (Versuche > 1)
			{
				cout << "Bereits verwendete Buchstaben: ";

				for (int i = 1; i < Versuche; i++)

					cout << EingegebeneBuchstaben[i] << " ";
			}
			cout << endl;

			// Eingabe eines Zeichens Buchstabens durch den Benutzer
			cout << "Rate einen Buchstaben: ";
			BuchstabeVorhanden = false;
			cin >> Buchstabe;

			// Funktion die den eingegeben Buchstaben UpperCase macht
			Buchstabe = SwitchStringToUppercase(Buchstabe);

			// Fuellen eines Arrays mit bereits benutzen Buchstaben
			EingegebeneBuchstaben[Versuche] = Buchstabe;

			for (int i = 0; i <= LaengeWort; i++)
			{
				if (Buchstabe == Wort[i])
				{
					BuchstabeVorhanden = true;
					ArrayWort[i] = Buchstabe;
				}
			}

			system("cls");

			// Buchstabe ist im Wort vorhanden
			if (BuchstabeVorhanden)
			{
				cout << "Richtig!!! Der Buchstabe " << Buchstabe << " ist im gesuchten Wort vorhanden!" << endl;
			}
			else
			{
				cout << "Leider kein Treffer :( Der Buchstabe " << Buchstabe << " ist nicht vorhanden!" << endl;
				Fehler++;
			}

			// Wandeln des Wortes im Array als String zum Vergleich mit dem Anfangswort
			string GeratenesWort(ArrayWort);

			cout << endl;

			if (GeratenesWort == Wort)
			{
				for (int i = 0; i < LaengeWort; i++)
				{
					cout << ArrayWort[i];
				}
				cout << endl;

				SpielVerlassen = true;
				cout << "Sie haben das Wort " << GeratenesWort << " erraten :) " << endl;

			}
		}
		else
		{
			SpielVerlassen = true;
			cout << "Sie haben das Spiel leider verloren :(" << endl;
		}
	}

	delete ArrayWort;

	system("pause");
	return 0;
}