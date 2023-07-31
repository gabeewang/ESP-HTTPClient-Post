//本專案適用於ESP8266的函式庫
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

//定義ESP8266將要連接Wi-Fi的名稱及密碼
#ifndef STASSID
#define STASSID "your Wi-Fi SSID"
#define STAPSK  "your Wi-Fi Password"
#endif

//定義要進行網頁POST目標伺服器的IP位置以及後端處理的網頁文件
#define SERVER_IP "IP of remote server" //記得加上http或https
#define SERVER_PATH "/Test/Post/HttpPostReceive.aspx"

void setup() {
  Serial.begin(9600);
  
  //開始連接Wi-Fi
  WiFi.begin(STASSID, STAPSK);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //成功連接至Wi-Fi，輸出即將連線伺服器的IP位址
  Serial.println("");
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  if ((WiFi.status() == WL_CONNECTED)) {
    WiFiClient client;
    HTTPClient http;
    
    Serial.print("[HTTP] begin...\n");
    // 配置伺服器與URL
    http.begin(client, SERVER_IP + SERVER_PATH);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    
    Serial.print("[HTTP] POST...\n");
    // 開始連接與發送HTTP的header與body
    int httpCode = http.POST("Temp=1"); // URL-encoded data
    
    // 發生錯誤httpCode將會是負數
    if (httpCode > 0) {
      // HTTP header已發送，伺服器響應header已處理
      Serial.printf("[HTTP] POST... code: %d\n", httpCode);
      
      // 檢查響應是否成功
      if (httpCode == HTTP_CODE_OK) {
        const String& payload = http.getString();
        Serial.println("Received payload:\n<<");
        Serial.println(payload);
        Serial.println(">>");
      }
    } else {
      Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    
    http.end();
  }
  
  delay(10000);
}
