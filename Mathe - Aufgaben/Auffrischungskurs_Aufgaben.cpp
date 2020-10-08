#include <iostream>
#include <vector>
using namespace std;


/*
Aufgabe 1:
Gefängniszellen von [1, N] sind Anfangs geschlossen. Zunächst wird jede Tür aufgemacht, danach jede 2'te zu, 3'te auf ... n'te zu/ auf.
Ermittle welche Türen nach n Durchgängen auf sind!
*/


//O(n^2) Time und O(n) Space Complexity 
// Idee: für ungerade Anzahl der Teiler der Tür t ist die Tür t offen  
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


//O(n) Time und Space Complexity 
//es genügt zu prüfen, ob die Tür t eine Quadratzahl ist, da NUR Quadratzahlen eine ungerade Anzahl an Teilern besitzen
vector<bool> doorOpenOptimized(int n){
    vector<bool> res(n +1,0);
    for(int doorNr = 1; doorNr <= n; doorNr++){
        if((sqrt(doorNr) - ceil(sqrt(doorNr))) == 0) res[doorNr] = true; 
    }
    return res;        
}




/*
Aufgabe 2:

Grundannahmen: ein Insasse pro Tag wird ins Zimmer des Wärters geholt, Zähler ist der erste Insasse, alle Insassen sind intelligent genug die Strategie zu befolgen; 
Strategie der Insassen: der erste Insasse der in den Lichtbetätigunsraum reingelassen wird ist der Zähler;
                        nur der Zähler darf das Licht ausmachen, falls ein Insasse zum ersten Mal in dem Lichtraum ist, macht er das Licht an,
                        sofern es noch nicht an ist. Somit weiß der Zähler beim nächsten Besuch im Lichtraum, dass mindestens eine Person da war.
                        Der Zähler muss 100 mal das Licht ausmachen, danach kann er sicher sein, dass alle Insassen einmal drin waren.
*/

int countDaysOfPrisoners(int n){
    long double days = 1; 
    while(n){
        days += (n*100/ n-1); 
        n--; 
    }     
    return days; 
}


int main(){
    int n = 100; 
    //vector<bool> doors = doorOpen(n); 
    vector<bool> doors = doorOpenOptimized(n); 
    for(int i = 1; i < doors.size(); i++){
      if(doors[i])cout << "Zimmer: " << i << " ist offen!" <<"\n" ;
    } 
    
    cout<<"\n\n" <<"Es dauert: "<< countDaysOfPrisoners(n) << " Tage, bis alle "<< n<< " Insassen im Lichtraum waren!" <<"\n"; 

    
    /*   
    Output: 
      Zimmer: 1 ist offen!
      Zimmer: 4 ist offen!
      Zimmer: 9 ist offen!
      Zimmer: 16 ist offen!
      Zimmer: 25 ist offen!
      Zimmer: 36 ist offen!
      Zimmer: 49 ist offen!
      Zimmer: 64 ist offen!
      Zimmer: 81 ist offen!
      Zimmer: 100 ist offen!
      
      Es dauert: 9901 Tage, bis alle 100 Insassen im Lichtraum waren!
    */
}