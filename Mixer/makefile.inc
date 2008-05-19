# -*- mode: makefile; -*-

Mixer_SRCS= \
Mixer/DPM.C \
Mixer/Mixer_Strip.C \
Mixer/Panner.C \
Mixer/Mixer.C \

Mixer_OBJS := $(Mixer_SRCS:.C=.o)

Mixer_LIBS := $(FLTK_LIBS)

INCLUDES := -I.

Mixer/mixer: $(Mixer_OBJS) FL
	@ echo -n Linking mixer...
	@ $(CXX) $(CXXFLAGS) $(Mixer_LIBS)  $(Mixer_OBJS) -o $@ -LFL -lfl_widgets && echo $(DONE)

.PHONEY: Mixer
Mixer: Mixer/mixer

Mixer_clean:
	rm -f $(Mixer_OBJS) Mixer/mixer