#define IR_RECEIVE_PIN 2
#include "TinyIRReceiver.hpp"

#define pwmCoolpin 4
#define pwmWarmpin 1   // previous ( In the PCB ) 1 , 0 in the simulation   

#define  powerON 69 
#define  ReadMode 71             
#define  bright_up  9          // 25 in simulation         
#define  bright_dowm  7        // 22 in simulation       
#define  temp_up 25            // 21 in simulation
#define  temp_dowm 64          // 7 in simulation 
#define  brightness25 12
#define  brightness50 24
#define  brightness75 94
#define  Select_warm  8
#define  Select_Daylight 28
#define  Select_cool  90
#define  Timer10 66
#define  Timer30 82
#define  Timer60 74  


const byte REMOTE_ADDRESS = 0;
byte Timer_Value=0;
unsigned long timer_enabled_time=0;
bool TIMER_ENABLED = false;
bool isON = false;   

short int cool_value;
short int  warm_value;
float temp=0;
short int brightness=0;

volatile struct TinyIRReceiverCallbackDataStruct sCallbackData;

void setup() {
 
  initPCIInterruptForTinyReceiver();
  pinMode(pwmCoolpin,OUTPUT);
  pinMode(pwmWarmpin,OUTPUT);
  

  digitalWrite(pwmCoolpin,LOW);
  digitalWrite(pwmWarmpin,LOW);
}

void loop() {

  if(TIMER_ENABLED && (( millis()-timer_enabled_time ) >= Timer_Value*60*1000)){
    brightness=0;
    isON=false;
  }
  
  if(sCallbackData.justWritten){
    
    sCallbackData.justWritten=false;
    
    if(sCallbackData.Address==REMOTE_ADDRESS){

      if(sCallbackData.Command==powerON && sCallbackData.Flags==0){
        TIMER_ENABLED=false;

        if(brightness>0){
          brightness=0;
          isON=false;
          cool_value=(0.5+temp)*brightness;
          warm_value=(0.5-temp)*brightness;
              
          analogWrite(pwmWarmpin,warm_value);
          analogWrite(pwmCoolpin,cool_value);

          delay(500);
          
        }
        else{
          brightness=255;
          isON=true;

          cool_value=(0.5+temp)*brightness;
          warm_value=(0.5-temp)*brightness;
              
          analogWrite(pwmWarmpin,warm_value);
          analogWrite(pwmCoolpin,cool_value);

          delay(500);
          
        }
      }

      if(isON && sCallbackData.Command!=powerON){

        if(sCallbackData.Command==bright_up){
          if(brightness<255){
            brightness=brightness+17;
          }
        }
        else if(sCallbackData.Command==bright_dowm){
          if(brightness>0){
            brightness=brightness-17;
          }
        }
        else if(sCallbackData.Command==temp_up){
          if(temp<0.5){
            temp=temp+0.1;
          }
        }
        else if(sCallbackData.Command==temp_dowm){
          if(temp>-0.5){
            temp=temp-0.1;
          }
        }
        else if(sCallbackData.Command==brightness25 && sCallbackData.Flags==0){
          brightness=64;
        }
        else if(sCallbackData.Command==brightness50 && sCallbackData.Flags==0){
          brightness=127;
        }
        else if(sCallbackData.Command==brightness75 && sCallbackData.Flags==0){
          brightness=191;
        }
        else if(sCallbackData.Command==Select_warm && sCallbackData.Flags==0){
          temp=-0.5;
        }
        else if(sCallbackData.Command==Select_cool && sCallbackData.Flags==0){
          temp=0.5;
        }
        else if(sCallbackData.Command==Select_Daylight && sCallbackData.Flags==0){
          temp=0;
        }
        else if((sCallbackData.Command==Timer10 || sCallbackData.Command==Timer30 ||sCallbackData.Command==Timer60) && sCallbackData.Flags==0){
          TIMER_ENABLED=true;
          timer_enabled_time=millis();

          switch (sCallbackData.Command){
            case Timer10:
              Timer_Value=10;
              break;
            case Timer30:
              Timer_Value=30;
              break;
            case Timer60:
              Timer_Value=60;
              break;
          }
        }
        else if(sCallbackData.Command==ReadMode && sCallbackData.Flags==0){
          temp=-0.4;
          brightness=210;
        }

        cool_value=(0.5+temp)*brightness;
        warm_value=(0.5-temp)*brightness;
                  
        analogWrite(pwmWarmpin,warm_value);
        analogWrite(pwmCoolpin,cool_value);

        delay(10);

        
      }
      
      
    }
    
      
  }

  
  
}

void handleReceivedTinyIRData(uint8_t aAddress, uint8_t aCommand, uint8_t aFlags){
  sCallbackData.justWritten=true;
  sCallbackData.Address=aAddress;
  sCallbackData.Command=aCommand;
  sCallbackData.Flags=aFlags;
}
