#include<iostream>
#include<fstream>
#include <ctime>
#include<math.h>
#include<iomanip>

using namespace std;

class Autoturism
{
private:
	const int id;
	static int nr_autoturisme;
	char* nume;
	char* motor;
	int viteza_maxima;
	int capacitate_cilindrica;
	int consum_viteza_med_urban[2];
	int consum_viteza_med[2];


public:
	static int get_nr_autoturisme()
	{
		return nr_autoturisme;
	}
	const int get_id()
	{
		return id;
	}
	char* get_nume()
	{
		return nume;
	}
	char* get_motor()
	{
		return motor;
	}
	int get_viteza_max()
	{
		return viteza_maxima;
	}
	int get_cap_cilindrica()
	{
		return capacitate_cilindrica;
	}
	int* get_consum_viteza_med_urban()
	{
		return consum_viteza_med_urban;
	}
	int* get_consum_viteza_med()
	{
		return consum_viteza_med;
	}

	void set_nume(char* nume)
	{
		if (this->nume != NULL)
			delete[]this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	void set_motor(char* motor)
	{
		if (this->motor != NULL)
			delete[] this->motor;
		this->motor = new char[strlen(motor) + 1];
		strcpy(this->motor, motor);
	}
	void set_viteza_max(int viteza_max)
	{
		if (viteza_max<400 && viteza_max>150)
			viteza_maxima = viteza_max;
	}
	void set_cap_cilindrica(int cap_cilindrica)
	{
		if (cap_cilindrica<2800 && cap_cilindrica>1000)
			cap_cilindrica = capacitate_cilindrica;
	}
	void set_consum_viteza_med_urban(int *consum_viteza_med_urban)
	{
		if (consum_viteza_med_urban[0]> 2 && consum_viteza_med_urban[0] < 30)
			this->consum_viteza_med_urban[0] = consum_viteza_med_urban[0];
		if (consum_viteza_med_urban[1]>40 && consum_viteza_med_urban[1]<300)
			this->consum_viteza_med_urban[1] = consum_viteza_med_urban[1];
	}
	void set_consum_viteza_med(int *consum_viteza_med)
	{
		if (consum_viteza_med[0]>2 && consum_viteza_med[0]<30)
			this->consum_viteza_med[0] = consum_viteza_med[0];
		if (consum_viteza_med[1]>40 && consum_viteza_med[1]<300)
			this->consum_viteza_med[1] = consum_viteza_med[1];
	}

	Autoturism() :id(nr_autoturisme + 1)
	{
		nume = new char[strlen("auto1") + 1];
		strcpy(nume, "auto1");
		motor = new char[strlen("hybrid") + 1];
		strcpy(motor, "hybrid");
		viteza_maxima = 200;
		capacitate_cilindrica = 1720;
		consum_viteza_med_urban[0] = 8;
		consum_viteza_med_urban[1] = 50;
		consum_viteza_med[0] = 6;
		consum_viteza_med[1] = 120;
		Autoturism::nr_autoturisme++;
	}
	Autoturism(int id2) :id(id2)
	{
		nume = NULL;
		motor = NULL;
		viteza_maxima = NULL;
		capacitate_cilindrica = NULL;
		consum_viteza_med_urban[0] = NULL;
		consum_viteza_med_urban[1] = NULL;
		consum_viteza_med[0] = NULL;
		consum_viteza_med[1] = NULL;
		Autoturism::nr_autoturisme++;
	}
	Autoturism(const int id_nou, char *nume, char* motor, int viteza_maxima, int capacitate_cilindrica, int* consum_viteza_med_urban, int* consum_viteza_med) :id(id_nou)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->motor = new char[strlen(motor) + 1];
		strcpy(this->motor, motor);
		this->viteza_maxima = viteza_maxima;
		this->capacitate_cilindrica = capacitate_cilindrica;
		this->consum_viteza_med_urban[0] = consum_viteza_med_urban[0];
		this->consum_viteza_med_urban[1] = consum_viteza_med_urban[1];
		this->consum_viteza_med[0] = consum_viteza_med[0];
		this->consum_viteza_med[1] = consum_viteza_med[1];
		Autoturism::nr_autoturisme++;
	}
	Autoturism(Autoturism &a) :id(a.id)
	{
		this->nume = new char[strlen(a.nume) + 1];
		strcpy(this->nume, a.nume);
		this->motor = new char[strlen(a.motor) + 1];
		strcpy(this->motor, a.motor);
		this->viteza_maxima = a.viteza_maxima;
		this->capacitate_cilindrica = a.capacitate_cilindrica;
		this->consum_viteza_med_urban[0] = a.consum_viteza_med_urban[0];
		this->consum_viteza_med_urban[1] = a.consum_viteza_med_urban[1];
		this->consum_viteza_med[0] = a.consum_viteza_med[0];
		this->consum_viteza_med[1] = a.consum_viteza_med[1];
		Autoturism::nr_autoturisme++;
	}

	Autoturism operator=(Autoturism a)
	{
		delete[]this->nume;
		delete[]this->motor;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->motor = new char[strlen(a.motor) + 1];
		strcpy(this->motor, a.motor);
		this->viteza_maxima = a.viteza_maxima;
		this->capacitate_cilindrica = a.capacitate_cilindrica;
		this->consum_viteza_med_urban[0] = a.consum_viteza_med_urban[0];
		this->consum_viteza_med_urban[1] = a.consum_viteza_med_urban[1];
		this->consum_viteza_med[0] = a.consum_viteza_med[0];
		this->consum_viteza_med[1] = a.consum_viteza_med[1];
		Autoturism::nr_autoturisme--;
		return *this;
	}

	~Autoturism()
	{
		delete[] this->nume;
		delete[] this->motor;
	}

	friend istream& operator>>(istream& intrare, Autoturism &a);
	friend ostream& operator<<(ostream& iesire, Autoturism a);
	friend ifstream& operator>>(ifstream& intrare, Autoturism &a);
	friend ofstream& operator<<(ofstream& iesire, Autoturism a)
	{
		iesire << a.id << endl;
		iesire << a.nume << endl;
		iesire << a.motor << endl;
		iesire << a.viteza_maxima << endl;
		iesire << a.capacitate_cilindrica << endl;
		iesire << a.consum_viteza_med_urban[0] << endl;
		iesire << a.consum_viteza_med_urban[1] << endl;
		iesire << a.consum_viteza_med[0] << endl;
		iesire << a.consum_viteza_med[1] << endl;

		return iesire;
	}

	void viteza()
		//functia verifica daca viteza medie este mai mica decat 100 pt ca masina sa consume mai putin combustibil
	{
		if ((consum_viteza_med[1] + 10) <= 100)
			consum_viteza_med[1] = consum_viteza_med[1] + 10;
		else throw "Viteza prea mare pt a consuma eficient carburant.";
	}
	void afisare();


	int operator+(int x)
	{
		return this->capacitate_cilindrica + x;
	}

	int operator-(int x)
	{
		return this->capacitate_cilindrica - x;
	}

	int operator*=(int x)
	{
		return this->viteza_maxima *= x;
	}

