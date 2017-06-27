temperature-sensor
==================

_temperature-sensor_ is an Arduino sketch for any Arduino board with a connected
DHT11 temperature and humidity sensor to send periodic measurements through a
Serial channel to the [temperature-beacon](https://github.com/toksaitov/temperature-beacon)
program running on ESP8266 to transmit data through a Wi-Fi connection to a
deployed data collection [server](https://github.com/toksaitov/temperature-back).

## Requirements

* Arduino IDE `>= 1.8.2`
* Any Arduino board
* A DHT11 (or DHT22) temperature-humidity sensor

## Usage

Open the `temperature-sensor.ino` sketch in the Arduino IDE and set or disable
an LCD.

```C
#define DISPLAY_RS_PIN     8
#define DISPLAY_ENABLE_PIN 9
#define DISPLAY_D4_PIN     4
#define DISPLAY_D5_PIN     5
#define DISPLAY_D6_PIN     6
#define DISPLAY_D7_PIN     7
#define DISPLAY_COLUMNS    16
#define DISPLAY_ROWS       2
```

Set the type of the temperature sensor, its pins, and the delays.

```C
#define SENSOR_TYPE       DHT11
#define SENSOR_VCC_PIN    51
#define SENSOR_DATA_PIN   53
#define SENSOR_READ_DELAY 2000
```

Connect the device or a programmer, compile, and upload the program.

Ensure to [setup](https://github.com/toksaitov/temperature-beacon) ESP8266 to
send data to the data collection [server](https://github.com/toksaitov/temperature-back).

## Credits

*temperature-sensor* was created by [Dmitrii Toksaitov](https://github.com/toksaitov).

