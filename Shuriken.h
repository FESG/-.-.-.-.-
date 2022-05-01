#pragma once
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;

class Shuriken {
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
	bool EsVisible; //marcar si el Shuriken esta vivo
	int color;
	int MovimientoShuriken;

public:
	Shuriken() {
		x = 4 + rand() % 99;
		y = 4 + rand() % 28;
		dx = 1;
		dy = 1;
		ancho = 1;
		alto = 1;
		color = rand() % 6;
		EsVisible = true;
		MovimientoShuriken = 1 + rand() % 4;
	}
	~Shuriken() {}

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

	void BorrarShuriken() {
		Console::SetCursorPosition(x, y); cout << "       ";
		Console::SetCursorPosition(x, y); cout << "       ";
		Console::SetCursorPosition(x, y + 1); cout << "       ";
		Console::SetCursorPosition(x, y + 2); cout << "        ";
		Console::SetCursorPosition(x, y + 3); cout << "        ";
	}

	void MoverShuriken()
	{
		switch (MovimientoShuriken)
		{
		case 1:
			if (y < 1) //diagonal hacia abajo
			{
				dy *= -1;
			}
			y += dy;
			x += dx;
			break;

		case 2:
			if (y < 1) // hacia abajo
			{
				dy *= -1;

			}
			y += dy;
			break;

		case 3:
			if (y < 33) // hacia arriba
			{
				dy *= 1;

			}
			y -= dy;
			x += dx;
			break;

		case 4:
			if (x < 105) // hacia arriba
			{
				dx *= 1;

			}
			y += dy;
			x -= dx;
			break;

		case 5:
			if (x > 4) 
			{ 
				x -= dx; 
			}
			break;

		case 6:
			if (x > 4) { 
				x += dx; 
			}
			break;
		}
	}

	void CambiarColor() {
		color = rand() % 6;
	}

	void DibujarShuriken() {

		switch (color) {
		case 1:
			Console::ForegroundColor = ConsoleColor::DarkRed;
			break;
		case 2:
			Console::ForegroundColor = ConsoleColor::DarkYellow;
			break;
		case 3:
			Console::ForegroundColor = ConsoleColor::DarkMagenta;
			break;
		case 4:
			Console::ForegroundColor = ConsoleColor::Green;
			break;
		case 5:
			Console::ForegroundColor = ConsoleColor::DarkGray;
			break;
		}

		Console::SetCursorPosition(x, y); cout << char(207);
	}

	Rectangle DameRectangulo() {
		return Rectangle(x, y, ancho, alto);
	}
};