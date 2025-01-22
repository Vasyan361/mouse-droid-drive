#include "Mpu6050.h"

void Mpu6050::init()
{
    Wire.setPins(I2C_SDA, I2C_SCK);
    Wire.begin();
    //Wire.setClock(1000000UL);   // разгоняем шину на максимум

    // инициализация DMP
    mpu.initialize();
    mpu.dmpInitialize();
    mpu.setDMPEnabled(true);
}

void Mpu6050::calculate()
{
    if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) {
        // переменные для расчёта (ypr можно вынести в глобал)
        Quaternion q;
        VectorFloat gravity;
        float ypr[3];

        // расчёты
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

        // выводим результат в радианах (-3.14, 3.14)
        Serial.print(ypr[0]); // вокруг оси Z
        Serial.print(',');
        Serial.print(ypr[1]); // вокруг оси Y
        Serial.print(',');
        Serial.print(ypr[2]); // вокруг оси X
        Serial.println();
        // для градусов можно использовать degrees()
    }
}