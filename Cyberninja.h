#pragma once
#include <iostream>
#include <time.h>
#include <string>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Cyberninja {
protected:
	int x, y;
	int ancho, alto;
	int dx, dy;
	int hp;
	int documentos;
	int AlmacenamientoMax;

private:
	bool EsVisibleElDocumento;

public:
	Cyberninja() {
		this->x = 50;
		this->y = 35;
		this->dx = 2;
		this->dy = 2;
		this->ancho = 8;
		this->alto = 2;
		this->hp = 5;
		documentos = 0;
		AlmacenamientoMax = 5;
		EsVisibleElDocumento = true;
	}

	~Cyberninja() {}

	int getY() {
		return this->y;
	}

	int getX() {
		return this->x;
	}

	int getDocumento() {
		return this->documentos;
	}

	int getAlmacenamientoMax() {
		return this->AlmacenamientoMax;
	}

	int getHp() {
		return hp;
	}

	void setHp(int hp) {
		this->hp = hp;
	}

	void setDocumento(int muestras) {
		this->documentos = muestras;
	}

	void setEsVisibleElDocumento(bool EsVisibleElDocumento) {
		this->EsVisibleElDocumento = EsVisibleElDocumento;
	}

	void BorrarCyberninja() {
		Console::SetCursorPosition(x, y);     cout << "       ";
		Console::SetCursorPosition(x, y + 1); cout << "       ";
	}

	void BorrarArmaduraDelCyberninja() {
		Console::SetCursorPosition(20, 1);

		for (int i = 0; i < hp; i++)
		{

			cout << " ";
		}
	}

	void BorrarDocumento() {
		if (EsVisibleElDocumento == false)
		{
			Console::SetCursorPosition(100, 38);
			Console::ForegroundColor = ConsoleColor::DarkRed;
			cout << " " << endl;
		}
	}

	void MoverCyberninja(char tecla) {
		switch (tecla)
		{
		case 'W':
			if (y > 7)
				y -= dy;
			break;
		case 'A':
			if (x > 5)
				x -= dx;
			break;
		case 'D':
			if (x + ancho < 105)
				x += dx;
			break;
		case 'S':
			if (y + alto < 39)
				y += dy;
			break;
		}
	}

	void DibujarCyberninja() {
		DibujarArmaduraDelCyberninja();
		DibujarDocumento();
		Console::ForegroundColor = ConsoleColor::Gray;
		Console::SetCursorPosition(x, y);     cout << "   0   ";
		Console::SetCursorPosition(x, y + 1); cout << "--=O=--";
	}

	void DibujarArmaduraDelCyberninja() {
		Console::SetCursorPosition(20, 1);

		for (int i = 0; i < hp; i++)
		{
			Console::ForegroundColor = ConsoleColor::DarkRed;
			cout << char(6);
		}
	}

	void DibujarDocumento() {
		if (EsVisibleElDocumento == true)
		{
			Console::SetCursorPosition(95, 38);

			for (int i = 0; i < documentos; i++)
			{
				Console::ForegroundColor = ConsoleColor::White;
				cout << char(176);
			}
		}
	}

	Rectangle DameRectangulo() {
		return Rectangle(x, y, ancho, alto);
	}
};