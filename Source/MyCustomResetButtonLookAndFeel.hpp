//
//  MyCustomResetButtonLookAndFeel.hpp
//  BPM Finder
//
//  Created by Joseph Lyons on 3/18/17.
//
//

#ifndef MyCustomResetButtonLookAndFeel_hpp
#define MyCustomResetButtonLookAndFeel_hpp

#include "../JuceLibraryCode/JuceHeader.h"

class MyCustomResetButtonLookAndFeel : public LookAndFeel_V3
{
public:
    Font getTextButtonFont (TextButton&, int buttonHeight) override;
};

#endif /* MyCustomResetButtonLookAndFeel_hpp */
