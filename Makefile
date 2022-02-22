CC=arm-openipc-linux-musleabi-gcc
MPP=$(HOME)/projects/cameras/sdk/Hi3516EV200_SDK_V1.0.1.2/mpp
CFLAGS=-I$(MPP)/include
LDFLAGS=-L$(MPP)/lib
LDLIBS=-static -l_hiawb -lisp -l_hildci -l_hidehaze -l_hidrc -l_hiae -lmpi -lsecurec -lVoiceEngine -lupvqe -ldnvqe

getisp:
