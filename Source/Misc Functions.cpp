//
//  Misc Functions.cpp
//  BPM Finder
//
//  Created by Joseph Lyons on 1/25/17.
//
//

#include "Misc Functions.hpp"

int roundFloat(const float &floatNumber)
{
    // Truncate
    int roundedNumber = floatNumber;
    
    // Get just decimal value and use that to decide if we round or not
    float roundingFactor = floatNumber - roundedNumber;
    
    if(roundingFactor >= 0.5)
    {
        roundedNumber++;
    }
    
    return roundedNumber;
}
