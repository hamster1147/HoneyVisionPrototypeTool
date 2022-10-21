#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QUdpSocket>

#pragma (push, 1)
typedef struct {
    int32_t brightness;
    int32_t contrast;
    int32_t saturation;
    int32_t sharpness;
    int32_t exposure;
    int32_t redBalance;
    int32_t blueBalance;

    int32_t threshConst;
    int32_t threshMin;
    int32_t threshMax;
    int32_t perimRateMin;
    int32_t perimRateMax;
    int32_t polyAccuracyRate;
    int32_t minCornerDist;
    int32_t minMarkerDist;
    int32_t minDistToBorder;
} cameraSettings_t;
#pragma pop

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

    cameraSettings_t settings;

    void sendPacket(void);
private:
    QUdpSocket *m_socket;

signals:

};

#endif // SERVER_H
