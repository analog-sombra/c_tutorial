
//for "Earth"
//String literals are stored as an array of characters
//\0 si indicates the end of the string
//Tatal 6 bytes of read_only memory is allocated to the above string literal
//"\0" character must not be confused with '0; character. Both have differeent ASCii codes. '\0' has the code 0 while "0" has the code 48
//inc c compiler treats a string literal as a pointer to the first character.
//so to the printf or scanf, we are passing a pointer to the first character of a string literal.
// Both printf and scanf function expects a character pointer (cahr*) as an argument.
 