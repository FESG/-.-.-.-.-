#pragma once
#include <vector>
#include <conio.h>
#include "Cyberninja.h"
#include "Documento.h"
#include "Shuriken.h"
#include "NinjaRecolector.h"

class Controlador {
private:
	Cyberninja* cyberninja;
	vector<Documento*> documentos;
	vector<Shuriken*> shurikens;
	int posiones;
	NinjaRecolector* ninja;

public:
	Controlador()
	{
		posiones = 3;
		cyberninja = new Cyberninja();
		ninja = new NinjaRecolector();
	}
	~Controlador() {}

	void AgregarDocumento()
	{
		documentos.push_back(new Documento());
	}

	void AgregarShuriken()
	{
		Shuriken* aux = new Shuriken();
		shurikens.push_back(aux);
	}

	//Borrar Mover Dibujar

	void BorrarTodo() {
		cyberninja->BorrarArmaduraDelCyberninja();
		cyberninja->BorrarCyberninja();

		for (int i = 0; i < documentos.size(); i++)
		{
			if (documentos[i]->getEsVisible() == true)
				documentos[i]->BorrarDocumento();
		}
		for (int i = 0; i < shurikens.size(); i++)
		{
			shurikens[i]->BorrarShuriken();
		}
		if (ninja->getEsVisible() == true)
		{
			ninja->BorrarNinjaRecolector();
		}
	}

	void MoverTodo() { //movimiento automatico (en donde yo no interfiero en su movimiento)
		for (int i = 0; i < shurikens.size(); i++)
		{
			shurikens[i]->MoverShuriken();
		}
		if (ninja->getEsVisible() == true)
			ninja->MoverNinjaRecolector();

	}

	void DibujarTodo() {
		cyberninja->DibujarCyberninja();

		for (int i = 0; i < documentos.size(); i++)
		{
			if (documentos[i]->getEsVisible() == true)
				documentos[i]->DibujarDocumento();
		}

		for (int i = 0; i < shurikens.size(); i++)
		{
			shurikens[i]->DibujarShuriken();
		}
		if (ninja->getEsVisible() == true)
			ninja->DibujarNinjaRecolector();
	}

	void RecogerDocumentos() {
		//Marcar
		int cont = 0; //contador temporal

		for (int i = 0; i < documentos.size(); i++) {
			if (documentos[i]->DameRectangulo().IntersectsWith(cyberninja->DameRectangulo()))
			{
				documentos[i]->setEsVisible(false);
				cont = cyberninja->getDocumento() + 1;
				cyberninja->setDocumento(cont);
			}
		}

		//Eliminar
		for (int i = 0; i < documentos.size(); i++)
		{
			if (documentos[i]->getEsVisible() == false)
				documentos.erase(documentos.begin() + i);
		}
	}

	void Colision() {
		int cont = 0;

		for (int i = 0; i < shurikens.size(); i++) {
			if (shurikens[i]->DameRectangulo().IntersectsWith(cyberninja->DameRectangulo()))
			{
				cont = cyberninja->getHp() - 1;
				cyberninja->setHp(cont);
			}
		}


		//Verificacion

		for (int i = 0; i < shurikens.size(); i++)
		{
			if (shurikens[i]->getY() > 33)
			{
				shurikens[i]->setEsVisible(false);
			}
			if (shurikens[i]->getX() > 105)
			{
				shurikens[i]->setEsVisible(false);
			}
			if (shurikens[i]->getY() < 5)
			{
				shurikens[i]->setEsVisible(false);
			}
			if (shurikens[i]->getX() < 5)
			{
				shurikens[i]->setEsVisible(false);
			}
		}


		if (cyberninja->getHp() == 0)
		{
			posiones--;
		}

		//Eliminacion

		for (int i = 0; i < shurikens.size(); i++)
		{
			if (shurikens[i]->getEsVisible() == false)
				shurikens.erase(shurikens.begin() + i);
		}


	}

	void IniciarJuego() {
		int t = 1; // tiempo en el que van a caer los meteoritos
		int contDocumentos = 0;
		int auxAlmacen;

		while (1) {
			char key;

			Console::CursorVisible = false;
			Console::ForegroundColor = ConsoleColor::DarkYellow;
			Console::SetCursorPosition(1, 1); cout << "PUNTOS DE ARMADURA";
			Console::SetCursorPosition(83, 38); cout << "DOCUMENTOS";

			BorrarTodo();

			if (cyberninja->getDocumento() == cyberninja->getAlmacenamientoMax())
			{
				ninja->setEsVisible(true);

				if (ninja->getX() > 94) {
					cyberninja->setEsVisibleElDocumento(false);
				}

				if (ninja->getX() > 105)
				{
					_sleep(300);
					break;
				}
			}

			Colision();

			if (cyberninja->getHp() == 0)
			{
				if (posiones == 0)
					break;

				auxAlmacen = cyberninja->getDocumento();

				cyberninja = new Cyberninja();

				cyberninja->setDocumento(auxAlmacen);
			}

			if (_kbhit())
			{
				key = _getch();
				key = toupper(key);
				cyberninja->MoverCyberninja(key);

				if (key == 'K')
				{
					if (cyberninja->getDocumento() != cyberninja->getAlmacenamientoMax())
					{
						RecogerDocumentos();
					}
				}
			}

			if (contDocumentos <= 4)
			{
				contDocumentos++;
				AgregarDocumento();
			}
			if (t % 5 == 0)
			{
				if (cyberninja->getDocumento() != cyberninja->getAlmacenamientoMax())
				{
					AgregarShuriken();
				}
			}

			MoverTodo();
			DibujarTodo();
			_sleep(100);
			t++;

		}
	}

};