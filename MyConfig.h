// ---------------------------------------------------------------------------------------------------------------------------------
// Configuration for OnStep

/*
            For more information on setting OnStep up see http://www.stellarjourney.com/index.php?r=site/equipment_onstep
                        and join the OnStep Groups.io at https://groups.io/g/onstep

 *           *** Read the compiler warnings and errors, they are there to help guard against invalid configurations ***
*/

// ---------------------------------------------------------------------------------------------------------------------------------
// ADJUST THE FOLLOWING TO CONFIGURE YOUR CONTROLLER FEATURES ----------------------------------------------------------------------
// <-Req'd = always must set, <-Often = usually must set, Option = optional, Adjust = adjust as req'd, Infreq = infrequently changed



// PINMAP ---------------------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#PINMAP
#undef  PINMAP
#define PINMAP                  MaxESP3

// SERIAL PORT COMMAND CHANNELS ------------------------------------ see https://onstep.groups.io/g/main/wiki/6-Configuration#SERIAL
#undef  SERIAL_A_BAUD_DEFAULT
#define SERIAL_A_BAUD_DEFAULT        9600 //   9600, n. Where n=9600,19200,57600,115200 (common baud rates.)                  Infreq
#undef  SERIAL_B_BAUD_DEFAULT
#define SERIAL_B_BAUD_DEFAULT        115200 //   9600, n. See (src/HAL/) for your MCU Serial port # etc.                        Option
#undef  SERIAL_B_ESP_FLASHING
#define SERIAL_B_ESP_FLASHING         ON //    OFF, ON Upload ESP8266 WiFi firmware through SERIAL_B with :ESPFLASH# cmd.    Option
#undef  SERIAL_C_BAUD_DEFAULT
#define SERIAL_C_BAUD_DEFAULT         ON //    OFF, n, ON for ESP32 Bluetooth.                                               Option
#define SERIAL_C_BLUETOOTH_NAME  "OnStep" // "On..", Bluetooth device name for ESP32.                                         Option

// MOUNT TYPE -------------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#MOUNT_TYPE
#undef MOUNT_TYPE
#define MOUNT_TYPE                    GEM //    GEM, GEM for German Equatorial, FORK for Equatorial Fork, or ALTAZM          <-Req'd
//         Dobsonian etc. mounts. GEM Eq mounts perform meridian flips.

// USER FEEDBACK -------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#USER_FEEDBACK
//#undef  LED_STATUS2
//#define LED_STATUS2                   ON //    OFF, ON Blinks 1s interval w/PPS sync, steady for gotos, off if in standby.   Option
#undef  LED_RETICLE
#define LED_RETICLE                   OFF //    OFF, n. Where n=0..255 (0..100%) activates feature sets default brightness.   Option

// TIME AND LOCATION -------------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#TLS
#undef TIME_LOCATION_SOURCE
#define TIME_LOCATION_SOURCE          DS3231 //    OFF, DS3231 (I2c,) DS3234 (Spi,) TEENSY (T3.2 internal,) or GPS source.       Option

// SENSORS -------------------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#SENSORS
// * = also supports ON_PULLUP or ON_PULLDOWN to activate MCU internal resistors if present.
#undef WEATHER
#define WEATHER                       BME280_0x76 //BME280_0x76 //    OFF, BME280 (I2C 0x77,) BME280_0x76, BME280_SPI (see pinmap for CS.)          Option
//         BMP280 (I2C 0x77,) BMP280_0x76, BMP280_SPI (see pinmap for CS.)
//         BME280 or BMP280 for temperature, pressure.  BME280 for humidity also.

#undef PPS_SENSE
#define PPS_SENSE                     ON_PULLUP//ON_PULLUP //    OFF, ON* enables PPS (pulse per second,) senses signal rising edge.           Option
//         Better tracking accuracy especially for Mega2560's w/ceramic resonator.

