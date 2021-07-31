
/****************************** c203-test.c ************************************
 * Předmět: Algoritmy (IAL) - FIT VUT v Brně
 * Základní testy pro příklad c203.c (Fronta znaků v poli)
 * Vytvořil: Václav Topinka, září 2005
 * Upravil: Bohuslav Křena, září 2012
 *******************************************************************************
 * V tomto příkladu jsme použili trochu více angličtinu než obvykle.
 * Máme pro to dva důvody:
 *  
 * 1) Angličtina je druhá mateřština informatika! Bez ní se jako informatici
 * (a v dnešní době nejenom jako informatici) asi jenom těžko obejdete.
 * Domácí úlohy (alespoň z části) v angličtině by vám proto mohli pomoci při
 * zažití tohoto jazyka. Pojmenovávat identifikátory anglickými termíny je
 * velice dobrý zvyk - nikdy nevíte, zda Váš kód nebude později číst nebo
 * dokonce upravovat někdo, kdo česky nerozumí. Stejně tak je užitečné psát
 * anglictky i komentáře.
 *  
 * 2) Na FIT přijíždějí zahraniční studenti v rámci projektů ERASMUS/SOCRATES
 * Aby se podmínky jejich studia co nejvíce blížily podmínkám, které mají
 * studenti studující v češtině, měli by zahraniční studenti dělat i stejné
 * domácí úlohy. Jenže to vyžaduje mít domácí úlohy připraveny v angličtině.
 * A udržovat konzistenci dvou verzí domácích úloh (českých a anglických) 
 * je značně pracné. Převedení domácích úloh do angličtiny by tento problém
 * elegatně vyřešilo.
 * 
 * Samotné zadání nakonec zůstalo i pro tento příklad v češtině, aby se nikdo
 * nemohl cítit poškozen tím, že zadání nerozuměl právě kvůli použití
 * nemateřského jazyka.
 ******************************************************************************/

#include "c203.h"

#include <stdio.h>
#include <stdlib.h>
                                             /* variables used within testing */
tQueue* queue;
int QUEUE_SIZE;
int solved;
int err_flag;

/*******************************************************************************
 * The following functions allow us to write shorter testing code.
 * They usually call particular operation, check whether the function
 * has been implemented, and, eventualy, print a result of the function.
 ******************************************************************************/

void queuePrint ( tQueue* q ) {
/* Prints a queue with the following index meaning:
 * F = Front
 * B = Back
 * E = queue is Empty (F == B)
 */
	putchar('\n');
                                                   /* Prints a queue content. */
	for ( int i=0; i<QUEUE_SIZE; i++ )
		putchar(q->arr[i]);
	putchar('\n');
                                                 /* Prints a queue index(es). */
	for ( int i=0; i<QUEUE_SIZE; i++ ) {
		if ( ( i == q->f_index ) || ( i == q->b_index ) )
			putchar('^');
		else
			putchar(' ');
	}
	putchar('\n');
                                                 /* Prints index(es) meaning. */
	for ( int i=0; i<QUEUE_SIZE; i++ ) {
		if ( (i == q->f_index) && (i==q->b_index))
			putchar('E');
		else if ( i == q->f_index )
			putchar ('F');
		else if ( i == q->b_index )
			putchar ('B');
		else
			putchar (' ');
	}
	putchar('\n');
}

void use_queue_init ( tQueue* q ) {
    solved = 1;
	queueInit( q );
	if ( ! solved )
		printf("Function queueInit has not been implemented.\n");
}

void use_queue_empty ( tQueue* q ) {
    solved = 1;
	int i = queueEmpty( q );
	if ( ! solved )
		printf("Function queueEmpty has not been implemented.\n");
	else
		printf("Function queueEmpty returned '%s'.\n", i ? "TRUE" : "FALSE");
}

void use_queue_full ( tQueue* q ) {
	solved = 1;
	int i = queueFull( q );
	if ( ! solved )
		printf("Function queueFull has not been implemented.\n");
	else
		printf("Fucntion queueFull returned '%s'.\n", i ? "TRUE" : "FALSE");
}

