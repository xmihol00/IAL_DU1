
/*
 *  Předmět: Algoritmy (IAL) - FIT VUT v Brně
 *  Základní testy pro příklad c201.c (Jednosměrně vázaný lineární seznam)
 *  Vytvořil: Martin Tuček, září 2005
 *  Úprava: Bohuslav Křena, říjen 2016
 *  Úprava: Kamil Jeřábek, září 2016
 */

#include "c201.h"
                                             /* Variables we need for testing */
tList TEMPLIST;
int ElemValue;			
int MaxListLength = 100;                     /* Handles wrongly linked lists. */

/*******************************************************************************
 * Pomocné funkce usnadňující testování vlastní implementace.
 ******************************************************************************/

void print_elements_of_list(tList TL)	{
/* Vytiskne seznam. */	
	tList TempList=TL;	
	int CurrListLength = 0;
	printf("-----------------");
	while ((TempList.First!=NULL) && (CurrListLength<MaxListLength))	{
		printf("\n\t %d",TempList.First->data);
		if ((TempList.First==TL.Act) && (TL.Act!=NULL))
			printf("\t <= toto je aktivní prvek ");
		TempList.First=TempList.First->ptr;	
		CurrListLength++;
	}
    if (CurrListLength>=MaxListLength)
        printf("\nList exceeded maximum length!");
	
	printf("\n-----------------\n");
}

int use_copy(tList *TL, int *ElemValue)	{
/* Ošetřuje použití operace Copy. */
	int tmp;	
	Copy(TL,&tmp);
	if (!solved) {
		printf("Operace Copy nebyla implementována!\n");
		return(FALSE);
	}
	else {
		if (errflg)	{
			printf("Operace Copy volala funkci Error.\n");
			errflg=FALSE;
			return(FALSE);
		}	
		else	{	 
			*ElemValue=tmp;		
			printf("Operace Copy vrací obsah %d.\n",tmp);
			return(TRUE);
		}	
	}	
}

int use_copy_first(tList *TL, int *ElemValue)	{
/* Ošetřuje použití operace CopyFirst. */
	int tmp;
	CopyFirst(TL,&tmp);
	
	if (!solved)	{
		printf("Operace CopyFirst nebyla implementována!\n");
		return(FALSE);
	}
	else {
		if (errflg)	{
			printf("Operace CopyFirst volala funkci Error.\n");
			errflg=FALSE;
			return(FALSE);
		}	
		else	{	 
			*ElemValue=tmp;			
			printf("Operace CopyFirst vrací obsah %d.\n",tmp);
			return(TRUE);
		}	
	}	
}

int use_active(tList TL)	{
/* Ošetřuje použití operace Active. */
	int IsActive = Active(&TL);
	if (!solved)	{
		printf("Operace Active nebyla implementována!\n");
		return(FALSE);
	}	
	else	{
		printf("Operace Active vrací %d.\n",IsActive);
		return(TRUE);
	}	
}	

/*
 * Následující funkce volané z vlastních testů uvedených ve funkci main
 * kontrolují, zda byly jednotlivé funkce implementovány,
 * případně vypisují aktuální stav pracovního seznamu TEMPLIST.
 */ 

