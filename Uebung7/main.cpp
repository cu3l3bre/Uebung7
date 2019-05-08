#include <iostream>
#include <string>


using namespace std;


void PictureHangman(int Fehlversuche)
{
	// TODO Irgendwann mal schick machen das das cool aussieht
	switch (Fehlversuche)
	{
	
	case 1:
		cout << "											|	     " << endl;
		cout << "											|	     " << endl;
		cout << "											|	     " << endl;
		cout << "___________________________________________|_______" << endl;
		break;

	case 2:
		cout << "										 |	     " << endl;
		cout << "										 |	     " << endl;
		cout << "										 |	     " << endl;
		cout << "_______________________________________/|_______" << endl;
		break;



	default: 
		
		cout << "											     " << endl;
		cout << "											     " << endl;
		cout << "											     " << endl;
		cout << "________________________________________________" << endl;
		
		break; 
		
		
	}
}



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
	// TODO das einfchste wird sein alles in Groﬂbuchtstaben zu wandeln
	// egal was eingegben wird
	// auch das anfangswort in Groﬂes buchstaben mappen


	// Uebung 7 Hangman

	// Deklaration der Varianlen
	// Definieren eines Wortes weleches Erraten werden soll
	string Wort = "dumdidum";	// TODO abfrage auf groﬂe und kleine Buchstaben!!
	char Buchstabe = char(0);
	int LaengeWort = 0;
	bool BuchstabeVorhanden = false;
	char EingegebeneBuchstaben[26]; // TODO kann sp‰ter die grˆﬂe von anzahl versuche haben
	bool SpielVerlassen = false;
	
	//transform(Wort.begin(), Wort.end(), Wort.begin(), ::toupper);

	int Versuche = 0;
	int Fehler = 0;

	// Funktion um den Eingabetext in Gross machn
	Wort = SwitchStringToUppercase(Wort);

	cout << " Das geanderte Wort ist nun: " << Wort << endl;


	LaengeWort = Wort.length();
	//cout << LaengeWort;

	//Dynamisch Speicher anforden in Abh‰ngkeit der L‰nge des zu ratenden Wortes
	char* ArrayWort = new char[LaengeWort+1]; // +1 um den \0 f¸r den string zu erg‰nzen, um keinen m¸ll zu sehen
	
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

		// Zum Anzeigen eines Bildes vom Hangman
		// TODO Versuche sind keine Fehler
		// Nur bei falsch geraten muss man das Bild ‰ndern
		PictureHangman(Fehler);


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

		/*
		// Groﬂer und kleiner Buchstabe eingegeben? vllt ne replace funktion machen?
		int BuchstabeZahlGross = 0;
		int BuchstabeZahlKlein = 0;
		int Offset = 32 ;

		if (isupper(Buchstabe))
		{
			cout << "Groﬂ" << endl;
			BuchstabeZahlGross = int(Buchstabe);
			BuchstabeZahlKlein = BuchstabeZahlGross + Offset;
			cout << BuchstabeZahlGross << endl;
			cout << BuchstabeZahlKlein << "  " << char(BuchstabeZahlKlein) << endl;
		}
		else if(islower(Buchstabe))
		{
			cout << "Klein" << endl;
			BuchstabeZahlKlein = int(Buchstabe);
			BuchstabeZahlGross = BuchstabeZahlKlein - Offset;
			cout << BuchstabeZahlGross << "  " << char(BuchstabeZahlGross) << endl;
			cout << BuchstabeZahlKlein << "  " << char(BuchstabeZahlKlein) << endl;
		}
		*/





		for (int i = 0; i <= LaengeWort; i++)
		{
			if (Buchstabe == Wort[i])
			{
				BuchstabeVorhanden = true;
				ArrayWort[i] = Buchstabe;
			}
		}

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


		//GeratenesWort = ArrayWort;

		string GeratenesWort(ArrayWort);

		cout << endl;
		//cout << "GeratenesWort ist : " << GeratenesWort << endl;




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


	






	// Pr¸fen ob der eingegebene Buchstabe im Wort vorhanden ist

	// Melung das der Buchstabe richtig geraten wurde

	// Meldung das der Buchstabe falsch geraten wurde


	// Printen mit den Buchstaben die richtig geraten worden sind
	// Printen von Underlines mit Anzahl Buchstaben des Wortes

	// Irgendwann mal Malen des Hangman Balkens





	delete ArrayWort;

	system("pause");
	return 0;
}