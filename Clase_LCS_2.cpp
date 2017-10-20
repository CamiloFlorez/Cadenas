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
     	
  	char Char_A[256];char Char_B[256];//ACA DEFINO DOS VECTORES DE 256 ELEMENTOS PARA CARGAR LAS CADENAS A COMPARAR
  	int i,j,_m,_n;
  
   	printf ("Ingrese la primera cadena: ");
  	gets (Char_A);// EN ESTA VARIABLE SE ALMACENA LA PRIMERA CADENA
  	printf ("Ingrese la segunda cadena: ");
  	gets (Char_B);//EN ESTA VARIABLE SE ALMACENA LA SEGUNDA CADENA
  	_m=(int)strlen(Char_A);//ACA SE CALCULA LA LONGITUD DE LA PRIMERA CADENA Y SE ALMACENA EN LA VARIABLE "m"
  	_n=(int)strlen(Char_B);//ACA SE CALCULA LA LONGITUD DE LA SEGUNDA CADENA Y SE ALMACENA EL RESULTADO EN LA VARIABLE "n"
  	
  	int L[_m+1][_n+1];//ACA SE CREA UNA MATRIZ CON m+1 FILAS Y n+1 COLUMNAS
  	int D[_m][_n];
  
  	char *_pX; char *_pY; int *_pL; int *_pD;//ACÁ SE DEFINEN LOS PUNTEROS QUE SERVIRAN PARA RECORRER LOS 2 STRINGS ALMACENADOS EN Char_A y Char_B, Y UN PUNTERO PARA ALMACENAR
  	//LAS LONGITUDES EN LA MATRIZ L(i,j)
  
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
        
         
             
