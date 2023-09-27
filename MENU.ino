/*
PRELAB6

 */


void setup() {
  // Inicializar la comunicación serial a 9600 baudios
  Serial.begin(115200);
  
  // Esperar a que la comunicación serial se establezca
  while (!Serial) {
    ;
  }
  
  // Imprimir el menú
  Serial.println("Menu:");
  Serial.println("1. Opción 1");
  Serial.println("2. Opción 2");
  Serial.println("3. Opción 3");
  Serial.println("Seleccione una opción (1-3):");
}

void loop() {
  if (Serial.available() > 0) {
    char opcion = Serial.read();
    
    switch (opcion) {
      case '1':
        Serial.println("Has seleccionado la Opción 1");
        break;
        
      case '2':
        Serial.println("Has seleccionado la Opción 2");
        break;
        
      case '3':
        Serial.println("Has seleccionado la Opción 3");
        break;
        
      default:
        break;
    }
  }
}
