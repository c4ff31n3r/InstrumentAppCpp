#pragma once
#include "MusicalInstrument.h"

class Guitar : public MusicalInstrument {
private:
    std::string guitarType;
    bool hasPickup;
    std::string color;

public:
    Guitar(const std::string& name, int stringsCount, const std::string& guitarType, bool hasPickup);
    Guitar(const std::string& name, int stringsCount, const std::string& guitarType, bool hasPickup, const std::string& color);
    void strum();
    void changeStrings();

    void describe() override;
    void specialFeature() override;
};
