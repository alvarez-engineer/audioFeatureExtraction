# Import the compiled C++ module
# This is the reason the test.py and wav_player.so are both in the 
# project root directory so they can see each other
import wav_player

# Call the function defined in C++ to play a .wav file
# Make sure the path points to a real WAV file
wav_player.play_wav_file("data/file_example_WAV_1MG.wav")
