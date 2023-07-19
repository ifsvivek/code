import ffmpeg

def convert_mp4_to_mp3(input_file, output_file):
    input_stream = ffmpeg.input(input_file)
    audio_stream = input_stream.audio
    output_stream = ffmpeg.output(audio_stream, output_file, codec='libmp3lame', qscale=0)
    ffmpeg.run(output_stream)

if __name__ == "__main__":
    input_file_path = "in.mp4"
    output_file_path = "out.mp3"

    convert_mp4_to_mp3(input_file_path, output_file_path)
