#ifndef LORAPRS_SEVICE_H
#define LORAPRS_SERVICE_H

#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include <WiFi.h>

#include "BluetoothSerial.h"
#include "ax25_payload.h"
#include "loraprs_config.h"

namespace LoraPrs {

class Service
{
public:
  Service();
  
  void setup(const Config &conf);
  void loop();

private:
  void setupWifi(const String &wifiName, const String &wifiKey);
  void setupLora(int loraFreq, int bw, byte sf, byte cr, byte pwr, byte sync);
  void setupBt(const String &btName);

  void reconnectWifi();
  bool reconnectAprsis();

  void onLoraDataAvailable(int packetSize);
  void onBtDataAvailable();
  void onAprsisDataAvailable();

  void sendPeriodicBeacon();
  
  void sendToAprsis(String aprsMessage);
  bool sendToLora(const AX25::Payload &payload);

  void kissResetState();

  inline bool needsAprsis() const { return !isClient_ && (enableRfToIs_ || enableIsToRf_); }
  inline bool needsWifi() const { return needsAprsis(); }
  inline bool needsBt() const { return isClient_; }
  inline bool needsBeacon() const { return !isClient_ && enableBeacon_; }

private:
  enum KissMarker {
    Fend = 0xc0,
    Fesc = 0xdb,
    Tfend = 0xdc,
    Tfesc = 0xdd
  };

  enum KissState {
    Void = 0,
    GetCmd,
    GetData,
    Escape
  };

  enum KissCmd {
    Data = 0x00,
    NoCmd = 0x80
  };

  const String CfgLoraprsVersion = "LoRAPRS 0.1";
  const int CfgPollDelayMs = 10;

  const byte CfgPinSs = 5;
  const byte CfgPinRst = 26;
  const byte CfgPinDio0 = 14;

private:
  // config
  bool isClient_;
  long loraFreq_;

  AX25::Callsign ownCallsign_;

  String aprsHost_;
  int aprsPort_;
  String aprsLogin_;
  String aprsBeacon_;
  int aprsBeaconPeriodMinutes_;

  bool autoCorrectFreq_;
  bool addSignalReport_;
  bool persistentConn_;
  bool enableRfToIs_;
  bool enableIsToRf_;
  bool enableRepeater_;
  bool enableBeacon_;

  // state
  KissCmd kissCmd_;
  KissState kissState_;
  long previousBeaconMs_;
  
  // peripherals
  BluetoothSerial serialBt_;
  WiFiClient aprsisConn_;
};

} // LoraPrs

#endif // LORAPRS_SERVICE_H