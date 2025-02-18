#ifndef __GLOBAL_H
#define __GLOBAL_H

//#define MAX_GLOBALS 3

extern int MAX_GLOBALS;
extern const int ee_size;

//typedef float globaldata_t ;
//typedef int globaldata_t ;
#define  globaldata_t int
typedef struct __globals_
{
    char *name;
    globaldata_t value;  
    globaldata_t min_val;
    globaldata_t max_val;
    bool updated;
} global_t; 

extern global_t globals[];

int index(String);
void setup_globals(void);
void globals_to_eeprom(bool);
void globals_from_eeprom(void);
float read_flt(int, char **);


#endif