#undef LIMIT_SENSE
#define LIMIT_SENSE                   ON //    OFF, ON* limit sense switch close to Gnd stops gotos and/or tracking.         Option
#undef LIMIT_SENSE_STATE
#define LIMIT_SENSE_STATE             LOW //    LOW, For NO (normally open) switches, HIGH for NC (normally closed.)          Adjust

#undef PEC_SENSE
#define PEC_SENSE                     ON //    OFF, ON*, n, sense digital OR n=0 to 1023 (0 to 3.3V or 5V) analog threshold. Option
#undef PEC_SENSE_STATE
#define PEC_SENSE_STATE              HIGH //   HIGH, Senses the PEC signal rising edge or use LOW for falling edge.           Adjust
//         Ignored in ALTAZM mode.

// ST4 INTERFACE ------------------------------------------------------ see https://onstep.groups.io/g/main/wiki/6-Configuration#ST4
// *** It is up to you to verify the interface meets the electrical specifications of any connected device, use at your own risk ***
#undef ST4_INTERFACE
#define ST4_INTERFACE                 ON //    OFF, ON, ON_PULLUP enables interface. <= 1X guides unless hand control mode.  Option
#undef ST4_HAND_CONTROL                                          //         During goto btn press: aborts slew or continue meridian flip pause home
#define ST4_HAND_CONTROL              ON//    OFF, ON for hand controller special features and SHC support.                 Option
//         Hold [E]+[W] btns >2s: Guide rate   [E]-  [W]+  [N] trk on/off [S] sync
//         Hold [N]+[S] btns >2s: Usr cat item [E]-  [W]+  [N] goto [S] snd on/off

#define SEPARATE_PULSE_GUIDE_RATE_ON

// SLEWING BEHAVIOUR ---------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#SLEWING
#undef SLEW_RATE_BASE_DESIRED
#define SLEW_RATE_BASE_DESIRED        4.0 //    1.0, n. Desired slew rate in deg/sec. Adjustable at run-time from            <-Req'd
//         1/2 to 2x this rate, and as MCU performace considerations require.
#undef SLEW_ACCELERATION_DIST
#define SLEW_ACCELERATION_DIST        5.0 //    5.0, n, (degrees.) Approx. distance for acceleration (and deceleration.)      Adjust
#undef SLEW_RAPID_STOP_DIST
#define SLEW_RAPID_STOP_DIST          2.0 //    2.0, n, (degrees.) Approx. distance required to stop when a slew              Adjust
//         is aborted or a limit is exceeded.

// PIER SIDE BEHAVIOUR -------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#SYNCING
#undef MFLIP_PAUSE_HOME_MEMORY
#define MFLIP_PAUSE_HOME_MEMORY       ON //    OFF, ON Remember meridian flip pause at home setting across power cycles.     Option
#undef MFLIP_AUTOMATIC_MEMORY
#define MFLIP_AUTOMATIC_MEMORY        ON //    OFF, ON Remember automatic meridian flip setting across power cycles.         Option
#undef PIER_SIDE_PREFERRED_DEFAULT
#define PIER_SIDE_PREFERRED_DEFAULT  EAST



// GUIDING BEHAVIOUR ---------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#GUIDING

#undef GUIDE_DISABLE_BACKLASH
#define GUIDE_DISABLE_BACKLASH        ON //    OFF, Disable backlash takeup during guiding at <= 1X                          Option

// MOTION CONTROL -------------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#MOTION
#undef STEP_WAVE_FORM
#define STEP_WAVE_FORM             PULSE // SQUARE, PULSE Step signal wave form faster rates. SQUARE best signal integrity.  Adjust

