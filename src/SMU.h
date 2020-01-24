/**
 * @file SMU.h
 * @brief The header file for SMU library.
 * @author Jonas Merkle [JJM] <a href="mailto:jonas.merkle@tam-onestone.net">jonas.merkle@tam-onestone.net</a>
 * @author Dominik Authaler <a href="mailto:dominik.authaler@team-onestone.net">dominik.authaler@team-onestone.net</a>
 * @author
 * This library is maintained by <a href="https://team-onestone.net">Team Onestone</a>.
 * E-Mail: <a href="mailto:info@team-onestone.net">info@team-onestone.net</a>
 * @version 1.0.0
 * @date 16 January 2020
 * @copyright This project is released under the GNU General Public License v3.0
 */

#ifndef SMU_H
#define SMU_H

//////////////
// Includes //
//////////////

// basic Includes
#include <Arduino.h>
#include <inttypes.h>

/////////////
// Defines //
/////////////

/////////////
// Members //
/////////////

/**
 * @namespace SMU_Com_Backend
 * 
 * @brief Namespace for SMU-Communication-Backend related stuff.
 */
namespace sensor_management_unit
{
    ///////////
	// enums //
	///////////

    /**
	 * @enum SensorModel
	 * 
	 * @brief Enum that represents the differnet supported sensor models.
	 */ 
	enum SensorModel : int8_t {
        SENSOR_ERROR = -1,

        NO_SENSOR = 0x00,

        SRF08 = 0x01
    };

    /////////////
    // structs //
    /////////////

    /**
     * @struct SensorReading
     * 
     * @brief Struct that represens a sensor reading.
     */
    struct SensorReading
    {
        float values[4];

        int16_t status;
    };
    
    
    /////////////
    // classes //
    /////////////

    /**
     * @class SensorMaping
     * 
     * @brief Represents the SensorMaping.
     */
    class SensorMapping {
        // Begin PUBLIC ------------------------------------------------------------------
        public:

            // Constructors

            SensorMapping();
            SensorMapping(SensorModel sensModel, int8_t sensPort);
            SensorMapping(SensorModel sensModel, int8_t sensPort, int8_t sensNoOnSMU);
            ~SensorMapping();

            // variables
            
            SensorModel sensorModel;
            int8_t sensorPort;
            int8_t sensorNoOnSMU;


        // End PUBLIC --------------------------------------------------------------------

        // Begin PRIVATE -----------------------------------------------------------------
        private:

        // End PRIVATE -------------------------------------------------------------------
    };

    /**
     * @class SMU
     * 
     * @brief Represents the SMU.
     */
    class SMU {
        // Begin PUBLIC ------------------------------------------------------------------
        public:

            // Constructors
            SMU();
            ~SMU();

            // sensor
            bool initSensor(SensorMapping *sensMapping, SensorModel sensModel, uint8_t sensPort);
            bool setSensorActivationStatus(SensorMapping *sensMapping, bool activationStatus);
            bool getSensorActivationStatus(SensorMapping *sensorMapping, bool *activationStatus);
            bool getSensorReadings(SensorMapping *sensMapping, SensorReading *sensReading);
            bool manUpdateSensorRadings(SensorMapping *sensMapping);

            // auto update
            bool setSensorAutoupdateActivationStatus(bool status);
            
            // smu
            bool getSMUComBackendVersion(uint16_t *version);
            bool getSMUFirmwareVersion(uint16_t *version);

            bool getSMULastComError(uint8_t *error);
            bool getSUMLastSystemError(uint8_t *error);

            bool ping(); 

        // End PUBLIC --------------------------------------------------------------------

        // Begin PRIVATE -----------------------------------------------------------------
        private:

        // End PRIVATE -------------------------------------------------------------------
    };


    ///////////////
	// functions //
	///////////////

    uint16_t getVersion();
}
#endif