	int& operator[](int poz)
	{
		if (poz == 0 || poz == 1)
			return consum_viteza_med[poz];
		else throw "Index out of bounds";
	}

	void scriereBinar(char* numeFis)
	{
		ofstream f(numeFis, ios::binary | ios::app);
		f.write((char*)nume, sizeof(strlen(nume)));
		f.write((char*)motor, sizeof(strlen(motor)));
		f.write((char*)&viteza_maxima, sizeof(int));
		f.write((char*)&capacitate_cilindrica, sizeof(int));
		f.write((char*)&consum_viteza_med_urban[0], sizeof(int));
		f.write((char*)&consum_viteza_med_urban[1], sizeof(int));
		f.write((char*)&consum_viteza_med[0], sizeof(int));
		f.write((char*)&consum_viteza_med[1], sizeof(int));
		f.close();
	}

	void citireBinar(char* numeFis)
	{
		ifstream f(numeFis, ios::binary | ios::cur);
		f.read((char*)nume, sizeof(strlen(nume)));
		f.read((char*)motor, sizeof(strlen(motor)));
		f.read((char*)&viteza_maxima, sizeof(int));
		f.read((char*)&capacitate_cilindrica, sizeof(int));
		f.read((char*)&consum_viteza_med_urban[0], sizeof(int));
		f.read((char*)&consum_viteza_med_urban[1], sizeof(int));
		f.read((char*)&consum_viteza_med[0], sizeof(int));
		f.read((char*)&consum_viteza_med[1], sizeof(int));
	}

};
int Autoturism::nr_autoturisme = 0;

void Autoturism::afisare()
{
	cout << "Id unic:" << get_id() << endl;
	cout << "Numele autoturismului: " << get_nume() << endl;
	cout << "Motorul: " << get_motor() << endl;
	cout << "Viteza maxima: " << get_viteza_max() << endl;
	cout << "Capacitate Cilindrica: " << get_cap_cilindrica() << endl;
	cout << "Consumul mediu urban: " << get_consum_viteza_med_urban()[0] << endl;
	cout << "Viteza medie urban: " << get_consum_viteza_med_urban()[1] << endl;
	cout << "Consum mediu: " << get_consum_viteza_med()[0] << endl;
	cout << "Viteza medie: " << get_consum_viteza_med()[1] << endl;
	cout << "Nr de autoturisme: " << nr_autoturisme << endl;
}

istream& operator>>(istream& intrare, Autoturism &a) //fara id
{
	char aux[20];
	cout << endl << "Numele autoturismului: ";
	if (a.nume != NULL)
	{
		delete[] a.nume;
	}
	intrare >> aux;
	a.nume = new char[strlen(aux) + 1];
	strcpy(a.nume, aux);
	cout << "Motor: ";
	delete[] a.motor;
	intrare >> aux;
	a.motor = new char[strlen(aux) + 1];
	strcpy(a.motor, aux);
	cout << "Viteza maxima: ";
	intrare >> a.viteza_maxima;
	cout << "Capacitate cilindrica: ";
	intrare >> a.capacitate_cilindrica;
	cout << "Consumul mediu urban: ";
	intrare >> a.consum_viteza_med_urban[0];
	cout << "Viteza medie urban: ";
	intrare >> a.consum_viteza_med_urban[1];
	cout << "Consum mediu: ";
	intrare >> a.consum_viteza_med[0];
	cout << "Viteza medie: ";
	intrare >> a.consum_viteza_med[1];
	return intrare;
}
ostream& operator<<(ostream& iesire, Autoturism a)
{
	iesire << "Id unic:" << a.id << endl;
	iesire << "Numele autoturismului: " << a.nume << endl;
	iesire << "Motorul: " << a.motor << endl;
	iesire << "Viteza maxima: " << a.viteza_maxima << endl;
	iesire << "Capacitate Cilindrica: " << a.capacitate_cilindrica << endl;
	iesire << "Consumul mediu urban: " << a.consum_viteza_med_urban[0] << endl;
	iesire << "Viteza medie urban: " << a.consum_viteza_med_urban[1] << endl;
	iesire << "Consum mediu: " << a.consum_viteza_med[0] << endl;
	iesire << "Viteza medie: " << a.consum_viteza_med[1] << endl;
	return iesire;
}
ifstream& operator>>(ifstream& intrare, Autoturism &a)
{
	char aux[20];
	intrare >> aux;
	delete[] a.nume;
	a.nume = new char[strlen(aux) + 1];
	strcpy(a.nume, aux);
	intrare >> aux;
	delete[] a.motor;
	a.motor = new char[strlen(aux) + 1];
	strcpy(a.motor, aux);
	intrare >> a.viteza_maxima;
	intrare >> a.capacitate_cilindrica;
	intrare >> a.consum_viteza_med_urban[0];
	intrare >> a.consum_viteza_med_urban[1];
	intrare >> a.consum_viteza_med[0];
	intrare >> a.consum_viteza_med[1];

	return intrare;
}

class Coordonate{
private:
	float latitudine;
	float longitudine;

public:
	float get_longitudine()
	{
		return longitudine;
	}
	float get_latitudine()
	{
		return latitudine;
	}

	void set_longitudine(float longitudine)
	{
		if (longitudine > -180 && longitudine <180)
			this->longitudine = longitudine;
	}
	void set_latitudine(float latitudine)
	{
		if (latitudine>-90 && latitudine < 90)
			this->latitudine = latitudine;
	}

	Coordonate()
	{
		longitudine = 52.51523649714909;
		latitudine = 13.18586926568004;
	}
	Coordonate(float latitudine)
	{
		this->latitudine = latitudine;
		longitudine = NULL;
	}

	Coordonate(float latitudine, float longitudine)
	{
		this->latitudine = latitudine;
		this->longitudine = longitudine;
	}
	Coordonate(Coordonate &b)
	{
		this->latitudine = b.latitudine;
		this->longitudine = b.longitudine;
	}
	Coordonate operator=(Coordonate b)
	{
		this->latitudine = b.latitudine;
		this->longitudine = b.longitudine;
		return *this;
	}

	friend istream& operator>>(istream& intrare, Coordonate	&c);
	friend ostream& operator<<(ostream& iesire, Coordonate c);
	friend ifstream& operator>>(ifstream& intrare, Coordonate&c);
	friend ofstream& operator<<(ofstream& out, Coordonate c)
	{
		out << setprecision(14) << c.latitudine << endl;
		out << setprecision(14) << c.longitudine << endl;
		return out;
	}


	void lat()
	{
		latitudine = latitudine + 0.001;
	}
	void afis()
	{
		cout << "latitudine: " << latitudine;
		cout << " si longitudine: " << longitudine <<

			endl;
	}

	Coordonate operator++()
	{
		this->longitudine += 1;
		return *this;
	}

	Coordonate operator++(int)
	{
		Coordonate x = *this;
		this->longitudine += 1;
		return x;
	}

	Coordonate operator--()
	{
		this->latitudine += 1;
		return *this;
	}

