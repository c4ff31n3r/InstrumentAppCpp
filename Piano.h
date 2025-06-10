#pragma once
#include "MusicalInstrument.h"

class Piano : public MusicalInstrument {
private:
    int pedalCount;
    bool isGrand;

public:
    Piano(const std::string& name, int stringsCount, int pedalCount, bool isGrand);

    void pressPedal();
    void cleanKeys();

    void describe() override;
    void specialFeature() override;
};
