#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Documento {
private:
	int x, y;
	int ancho, alto;
	bool EsVisible; //marcar si el meteorito esta vivo

public:
	Documento() {
		x = 10 + rand() % 80;
		y = 10 + rand() % 20;
		ancho = 1;
		alto = 1;
		EsVisible = true;
	}
	~Documento() {}

	bool getEsVisible() {
		return EsVisible;
	}

	void setEsVisible(bool EsVisible) {
		this->EsVisible = EsVisible;
	}

	int getY() {
		return this->y;
	}

	void BorrarDocumento() {
		Console::SetCursorPosition(x, y);
		cout << " ";
	}

	void DibujarDocumento() {
		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(x, y); cout << char(176);
	}

	Rectangle DameRectangulo() {
		return Rectangle(x, y, ancho, alto);
	}
};