	Coordonate operator--(int)
	{
		Coordonate x = *this;
		this->latitudine += 1;
		return x;
	}
	bool operator==(Coordonate temp)
	{
		bool egali = true;
		if (this->longitudine != temp.longitudine)
			egali = false;
		if (this->latitudine != temp.latitudine)
			egali = false;
		return egali;
	}
};

istream& operator>>(istream& intrare, Coordonate &c)
{
	cout << endl;
	cout << "latitudine: ";
	intrare >> c.latitudine;
	cout << "longitudine: ";
	intrare >> c.longitudine;
	return intrare;
}
ostream& operator<<(ostream& iesire, Coordonate c)
{
	iesire << setprecision(14) << endl << c.latitudine << endl;
	iesire << setprecision(14) << c.longitudine << endl;
	return iesire;
}
ifstream& operator>>(ifstream& intrare, Coordonate &c)
{

	intrare >> c.latitudine;
	intrare >> c.longitudine;
	return intrare;
}

class Gps{
private:
	char* nume;
	long long timp;
	int viteza;
	Coordonate c;

public:

	char* get_nume()
	{
		return nume;
	}
	long long get_timp()
	{
		return timp;
	}
	int get_viteza()
	{
		return viteza;
	}
	Coordonate get_c()
	{
		return c;
	}

	void set_nume(char* nume)
	{
		if (this->nume != NULL)
			delete[]this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	void set_timp(long long timp)
	{
		if (timp>-7200000)
			this->timp = timp;
	}
	void set_viteza(int viteza)
	{
		if (viteza > 20 && viteza < 400)
			this->viteza = viteza;
	}
	void set_Coordonate(float latitudine, float longitudine)
	{
		if (latitudine>-90 && latitudine < 90)
			c.set_latitudine(latitudine);
		if (longitudine>-180 && longitudine < 180)
			c.set_longitudine(longitudine);
	}

	Gps()
	{
		nume = new char[strlen("auto1") + 1];
		strcpy(nume, "auto1");
		timp = 1439467747492;
		viteza = 100;
		c.set_latitudine(52.513860835568);
		c.set_longitudine(13.192917916887316);
	}
	Gps(char*nume){
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		timp = NULL;
		viteza = NULL;
		c.set_latitudine(0);
		c.set_longitudine(0);
	}
	Gps(char *nume, long long timp, int viteza, Coordonate d)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->timp = timp;
		this->viteza = viteza;
		c = d;
	}
	Gps(Gps &a)
	{
		this->nume = new char[strlen(a.nume) + 1];
		strcpy(this->nume, a.nume);
		this->timp = a.timp;
		this->viteza = a.viteza;
		c = a.c;
	}

	~Gps()
	{
		delete[] this->nume;
	}

	Gps operator=(Gps a)
	{
		delete[] this->nume;
		this->nume = new char[strlen(a.nume) + 1];
		strcpy(this->nume, a.nume);
		this->timp = a.timp;
		this->viteza = a.viteza;
		c = a.c;
		return *this;
	}

	friend istream& operator>>(istream& intrare, Gps &x);
	friend ostream& operator<<(ostream& iesire, Gps x);
	friend ifstream& operator>>(ifstream& intrare, Gps &x);
	friend ofstream& operator<<(ofstream& iesire, Gps a)
	{
		iesire << a.nume << endl;
		iesire << a.timp << endl;
		iesire << a.viteza << endl;
		iesire << a.c << endl;
		return iesire;
	}
	void afisare()
	{
		cout << "Numele autoturismului: " << nume << endl;
		cout << "Date despre locatia curenta: " << endl;
		cout << "Timp: " << timp << endl;
		cout << "Viteza: " << viteza << endl;
		cout << "Cordoonate geografice: " << endl;
		cout << "latitudine si longitudine: " << c << endl;
	}

	void conversieUTC(int *t)
	{
		timp = timp / 1000;

		tm *utc = localtime(&timp);
		t[1] = 1900 + utc->tm_year;
		t[2] = 1 + utc->tm_mon;
		t[3] = utc->tm_mday;
		t[4] = -3 + utc->tm_hour;
		t[5] = utc->tm_min;
		t[6] = utc->tm_sec;

	}

	int operator+=(int x)
	{
		return this->viteza += x;
	}
	int operator-=(int x)
	{
		return this->viteza -= x;
	}

	operator long long()
	{
		return this->timp;
	}

	void scrieBinar(char* numeFis)
	{
		ofstream f(numeFis);
		f.write(nume, sizeof(strlen(nume)));
		f.write((char*)&timp, sizeof(long long));
		f.write((char*)&viteza, sizeof(int));
		float x;
		f.write((char*)&x, sizeof(float));
		c.set_latitudine(x);
		f.write((char*)&x, sizeof(float));
		c.set_longitudine(x);
		f.close();
	}

	void citireBinar(char* numeFis)
	{
		ifstream f(numeFis);
		f.read(nume, sizeof(strlen(nume)));
		f.read((char*)&timp, sizeof(long long));
		f.read((char*)&viteza, sizeof(int));
		float x;
		x = c.get_latitudine();
		f.read((char*)&x, sizeof(float));
		x = c.get_longitudine();
		f.read((char*)&x, sizeof(float));
		f.close();
	}
};

istream& operator>>(istream& intrare, Gps &a)
{
	char aux[20];
	cout << "Numele autoturismului: ";
	delete[] a.nume;
	intrare >> aux;
	a.nume = new char[strlen(aux) + 1];
	strcpy(a.nume, aux);
	cout << "Date despre locatia curenta: " << endl;
	cout << "Timp: ";
	intrare >> a.timp;
	cout << "Viteza: ";
	intrare >> a.viteza;
	cout << "Coordonate geografice: ";
	intrare >> a.c;
	return intrare;
}
ostream& operator<<(ostream& iesire, Gps a){
	iesire << "Numele autoturismului: " << a.nume << endl;
	iesire << "Date despre locatia curenta: " << endl;
	iesire << "Timp: " << a.timp << endl;
	iesire << "Viteza: " << a.viteza << endl;
	iesire << "Cordoonate geografice: " << endl;
	iesire << a.c;
	return iesire;
}
ifstream& operator>>(ifstream& intrare, Gps &a)
{
	char aux[20];
	intrare >> aux;
	delete[] a.nume;
	a.nume = new char[strlen(aux) + 1];
	strcpy(a.nume, aux);
	intrare >> a.timp;
	intrare >> a.c;
	intrare >> a.viteza;
	return intrare;
}

class Cerc
{
private:
	char* restrictie;
	int raza;
	Coordonate loc;

public:
	char* get_restrictie()
	{
		return restrictie;
	}
	int get_raza()
	{
		return raza;
	}
	Coordonate get_loc()
	{
		return loc;
	}

	void set_restrictie(char* restrictie)
	{
		if (this->restrictie != NULL)
			delete[] this->restrictie;
		this->restrictie = new char[strlen(restrictie) + 1];
		strcpy(this->restrictie, restrictie);
	}
	void set_raza(int raza)
	{
		if (raza > 0 && raza < 150)
			this->raza = raza;
	}
	void set_loc(float lat, float longi)
	{
		if (lat>-90 && lat < 90)
			loc.set_latitudine(lat);
		if (longi>-180 && longi < 180)
			loc.set_longitudine(longi);

	}

