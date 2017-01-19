//
//  TIme.cpp
//  BPM Finder
//
//  Created by Joseph Lyons on 1/18/17.
//
//

#include "TImeClass.hpp"

TimeClass::TimeClass()
{
    tapCount = 0;
}

void TimeClass::incrementTapCount()
{
    tapCount++;
}

String TimeClass::getStringTapCount()
{
    // typecast unsigned long int to juce string and return
    return (String) tapCount;
}

Time TimeClass::getJuceTimeObject()
{
    return juceTimeOjbect;
}
