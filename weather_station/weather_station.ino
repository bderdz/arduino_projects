#include <LiquidCrystal_I2C.h>
#include  <Wire.h>
#include <DHT11.h>

LiquidCrystal_I2C lcd(0x27,  16, 2);
DHT11 dht11(5);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
}
void loop() {
  int temperature = 0;
  int humidity = 0;
  int result = dht11.readTemperatureHumidity(temperature, humidity);

  if(!result) {
    lcd.setCursor(13, 0);
    lcd.print(temperature);
    lcd.print("\xDF""");
    lcd.setCursor(10, 1);
    lcd.print(humidity);
    lcd.print("%");
  }

  delay(1000);  
}
