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
#include "Arduino.h"
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
namespace smu
{
    ///////////
	// enums //
	///////////

    
    /////////////
    // classes //
    /////////////

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


            // Setter


            // Sensors



            // util
            uint16_t getVersion();

        // End PUBLIC --------------------------------------------------------------------

        // Begin PRIVATE -----------------------------------------------------------------
        private:

        // End PRIVATE -------------------------------------------------------------------
    };
}
#endif