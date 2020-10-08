/**********************************************************************************
 *                                                                                *
 *                               Aufgabenstellungen                               *
 *                                                                                *
 *   Aufgabe 1:         Gefängniszellen von [1, N] sind Anfangs geschlossen.      *
 *                      Zunächst wird jede Tür aufgemacht, danach jede 2'te zu,   *
 *                      3'te auf, 4'te zu ... n'te zu/auf.                        *
 *                      Ermittle welche Türen nach N Durchgängen auf sind!        *
 *                                                                                *
 *                                                                                *
 *   Aufgabe 2:         Aus N Insassen [1, N] wird täglich ZUFÄLLIG ein           *
 *                      Gefängnisinsasse gewählt und in den Lichtraum geführt.    *
 *                      In diesem Raum kann er das Licht an/ aus machen,          *
 *                      oder nichts ändern. Die Insassen können nicht miteinander *
 *                      kommunizieren, aber vorab eine Strategie bereden.         *
 *                      Grundannahmen:pro Tag kommt ein Insasse in den Lichtraum. *
 *                      Wann können die Insassen sicher gehen, dass jeder der     *
 *                      N Insassen im Lichtraum war?                              *
 *                                                                                *
 *                                                                                *
 *   Aufgabe 3:         N Touristen müssen deren eigene Hutfarbe erraten.         *
 *                      Die Touristen sehen lediglich die Hutfarbe der            *
 *                      anderen Touristen, aber nicht deren eigene.               *
 *                      Es gibt 2 verschiedene Hutfarben.                         *
 *                      Die Touristen dürfen nicht miteinander kommunizieren.     *
 *                                                                                *
 *                                                                                *                                                                             
 *   Aufgabe 4:         N touristen mit 2 verschiedenen Hutfarben, sollen sich    *
 *                      in 2 verschiedenen Reihen sortieren und zwar nach ihrer   *
 *                      Hutfarbe. Dabei dürfen sich nicht kommunizieren, oder     *
 *                      sich berühren. Die Touristen kennen nur die Hutfarbe der  *
 *                      anderen Touristen, deren eigene jedoch nicht.             *
 *                                                                                *
 *                                                                                *
 *********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;



//Aufgabe 1: Schließung / Öffnung aller N Gefängniszellen in O(n^2) Time und O(n) Space 
// Idee: für ungerade Anzahl der Teiler der Tür t, ist die Tür t offen  
vector<bool> doorOpen(int n){
    vector<bool> res(n +1,0);
    for(int doorNr = 0; doorNr <= n; doorNr++){
        int anzahlTeiler =1; 
        for(int i = 1; i < doorNr; i++){
            if(!(doorNr % i))anzahlTeiler++; 
        }
        if(anzahlTeiler &1)res[doorNr] = true; 
    }
    return res;        
}


//Aufgabe 1 optimierte Version: O(n) Time/ Space  
//es genügt zu prüfen, ob die Tür t eine Quadratzahl ist, da NUR Quadratzahlen eine ungerade Anzahl an Teilern besitzen
vector<bool> doorOpenOptimized(int n){
    vector<bool> res(n +1,0);
    for(int doorNr = 1; doorNr <= n; doorNr++){
        if((sqrt(doorNr) - ceil(sqrt(doorNr))) == 0) res[doorNr] = true; 
    }
    return res;        
}




/*
Aufgabe 2: Lösung: 
    Der erste Insasse der in den Lichtbetätigunsraum reingelassen wird ist der Zähler;
    nur der Zähler darf das Licht ausmachen, falls ein Insasse zum ersten Mal in dem Lichtraum ist,
    macht er das Licht an, ansonsten ändert er nichts.
    Somit weiß der Zähler beim nächsten Besuch im Lichtraum, ob mindestens eine Person im Lichtraum war.
    Wenn der Zähler das 100'ste. mal das Licht ausmacht, kann er sicher sein, dass alle Insassen einmal drin waren.
*/

//Analyse der Dauer bis N Insassen im Lichtraum waren in O(n) Zeit und O(1) Space
int countDaysOfPrisoners(int n){
    long double days = 1; 
    while(n){
        days += (n*100/ n-1); 
        n--; 
    }     
    return days; 
}


/*
Aufgabe 3: Lösung:
    Idee: Farben als Abfolge [1, N] --> [0,1,1,0,1,1,0,0,0,0,1,0,1,0]
    Strategie: Person 1 rät seine Hutfarbe. 
    Falls die Hutfarbe dem seines Nachbarn entspricht, sagt er dies mit lauter Stimme,
    falls nicht, mit leiser Stimme. Somit können wir mindestens N -1 Touristen retten.
*/


/*
Aufgabe 4: Lösung:
    Idee: erste Person stellt sich in eine beliebige Reihe. 
    Fall 1: [1 X] --> der Nachfolger X stellt sich in Richtung A zu seinem Vörgänger, da der Vor-
            in der richtigen Reihe steht.  
    Fall 2: [X 1] --> der Nachfolger X stellt sich in Richtung B zu seinem Vörgänger. Der Vorgänger
    muss auf die andere Seite. Nun ist die Person i sortiert und genauso sortieren sich alle anderen. 
    Die letzte Person n hat keinen Nachfolger, somit muss der bereits sortierte Vorgänger n-1 aushelfen. 
*/

int main(){
    int n = 100; 
    vector<bool> doors = doorOpenOptimized(n); 
    for(int i = 1; i < doors.size(); i++){
      if(doors[i])cout << "Gefängniszelle: " << i << " ist offen!" <<"\n" ;
    } 
    
    cout<<"\n\n" <<"Es dauert: "<< countDaysOfPrisoners(n) << " Tage, bis alle "<< n<< " Insassen im Lichtraum waren!" <<"\n"; 

    
    /*   
    Output: 
        Gefängniszelle: 1 ist offen!
        Gefängniszelle: 4 ist offen!
        Gefängniszelle: 9 ist offen!
        Gefängniszelle: 16 ist offen!
        Gefängniszelle: 25 ist offen!
        Gefängniszelle: 36 ist offen!
        Gefängniszelle: 49 ist offen!
        Gefängniszelle: 64 ist offen!
        Gefängniszelle: 81 ist offen!
        Gefängniszelle: 100 ist offen!
      
        Es dauert: 9901 Tage, bis alle 100 Insassen im Lichtraum waren!
    */
}
