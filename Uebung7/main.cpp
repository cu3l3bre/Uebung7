#include <iostream>
#include <string>

using namespace std;





int main()
{

	// Uebung 7 Hangman

	// Deklaration der Varianlen
	// Definieren eines Wortes weleches Erraten werden soll
	string Wort = "test";	// TODO abfrage auf groﬂe und kleine Buchstaben!!
	char Buchstabe = char(0);
	int LaengeWort = 0;
	bool BuchstabeVorhanden = false;
	char EingegebeneBuchstaben[26];
	bool SpielVerlassen = false;
	

	int Versuche = 0;


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

		EingegebeneBuchstaben[Versuche] = Buchstabe;


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