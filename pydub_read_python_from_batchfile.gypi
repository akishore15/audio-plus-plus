from pydub import AudioSegment
import speech_recognition as sr
import io

def convert_audio_to_text(audio_path):
    audio = AudioSegment.from_file(audio_path)
    
    recognizer = sr.Recognizer()
    with sr.AudioFile(audio_path) as source:
        audio_data = recognizer.record(source)
        text = recognizer.recognize_google(audio_data)
    return text

def execute_python_code_from_text(text):
    exec(text)

# Prompt user for the file path
audio_path = input("Please enter the path to your audio file: ")
text = convert_audio_to_text(audio_path)
print("Transcribed text: ", text)

try:
    execute_python_code_from_text(text)
except Exception as e:
    print(f"An error occurred: {e}")
