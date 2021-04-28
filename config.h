#define LED_TOGGLE_PERIOD     1000

#define SERIAL_BAUD_RATE      115200

// change pinouts if not defined through native board LORA_* definitions
#ifndef LORA_RST
#pragma message("LoRa pin definitions are not found, redefining...")
#define LORA_RST              23 //t-beam 23 //lora32 12
#define LORA_IRQ              26
#endif

#ifndef BUILTIN_LED
#pragma message("BUILDIN_LED is not found, defining as 2")
#define BUILTIN_LED           14 //14 //22
#endif

#define CFG_IS_CLIENT_MODE    true

#define CFG_LORA_PIN_SS       18
#define CFG_LORA_PIN_RST      23 //23 //12
#define CFG_LORA_PIN_DIO0     26

#define CFG_LORA_FREQ         433.775E6
#define CFG_LORA_BW           125e3
#define CFG_LORA_SF           12
#define CFG_LORA_CR           5
#define CFG_LORA_PWR          20
#define CFG_LORA_ENABLE_CRC   true

#define CFG_BT_NAME           "Loraprs-1"

#define CFG_APRS_LOGIN        "NOCALL-10"
#define CFG_APRS_PASS         "12345"
#define CFG_APRS_FILTER	      "r/48.749/2.506/25"
#define CFG_APRS_RAW_BKN      "F8COD-10>APZMDM,WIDE1-1:!4844.96N/00230.38E#LoRA 433.775MHz/BW125/SF12/CR5/0x34"

#define CFG_WIFI_SSID         ""
#define CFG_WIFI_KEY          ""

#define CFG_FREQ_CORR         true
#define CFG_PERSISTENT_APRS   false
#define CFG_DIGIREPEAT        false
#define CFG_RF_TO_IS          false
#define CFG_IS_TO_RF          false
#define CFG_BEACON            false
#define CFG_KISS_EXTENSIONS   true