// AXIS1 RA/AZM
// see https://onstep.groups.io/g/main/wiki/6-Configuration#AXIS1
#undef AXIS1_STEPS_PER_DEGREE
#define AXIS1_STEPS_PER_DEGREE    25066.66 //  12800, n. Number of steps per degree:                                          <-Req'd
//         n = (stepper_steps * micro_steps * overall_gear_reduction)/360.0
//  400*32*144*(48/15)/*360
#undef AXIS1_STEPS_PER_WORMROT
#define AXIS1_STEPS_PER_WORMROT         50133 //      0, n. Number steps per worm rotation (PEC Eq mode only, 0 disables PEC.)   <-Req'd
//         n = (AXIS1_STEPS_PER_DEGREE*360)/reduction_final_stage
#undef AXIS1_DRIVER_MODEL
#define AXIS1_DRIVER_MODEL            TMC2130_QUIET //    OFF, (See above.) Stepper driver model.                                      <-Often
#undef AXIS1_DRIVER_MICROSTEPS
#define AXIS1_DRIVER_MICROSTEPS       32 //    OFF, n. Microstep mode when tracking.                                        <-Often
#undef AXIS1_DRIVER_MICROSTEPS_GOTO    //    OFF, n. Microstep mode used during gotos.                                     Option
#define AXIS1_DRIVER_MICROSTEPS_GOTO  OFF //    OFF, n. Microstep mode used during gotos.                                     Option
#undef AXIS1_DRIVER_REVERSE
#define AXIS1_DRIVER_REVERSE          ON //    OFF, ON Reverses movement direction, or reverse wiring instead to correct.   <-Often

#undef AXIS1_DRIVER_IRUN
#define AXIS1_DRIVER_IRUN             1100 //    OFF, n, (mA.) Current during tracking, appropriate for stepper/driver/etc.    Option
#undef AXIS1_LIMIT_MIN
#define AXIS1_LIMIT_MIN              -180 //   -180, n. Where n= -90..-270 (degrees.) Minimum "Hour Angle" for Eq modes.      Adjust
//         n. Where n=-180..-360 (degrees.) Minimum Azimuth for AltAzm mode.

#undef AXIS1_LIMIT_MAX
#define AXIS1_LIMIT_MAX               180 //    180, n. Where n=  90.. 270 (degrees.) Maximum "Hour Angle" for Eq modes.      Adjust
//         n. Where n= 180.. 360 (degrees.) Maximum Azimuth for AltAzm mode.

// AXIS2 DEC/ALT
// see https://onstep.groups.io/g/main/wiki/6-Configuration#AXIS2
#undef AXIS2_STEPS_PER_DEGREE
#define AXIS2_STEPS_PER_DEGREE    25066.66 //  12800, n. Number of steps per degree:                                          <-Req'd
//         n = (stepper_steps * micro_steps * overall_gear_reduction)/360.0
//  400*32*144*(48/15)/*360
#undef AXIS2_DRIVER_MODEL
#define AXIS2_DRIVER_MODEL            TMC2130_QUIET //    OFF, (See above.) Stepper driver model.                                      <-Often
#undef AXIS2_DRIVER_MICROSTEPS
#define AXIS2_DRIVER_MICROSTEPS       32 //    OFF, n. Microstep mode when tracking.                                        <-Often
#undef AXIS1_DRIVER_MICROSTEPS_GOTO    //    OFF, n. Microstep mode used during gotos.                                     Option
#define AXIS1_DRIVER_MICROSTEPS_GOTO  OFF //    OFF, n. Microstep mode used during gotos.                                     Option

#undef AXIS2_DRIVER_IRUN
#define AXIS2_DRIVER_IRUN             1100 //    OFF, n, (mA.) Current during tracking, appropriate for stepper/driver/etc.    Option
#undef AXIS2_DRIVER_REVERSE
#define AXIS2_DRIVER_REVERSE          OFF //    OFF, ON Reverses movement direction, or reverse wiring instead to correct.   <-Often

#undef AXIS2_LIMIT_MIN
#define AXIS2_LIMIT_MIN               -90 //    -90, n. Where n=-90..0 (degrees.) Minimum allowed declination.                Infreq

