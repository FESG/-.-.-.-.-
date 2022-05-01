#pragma once
#include <iostream>
#include "Cyberninja.h"

using namespace std;
using namespace System;
using namespace System::Drawing;

class NinjaRecolector : public Cyberninja {
private:
	bool EsVisible;

public:
	NinjaRecolector() : Cyberninja() {
		x = 100;
		y = 36;
		dx = 1;
		dy = 1;
		ancho = 4;
		alto = 4;
		EsVisible = false;
	}
	~NinjaRecolector() {}

	bool getEsVisible() {
		return EsVisible;
	}

	void setEsVisible(bool EsVisible) {
		this->EsVisible = EsVisible;
	}

	int getY() {
		return this->y;
	}

	int getX() {
		return this->x;
	}

	void setY(int y) {
		this->y = y;
	}

	void setX(int x) {
		this->x = x;
	}

	void BorrarNinjaRecolector() {
		Console::SetCursorPosition(x, y); cout << "   ";
		Console::SetCursorPosition(x, y + 1); cout << "   ";
		Console::SetCursorPosition(x, y + 2); cout << "   ";
		Console::SetCursorPosition(x, y + 3); cout << "   ";
	}

	void MoverNinjaRecolector()
	{
		if (dx == 1) {
			if (x == 94) dx = -1;
			else if (x > 94 && x <= 100)
			{
				x -= dx;
			}
		}
		else {
			if(x <=110) x -= dx;
			
		}
	}

	void DibujarNinjaRecolector() {
		Console::ForegroundColor = ConsoleColor::DarkRed;

		Console::SetCursorPosition(x, y); cout << " 0  ";
		Console::SetCursorPosition(x, y + 1); cout << "-|-";
		Console::SetCursorPosition(x, y + 2); cout << " |";
		Console::SetCursorPosition(x, y + 3); cout << "| |";
	}

	Rectangle DameRectangulo() {
		return Rectangle(x, y, ancho, alto);
	}
};