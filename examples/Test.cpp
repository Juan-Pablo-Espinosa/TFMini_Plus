#include "TFLidar.hpp"

TFLidar Lidar1;

void setup() {
  Serial.begin(115200);
  Lidar1.begin(&Serial1);
}

void loop() {
  Lidar1.updateLoop();
  Serial.printf("Distance: %i, Strenght: %i \n", Lidar1.getDistance(), Lidar1.getStrenght());
}
