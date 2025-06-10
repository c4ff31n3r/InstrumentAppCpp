#pragma once
#include <string>

class MusicalInstrument {
protected:
    std::string name;
    int stringsCount;

public:
    MusicalInstrument(const std::string& name, int StringsCount);
    virtual ~MusicalInstrument();

    virtual void play();
    virtual void tune();
    virtual void describe();
    virtual void specialFeature();

    void setName(const std::string& newName);
    std::string getName();
    void setStringsCount(int count);
    int getStringsCount();
};
