#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void printsec(char *pX,int *_pL,int *_pD,int i, int j, int _n);

//EN ESTA SECCIÖN DE CONSTRUYE LA CLASE
class MatrizL{
      private:
              char *pX, *pY;
			  int *pL, *pD;
			  int m,n;
              
      public:
             MatrizL(char &_pX,char &_pY,int &_pL,int &_pD,int _m,int _n);
             void L(char &_pX,char &_pY,int &_pL,int &_pD,int _m,int _n);
             void Procedencia(char &_pX,char &_pY,int &_pL,int &_pD,int _m,int _n);
             
            };
            
//EN ESTE PASO SE INICIALIZA LA CLASE             
MatrizL::MatrizL(char &_pX,char &_pY,int &_pL,int &_pD,int _m,int _n){
	
                       pX =&_pX;
                       pY =&_pY;
                       pL =&_pL;
                       pD =&_pD;
                       m=_m;
                       n=_n;
                                };
                       
//SE PROCEDE A DEFINIR LOS MÉTODOS INCLUIDOS EN LA CLASE LCS:

//METODO L

void MatrizL::L(char &_pX,char &_pY,int &_pL,int &_pD,int _m,int _n){
	
   	int i, j;
	
	
	for (i=0;i<=_m;i++){
		
		*(&_pL+i*(_n+1)+0)=0;//SE LLENA LA COLUMNA CERO CON CEROS
		
			}
	
	for (j=0;j<=_n;j++){
		
		*(&_pL+0*(_n+1)+j)=0;//SE LLENA LA FILA CERO CON CEROS
					
		}
	
	
	for (i=1;i<=_m;i++){
  	
  		for (j=1;j<=_n;j++){
  		
  		//SI LAS CADENAS Char_A(i)==Char_B(j) ENTONCES L(i,j)=L(i-1,j-1)+1. EN EL PROGRAMA DEL PROFESOR HAY UN PEQUEÑO ERROR, LOS CICLOS NO ESTAN REVISANDO
  		//DE FORMA COMPLETA TODAS LAS POSICIONES DE LAS CADENAS, POR TAL MOTIVO TUVE QUE RESTAR 1 A LOS INDICES i & j, PARA QUE ARRANCARAN EN LAS POSICIONES CERO.
  		
		  if (*(&_pX+i-1)==*(&_pY+j-1)){
  			
  			*(&_pL+i*(_n+1)+j)=*(&_pL+(i-1)*(_n+1)+(j-1))+1;
  		  
			}
  				
			  
		//DE LO CONTRARIO SI L(i-1,j)>=L(i,j-1) ENTONCES L(i,j)=L(i-1,j)
			  else if (*(&_pL+(i-1)*(_n+1)+j)>=*(&_pL+(i)*(_n+1)+(j-1))){
			  				  		
			  		*(&_pL+(i)*(_n+1)+j)=*(&_pL+(i-1)*(_n+1)+j);	  						
			  							  
					}
			  		 		
		//DE LO CONTRARIO L(i,j)=L(i,j-1)
					  else {
					  	
					  	*(&_pL+(i)*(_n+1)+j)=*(&_pL+(i)*(_n+1)+(j-1));
					  					  		  	
					}
					  	
	  		}
  		}
    
	}
     
//METODO Procedencia

 void MatrizL::Procedencia(char &_pX,char &_pY,int &_pL,int &_pD,int _m,int _n){
 	int i, j;
	
	for (i=0;i<=_m;i++){
		
		*(&_pL+i*(_n+1)+0)=0;//SE LLENA LA COLUMNA CERO CON CEROS
		
			}
	
	for (j=0;j<=_n;j++){
		
		*(&_pL+0*(_n+1)+j)=0;//SE LLENA LA FILA CERO CON CEROS
		
		}
	
	
	for (i=1;i<=_m;i++){
  	
  		for (j=1;j<=_n;j++){
  		
  		//SI LAS CADENAS Char_A(i)==Char_B(j) ENTONCES L(i,j)=L(i-1,j-1)+1. EN EL PROGRAMA DEL PROFESOR HAY UN PEQUEÑO ERROR, LOS CICLOS NO ESTAN REVISANDO
		//DE FORMA COMPLETA TODAS LAS POSICIONES DE LAS CADENAS, POR TAL MOTIVO TUVE QUE RESTAR 1 A LOS INDICES i & j, PARA QUE ARRANCARAN EN LAS POSICIONES CERO.
  		if (*(&_pX+i-1)==*(&_pY+j-1)){
  			
  			*(&_pD+i*(_n)+j)=10;
  		  
			}
  			  					  
		//DE LO CONTRARIO SI L(i-1,j)>=L(i,j-1) ENTONCES L(i,j)=L(i-1,j)
			  else if (*(&_pL+(i-1)*(_n+1)+j)>=*(&_pL+(i)*(_n+1)+(j-1))){
			  		
			  		*(&_pD+i*(_n)+j)=20;
			  				  		
					}
			  		 		  		
		//DE LO CONTRARIO L(i,j)=L(i,j-1)
					  else {
					  					  		  	
					  	*(&_pD+i*(_n)+j)=30;
						
					}
					  	
	  		}
  		}
    
	}
     


	
