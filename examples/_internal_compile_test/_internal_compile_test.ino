/*
    WARNING!!!
    This Example is only used for internal testing of the library.
    It don't represent a propper usecase for this library.

    So please ignore this file!
*/





























































































#include "SMU.h"
#include "SMU-Communication-Backend.h"
#include "arduino-util.h"
#include "millis_delay.h"
#include "bit_op.h"

using namespace sensor_management_unit;
using namespace smu_com_backend;
using namespace arduino_util::millis_delay;
using namespace arduino_util::bit_op;

SMU smu;

void setup() {

    // sensor
    SensorMapping sm(SensorModel::SRF08, 0,0 );
    smu.initSensor(&sm, SensorModel::SRF08, 0);
    smu.setSensorActivationStatus(&sm, false);
    bool *boolPtr = 0;
    smu.getSensorActivationStatus(&sm, boolPtr);
    SensorReading sr;
    smu.getSensorReadings(&sm, &sr);
    smu.manUpdateSensorRadings(&sm);

    // auto update
    smu.setSensorAutoupdateActivationStatus(false);
    
    // smu
    uint16_t *intPtr = 0;
    smu.getSMUComBackendVersion(intPtr);
    smu.getSMUFirmwareVersion(intPtr);

    uint8_t *bytePtr = 0;
    smu.getSMULastComError(bytePtr);
    smu.getSUMLastSystemError(bytePtr);

    smu.ping(); 
}

void loop() {

}