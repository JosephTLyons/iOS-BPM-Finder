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
    tapButton->setColour (TextButton::buttonColourId, Colour (0xff53ffc5));

    addAndMakeVisible (resetButton = new TextButton ("resetButton"));
    resetButton->setButtonText (TRANS("Reset"));
    resetButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    resetButton->addListener (this);
    resetButton->setColour (TextButton::buttonColourId, Colour (0xffc43838));
    resetButton->setColour (TextButton::textColourOffId, Colours::white);

    addAndMakeVisible (tapOutputEditor = new TextEditor ("new text editor"));
    tapOutputEditor->setMultiLine (false);
    tapOutputEditor->setReturnKeyStartsNewLine (false);
    tapOutputEditor->setReadOnly (true);
    tapOutputEditor->setScrollbarsShown (true);
    tapOutputEditor->setCaretVisible (false);
    tapOutputEditor->setPopupMenuEnabled (true);
    tapOutputEditor->setColour (TextEditor::textColourId, Colours::white);
    tapOutputEditor->setColour (TextEditor::backgroundColourId, Colour (0xff4e4242));
    tapOutputEditor->setText (String());

    addAndMakeVisible (bPMOutputEditor = new TextEditor ("new text editor"));
    bPMOutputEditor->setMultiLine (false);
    bPMOutputEditor->setReturnKeyStartsNewLine (false);
    bPMOutputEditor->setReadOnly (true);
    bPMOutputEditor->setScrollbarsShown (true);
    bPMOutputEditor->setCaretVisible (false);
    bPMOutputEditor->setPopupMenuEnabled (true);
    bPMOutputEditor->setColour (TextEditor::textColourId, Colours::white);
    bPMOutputEditor->setColour (TextEditor::backgroundColourId, Colour (0xff4e4242));
    bPMOutputEditor->setText (String());

    addAndMakeVisible (taps = new Label ("taps",
                                         TRANS("Taps:")));
    taps->setFont (Font (41.00f, Font::plain));
    taps->setJustificationType (Justification::centred);
    taps->setEditable (false, false, false);
    taps->setColour (Label::textColourId, Colours::white);
    taps->setColour (TextEditor::textColourId, Colours::black);
    taps->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (bPM = new Label ("bPM",
                                        TRANS("BPM:")));
    bPM->setFont (Font (41.00f, Font::plain));
    bPM->setJustificationType (Justification::centred);
    bPM->setEditable (false, false, false);
    bPM->setColour (Label::textColourId, Colours::white);
    bPM->setColour (TextEditor::textColourId, Colours::black);
    bPM->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (BPMFinder = new Label ("BPM Finder",
                                              TRANS("BPM Finder")));
    BPMFinder->setFont (Font ("Baskerville", 65.90f, Font::plain));
    BPMFinder->setJustificationType (Justification::centred);
    BPMFinder->setEditable (false, false, false);
    BPMFinder->setColour (Label::backgroundColourId, Colour (0x00ffffff));
    BPMFinder->setColour (Label::textColourId, Colours::white);
    BPMFinder->setColour (TextEditor::textColourId, Colours::black);
    BPMFinder->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (JosephLyons = new Label ("Joseph Lyons",
                                                TRANS("Joseph Lyons")));
    JosephLyons->setFont (Font ("Savoye LET", 34.70f, Font::plain));
    JosephLyons->setJustificationType (Justification::centred);
    JosephLyons->setEditable (false, false, false);
    JosephLyons->setColour (Label::backgroundColourId, Colour (0x00ffffff));
    JosephLyons->setColour (Label::textColourId, Colour (0xffd8d8d8));
    JosephLyons->setColour (TextEditor::textColourId, Colours::black);
    JosephLyons->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (preciseModeToggle = new ToggleButton ("preciseModeToggle"));
    preciseModeToggle->setButtonText (TRANS("Precise"));
    preciseModeToggle->addListener (this);
    preciseModeToggle->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (beepToggle = new ToggleButton ("beepToggle"));
    beepToggle->setButtonText (TRANS("Beep"));
    beepToggle->addListener (this);
    beepToggle->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (averageModeToggle = new ToggleButton ("averageModeToggle"));
    averageModeToggle->setButtonText (TRANS("Average"));
    averageModeToggle->addListener (this);
    averageModeToggle->setColour (ToggleButton::textColourId, Colours::white);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (320, 568);


    //[Constructor] You can add your own custom stuff here..

    // Precision mode and beep mode is off automatically
    preciseModeToggle->setToggleState(false, dontSendNotification);
    beepToggle->setToggleState(false, dontSendNotification);
    averageModeToggle->setToggleState(true, dontSendNotification);
    
    // Set button to work on downclick, not "upclick"
    tapButton->setTriggeredOnMouseDown(true);

    // Set Font object up
    fontForEditors.setSizeAndStyle(41, bold, 1, 0);

    // Set font for textEditors
    tapOutputEditor->setFont(fontForEditors);
    bPMOutputEditor->setFont(fontForEditors);

    // Set to zero for when app opens
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
    BPMFinder = nullptr;
    JosephLyons = nullptr;
    preciseModeToggle = nullptr;
    beepToggle = nullptr;
    averageModeToggle = nullptr;


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

    tapButton->setBounds (0, 268, 320, 250);
    resetButton->setBounds (0, 518, 320, 50);
    tapOutputEditor->setBounds (160, 105, 160, 55);
    bPMOutputEditor->setBounds (160, 171, 160, 55);
    taps->setBounds (0, 102, 160, 50);
    bPM->setBounds (0, 171, 160, 50);
    BPMFinder->setBounds (0, 0, 320, 56);
    JosephLyons->setBounds (0, 47, 320, 47);
    preciseModeToggle->setBounds (13, 240, 72, 24);
    beepToggle->setBounds (254, 240, 53, 24);
    averageModeToggle->setBounds (126, 240, 72, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TapWindow::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    
    Time juceTimeObject(Time::getCurrentTime());
    double seconds;
    double minutes;
    double bpmPrecise;
    int bpmRounded;

    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == tapButton)
    {
        //[UserButtonCode_tapButton] -- add your button handler code here..

        // Enter average mode
        if(averageModeToggle->getToggleState())
        {
            // start timer - only do this once
            if(bpmObject.getIntTapCount() == 0)
            {
                bpmObject.setStartingTime(juceTimeObject.toMilliseconds());
            }

            bpmObject.incrementTapCount();

            // get and display newest tapcount
            tapOutputEditor->setText(bpmObject.getStringTapCount());

            // get new current time to calculate new duration, do this everytime
            if(bpmObject.getIntTapCount() > 1)
            {
                // set end time
                bpmObject.setEndingTime(juceTimeObject.toMilliseconds());

                // convert elapsed time to seconds
                seconds = bpmObject.getTotalTimeElapsed() / (double) millisecondsInASecond;

                // convert elapsed time to minutes
                minutes = seconds / secondsInAMinute;
            }

            // calculate BPM - subtract 1 from bpm count because intervals are always 1
            // less than the BPM count
            bpmPrecise = (bpmObject.getIntTapCount() - 1) / minutes;

            bpmRounded = roundFloat(bpmPrecise);
        }

        // Enter non-average mode
        else
        {
            if(bpmObject.getIntTapCount() > 0)
            {
                bpmObject.setEndingTime(juceTimeObject.toMilliseconds());

                // convert elapsed time to seconds
                seconds = bpmObject.getTotalTimeElapsed() / (double) millisecondsInASecond;

                // convert elapsed time to minutes
                minutes = seconds / secondsInAMinute;
            }

            bpmObject.setStartingTime(juceTimeObject.toMilliseconds());

            bpmObject.incrementTapCount();

            // get and display newest tapcount
            tapOutputEditor->setText(bpmObject.getStringTapCount());

            // Set bpm to 0 in this mode on first tap, as there can't be a BPM with only one tap
            // Requires two taps to get a BPM
            if(bpmObject.getIntTapCount() == 1)
            {
                bpmPrecise = 0;
            }

            else
            {
                // Divide by one, as we are only measuring the time between the current tap
                bpmPrecise = 1 / minutes;
            }

            bpmRounded = roundFloat(bpmPrecise);
        }

        // Display either decimals or integer only
        if(preciseModeToggle->getToggleState())
        {
            bPMOutputEditor->setText((String) bpmPrecise);
        }

        else
        {
            bPMOutputEditor->setText((String) bpmRounded);
        }

        //[/UserButtonCode_tapButton]
    }
    else if (buttonThatWasClicked == resetButton)
    {
        //[UserButtonCode_resetButton] -- add your button handler code here..

        // reset all fields
        bpmObject.setIntTapCount(0);
        bpmObject.setStartingTime(0);
        bpmObject.setEndingTime(0);

        // set both fields back to 0
        tapOutputEditor->setText((String) 0);
        bPMOutputEditor->setText((String) 0);

        //[/UserButtonCode_resetButton]
    }
    else if (buttonThatWasClicked == preciseModeToggle)
    {
        //[UserButtonCode_preciseModeToggle] -- add your button handler code here..
        //[/UserButtonCode_preciseModeToggle]
    }
    else if (buttonThatWasClicked == beepToggle)
    {
        //[UserButtonCode_beepToggle] -- add your button handler code here..
        //[/UserButtonCode_beepToggle]
    }
    else if (buttonThatWasClicked == averageModeToggle)
    {
        //[UserButtonCode_averageModeToggle] -- add your button handler code here..

        // Triggers reset when switching modes to reset internal values
        resetButton->triggerClick();

        //[/UserButtonCode_averageModeToggle]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

int TapWindow::roundFloat(const float &floatNumber)
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
                 fixedSize="1" initialWidth="320" initialHeight="568">
  <BACKGROUND backgroundColour="ff4e4242"/>
  <TEXTBUTTON name="tapButton" id="ca627b359bc64f50" memberName="tapButton"
              virtualName="" explicitFocusOrder="0" pos="0 268 320 250" bgColOff="ff53ffc5"
              buttonText="Tap" connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="resetButton" id="88dc555f2403c8fc" memberName="resetButton"
              virtualName="" explicitFocusOrder="0" pos="0 518 320 50" bgColOff="ffc43838"
              textCol="ffffffff" buttonText="Reset" connectedEdges="3" needsCallback="1"
              radioGroupId="0"/>
  <TEXTEDITOR name="new text editor" id="f94a8be5ddeb7596" memberName="tapOutputEditor"
              virtualName="" explicitFocusOrder="0" pos="160 105 160 55" textcol="ffffffff"
              bkgcol="ff4e4242" initialText="" multiline="0" retKeyStartsLine="0"
              readonly="1" scrollbars="1" caret="0" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="6c6e0ab145fad75" memberName="bPMOutputEditor"
              virtualName="" explicitFocusOrder="0" pos="160 171 160 55" textcol="ffffffff"
              bkgcol="ff4e4242" initialText="" multiline="0" retKeyStartsLine="0"
              readonly="1" scrollbars="1" caret="0" popupmenu="1"/>
  <LABEL name="taps" id="6bb71dd7450d482a" memberName="taps" virtualName=""
         explicitFocusOrder="0" pos="0 102 160 50" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Taps:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="41" bold="0" italic="0" justification="36"/>
  <LABEL name="bPM" id="6a439a16ebfb2284" memberName="bPM" virtualName=""
         explicitFocusOrder="0" pos="0 171 160 50" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="BPM:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="41" bold="0" italic="0" justification="36"/>
  <LABEL name="BPM Finder" id="2556d6d714a02054" memberName="BPMFinder"
         virtualName="" explicitFocusOrder="0" pos="0 0 320 56" bkgCol="ffffff"
         textCol="ffffffff" edTextCol="ff000000" edBkgCol="0" labelText="BPM Finder"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Baskerville" fontsize="65.900000000000005684" bold="0"
         italic="0" justification="36"/>
  <LABEL name="Joseph Lyons" id="124d3b3268108be4" memberName="JosephLyons"
         virtualName="" explicitFocusOrder="0" pos="0 47 320 47" bkgCol="ffffff"
         textCol="ffd8d8d8" edTextCol="ff000000" edBkgCol="0" labelText="Joseph Lyons"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Savoye LET" fontsize="34.700000000000002842" bold="0"
         italic="0" justification="36"/>
  <TOGGLEBUTTON name="preciseModeToggle" id="876f27a25960a084" memberName="preciseModeToggle"
                virtualName="" explicitFocusOrder="0" pos="13 240 72 24" txtcol="ffffffff"
                buttonText="Precise" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="beepToggle" id="3297335df774edc0" memberName="beepToggle"
                virtualName="" explicitFocusOrder="0" pos="254 240 53 24" txtcol="ffffffff"
                buttonText="Beep" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="averageModeToggle" id="540e24a23ba6e447" memberName="averageModeToggle"
                virtualName="" explicitFocusOrder="0" pos="126 240 72 24" txtcol="ffffffff"
                buttonText="Average" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
