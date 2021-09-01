/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
Autor....: Euler da Silva Lima
Matrícula: 201911534
Inicio...: 18 de marco de 2021
Alteracao: 21 de marco de 2021
Nome.....: Principal.cpp
Funcao...: Exemplo do uso do comando fork em C++ com arvore geneologica.
=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

int main(){

pid_t filhoum; //Iniciando pid_t do primeiro filho.
pid_t filhodois; //Iniciando pid_t do segundo filho.
pid_t filhotres; //Iniciando pid_t do terceiro filho.
pid_t netoum; //Iniciando pid_t do neto do primeiro filho.
pid_t netodois; //Iniciando pid_t do neto do segundo filho.
pid_t bisneto; //Iniciando o pid_t do bisneto.

cout << "O pai nasce id: " << getpid() << endl; //A arvore eh iniciada e temos o id do processo;

sleep(22); //22 Segundos sao passados simulando os 22 anos, ou seja o processo Pai tem 22 anos.

filhoum = fork(); //O fork() da inicio ao processo filhoum que sera filho do pai (main).

if(filhoum == 0){ //Verificando se o processo foi iniciado corretamente (com o 0).

  cout << "Nasce o primeiro filho do pai aos seus 22 anos id: " << getpid() << endl;
  sleep(16); //16 segundos (anos) se passam, o pai tem 38 anos e tem seu primeiro neto.
  
  netoum = fork(); //Iniciando o processo do primeiro neto do pai apos o sleep.
  
    if(netoum == 0){ //Verificando se o processo foi iniciado corretamente (com o 0);
      cout << "Nasce o filho do primeiro filho (Primeiro neto) aos 38 anos do pai id: " << getpid() << endl;
    
      sleep(30); //30 segundos (anos) se passam, o pai tem 68 anos, tendo seu bisneto.
    
      bisneto = fork(); //Iniciando o processo do bisneto.
        if(bisneto == 0){ //Verificando se o processo foi iniciado corretamente (com o 0);;
    
        cout << "Nasce o bisneto (primeiro filho) aos 68 anos do pai id: " << getpid() << endl;
    
        sleep(12); //12 segundos (anos) se passam, e o bisneto morre.
            
        cout << "Bisneto morre aos 12" << endl;
    
        }else{ //fim do if do bisneto, voltamos para netoum.
          
          sleep(5); //Mais 5 segundos (anos) se passam, competando 35 anos do neto do (primeiro filho).
          
          cout << "Neto do primeiro filho morre aos 35 anos " << endl;
         }
      }else{ //fim do if do netoum, voltamos para filhoum.
        
        sleep(45); //Mais 45 segundos (anos) se passam, e o primeiro filho completa 61 anos.      
        
        cout << "Primeiro filho morre aos 61 anos " << endl;
        }
    }else{ //fim do if do primeiro filho, voltamos para o pai.
    
    sleep(3); //Mais 3 segundos (anos) se passam e o pai agora tem 25 anos, tendo o segundo filho.
    
    filhodois = fork(); //Iniciando o processo do segundo filho.
    
    
      if(filhodois == 0){ //Verificando se o processo foi iniciado corretamente (com o 0);
      
        cout << "Nasce o segundo filho aos 25 anos do pai id: " << getpid() << endl; 
        
        sleep(20); //Mais 20 segundos (anos) se passam, e agora o pai tem 45 anos tendo o segundo neto.
        
        netodois = fork(); //Iniciando o processo do segundo neto.              
                
        if(netodois == 0){ //Verificando se o processo foi iniciado corretamente (com o 0);
      
          cout << "Nasce o filho do segundo filho aos 45 anos do pai id: " << getpid() << endl;  
      
          sleep(33); //Passam 33 segundos (anos) e o segundo neto morre.
        
          cout << "O segundo neto morre aos 33 anos" << endl;   
                           
        }else{ //Fim do if do if do netodois, voltamos para o filhodois.
      
          sleep(35); //35 segundos (anos) se passam, e agora o filho tem 55 anos.
      
          cout << "O segundo filho morre 55 anos" << endl;
        }
      }else{ //fim do if do filhodois, voltamos para o pai.
      
        sleep(7); //Mais 7 segundos (anos) se passam e agora o pai tem 32 anos tendo o terceiro filho.
        
        filhotres = fork(); //Iniciamos o processo do terceiro filho.
        
        if(filhotres == 0){ //Verificando se o processo foi iniciado corretamente (com o 0);
        
        cout << "O pai tem o terceiro filho aos 32 anos id: " << getpid() << endl;
        
        sleep(55); //55 segundos (anos) se passam e o terceiro filho morre.
        
        cout << "O terceiro filho morre aos 55 anos" << endl;
        
        }else{ //Fim do if do terceiro filho, volta para o pai.
        
        sleep(58); //58 segundos (anos) se passam e o pai agora tem 90 anos.
        
        cout << "Pai morre aos 90" << endl;
        
      } //Fim else filhotres.
        
    } //Fim else filhodois.
    
  } //Fim do else filhoum.
  return 0;
} //Fim do main.

