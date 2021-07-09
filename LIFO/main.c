#include <stdio.h>
#include <stdlib.h>

typedef struct lifo_stos
{
    int liczba;
    char nazwa[50];
    struct lifo_stos *next;
}lifo_stos;

//Funkcja 1
void Push(lifo_stos** stos, lifo_stos** pierwszy, lifo_stos** ostatni)
{
    char j[5];
    gets(j);
    struct lifo_stos* nowa = (struct lifo_stos*)malloc(sizeof(struct lifo_stos));
    printf("Podaj nazwe: ");
    gets(nowa->nazwa);
	printf("Podaj liczbe: ");
	scanf("%d", &nowa->liczba);
	nowa->next = NULL;
	nowa->next = *stos;
	*stos = nowa;
	if(*pierwszy == NULL)
    {
        *pierwszy = *stos;
    }
    *ostatni = *stos;
}

//Funkcja 2
void Top(lifo_stos* stos, lifo_stos* pierwszy, lifo_stos* ostatni)
{
    if(stos == NULL)
    {
         printf("Nie ma szczytu stosu\n");
    }
    else
    {
        printf("%s %d\n", ostatni->nazwa, ostatni->liczba);
    }
}

//Funkcja 3
void Pop(lifo_stos** stos, lifo_stos** pierwszy, lifo_stos** ostatni)
{
    if(*ostatni != NULL)
    {
        lifo_stos *temp = (*ostatni)->next;
        (*stos)=(*stos)->next;
        free(*ostatni);
        *ostatni = temp;
        printf("Usunieto szczyt stosu\n");
    }
    else
    {
        printf("Nie ma szczytu stosu\n");
    }

}
//Funkcja 4
void IsEmpty(lifo_stos* stos, lifo_stos* pierwszy, lifo_stos* ostatni)
{
    if(stos==NULL)
    {
        printf("stos jest pusty\n");
    }
    else
    {
        printf("stos ma elementy\n");
    }
}
//Funkcja 5
void Show(lifo_stos* stos, lifo_stos* pierwszy, lifo_stos* ostatni)
{
    lifo_stos* wsk = stos;
    if(stos == NULL)
    {
         printf("stos jest pusty\n");
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
void Clear(lifo_stos** stos, lifo_stos** pierwszy, lifo_stos** ostatni)
{
    if(*stos == NULL)
    {
        printf("stos jest juz pusty\n");
    }
    else
    {
        while((*stos) != NULL)
        {
            lifo_stos *temp = (*ostatni)->next;
            (*stos)=(*stos)->next;
            free(*ostatni);
            *ostatni = temp;
        }
        printf("Wyczyszczono stos\n");
    }

}

int main()
{
    int komenda;
    lifo_stos* pierwszy = NULL;
    lifo_stos* ostatni = NULL;
    lifo_stos* stos = NULL;
    printf("Program stosu LIFO\n");
	printf("----------------------------------------------\n");
	printf("[0] Wyjscie z programu\n");
	printf("[1] Wprowadz nowe dane do stosu\n");
	printf("[2] Wyswietl szczyt stosu\n");
	printf("[3] Usun element z poczatku stosu\n");
	printf("[4] Sprawdz czy stos jest pusty\n");
	printf("[5] Wyswietl stos\n");
	printf("[6] Wyczysc stos\n");
	printf("----------------------------------------------\n\n");

	while(1)
    {
		printf("\nWybrana komenda: ");
		scanf("%d", &komenda);
		printf("\n");
		switch (komenda)
		{
			case 0: return 0; break;
			case 1: Push(&stos, &pierwszy, &ostatni); break;
			case 2: Top(stos, pierwszy, ostatni); break;
			case 3: Pop(&stos, &pierwszy, &ostatni); break;
			case 4: IsEmpty(stos, pierwszy, ostatni); break;
			case 5: Show(stos, pierwszy, ostatni); break;
			case 6: Clear(&stos, &pierwszy, &ostatni); break;
        }
    }

    return 0;
}
//Mateusz Gajda Grupa WCY20IY2S1