int test_InitList()	{

	solved=TRUE;	
	InitList(&TEMPLIST);
	if (!solved)	{
		printf("Operace InitList nebyla implementovana \n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}	
	
}

int test_Copy()	{	
	
	solved=TRUE;
	return(use_copy(&TEMPLIST,&ElemValue));
	
}

int test_CopyFirst()	{	
	
	solved=TRUE;
	return(use_copy_first(&TEMPLIST,&ElemValue));
	
}

int test_InsertFirst()	{
	
	solved=TRUE;
	InsertFirst(&TEMPLIST,ElemValue);
	if (!solved)	{
		printf("Operace InsertFirst nebyla implementována!\n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}	
	
}

int test_First()	{
	
	solved=TRUE;
	First(&TEMPLIST);
	if (!solved)	{
		printf("Operace First nebyla implementována!\n");
		return(FALSE);
	}
	print_elements_of_list(TEMPLIST);
	return(TRUE);
	
}	

int test_Active()	{
	
	solved=TRUE;
	return(use_active(TEMPLIST));
	
}

int test_Succ()	{
	
	solved=TRUE;
	Succ(&TEMPLIST);
	if (!solved)	{
		printf("Operace Succ nebyla implementována!\n");
		return(FALSE);
	}
	print_elements_of_list(TEMPLIST);
	return(TRUE);
	
}

int test_Actualize()	{		
	
	solved=TRUE;
	Actualize(&TEMPLIST,ElemValue);
	if (!solved)	{
		printf("Operace Actualize nebyla implementována!\n");
		return(FALSE);
	}
	print_elements_of_list(TEMPLIST);
	return(TRUE);
	
}

int test_DeleteFirst()	{	
	
	solved=TRUE;
	DeleteFirst(&TEMPLIST);
	if (!solved)	{
		printf("Operace DeleteFirst() nebyla implementována!\n");
		return(FALSE);
	}	
	print_elements_of_list(TEMPLIST);
	return(TRUE);	
	
}	

int test_PostDelete()	{
	
	solved=TRUE;
	PostDelete(&TEMPLIST);
	if (!solved)	{
		printf("Operace PostDelete() nebyla implementována!\n");
		return(FALSE);
	}	
	print_elements_of_list(TEMPLIST);
	return(TRUE);
	
}

int test_PostInsert()	{
	
	solved=TRUE;
	PostInsert(&TEMPLIST,ElemValue);
	if (!solved){
		printf("Operace PostInsert nebyla implementována!\n");
		return(FALSE);
	}
	print_elements_of_list(TEMPLIST);
	return(TRUE);
	
}

int test_DisposeList() {

    solved=TRUE;
    DisposeList(&TEMPLIST);
    if (!solved) {
        printf("Operace DisposeList() nebyla implementována!\n");
        return(FALSE);
    }	
    print_elements_of_list(TEMPLIST);
    return(TRUE);	
}

/*******************************************************************************
 * ZÁKLADNÍ TESTY
 * -------------- 
 * Za jejich úspěšné projítí získá student první část bodů za příklad.
 * Při hodnocení však budou použity rozšířené testy, které se zaměří
 * i na okrajové situace. Doporučujeme proto, aby si každý student
 * zkusil tyto základní testy rozšířit o další zajímavé situace.
 *  
 ******************************************************************************/

#define BASIC_TESTS 1
#define ADDITIONAL_TESTS 0

int main(int argc, char *argv[])	{

#if BASIC_TESTS
    printf("Jednosměrně vázaný lineární seznam\n");
    printf("==================================\n");

    printf("\n[TEST01]\n");
    printf("Inicializace seznamu\n");
    printf("~~~~~~~~~~~~~~~~~~~~\n");
    test_InitList();
	
    printf("\n[TEST02]\n");
    printf("Pokus o volání CopyFirst nad prázdným seznamem => chyba\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_CopyFirst();
	
    printf("\n[TEST03]\n");
    printf("Zavoláme 4x operaci InsertFirst.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    ElemValue=1; test_InsertFirst();
    ElemValue=2; test_InsertFirst();
    ElemValue=3; test_InsertFirst();
    ElemValue=4; test_InsertFirst();

    printf("\n[TEST04]\n");
    printf("Seznam je neaktivní -- ověříme si to voláním funce Active.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_Active(); 
	
    printf("\n[TEST05]\n");
    printf("Otestujeme funkci First při neaktivním seznamu a funkci Active.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_First();
    test_Active();
	
    printf("\n[TEST06]\n");
    printf("Test funkce Copy při aktivitě na prvním prvku\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_Copy();
 
    printf("\n[TEST07]\n");
    printf("Test funkce Succ -- voláme 3x, aktivita bude na posledním prvku.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_Succ();
    test_Succ();
    test_Succ();
    test_Active();
 
    printf("\n[TEST08]\n");
    printf("Aktualizujeme obsah aktivního prvku.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    ElemValue=10;	
    test_Actualize();
    test_Active();
    test_Copy();
	
    printf("\n[TEST09]\n"); 
    printf("Provedeme ještě jednou Succ -- aktivita se ztratí.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_Succ();
    test_Active();
	
    printf("\n[TEST10]\n");
    printf("Operace First nastaví aktivitu na první prvek.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_First();
    test_Active();

    printf("\n[TEST11]\n");
    printf("DeleteFirst aktivního prvku povede ke ztrátě aktivity.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DeleteFirst();
    test_Active();

    printf("\n[TEST12]\n");
    printf("Užitím operací First a Succ nastavíme aktivitu na konec seznamu.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_First();
    test_Succ();
    test_Succ();
    test_Active();

    printf("\n[TEST13]\n");
    printf("Operace PostDelete při aktivitě na posledním prvku nedělá nic.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_PostDelete();
    test_Active();
    
    printf("\n[TEST14]\n");
    printf("Nastavíme aktivitu na začátek a dvakrát zavoláme PostDelete.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_First();
    test_Active();
    test_PostDelete();
    test_PostDelete();
    test_Active();
	
    printf("\n[TEST15]\n");
    printf("Otestujeme InsertFirst při seznamu s jediným prvkem, nastavíme\n");
    printf("aktivitu na nově vložený prvek a opět posuneme aktivitu na konec\n"); 
    printf("seznamu.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    ElemValue=101;
    test_InsertFirst();
    test_First();
    test_Succ();
    test_Active();

    printf("\n[TEST16]\n");
    printf("Operací PostInsert vložíme nový prvek za poslední prvek seznamu.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    ElemValue=102;
    test_PostInsert();
    test_Active();

    printf("\n[TEST17]\n");
    printf("Nastavíme aktivitu na první prvek seznamu a vyzkoušíme PostInsert.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_First();
    ElemValue=103;
    test_PostInsert();
    test_Active();

    printf("\n[TEST18]\n");
    printf("Otestujeme funkčnost operace DisposeList.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DisposeList();
    
    printf("\n----------------------- konec příkladu c201 -------------------------\n");

#endif //BASIC_TESTS

#if ADDITIONAL_TESTS
#include <stdbool.h>
#define CHECK(RESULT) if (!(RESULT)) { puts("FAILED"); break;}

	int value = 0;
	printf("\n---------------------- additional tests c201 ------------------------\n");

	TEMPLIST.Act = (void*)1;
	TEMPLIST.Act = (void*)2;
	printf("\n[ADDITIONAL TEST1] expect two ERROR prints\n");
	// operations on an empty list
	while(1)
	{
		InitList(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL)
		First(&TEMPLIST);
		CHECK(TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		CHECK(!Active(&TEMPLIST))
		Succ(&TEMPLIST);
		CHECK(TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		PostDelete(&TEMPLIST);
		CHECK(TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		PostInsert(&TEMPLIST, 0);
		CHECK(TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		Actualize(&TEMPLIST, 0);
		CHECK(TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		CopyFirst(&TEMPLIST, &value);
		Copy(&TEMPLIST, &value);
		CHECK(TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		DeleteFirst(&TEMPLIST);
		CHECK(TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		DisposeList(&TEMPLIST);
		CHECK(TEMPLIST.First == NULL && TEMPLIST.Act == NULL)

		puts("OK");		
		break;
	}
	DisposeList(&TEMPLIST);

	printf("\n[ADDITIONAL TEST2] expect one ERROR print\n");
	while(1)
	{
		// operations on list of lenght 1
		InsertFirst(&TEMPLIST, 1);
		CHECK(TEMPLIST.First != NULL && TEMPLIST.Act == NULL)
		CopyFirst(&TEMPLIST, &value);
		CHECK(value == 1)
		Copy(&TEMPLIST, &value);
		CHECK(value == 1)
		Actualize(&TEMPLIST, 2);
		CHECK(TEMPLIST.First->data == 1)
		First(&TEMPLIST);
		CHECK(TEMPLIST.First != NULL && TEMPLIST.First == TEMPLIST.Act)
		Actualize(&TEMPLIST, 2);
		CHECK(TEMPLIST.First->data == 2)
		Copy(&TEMPLIST, &value);
		CHECK(value == 2)
		Succ(&TEMPLIST);
		CHECK(TEMPLIST.First != NULL && TEMPLIST.Act == NULL)
		PostDelete(&TEMPLIST);
		CHECK(TEMPLIST.First != NULL && TEMPLIST.Act == NULL)
		First(&TEMPLIST);
		CHECK(TEMPLIST.First != NULL && TEMPLIST.First == TEMPLIST.Act)
		PostInsert(&TEMPLIST, 3);
		CHECK(TEMPLIST.First->ptr->data == 3 && TEMPLIST.First == TEMPLIST.Act)
		Succ(&TEMPLIST);
		CHECK(TEMPLIST.First->ptr == TEMPLIST.Act && Active(&TEMPLIST))
		Actualize(&TEMPLIST, 4);
		CHECK(TEMPLIST.Act->data == 4)
		First(&TEMPLIST);
		PostDelete(&TEMPLIST);
		CHECK(TEMPLIST.First == TEMPLIST.Act)
		DeleteFirst(&TEMPLIST);
		CHECK(TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		DisposeList(&TEMPLIST);
		CHECK(TEMPLIST.First == NULL && TEMPLIST.Act == NULL)

		puts("OK");
		break;
	}
	DisposeList(&TEMPLIST);

	printf("\n[ADDITIONAL TEST3] exect no ERROR prints\n");
	// operations on list of lenght N
	//const int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	while(1)
	{
		InitList(&TEMPLIST);
		InsertFirst(&TEMPLIST, 0);
		First(&TEMPLIST);
		for (int i = 1; i <= 10; i++)
		{
			InsertFirst(&TEMPLIST, i);
		}
		CHECK(TEMPLIST.Act->data == 0);
		First(&TEMPLIST);
		CHECK(TEMPLIST.Act->data == 10);

		for (int i = 0; i < 5; i++)
		{
			Succ(&TEMPLIST);
		}
		CHECK(TEMPLIST.Act->data == 5);
		CHECK(TEMPLIST.Act->ptr->data == 4);
		PostDelete(&TEMPLIST);
		CHECK(TEMPLIST.Act->ptr->data == 3);
		PostInsert(&TEMPLIST, -1);
		CHECK(TEMPLIST.Act->ptr->data == -1);
		Succ(&TEMPLIST);
		Actualize(&TEMPLIST, 4);
		CHECK(TEMPLIST.Act->data == 4);
		First(&TEMPLIST);

		for (int i = 10; i > 0; i--)
		{
			CHECK(TEMPLIST.Act->data == i);
			Succ(&TEMPLIST);
		}
		CHECK(TEMPLIST.Act->ptr == NULL);
		CHECK(TEMPLIST.Act->data == 0);
		Succ(&TEMPLIST);
		CHECK(!Active(&TEMPLIST));
		First(&TEMPLIST);
		for (int i = 9; i > 0; i--)
		{
			CHECK(TEMPLIST.Act == TEMPLIST.First && TEMPLIST.Act->ptr->data == i)
			PostDelete(&TEMPLIST);
		}
		CHECK(TEMPLIST.Act->ptr->data == 0)
		PostDelete(&TEMPLIST);
		CHECK(TEMPLIST.Act->ptr == NULL)
		for (int i = 0; i < 10; i++)
		{
			PostInsert(&TEMPLIST, i);
			CHECK(TEMPLIST.Act->ptr->data == i);
		}
		
		for (int i = 10; i > 0; i--)
		{
			CHECK(TEMPLIST.Act->data == i);
			Succ(&TEMPLIST);
		}
		CHECK(TEMPLIST.Act->data == 0);
		First(&TEMPLIST);
		Succ(&TEMPLIST);
		DeleteFirst(&TEMPLIST);
		CHECK(TEMPLIST.First == TEMPLIST.Act)
		DeleteFirst(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL);
		First(&TEMPLIST);
		Succ(&TEMPLIST);
		Succ(&TEMPLIST);
		Succ(&TEMPLIST);
		CopyFirst(&TEMPLIST, &value);
		CHECK(value == 8)
		Copy(&TEMPLIST, &value);
		CHECK(value == 5)
		Actualize(&TEMPLIST, -5);
		Copy(&TEMPLIST, &value);
		CHECK(value == -5)
		TEMPLIST.Act->data = 5;
		CHECK(TEMPLIST.First->data == 8);
		for (int i = 8; i >= 0; i--)
		{
			CHECK(TEMPLIST.First->data == i);
			DeleteFirst(&TEMPLIST);
		}
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL);
		
		InsertFirst(&TEMPLIST, 1);
		DisposeList(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL);

		for (int i = 1; i <= 10; i++)
		{
			InsertFirst(&TEMPLIST, i);
		}
		DisposeList(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL);

		puts("OK");
		break;
	}
	DisposeList(&TEMPLIST);

	DisposeList(&TEMPLIST);
    return(0);

#endif //ADDITIONAL_TESTS
}	
