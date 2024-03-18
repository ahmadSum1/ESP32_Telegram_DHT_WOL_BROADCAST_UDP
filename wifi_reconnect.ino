void WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info) {
  Serial.println("Connected to AP successfully!");

  digitalWrite(ledPin, ledState);
}

void WiFiGotIP(WiFiEvent_t event, WiFiEventInfo_t info) {
  Serial.println("WiFi connected! \tSSID: ");
  Serial.print(ssid);
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  //initializes the UDP state
  //This initializes the transfer buffer
  // udp.begin(WiFi.localIP(), udpPort);
  // UDP_connected = true;
  // Serial.println("UDP connected");
}

void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info) {
  Serial.println("Disconnected from WiFi access point");
  Serial.print("WiFi lost connection. Reason: ");
  Serial.println(info.wifi_sta_disconnected.reason);
  Serial.println("Trying to Reconnect to: ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);


  // UDP_connected = false;
}

void setup_wifi_reconnect() {
  Serial.begin(115200);

  // delete old config
  WiFi.disconnect(true);

  delay(1000);

  WiFi.onEvent(WiFiStationConnected, ARDUINO_EVENT_WIFI_STA_CONNECTED);
  WiFi.onEvent(WiFiGotIP, ARDUINO_EVENT_WIFI_STA_GOT_IP);
  WiFi.onEvent(WiFiStationDisconnected, ARDUINO_EVENT_WIFI_STA_DISCONNECTED);

  /* Remove WiFi event
  Serial.print("WiFi Event ID: ");
  Serial.println(eventID);
  WiFi.removeEvent(eventID);*/

  WiFi.begin(ssid, password);

  Serial.println();
  Serial.println();
  Serial.println("Waiting for WiFi... ");
}

void loop_wifi_reconnect() {
  if (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(100);
  }
  else {
      digitalWrite(ledPin, ledState);
  }
}