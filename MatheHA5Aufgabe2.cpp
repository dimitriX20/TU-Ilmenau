int stellenLength(double d){
    int res = 0; 
    while(abs((floor(res) - d)) >0){
        d*=10; 
        res = d;  
    }
    return to_string(res).length(); 
}


 double f(int k){ 
    //für ungerade pos.: 
    return k&1? 1/(pow(k,3) + k): -1/(pow(k,3) + k); 
}


int main() {
    int iterations = 1; 
    double erg = 0, preVal = 0; 
    while(stellenLength(iterations-1) < 3){
        cout << iterations-1 << "'es Glied, Wert: " << erg << " Änderung: " << preVal << endl; 
        erg += f(iterations); 
        preVal =f(iterations);  
        iterations++;   
    }
    cout<< iterations-1 << "'es Glied, Gliedveränderung wäre: " << f(iterations); 
}

/*
OUTPUT: 

0'es Glied, Wert: 0 Änderung: 0
1'es Glied, Wert: 0.5 Änderung: 0.5
2'es Glied, Wert: 0.4 Änderung: -0.1
3'es Glied, Wert: 0.433333 Änderung: 0.0333333
4'es Glied, Wert: 0.418627 Änderung: -0.0147059
5'es Glied, Wert: 0.42632 Änderung: 0.00769231
6'es Glied, Wert: 0.421815 Änderung: -0.0045045
7'es Glied, Wert: 0.424672 Änderung: 0.00285714
8'es Glied, Wert: 0.422749 Änderung: -0.00192308
9'es Glied, Wert: 0.424104 Änderung: 0.00135501
10'es Glied, Gliedveränderung wäre: 0.000745156

*/