//PROGRAMA PRINCIPAL	
     
    int main(){
    
    /**var char Char_A: Esta variable tipo arreglo char sirve para almacenar una cadena de caracteres #1 con una longitud máxima igual a 256 */ 	
  	char Char_A[256];
  	
  	/** La variable Char_B, tipo char, es un arreglo que sirve para almacenar los caracteres de una cadena #2, con una longitud máxima igual a 256 */
    char Char_B[256];
    
    /** Esta variable se usa para barrer las filas de la matriz L y P (Procedencia) */
  	int i;
  	
  	/** La variable entera j se usa para barrer las columnas de las matrices L y de P (Procedencia) */
    int j;
    
    /** _m es una variable tipo entero que define el número de filas de las matrices L y P (Procedencia) */
    int _m;
    
    /** _n es una variable tipp entero que define el número de columnas de las matrices L y P (Procedencia) */
    int _n;
  
   	printf ("Ingrese la primera cadena: ");
  	gets (Char_A);// EN ESTA VARIABLE SE ALMACENA LA PRIMERA CADENA
  	printf ("Ingrese la segunda cadena: ");
  	gets (Char_B);//EN ESTA VARIABLE SE ALMACENA LA SEGUNDA CADENA
  	_m=(int)strlen(Char_A);//ACA SE CALCULA LA LONGITUD DE LA PRIMERA CADENA Y SE ALMACENA EN LA VARIABLE "m"
  	_n=(int)strlen(Char_B);//ACA SE CALCULA LA LONGITUD DE LA SEGUNDA CADENA Y SE ALMACENA EL RESULTADO EN LA VARIABLE "n"
  	
  	/** La matriz L de tipo entero es una variable bidimensional que se emplea para almacenar las longitudes de la subcadena común existentes entre las cadenas a comparar */
  	int L[_m+1][_n+1];
  	
   /** La matriz D tipo entero sirve para almacenar la información de procedencia, P: D[i,j]=10, equivale a "D" */
    int D[_m][_n];
  
  /** Esta variable es un puntero tipo char que apunta a la dirección inicial del arreglo Char_A */
   	char *_pX;
   	
 /** Esta variable es un puntero tipo char que apunta a la dirección inicial del arreglo Char_B */
    char *_pY;
    
 /** La variable ilustrada es un puntero tipo entero que apunta a la primera direcciòn de memoria de la matriz L */
    int *_pL;
    
 /** La variable ilustrada es un puntero tipo entero que apunta a la primera direcciòn de memoria de la matriz de procedencia P */
    int *_pD;
  
  	_pX=&Char_A[0];//EN EL PUNTERO pX SE ALMACENA LA DIRECCION DE MEMORIA DONDE INICIA EL PRIMER ELEMENTO DEL VECTOR Char_A
  	_pY=&Char_B[0];//EN EL PUNTERO pY SE ALMACENA LA DIRECCION DE MEMORIA DONDE INICIA EL PRIMER ELEMENTO DEL VECTOR Char_B
 	_pL=&L[0][0];
  	_pD=&D[0][0];// EN EL PUNTERO plP SE ALMACENA LA DIRECCION DE MEMORIA DONDE INICIA EL PRIMER ELEMENTO DE LA MATRIZ lP (ESTA MATRIZ ALMACENTARÁ LOS VALORES DE
  	//L(i,j) Y DE PROCEDENCIA. POR EL MOMENTO ESTA MATRIZ SOLO ALMACENA L.
	
	         
    //SE CREA EL OBJETO R DE CLASE "Mat_L"
                  
	MatrizL R=MatrizL(*_pX,*_pY,*_pL,*_pD,_m,_n);
         
    //Y LUEGO SE PROCEDE A APLICAR LOS MÉTODOS SOBRE EL OBJETO R:
    
    ///////////////////////////////////////////////////////////////////////////////
    
    R.L(*_pX,*_pY,*_pL,*_pD,_m,_n);
    
    R.Procedencia(*_pX,*_pY,*_pL,*_pD,_m,_n);
         
    ///////////////////////////////////////////////////////////////////////////////

    printsec(_pX,_pL,_pD,_m,_n,_n);
	
	//for (i=0;i<=_m;i++){
//  	
//  		for (j=0;j<=_n;j++){
//  		
//  		printf("L[%d,%d]=%d \n",i,j,L[i][j]);//DESPUES DE EJECUTARSE LA FUNCION, SE IMPRIME LA MATRIZ L PARA VERIFICAR SU CONTENIDO
//  		
//		  }
//  	}     
								
         	
        system("pause");
			
	}
         
/** void printsec
    * \brief La función printsec sirve para imprimir en pantalla la subcadena común de máxima longitud existente en dos cadenas de longitudes arbitrarias
    */
		 
void printsec(char *_pX,int *_pL,int *_pD,int i, int j,int _n){
	
	if (i==0 || j==0) { 
	return;
}
	
	if 	(*(_pD+i*(_n)+j)==10) { 
	
	printsec(_pX,_pL,_pD,i-1,j-1,_n);
	
	printf("%c \n",*(_pX+i-1));
	
	}
	
	else {
		
		if (*(_pD+i*(_n)+j)==30) {
			printsec(_pX,_pL,_pD,i,j-1,_n);		
		}
		
		else {
			
			printsec(_pX,_pL,_pD,i-1,j,_n);
			
		}
	}
	
	
	
	
	
}   
        
         
             
