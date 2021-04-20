/* 

Programa Computacional 02


Ernesto Guadalupe Rincon Ortiz    1903481

Rafael Barboza Garza              1897498

Hiram Josué García Niño           1894398 

Jair Azael Sánchez Tovar          1918174 

*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Prototipo de la Funcion Validacion 

bool Validacion (char x [150]) ;

// Inicializando las Cadenas

char W[] = {'b' , 'g' , '\0'};
char W_Inversa[] = {'g' , 'b' , '\0'} ; 
char Matricula[] = {'1','8','9','7','4','9','8','\0'};
char j[] = {'r','a','f' ,'a','e','l', 'r','a','f' ,'a','e','l' ,'\0'} ;

int main (int argc, char const *argv[]) {


  system ("Color F0") ;

  // La Variable Cadena es para que el Usuario Ingrese la Cadena que Guste

  char Cadena[150] ;

  // La Variable Respuesta Sirve para Cuando le Salga la Pregunta "¿Quiere Ingresar Otra Cadena?"
  
  char Respuesta[2] ;
  

  do {
    
    // Esta Variable nos va Servir para la Validacion de la Respuesta
    
    bool Flag = false;
    
    // Se le pide al usuario que ingrese una cadena que luego el programa va a validar
    
    // Imprime Titulo y los Datos Necesarios para el Usuario
    
    std::cout << "\n\t\t\t\t\t\tPrograma Computacional 02\n\n" ;


    std::cout << "\n Nombre : rafael barboza garza" << "\n"
    << " Matricula : 1897498\n";

    printf ("\n El lenguaje independiente del contexto es: \n\n\tL = {i(w)^n i(w')^2n j%c|n>=1}\n\n", 253); 

    std::cout <<"\n Donde: \n\n\tw = Las iniciales del nombre escogido : "<< W ; 
     
    printf("\n\ti = Todos los d%cgitos de la matr%ccula : %s", 161, 161, (Matricula));
    
    
    std ::cout<< "\n\tw'= w inversa : " << W_Inversa
    << "\n\tj = El primer nombre de la persona : " << "rafael" << "\n" ;
    
    
    // Imprime "Ingrese una Cadena"

    std::cout << "\n Ingrese una Cadena : ";

    // Aqui Guarda la Cadena y le damos como limite 150 caracteres como se inicializó la variable , el '\n' sirve para cuando acabó de escribir la cadena presione un Enter

    std::cin.getline (Cadena , 150 , '\n');

    // La función del fflush, realiza la limpieza del buffer de entrada (stdin)

    fflush (stdin);

    //Se procede a validar si la cadena cumple con las condiciones específicadas
    
    Flag = Validacion (Cadena);


    //Ciclo para ver si se desea seguir ingresando más cadenas o no

    do {

      Flag = false ;
      
      printf ("\n\n %cDesea Ingresar Otra Cadena [Si - No]? : " , 168) ;
      std::cin >> Respuesta ;
      fflush (stdin) ;
      
      //Se crea una variable para que solo estas puedan ser las respuestas correctas
      
      bool Validacion_Respuesta = (strcmp ("No" , Respuesta)) && (strcmp ("NO" , Respuesta)) && (strcmp ("no" , Respuesta)) && (strcmp ("Si" , Respuesta)) && (strcmp ("SI" , Respuesta)) && (strcmp ("si" , Respuesta))  ;
      
      if (Validacion_Respuesta == 0) {

        Flag = true ;

      }
      
      //Si se ingresa una respuesta no válida el programa le pedirá al usuario que ingrese una cadena válida
      
      else {
        
        std::cout << "\n Error al Ingresar la Respuesta. Favor de Volver a Intentarlo , Presione Enter." << "\n\n " ;
        getch () ;

      }

      system ("cls") ;

    } while ( !Flag ) ;
    
    //En el caso de que el usuario ingrese que ya no quiere seguir utilizando sel programa se daldrá del ciclo, en el caso opuesto seguirá pidiendo y validando cadenas


  } while ((strcmp ("No" , Respuesta)) && (strcmp ("NO" , Respuesta)) && (strcmp ("no" , Respuesta))) ;  
  
  //Finalización del programa con un mensaje de despedida

  printf ("\n\n Gracias por Utilizar nuestro Programa, Tenga un Buen D%ca , Presione Enter Para Salir. :)\n\n " , 161) ;

  // Para que el Ejecutable no se Cierre
  
  getch () ;
  std::cout << std::endl ;
  return 0 ;

}

bool Validacion (char x[150]) {

  // Validacion de que no sea una Cadena Vacia

  if ( x[0] == '\0') {
  
    printf("\n Ingres%c una Cadena inv%clida. La Cadena es vac%ca.\n", 162, 160, 161);
    return 0;
  
  }


  // Validacion de que ingrese los caracteres mínimos en la cadena requerida (32 caracteres)

  bool Flag = true ;

  if ( strlen(x) < 32) {
    
    Flag= false ;
    
  }
  
  // Validacion de que ingrese su matricula al inicio

  for (size_t i = 0 ; i < strlen(Matricula)  ; i++) {

    if ( x[i] != Matricula[i]) {

      Flag = false;
      break;             
      
    }
  
  }

  // Validacion de iniciales del apellidos (bg) elevadas a la n (W^n) 

  unsigned short contador = 0 ;

  for (size_t i = 7 ; i < strlen(x) ; i++) {

    if (x[i] != W[0] && contador == 0){

      Flag = false ;
      break ;
      
    }

    if (x[i] == W[0] && x[i+1] == W[1]) {

      contador++ ;
      i++;
      
    }
    
    else if (contador != 0) {

      break;

    } 
  
  }

  //Validacion de que ponga la matricula por segunda ocasión
  
  unsigned short k = 0 ;
  
  for (size_t i = (7 + (2*contador)) ; i <= (13 + (2*contador))  ; i++) {


    if ( x[i] != Matricula[k] ) {

      Flag = false ;
      break ;             
      
    }
  
    k++;
    
  }

  // Validacion de iniciales del apellidos al revés (gb) elevadas a la n (W'^2n)

  unsigned short cont = 0 ;

  
  for (size_t i = (14 + (2*contador)) ; i < (14 + (2*contador) + (4*contador)) ; i++) { 
    

    if (x[i] == W_Inversa[0] && x[i+1] == W_Inversa[1]) {
      
      i++ ;
      cont++ ;
      
    } 
    
    else {

      Flag = false;
      break;

    }
    
    if (cont == 2*contador) {
      
      break;
    
    } 

  }


  //Validación para ingresar el nombre dos veces (j^2)

  unsigned short z = strlen(j) -1 ;

  for (size_t i = strlen(x) -1 ; i > (strlen(x) - strlen(j)) ; i--) {


    if ( x[i] != j[z]){

      Flag= false;
      break;

    }

    z--; 

  }

  // Impresion de si la cadena ingresada es valida o no 

  fflush(stdin);

  if (Flag){

    printf("\n\n La Cadena Ingresada es V%clida para el Alfabeto Dado \n",160);
    
  }
  
  else {

    printf("\n\n Cadena inv%clida\n" , 160);
  
  }

  return Flag;

}