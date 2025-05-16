#include <iostream> // For basic input/output
#include "wave_player.h" // Include custom header to play adio


int main() {
    // Play the wav file located in "data/" directory
    // !Make sure "file_example_WAV_1MG.wav" exists in that directory 
    playSound("../data/file_example_WAV_1MG.wav");

    return 0; // Exit program with success code
}