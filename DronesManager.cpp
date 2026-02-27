//
// Created by Alessandro Falcari on 27/02/26.
//

#include "DronesManager.h"

DronesManager::DronesManager() {
    for (int i = 0; i < 8; i++) {
        drones[i] = nullptr; //serve per puntare a NULL
    }
};

void DronesManager::addDrone(Drone *drone) {
    lock_guard<mutex> lock(m);
    if (drones[drone->getId()] != nullptr) //controllo nel caso c'è qualcosa in quella posizione la tolgo
        delete drones[drone->getId()];
    drones[drone->getId()] = drone; //in principio carico il drone
}

bool DronesManager::getDrone(int droneId, Drone *&drone) {
    lock_guard<mutex> lock(m);
    if (droneId < 0 || droneId >= 8 || drones[droneId] == nullptr)
        return false;
    drone = new Drone(*drones[droneId]);
    return true;
}