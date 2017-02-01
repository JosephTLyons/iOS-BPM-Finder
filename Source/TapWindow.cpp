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
    tapOutputEditor->setBounds (130, 105, 190, 55);
    bPMOutputEditor->setBounds (130, 171, 190, 55);
    taps->setBounds (0, 102, 130, 50);
    bPM->setBounds (0, 171, 130, 50);
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
    double seconds    = 0;
    double minutes    = 0;
    double bpmPrecise = 0;
    int bpmRounded    = 0;

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
                // Set minutes to one, otherwise, first tap will result in a division with
                // 0 in the denominator, which will output "nan" on the first tap
                minutes = 1;

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
              virtualName="" explicitFocusOrder="0" pos="130 105 190 55" textcol="ffffffff"
              bkgcol="ff4e4242" initialText="" multiline="0" retKeyStartsLine="0"
              readonly="1" scrollbars="1" caret="0" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="6c6e0ab145fad75" memberName="bPMOutputEditor"
              virtualName="" explicitFocusOrder="0" pos="130 171 190 55" textcol="ffffffff"
              bkgcol="ff4e4242" initialText="" multiline="0" retKeyStartsLine="0"
              readonly="1" scrollbars="1" caret="0" popupmenu="1"/>
  <LABEL name="taps" id="6bb71dd7450d482a" memberName="taps" virtualName=""
         explicitFocusOrder="0" pos="0 102 130 50" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Taps:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="41" bold="0" italic="0" justification="36"/>
  <LABEL name="bPM" id="6a439a16ebfb2284" memberName="bPM" virtualName=""
         explicitFocusOrder="0" pos="0 171 130 50" textCol="ffffffff"
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

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: bpmFinderNotes_rtf, 983, "BPM Finder Notes.rtf"
static const unsigned char resource_TapWindow_bpmFinderNotes_rtf[] = { 123,92,114,116,102,49,92,97,110,115,105,92,97,110,115,105,99,112,103,49,50,53,50,92,99,111,99,111,97,114,116,102,49,53,48,52,92,99,
111,99,111,97,115,117,98,114,116,102,55,54,48,10,123,92,102,111,110,116,116,98,108,92,102,48,92,102,115,119,105,115,115,92,102,99,104,97,114,115,101,116,48,32,72,101,108,118,101,116,105,99,97,59,125,10,
123,92,99,111,108,111,114,116,98,108,59,92,114,101,100,50,53,53,92,103,114,101,101,110,50,53,53,92,98,108,117,101,50,53,53,59,125,10,123,92,42,92,101,120,112,97,110,100,101,100,99,111,108,111,114,116,
98,108,59,59,125,10,92,109,97,114,103,108,49,52,52,48,92,109,97,114,103,114,49,52,52,48,92,118,105,101,119,119,49,48,56,48,48,92,118,105,101,119,104,56,52,48,48,92,118,105,101,119,107,105,110,100,48,10,
92,112,97,114,100,92,116,120,48,92,116,120,55,50,48,92,116,120,49,52,52,48,92,116,120,50,49,54,48,92,116,120,50,56,56,48,92,116,120,51,54,48,48,92,116,120,52,51,50,48,92,116,120,53,48,52,48,92,116,120,
53,55,54,48,92,116,120,54,52,56,48,92,116,120,55,50,48,48,92,116,120,55,57,50,48,92,116,120,56,54,52,48,92,112,97,114,100,105,114,110,97,116,117,114,97,108,92,112,97,114,116,105,103,104,116,101,110,102,
97,99,116,111,114,48,10,10,92,102,48,92,102,115,50,52,32,92,99,102,48,32,49,41,32,65,100,100,32,66,101,101,112,92,10,50,41,32,67,108,101,97,110,32,85,112,32,67,111,100,101,92,10,51,41,32,73,110,99,114,
101,97,115,101,32,102,111,110,116,32,115,105,122,101,32,105,110,32,98,117,116,116,111,110,32,116,101,120,116,92,10,92,10,71,82,69,89,32,79,85,84,32,82,69,83,69,84,32,73,78,32,78,79,78,45,65,86,69,82,65,
71,69,32,77,79,68,69,44,32,78,79,84,32,78,69,69,68,69,68,63,63,63,63,92,10,92,112,97,114,100,92,116,120,55,50,48,92,116,120,49,52,52,48,92,116,120,50,49,54,48,92,116,120,50,56,56,48,92,116,120,51,54,48,
48,92,116,120,52,51,50,48,92,116,120,53,48,52,48,92,116,120,53,55,54,48,92,116,120,54,52,56,48,92,116,120,55,50,48,48,92,116,120,55,57,50,48,92,116,120,56,54,52,48,92,112,97,114,100,105,114,110,97,116,
117,114,97,108,92,112,97,114,116,105,103,104,116,101,110,102,97,99,116,111,114,48,10,92,99,102,48,32,92,10,73,109,112,114,111,118,101,32,71,85,73,92,10,45,66,101,116,116,101,114,32,85,115,101,32,111,102,
32,83,112,97,99,101,44,32,84,101,120,116,69,100,105,116,111,114,32,105,110,102,111,114,109,97,116,105,111,110,32,99,101,110,116,101,114,101,100,44,32,109,97,107,101,32,101,100,105,116,111,114,32,99,111,
108,111,114,32,115,97,109,101,32,97,115,32,98,97,99,107,103,114,111,117,110,100,63,92,10,92,10,83,116,114,105,112,32,99,111,109,109,101,110,116,101,100,32,111,117,116,32,99,111,100,101,92,10,114,101,112,
108,97,99,101,32,65,112,112,73,99,111,110,32,105,109,97,103,101,115,32,119,105,116,104,32,115,101,114,105,111,117,115,32,105,109,97,103,101,92,10,92,10,82,101,102,97,99,116,111,114,92,10,45,82,101,110,
97,109,101,32,74,117,99,101,32,116,105,109,101,32,111,98,106,101,99,116,115,92,10,45,80,117,108,108,32,99,97,108,99,117,108,97,116,105,111,110,32,105,110,116,111,32,109,121,32,99,108,97,115,115,32,111,
114,32,115,105,109,112,108,121,32,106,117,115,116,32,112,117,108,108,32,116,104,101,109,32,105,110,116,111,32,116,104,101,105,114,32,111,119,110,32,102,117,110,99,116,105,111,110,115,32,105,110,32,116,
104,101,32,116,97,112,87,105,110,100,111,119,46,99,112,112,32,109,105,115,99,32,102,117,110,99,116,105,111,110,32,97,114,101,97,32,97,110,100,32,114,101,109,111,118,101,32,34,109,105,115,99,32,102,117,
110,99,116,105,111,110,115,34,92,10,92,10,83,99,97,108,105,110,103,32,71,85,73,115,63,125,0,0};

const char* TapWindow::bpmFinderNotes_rtf = (const char*) resource_TapWindow_bpmFinderNotes_rtf;
const int TapWindow::bpmFinderNotes_rtfSize = 983;


//[EndFile] You can add extra defines here...
//[/EndFile]
