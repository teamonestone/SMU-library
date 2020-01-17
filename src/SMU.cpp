/**
 * @file SMU.cpp
 * @brief The source file for SMU library.
 * @author Jonas Merkle [JJM] <a href="mailto:jonas.merkle@tam-onestone.net">jonas.merkle@tam-onestone.net</a>
 * @author Dominik Authaler <a href="mailto:dominik.authaler@team-onestone.net">dominik.authaler@team-onestone.net</a>
 * @author
 * This library is maintained by <a href="https://team-onestone.net">Team Onestone</a>.
 * E-Mail: <a href="mailto:info@team-onestone.net">info@team-onestone.net</a>
 * @version 1.0.0
 * @date 09 January 2020
 * @copyright This project is released under the GNU General Public License v3.0
 */

// associated header
#include "SMU.h"

// additional headers
#include "SMU-Communication-Backend.h"
#include "arduino-util.h"
#include "mdelay.h"
#include "bit_op.h"

// defines
#define _SMU_LIB_VERSION 10000
#define _SMU_REQUEST_DELAY 5

// used namespaces
using namespace smu;
using namespace smu_com_backend;
using namespace arduino_util::mdelay;
using namespace arduino_util::bit_op;


///////////////////////
// class construcots //
///////////////////////

/**
 * @brief Default Constructor of the SensorMapping class.
 * 
 */
SensorMapping::SensorMapping() {
    sensorModel = SensorModel::NO_SENSOR;
    sensorPort = -1;
    sensorNoOnSMU = -1;
}

/**
 * @brief Constructor of the SensorMapping class.
 * 
 * @param sensModel The model of the sensor.
 * @param sensPort The port of the sensor.
 */
SensorMapping::SensorMapping(SensorModel sensModel, int8_t sensPort) {
    sensorModel = SensorModel::sensModel;
    sensorPort = sensPort;
    sensorNoOnSMU = -1;
}

/**
 * @brief Constructor of the SensorMapping class.
 * 
 * @param sensModel The model of the sensor.
 * @param sensPort The port of the sensor.
 * @param sensNoOnSMU The internal number of the sensor on the SMU.
 */
SensorMapping::SensorMapping(SensorModel sensModel, int8_t sensPort, uint8_t sensNoOnSMU) {
    sensorModel = SensorModel::sensModel;
    sensorPort = sensPort;
    sensorNoOnSMU = sensNoOnSMU;
}

/**
 * @brief Default Destructor of the SensorMapping class.
 *  
 */
SensorMapping::~SensorMapping() {

}

/**
 * @brief Default Constructor of the SMU class.
 * 
 */
SMU::SMU() {

}

/**
 * @brief Default Destructor of the SMU class.
 *  
 */
SMU::~SMU() {
    
}


/////////////////////
// class functions //
/////////////////////

/**
 * @brief Initialize a new sensor.
 * 
 * @param sensMapping A SensorMapping pointer to a empty SensorMapping object.
 * @param sensModel The model of the sensor that should be connected.
 * @param sensPort The port of the sensor that should be connected.
 * 
 * @return True on success, else false.
 */
bool SMU::initSensor(SensorMapping *sensMapping, SensorModel sensModel, uint8_t sensPort) {

    // local variables
    Message msg;
    uint8_t payload[25] = {0};

    // setup payloads
    payload[0] = static_cast<uint8_t>(sensModel);
    payload[1] = sensPort;

    // setup message
    msg.setMsgType(MessageType::INIT_SENSOR);
    msg.setPayload(payload, 2)

    // send message
    sendMessage(&msg);

    // wait for smu to process the request
    mdelay(_SMU_REQUEST_DELAY);
    
    // clear the message object
    msg.clear();

    // read received message
    readNextMessage(&msg);

    // starting evaluating received message ------------------------------------------------------

    if (msg.getMsgType != MessageType::ACK) {
        return false;
    }

    if (static_cast<MessageType>(msg.getPayload[0]) != MessageType::INIT_SENSOR) {
        return false;
    }

    if (msg.getPayload[1] == 0) {
        return false;
    }

    sensMapping->sensorModel = sensModel;
    sensMapping->sensorPort = sensPort;
    sensMapping->sensorNoOnSMU = getPayload[2];

    // evaluating received message finished ------------------------------------------------------

    return true;
}

