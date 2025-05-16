#pragma once // Ensure this header file only included once by compiler

#include <iostream> // For error message printing
#include <string> // For using std::string to handle file paths
#include <cstdlib> // For std::system to run terminal commands

// This function plays a .wav audio file using the Linux `aplay` command-line utility.
// @param filepath A string representing the path to the WAV file.
//        Example: "data/file_example_WAV_1MG.wav"
void playSound(const std::string& filepath)
{
    // Create command string to play audio
    std::string command = "aplay \"" + filepath +"\"";
    int result = std::system(command.c_str());

    // Check if system call failed (non-zero means error)
    if (result !=0) {
        // Print error message to standard error output
        std::cerr << "Failed to play audio file: " << filepath << std::endl;
    }
}