	Cerc()
	{
		restrictie = new char[strlen("Rosu") + 1];
		strcpy(restrictie, "Rosu");
		raza = 50;
		loc.set_latitudine(52.51501662980105);
		loc.set_longitudine(13.187152644890508);

	}
	Cerc(char *restrictie, int raza, Coordonate c)
	{
		this->restrictie = new char[strlen(restrictie) + 1];
		strcpy(this->restrictie, restrictie);
		this->raza = raza;
		loc = c;
	}
	Cerc(char* restrictie, Coordonate c)
	{
		this->restrictie = new char[strlen(restrictie) + 1];
		strcpy(this->restrictie, restrictie);
		this->raza = NULL;
		loc = c;
	}
	Cerc(Cerc &d)
	{
		this->restrictie = new char[strlen(d.restrictie) + 1];
		strcpy(this->restrictie, d.restrictie);
		this->raza = d.raza;
		loc = d.loc;
	}

	Cerc operator=(Cerc d)
	{
		delete[] this->restrictie;
		this->restrictie = new char[strlen(d.restrictie) + 1];
		strcpy(this->restrictie, d.restrictie);
		this->raza = d.raza;
		loc = d.loc;
		return *this;
	}

	~Cerc()
	{
		delete[] this->restrictie;
	}

	friend istream& operator>>(istream& citire, Cerc &z);
	friend ostream& operator<<(ostream& afisare, Cerc z);
	friend ifstream& operator>>(ifstream& citire, Cerc &z);
	friend ofstream& operator<<(ofstream& afisare, Cerc z)
	{
		afisare << z.restrictie << endl;
		afisare << z.raza << endl;
		afisare << z.loc << endl;
		return afisare;
	}

	float consum_parcurgere(int raza, Autoturism a)
		//functia verifica cat ar consuma in medie masina daca ar parcurge intreg spatiul de tip cerc
	{
		float consum, aria;
		aria = 3.14159*raza*raza;
		consum = a.get_consum_viteza_med()[0] * aria;
		return consum;

	}



	void citireBinar(char* numeFis)
	{
		ifstream f(numeFis);
		f.read((char*)restrictie, sizeof(strlen(restrictie)));
		f.read((char*)&raza, sizeof(int));
		float x;
		f.read((char*)&x, sizeof(float));
		loc.set_latitudine(x);
		f.read((char*)&x, sizeof(float));
		loc.set_longitudine(x);
		f.close();
	}

	void scrieBinar(char* numeFis)
	{
		ofstream f(numeFis);
		f.write((char*)restrictie, sizeof(strlen(restrictie)));
		f.write((char*)&raza, sizeof(int));
		float x;
		x = loc.get_latitudine();
		f.write((char*)&x, sizeof(float));
		x = loc.get_longitudine();
		f.write((char*)&x, sizeof(float));
		f.close();
	}

	void afisare()
	{
		cout << "Tipul restrictiei: " << restrictie << endl;
		cout << "Raza: " << raza << endl;
		cout << "Coordonatele geografice: " << loc << endl;
	}
	void operator*(int x)
	{
		this->raza *= x;
	}
	void operator/(int x)
	{
		this->raza /= x;
	}
};

istream& operator>>(istream& citire, Cerc &z)
{
	char aux[25];
	cout << "Tipul restrictiei: ";
	delete[] z.restrictie;
	citire >> aux;
	z.restrictie = new char[strlen(aux) + 1];
	strcpy(z.restrictie, aux);
	cout << "Raza: ";
	citire >> z.raza;
	cout << "Coordonate geografice:";
	citire >> z.loc;
	return citire;
}
ostream& operator<<(ostream& afisare, Cerc z)
{
	afisare << "Cerc" << endl;
	afisare << "Tipul restrictiei: " << z.restrictie << endl;
	afisare << "Raza: " << z.raza << endl;
	afisare << "Coordonatele geografice: " << z.loc << endl;
	return afisare;
}

ifstream& operator>>(ifstream& citire, Cerc &z)
{
	char aux[25];
	citire >> aux;
	if (z.restrictie != NULL)
		delete[] z.restrictie;
	z.restrictie = new char[strlen(aux) + 1];
	strcpy(z.restrictie, aux);
	citire >> z.loc;
	citire >> z.raza;

	return citire;
}

class DreptunghiComplet;
class Dreptunghi{
private:
	char* restrictie;
	Coordonate colt_sus_stanga;
	Coordonate colt_jos_dreapta;

public:
	char* get_restrictie()
	{
		return restrictie;
	}

	Coordonate get_stanga()
	{
		return colt_sus_stanga;
	}
	Coordonate get_dreapta()
	{
		return colt_jos_dreapta;
	}

	void set_restrictie(char* restrictie)
	{
		if (this->restrictie != NULL)
			delete[] this->restrictie;
		this->restrictie = new char[strlen(restrictie) + 1];
		strcpy(this->restrictie, restrictie);
	}

	void set_stanga(float lo, float la)
	{
		if (la>-90 && la < 90)
			colt_sus_stanga.set_latitudine(la);
		if (lo>-180 && lo< 180)
			colt_sus_stanga.set_longitudine(lo);

	}
	void set_dreapta(float lo, float la)
	{
		if (la>-90 && la < 90)
			colt_jos_dreapta.set_latitudine(la);
		if (lo>-180 && lo< 180)
			colt_jos_dreapta.set_longitudine(lo);

	}

	Dreptunghi()
	{
		restrictie = new char[strlen("verde") + 1];
		strcpy(restrictie, "verde");
		colt_sus_stanga.set_latitudine(13.19163543303047);
		colt_sus_stanga.set_longitudine(52.514118332436404);
		colt_jos_dreapta.set_latitudine(13.193559756034373);
		colt_jos_dreapta.set_longitudine(52.51373807944698);
	}
	Dreptunghi(char* restrictie)
	{
		this->restrictie = new char[strlen(restrictie) + 1];
		strcpy(this->restrictie, restrictie);
		colt_sus_stanga.set_latitudine(NULL);
		colt_sus_stanga.set_longitudine(NULL);
		colt_jos_dreapta.set_latitudine(NULL);
		colt_jos_dreapta.set_longitudine(NULL);
	}
	Dreptunghi(char* restrictie, Coordonate stanga, Coordonate dreapta)
	{
		this->restrictie = new char[strlen(restrictie) + 1];
		strcpy(this->restrictie, restrictie);
		colt_sus_stanga = stanga;
		colt_jos_dreapta = dreapta;
	}
	Dreptunghi(Dreptunghi &d)
	{
		this->restrictie = new char[strlen(d.restrictie) + 1];
		strcpy(this->restrictie, d.restrictie);
		this->colt_sus_stanga = d.colt_sus_stanga;
		this->colt_jos_dreapta = d.colt_jos_dreapta;
	}

	Dreptunghi operator=(Dreptunghi d)
	{
		delete[] this->restrictie;
		this->restrictie = new char[strlen(d.restrictie) + 1];
		strcpy(this->restrictie, d.restrictie);
		colt_sus_stanga = d.colt_sus_stanga;
		colt_jos_dreapta = d.colt_jos_dreapta;
		return *this;
	}

