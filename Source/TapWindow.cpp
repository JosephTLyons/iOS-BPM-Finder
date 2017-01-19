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
#include "TapWindow.h"
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
    tapButton->setColour (TextButton::buttonColourId, Colour (0xff79ab93));

    addAndMakeVisible (resetButton = new TextButton ("resetButton"));
    resetButton->setButtonText (TRANS("Reset"));
    resetButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    resetButton->addListener (this);
    resetButton->setColour (TextButton::buttonColourId, Colour (0xffc85454));

    addAndMakeVisible (tapOutputEditor = new TextEditor ("new text editor"));
    tapOutputEditor->setMultiLine (false);
    tapOutputEditor->setReturnKeyStartsNewLine (false);
    tapOutputEditor->setReadOnly (true);
    tapOutputEditor->setScrollbarsShown (true);
    tapOutputEditor->setCaretVisible (false);
    tapOutputEditor->setPopupMenuEnabled (true);
    tapOutputEditor->setText (String());

    addAndMakeVisible (bPMOutputEditor = new TextEditor ("new text editor"));
    bPMOutputEditor->setMultiLine (false);
    bPMOutputEditor->setReturnKeyStartsNewLine (false);
    bPMOutputEditor->setReadOnly (true);
    bPMOutputEditor->setScrollbarsShown (true);
    bPMOutputEditor->setCaretVisible (false);
    bPMOutputEditor->setPopupMenuEnabled (true);
    bPMOutputEditor->setText (String());

    addAndMakeVisible (taps = new Label ("taps",
                                         TRANS("Taps")));
    taps->setFont (Font (15.00f, Font::plain));
    taps->setJustificationType (Justification::centredLeft);
    taps->setEditable (false, false, false);
    taps->setColour (Label::textColourId, Colours::white);
    taps->setColour (TextEditor::textColourId, Colours::black);
    taps->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (bPM = new Label ("bPM",
                                        TRANS("BPM")));
    bPM->setFont (Font (15.00f, Font::plain));
    bPM->setJustificationType (Justification::centredLeft);
    bPM->setEditable (false, false, false);
    bPM->setColour (Label::textColourId, Colours::white);
    bPM->setColour (TextEditor::textColourId, Colours::black);
    bPM->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (300, 400);


    //[Constructor] You can add your own custom stuff here..

    // set to zero for when app opens
    tapOutputEditor->setText((String) 0);
    bPMOutputEditor->setText((String) 0);

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
    taps = nullptr;
    bPM = nullptr;


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
    tapOutputEditor->setBounds (80, 26, 150, 24);
    bPMOutputEditor->setBounds (80, 76, 150, 24);
    taps->setBounds (130, 0, 40, 24);
    bPM->setBounds (130, 52, 40, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TapWindow::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]

    Time juceTimeObject(Time::getCurrentTime());
    static double timeElapsedTotal;
    static double timeElaspedAverage;
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

            // calculate BPM - subtract 1 from bpm count because intervals are always 1
            // less than the BPM count
            bPM = (timeObject.getIntTapCount() - 1) / minutes;

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
              virtualName="" explicitFocusOrder="0" pos="0 100 300 250" bgColOff="ff79ab93"
              buttonText="Tap" connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="resetButton" id="88dc555f2403c8fc" memberName="resetButton"
              virtualName="" explicitFocusOrder="0" pos="0 350 300 50" bgColOff="ffc85454"
              buttonText="Reset" connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="new text editor" id="f94a8be5ddeb7596" memberName="tapOutputEditor"
              virtualName="" explicitFocusOrder="0" pos="80 26 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="6c6e0ab145fad75" memberName="bPMOutputEditor"
              virtualName="" explicitFocusOrder="0" pos="80 76 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
  <LABEL name="taps" id="6bb71dd7450d482a" memberName="taps" virtualName=""
         explicitFocusOrder="0" pos="130 0 40 24" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="Taps" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="bPM" id="6a439a16ebfb2284" memberName="bPM" virtualName=""
         explicitFocusOrder="0" pos="130 52 40 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="BPM" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
