#include <SD.h>          
#include <TMRpcm.h>     

#define SD_CSN_PIN 10   
#define SPEAKER_PIN 9   
TMRpcm tmrpcm;         

void setup(){
  Serial.begin(9600);

 
  if (!SD.begin(SD_CSN_PIN)) {
    Serial.println("SD fail");
    return;
  }

  
  tmrpcm.speakerPin = SPEAKER_PIN;

  
  tmrpcm.setVolume(6); 

void loop(){
  
  tmrpcm.play("test.wav"); 

  
  while(tmrpcm.isPlaying()) {
    delay(100);
  }

  
  delay(5000);
}