	~Dreptunghi()
	{
		delete[] this->restrictie;
	}
	friend ostream& operator<<(ostream& out, DreptunghiComplet& dr);
	friend istream& operator>>(istream& in, DreptunghiComplet& dr);
	friend istream& operator>>(istream& citire, Dreptunghi &x);
	friend ostream& operator<<(ostream& afisare, Dreptunghi x);
	friend ifstream& operator>>(ifstream& citire, Dreptunghi &x);
	friend ifstream& operator>>(ifstream& in, DreptunghiComplet& dr);
	friend ofstream& operator<<(ofstream& afisare, Dreptunghi x)
	{
		afisare << "Tipul restrictiei: " << x.restrictie << endl;
		afisare << "Coltul stanga sus: " << x.colt_sus_stanga << endl;
		afisare << "Coltul dreapta jos:" << x.colt_jos_dreapta << endl;
		return afisare;
	}
	void afisare()
	{
		cout << "Tipul restrictiei: " << restrictie << endl;
		cout << "Coltul stanga sus: " << colt_sus_stanga;
		cout << "Coltul dreapta jos:" << colt_jos_dreapta;

	}

	float distanta_colturi()
		//functia verifica care e distanta dintre coordonatele din stanga sus fata de cele din dreapta jos.
	{
		float distanta = sqrt((colt_sus_stanga.get_latitudine() - colt_jos_dreapta.get_latitudine())*(colt_sus_stanga.get_latitudine() - colt_jos_dreapta.get_latitudine()) + (colt_sus_stanga.get_longitudine() - colt_jos_dreapta.get_longitudine())*(colt_sus_stanga.get_longitudine() - colt_jos_dreapta.get_longitudine()))*10000;
		return distanta;
	}



	void citireBinar(char* numeFis)
	{
		ifstream f(numeFis);
		f.read((char*)restrictie, sizeof(strlen(restrictie)));
		float x;
		f.read((char*)&x, sizeof(float));
		colt_sus_stanga.set_latitudine(x);
		f.read((char*)&x, sizeof(float));
		colt_sus_stanga.set_longitudine(x);
		f.read((char*)&x, sizeof(float));
		colt_jos_dreapta.set_latitudine(x);
		f.read((char*)&x, sizeof(float));
		colt_jos_dreapta.set_longitudine(x);
		f.close();
	}

	void scrieBinar(char* numeFis)
	{
		ofstream f(numeFis);
		f.write((char*)restrictie, sizeof(strlen(restrictie)));
		float x;
		x = colt_sus_stanga.get_latitudine();
		f.write((char*)&x, sizeof(float));
		x = colt_sus_stanga.get_longitudine();
		f.write((char*)&x, sizeof(float));
		x = colt_jos_dreapta.get_latitudine();
		f.write((char*)&x, sizeof(float));
		x = colt_jos_dreapta.get_longitudine();
		f.write((char*)&x, sizeof(float));
		f.close();
	}

};

istream& operator>>(istream& citire, Dreptunghi &x)
{
	cout << "Tipul restrictiei: ";
	delete[] x.restrictie;
	char aux[20];
	citire >> aux;
	x.restrictie = new char[strlen(aux) + 1];
	strcpy(x.restrictie, aux);
	cout << "Coordonate colt stanga sus: ";
	citire >> x.colt_sus_stanga;
	cout << "Coordonate colt dreapta jos: ";
	citire >> x.colt_jos_dreapta;
	return citire;
}
ostream& operator<<(ostream& afisare, Dreptunghi x)
{
	afisare << "Tipul restrictiei: " << x.restrictie << endl;
	afisare << "Coltul stanga sus: " << endl << x.colt_sus_stanga;
	afisare << "Coltul dreapta jos:" << endl << x.colt_jos_dreapta << endl;
	return afisare;
}

ifstream& operator>>(ifstream& citire, Dreptunghi &x)
{
	char aux[25];
	citire >> aux;
	delete[] x.restrictie;
	x.restrictie = new char[strlen(aux) + 1];
	strcpy(x.restrictie, aux);
	citire >> x.colt_sus_stanga;
	citire >> x.colt_jos_dreapta;
	return citire;
}

class DreptunghiComplet : public Dreptunghi
{
private:
	Coordonate colt_jos_stanga;
	Coordonate colt_sus_dreapta;
public:
	Coordonate get_stanga2()
	{
		return colt_jos_stanga;
	}
	Coordonate get_dreapta2()
	{
		return colt_sus_dreapta;
	}
	DreptunghiComplet() :Dreptunghi()
	{
		colt_jos_stanga.set_latitudine(52.514118332436404);
		colt_jos_stanga.set_longitudine(13.19163543303047);
		colt_sus_dreapta.set_latitudine(52.514118332436404);
		colt_sus_dreapta.set_longitudine(13.193559756034373);
	}
	DreptunghiComplet(Coordonate stanga_jos, Coordonate dreapta_sus,
		char* restrictie, Coordonate stanga, Coordonate dreapta)
		:Dreptunghi(restrictie, stanga, dreapta)
	{
		colt_jos_stanga = stanga_jos;
		colt_sus_dreapta = dreapta_sus;
	}

	DreptunghiComplet(DreptunghiComplet& d) : Dreptunghi(d)
	{
		colt_jos_stanga = d.colt_jos_stanga;
		colt_sus_dreapta = d.colt_sus_dreapta;
	}

	DreptunghiComplet operator=(DreptunghiComplet d)
	{
		Dreptunghi::operator=(d);
		colt_jos_stanga = d.colt_jos_stanga;
		colt_sus_dreapta = d.colt_sus_dreapta;
		return *this;
	}

	~DreptunghiComplet()
	{

	}

	friend istream& operator>>(istream& in, DreptunghiComplet& dr)
	{
		cout << "Restrictia: ";
		in >> dr.restrictie;
		cout << "Datele: " << endl;
		in >> dr.colt_jos_dreapta;
		in >> dr.colt_sus_stanga;
		dr.colt_jos_stanga.set_latitudine(dr.get_stanga().get_latitudine());
		dr.colt_jos_stanga.set_longitudine(dr.get_dreapta().get_longitudine() + 0.0002);
		dr.colt_sus_dreapta.set_latitudine(dr.get_stanga().get_latitudine());
		dr.colt_sus_dreapta.set_longitudine(dr.get_dreapta().get_longitudine() + 0.000001);
		return in;
	}

	friend ifstream& operator>>(ifstream& in, DreptunghiComplet& dr)
	{
		in >> dr.restrictie;
		in >> dr.colt_jos_dreapta;
		in >> dr.colt_sus_stanga;
		dr.colt_jos_stanga.set_latitudine(dr.get_stanga().get_latitudine());
		dr.colt_jos_stanga.set_longitudine(dr.get_dreapta().get_longitudine() + 0.0002);
		dr.colt_sus_dreapta.set_latitudine(dr.get_stanga().get_latitudine());
		dr.colt_sus_dreapta.set_longitudine(dr.get_dreapta().get_longitudine() + 0.000001);
		return in;
	}

