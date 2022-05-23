//Static memory allocaton
// Memory alllocatied during compile time is called static memory.
//The memory allocated is fixed and cannot ve increased or decreased during run time.

//Problems faced in static memory allocation

//1. if you are alloating memory for an array during compile time then you have to fix the size at the time of declaration. Size is fixed and user cannot increase or decrease the size of the array at run time.

//2. if the values stored byt he user in the array at run time is less then the size specified then there will be wastage of memory. 

//3. if the values stored by the user in the array at run time is more then the size specified then the program may crash or misbehave.


//dynamic memory allocation

//the process of allocating memory at the time of execution is called dynamic memory allocation.
//built in function malloc() calloc() and realloc() are used to allocate memory at the time of execution.
//and free() is used to free the memory.

//Heap is the segment of memory where dynamic memory allocatio takes place

//unlike stack where memory is allocated or deallated in a defined order, heap is an area of memory where memory is allocated or deallocated with any order or randomly.

//There are certain build-in function that can help in allocating or deallocation some memory space run time.

//Note
//Pointers play an important role in dynamic memory allocation.
//allocated memory can only be accessed through pointers.