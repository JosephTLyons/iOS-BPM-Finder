//
//  MyCustomTapButtonLookAndFeel.cpp
//  BPM Finder
//
//  Created by Joseph Lyons on 3/18/17.
//
//

#include "MyCustomTapButtonLookAndFeel.hpp"

Font MyCustomTapButtonLookAndFeel::getTextButtonFont (TextButton&, int buttonHeight)
{
    return Font (jmin (50.0f, buttonHeight * 0.6f));
}
