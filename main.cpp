//FALCARI
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>

#include "Drone.h"
#include "DronesManager.h"

using namespace std;


int getDroneData(float *latitude, float *longitude, float *altitude) {
    //simulo i dati
    *latitude = static_cast<float>(rand() % 90);
    *longitude = static_cast<float>(rand() % 180);
    *altitude = static_cast<float>(rand() % 500);

    return rand() % 8; //ritorna drone ID 0-7
}

void writerThread(DronesManager* manager) {
    cout << "[Writer] Thread started..." << endl;
    while (true) {
        float lat, lon, alt;
        int id = getDroneData(&lat, &lon, &alt);

        if (id >= 0 && id <= 7)
            manager->addDrone(new Drone(id, lat, lon, alt));

        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

void readerThread(DronesManager* manager, int droneId, string baseFileName) {
    string fullPath = baseFileName + to_string(droneId) + ".csv";

    while (true) {
        this_thread::sleep_for(chrono::seconds(1));

        Drone* d = nullptr;
        if (manager->getDrone(droneId, d)) {
            ofstream outFile(fullPath, ios::app); //app serve appunto per "append"
            if (outFile.is_open()) {
                outFile << d->getLat() << "," << d->getLon() << "," << d->getAlt() << endl;
                outFile.close();

                cout << "[Thread " << droneId << "] Dati salvati su " << fullPath << endl;
            }
            delete d; //evitare di occupare RAM
        }
    }
}

int main(int argc, char* argv[]) {
    //base filename argument (controllo per evitare errori)
    if (argc < 2) {
        cerr << "Error: You must provide a base filename as an argument." << endl;
        cerr << "Usage: ./program_name <filename>" << endl;
        return 1;
    }

    string baseName = argv[1];
    DronesManager* manager = new DronesManager();

    //faccio parire il Thread di scrittura
    thread t_writer(writerThread, manager);

    //qua collego un thread per ogni drone
    vector<thread> readers;
    for (int i = 0; i < 8; i++)
        readers.push_back(thread(readerThread, manager, i, baseName));

    //parallelismo
    t_writer.join();
    for (int i = 0; i < 8; i++)
        readers[i].join();

    //pulisce
    delete manager;
    return 0;
}