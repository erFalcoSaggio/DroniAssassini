//
// Created by Alessandro Falcari on 27/02/26.
//

#ifndef DRONIASSASSINI_DRONE_H
#define DRONIASSASSINI_DRONE_H


class Drone {
//private
    int id;
    float lat;
    float lon;
    float alt;
public:
    Drone(int id, float lat, float lon, float alt);
    int getId() const;
    float getLat() const;
    float getLon() const;
    float getAlt() const;
};


#endif //DRONIASSASSINI_DRONE_H