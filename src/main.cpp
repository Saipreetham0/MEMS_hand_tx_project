#include <Arduino.h>

// #include <SPI.h>
// #include <nRF24L01.h>
// #include <RF24.h>

// #define CE_PIN 26
// #define CSN_PIN 27

// RF24 radio(CE_PIN, CSN_PIN);
// const byte address[6] = "00001"; // Address for communication

// void setup() {
//   Serial.begin(115200);
//   radio.begin();
//   radio.openReadingPipe(0, address);
//   radio.setPALevel(RF24_PA_LOW);
//   radio.startListening(); // Set as receiver
//   Serial.println("Listening for messages...");
// }

// void loop() {
//   if (radio.available()) {
//     char text[32] = {0};
//     radio.read(&text, sizeof(text)); // Receive data
//     Serial.print("Received message: ");
//     Serial.println(text);
//   }
// }


// #include <SPI.h>
// #include <nRF24L01.h>
// #include <RF24.h>
// #include <Wire.h>
// #include <Adafruit_ADXL345_U.h> // Include the ADXL345 library

// #define CE_PIN 9
// #define CSN_PIN 10

// // Hardware configuration
// RF24 radio(CE_PIN, CSN_PIN); // Set up nRF24L01 radio on SPI bus plus pins 9 & 10
// Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

// #define TX_LED 3

// const byte Address[6] = "00001";
// int Pot_Val_Y = 0, Pot_Val_X = 0, Up_key = 0, Dn_key = 0, Left_key = 0, Right_key = 0;
// unsigned char Tx_command = 0, Speed_index = 0;
// unsigned char Tx_Array[2];

// void setup() {
//   Serial.begin(115200);
//   pinMode(TX_LED, OUTPUT);

//   // Initialize RF24 module
//   if (!radio.begin()) {
//     Serial.println("NRF24L01 initialization failed");
//     while (1);
//   }
//   radio.openWritingPipe(Address);
//   radio.setPALevel(RF24_PA_MAX);
//   radio.stopListening();

//   // Send initial command to ensure setup
//   radio.write(&Tx_command, sizeof(Tx_command));

//   // Initialize the ADXL345
//   if (!accel.begin()) {
//     Serial.println("ADXL345 connection failed");
//     while (1);
//   }
//   Serial.println("ADXL345 connected");

//   Tx_Array[0] = 0;
//   Tx_Array[1] = 0;
// }

// void loop() {
//   // Fetch accelerometer data
//   sensors_event_t event;
//   accel.getEvent(&event);

//   float ax = event.acceleration.x;
//   float ay = event.acceleration.y;
//   float az = event.acceleration.z;

//   // Determine direction and speed based on accelerometer values
//   if ((ay <= -4.0) || (ay >= 4.0)) {
//     if ((ax >= -4.0) || (ax <= 4.0)) {
//       if (ay <= -4.0) {
//         Tx_command = 1; // Forward
//         Speed_index = ((ay + 4.0) / -2.0) + 1;
//         if (Speed_index > 5) Speed_index = 5;
//       } else if (ay >= 4.0) {
//         Tx_command = 2; // Backward
//         Speed_index = ((ay - 4.0) / 2.0) + 1;
//         if (Speed_index > 5) Speed_index = 5;
//       }
//     } else {
//       Tx_command = 0;
//       Speed_index = 0;
//     }
//   } else if ((ax <= -4.0) || (ax >= 4.0)) {
//     if ((ay >= -4.0) || (ay <= 4.0)) {
//       if (ax <= -4.0) {
//         Tx_command = 4; // Right
//         Speed_index = ((ax + 4.0) / -2.0) + 1;
//         if (Speed_index > 5) Speed_index = 5;
//       } else if (ax >= 4.0) {
//         Tx_command = 3; // Left
//         Speed_index = ((ax - 4.0) / 2.0) + 1;
//         if (Speed_index > 5) Speed_index = 5;
//       }
//     } else {
//       Tx_command = 0;
//       Speed_index = 0;
//     }
//   } else {
//     Tx_command = 0;
//     Speed_index = 0;
//   }

