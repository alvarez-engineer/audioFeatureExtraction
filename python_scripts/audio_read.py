"""PyAudio Example: Play a wave file."""

# Import libraries
import wave
import pyaudio


# Setting up constants for file path (this is modular due to easier future variable changes)
CHUNK = 1024
FILE_LOCATION = '../data/'
FILE_NAME = 'file_example_WAV_1MG.wav'
FILE_PATH = FILE_LOCATION + FILE_NAME
print(f'Attempting to play {FILE_PATH}.')


with wave.open(FILE_PATH, 'rb') as wf:
    # Instantiate PyAudio and initialize PortAudio system resources
    p = pyaudio.PyAudio()

    # Open audio stream
    stream = p.open(
        format=p.get_format_from_width(wf.getsampwidth()),
        channels=wf.getnchannels(),
        rate=wf.getframerate(),
        output=True
        )

    # Play samples from the wave file
    while len(data := wf.readframes(CHUNK)):
        stream.write(data)

    # Close audio stream
    stream.close()

    # Release PortAudio system resources
    p.terminate()

print("The ALSA will be unable to find some audio drivers, that is fine for now")