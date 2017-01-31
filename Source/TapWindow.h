/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_F309236315CAB33E__
#define __JUCE_HEADER_F309236315CAB33E__

//[Headers]     -- You can add your own extra header files here --
#include "BPM.hpp"
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
                   public ButtonListener
{
public:
    //==============================================================================
    TapWindow ();
    ~TapWindow();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    BPM bpmObject;
    Font fontForEditors;
    
    double seconds;
    double minutes;
    
    // Wouldn't normally initialize objects in a specification file, but these are const,
    // So I can't declare them as const and assign their values in the constructor at the same time
    const int millisecondsInASecond = 1000;
    const int secondsInAMinute = 60;
    
    double bpmPrecise;
    int bpmRounded;
    
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextButton> tapButton;
    ScopedPointer<TextButton> resetButton;
    ScopedPointer<TextEditor> tapOutputEditor;
    ScopedPointer<TextEditor> bPMOutputEditor;
    ScopedPointer<Label> taps;
    ScopedPointer<Label> bPM;
    ScopedPointer<Label> BPMFinder;
    ScopedPointer<Label> JosephLyons;
    ScopedPointer<ToggleButton> preciseModeToggle;
    ScopedPointer<ToggleButton> beepToggle;
    ScopedPointer<ToggleButton> averageModeToggle;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TapWindow)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_F309236315CAB33E__
