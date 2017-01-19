/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "TapWindow.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TapWindow::TapWindow ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (tapButton = new TextButton ("tapButton"));
    tapButton->setButtonText (TRANS("Tap"));
    tapButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    tapButton->addListener (this);

    addAndMakeVisible (resetButton = new TextButton ("resetButton"));
    resetButton->setButtonText (TRANS("Reset"));
    resetButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    resetButton->addListener (this);

    addAndMakeVisible (tapOutputEditor = new TextEditor ("new text editor"));
    tapOutputEditor->setMultiLine (false);
    tapOutputEditor->setReturnKeyStartsNewLine (false);
    tapOutputEditor->setReadOnly (false);
    tapOutputEditor->setScrollbarsShown (true);
    tapOutputEditor->setCaretVisible (true);
    tapOutputEditor->setPopupMenuEnabled (true);
    tapOutputEditor->setText (String());

    addAndMakeVisible (bPMOutputEditor = new TextEditor ("new text editor"));
    bPMOutputEditor->setMultiLine (false);
    bPMOutputEditor->setReturnKeyStartsNewLine (false);
    bPMOutputEditor->setReadOnly (false);
    bPMOutputEditor->setScrollbarsShown (true);
    bPMOutputEditor->setCaretVisible (true);
    bPMOutputEditor->setPopupMenuEnabled (true);
    bPMOutputEditor->setText (String());


    //[UserPreSize]
    //[/UserPreSize]

    setSize (300, 400);


    //[Constructor] You can add your own custom stuff here..

    // set output to tap value - zero at this point
    tapOutputEditor->setText(timeObject.getStringTapCount());

    //[/Constructor]
}

TapWindow::~TapWindow()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    tapButton = nullptr;
    resetButton = nullptr;
    tapOutputEditor = nullptr;
    bPMOutputEditor = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TapWindow::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff4e4242));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TapWindow::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    tapButton->setBounds (0, 100, 300, 250);
    resetButton->setBounds (0, 350, 300, 50);
    tapOutputEditor->setBounds (80, 16, 150, 24);
    bPMOutputEditor->setBounds (80, 64, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TapWindow::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]

    Time juceTimeObject(Time::getCurrentTime());
    double seconds;
    double minutes;
    double bPM;

    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == tapButton)
    {
        //[UserButtonCode_tapButton] -- add your button handler code here..

        // start timer - only do this once
        if(timeObject.getIntTapCount() == 0)
        {
            timeObject.setStartingTime(juceTimeObject.toMilliseconds());
        }

        timeObject.incrementTapCount();

        // get and display newest tapcount
        tapOutputEditor->setText(timeObject.getStringTapCount());

        // get new current time to calculate new duration, do this everytime
        if(timeObject.getIntTapCount() > 1)
        {
            // get end time
            timeObject.setEndingTime(juceTimeObject.toMilliseconds());

            // convert elapsed time to seconds
            seconds = timeObject.getTotalTimeElapsed() / (double) millisecondsInASecond;

            // convert elapsed time to minutes
            minutes = seconds / secondsInAMinute;

            // calculate BPM
            bPM = timeObject.getIntTapCount() / minutes;
            
            bPMOutputEditor->setText((String) bPM);
        }

        //[/UserButtonCode_tapButton]
    }
    else if (buttonThatWasClicked == resetButton)
    {
        //[UserButtonCode_resetButton] -- add your button handler code here..
        
        // reset all fields
        timeObject.setIntTapCount(0);
        timeObject.setStartingTime(0);
        timeObject.setEndingTime(0);
        
        // set both fields back to 0
        tapOutputEditor->setText((String) 0);
        bPMOutputEditor->setText((String) 0);
        
        //[/UserButtonCode_resetButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TapWindow" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="300" initialHeight="400">
  <BACKGROUND backgroundColour="ff4e4242"/>
  <TEXTBUTTON name="tapButton" id="ca627b359bc64f50" memberName="tapButton"
              virtualName="" explicitFocusOrder="0" pos="0 100 300 250" buttonText="Tap"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="resetButton" id="88dc555f2403c8fc" memberName="resetButton"
              virtualName="" explicitFocusOrder="0" pos="0 350 300 50" buttonText="Reset"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="new text editor" id="f94a8be5ddeb7596" memberName="tapOutputEditor"
              virtualName="" explicitFocusOrder="0" pos="80 16 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="6c6e0ab145fad75" memberName="bPMOutputEditor"
              virtualName="" explicitFocusOrder="0" pos="80 64 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
