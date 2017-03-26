#ifndef Callback_hpp
#define Callback_hpp

#include <string>
#include <cstring>
using namespace std;

#define ERROR 0
#define NOERROR 1
enum modo{NOMODE, MODO1, MODO2};

typedef struct{
    int modo; //indica el modo seleccionado
    unsigned int robots; //indica la cantidad de robots que limpiaran el piso
    unsigned int Width; //indica la longitud del piso
    unsigned int Heigh; //indica el alto del piso
}parseModo1_t; //estructura del modo1

typedef struct{
    int modo; //indica el modo seleccionado
    unsigned int Width; //indica la longitud del piso
    unsigned int Heigh; //indica el alto del piso
}parseModo2_t; //estructura del modo2



typedef union{
    parseModo1_t modo1;
    parseModo2_t modo2;
    int modo;   //permite acceder al modo sin usar un tipo de estructura especifica
}parseInfo_t;   //union usada para intercambiar datos entre el callback y el main


typedef struct
{
    string  key;
    int (*pRut) ( string value, parseInfo_t *info);
} KEY;

int Callback (char * key, char * value, void * userdata);

int rutModo (string value, parseInfo_t * info);
int rutRobots (string value, parseInfo_t *info);
int rutWidth (string value, parseInfo_t * info);
int rutHeigh (string value, parseInfo_t * info);
int rutError (string value, parseInfo_t * info);

int rutValidacion (string value);
int rutValidacionInts(string value);






#endif /* Callback_hpp */