/**
 * @brief Get the activation status of a sensor.
 * 
 * @param sensMapping A SensorMapping pointer to a SensorMapping object.
 * @param activationStatus The activation status as bool.
 * 
 * @return True on success, else false.
 */
bool SMU::setSensorActivationStatus(SensorMapping *sensMapping, bool activationStatus) {
    Message msg;
    
    uint8_t payload[25] = {0};
    payload[0] = static_cast<uint8_t>(sensModel);
    payload[1] = sensPort;
    msg.setMsgType(MessageType::INIT_SENSOR);
    msg.setPayload(payload, 2)

    sendMessage(&msg);

    mdelay(_SMU_REQUEST_DELAY);

    

    return true;
}

/**
 * @brief Set the activation status of a sensor.
 * 
 * @param sensMapping A SensorMapping pointer to a SensorMapping object.
 * @param activationStatus A bool pointer for the activation status.
 * 
 * @return True on success, else false.
 */
bool SMU::getSensorActivationStatus(SensorMapping *SensorMapping, bool *activationStatus) {

}

/**
 * @brief Get the latest reading of a sensor.
 * 
 * @param sensMapping A SensorMapping pointer to a SensorMapping object.
 * @param sensReading A SensorReading pointer where the sensor readings should be stroed.
 * 
 * @return True on success, else false.
 */
bool SMU::getSensorReadings(SensorMapping *sensMapping, SensorReading *sensReading) {

}

/**
 * @brief Manual update the reading of a sensor.
 * 
 * @param sensMapping A SensorMapping pointer to a SensorMapping object.
 * 
 * @return True on success, else false.
 */
bool SMU::manUpdateSensorRadings(SensorMapping *sensMapping) {
    Message msg;
    
    uint8_t payload[] = {static_cast<uint8_t>(sensModel), sensPort};
    msg.setMsgType(MessageType::INIT_SENSOR);
    msg.setPayload(payload, 2)

    sendMessage(&msg);

    return true;
}

/**
 * @brief Enable the automatic update of the sensor vaules at the SMU.
 * 
 * @return True on success, else false.
 */
bool SMU::enableSensorAutoupdate() {
    Message msg;
    
    uint8_t payload[] = {static_cast<uint8_t>(sensModel), sensPort};
    msg.setMsgType(MessageType::INIT_SENSOR);
    msg.setPayload(payload, 2)

    sendMessage(&msg);

    return true;
}

/**
 * @brief Disables the automaitc update of the sensor values at the SMU.
 * 
 * @return True on success, else false.
 */
bool SMU::disableSensorAutoUpdate() {
    Message msg;
    
    uint8_t payload[] = {static_cast<uint8_t>(sensModel), sensPort};
    msg.setMsgType(MessageType::INIT_SENSOR);
    msg.setPayload(payload, 2)

    sendMessage(&msg);

    return true;
}

/**
 * @brief Get the version of the Communication Backend lib on the SMU.
 * 
 * @param version A uint16_t pointer to store the version no.
 * 
 * @return True on success, else false.
 */
bool SMU::getSMUComBackendVersion(uint16_t *version) {

}

/**
 * @brief Get the version of the firmware on the SMU.
 * 
 * @param version A uint16_t pointer to store the version no.
 * 
 * @return True on success, else false.
 */
bool SMU::getSMUFirmwareVersion(uint16_t *version) {

}

/**
 * @brief Get the last Communication Error code of the SMU.
 * 
 * @param error A uint8_t pointer to store the error code.
 * 
 * @return True on success, else false.
 */
bool SMU::getSMULastComError(uint8_t *error) {

}

/**
 * @brief Get the last System Error code of the SMU.
 * 
 * @param error A uint8_t pointer to store the error code.
 * 
 * @return True on success, else false.
 */
bool SMU::getSUMLastSystemError(uint8_t *error) {

}

/**
 * @brief Ping the SMU.
 * 
 * @return True on success, else false.
 */
bool SMU::ping() {

}


/////////////////////////
// namespace functions // 
/////////////////////////

/**
 * @brief Get the version of the library.
 * 
 * @retrun the current version of the library.
 */
uint16_t smu::getVersion() {
    return _SMU_LIB_VERSION;
}