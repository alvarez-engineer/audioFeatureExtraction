#include <pybind11/pybind11.h>
#include "wave_player.h"

namespace py = pybind11;

// The module name must match the name you use in the Python import
PYBIND11_MODULE(audio_playback, m) {
    m.doc() = "Audio playback module using C++ and pybind11";
    m.def("play_sound", &playSound, "Play a WAV file using aplay");
}
