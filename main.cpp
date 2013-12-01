#include <iostream>
//! fuer mingw unter win7 damit BUFSIZ definition gefunden wird:
#include <cstdio>

/*
Programm zum Umrechnen einer Dezimalzahl
in ein beliebigs Zahlenformat der Basiszahl
2 bis 9.
*/


using namespace std;

int main()
{

    int basis=0,stellen = 0,rest =0 ;
    unsigned long dezwert=0;
    bool nocheinmal=false,eingabeOk;
    string eingabebasis = "Geben sie eine Basiszahl zwischen 2 und 9 (einschliesslich) ein:";
    string eingabedez = "Geben sie einen positiven umzurechnenden dezimalen Wert ein. Der Wert muss kleiner gleich ";
    string fehlerbasis = "\nUngueltige Eingabe!\nDie Basiszahl muss zwischen 1 und 10 liegen!";
    string fehlerdez = "Ungueltige Eingabe - Der Wert muss positiv sein und nicht groesser als ";
    string ende = "moechten sie noch eine Berechung durchfuehren? (Ja = 1)";

    //! Ermitteln der maximal möglichen Dezimalzahl.
    //! Zuerst ermittle ich wievele Bits das System darstellen kann.
    //! Dadurch erhalte ich die maximal notwendigen Stellen
    //! des Arrays zur Aufnahme der Stellen für die Umgerechnete
    //! Zahl.
    stellen = sizeof(unsigned long)*8;
    //cout << "Stellen: "  << stellen << endl;


    //! Berechnen des maximal möglichen Dezimalwertes:
    //! "(basiszahl exponent anzahl der Stellen)-1"
    //! Basiszahl ist dabei 2 da es sich bei einem Computer um
    //! ein Binäres System handelt.
    unsigned long maxwert = 1;
    int z=0;
    while(z < 63){
         maxwert = maxwert*2;
        z++;
    }
    maxwert = maxwert + maxwert-1;
    //cout << "maxwert: "  << maxwert << endl;
    //unsigned long maxwert = 18446744073709551615;

    //! Das Feld fuer die Umgerechnete Zahl:
    unsigned long ergebniss[stellen];




    do{//! Abfrage ob noch eine Berechnung durchgeführt werden soll

        //! Initialisierung des Array mit 0;
        for(int i=0;i<stellen;i++){
            ergebniss[i]=0;
        }
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
                cin.ignore(BUFSIZ, '\n');
        do {//! Pruefen of die Basiszahl zwischen 1 und 10 liegt
                eingabeOk = true;
                cout << eingabebasis << endl;
                cin >> basis;
                if(!(basis >1 && basis < 10) || cin.fail()){
                    cout << fehlerbasis << endl;
                    eingabeOk = false;
                    cin.clear();
                    cin.ignore(BUFSIZ, '\n');
                }
                else{
                    do{//! Prüfen ob ein gültiger Dezimalwert eingegeben wurde
                       eingabeOk = true;
                       cout << eingabedez << maxwert << " sein! "<< endl;
                       cin >> dezwert;
                       if(cin.fail() || dezwert > maxwert){
                            eingabeOk = false;
                            //cout << "\ungueltige Eingabe!\n";
                            cin.clear();
                            cin.ignore(BUFSIZ, '\n');
                        }

                            if(!eingabeOk){
                                cout << fehlerdez << maxwert << "!\n";

                            }
                    }while(!eingabeOk);

                    cout << "\nIhre Eingabe:\nDezimalwert: " << dezwert << "\nBasiszahl: "<< basis << endl <<
                    "\nErgebniss";
                    int z = 0;
                    //! Umrechnung:
                    do{
                        rest = dezwert%basis;
                        ergebniss[z] = rest;
                        dezwert /=basis;
                        z++;
                    } while(dezwert && z< stellen);

                    //! Ausgabe des Ergebnisses:
                    if(basis == 2){
                        cout << " (dual):\n";
                    }
                    else if(basis == 8){
                        cout << " (octal):\n";
                    }
                    else
                        cout << "zahl mit der Basis "<< basis <<":\n";
                    //! Unnoetige Nullwerte am Beginn der Ergenisses entfernen:
                    bool skip_0 = true;
                    for(int i=stellen-1;i>=0;i--){
                        if( basis == 2){
                            cout << ergebniss[i];
                            if (i % 4 == 0) cout << " ";
                            if (i % 8 == 0) cout << "  ";
                            if (i % 16 == 0) cout << "\n";
                        }
                        else{
                            if(!ergebniss[i] == 0 || !skip_0){
                                cout << ergebniss[i];
                                skip_0 = false;
                            }
                        }
                    }
                    cout << endl << endl;
                }
        }while (!eingabeOk);
        cout << ende << endl;
        cin >> nocheinmal;

        if(cin.fail()){
            //cout << "ihre Eingabe war nicht gueltig!\n";
            cin.clear();
            cin.ignore(BUFSIZ, '\n');
            nocheinmal = 0;
            }
    }while(nocheinmal == 1);

    return 0;
}
