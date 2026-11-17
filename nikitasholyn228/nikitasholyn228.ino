#include <GyverPing.h>

#define HC_TRIG 3
#define HC_ECHO 2

GPingSync sonar(HC_TRIG, HC_ECHO);

void setup() {
    Serial.begin(115200);
}

void loop() {
    // сделать измерение
    sonar.ping();

    // открой плоттер для вывода графика
    Serial.print(sonar.getRaw());       // "сырое" значение
    Serial.print(',');
    Serial.print(sonar.getFiltered());  // фильтрованное от резких выбросов
    Serial.print(',');
    Serial.println(sonar.getSmooth());  // + усреднение, плавный точный сигнал

    delay(50);
}
