#include <stdio.h>
#include <stdlib.h>

typedef struct fifo_kolejka
{
    int liczba;
    char nazwa[50];
    struct fifo_kolejka *next;
}fifo_kolejka;


//Funkcja 1
void Enqueue(fifo_kolejka** kolejka, fifo_kolejka** pierwszy, fifo_kolejka** ostatni)
{
    char j[5];
    gets(j);
    struct fifo_kolejka* nowa = (struct fifo_kolejka*)malloc(sizeof(struct fifo_kolejka));
    printf("Podaj nazwe: ");
    gets(nowa->nazwa);
	printf("Podaj liczba: ");
	scanf("%d", &nowa->liczba);
	nowa->next = NULL;
	if((*kolejka)==NULL)
     {
        *kolejka = nowa;
     }
     else
     {
        fifo_kolejka* wsk = *kolejka;
         while((wsk)->next != NULL)
         {
            wsk = wsk->next;
         }
        wsk->next = nowa;
     }
    *pierwszy = *kolejka;
    *ostatni = *kolejka;
}

//Funkcja 2
void Front(fifo_kolejka* kolejka, fifo_kolejka* pierwszy, fifo_kolejka* ostatni)
{
    if(kolejka == NULL)
    {
         printf("Nie ma elementu pierwszego\n");
    }
    else
    {
        printf("%s %d\n", pierwszy->nazwa, pierwszy->liczba);
    }
}

//Funkcja 3
void Dequeue(fifo_kolejka** kolejka, fifo_kolejka** pierwszy, fifo_kolejka** ostatni)
{
    if(*pierwszy != NULL)
    {
        fifo_kolejka *temp = (*pierwszy)->next;
        (*kolejka)=(*kolejka)->next;
        free(*pierwszy);
        *pierwszy = temp;
        printf("Usunieto element pierwszy\n");
    }
    else
    {
        printf("Nie ma elementu pierwszego\n");
    }

}
//Funkcja 4
void IsEmpty(fifo_kolejka* kolejka, fifo_kolejka* pierwszy, fifo_kolejka* ostatni)
{
    if(kolejka==NULL)
    {
        printf("kolejka jest pusta\n");
    }
    else
    {
        printf("kolejka ma elementy\n");
    }
}
//Funkcja 5
void Show(fifo_kolejka* kolejka, fifo_kolejka* pierwszy, fifo_kolejka* ostatni)
{
    fifo_kolejka* wsk = kolejka;
    if(kolejka == NULL)
    {
         printf("kolejka jest pusta\n");
    }
    else
    {
        while(wsk != NULL)
        {
            printf("%s %d\n", wsk->nazwa, wsk->liczba);
            wsk = wsk->next;
        }
    }
}
//Funkcja 6
void Clear(fifo_kolejka** kolejka, fifo_kolejka** pierwszy, fifo_kolejka** ostatni)
{
    if(*kolejka == NULL)
    {
        printf("Kolejka jest juz pusta\n");
    }
    else
    {
        while((*kolejka) != NULL)
        {
            fifo_kolejka *temp = (*pierwszy)->next;
            (*kolejka)=(*kolejka)->next;
            free(*pierwszy);
            *pierwszy = temp;
        }
        printf("Wyczyszczono kolejke\n");
    }

}

int main()
{
    int komenda;
    fifo_kolejka* pierwszy = NULL;
    fifo_kolejka* ostatni = NULL;
    fifo_kolejka* kolejka = NULL;
    printf("Program kolejki FIFO\n");
	printf("----------------------------------------------\n");
	printf("[0] Wyjscie z programu\n");
	printf("[1] Wprowadz nowe dane do kolejki\n");
	printf("[2] Wyswietl pierwszy element kolejki\n");
	printf("[3] Usun element z poczatku kolejki\n");
	printf("[4] Sprawdz czy kolejka jest pusta\n");
	printf("[5] Wyswietl kolejke\n");
	printf("[6] Wyczysc kolejke\n");
	printf("----------------------------------------------\n\n");

	while(1)
    {
		printf("\nWybrana komenda: ");
		scanf("%d", &komenda);
		printf("\n");
		switch (komenda)
		{
			case 0: return 0; break;
			case 1: Enqueue(&kolejka, &pierwszy, &ostatni); break;
			case 2: Front(kolejka, pierwszy, ostatni); break;
			case 3: Dequeue(&kolejka, &pierwszy, &ostatni); break;
			case 4: IsEmpty(kolejka, pierwszy, ostatni); break;
			case 5: Show(kolejka, pierwszy, ostatni); break;
			case 6: Clear(&kolejka, &pierwszy, &ostatni); break;
        }
    }

    return 0;
}
//Mateusz Gajda Grupa WCY20IY2S1
