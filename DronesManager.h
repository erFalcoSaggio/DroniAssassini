//
// Created by Alessandro Falcari on 27/02/26.
//

#ifndef DRONIASSASSINI_DRONESMANAGER_H
#define DRONIASSASSINI_DRONESMANAGER_H
#include <mutex>
#include "Drone.h"
using namespace std;


class DronesManager {
    //private
    Drone* drones[8]{};
    mutex m;
public:
    DronesManager();
    void addDrone(Drone* drone);
    bool getDrone(int droneId, Drone*& drone);
};


#endif //DRONIASSASSINI_DRONESMANAGER_H