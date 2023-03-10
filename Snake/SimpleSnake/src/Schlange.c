/*
 * Schlange.c
 *
 *  Created on: 12.12.2022
 *      Author: student
 */
#include <stdlib.h>
#include "Configuration.h"
#include "Schlange.h"
#include "Console.h"

/*
 * Initialisiert alle Attribute
 */
void schlange_init (Schlange* schlange_ptr)
{
	schlange_ptr->positionen_ptr = liste_erzeugen();
	schlange_ptr->punkte = 0;
	schlange_ptr->wachsen = 0;
}

Schlange* schlange_erzeugen()
{
	Schlange *schlange_ptr = (Schlange*) malloc(sizeof(Schlange));
	schlange_init(schlange_ptr);
	return schlange_ptr;
}


/*
 * Funktion bewegt die Schlange in die angegebene Richtung
 * */
void schlange_bewege (Schlange* schlange_ptr, int richtung)
{
	if (schlange_ptr->wachsen == 0)
	{
		liste_einfuegen_kopf(schlange_ptr->positionen_ptr, liste_entferne_ende(schlange_ptr->positionen_ptr));

	} else {
		liste_einfuegen_kopf(schlange_ptr->positionen_ptr, element_erzeugen());
		schlange_ptr->wachsen--;
	}

	switch (richtung)
	{
		case 2: schlange_ptr->positionen_ptr->kopf_ptr->pos.x = schlange_ptr->positionen_ptr->kopf_ptr->nachfolger_ptr->pos.x;
				schlange_ptr->positionen_ptr->kopf_ptr->pos.y = schlange_ptr->positionen_ptr->kopf_ptr->nachfolger_ptr->pos.y + 1;
				break;

		case 3: schlange_ptr->positionen_ptr->kopf_ptr->pos.x = schlange_ptr->positionen_ptr->kopf_ptr->nachfolger_ptr->pos.x + 1;
				schlange_ptr->positionen_ptr->kopf_ptr->pos.y = schlange_ptr->positionen_ptr->kopf_ptr->nachfolger_ptr->pos.y;
				break;

		case 0: schlange_ptr->positionen_ptr->kopf_ptr->pos.x = schlange_ptr->positionen_ptr->kopf_ptr->nachfolger_ptr->pos.x;
				schlange_ptr->positionen_ptr->kopf_ptr->pos.y = schlange_ptr->positionen_ptr->kopf_ptr->nachfolger_ptr->pos.y - 1;
				break;

		case 1: schlange_ptr->positionen_ptr->kopf_ptr->pos.x = schlange_ptr->positionen_ptr->kopf_ptr->nachfolger_ptr->pos.x - 1;
				schlange_ptr->positionen_ptr->kopf_ptr->pos.y = schlange_ptr->positionen_ptr->kopf_ptr->nachfolger_ptr->pos.y;
				break;

		default: break;
	}
}


/*
 * Zeichnet die Schlange auf der Konsole
 */
void schlange_zeichne(Schlange* schlange_ptr, int farbe)
{
	Element *element_ptr = schlange_ptr->positionen_ptr->kopf_ptr;
	attron(COLOR_PAIR(farbe));
	while(element_ptr->nachfolger_ptr != NULL)
	{
		console_zeichne_punkt(element_ptr->pos.x, element_ptr->pos.y, ' ');
		element_ptr = element_ptr->nachfolger_ptr;
	}
}

/*
 * Die Funktion ver??ndert die Schlange in Abh??ngigkeit des eingesammelten Pickups.
 * Alles ist denkbar. Beschleunigung, Wurmloch oder ??hnliches.
 */
void schlange_bearbeite_pickup(Schlange* schlange_ptr, char pickup)
{
	//Aufgabe 3e) OPTIONAL
	//TODO
}

/*
 * Die Funktion sollte nach jeder Bewegung aufgerufen werden und zum Beispiel den
 * Punktestand in Abh??ngigkeit der L??nge der Schlange oder der Spieldauer erh??hen.
 */
void schlange_aktualisiere(Schlange* schlange_ptr)
{
	//Aufgabe 3f) OPTIONAL
	//TODO
}