void use_queue_front ( tQueue* q ) {
	solved = 1;
	err_flag = 0;
	char c;
  queueFront( q, &c );
	if ( ! solved )
		printf("Function queueFront has not been implemented.\n");
	else if ( !err_flag )
		printf("Function queueFront returned value '%c'.\n", c );
}

void use_queue_remove ( tQueue* q ) {
	solved = 1;
	queueRemove( q );
	if ( ! solved )
		printf("Function queueRemove has not been implemented.\n");
}

void use_queue_get ( tQueue* q ) {
	solved = 1;
	err_flag = 0;
	char c;
  queueGet( q, &c );
	if ( ! solved )
		printf("Function queueGet has not been implemented.\n");
	else if ( !err_flag )
		printf("Function queueGet returned value '%c'.\n", c );
}

void use_queue_up ( tQueue* q, char c ) {
    solved = 1;
    queueUp( q, c );
    if ( ! solved )
		    printf("Function queueUp has not been implemented.\n");
		return;
}

/*******************************************************************************
 * BASIC TESTS
 * -----------
 * The student earns the first part of the exercise points by passing these
 * basic tests. To earn the rest of points, it is necessary to pass advanced
 * tests which deal with margin situations. We recommend to all students to
 * improve these basic tests in order to find as much bugs in the implementation
 * as possible. Of course, if you are able to write the code without mistakes
 *  you do not need any testing.
 ******************************************************************************/
#define CHECK(RESULT) if (!(RESULT)) { puts("FAILED"); break;}
#define BASIC_TESTS 1
#define ADDITIONAL_TESTS 0

