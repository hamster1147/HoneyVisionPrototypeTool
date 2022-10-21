#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

#include "server.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Server *server = new Server();

    server->settings.brightness  = ui->brightnessEntry->value();
    server->settings.contrast    = ui->contrastEntry->value();
    server->settings.saturation  = ui->saturationEntry->value();
    server->settings.exposure    = ui->exposureEntry->value();
    server->settings.sharpness   = ui->sharpnessEntry->value();
    server->settings.redBalance  = ui->redBalanceEntry->value();
    server->settings.blueBalance = ui->blueBalanceEntry->value();

    connect(ui->brightnessEntry, QOverload<int>::of(&QSlider::valueChanged), [server](int value) {
        server->settings.brightness = (int32_t)value;
        server->sendPacket();
    });

    connect(ui->contrastEntry, QOverload<int>::of(&QSlider::valueChanged), [server](int value) {
        server->settings.contrast = (int32_t)value;
        server->sendPacket();
    });

    connect(ui->saturationEntry, QOverload<int>::of(&QSlider::valueChanged), [server](int value) {
        server->settings.saturation = (int32_t)value;
        server->sendPacket();
    });

    connect(ui->exposureEntry, QOverload<int>::of(&QSlider::valueChanged), [server](int value) {
        server->settings.exposure = (int32_t)value;
        server->sendPacket();
    });

    connect(ui->sharpnessEntry, QOverload<int>::of(&QSlider::valueChanged), [server](int value) {
        server->settings.sharpness = (int32_t)value;
        server->sendPacket();
    });

    connect(ui->redBalanceEntry, QOverload<int>::of(&QSlider::valueChanged), [server](int value) {
        server->settings.redBalance = (int32_t)value;
        server->sendPacket();
    });

    connect(ui->blueBalanceEntry, QOverload<int>::of(&QSlider::valueChanged), [server](int value) {
        server->settings.blueBalance = (int32_t)value;
        server->sendPacket();
    });

    server->settings.threshConst      = ui->threshConstEntry->value();
    server->settings.threshMin        = ui->threshMinEntry->value();
    server->settings.threshMax        = ui->threshMaxEntry->value();
    server->settings.perimRateMin     = ui->perimRateMinEntry->value();
    server->settings.perimRateMax     = ui->perimRateMaxEntry->value();
    server->settings.polyAccuracyRate = ui->polyAccuracyRateEntry->value();
    server->settings.minCornerDist    = ui->minCornerDistEntry->value();
    server->settings.minMarkerDist    = ui->minMarkerDistEntry->value();
    server->settings.minDistToBorder  = ui->minDistToBorderEntry->value();
    server->sendPacket();

    connect(ui->threshConstEntry, QOverload<int>::of(&QSlider::valueChanged), [server](int value) {
        server->settings.threshConst = (int32_t)value;
        server->sendPacket();
    });

    connect(ui->threshMinEntry, QOverload<int>::of(&QSlider::valueChanged), [server](int value) {
        server->settings.threshMin = (int32_t)value;
        server->sendPacket();
    });

    connect(ui->threshMaxEntry, QOverload<int>::of(&QSlider::valueChanged), [server](int value) {
        server->settings.threshMax = (int32_t)value;
        server->sendPacket();
    });

    connect(ui->perimRateMinEntry, QOverload<int>::of(&QSlider::valueChanged), [server](int value) {
        server->settings.perimRateMin = (int32_t)value;
        server->sendPacket();
    });

    connect(ui->perimRateMaxEntry, QOverload<int>::of(&QSlider::valueChanged), [server](int value) {
        server->settings.perimRateMax = (int32_t)value;
        server->sendPacket();
    });

    connect(ui->polyAccuracyRateEntry, QOverload<int>::of(&QSlider::valueChanged), [server](int value) {
        server->settings.polyAccuracyRate = (int32_t)value;
        server->sendPacket();
    });

    connect(ui->minCornerDistEntry, QOverload<int>::of(&QSlider::valueChanged), [server](int value) {
        server->settings.minCornerDist = (int32_t)value;
        server->sendPacket();
    });

    connect(ui->minMarkerDistEntry, QOverload<int>::of(&QSlider::valueChanged), [server](int value) {
        server->settings.minMarkerDist = (int32_t)value;
        server->sendPacket();
    });

    connect(ui->minDistToBorderEntry, QOverload<int>::of(&QSlider::valueChanged), [server](int value) {
        server->settings.minDistToBorder = (int32_t)value;
        server->sendPacket();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

