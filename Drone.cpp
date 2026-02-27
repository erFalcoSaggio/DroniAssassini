//
// Created by Alessandro Falcari on 27/02/26.
//
#include "Drone.h"

Drone::Drone(int id, float lat, float lon, float alt) {
    this->id = id;
    this->lat = lat;
    this->lon = lon;
    this->alt = alt;
}

int Drone::getId() const {
    return this->id;
}

float Drone::getLat() const {
    return this->lat;
}

float Drone::getLon() const {
    return this->lon;
}

float Drone::getAlt() const {
    return this->alt;
}
