#include "SVGUITest.h"
#include "IPlug_include_in_plug_src.h"

SVGUITest::SVGUITest(const InstanceInfo& info)
: Plugin(info, MakeConfig(kNumParams, kNumPresets))
{
  // declare parameters
  GetParam(kParamGain)->InitGain("Gain", -70, -70, 0.);

  // lambda function that gets called async when UI opens/webview is ready
  mEditorInitFunc = [&]() {
    LoadFile("index.html", GetBundleID());
    EnableScroll(false);
  };
  
  MakePreset("Preset 1", 0.);
}

// audio processing happens here, on realtime thread
void SVGUITest::ProcessBlock(sample** inputs, sample** outputs, int nFrames)
{
  const double gain = GetParam(kParamGain)->DBToAmp();
  
  for (int s = 0; s < nFrames; s++)
  {
    outputs[0][s] = inputs[0][s] * gain;
    outputs[1][s] = inputs[1][s] * gain;
  }
}

// when you send a message from the UI it will trigger this method
bool SVGUITest::OnMessage(int msgTag, int ctrlTag, int dataSize, const void* pData)
{
  DBGMSG("msgTag %i\n", msgTag);
  return false;
}

// In OnReset() you can update DSP buffer sizes, clear delay memory etc when SR changes
//void SVGUITest::OnReset()
//{
//  auto sr = GetSampleRate();
//}

// If you need to update the UI for e.g. VU meters you can send messages in OnIdle()
//void SVGUITest::OnIdle()
//{
//}
