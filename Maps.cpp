//
// Created by daniel on 18/12/18.
//

#include "Maps.h"
Maps::Maps(){
    indexMap[0] = "/instrumentation/airspeed-indicator/indicated-speed-kt";
    indexMap[1] = "/instrumentation/altimeter/indicated-altitude-ft";
    indexMap[2] = "/instrumentation/altimeter/pressure-alt-ft";
    indexMap[3] = "/instrumentation/attitude-indicator/indicated-pitch-deg";
    indexMap[4] = "/instrumentation/attitude-indicator/indicated-roll-deg";
    indexMap[5] = "/instrumentation/attitude-indicator/internal-pitch-deg";
    indexMap[6] = "/instrumentation/attitude-indicator/internal-roll-deg";
    indexMap[7] = "/instrumentation/encoder/indicated-altitude-ft";
    indexMap[8] = "/instrumentation/encoder/pressure-alt-ft";
    indexMap[9] = "/instrumentation/gps/indicated-altitude-ft";
    indexMap[10] = "/instrumentation/gps/indicated-ground-speed-kt";
    indexMap[11] = "/instrumentation/gps/indicated-vertical-speed";
    indexMap[12] = "/instrumentation/heading-indicator/indicated-heading-deg";
    indexMap[13] = "/instrumentation/magnetic-compass/indicated-heading-deg";
    indexMap[14] = "/instrumentation/slip-skid-ball/indicated-slip-skid";
    indexMap[15] = "/instrumentation/turn-indicator/indicated-turn-rate";
    indexMap[16] = "/instrumentation/vertical-speed-indicator/indicated-speed-fpm";
    indexMap[17] = "/controls/flight/aileron";
    indexMap[18] = "/controls/flight/elevator";
    indexMap[19] = "/controls/flight/rudder";
    indexMap[20] = "/controls/flight/flaps";
    indexMap[21] = "/controls/engines/current-engine/throttle";
    indexMap[22] = "/engines/engine/rpm";
}

Maps *Maps::maps_instance = 0;
Maps* Maps:: instance() {
    if (!maps_instance) {
        maps_instance = new Maps;
    }
    return maps_instance;
}