//   Serial.print("Command: ");
//   Serial.print(Tx_command);
//   Serial.print(" , Speed Index: ");
//   Serial.println(Speed_index);

//   // Transmit data and control LED
//   Tx_Array[0] = Tx_command;
//   Tx_Array[1] = Speed_index;

//   if (radio.write(&Tx_Array, 2)) {
//     digitalWrite(TX_LED, HIGH); // Turn on LED when data is transmitted
//   } else {
//     digitalWrite(TX_LED, LOW); // Turn off LED if transmission fails
//   }

//   delay(100); // Add a small delay to avoid spamming
// }



// #include <SPI.h>
// #include <nRF24L01.h>
// #include <RF24.h>
// #include <Wire.h>
// #include <Adafruit_ADXL345_U.h> // Include the ADXL345 library

// #define CE_PIN 9
// #define CSN_PIN 10

// // Hardware configuration
// RF24 radio(CE_PIN, CSN_PIN); // Set up nRF24L01 radio on SPI bus plus pins 9 & 10
// Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

// #define TX_LED 3

// const byte Address[6] = "00001";
// int Pot_Val_Y = 0, Pot_Val_X = 0;
// unsigned char Tx_command = 0, Speed_index = 0;
// unsigned char Tx_Array[2];

// void setup() {
//   Serial.begin(115200);
//   pinMode(TX_LED, OUTPUT);

//   // Initialize RF24 module
//   if (!radio.begin()) {
//     Serial.println("NRF24L01 initialization failed");
//     while (1);
//   }
//   radio.openWritingPipe(Address);
//   radio.setPALevel(RF24_PA_MAX);
//   radio.stopListening();

//   // Send initial command to ensure setup
//   radio.write(&Tx_command, sizeof(Tx_command));

//   // Initialize the ADXL345
//   if (!accel.begin()) {
//     Serial.println("ADXL345 connection failed");
//     while (1);
//   }
//   Serial.println("ADXL345 connected");

//   Tx_Array[0] = 0;
//   Tx_Array[1] = 0;
// }

// void loop() {
//   // Fetch accelerometer data
//   sensors_event_t event;
//   accel.getEvent(&event);

//   float ax = event.acceleration.x;
//   float ay = event.acceleration.y;
//   float az = event.acceleration.z;

//   // Determine direction and speed based on accelerometer values
//   if ((ay <= -4.0) || (ay >= 4.0)) {
//     if ((ax >= -4.0) || (ax <= 4.0)) {
//       if (ay <= -4.0) {
//         Tx_command = 1; // Forward
//         Speed_index = ((ay + 4.0) / -2.0) + 1;
//         if (Speed_index > 5) Speed_index = 5;
//       } else if (ay >= 4.0) {
//         Tx_command = 2; // Backward
//         Speed_index = ((ay - 4.0) / 2.0) + 1;
//         if (Speed_index > 5) Speed_index = 5;
//       }
//     } else {
//       Tx_command = 0;
//       Speed_index = 0;
//     }
//   } else if ((ax <= -4.0) || (ax >= 4.0)) {
//     if ((ay >= -4.0) || (ay <= 4.0)) {
//       if (ax <= -4.0) {
//         Tx_command = 4; // Right
//         Speed_index = ((ax + 4.0) / -2.0) + 1;
//         if (Speed_index > 5) Speed_index = 5;
//       } else if (ax >= 4.0) {
//         Tx_command = 3; // Left
//         Speed_index = ((ax - 4.0) / 2.0) + 1;
//         if (Speed_index > 5) Speed_index = 5;
//       }
//     } else {
//       Tx_command = 0;
//       Speed_index = 0;
//     }
//   } else {
//     Tx_command = 0;
//     Speed_index = 0;
//   }

//   Serial.print("Command: ");
//   Serial.print(Tx_command);
//   Serial.print(" , Speed Index: ");
//   Serial.println(Speed_index);

//   // Transmit data and control LED (blink LED when sending data)
//   Tx_Array[0] = Tx_command;
//   Tx_Array[1] = Speed_index;

