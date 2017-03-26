#include "Callback.hpp"
using namespace std;


int Callback (char * key, char * value, void * userdata)
{
    parseInfo_t* info = (parseInfo_t*)userdata; //info: uncion que contiene el input del usuario
    KEY* pKey;
    string opcion;
    string error = "-error";
    
    //Arreglo con las posibles keys y las correspondientes rutinas de verificacion del valor de las mismas
    KEY arr[] = {
        {"-modo", rutModo},
        {"-robots", rutRobots},
        {"-heigh", rutHeigh},
        {"-width", rutWidth},
        {"-error", rutError} //en caso de que se haya ingresado una key invalida
    };
    
    opcion = key;
    pKey= arr;
    
    //Recorre el arreglo de estructuras buscando con cual coincide la opcion ingresada
    while ((pKey -> key != opcion) && (pKey -> key != error))
        ++pKey;
    
    return ((*pKey -> pRut )(value, info));//Ejecuta rutina de accion corresondiente y devuelve lo mismo
}



// rutinas para cada key

/* rutModo
 *
 * funcion que analiza si el valor de la key -Modo es valido, es decir, si es
 * 1 o 2, y lo guarda en la estructura de comunciacion con el main, borrando 
 * todos los otros parametros de le estructura
 *
 * Recibe:
 * value: puntero a string a analizar
 * parseInfo_t info: estructura para almacenar datos
 *
 * Devuelve:
 * true (1) si el valor es valido
 * falso (0) si el valor es invalido o si ya se habia establecido un modo
 * anteriormente
 */
int rutType (string value, parseInfo_t* info)
{
    
    if(!(info->modo))   //si todavia no se selecciono un modo
    {
        if (value == "1") //Si el modo seleccionado es 1
        {
            info->modo = MODO1;  //indicar el modo seleccionado
            
            info->modo1.robots = 0; //resetea todos los parametros del triangulo
            info->modo1.Width= 0;
            info->modo1.Heigh = 0;
            
            return true;
        }
        else if (value== "2")
        {
            info->modo = MODO2;  //indicar el modo seleccionado
            
            info->modo2.Heigh = 0; //resetea todos los parametros del triangulo
            info->modo2.Width = 0;
 
            
            return true;
        }
        
        else
        {
            fprintf(stderr,"Error: valor de -Modo %s es incorrecto.\n\
                    Valores posibles: 1 o 2", value.c_str());
            return false;
        }
    }
    
    else
    {
        fprintf(stderr,"Error: -Modo invocado mas de una vez\n");
        return false;
    }
}


