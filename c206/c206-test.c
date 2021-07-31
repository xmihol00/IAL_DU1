
/*
 *  Předmět: Algoritmy (IAL) - FIT VUT v Brně
 *  Základní testy pro příklad c206.c (Dvousměrně vázaný lineární seznam)
 *  Vytvořil: Martin Tuček, září 2005
 *  Úprava: Kamil Jeřábek, září 2020
 */

#include "c206.h"
                                                         /* pracovní proměnné */
tDLList TEMPLIST;		
int ElemValue=1;
int MaxListLength = 100;                     /* Handles wrongly linked lists. */


/*******************************************************************************
 * Pomocné funkce usnadňující testování vlastní implementace.
 ******************************************************************************/

void print_elements_of_list(tDLList TL)	{
	
	tDLList TempList=TL;
	int CurrListLength = 0;
	printf("-----------------");
	while ((TempList.First!=NULL) && (CurrListLength<MaxListLength))	{
		printf("\n \t%d",TempList.First->data);
		if ((TempList.First==TL.Act) && (TL.Act!=NULL))
			printf("\t <= toto je aktivní prvek ");
		TempList.First=TempList.First->rptr;
		CurrListLength++;
	}
    if (CurrListLength>=MaxListLength)
        printf("\nList exceeded maximum length!");
	printf("\n-----------------\n");     
}

