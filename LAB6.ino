/*
  SD card read/write

 This example shows how to read and write data to and from an SD card file
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

#include <SPI.h>
#include <SD.h>

File myFile;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  SPI.setModule(0);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  // Imprimir el menú
  Serial.println("Menu:");
  Serial.println("1. Opción 1");
  Serial.println("2. Opción 2");
  Serial.println("3. Opción 3");


  Serial.println("Seleccione una opción (1-3):");

  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(12, OUTPUT);

  if (!SD.begin(12)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  
  
}


  void loop() {

  //MENÚ
  if (Serial.available() > 0) {
    char opcion = Serial.read();
    
    switch (opcion) {
      case '1': //OPCION 1
        Serial.println("Has seleccionado la Opción 1");
        // LEYENDO
          myFile = SD.open("a.txt");
          if (myFile) {
            Serial.println("a.txt:");
        
            // read from the file until there's nothing else in it:
            while (myFile.available()) {
              Serial.write(myFile.read());
          }
          // close the file:
          myFile.close();
        } else {
          // if the file didn't open, print an error:
          Serial.println("error opening test.txt");
        }
        break;
        
      case '2': //OPCION 2
        Serial.println("Has seleccionado la Opción 2");
           // LEYENDO

          myFile = SD.open("b.txt");
          if (myFile) {
            Serial.println("b.txt:");
        
            // read from the file until there's nothing else in it:
            while (myFile.available()) {
              Serial.write(myFile.read());
          }
          // close the file:
          myFile.close();
        } else {
          // if the file didn't open, print an error:
          Serial.println("error opening test.txt");
        }
        break;
        
      case '3'://OPCION 3
        Serial.println("Has seleccionado la Opción 3");
        //LEYENDO
          myFile = SD.open("c.txt");
          if (myFile) {
            Serial.println("c.txt:");
        
            // read from the file until there's nothing else in it:
            while (myFile.available()) {
              Serial.write(myFile.read());
          }
          // close the file:
          myFile.close();
        } else {
          // if the file didn't open, print an error:
          Serial.println("error opening test.txt");
        }
        break;
        
      default:
        break;
    }
  }
}
