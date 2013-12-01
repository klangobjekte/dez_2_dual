#include <iostream>
/*
Programm zum Umrechnen einer Dezimalzahl
in ein beliebigs Zahlenformat der Basiszahl
2 bis 9.
*/


using namespace std;

int main()
{
    int basis=0,stellen = 0,rest =0 ;
    //! todo
    //! sizeof liefert als Einheit bytes deshalb *8!
    stellen = sizeof(unsigned long)*8;
    cout << "Stellen: "  << stellen << endl;
    unsigned long wert=0;

    //! Um einen Speicherüberlauf zu vermeiden
    //! ermittele ich den maximal moeglichen Wertes:
    //! "(basiszahl exponent anzahl der Stellen)-1"
    unsigned long maxwert = 1;
    int z=0;
    while(z < 63){
         maxwert = maxwert*2;
        z++;
    }
    maxwert = maxwert + maxwert-1;
    cout << "maxwert: "  << maxwert << endl;
    //unsigned long maxwert = 18446744073709551615;
    bool nocheinmal=false,eingabeOk ;
    unsigned long ergebniss[stellen];
    string text = "Geben sie einen umzurechnenden dezimalen Wert ein.\nDer Wert muss positiv sein und kleiner als ";
    string text2 = "Geben sie den umzurechnenden dezimalen Wert ein.\nDer Wert muss positiv sein und nicht groesser als ";
    string text3 = "Geben sie einen positiven umzurechnenden dezimalen Wert ein: ";


    do{//! Abfrage noch eine Berechnung
        //! Initialisierung des Array mit 0;
        for(int i=0;i<stellen;i++){
            ergebniss[i]=0;
        }
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
                //cin.ignore(BUFSIZ, '\n');
        do {//! Wir pruefen of die Basiszahl zwischen 1 und 10 liegt
                eingabeOk = true;
                cout << "Geben sie eine Basiszahl zwischen 2 und 9 (einschliesslich) ein:" << endl;
                cin >> basis;
                if(!(basis >1 && basis < 10) || cin.fail()){
                    cout << "\nUngueltige Eingabe!\nDie Basiszahl muss zwischen 1 und 10 liegen!" << endl;
                    eingabeOk = false;
                    cin.clear();
                    cin.ignore(BUFSIZ, '\n');
                }
                else{
                    //!  Da unser Array nur 16 Stellen hat,
                    //!  muessen wir die Eingabe auf einen Maximale Wert, welcher mit
                    //!  "basiszahl exponent anzahl der Stellen-1" ermittelt wurde, beschraenken!
                    do{
                       eingabeOk = true;
                       cout << text3 << endl;
                       cin >> wert;
                       if(cin.fail() || wert > maxwert){
                            eingabeOk = false;
                            //cout << "\ungueltige Eingabe!\n";
                            cin.clear();
                            cin.ignore(BUFSIZ, '\n');
                        }

                       switch(basis){
                                case 2:
                                cout << text << " 65.536 sein!" << endl;
                                cin >> wert;
                                if(wert >65536 || wert < 0){
                                    eingabeOk = false;
                                }
                                break;
                                case 3:
                                cout << text << " 43.046.721 sein!" << endl;
                                cin >> wert;
                                if(wert >43046721 || wert < 0){
                                    eingabeOk = false;
                                }
                                break;
                                case 4:
                                cout << text << " 4.294.967.296 sein!" << endl;
                                cin >> wert;
                                if(wert >4294967296 || wert < 0){
                                    eingabeOk = false;
                                }
                                break;
                                case 5:
                                cout << text << " 152.587.890.625 sein!" << endl;
                                cin >> wert;
                                if(wert >152587890625 || wert < 0){
                                    eingabeOk = false;
                                }
                                break;
                                case 6:
                                cout << text << "2.821.109.907.456 sein!" << endl;
                                cin >> wert;
                                if(wert >2821109907456 || wert < 0){
                                    eingabeOk = false;
                                }
                                break;
                                case 7:
                                cout << text << " 33.232.930.569.601 sein!" << endl;
                                cin >> wert;
                                if(wert >33232930569601 || wert < 0){
                                    eingabeOk = false;
                                }
                                break;
                                case 8:
                                cout << text<< " 281.474.976.710.656 sein!" << endl;
                                cin >> wert;
                                if(wert >281474976710656 || wert < 0){
                                    eingabeOk = false;
                                }
                                break;
                                case 9:
                                cout << text<< " 1.853.020.188.851.840 sein!" << endl;
                                cin >> wert;
                                if(wert >1853020188851840 || wert < 0){
                                    eingabeOk = false;
                                }
                                break;
                            }

                            if(!eingabeOk){
                                cout << "Ungueltige Eingabe - Der Wert muss positiv sein und nicht groesser als " << maxwert << "!\n";

                            }
                    }while(!eingabeOk);

                    cout << "\nIhre Eingabe:\nDezimalwert: " << wert << "\nBasiszahl: "<< basis << endl <<
                    "\nErgebniss";
                    int z = 0;
                    //! Umrechnung:
                    do{
                        rest = wert%basis;
                        //out << endl << z << " " << wert << " % " << basis << " = rest: "<< rest << ", wert: ";
                        wert = wert/basis;
                        //cout << wert << endl;
                        ergebniss[z] = rest;
                        z++;
                    } while(wert && z< stellen);
                    //! Ausgabe des Ergebnisses:
                    if(basis == 2){
                        cout << " (dual):\n";
                    }
                    else if(basis == 8){
                        cout << " (octal):\n";
                    }
                    else
                        cout << ":\n";
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
        cout << "moechten sie noch eine Berechung durchfuehren? (Ja = 1)" << endl;
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
