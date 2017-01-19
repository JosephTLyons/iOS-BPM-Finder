//
//  TIme.hpp
//  BPM Finder
//
//  Created by Joseph Lyons on 1/18/17.
//
//
#include "../JuceLibraryCode/JuceHeader.h"

#ifndef TimeClass_hpp
#define TimeClass_hpp

class TimeClass
{
private:
    Time juceTimeOjbect;
    unsigned long int tapCount;
    
public:
    TimeClass();
    void incrementTapCount();
    String getStringTapCount();
    Time getJuceTimeObject();
};

#endif /* TIme_hpp */
