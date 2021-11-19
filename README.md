# Database-using-C
### This is a database written in C with different utilities
1. customize your own data unit
```c
/* basic unit of database */
typedef struct database
{
	/* Put your data here */
	/***** Example *****/
		int PAN;        // specific number for each card
		float balance;  // money in the card
	
}database_t;
```
2. Hook function to initialize the database
```c
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
}
```
3. Insert into database
4. High performace (sorting data continously using sort module functions)
### Future Improvements
1. Multiple Database instances at same time
2. Optimize memory consumption

