#ifndef AWILLI64_HW1_H
#define AWILLI64_HW1_H

#define printf(...) myprintf(__VA_ARGS__)

#define MYMSG(formatString, ...) printf("Original message --> %s:%d: " formatString, __FILE__, __LINE__, ##__VA_ARGS__) 

#endif
