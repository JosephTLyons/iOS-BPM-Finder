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
    startingMillisecondHolder = 0;
    endingMillisecondHolder = 0;
}

void TimeClass::incrementTapCount()
{
    tapCount++;
}

unsigned long int TimeClass::getIntTapCount()
{
    return tapCount;
}

void TimeClass::setIntTapCount(const unsigned long int &input)
{
    tapCount = input;
}

String TimeClass::getStringTapCount()
{
    // typecast unsigned long int to juce string and return
    return (String) tapCount;
}

void TimeClass::setStartingTime(const int64 &input)
{
    startingMillisecondHolder = input;
}

int64 TimeClass::getStartingTime()
{
    return startingMillisecondHolder;
}

void TimeClass::setEndingTime(const int64 &input)
{
    endingMillisecondHolder = input;
    
    calculateTimeElapsed();
}

int64 TimeClass::getEndingTime()
{
    return endingMillisecondHolder;
}

void TimeClass::calculateTimeElapsed()
{
    timeElapsed = endingMillisecondHolder - startingMillisecondHolder;
}

int64 TimeClass::getTotalTimeElapsed()
{
    return timeElapsed;
}