#undef AXIS2_LIMIT_MAX
#define AXIS2_LIMIT_MAX                90 //     90, n. Where n=0..90 (degrees.) Maximum allowed declination.                 Infreq


// AUXILIARY FEATURE CONTROL ------------------------------ see https://onstep.groups.io/g/main/wiki/6-ConfigurationMaster#AUXILIARY

#undef  FEATURE1_NAME
#define FEATURE1_NAME          "CAMERA" // "FE..", Name of feature being controlled.                                        Adjust
#undef  FEATURE1_PURPOSE
#define FEATURE1_PURPOSE              SWITCH //    OFF, SWITCH, ANALOG_OUT, DEW_HEATER, etc.                                     Option
#undef  FEATURE1_TEMP
#define FEATURE1_TEMP                 OFF //    OFF, DS1820, n. Where n is the ds18b20 s/n for DEW_HEATER temperature.        Adjust
#undef  FEATURE1_PIN
#define FEATURE1_PIN                  DS2413 //    OFF, AUX, DS2413, n. Where n is ds2413 s/n (gpio0) or n=0 to 255 (pin#.)      Adjust
#undef  FEATURE1_DEFAULT_VALUE
#define FEATURE1_DEFAULT_VALUE        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#undef  FEATURE2_NAME
#define FEATURE2_NAME          "DEW1" // "FE..", Name of feature being controlled.                                        Adjust
#undef  FEATURE2_PURPOSE
#define FEATURE2_PURPOSE              SWITCH //    OFF, SWITCH, ANALOG_OUT, DEW_HEATER, etc.                                     Option
#undef  FEATURE2_TEMP
#define FEATURE2_TEMP                 OFF //    OFF, DS1820, n. Where n is the ds18b20 s/n for DEW_HEATER temperature.        Adjust
#undef  FEATURE2_PIN
#define FEATURE2_PIN                  CHAIN //    OFF, AUX, CHAIN (ds2413 gpio1,) n. Where n=0 to 255 (pin#.)                   Adjust
#undef  FEATURE2_DEFAULT_VALUE
#define FEATURE2_DEFAULT_VALUE        ON //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#undef  FEATURE3_NAME
#define FEATURE3_NAME          "DEW2" // "FE..", Name of feature being controlled.                                        Adjust
#undef  FEATURE3_PURPOSE
#define FEATURE3_PURPOSE              SWITCH //    OFF, SWITCH, ANALOG_OUT, DEW_HEATER, etc.                                     Option
#undef  FEATURE3_TEMP
#define FEATURE3_TEMP                 OFF //    OFF, DS1820, n. Where n is the ds18b20 s/n for DEW_HEATER temperature.        Adjust
#undef  FEATURE3_PIN
#define FEATURE3_PIN                  DS2413 //    OFF, AUX, DS2413, n. Where n is ds2413 s/n (gpio0) or n=0 to 255 (pin#.)      Adjust
#undef  FEATURE3_DEFAULT_VALUE
#define FEATURE3_DEFAULT_VALUE        ON //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#undef  FEATURE4_NAME
#define FEATURE4_NAME          "DEW3" // "FE..", Name of feature being controlled.                                        Adjust
#undef  FEATURE4_PURPOSE
#define FEATURE4_PURPOSE              SWITCH //    OFF, SWITCH, ANALOG_OUT, DEW_HEATER, etc.                                     Option
#undef  FEATURE4_TEMP
#define FEATURE4_TEMP                 OFF //    OFF, DS1820, n. Where n is the ds18b20 s/n for DEW_HEATER temperature.        Adjust
#undef  FEATURE4_PIN
#define FEATURE4_PIN                  CHAIN //    OFF, AUX, CHAIN (ds2413 gpio1,) n. Where n=0 to 255 (pin#.)                   Adjust
#undef  FEATURE4_DEFAULT_VALUE
#define FEATURE4_DEFAULT_VALUE        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.   