	friend ostream& operator<<(ostream& out, DreptunghiComplet& dr)
	{
		out << "Dreptunghi" << endl;
		out << "Colt dreapta jos: " << dr.colt_jos_dreapta;
		out << "Colt jos stanga: " << dr.colt_jos_stanga;
		out << "Colt sus stanga: " << dr.colt_sus_stanga;
		out << "Colt sus dreapta: " << dr.colt_sus_dreapta;
		return out;
	}
};

void main()
{
	Autoturism autot[3];
	Gps *gps;
	Cerc crc[3];
	DreptunghiComplet::Dreptunghi drp[3];
	DreptunghiComplet drpc[3];
	gps = new Gps[65465];

	ifstream masina("auto.txt");
	for (int i = 0; i < 3; i++)
	{
		masina >> autot[i];
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "Date despre auto " << i + 1 << endl;
		cout << autot[i] << endl;
	}
	int x;
	cout << "Doriti ca datele despre autoturisme sa fie salvate in fisiere? " << endl << "Tastati 1-pentru DA si 0-pentru NU ";
	cin >> x;
	if (x == 1)
	{
		cout << "Profilul carui autoturism doriti sa fie salvat? " << endl;
		cout << "1) auto1" << endl;
		cout << "2) auto2" << endl;
		cout << "3) auto3" << endl;
		cout << "4) toate" << endl;
		cin >> x;
		if (x == 1)
		{
			ofstream auto1("auto1.txt");
			auto1 << autot[0];
			autot[0].scriereBinar("auto1.bin");
		}
		if (x == 2)
		{
			ofstream auto2("auto2.txt");
			auto2 << autot[1];
			autot[1].scriereBinar("auto2.bin");
		}
		if (x == 3)
		{
			ofstream auto3("auto3.txt");
			auto3 << autot[2];
			autot[2].scriereBinar("auto3.bin");
		}
		if (x == 4)
		{
			ofstream auto1("auto1.txt");
			auto1 << autot[0];
			autot[0].scriereBinar("auto1.bin");
			ofstream auto2("auto2.txt");
			auto2 << autot[1];
			autot[1].scriereBinar("auto2.bin");
			ofstream auto3("auto3.txt");
			auto3 << autot[2];
			autot[2].scriereBinar("auto3.bin");

		}
	}

	ifstream gpsf("telematics.txt");
	for (int i = 0; i < 65465; i++)
	{
		gpsf >> gps[i];
	}

	cout << endl << endl << "Afisare elemente din fisierul geofence:" << endl << endl;
	ifstream geof("geofence.txt");

	char aux[10];
	int i = 1;
	int j = 1;
	while (!geof.eof())
	{
		geof >> aux;
		if (strcmp(aux, "circle") == 0)
		{
			geof >> crc[i];
			cout << i << ". " << crc[i] << endl;
			i++;
		}
		else
		{
			geof >> drpc[j];
			cout << j << ". " << drpc[j] << endl;
			j++;
		}
	}

	cout << endl <<"Verificare daca autoturismele au patruns in spatiile din Geofence"<<endl<< endl;
	//VERIFICARE DACA PRIMA ZONA DE TIP CERC 1 A FOST STRABATUTA
	int k = 0;
	int nr = 0;
	while (k < 65465)
	{
		if (gps[k].get_c() == crc[1].get_loc())
		{
			cout << "Masina " << gps[k].get_nume() << " a fost in zona 1 de tip cerc la ";
			nr++;
			int timpp[7];
			gps[k].conversieUTC(timpp);
			cout << "data: " << timpp[3] << "-" << timpp[2] << "-" << timpp[1] << " ";
			cout << "ora:  " << timpp[4] << ":" << timpp[5] << ":" << timpp[6] << endl;
			cout << "Iar automobilul avea viteza: " << gps[k].get_viteza();
			if (gps[k].get_viteza() > 120)
			{
				gps[k] -= 20;
				cout << endl << "Automobilul are viteza prea mare pt a ca masina sa consume eficient carburant." << endl << "Incercati sa reduceti viteza pana la: " << gps[k].get_viteza() << endl;
			}
			else if (gps[k].get_viteza() < 70)
			{
				gps[k] += 20;
				cout << endl << "Automobilul are viteza prea mica pt a ca masina sa consume eficient carburant." << endl << "Incercati sa cresteti viteza pana la: " << gps[k].get_viteza() << endl;
			}
			else cout << "Parcurgerea e GreenDriving." << endl;
			

		}
		k++;
	}
	if (nr == 0)
		cout << "zona 1 de tip cerc nu a fost strabatuta de niciun autotursim.";


	//VERIFICARE DACA PRIMA ZONA DE TIP CERC 2 A FOST STRABATUTA
	int m = 0;
	int nrm = 0;
	while (m < 65465)
	{
		if (gps[m].get_c() == crc[2].get_loc())
		{
			cout << endl << "Masina " << gps[m].get_nume() << " a fost in zona 2 de tip cerc la ";
			nrm++;
			int timpp[7];
			gps[m].conversieUTC(timpp);
			cout << "data: " << timpp[3] << "-" << timpp[2] << "-" << timpp[1] << " ";
			cout << "ora:  " << timpp[4] << ":" << timpp[5] << ":" << timpp[6] << endl;
			cout << "Iar automobilul avea viteza: " << gps[m].get_viteza();
			if (gps[m].get_viteza() > 120)
			{
				gps[m] -= 20;
				cout << endl << "Automobilul are viteza prea mare pt a ca masina sa consume eficient carburant." << endl << "Incercati sa reduceti viteza pana la: " << gps[m].get_viteza() << endl;
			}
			else if (gps[m].get_viteza() < 70)
			{
				gps[m] += 20;
				cout << endl << "Automobilul are viteza prea mica pt a ca masina sa consume eficient carburant." << endl << "Incercati sa cresteti viteza pana la:" << gps[m].get_viteza() << endl;
			}
			else cout << "Parcurgerea e GreenDriving." << endl;
		}
		m++;
	}
	if (nr == 0)
		cout << "zona 2 de tip cerc nu a fost strabatuta de niciun autotursim";




	//VERIFICARE DACA ZONA DREPTUNGHI A FOST PATRUNSA
	int l = 0;
	int nrr = 0;
	while (l < 65465)
	{
		if (gps[l].get_c() == drpc[1].get_dreapta() || gps[l].get_c() == drpc[1].get_stanga() || gps[l].get_c() == drpc[1].get_stanga2() ||
			gps[l].get_c() == drpc[1].get_dreapta2())
		{
			cout << endl << "Masina " << gps[l].get_nume() << " a fost in zona 1 de tip dreptunghi la ";
			nrr++;
			int timpp[7];
			gps[l].conversieUTC(timpp);
			cout << "data: " << timpp[3] << "-" << timpp[2] << "-" << timpp[1] << " ";
			cout << "ora: " << timpp[4] << ":" << timpp[5] << ":" << timpp[6] << endl;
			cout << "Iar automobilul avea viteza: " << gps[l].get_viteza();
			if (gps[l].get_viteza() > 120)
			{
				gps[l] -= 20;
				cout << endl << "Automobilul are viteza prea mare pt a ca masina sa consume eficient carburant." << endl << "Incercati sa reduceti viteza pana la:" << gps[l].get_viteza() << endl;
			}
			else if (gps[l].get_viteza() < 70)
			{
				gps[l] += 20;
				cout << endl << "Automobilul are viteza prea mica pt a ca masina sa consume eficient carburant." << endl << " Incercati sa cresteti viteza pana la: " << gps[l].get_viteza() << endl;
			}
			else cout << endl << "Parcurgerea e GreenDriving." << endl;
			cout << "Distanta dintre colturile dreptunghiului este: " << drpc[1].distanta_colturi();
		}
		l++;
	}
	if (nrr == 0)
		cout << "zona 1 de tip dreptunghi nu a fost strabatuta de niciun autotursim";

	cout << endl;




	/*Coordonate cc;
	cout << cc++ << endl << cc-- << endl << ++cc << endl << --cc<<endl;

	long long xe;
	Gps aa;
	xe = aa;
	cout << xe;
	*/


	//Autoturism xd;
	//int a;
	//cin >> a;
	//cout << xd - a << " " << xd + a << " " <<endl;
	//xd *= a;
	//cout << xd;
	//cout << xd.get_consum_viteza_med()[1];


	/*ifstream f1("auto.txt");
	Autoturism av[3];
	int j = 0;
	while (!f1.eof())
	{
	f1 >> av[j];
	cout << av[j]<<endl;
	j++;
	f1.ignore();
	}

	ifstream f2("telematics.txt");
	Gps cv[30000];
	int i = 0;
	while (!f2.eof() && i<30000 )
	{
	f2 >> cv[i];
	i++;
	f2.ignore();
	}*/

	/*Autoturism as;
	cin >> as;
	as.scriereBinar("as.bin");
	as.citireBinar("as.bin");
	cout << as;*/

	/*Gps gp;*/
	//cin >> gp;
	//gp.scrieBinar("gp.bin");
	/*gp.citireBinar("gp.bin");
	cout << gp;*/

	//Cerc c1;
	//cin >> c1;
	//c1.scrieBinar("cerc.bin");
	//c1.citireBinar("cerc.bin");
	//cout << c1;
	//Autoturism b; 
	//b.citireBinar("fisier.bin");
	//cout << b;

	//DreptunghiComplet bc;
	//cin >> bc;
	//cout << bc;

	//{
	//	//AUTOTURISM
	//
	//	cout << "Test AUTOTURISM :" << endl << endl;
	//	Autoturism a;
	//	cout << "Test functie de afisare: (constructor fara parametri)" << endl;
	//	a.afisare();
	//
	//	int consum_viteza_med_urban[2], consum_viteza_med[2];
	//	consum_viteza_med_urban[0] = 10;
	//	consum_viteza_med_urban[1] = 60;
	//	consum_viteza_med[0] = 7;
	//	consum_viteza_med[1] = 85;
	//
	//	Autoturism b(23,"auto2", "Isuzu", 80, 1750, consum_viteza_med_urban, consum_viteza_med);
	//	cout << endl << "Test <<: (constructor cu parametri)";
	//	cout << b << endl;
	//
	//	Autoturism c;
	//	cout << endl << "Test >>:";
	//	cin >> c;
	//	cout << c;
	//
	//	cout << endl << "Test functie viteza:" << endl;
	//	cout << endl << " -pentru " << a.get_nume() << " cu viteza " << a.get_consum_viteza_med()[1] << ": ";
	//	try{
	//		a.viteza();
	//		cout << a.get_consum_viteza_med()[1];
	//	}
	//	catch (char *exceptie)
	//	{
	//		cout << endl << exceptie << endl;
	//	}
	//	cout << " -pentru " << b.get_nume() << " cu viteza " << b.get_consum_viteza_med()[1] << ": ";
	//	try{
	//		b.viteza();
	//		cout << b.get_consum_viteza_med()[1] << endl;
	//	}
	//	catch (char *exceptie)
	//	{
	//		cout << endl << exceptie << endl;
	//	}
	//
	//
	//	cout << endl << "Test construcotr de copiere:";
	//	Autoturism d(a);
	//	cout << d << endl;
	//
	//	cout << "Test operator= : ";
	//	Autoturism e = b;
	//	cout << b;
	//
	//	cout << endl << "Test getteri: " << endl;
	//	cout << endl << "Nume: " << a.get_nume() << endl << "Motor: " << a.get_motor() << endl;
	//	cout << "Viteza maxima: " << a.get_viteza_max() << endl << "Capacitate cilindrica: " << a.get_cap_cilindrica() << endl;
	//	cout << "Consum mediu urban: " << a.get_consum_viteza_med_urban()[0] << endl << "Viteza medie urban: " << a.get_consum_viteza_med_urban()[1] << endl;
	//	cout << "Consum mediu: " << a.get_consum_viteza_med()[0] << endl << "Viteza medie: " << a.get_consum_viteza_med()[1] << endl << "Nr autoturisme: " << a.get_nr_autoturisme() << endl;
	//	cout << endl << "Test setteri:";
	//	b.set_motor("Hibrid");
	//	b.set_viteza_max(150);
	//	b.set_cap_cilindrica(1550);
	//	int consum_viteza_med_urban2[2], consum_viteza_med2[2];
	//	consum_viteza_med_urban2[0] = 10;
	//	consum_viteza_med_urban2[1] = 60;
	//	consum_viteza_med2[0] = 7;
	//	consum_viteza_med2[1] = 110;
	//	b.set_consum_viteza_med_urban(consum_viteza_med_urban2);
	//	b.set_consum_viteza_med(consum_viteza_med2);
	//	cout << b;
	//
	//
	//
	//	//COORDONATE
	//
	//	cout << endl << endl << "Test COORDONATE" << endl << endl;
	//	Coordonate a2;
	//	cout << "Test functie afisare: " << endl;
	//	a2.afis();
	//	Coordonate b2(52.51443912093393, 13.19003439533035);
	//	cout << endl << "Test <<: " << endl;
	//	cout << b2;
	//	cout << endl << "Test constructor de copiere: " << endl;
	//	Coordonate c2(a2);
	//	cout << c2;
	//	cout << endl << "Test operator egal: " << endl;
	//	Coordonate d2 = b2;
	//	cout << d2;
	//	cout << endl << "Test >>: ";
	//	Coordonate e2;
	//	cin >> e2;
	//	cout << e2;
	//	cout << endl << "Test constructor cu un parametru: " << endl;
	//	Coordonate f2(56.51379945589848);
	//	cout << f2;
	//	cout << endl << "Test getteri: " << endl;
	//	cout << "latitudine " << e2.get_latitudine() << " si longitudine " << e2.get_longitudine() << endl;
	//	cout << endl << "Test setteri: " << endl;
	//	b2.set_latitudine(52.51379945589848);
	//	b2.set_longitudine(13.193559756034373);
	//	cout << b2;
	//	cout << endl << "Test functie de prelucrare : lat " << endl;
	//	b2.lat(); cout << b2.get_latitudine();
	//
	//
	//	//GPS
	//
	//	cout << endl << endl << "Test GPS" << endl;
	//	Gps a3;
	//	cout << endl << "Test functie de afisare: " << endl;
	//	a3.afisare();
	//	cout << endl << "Test <<: " << endl;
	//	Coordonate b33(52.5142469744993, 13.190995127503486);
	//	Gps b3("Cielo", 1439467755549, 130, b33);
	//	cout << b3;
	//	cout << endl << "Test >>: " << endl;
	//	Gps c3;
	//	cin >> c3;
	//	cout << endl << c3;
	//	Gps e3("Cielo");
	//	cout << endl << "Test constructor cu un parametru:" << endl;
	//	cout << e3;
	//	cout << endl << "Test constructor de copiere: " << endl;
	//	Gps d3(a3);
	//	cout << d3;
	//	cout << endl << "Test operator egal: " << endl;
	//	e3 = b3;
	//	cout << e3;
	//	cout << endl << "Test getteri: " << endl;
	//	cout << "nume: " << e3.get_nume() << " timp: " << e3.get_timp() << " viteza " << e3.get_viteza() << endl;
	//	cout << e3.get_c();
	//
	//	cout << endl << "Test setteri: " << endl;
	//	d3.set_nume("BMW"); d3.set_timp(1439467770639); d3.set_viteza(120);
	//	d3.set_Coordonate(52.513924868517165, 13.192597225086105);
	//	cout << d3;
	//	cout << endl << "Test functie de transformare timp in format UTC" << endl;
	//	int t[7];
	//	d3.conversieUTC(t);
	//	cout << d3.get_timp() << " in format UTC : " << endl;
	//	cout << "Data: " << t[3] << "-" << t[2] << "-" << t[1] << endl;
	//	cout << "Ora:  " << t[4] << ":" << t[5] << ":" << t[6] << endl;
	//
	//
	//
	//	//CERC
	//
	//	cout << endl << endl << "Test CERC" << endl;
	//	Cerc a4;
	//	cout << endl << "Test functie de afisare: " << endl;
	//	a4.afisare();
	//	cout << endl << "Test <<: " << endl;
	//	Coordonate b44(52.5142469744993, 13.190995127503486);
	//	Cerc b4("rosu", 50, b44);
	//	cout << b4;
	//
	//	cout << endl << "Test >>: " << endl;
	//	Cerc c4;
	//	cin >> c4;
	//	cout << endl << c4;
	//	Coordonate e44(52.51345964916754, 13.194834112961047);
	//	Cerc e4("Rosu", e44);
	//	cout << endl << "Test constructor cu 2 parametri: ";
	//	cout << e4;
	//	cout << endl << "Test constructor de copiere: " << endl;
	//	Cerc d4(a4);
	//	cout << d4;
	//	cout << endl << "Test operator egal: " << endl;
	//	e4 = b4;
	//	cout << e4;
	//	cout << endl << "Test getteri: " << endl;
	//	cout << "restrictie: " << e4.get_restrictie() << " raza: " << e4.get_raza() << endl;
	//	cout << e4.get_loc();
	//
	//	cout << endl << "Test setteri: " << endl;
	//	d4.set_restrictie("galben"); d4.set_raza(35);
	//	d4.set_loc(52.513924868517165, 13.192597225086105);
	//	cout << d4;
	//	cout << "Test functie consum_parcurgere: " << endl;
	//	float consum = d4.consum_parcurgere(40, a);
	//	cout << consum << endl;
	//
	//
	//
	//	//DREPTUNGHI
	//
	//	cout << endl << endl << "Test DREPTUNGHI" << endl;
	//	Dreptunghi a5;
	//	cout << endl << "Test functie de afisare: " << endl;
	//	a5.afisare();
	//	cout << endl << "Test <<: " << endl;
	//	Coordonate b55s(52.5142469744993, 13.190995127503486);
	//	Coordonate b55d(53.5142469744993, 14.190995127503486);
	//	Dreptunghi b5("rosu", b55s, b55d);
	//	cout << b5;
	//
	//	cout << endl << "Test >>: " << endl;
	//	Dreptunghi c5;
	//	cin >> c5;
	//	cout << endl << c5;
	//	cout << endl << "Test constructor cu un parametru:";
	//	Dreptunghi e5("Rosu");
	//	cout << endl << e5 << endl;
	//	cout << endl << "Test constructor de copiere: " << endl;
	//	Dreptunghi d5(a5);
	//	cout << d5;
	//	cout << endl << "Test operator egal: " << endl;
	//	e5 = b5;
	//	cout << e5;
	//	cout << endl << "Test getteri: " << endl;
	//	cout << "restrictie: " << e5.get_restrictie() << endl;
	//	cout << "Coltul stanga sus: " << e5.get_stanga();
	//	cout << "Coltul dreapta jos: " << e5.get_dreapta() << endl;
	//
	//	cout << endl << "Test setteri: " << endl;
	//	d5.set_restrictie("galben");
	//	d5.set_stanga(52.513924868517165, 13.192597225086105);
	//	d5.set_dreapta(52.511234868517165, 13.192537825086105);
	//	cout << d5;
	//	cout << endl << "Test functie distanta_colturi: " << endl;
	//	float x;
	//	x = d5.distanta_colturi();
	//	cout << x << " km" << endl;

	//Dreptunghi dr;
	////cin >> dr; 
	////dr.scrieBinar("drept.bin");
	//dr.citireBinar("drept.bin");
	//cout << dr;


	//Autoturism at[4];
	//int i = 1;
	//char x[10];
	//int y;
	//int z[2];
	//Autoturism bc, cc;
	//cin >> bc; 
	//bc.citireBinar("cit.bin");
	////bc.scriereBinar("cit.bin");
	//cout << bc;
	////cin >> cc;
	////cc.scriereBinar("cit.bin");
	////cc.scriereBinar("cit2.bin");
	//cc.citireBinar("cit.bin");
	//cout << cc;


	//ifstream g("auto.txt");
	//for (i = 1; i < 4; i++)
	//{
	//	g >> at[i];
	//	at[i].scriereBinar("auttt.bin");
	//}

	//ifstream f("autoti.bin", ios::binary);
	//for (i = 1; i <= 3; i++)
	//{
	//	f.read((char*)x, sizeof(10));
	//	at[i].set_nume(x);
	//	cout << at[i].get_nume();
	//	f.read((char*)x, sizeof(10));
	//	at[i].set_motor(x);
	//	f.read((char*)y, sizeof(int));
	//	at[i].set_viteza_max(y);
	//	f.read((char*)y, sizeof(int));
	//	at[i].set_cap_cilindrica(y);
	//	f.read((char*)y, sizeof(int));
	//	z[0] = y;
	//	f.read((char*)y, sizeof(int));
	//	z[1] = y;
	//	at[i].set_consum_viteza_med_urban(z);
	//	f.read((char*)y, sizeof(int));
	//	z[0] = y;
	//	f.read((char*)y, sizeof(int));
	//	z[1] = y;
	//	at[i].set_consum_viteza_med(z);
	//}
	//
	//for (i = 1; i < 4; i++)
	//	cout << at[i];
}