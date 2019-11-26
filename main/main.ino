#include <Arduino_FreeRTOS.h>
/*  A0 -> 2 // SENSOR 1
 *  A1 -> 3 // SENSOR 2
 *  6 -> 7
 *  5 -> 1
 */
void TarefaPeriodicaM1( void *pvParameters );
void TarefaPeriodicaM2( void *pvParameters );
void TarefaPeriodica1( void *pvParameters );

int sensor1,sensor2;

void setup(){
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
   xTaskCreate(
    TarefaPeriodicaM1
    ,  (const portCHAR *)"TarefaP"   // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  3
    ,  NULL );

       xTaskCreate(
    TarefaPeriodicaM2
    ,  (const portCHAR *)"TarefaP"   // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  3
    ,  NULL );


    xTaskCreate(
    TarefaPeriodica1
    ,  (const portCHAR *)"TarefaP"   // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  3
    ,  NULL );

    vTaskStartScheduler();     

}

void loop(){
  // put your main code here, to run repeatedly:
}

void  TarefaPeriodicaM1 (void *pvParameters){
  TickType_t proxTime;
  int x = 450;
  proxTime = xTaskGetTickCount();
  while(1){
    if (sensor1 > x){
      analogWrite(5, 180);
    }
    else{
      analogWrite(5, 100);
    }
    //Tarefe periódica com período de 500ms 
    vTaskDelayUntil(&proxTime, (10/portTICK_PERIOD_MS)); 
  }  
}

void  TarefaPeriodicaM2 (void *pvParameters){
  TickType_t proxTime;
  int x = 450;
  proxTime = xTaskGetTickCount();
  while(1){
    if (sensor2 > x){
      analogWrite(6, 180);
    }
    else{
      analogWrite(6, 100);
    }
    //Tarefe periódica com período de 500ms 
    vTaskDelayUntil(&proxTime, (10/portTICK_PERIOD_MS)); 
  }  
}

void  TarefaPeriodica1 (void *pvParameters){


  TickType_t proxTime;

  proxTime = xTaskGetTickCount();
  
  while(1){

    //Implementar a lógica da tarefa
    Serial.print("S1 :");
    Serial.print(analogRead(A0));
    sensor1 = analogRead(A0);
    Serial.print("\tS2 :");
    sensor2 = analogRead(A1);
    Serial.println(sensor2);
    
  
              //Tarefe periódica com período de 500ms 
    vTaskDelayUntil(&proxTime, (10/portTICK_PERIOD_MS)); 
  }  
}
