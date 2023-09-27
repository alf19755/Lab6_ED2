#include <SPI.h>
#include <SD.h>

const int chipSelect = 12; // Pin CS para la tarjeta SD
File dataFile;

void setup() {
  Serial.begin(115200);
  pinMode(chipSelect, OUTPUT);

  if (!SD.begin(chipSelect)) {
    Serial.println("Error al inicializar la tarjeta SD");
    while (1);
  }

  Serial.println("Tarjeta SD inicializada");
}

void saveTextToSD() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Lee la línea de la terminal serial

    // Abre el archivo en modo de escritura
    dataFile = SD.open("data.txt", FILE_WRITE);

    if (dataFile) {
      // Escribe el texto en el archivo
      dataFile.println(input);
      dataFile.close();
      Serial.println("Imagen guardada en la tarjeta SD: " + input);
    } else {
      Serial.println("Error al abrir el archivo");
    }
  }
}

void loop() {
  // Llama a la rutina para guardar texto en SD
  saveTextToSD();

  // Tu otro código en loop() si lo tienes
}
