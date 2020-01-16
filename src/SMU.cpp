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

// defines
#define _SMU_LIB_VERSION 100

// used namespaces
using namespace smu_com_backend;


///////////////////////
// class construcots //
///////////////////////

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
 * @brief Get the version of the library.
 * 
 * @retrun the current version of the library.
 */
uint16_t SMU_Com_Backend::getVersion() {
    return _SMU_LIB_VERSION;
}