int test_DLInitList()	{
	solved=TRUE;	
	DLInitList(&TEMPLIST);
	if (!solved)	{
		printf("Operace InitList nebyla implementována!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}	
}

int test_DLDisposeList()	{
	solved=TRUE;
	DLDisposeList(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLDisposeList nebyla implementována!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}	
}

int test_DLInsertFirst()	{
	solved=TRUE;
	DLInsertFirst(&TEMPLIST,ElemValue);
	if (!solved)	{
		printf("Operace DLInsertFirst nebyla implementována!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}	

int test_DLInsertLast()	{
	solved=TRUE;
	DLInsertLast(&TEMPLIST,ElemValue);
	if (!solved)	{
		printf("Operace DLInsertLast nebyla implementována!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}	

int test_DLFirst()	{
	solved=TRUE;
	DLFirst(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLFirst nebyla implementována!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLLast()	{
	solved=TRUE;
	DLLast(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLLast nebyla implementována!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLCopyFirst()	{
	solved=TRUE;	
    int temp;
    DLCopyFirst(&TEMPLIST,&temp);	
	if (!solved)	{
		printf("Operace DLCopyFirst nebyla implementována!\n");
		return(FALSE);
	}
	else {
		if (errflg)	{
			printf("Operace DLCopyFirst volala funkci DLError.\n");
			errflg=FALSE;
			return(FALSE);
		}	
		else	{	 			
			printf("Operace DLCopyFirst vrací obsah %d.\n",temp);
			return(TRUE);
		}	
	}
}	

int test_DLCopyLast()	{
	solved=TRUE;
    int temp;
    DLCopyLast(&TEMPLIST,&temp);	
	if (!solved)	{
		printf("Operace DLCopyLast nebyla implementována!\n");
		return(FALSE);
	}
	else {
		if (errflg)	{
			printf("Operace DLCopyLast volala funkci DLError.\n");
			errflg=FALSE;
			return(FALSE);
		}	
		else	{	 			
			printf("Operace DLCopyLast vrací obsah %d.\n",temp);
			return(TRUE);
		}	
	}
}	

int test_DLDeleteFirst ()	{
	solved=TRUE;	
	DLDeleteFirst(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLDeleteFirst nebyla implementována!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}	

int test_DLDeleteLast ()	{
	solved=TRUE;	
	DLDeleteLast(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLDeleteLast nebyla implementována!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}	

int test_DLPostDelete()	{
	solved=TRUE;	
	DLPostDelete(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLPostDelete nebyla implementována!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}	

int test_DLPreDelete()	{
	solved=TRUE;	
	DLPreDelete(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLPreDelete nebyla implementována!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLPostInsert()	{
	solved=TRUE;
	DLPostInsert(&TEMPLIST,ElemValue);
	if (!solved)	{
		printf("Operace DLPostInsert nebyla implementována!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLPreInsert()	{
	solved=TRUE;
	DLPreInsert(&TEMPLIST,ElemValue);
	if (!solved)	{
		printf("Operace DLPreInsert nebyla implementována!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLCopy()	{
	solved=TRUE;
	int temp;
  DLCopy(&TEMPLIST,&temp);	
	
	if (!solved)	{
		printf("Operace DLCopy nebyla implementována!\n");
		return(FALSE);
	}
	else {
		if (errflg)	{
			printf("Operace DLCopy volala funkci DLError.\n");
			errflg=FALSE;
			return(FALSE);
		}	
		else	{	 			
			printf("Operace DLCopy vrací obsah %d.\n",temp);
			return(TRUE);
		}	
	}	
}

int test_DLActualize()	{
	solved=TRUE;
	DLActualize(&TEMPLIST,ElemValue);
	if (!solved)	{
		printf("Operace DLActualize nebyla implementována!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLSucc()	{
	solved=TRUE;
	DLSucc(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLSucc nebyla implementována!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLPred()	{
	solved=TRUE;
	DLPred(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLPred nebyla implementována!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLActive()	{
	solved=TRUE;
	int tmp=DLActive(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLActive nebyla implementována!\n");
		return(FALSE);
	}	
	else	{
		if (tmp)
			printf("Operace DLActive vrací hodnotu true.\n");
		else
			printf("Operace DLActive vrací hodnotu false.\n");	
		return(TRUE);			
	}
}

/*******************************************************************************
 * ZÁKLADNÍ TESTY
 * -------------- 
 * Za jejich úspěšné projítí získá student první část bodů za příklad.
 * Při hodnocení však budou použity rozšířené testy, které se zaměří
 * i na okrajové situace. Doporučujeme proto, aby si každý student
 * zkusitl tyto základní testy rozšířit o další zajímavé situace.
 *  
 ******************************************************************************/

#define BASIC_TESTS 1
#define ADDITIONAL_TESTS 0
#define CHECK(RESULT) if (!(RESULT)) { puts("FAILED"); break;}

int main(int argc, char *argv[])	{
#if BASIC_TESTS	
    printf("Dvousměrně vázaný lineární seznam\n");
    printf("=================================\n");

    printf("\n[TEST01]\n");
    printf("Inicializace seznamu\n");
    printf("~~~~~~~~~~~~~~~~~~~~\n");
    test_DLInitList();

    printf("\n[TEST02]\n");
    printf("Zavoláme 2x operaci DLInsertFirst a 2x operaci DLInsertLast.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
    ElemValue=1;
    test_DLInsertFirst();	
    ElemValue=2;
    test_DLInsertFirst();	
    ElemValue=3;
    test_DLInsertLast();
    ElemValue=4;
    test_DLInsertLast();
	
    printf("\n[TEST03]\n");
    printf("Otestujeme funkci DLFirst při neaktivním seznamu a funkci DLActive.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLFirst();
    test_DLActive();

    printf("\n[TEST04]\n");
    printf("Otestujeme funkci DLLast.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLLast();
    test_DLActive();
	
    printf("\n[TEST05]\n");
    printf("Test funkce DLCopy při aktivitě na posledním prvku\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLCopy();

    printf("\n[TEST06]\n");
    printf("Test funkce DLPred -- voláme 3x, aktivita zůstane na prvním prvku.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLPred();
    test_DLPred();
    test_DLPred();
    test_DLActive();

    printf("\n[TEST07]\n");
    printf("Aktualizujeme obsah aktivního prvku.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
    ElemValue=5;
    test_DLActualize();
    test_DLActive();
    test_DLCopy();
	
    printf("\n[TEST08]\n");
    printf("Test funkce DLSucc -- voláme 3x, aktivita zůstane na posledním prvku.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLSucc();
    test_DLSucc();
    test_DLSucc();
    test_DLActive();
	
    printf("\n[TEST09]\n");
    printf("Provedeme ještě jednou DLSucc - aktivita se ztratí.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLSucc();
    test_DLActive();
	
    printf("\n[TEST10]\n");
    printf("Nastavíme aktivitu na začátek a pak ji zrušíme operací DLPred.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLFirst();
    test_DLPred();
    test_DLActive();
	
    printf("\n[TEST11]\n");
    printf("Pokus o DLCopy při neaktivním seznamu => ošetřená chyba.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLCopy();
    
    printf("\n[TEST12]\n");
    printf("Použití operace DLCopyFirst při neaktivním seznamu\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLCopyFirst();

    printf("\n[TEST13]\n");
    printf("Použití operace DLCopyLast při neaktivním seznamu\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLCopyLast();

    printf("\n[TEST14]\n");
    printf("Použití operace DLDeleteFirst při neaktivním seznamu\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLDeleteFirst();
    test_DLActive();

    printf("\n[TEST15]\n");
    printf("Použití operace DLDeleteLast při neaktivním seznamu\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLDeleteLast();
      test_DLActive();
	
    printf("\n[TEST16]\n");
    printf("Zkusíme DLPostDelete při aktivitě na posledním prvku.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLLast();
    test_DLPostDelete();
    test_DLActive();
	
    printf("\n[TEST17]\n");
    printf("Operace DLPreDelete nyní smaže první prvek.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLPreDelete();
    test_DLActive();
    
    printf("\n[TEST18]\n"); 
    printf("Seznam nakonec zrušíme.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLDisposeList();
    test_DLActive();

    printf("\n----------------------- konec příkladu c206 -------------------------\n");
#endif //BASIC_TESTS

#if ADDITIONAL_TESTS
	int val = 0;
	printf("\n---------------------- ADDITIONAL TESTS c206 -------------------------\n");
	DLInitList(&TEMPLIST);
	printf("\n[ADDITIONAL TEST1] expect 3 errors\n");
	// tests on an empty list
	while(1)
	{
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		DLFirst(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		DLLast(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		DLCopy(&TEMPLIST, &val);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		DLCopyFirst(&TEMPLIST, &val);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		DLCopyLast(&TEMPLIST, &val);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		DLDeleteFirst(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		DLDeleteLast(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		DLPreDelete(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		DLPostDelete(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		DLPostInsert(&TEMPLIST, 1);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		DLPreInsert(&TEMPLIST, 1);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		DLSucc(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		DLPred(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		CHECK(!DLActive(&TEMPLIST))
		DLActualize(&TEMPLIST, 1);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		DLDisposeList(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)

		puts("OK");
		break;
	}

	DLInitList(&TEMPLIST);
	printf("\n[ADDITIONAL TEST2] expect no errors\n");
	// tests on a list with one element
	while (1)
	{
		DLInsertFirst(&TEMPLIST, 1);
		CHECK(TEMPLIST.First->data == 1 && TEMPLIST.Last->data == 1)
		DLFirst(&TEMPLIST);
		CHECK(TEMPLIST.Act->data == 1 && TEMPLIST.First->data == 1 && TEMPLIST.Last->data == 1)
		DLPred(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First->data == 1 && TEMPLIST.Last->data == 1)
		DLLast(&TEMPLIST);
		CHECK(TEMPLIST.Act->data == 1 && TEMPLIST.First->data == 1 && TEMPLIST.Last->data == 1)
		DLSucc(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First->data == 1 && TEMPLIST.Last->data == 1)
		DLFirst(&TEMPLIST);
		CHECK(DLActive(&TEMPLIST))
		DLActualize(&TEMPLIST, -1);
		CHECK(TEMPLIST.Act->data == -1 && TEMPLIST.First->data == -1 && TEMPLIST.Last->data == -1)
		DLCopy(&TEMPLIST, &val);
		CHECK(val == -1)
		CHECK(TEMPLIST.Act->data == -1 && TEMPLIST.First->data == -1 && TEMPLIST.Last->data == -1)
		DLCopyLast(&TEMPLIST, &val);
		CHECK(val == -1)
		CHECK(TEMPLIST.Act->data == -1 && TEMPLIST.First->data == -1 && TEMPLIST.Last->data == -1)
		DLCopyFirst(&TEMPLIST, &val);
		CHECK(val == -1)
		CHECK(TEMPLIST.Act->data == -1 && TEMPLIST.First->data == -1 && TEMPLIST.Last->data == -1)
		DLDeleteFirst(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)
		
		DLInsertLast(&TEMPLIST, 1);
		CHECK(TEMPLIST.First->data == 1 && TEMPLIST.Last->data == 1 && TEMPLIST.First->lptr == NULL && TEMPLIST.First->rptr == NULL)	
		DLFirst(&TEMPLIST);
		CHECK(TEMPLIST.Act->data == 1 && TEMPLIST.First->data == 1 && TEMPLIST.Last->data == 1 && TEMPLIST.First->lptr == NULL && TEMPLIST.First->rptr == NULL)
		DLPred(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First->data == 1 && TEMPLIST.Last->data == 1 && TEMPLIST.First->lptr == NULL && TEMPLIST.First->rptr == NULL)
		DLLast(&TEMPLIST);
		CHECK(TEMPLIST.Act->data == 1 && TEMPLIST.First->data == 1 && TEMPLIST.Last->data == 1 && TEMPLIST.First->lptr == NULL && TEMPLIST.First->rptr == NULL)
		DLSucc(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First->data == 1 && TEMPLIST.Last->data == 1 && TEMPLIST.First->lptr == NULL && TEMPLIST.First->rptr == NULL)
		DLFirst(&TEMPLIST);
		CHECK(DLActive(&TEMPLIST))
		DLActualize(&TEMPLIST, -1);
		CHECK(TEMPLIST.Act->data == -1 && TEMPLIST.First->data == -1 && TEMPLIST.Last->data == -1 && TEMPLIST.First->lptr == NULL && TEMPLIST.First->rptr == NULL)
		DLCopy(&TEMPLIST, &val);
		CHECK(val == -1)
		CHECK(TEMPLIST.Act->data == -1 && TEMPLIST.First->data == -1 && TEMPLIST.Last->data == -1 && TEMPLIST.First->lptr == NULL && TEMPLIST.First->rptr == NULL)
		DLCopyLast(&TEMPLIST, &val);
		CHECK(val == -1)
		CHECK(TEMPLIST.Act->data == -1 && TEMPLIST.First->data == -1 && TEMPLIST.Last->data == -1 && TEMPLIST.First->lptr == NULL && TEMPLIST.First->rptr == NULL)
		DLCopyFirst(&TEMPLIST, &val);
		CHECK(val == -1)
		CHECK(TEMPLIST.Act->data == -1 && TEMPLIST.First->data == -1 && TEMPLIST.Last->data == -1 && TEMPLIST.First->lptr == NULL && TEMPLIST.First->rptr == NULL)
		DLActualize(&TEMPLIST, 1);
		CHECK(TEMPLIST.Last->data == 1 && TEMPLIST.First->data == 1 && TEMPLIST.Act->data == 1)
		DLDeleteLast(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)

		DLInsertFirst(&TEMPLIST, 2);
		DLFirst(&TEMPLIST);
		DLPreInsert(&TEMPLIST, 1);
		CHECK(TEMPLIST.Act->data == 2 && TEMPLIST.First->data == 1 && TEMPLIST.Last->data == 2 && TEMPLIST.First->rptr == TEMPLIST.Last && TEMPLIST.Last->lptr == TEMPLIST.First && TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL)
		DLPreDelete(&TEMPLIST);
		CHECK(TEMPLIST.First->data == 2 && TEMPLIST.Last == TEMPLIST.First && TEMPLIST.Act == TEMPLIST.First && TEMPLIST.First->lptr == NULL && TEMPLIST.First->rptr == NULL)
		DLPostInsert(&TEMPLIST, 1);
		CHECK(TEMPLIST.Act->data == 2 && TEMPLIST.First->data == 2 && TEMPLIST.Last->data == 1 && TEMPLIST.First->rptr == TEMPLIST.Last && TEMPLIST.Last->lptr == TEMPLIST.First && TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL)
		DLPostDelete(&TEMPLIST);
		CHECK(TEMPLIST.First->data == 2 && TEMPLIST.Last == TEMPLIST.First && TEMPLIST.Act == TEMPLIST.First && TEMPLIST.First->lptr == NULL && TEMPLIST.First->rptr == NULL)
		DLDeleteLast(&TEMPLIST);
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.First == NULL && TEMPLIST.Act == NULL)

		DLInsertLast(&TEMPLIST, 3);
		DLInsertLast(&TEMPLIST, 4);
		CHECK(TEMPLIST.Last->data == 4 && TEMPLIST.First->data == 3 && TEMPLIST.First->rptr == TEMPLIST.Last && TEMPLIST.Last->lptr == TEMPLIST.First && TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL)
		DLLast(&TEMPLIST);
		CHECK(DLActive(&TEMPLIST))
		CHECK(TEMPLIST.Last == TEMPLIST.Act && TEMPLIST.Act->lptr == TEMPLIST.First && TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL)
		DLPred(&TEMPLIST);
		CHECK(DLActive(&TEMPLIST))
		DLActualize(&TEMPLIST, 987);
		CHECK(TEMPLIST.First == TEMPLIST.Act && TEMPLIST.Act->rptr == TEMPLIST.Last && TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL)
		DLPred(&TEMPLIST);
		CHECK(!DLActive(&TEMPLIST))
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL && TEMPLIST.First->rptr == TEMPLIST.Last && TEMPLIST.Last->lptr == TEMPLIST.First)
		DLDeleteLast(&TEMPLIST);
		CHECK(TEMPLIST.First == TEMPLIST.Last && TEMPLIST.Act == NULL && TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL && TEMPLIST.First->data == 987)
		DLDeleteLast(&TEMPLIST);
		CHECK(TEMPLIST.First == NULL && TEMPLIST.Last == NULL && TEMPLIST.First == NULL)

		DLInsertFirst(&TEMPLIST, 5);
		DLInsertFirst(&TEMPLIST, 6);
		CHECK(TEMPLIST.Last->data == 5 && TEMPLIST.First->data == 6 && TEMPLIST.First->rptr == TEMPLIST.Last && TEMPLIST.Last->lptr == TEMPLIST.First && TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL)
		DLFirst(&TEMPLIST);
		CHECK(DLActive(&TEMPLIST))
		CHECK(TEMPLIST.First == TEMPLIST.Act && TEMPLIST.Act->rptr == TEMPLIST.Last && TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL)
		DLSucc(&TEMPLIST);
		CHECK(DLActive(&TEMPLIST))
		DLActualize(&TEMPLIST, 123);
		CHECK(TEMPLIST.Last == TEMPLIST.Act && TEMPLIST.Act->lptr == TEMPLIST.First && TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL)
		DLSucc(&TEMPLIST);
		CHECK(!DLActive(&TEMPLIST))
		CHECK(TEMPLIST.Act == NULL && TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL && TEMPLIST.First->rptr == TEMPLIST.Last && TEMPLIST.Last->lptr == TEMPLIST.First)
		DLDeleteFirst(&TEMPLIST);
		CHECK(TEMPLIST.First == TEMPLIST.Last && TEMPLIST.Act == NULL && TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL && TEMPLIST.First->data == 123)
		DLDeleteFirst(&TEMPLIST);
		CHECK(TEMPLIST.First == NULL && TEMPLIST.Last == NULL && TEMPLIST.First == NULL)

		puts("OK"); 
		break;
	}

	DLInitList(&TEMPLIST);
	printf("\n[ADDITIONAL TEST3] expect no errors\n");
	// tests on a list with many element
	while (1)
	{
		for (int i = 0; i < 8; i++)
		{
			DLInsertFirst(&TEMPLIST, i);
		}
		CHECK(TEMPLIST.First->lptr == NULL && TEMPLIST.Last->rptr == NULL)
		DLLast(&TEMPLIST);
		for (int i = 0; i < 8; i++)
		{
			DLCopy(&TEMPLIST, &val);
			CHECK(val == i)
			DLPred(&TEMPLIST);
		}
		CHECK(TEMPLIST.First->lptr == NULL && TEMPLIST.Last->rptr == NULL)
		for (int i = 0; i < 6; i++)
		{
			DLLast(&TEMPLIST);
			DLCopy(&TEMPLIST, &val);
			CHECK(val == i)
			DLDeleteLast(&TEMPLIST);
		}
		CHECK(TEMPLIST.First->lptr == NULL && TEMPLIST.Last->rptr == NULL)
		DLLast(&TEMPLIST);
		CHECK(TEMPLIST.Last == TEMPLIST.Act && TEMPLIST.Act->lptr == TEMPLIST.First && TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL)
		DLCopy(&TEMPLIST, &val);
		CHECK(val == 6)
		DLDeleteLast(&TEMPLIST);
		DLLast(&TEMPLIST);
		CHECK(TEMPLIST.Last == TEMPLIST.Act && TEMPLIST.Last == TEMPLIST.First && TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL)
		DLCopy(&TEMPLIST, &val);
		CHECK(val == 7)
		DLDeleteLast(&TEMPLIST);
		CHECK(TEMPLIST.First == NULL && TEMPLIST.Last == NULL && TEMPLIST.Act == NULL);

		for (int i = 0; i < 8; i++)
		{
			DLInsertLast(&TEMPLIST, i);
		}
		CHECK(TEMPLIST.First->lptr == NULL && TEMPLIST.Last->rptr == NULL)
		DLFirst(&TEMPLIST);
		for (int i = 0; i < 8; i++)
		{
			DLCopy(&TEMPLIST, &val);
			CHECK(val == i)
			DLSucc(&TEMPLIST);
		}
		CHECK(TEMPLIST.First->lptr == NULL && TEMPLIST.Last->rptr == NULL)
		for (int i = 0; i < 6; i++)
		{
			DLFirst(&TEMPLIST);
			DLCopy(&TEMPLIST, &val);
			CHECK(val == i)
			DLDeleteFirst(&TEMPLIST);
		}
		DLFirst(&TEMPLIST);
		CHECK(TEMPLIST.First == TEMPLIST.Act && TEMPLIST.Act->rptr == TEMPLIST.Last && TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL)
		DLCopy(&TEMPLIST, &val);
		CHECK(val == 6)
		DLDeleteFirst(&TEMPLIST);
		DLFirst(&TEMPLIST);
		CHECK(TEMPLIST.First == TEMPLIST.Act && TEMPLIST.Last == TEMPLIST.First && TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL)
		DLCopy(&TEMPLIST, &val);
		CHECK(val == 7)
		DLDeleteFirst(&TEMPLIST);
		CHECK(TEMPLIST.First == NULL && TEMPLIST.Last == NULL && TEMPLIST.Act == NULL);

		DLInsertFirst(&TEMPLIST, -1);
		DLFirst(&TEMPLIST);
		for (int i = 0; i < 8; i++)
		{
			DLPostInsert(&TEMPLIST, i);
		}
		DLCopyFirst(&TEMPLIST, &val);
		CHECK(val == -1)
		DLCopyLast(&TEMPLIST, &val);
		CHECK(val == 0)
		DLSucc(&TEMPLIST);
		DLSucc(&TEMPLIST);
		DLCopy(&TEMPLIST, &val);
		CHECK(val == 6)
		DLPostInsert(&TEMPLIST, 88);
		DLSucc(&TEMPLIST);
		DLCopy(&TEMPLIST, &val);
		CHECK(val == 88)
		DLPred(&TEMPLIST);
		DLPreInsert(&TEMPLIST, 99);
		DLPred(&TEMPLIST);
		DLCopy(&TEMPLIST, &val);
		CHECK(val == 99)
		CHECK(TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL)
		DLPreDelete(&TEMPLIST);
		CHECK(TEMPLIST.Act->lptr == TEMPLIST.First)
		DLPreDelete(&TEMPLIST);
		CHECK(TEMPLIST.Act == TEMPLIST.First && TEMPLIST.Last->rptr == NULL && TEMPLIST.First->lptr == NULL);
		DLPostDelete(&TEMPLIST);
		CHECK(TEMPLIST.Act->rptr->data == 88)
		for (int i = 0; i < 6; i++)
			DLPostDelete(&TEMPLIST);
		CHECK(TEMPLIST.First->rptr == TEMPLIST.Last && TEMPLIST.First == TEMPLIST.Act)
		DLPostDelete(&TEMPLIST);
		CHECK(TEMPLIST.First == TEMPLIST.Last && TEMPLIST.First == TEMPLIST.Act)
		DLDeleteLast(&TEMPLIST);
		CHECK(TEMPLIST.First == NULL && TEMPLIST.Last == NULL && TEMPLIST.Act == NULL);

		DLInsertLast(&TEMPLIST, -1);
		DLLast(&TEMPLIST);
		for (int i = 0; i < 8; i++)
		{
			DLPreInsert(&TEMPLIST, i);
		}
		DLCopyLast(&TEMPLIST, &val);
		CHECK(val == -1);
		DLCopyFirst(&TEMPLIST, &val);
		CHECK(val == 0);
		int j = 7;
		while (TEMPLIST.First != TEMPLIST.Act)
		{
			DLPred(&TEMPLIST);
			DLCopy(&TEMPLIST, &val);
			CHECK(val == j--)
		}
		j = 1;
		DLDeleteLast(&TEMPLIST);
		while (TEMPLIST.Last != TEMPLIST.Act)
		{
			DLSucc(&TEMPLIST);
			DLCopy(&TEMPLIST, &val);
			CHECK(val == j++)
		}
		DLPred(&TEMPLIST);
		DLPred(&TEMPLIST);
		DLPred(&TEMPLIST);
		DLPred(&TEMPLIST);
		DLInsertFirst(&TEMPLIST, -1);
		DLCopy(&TEMPLIST, &val);
		CHECK(val == 3)
		DLPreDelete(&TEMPLIST);
		DLPostDelete(&TEMPLIST);
		DLCopy(&TEMPLIST, &val);
		CHECK(val == 3)
		DLPreDelete(&TEMPLIST);
		DLPostDelete(&TEMPLIST);
		DLCopy(&TEMPLIST, &val);
		CHECK(val == 3)
		DLPreDelete(&TEMPLIST);
		DLPostDelete(&TEMPLIST);
		DLCopy(&TEMPLIST, &val);
		CHECK(val == 3)
		DLPostInsert(&TEMPLIST, 777);
		DLPreInsert(&TEMPLIST, 222);
		DLSucc(&TEMPLIST);
		DLSucc(&TEMPLIST);
		DLCopy(&TEMPLIST, &val);
		CHECK(val == 7)
		DLPred(&TEMPLIST);
		DLPred(&TEMPLIST);
		DLCopy(&TEMPLIST, &val);
		CHECK(val == 3)
		DLPred(&TEMPLIST);
		DLPred(&TEMPLIST);
		DLCopy(&TEMPLIST, &val);
		CHECK(val == -1)
		DLSucc(&TEMPLIST);
		DLSucc(&TEMPLIST);
		DLCopy(&TEMPLIST, &val);
		CHECK(val == 3)
		CHECK(TEMPLIST.First->lptr == NULL && TEMPLIST.Last->rptr == NULL)
		DLPostDelete(&TEMPLIST);
		DLPreDelete(&TEMPLIST);
		DLActualize(&TEMPLIST, 555);
		DLCopy(&TEMPLIST, &val);
		CHECK(val == 555)
		CHECK(TEMPLIST.Act->rptr == TEMPLIST.Last && TEMPLIST.Act->lptr == TEMPLIST.First);
		DLPostDelete(&TEMPLIST);
		DLPreDelete(&TEMPLIST);
		DLActualize(&TEMPLIST, 666);
		DLCopy(&TEMPLIST, &val);
		CHECK(val == 666)
		CHECK(TEMPLIST.Act == TEMPLIST.First && TEMPLIST.Last == TEMPLIST.Act)

		

		puts("OK");
		break;
	}

	DLDisposeList(&TEMPLIST);
#endif
    return(0);
} 
