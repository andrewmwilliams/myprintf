//Author: Andrew Williams awilli64@binghamton.edu

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_manip(char * str, char * substr) {
  //error check arguments (we would also like to make sure arguments are null terminated,
  //but this is apparently impossible)
  if (str == NULL) {
    printf("First argument not allowed to be null.\n");
    return -1;
  }
  if (substr == NULL) {
    printf("Second argument not allowed to be null.\n");
    return -1;
  }

  printf("str %s\n", str);

  int strSize = strlen(str);
  int substrSize = strlen(substr);
  char newstr[2 * strSize + 1];
  int newstrSize = 2 * strSize;
  strcpy(newstr, str);

  int index = strSize - 1;
  
  printf("strSize = %d\nnewstrSize = %d\n", strSize, newstrSize);

  //copy str into second half of newstr, but reversed
  while (index >= 0) {
    newstr[newstrSize - index - 1] = str[index];
    --index;
  }
  //convert all upper case characters in newstr to lowercase
  index = 0;
  while (index < strlen(newstr)) {
    if (newstr[index] >= 'A' && newstr[index] <= 'Z')
      newstr[index] = tolower(newstr[index]);
    ++index;
  }
  newstr[2 * strSize] = '\0';

  printf("newstr %s\n", newstr);

  printf("substr %s\n", substr);
	 
  int numOcc = 0;
  int trav = 0;
  int subTrav = 0;
  bool match = true;

  //convert substr to lower case to make pattern match easier
  for (index = 0; index < substrSize; ++index) {
    if (substr[index] >= 'A' && substr[index] <= 'Z')
      substr[index] = tolower(substr[index]);
  }


  //move through newstr and find all occurences of substr
  while (trav < newstrSize) {
    subTrav = 0;
    if (newstr[trav] == substr[subTrav]) {
      match = true;
      while (subTrav < substrSize && match) {
	if (newstr[trav + subTrav] != substr[subTrav])
	  match = false;
	++subTrav;
      }
      if (match)
	++numOcc;
    }
    ++trav;
  }

  printf("occurences %d\n", numOcc);

  return 0;
}
