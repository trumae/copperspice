MULTIMEDIA_DIRS += src/multimedia/audio

MULTIMEDIA_PUBLIC_INCLUDES += \
	QAudio \
	QAudioFormat \
	QAudioInput \
	QAudioOutput \
	QAudioDeviceInfo \
	QAudioEnginePlugin \
	QAudioEngineFactoryInterface \
	QAbstractAudioDeviceInfo \
	QAbstractAudioInput \
	QAbstractAudioOutput

MULTIMEDIA_AUDIO_INCLUDES = \
	qabstractaudiodeviceinfo.h \
	qabstractaudioinput.h \
	qabstractaudiooutput.h \
	qaudio.h \
	qaudioformat.h \
	qaudioinput.h \
	qaudiooutput.h \
	qaudiodeviceinfo.h \
	qaudioengineplugin.h \
	qaudioenginefactoryinterface.h \
	qaudioengine.h

MULTIMEDIA_AUDIO_PRIVATE_INCLUDES = \
	qaudiodevicefactory_p.h \
	qaudioinput_mac_p.h \
	qaudiooutput_mac_p.h \
	qaudiodeviceinfo_mac_p.h \
	qaudio_mac_p.h \
	qaudioinput_win32_p.h \
	qaudiooutput_win32_p.h \
	qaudiodeviceinfo_win32_p.h \
	qaudiooutput_alsa_p.h \
	qaudioinput_alsa_p.h \
	qaudiodeviceinfo_alsa_p.h

MULTIMEDIA_INCLUDES += $(MULTIMEDIA_AUDIO_INCLUDES)
MULTIMEDIA_PRIVATE_INCLUDES += $(MULTIMEDIA_AUDIO_PRIVATE_INCLUDES)

noinst_HEADERS+=$(patsubst %,src/multimedia/audio/%,$(MULTIMEDIA_AUDIO_INCLUDES)) \
		$(patsubst %,src/multimedia/audio/%,$(MULTIMEDIA_AUDIO_PRIVATE_INCLUDES))

lib_libCsMultimedia@BUILD_ABI@_la_SOURCES += \
	src/multimedia/audio/qaudio.cpp \
	src/multimedia/audio/qaudioformat.cpp

if OSTYPE_WIN
lib_libCsMultimedia@BUILD_ABI@_la_SOURCES += \
	src/multimedia/audio/qaudiodeviceinfo_win32_p.cpp \
	src/multimedia/audio/qaudiooutput_win32_p.cpp \
	src/multimedia/audio/qaudioinput_win32_p.cpp

lib_libCsMultimedia@BUILD_ABI@_la_LIBADD+= -lwinmm
endif

if ALSA
lib_libCsMultimedia@BUILD_ABI@_la_SOURCES += \
	src/multimedia/audio/qaudiodeviceinfo_alsa_p.cpp \
	src/multimedia/audio/qaudiooutput_alsa_p.cpp \
	src/multimedia/audio/qaudioinput_alsa_p.cpp

lib_libCsMultimedia@BUILD_ABI@_la_LIBADD+= $(ALSA_LIBS)
endif
