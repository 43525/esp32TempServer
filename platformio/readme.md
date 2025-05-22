Temperature and Humility display screen and web
---

DHT11 WebServer, pushButton to on info on board 
* Low power components, which can power via powerBank.
* Press Push button to shown the SSID, IP address & this link.

PlatformIO setup
- New Project : <this project>
- Board : DOIT ESP32 DEVKIT V1
- Framework : Arduino

## To start without Wifi coonection
* After few seconds if without wifi connection, will only OLED display.

## To configure connection with WiFi
Need to set `WIFI_SSID` and `WIFI_PASS` before upload to Esp32 

GitBash to set the Wifi credential, and unload
```bash
$ export WIFI_SSID="<your_wifi_ssid>"
$ export WIFI_PASS="<your_wifi_pass>"

$ cd platformio
$ /c/Users/Ng/.platformio/penv/Scripts/activate
$ /c/Users/Ng/.platformio/penv/Scripts/platformio.exe run
$ /c/Users/Ng/.platformio/penv/Scripts/platformio.exe run -t erase
$ /c/Users/Ng/.platformio/penv/Scripts/platformio.exe run -t upload
```

Upload from VSCode `PlatformIO: New Terminal`, RaspberryPi 4B
```console
platformio $ 
$ export WIFI_SSID="<your_wifi_ssid>"
$ export WIFI_PASS="<your_wifi_pass>"
$ echo $WIFI_SSID

 $ /home/pi/.platformio/penv/bin/platformio run
 $ /home/pi/.platformio/penv/bin/platformio run -t erase
 $ /home/pi/.platformio/penv/bin/platformio run -t upload
 $ /home/pi/.platformio/penv/bin/platformio device monitor
```

Web server display temperature and humidity   
Only work with same connection of wifi in this code.

IP Address can be seen during start, or press button.

Hardwares
---
### main board
model: ESP-WROOM-32D

partNo: ESP32 DEVKITV1

### SSD1306 0.96inch OLED Display
OLED Pin | ESP32
--- | ---
Vin | 3.3V
GND | GND
SCL | GPIO22
SDA | GPIO21


### DHT11 module
DHT11 | ESP32
--- | ---
`-` | GND
`+` | 3.3V
S | GPIO15


### push button
button | ESP32
--- | ---
pin1 | GPIO4
" | 10k resistor to 3.3V
pin2 | GND

---