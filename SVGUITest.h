#pragma once

#include "IPlug_include_in_plug_hdr.h"
#include "Oscillator.h"
#include "Smoothers.h"

using namespace iplug;

const int kNumPresets = 1;

// enumerated list of parameter ids
enum EParams
{
  kParamGain = 0,
  kNumParams
};

// enumerated list of msg tags, to identify messages from UI to DSP / vice versa
enum EMsgTags
{
  kNumMsgTags
};

// enumerated list of ctrl tags, to identify controls in UI, when sending messages
enum ECtrlTags
{
  kNumCtrlTags
};

class SVGUITest final : public Plugin
{
public:
  SVGUITest(const InstanceInfo& info);
  
  void ProcessBlock(sample** inputs, sample** outputs, int nFrames) override;
  bool OnMessage(int msgTag, int ctrlTag, int dataSize, const void* pData) override;

//  void OnReset() override;
//  void OnIdle() override;
private:
};
