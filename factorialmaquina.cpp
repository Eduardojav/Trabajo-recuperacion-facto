include <iostream>


long long facto(long n){//funcion factorial recursiva con caso base 1! = 1
    if (n==1){
        return 1;
    }
    return n*facto(n-1);
}

long long combinacion(long a,long b){// funcion que retorna el resultado de una combinacion de b elementos en un conjunto de a elementos
    if (b==0){
        return 0;
    }
    // se halla que es mayor el numero de elementos o su diferencia con el total para evitar usar la funcion factorial con numeros muy grandes
    long mayor;
    if (b>=a-b){
        mayor=b;
    }else{
        mayor=a-b;
    }
    long long resultado=1;
    for(int c=mayor+1;c<=a;c++){//se calcula la el resultado de mayor*(mayor+1)*(mayor+2)*...*(a-1)*a
        resultado*=c;
    }
    return resultado/factorial(a-mayor);// se retorna el resultado obtenido de la simplificacion dividido entre el valor restante
}

int main()
{
    long contador;
    long long rAux;
    long long resultado=1;
    for(long a=1;a<=100;a++){//for para calcular las combinaciones que se pueden calcular con normalidad para conjuntos desde 1 hasta 100 elementos
        contador=1;
        resultado=1;
        aux=0;
        while(resultado>0){
            if (contador>a/2){//si se supera la barrera de la mitad y la combinacion no arroja un valor extraño se asume que
                              //se puede calcular todo tipo de combinaciones pues recordemos Combinacion(11,5)=Combinacion(11,6)
               cout << "para " << a << " se puede calcular ";
                resultado=-1;
            }else{
                resultado=combinacion(a,contador);
                if (resultado<rAux){// la variable rAux guarda el resultado anterior y si el resultado actual es menor al anterior
                                    //significa que se ha dado un overfloading y por lo tanto las combinaciones entre contador y
                                    //a-contador no se podran calcular incluyendo a estos dos
                   cout << "para " << a << " elementos no se puede calcular combinaciones de cantidad de elementos entre los numeros " << contador <<" y " << a-contador << "\n";
                    resultado=-1;
                }
                rAux=resultado;
            }
            contador++;
        }
    }
    return 0;