int main ( int argc, char* argv[] ) {
#if BASIC_TESTS
	printf ("******************************************\n");
	printf ("* C203: Queue implemented using an array *\n");
	printf ("* Basic testing script (c203-test.c)     *\n");
	printf ("******************************************\n");
	printf ("* The explanation:                       *\n");
	printf ("* ~~~~~~~~~~~~~~~~                       *\n");
	printf ("* * - not used yet                       *\n");
	printf ("* F - Front                              *\n");
	printf ("* B - Back                               *\n");
	printf ("* E - Empty (F == B)                     *\n");
	printf ("******************************************\n");

	QUEUE_SIZE = 9;
                                     /* We allocate the memory for the queue. */
    queue = (tQueue*)malloc(sizeof(tQueue));
    if ( queue == NULL ) {
    	printf ("\nc203-test.c: Error: There is not enough memory for the queue.\n");
        return 1;
    }

	printf ("\n[TEST01] queue initialization\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
    use_queue_init( queue );
	queuePrint( queue );

	printf ("\n[TEST02] We try queueEmpty and queueFull over the empty queue.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_empty( queue );
	use_queue_full( queue );

	printf ("\n[TEST03] queueFront, queueGet, and queueRemove should cause handled errors.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_front ( queue );
	use_queue_get ( queue );
	use_queue_remove ( queue );
	queuePrint( queue );

	printf ("\n[TEST04] We put 'Ciao!' into the queue using queueUp.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_up( queue, 'C' );
	use_queue_up( queue, 'i' );
	use_queue_up( queue, 'a' );
	use_queue_up( queue, 'o' );
	use_queue_up( queue, '!' );
	queuePrint( queue );

	printf ("\n[TEST05] Functions queueEmpty as well as queueFull should return FALSE now.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_empty( queue );
	use_queue_full( queue );
	
	printf ("\n[TEST06] Function queueFront should always return the same value.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_front( queue );
	use_queue_front( queue );
	queuePrint( queue );
	
	printf ("\n[TEST07] Let's examine the difference between queueRemove and queueGet.\n" );
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_remove( queue );
	use_queue_get( queue );
	queuePrint( queue );
	
	printf ("\n[TEST08] After three queueGet the queue should be empty.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_get( queue );
	use_queue_get( queue );
	use_queue_get( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue );

                   /* Back index should be at the end of array after test 09. */
	printf ("\n[TEST09] We put 1, 2, and 3 to the queue using QueueUp and check the result.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_up( queue, '1' );
	use_queue_up( queue, '2' );
	use_queue_up( queue, '3' );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue );
	
	printf ("\n[TEST10] After removing three elements using queueGet, the queue should be empty.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_get( queue );
	use_queue_get( queue );
	use_queue_get( queue );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue);

	printf ("\n[TEST11] Additional queueUp should move to b_index possition 0.\n" );
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_up( queue, '4' );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue );

	printf ("\n[TEST12] After queueGet, the indexes should be the same as after queueInit.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_get( queue );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue);

	printf ("\n[TEST13] We use queueUp eight times to fill up the queue.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	for ( int i=0; i<8; i++ )
		use_queue_up( queue, 'A'+i );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue );

	printf ("\n[TEST14] Addition queueUp() should cause hadled error.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_up( queue, 'Z' );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue );

	printf ("\n******* The end of Basic Tests (c203-test.c) *******\n");
	free (queue);
#endif //BASIC_TEST

#if ADDITIONAL_TESTS
	printf ("\n********* Additional tests (c203-test.c) *********\n");
	char value = 0;
	tQueue* q = malloc(sizeof(tQueue));
	if (q == NULL)
		return 1;
	
	QUEUE_SIZE = 15;

	queueInit(q);
	for (int i = 0; i < 15; i++)
	{
		CHECK(q->arr[i] == '*')
		CHECK(q->b_index == 0 && q->f_index == 0)
	}
	printf ("\n[ADDITIONAL TEST1] expect errors: GET, REMOVE, FRONT\n");
	//tests on an empty queue
	while (1)
	{
		CHECK(queueEmpty(q))
		queueGet(q, &value);
		CHECK(queueEmpty(q))
		queueRemove(q);
		CHECK(queueEmpty(q))
		queueFront(q, &value);
		CHECK(queueEmpty(q))
		CHECK(!queueFull(q))
		puts("OK");
		break;
	}
	printf ("\n[ADDITIONAL TEST2] expect no errors\n");
	//tests on a queue with one element
	while (1)
	{
		queueUp(q, 1);
		CHECK(!queueEmpty(q))
		CHECK(!queueFull(q))
		CHECK(q->arr[0] == 1)
		queueFront(q, &value);
		CHECK(q->arr[0] == 1);
		CHECK(value == 1);
		value = 0;
		queueGet(q, &value);
		CHECK(queueEmpty(q))
		CHECK(!queueFull(q))
		CHECK(q->arr[0] == 1);
		CHECK(value == 1);
		queueUp(q, 1);
		queueRemove(q);
		CHECK(queueEmpty(q))
		CHECK(!queueFull(q))

		puts("OK");
		break;
	}
	queueInit(q);

	printf ("\n[ADDITIONAL TEST3] expect errors: UP, UP\n");
	//tests on a queue with multiple elements
	while (1)
	{
		for (int i = 0; i < 14; i++)
		{
			queueUp(q, i+'a');
			CHECK(q->arr[i] == i+'a')
			queueFront(q, &value);
			CHECK(value == 'a')
		}
		CHECK(!queueEmpty(q))
		CHECK(queueFull(q))
		queueUp(q, 'X');
		CHECK(!queueEmpty(q))
		CHECK(queueFull(q))
		queueGet(q, &value);
		CHECK(value == 'a');
		queueFront(q, &value);
		CHECK(value == 'b');
		queueUp(q, 'o');
		CHECK(!queueEmpty(q))
		CHECK(queueFull(q))
		queueRemove(q);
		CHECK(!queueEmpty(q))
		CHECK(!queueFull(q))
		queueFront(q, &value);
		CHECK(value == 'c');
		queueUp(q, 'p');
		CHECK(!queueEmpty(q))
		CHECK(queueFull(q))
		queueUp(q, 'q');
		CHECK(!queueEmpty(q))
		CHECK(queueFull(q))

		for (int  i = 'c'; i <= 'p'; i++)
		{
			queueGet(q, &value);
			CHECK(value == i);
		}
		CHECK(queueEmpty(q))
		CHECK(!queueFull(q))

		queueUp(q, 'a');
		queueUp(q, 'b');
		CHECK(!queueEmpty(q))
		CHECK(!queueFull(q))
		queueGet(q, &value);
		CHECK(value == 'a');
		CHECK(!queueEmpty(q))
		CHECK(!queueFull(q))
		queueFront(q, &value);
		CHECK(value == 'b');
		CHECK(!queueEmpty(q))
		CHECK(!queueFull(q))
		queueUp(q, 'c');
		queueRemove(q);
		queueFront(q, &value);
		CHECK(value == 'c');
		CHECK(!queueEmpty(q))
		CHECK(!queueFull(q))

		puts("OK");
		break;
	}

	QUEUE_SIZE = 1;
	queueInit(q);
	printf ("\n[ADDITIONAL TEST3] expect errors: GET, REMOVE, FRONT, UP\n");
	// queue size 1
	while (1)
	{
		CHECK(queueEmpty(q))
		CHECK(queueFull(q))
		CHECK(queueEmpty(q))
		queueGet(q, &value);
		CHECK(queueEmpty(q))
		CHECK(queueFull(q))
		queueRemove(q);
		CHECK(queueFull(q))
		CHECK(queueEmpty(q))
		queueFront(q, &value);
		CHECK(queueEmpty(q))
		CHECK(queueFull(q))
		queueUp(q, 'X');
		CHECK(queueEmpty(q))
		CHECK(queueFull(q))

		puts("OK");
		break;
	}

	QUEUE_SIZE = MAX_QUEUE;
	queueInit(q);
	printf ("\n[ADDITIONAL TEST4] expect no errors\n");
	// queue size MAX_QUEUE
	while (1)
	{
		CHECK(!queueFull(q))
		CHECK(queueEmpty(q))
		for (int i = 'A'; i < 'A' + MAX_QUEUE - 1; i++)
		{
			queueUp(q, i);
		}
		CHECK(queueFull(q))
		CHECK(!queueEmpty(q))
		for (int i = 0; i < MAX_QUEUE - 1; i++)
		{
			queueRemove(q);
		}
		CHECK(!queueFull(q))
		CHECK(queueEmpty(q))

		for (int i = 'a'; i <= 'z'; i++)
		{
			queueUp(q, i);
			queueFront(q, &value);
			CHECK(value == 'a')
		}
		CHECK(!queueEmpty(q))
		CHECK(!queueFull(q))
		queueUp(q, 'A');
		CHECK(!queueEmpty(q))
		CHECK(!queueFull(q))
		queueGet(q, &value);
		CHECK(value == 'a');
		queueFront(q, &value);
		CHECK(value == 'b');
		queueUp(q, 'B');
		CHECK(!queueEmpty(q))
		CHECK(!queueFull(q))
		queueRemove(q);
		CHECK(!queueEmpty(q))
		CHECK(!queueFull(q))
		queueFront(q, &value);
		CHECK(value == 'c');
		queueUp(q, 'C');
		CHECK(!queueEmpty(q))
		CHECK(!queueFull(q))
		queueUp(q, 'D');
		CHECK(!queueEmpty(q))
		CHECK(!queueFull(q))

		for (int  i = 'c'; i <= 'z'; i++)
		{
			queueGet(q, &value);
			CHECK(value == i);
		}

		queueGet(q, &value);
		CHECK(value == 'A')
		queueGet(q, &value);
		CHECK(value == 'B')
		queueGet(q, &value);
		CHECK(value == 'C')
		queueGet(q, &value);
		CHECK(value == 'D')
		CHECK(queueEmpty(q))
		CHECK(!queueFull(q))

		puts("OK");
		break;
	}

	free(q);
#endif //ADDITIONAL_TESTS
	return 0;
}

