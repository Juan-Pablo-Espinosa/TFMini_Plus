#include "TFLidar.hpp"

TFLidar::TFLidar()
{
}

TFLidar::~TFLidar()
{
}

void TFLidar::begin(HardwareSerial *_lidaraSerial){
    m_lidarSerial = _lidaraSerial;
    Serial.begin(115200);
    m_lidarSerial->begin(115200);
}

void TFLidar::updateLoop(){
    
    while (m_lidarSerial->available() > 9){
        m_lidarSerial->read();
    }
    m_uart[0] = m_lidarSerial->read();
    if (m_uart[0] == HEADER){
        delayMicroseconds(700);
        m_uart[1] = m_lidarSerial->read();
        if (m_uart[1] == HEADER){
            for (int i=2;i<9;i++){
                m_uart [i] = m_lidarSerial->read();
            }
            m_check = m_uart [0] + m_uart [1] + m_uart [2] +m_uart [3] + m_uart [4] + m_uart [5] + m_uart [6] + m_uart [7];
            if (m_uart [8] == (m_check & 0xff)){
                m_distance = m_uart [2] + m_uart [3] * 256;
                m_strength= m_uart [4] + m_uart [5] *256;
                //Serial.printf("Distance: %i, Strenght: %i \n", m_distance, m_strength);
            }
        }
    }
}