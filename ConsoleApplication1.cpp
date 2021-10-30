// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

string space = " ";
vector<string> twentyString = {
	"", "Uno", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", 
	"Ocho", "Nueve", "Diez", "Once", "Doce", "Trece", "Catorce", "Quince", 
	"Diez y Seis", "Diez y Siete", "Diez y Ocho", "Diez y Nueve", "Veinte"
};

string twenties(int number) 
{
	return twentyString[number];
}

vector<string> overTwentis =
{
	"","","Veinte","Treinta","Cuarenta","Cincuenta","Sesenta",
	"Setenta","Ochenta","Noventa"
};

string tens(string number) {
	int numberAsInt = stoi(number);
	if (numberAsInt > 20) {
		string firstDigit = number.substr(0, 1);
		string secondDigit = number.substr(1,1);
		int firstDigitInt = stoi(firstDigit);
		int secondDigitInt = stoi(secondDigit);
		return overTwentis[firstDigitInt] + space + twenties(secondDigitInt);
	}
	return twenties(numberAsInt);
}

string hundreds(string number)
{
	int numberAsInt = stoi(number);
	int digits = number.size();
	int digitsLeft = digits - 2;

	string hundred = "Cientos";
	string quinientos = "Quinientos";
	if (numberAsInt > 100) {
		string hundredsLeft = number.substr(0, digitsLeft);
		string hundredsRight = number.substr(digitsLeft);
		if (hundredsLeft == "5")
		{
			return quinientos + space + tens(hundredsRight);
		}
		else
		{
			return tens(hundredsLeft) + space + hundred + space + tens(hundredsRight);
		}
	}
	return tens(number);
}

string thousands(string number)
{
	int numberAsInt = stoi(number);
	int digits = number.size();
	int digitsLeft = digits - 3;

	string thousands = "Mil";
	if (numberAsInt > 1000) {
		string thousandsLeft = number.substr(0, digitsLeft);
		string thousandsRight = number.substr(digitsLeft);
		return hundreds(thousandsLeft) + space + thousands + space + hundreds(thousandsRight);
	}
	return hundreds(number);
}

string million(string number)
{
	int numberAsInt = stoi(number);
	int digits = number.size();
	int digitsLeft = digits - 6;

	string million;
	
	if (numberAsInt > 1000000) {
		string thousandsLeft = number.substr(0, digitsLeft);
		string thousandsRight = number.substr(digitsLeft);
		if (thousandsLeft > "1")
		{
			million = "Millones";
		}
		else
		{
			million = "Millon";
		}
		return thousands(thousandsLeft) + space + million + space + thousands(thousandsRight);
	}

	return thousands(number);
}

void ExportarPDF(string lugarFecha, string nombre, string numero, string valor) {
	std::ofstream outfile("test.txt");
	outfile << "Lugar Y Fecha:" << lugarFecha << "\t" << "Q:" << numero << "\n";
	outfile << "Pago a la orden de:" << nombre << "\n";
	outfile << "Suma de:" << valor << "\n";
	outfile.close();
}

int main() {

	cout << "Ingrese Un Numero:";
	string numeroLetra = "";
	cin >> numeroLetra;
	string valorNumero = million(numeroLetra) + "Quetzales Exactos";
	cout << valorNumero << std::endl;
	ExportarPDF("Guatemala, 30 de Octubre 2021", "Keyler Fernando Tajtaj", numeroLetra, valorNumero);
	cout << "\n==================================================================================== = \n";
	cout << "\n  \t\t\t\tBANCO CENTRAL DE MEXICO\n  ";
	cout << "\n  Sucursal Plaza Revolucion, Mexico, D.F.\t\t\t\t\n";
	cout << "\n   \n\n\t\tPaguese este cheque a:";
	cout << "\n  Por la cantidad de:" << valorNumero;
	cout << " pesos.)\n";
	cout << "\n\n\n\t\t\t\t\t\t\t ____________________________\n";
	cout << "\t\t\t\t\t\t\t\t\tFirma\n";
	cout << "\n=====================================================================================\n";
	return 0;
}