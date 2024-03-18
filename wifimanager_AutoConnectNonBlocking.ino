// Wifi manager library
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
WiFiManager wm;

void wm_setup() {
    WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP    

    
    //reset settings - wipe credentials for testing
    //wm.resetSettings();

    wm.setConfigPortalBlocking(false);
    wm.setConfigPortalTimeout(60);
    //automatically connect using saved credentials if they exist
    //If connection fails it starts an access point with the specified name
    if(wm.autoConnect("AutoConnectAP")){
        Serial.println("connected...yeey :)");
    }
    else {
        Serial.println("Configportal running");
    }
}

void wm_loop() {
    wm.process();
    // put your main code here, to run repeatedly:
}
