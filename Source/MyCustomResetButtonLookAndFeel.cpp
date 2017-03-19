//
//  MyCustomResetButtonLookAndFeel.cpp
//  BPM Finder
//
//  Created by Joseph Lyons on 3/18/17.
//
//

#include "MyCustomResetButtonLookAndFeel.hpp"

Font MyCustomResetButtonLookAndFeel::getTextButtonFont (TextButton&, int buttonHeight)
{
    return Font (jmin (20.0f, buttonHeight * 0.6f));
}
