/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "BPM.hpp"
#include "MyCustomTapButtonLookAndFeel.hpp"
#include "MyCustomResetButtonLookAndFeel.hpp"
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TapWindow  : public Component,
                   public Button::Listener
{
public:
    //==============================================================================
    TapWindow ();
    ~TapWindow();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    int roundFloat(const float &floatNumber);
    void averageMode();
    void nonAverageMode();
    void getTimeElapsedInMinutes(const Time &juceTimeObject);
    void resetAllFields();
    void buttonStateChange (Button* b);

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* bpmFinderNotes_rtf;
    static const int bpmFinderNotes_rtfSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    BPM bpmObject;
    Font fontForEditors;

    double seconds    = 0;
    double minutes    = 0;

    const int millisecondsInASecond = 1000;
    const int secondsInAMinute      = 60;

    double bpmPrecise = 0;
    int bpmRounded    = 0;

    MyCustomTapButtonLookAndFeel myCustomTapButtonLookAndFeel;
    MyCustomResetButtonLookAndFeel myCustomResetButtonLookAndFeel;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextButton> tapButton;
    ScopedPointer<TextButton> resetButton;
    ScopedPointer<TextEditor> tapOutputEditor;
    ScopedPointer<TextEditor> bPMOutputEditor;
    ScopedPointer<Label> tapsLabel;
    ScopedPointer<Label> BPMFinder;
    ScopedPointer<Label> lyonsDenLabel;
    ScopedPointer<ToggleButton> preciseModeToggle;
    ScopedPointer<ToggleButton> beepToggle;
    ScopedPointer<ToggleButton> averageModeToggle;
    ScopedPointer<Label> bpmLabel;
    ScopedPointer<ToggleButton> safeToggle;
    ScopedPointer<Label> modesLabel;
    ScopedPointer<TextButton> lockButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TapWindow)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
