
#include <Arduino.h>
//#include <iostream>
#include <string.h>
#include <EEPROM.h>
#include "Cmd.h"
#include "globals.h"

const int ee_size = MAX_GLOBALS*sizeof(int)+2;

int index(String arg){
  int index;
  bool ok = false;
     
  for(index = 0; index < MAX_GLOBALS; index++){
    if( strcmp(arg.c_str() , globals[index].name) == 0){
      ok = true;
      break;
    }
  } 
  int retval = -1;
  if(ok) retval =index; 
  return retval;
}


void globals_from_eeprom(void){
  for(int i=0; i< MAX_GLOBALS; i++){
    if(globals[i].min_val != globals[i].max_val ){
      EEPROM.get(i*sizeof( globals[i].value), globals[i].value);
      globals[i].updated = true;
    }
  }
  cmdGetStream()->println("Ok");    
}

void globals_to_eeprom(void){ 
  for(int i=0; i< MAX_GLOBALS; i++){
    if(globals[i].min_val != globals[i].max_val ){
      EEPROM.put(i*sizeof( globals[i].value), globals[i].value);
    }
  }
  cmdGetStream()->println("Ok"); 
}

void _list_gloabals(int nargs, char **args){
  for(int i=0; i< MAX_GLOBALS; i++){
      cmdGetStream()->print(globals[i].name);
      cmdGetStream()->print(" = ");
      cmdGetStream()->print( globals[i].value);
      cmdGetStream()->print(" [");
      cmdGetStream()->print( globals[i].min_val);
      cmdGetStream()->print(" , ");
      cmdGetStream()->print( globals[i].max_val);
      cmdGetStream()->print("] ");
      cmdGetStream()->println( globals[i].updated);
  }
}



void _glob_reg(int nargs, char **args){
  int iter;
  iter = index(args[0]); // args[0] = name of command 
  if((nargs > 1) && (iter < MAX_GLOBALS)){
    globaldata_t tmp = (globaldata_t)parse_float(--nargs, ++args);
    if(tmp < globals[iter].min_val) tmp = globals[iter].min_val;
    if(tmp > globals[iter].max_val) tmp = globals[iter].max_val;
    if(globals[iter].min_val != globals[iter].max_val ){ //not read only
         globals[iter].value = tmp; 
         globals[iter].updated = true;
    } 
  }
  cmdGetStream()->println(globals[iter].value);
}

void addGlobals(void){
  cmdGetStream()->println("Adding globals...");
  for(int index = 0; index < MAX_GLOBALS; index++){
    cmdAdd(globals[index].name,_glob_reg);
    //cmdGetStream()->println(globals[index].name);
  }
}

void setup_globals(void){
   addGlobals();
   cmdAdd("regs", _list_gloabals); 
   cmdAdd("toee", [](int argcnt, char**){globals_to_eeprom();});
   cmdAdd("fromee", [](int argcnt, char**){globals_from_eeprom();});
}