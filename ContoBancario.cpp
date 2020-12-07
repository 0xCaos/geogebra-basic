#include <iostream>
using namespace std;

class ContoBancario {
private:	// MANTRA: membri sensibili => parte privata
    double saldo;
public:
    ContoBancario() : saldo(0){};
    // Controllo solo che il prelievo o il deposito siano consistenti, altrimenti insensato!!!
    double deposita(double x){
        return x>=0 ? saldo += x : saldo;
    }
    double preleva(double x){
        return x>=0 ? saldo -= x : saldo;
    }

//protected: ancora più sicuro ma blocca l'accesso all'utente !!!
    double getSaldo() const {return saldo;}

    ContoBancario(double s=0.0) : saldo(s >= 0? s : 0.0){}
};

class ContoCorrente: public ContoBancario {
private:
    static double spesaFissa; 	// è un attributo statico (così non viene ripetuto in ogni oggetto)
    // manteniamo la possibilità di modifiche di questo valore
public:
    /*
        Riflessione:
            non abbiamo a disposizione il saldo perchè è privato !!!
    */
    // se (x < spesaFissa), non avviene il deposito
    double deposita(double x){
        return ContoBancario::deposita(x-spesaFissa);
    }
    double preleva(double x){
        return ContoBancario::preleva(x+spesaFissa);
    }
};

// N.B Le variabili statiche vanno create fuori
double ContoCorrente::spesaFissa = 1.0;

class ContoDiRisparmio: public ContoBancario {
public:
    // Invariante: saldo >= 0	
    double preleva(double x){
        return x < getSaldo() ? ContoBancario::preleva(x) : getSaldo();
    }
    // ContoBancario::deposita() non necessita di ridefinizione

    ContoDiRisparmio(double s=0.0) : ContoBancario(s) {} 
};

/*
class ContoArancio: public ContoDiRisparmio {
// Conto di appoggio deve essere modificabile! Pensare a come incapsularlo
private:
    ContoCorrente cca;
public:
    double preleva(double s){ // ContoArancio è un ContoDiRisparmio => saldo >=0
        ContoDiRisparmio::preleva(s);
        cca.ContoCorrente::deposita(s);
        return getSaldo();
    }
    double deposita(double s){
        cca.ContoCorrente::preleva(s);	// tolgo la somma dal conto corrente di appoggio
        return ContoBancario::deposita(s);
    }

    void inizializzaSaldoAppoggio(int saldo){
        cca.deposita(saldo);
    }

    //ContoArancio() : ContoDiRisparmio() {};
};
*/

class ContoArancio: public ContoDiRisparmio {
// ci dobbiamo riferire a un conto esterno!!!
private:
	ContoCorrente& appoggio;
	// ContoArancio è un ContoDiRisparmio => Invariante: saldo >= 0
public:
	// per i field che sono dei riferimenti devo INIZIALIZZARLI => devo scrivere un costruttore
	// non con un riferimento costante visto che voglio che possa subire modifiche
	// l'esercizio non richiede di scrivere dei costruttori, ma richiede esclusivamente di funzionare con un conto di appoggio
	ContoArancio(ContoCorrente& cc, double s=0.0) : ContoDiRisparmio(s), appoggio(cc) {}
	double preleva(double x){
		if(x<=getSaldo() && 0<=x) {
			appoggio.deposita(x);
			return ContoDiRisparmio::preleva(x);
		}
		return getSaldo();

	}

	double deposita(double x){
		if(x>=0){
			appoggio.preleva(x);
			return ContoDiRisparmio::deposita(x);
		}
		return getSaldo();
	}

};


int main(){
    ContoArancio ca;
    ca.inizializzaSaldoAppoggio(2000);
    cout << "Saldo conto di appoggio: " << ca.getSaldo() << endl;
    cout << "Saldo attuale: " << ca.deposita(200) << endl;
    cout << "Saldo attuale: " << ca.preleva(50) << endl;

    cout << "Fine";
}