//   if (radio.write(&Tx_Array, 2)) {
//     // Blink the LED on successful transmission
//     digitalWrite(TX_LED, HIGH); // Turn on LED when data is being sent
//     delay(100); // LED stays on for 100ms
//     digitalWrite(TX_LED, LOW); // Turn off LED
//     delay(100); // LED stays off for 100ms
//   } else {
//     digitalWrite(TX_LED, LOW); // Turn off LED if transmission fails
//   }

//   delay(100); // Small delay before fetching new accelerometer data
// }



#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <Adafruit_ADXL345_U.h> // Include the ADXL345 library

#define CE_PIN 9
#define CSN_PIN 10

// Hardware configuration
RF24 radio(CE_PIN, CSN_PIN); // Set up nRF24L01 radio on SPI bus plus pins 9 & 10
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

#define TX_LED 3

const byte Address[6] = "00001";
int Pot_Val_Y = 0, Pot_Val_X = 0;
unsigned char Tx_command = 0, Speed_index = 0;
unsigned char Tx_Array[2];

void setup() {
  Serial.begin(115200);
  pinMode(TX_LED, OUTPUT);

  // Initialize RF24 module
  if (!radio.begin()) {
    Serial.println("NRF24L01 initialization failed");
    while (1);
  }
  radio.openWritingPipe(Address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();

  // Send initial command to ensure setup
  radio.write(&Tx_command, sizeof(Tx_command));

  // Initialize the ADXL345
  if (!accel.begin()) {
    Serial.println("ADXL345 connection failed");
    while (1);
  }
  Serial.println("ADXL345 connected");

  Tx_Array[0] = 0;
  Tx_Array[1] = 0;
}

void loop() {
  // Fetch accelerometer data
  sensors_event_t event;
  accel.getEvent(&event);

  float ax = event.acceleration.x;
  float ay = event.acceleration.y;
  float az = event.acceleration.z;

  // Determine direction and speed based on accelerometer values
  if ((ay <= -4.0) || (ay >= 4.0)) {
    if ((ax >= -4.0) || (ax <= 4.0)) {
      if (ay <= -4.0) {
        Tx_command = 1; // Forward
        Speed_index = ((ay + 4.0) / -2.0) + 1;
        if (Speed_index > 5) Speed_index = 5;
      } else if (ay >= 4.0) {
        Tx_command = 2; // Backward
        Speed_index = ((ay - 4.0) / 2.0) + 1;
        if (Speed_index > 5) Speed_index = 5;
      }
    } else {
      Tx_command = 0;
      Speed_index = 0;
    }
  } else if ((ax <= -4.0) || (ax >= 4.0)) {
    if ((ay >= -4.0) || (ay <= 4.0)) {
      if (ax <= -4.0) {
        Tx_command = 4; // Right
        Speed_index = ((ax + 4.0) / -2.0) + 1;
        if (Speed_index > 5) Speed_index = 5;
      } else if (ax >= 4.0) {
        Tx_command = 3; // Left
        Speed_index = ((ax - 4.0) / 2.0) + 1;
        if (Speed_index > 5) Speed_index = 5;
      }
    } else {
      Tx_command = 0;
      Speed_index = 0;
    }
  } else {
    Tx_command = 0;
    Speed_index = 0;
  }

  Serial.print("Command: ");
  Serial.print(Tx_command);
  Serial.print(" , Speed Index: ");
  Serial.println(Speed_index);

  // Transmit data and control LED (blink LED when sending data)
  Tx_Array[0] = Tx_command;
  Tx_Array[1] = Speed_index;

  if (radio.write(&Tx_Array, 2)) {
    // Blink the LED on successful transmission
    digitalWrite(TX_LED, HIGH); // Turn on LED when data is being sent
    delay(100); // LED stays on for 100ms
    digitalWrite(TX_LED, LOW); // Turn off LED
    delay(100); // LED stays off for 100ms
    Serial.println("Data sent successfully");
  } else {
    digitalWrite(TX_LED, LOW); // Turn off LED if transmission fails
    Serial.println("Transmission failed");
  }

  delay(100); // Small delay before fetching new accelerometer data
}
