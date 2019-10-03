// -----------------------------------------------------------------------------------
// Constants

#pragma once

// On/Off, etc.
#define OFF         -1
#define ON          -2
#define ON_PULLUP   -3
#define ON_PULLDOWN -4
#define XDIRECT     -5

// Pinmaps
#define PINMAP_FIRST 1
#define Classic     1
#define AltMega2560 2
#define Ramps14     3
#define MksGenL     3
#define MksGenL2    4
#define MiniPCB     10
#define MiniEMB     11
#define MiniPCB2    12
#define MaxPCB      20
#define MaxPCB2     21
#define MaxTMC      22
#define MaxESP      30
#define MaxESP2     31
#define MaxESP3     32
#define STM32Blue   40
#define STM32Black  41
#define PINMAP_LAST 41

// mount types
#define MOUNT_TYPE_FIRST 1
#define GEM    1                // German Equatorial Mount.  Meridian flips enabled.
#define FORK   2                // Fork Mount.  Meridian flips disabled.
#define ALTAZM 3                // Altitude Azimuth Mount.  Dobsonians, etc.
#define MOUNT_TYPE_LAST 3

// various RTC's supported
#define RTC_FIRST 1
#define DS3231 1                // DS3231 RTC on I2C
#define DS3234 2                // DS3234 RTC on SPI (default CS)
#define TEENSY 3                // TEENSY3.2 RTC (Built-in)
#define RTC_LAST 3

// various Weather sensors supported
#define WEATHER_FIRST 1
#define BME280       1          // BME280 on I2C (at default address 0x77)
#define BME280_0x76  2          // BME280 on I2C (at address 0x76)
#define BME280SPI    3          // BME280 on SPI (default CS)
#define WEATHER_LAST 4

#define TELESCOPE_TEMPERATURE_FIRST 1
#define DS1820       1          // DS18B20 on OneWire
#define TELESCOPE_TEMPERATURE_LAST 1

// coordinate mode for getting and setting RA/Dec
#define OBSERVED_PLACE 1
#define TOPOCENTRIC 2
#define ASTROMETRIC_J2000 3
#define TELESCOPE_COORDINATES TOPOCENTRIC

// EEPROM Info --------------------------------------------------------------------------------------------------------------
// General purpose storage A (100 bytes), 0..99

#define EE_posAxis1    0        // 4
#define EE_posAxis2    4        // 4
#define EE_pierSide    8        // 1
#define EE_parkStatus  9        // 1
#define EE_parkSaved   10       // 1

#define EE_currentSite 11       // 1

#define EE_pauseHome   12       // 1 + 1

#define EE_LMT         14       // 4
#define EE_JD          18       // 4

#define EE_pulseGuideRate 22    // 1
#define EE_maxRate     23       // 2

#define EE_autoMeridianFlip 25  // 1

#define EE_dfCor       26       // 4
#define EE_ax1Cor      30       // 4
#define EE_ax2Cor      34       // 4

#define EE_dpmE        38       // 1
#define EE_dpmW        39       // 1
#define EE_minAlt      40       // 1
#define EE_maxAlt      41       // 1

#define EE_doCor       42       // 4
#define EE_pdCor       46       // 4
#define EE_altCor      50       // 4
#define EE_azmCor      54       // 4
#define EE_indexAxis1  58       // 4
#define EE_indexAxis2  62       // 4
#define EE_tfCor       66       // 4

#define EE_pecStatus   70       // 1
#define EE_pecRecorded 71       // 1

#define EE_posAxis4    72       // 4

#define EE_wormSensePos 76      // 4

#define EE_backlashAxis1 80     // 4
#define EE_backlashAxis2 84     // 4
#define EE_siderealInterval 88  // 4
#define EE_posAxis5      92     // 4

#define EE_autoInitKey 96

// site index: 100-199
// 100..103 latitude  1  ((index 1-1)*25+100)
// 104..107 longitude 1
// 108      timeZone  1
// 109..124 site name 1

// 125..128 latitude  2  ((index 2-1)*25+100)
// 129..132 longitude 2
// 133      timeZone  2
// 134..149 site name 2

// 150..153 latitude  3  ((index 3-1)*25+100)
// 154..157 longitude 3
// 158      timeZone  3
// 159..174 site name 3

// 175..178 latitude  4  ((index 4-1)*25+100)
// 179..182 longitude 4
// 183      timeZone  4
// 184..199 site name 4

#define EE_sites    100

// PEC table: 200...pecBufferSize+199
// pecBufferSize table of byte sized integers -128..+127, units are steps

#define EE_pecTable 200

// Library
// Catalog storage starts at 200+pecBufferSize and ends at E2END-100

// General purpose storage B (100 bytes), E2END-99..E2END
#define GSB (E2END-100)
#define EE_dcPwrAxis4  GSB+0   // 1
#define EE_dcPwrAxis5  GSB+1   // 1
#define EE_maxRateL    GSB+2   // 4

// --------------------------------------------------------------------------------------------------------------------------
// Unique identifier for the current initialization format for NV, do not change
#define initKey 915307548

#define PierSideNone     0
#define PierSideEast     1
#define PierSideWest     2
#define PierSideBest     3
#define PierSideFlipWE1  10
#define PierSideFlipWE2  11
#define PierSideFlipWE3  12
#define PierSideFlipEW1  20
#define PierSideFlipEW2  21
#define PierSideFlipEW3  22
