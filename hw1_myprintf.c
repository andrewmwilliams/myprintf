#include <stdio.h>
#include <stdarg.h>

int myprintf(const char * format, ...) {
  va_list ap;
  const char *p; 
  char *sval;
  int ival;
  char cval;
  int charCount = 0;

  va_start(ap, format);

  for (p = format; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      ++charCount;
      continue;
    }
    switch (*++p) {
    case 'c':
      cval = va_arg(ap, int);
      charCount += printf("%c", cval);
      break;
    case 'd':
      ival = va_arg(ap, int);
      charCount += printf("%d", ival);
      break;
    case 's':
      for (sval = va_arg(ap, char *); *sval != '\0'; sval++) {
	charCount++;
	putchar(*sval);
      }
      break;
    default:
      putchar(*p);
      break;
    }
  }
  
  printf("\nArgument list:\n");
  va_start(ap, format);
  for (p = format; *p; p++) {
    if (*p != '%') continue;

    switch (*++p) {
    case 'c':
      cval = va_arg(ap, int);
      printf("Char-->%c\n", cval);
      break;
    case 'd':
      ival = va_arg(ap, int);
      printf("Integer-->%d\n", ival);
      break;
    case 's':
      printf("String-->");
      for (sval = va_arg(ap, char *); *sval; sval++) {
	putchar(*sval);
      }
      printf("\n");
      break;
    }
  }

  va_end(ap);

  return charCount;
}
