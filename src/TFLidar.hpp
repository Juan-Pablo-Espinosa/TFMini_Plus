#pragma once

#include <HardwareSerial.h>
#include <Arduino.h>

#define HEADER 0x59
#define FRAME_SIZE 9

class TFLidar
{
public:
    TFLidar();
    ~TFLidar();
    void begin(HardwareSerial *_lidaraSerial);
    void updateLoop();
    int getDistance() const{return m_distance;};
    int getStrenght() const{return m_strength;};
private:
    int m_distance;
    int m_strength;
    int m_check;
    int m_uart[9];
    HardwareSerial * m_lidarSerial;
};
