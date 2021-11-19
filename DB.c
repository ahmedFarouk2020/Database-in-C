/****************************************************/
/* Author:    Farouk                                 */
/* Date:      24th August 2021                       */
/* Version:   V01                                    */
/* File Name: DB.h                            */
/***************************************************/

#include "./search/search.h"
#include "./sort/sort.h"
#include "DB.h"

#include <stdlib.h>
#include <stdio.h>

database_t *db;  // global pointer to DB
static uint8_t size = 10; // DB occupied size



database_t* create_database (void) {
    static int key = 1;  // exist

    // key exist?  open the door (create database)
    if (key == 1)
    {
        db = (database_t*) calloc(15, sizeof(database_t));
        key = 0; // close door
        return db;
    }
    // key not exist -> NULL
    return NULL;
}



void init_database (database_t* ptr) {
    
    // first user
    ptr[0].PAN = 123456789;
    ptr[0].balance = 100.00;
    // second user
    ptr[1].PAN = 234567891;
    ptr[1].balance = 6000.00;
    // 3rd user
    ptr[2].PAN = 567891234;
    ptr[2].balance = 3250.25;
    // 4th user
    ptr[3].PAN = 456789123;
    ptr[3].balance = 1500.12;
    // 5th user
    ptr[4].PAN = 258649173;
    ptr[4].balance = 500.00;
    // 6th user
    ptr[5].PAN = 654823719;
    ptr[5].balance = 2100.00;
    // 7th user
    ptr[6].PAN = 971362485;
    ptr[6].balance = 00.00;
    // 8th user
    ptr[7].PAN = 793148625;
    ptr[7].balance = 1.00;
    // 9th user
    ptr[8].PAN = 123123456;
    ptr[8].balance = 10.12;
    // 10th user
    ptr[9].PAN = 456789321;
    ptr[9].balance = 0.55;
}



uint8_t Is_PAN_exist(int PAN) {
	
    // if not sorted? sort it
    if ( !(Is_sorted(db)) )
    {
        bubbleSort(db);
    }
    
    return binarySearch(db, PAN);
}



uint8_t insert_user(int PAN, float balance) {
	
    // check if the user already in database
    if ( Is_PAN_exist(PAN) != 255) {
		
        printf("User already exist\n");
        return 0; // exist (no insertion occurs)
    }
	
    static uint8_t total_size = 15;
	
    // array is full?
    if (size >= total_size)
    {
        // enlarge the array
        db = (database_t*)realloc(db, total_size+5);

        // data can't be realocated? (database if freed)
        if (db == NULL)
        {
            // start the process from beginning
            db = create_database();
            init_database(db);
            return 0; // can't add users anymore
        }
        
        // initialize database again
        init_database(db);

        // update total_size 
        total_size += 5;
    }
    // add user
    db[size].balance = balance;
    db[size].PAN = PAN;
	
    // increment the occupied size 
    size++ ;
    printf("successfully updated\n");
    return 1; // successfully updated
}



static void printArray(database_t* arr)
{
    printf("Array Elements:\n");
    for (int i = 0; i < size; i++)
    {
        printf("(");
        printf("%d", arr[i].PAN);
        printf(",");
        printf("%.2f", arr[i].balance);
        printf("),");
    }
    printf("\n");
}



/* the main function is for debugging purposes */
int main() {
    create_database();
    init_database(db);
    // printf("%d %f", db[5].PAN, db[5].balance);
    Is_sorted(db);
    // printArray(db);
    bubbleSort(db);
    // printArray(db);
    
    // int user_status = binarySearch(ptr, 123100000);
    // printf("%d\n", Is_PAN_exist(456789123));
    insert_user(234000891, 10000.00);
    insert_user(234000890, 10000.00);
    insert_user(234000895, 10000.00);
    insert_user(234000896, 10000.00);
    insert_user(234000897, 10000.00);
    insert_user(234000898, 10000.00);
    printArray(db);
    free(db); // segmentation fault
    return 0;
}