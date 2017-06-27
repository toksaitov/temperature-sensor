#include <inttypes.h>

#include "LiquidCrystal.h"
#include "DHT.h"

#define SERIAL_SPEED 9600

#define DISPLAY_RS_PIN     8
#define DISPLAY_ENABLE_PIN 9
#define DISPLAY_D4_PIN     4
#define DISPLAY_D5_PIN     5
#define DISPLAY_D6_PIN     6
#define DISPLAY_D7_PIN     7
#define DISPLAY_COLUMNS    16
#define DISPLAY_ROWS       2

#define SENSOR_TYPE       DHT11
#define SENSOR_VCC_PIN    51
#define SENSOR_DATA_PIN   53
#define SENSOR_READ_DELAY 2000

LiquidCrystal lcd_display(
    DISPLAY_RS_PIN,
    DISPLAY_ENABLE_PIN,
    DISPLAY_D4_PIN,
    DISPLAY_D5_PIN,
    DISPLAY_D6_PIN,
    DISPLAY_D7_PIN
);

DHT sensor(
    SENSOR_DATA_PIN,
    SENSOR_TYPE
);

void enable_pin_as_vcc(int pin)
{
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
}

void setup()
{
    Serial.begin(SERIAL_SPEED);
    Serial3.begin(SERIAL_SPEED);

    enable_pin_as_vcc(SENSOR_VCC_PIN);
    lcd_display.begin(DISPLAY_COLUMNS, DISPLAY_ROWS);
}

void loop()
{
    delay(SENSOR_READ_DELAY);

    float temperature = sensor.readTemperature();
    float humidity = sensor.readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
        lcd_display.setCursor(0, 0);
        lcd_display.print("Sensor is faulty");
    } else {
        int row = 0, column = 0;

        lcd_display.setCursor(row, column);
        lcd_display.print("Temp.: ");
        lcd_display.print(temperature);

        ++column;
        lcd_display.setCursor(row, column);
        lcd_display.print("Humidity: ");
        lcd_display.print(humidity);

        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print(" C; Humidity: ");
        Serial.print(humidity);
        Serial.println("%");

        Serial3.print('t');
        Serial3.write((const uint8_t *) &temperature, sizeof(temperature));
        Serial3.print('h');
        Serial3.write((const uint8_t *) &humidity, sizeof(humidity));
    }
}

