// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "f41773a6-27f8-495f-b133-6c8b0391fbc0";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

void onBuzzerChange();
void onMalingChange();

bool buzzer;
bool maling;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(buzzer, READWRITE, ON_CHANGE, onBuzzerChange);
  ArduinoCloud.addProperty(maling, READWRITE, ON_CHANGE, onMalingChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
