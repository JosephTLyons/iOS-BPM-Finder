//
//  MyCustomTapButtonLookAndFeel.hpp
//  BPM Finder
//
//  Created by Joseph Lyons on 3/18/17.
//
//

#ifndef MyCustomTapButtonLookAndFeel_hpp
#define MyCustomTapButtonLookAndFeel_hpp

#include "../JuceLibraryCode/JuceHeader.h"

class MyCustomTapButtonLookAndFeel : public LookAndFeel_V3
{
public:
    Font getTextButtonFont (TextButton&, int buttonHeight) override;
};

#endif /* MyCustomTapButtonLookAndFeel_hpp */
